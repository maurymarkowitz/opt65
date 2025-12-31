#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "stats.h"

#define NUM_OPCODES 256
#define MAX_ZERO_TRANSFERS 1000
#define MAX_REPLACEMENTS 1000
#define MAX_INSTR_HISTORY 10

static int opcode_counts[NUM_OPCODES];
static int total_opcodes = 0;
static int c02_opcode_count = 0;
static char *current_filename = NULL;
static int binary_size = 0;

/* Instruction history for pattern detection */
typedef struct {
    uint8_t opcode;
    char instr_name[16];
    uint16_t operand;
    uint16_t pc_at_instruction;
    int line_num;
    char expression[64];  /* Original expression/label for JMP instructions */
} instr_history_t;

static instr_history_t instr_history[MAX_INSTR_HISTORY];
static int instr_history_count = 0;

/* Replacement opportunities */
typedef struct {
    char type[32];  /* "STZ", "PHX", "PHY", "PLX", "PLY", "BRA" */
    int line_num;
    char filename[256];
    char old_code[64];
    char new_code[64];
    int bytes_saved;  /* Number of bytes saved by this replacement */
} replacement_t;

static replacement_t replacements[MAX_REPLACEMENTS];
static int replacement_count = 0;

/* Zero transfer tracking */
typedef struct {
    char instruction[32];
    uint16_t address;  /* 0xFFFF for register transfers, actual address for memory */
    int is_register;   /* 1 for register, 0 for memory */
} zero_transfer_t;

static zero_transfer_t zero_transfers[MAX_ZERO_TRANSFERS];
static int zero_transfer_count = 0;

/* Opcode names for display */
static const char *opcode_names[256] = {
    [0x00] = "BRK", [0x01] = "ORA (ind,X)", [0x05] = "ORA zp", [0x06] = "ASL zp",
    [0x08] = "PHP", [0x09] = "ORA #", [0x0A] = "ASL A", [0x0D] = "ORA abs",
    [0x0E] = "ASL abs", [0x10] = "BPL", [0x11] = "ORA (ind),Y", [0x15] = "ORA zp,X",
    [0x16] = "ASL zp,X", [0x18] = "CLC", [0x19] = "ORA abs,Y", [0x1D] = "ORA abs,X",
    [0x1E] = "ASL abs,X", [0x20] = "JSR", [0x21] = "AND (ind,X)", [0x24] = "BIT zp",
    [0x25] = "AND zp", [0x26] = "ROL zp", [0x28] = "PLP", [0x29] = "AND #",
    [0x2A] = "ROL A", [0x2C] = "BIT abs", [0x2D] = "AND abs", [0x2E] = "ROL abs",
    [0x30] = "BMI", [0x31] = "AND (ind),Y", [0x35] = "AND zp,X", [0x36] = "ROL zp,X",
    [0x38] = "SEC", [0x39] = "AND abs,Y", [0x3D] = "AND abs,X", [0x3E] = "ROL abs,X",
    [0x40] = "RTI", [0x41] = "EOR (ind,X)", [0x45] = "EOR zp", [0x46] = "LSR zp",
    [0x48] = "PHA", [0x49] = "EOR #", [0x4A] = "LSR A", [0x4C] = "JMP abs",
    [0x4D] = "EOR abs", [0x4E] = "LSR abs", [0x50] = "BVC", [0x51] = "EOR (ind),Y",
    [0x55] = "EOR zp,X", [0x56] = "LSR zp,X", [0x58] = "CLI", [0x59] = "EOR abs,Y",
    [0x5D] = "EOR abs,X", [0x5E] = "LSR abs,X", [0x60] = "RTS", [0x61] = "ADC (ind,X)",
    [0x65] = "ADC zp", [0x66] = "ROR zp", [0x68] = "PLA", [0x69] = "ADC #",
    [0x6A] = "ROR A", [0x6C] = "JMP (ind)", [0x6D] = "ADC abs", [0x6E] = "ROR abs",
    [0x70] = "BVS", [0x71] = "ADC (ind),Y", [0x75] = "ADC zp,X", [0x76] = "ROR zp,X",
    [0x78] = "SEI", [0x79] = "ADC abs,Y", [0x7D] = "ADC abs,X", [0x7E] = "ROR abs,X",
    [0x81] = "STA (ind,X)", [0x84] = "STY zp", [0x85] = "STA zp", [0x86] = "STX zp",
    [0x88] = "DEY", [0x8A] = "TXA", [0x8C] = "STY abs", [0x8D] = "STA abs",
    [0x8E] = "STX abs", [0x90] = "BCC", [0x91] = "STA (ind),Y", [0x94] = "STY zp,X",
    [0x95] = "STA zp,X", [0x96] = "STX zp,Y", [0x98] = "TYA", [0x99] = "STA abs,Y",
    [0x9A] = "TXS", [0x9D] = "STA abs,X", [0xA0] = "LDY #", [0xA1] = "LDA (ind,X)",
    [0xA2] = "LDX #", [0xA4] = "LDY zp", [0xA5] = "LDA zp", [0xA6] = "LDX zp",
    [0xA8] = "TAY", [0xA9] = "LDA #", [0xAA] = "TAX", [0xAC] = "LDY abs",
    [0xAD] = "LDA abs", [0xAE] = "LDX abs", [0xB0] = "BCS", [0xB1] = "LDA (ind),Y",
    [0xB4] = "LDY zp,X", [0xB5] = "LDA zp,X", [0xB6] = "LDX zp,Y", [0xB8] = "CLV",
    [0xB9] = "LDA abs,Y", [0xBA] = "TSX", [0xBC] = "LDY abs,X", [0xBD] = "LDA abs,X",
    [0xBE] = "LDX abs,Y", [0xC0] = "CPY #", [0xC1] = "CMP (ind,X)", [0xC4] = "CPY zp",
    [0xC5] = "CMP zp", [0xC6] = "DEC zp", [0xC8] = "INY", [0xC9] = "CMP #",
    [0xCA] = "DEX", [0xCC] = "CPY abs", [0xCD] = "CMP abs", [0xCE] = "DEC abs",
    [0xD0] = "BNE", [0xD1] = "CMP (ind),Y", [0xD5] = "CMP zp,X", [0xD6] = "DEC zp,X",
    [0xD8] = "CLD", [0xD9] = "CMP abs,Y", [0xDD] = "CMP abs,X", [0xDE] = "DEC abs,X",
    [0xE0] = "CPX #", [0xE1] = "SBC (ind,X)", [0xE4] = "CPX zp", [0xE5] = "SBC zp",
    [0xE6] = "INC zp", [0xE8] = "INX", [0xE9] = "SBC #", [0xEA] = "NOP",
    [0xEC] = "CPX abs", [0xED] = "SBC abs", [0xEE] = "INC abs", [0xF0] = "BEQ",
    [0xF1] = "SBC (ind),Y", [0xF5] = "SBC zp,X", [0xF6] = "INC zp,X", [0xF8] = "SED",
    [0xF9] = "SBC abs,Y", [0xFD] = "SBC abs,X", [0xFE] = "INC abs,X",
    /* 65C02 opcodes */
    [0x04] = "TSB zp (C02)", [0x0C] = "TSB abs (C02)", [0x14] = "TRB zp (C02)",
    [0x1C] = "TRB abs (C02)", [0x5A] = "PHY (C02)", [0x64] = "STZ zp (C02)",
    [0x74] = "STZ zp,X (C02)", [0x7A] = "PLY (C02)", [0x80] = "BRA (C02)",
    [0x9C] = "STZ abs (C02)", [0x9E] = "STZ abs,X (C02)", [0xCB] = "WAI (C02)",
    [0xDA] = "PHX (C02)", [0xDB] = "STP (C02)", [0xFA] = "PLX (C02)"
};

/* 65C02 opcodes */
static const uint8_t c02_opcodes[] = {
    0x04, 0x0C, 0x14, 0x1C, 0x5A, 0x64, 0x74, 0x7A,
    0x80, 0x9C, 0x9E, 0xCB, 0xDA, 0xDB, 0xFA
};
#define NUM_C02_OPCODES (sizeof(c02_opcodes) / sizeof(c02_opcodes[0]))

void stats_init(void) {
    memset(opcode_counts, 0, sizeof(opcode_counts));
    total_opcodes = 0;
    zero_transfer_count = 0;
    c02_opcode_count = 0;
    instr_history_count = 0;
    replacement_count = 0;
    current_filename = NULL;
    binary_size = 0;
}

void stats_set_binary_size(int size) {
    binary_size = size;
}

void stats_set_filename(const char *filename) {
    if (current_filename) {
        free(current_filename);
    }
    current_filename = filename ? strdup(filename) : NULL;
}

void stats_record_opcode(uint8_t opcode) {
    opcode_counts[opcode]++;
    total_opcodes++;
    if (stats_is_c02_opcode(opcode)) {
        c02_opcode_count++;
    }
}

void stats_record_instruction(uint8_t opcode, const char *instr_name, uint16_t operand, int line_num, const char *filename, const char *expression) {
    /* Add to history */
    if (instr_history_count >= MAX_INSTR_HISTORY) {
        /* Shift history */
        memmove(&instr_history[0], &instr_history[1], (MAX_INSTR_HISTORY - 1) * sizeof(instr_history_t));
        instr_history_count = MAX_INSTR_HISTORY - 1;
    }
    
    instr_history_t *hist = &instr_history[instr_history_count];
    hist->opcode = opcode;
    strncpy(hist->instr_name, instr_name ? instr_name : "UNKNOWN", sizeof(hist->instr_name) - 1);
    hist->instr_name[sizeof(hist->instr_name) - 1] = '\0';
    hist->operand = operand;
    hist->line_num = line_num;
    extern uint16_t pc;
    hist->pc_at_instruction = pc;
    if (expression) {
        strncpy(hist->expression, expression, sizeof(hist->expression) - 1);
        hist->expression[sizeof(hist->expression) - 1] = '\0';
    } else {
        hist->expression[0] = '\0';
    }
    instr_history_count++;
    
    /* Check for replacement patterns */
    if (instr_history_count >= 2) {
        /* Check for LDA #0 followed by STA -> STZ */
        if (instr_history_count >= 2) {
            instr_history_t *prev = &instr_history[instr_history_count - 2];
            instr_history_t *curr = &instr_history[instr_history_count - 1];
            
            if (prev->opcode == 0xA9 && prev->operand == 0 && 
                (curr->opcode == 0x85 || curr->opcode == 0x8D || 
                 curr->opcode == 0x95 || curr->opcode == 0x9D)) {
                /* LDA #0 followed by STA -> STZ */
                if (replacement_count < MAX_REPLACEMENTS) {
                    replacement_t *r = &replacements[replacement_count];
                    strcpy(r->type, "STZ");
                    r->line_num = prev->line_num;
                    strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                    r->filename[sizeof(r->filename) - 1] = '\0';
                    if (curr->opcode == 0x85) {
                        snprintf(r->old_code, sizeof(r->old_code), "LDA #0; STA $%02X", curr->operand);
                        snprintf(r->new_code, sizeof(r->new_code), "STZ $%02X", curr->operand);
                        r->bytes_saved = 2; /* LDA #0 (2) + STA zp (2) = 4, STZ zp (2) = 2, saves 2 */
                    } else if (curr->opcode == 0x95) {
                        snprintf(r->old_code, sizeof(r->old_code), "LDA #0; STA $%02X,X", curr->operand);
                        snprintf(r->new_code, sizeof(r->new_code), "STZ $%02X,X", curr->operand);
                        r->bytes_saved = 2; /* LDA #0 (2) + STA zp,X (2) = 4, STZ zp,X (2) = 2, saves 2 */
                    } else if (curr->opcode == 0x8D) {
                        snprintf(r->old_code, sizeof(r->old_code), "LDA #0; STA $%04X", curr->operand);
                        snprintf(r->new_code, sizeof(r->new_code), "STZ $%04X", curr->operand);
                        r->bytes_saved = 2; /* LDA #0 (2) + STA abs (3) = 5, STZ abs (3) = 3, saves 2 */
                    } else { /* 0x9D */
                        snprintf(r->old_code, sizeof(r->old_code), "LDA #0; STA $%04X,X", curr->operand);
                        snprintf(r->new_code, sizeof(r->new_code), "STZ $%04X,X", curr->operand);
                        r->bytes_saved = 2; /* LDA #0 (2) + STA abs,X (3) = 5, STZ abs,X (3) = 3, saves 2 */
                    }
                    replacement_count++;
                }
            }
            
            /* Check for TAX/TAY followed by PHA -> PHX/PHY */
            if ((prev->opcode == 0xAA || prev->opcode == 0xA8) && curr->opcode == 0x48) {
                if (replacement_count < MAX_REPLACEMENTS) {
                    replacement_t *r = &replacements[replacement_count];
                    if (prev->opcode == 0xAA) {
                        strcpy(r->type, "PHX");
                        snprintf(r->old_code, sizeof(r->old_code), "TAX; PHA");
                        strcpy(r->new_code, "PHX");
                    } else {
                        strcpy(r->type, "PHY");
                        snprintf(r->old_code, sizeof(r->old_code), "TAY; PHA");
                        strcpy(r->new_code, "PHY");
                    }
                    r->line_num = prev->line_num;
                    strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                    r->filename[sizeof(r->filename) - 1] = '\0';
                    r->bytes_saved = 1; /* TAX/TAY (1) + PHA (1) = 2, PHX/PHY (1) = 1, saves 1 */
                    replacement_count++;
                }
            }
            
            /* Check for PLA followed by TAX/TAY -> PLX/PLY */
            if (prev->opcode == 0x68 && (curr->opcode == 0xAA || curr->opcode == 0xA8)) {
                if (replacement_count < MAX_REPLACEMENTS) {
                    replacement_t *r = &replacements[replacement_count];
                    if (curr->opcode == 0xAA) {
                        strcpy(r->type, "PLX");
                        snprintf(r->old_code, sizeof(r->old_code), "PLA; TAX");
                        strcpy(r->new_code, "PLX");
                    } else {
                        strcpy(r->type, "PLY");
                        snprintf(r->old_code, sizeof(r->old_code), "PLA; TAY");
                        strcpy(r->new_code, "PLY");
                    }
                    r->line_num = prev->line_num;
                    strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                    r->filename[sizeof(r->filename) - 1] = '\0';
                    r->bytes_saved = 1; /* PLA (1) + TAX/TAY (1) = 2, PLX/PLY (1) = 1, saves 1 */
                    replacement_count++;
                }
            }
            
            /* Check for LDA addr; ADC #1; STA addr -> INC addr */
            if (instr_history_count >= 3) {
                instr_history_t *lda = &instr_history[instr_history_count - 3];
                instr_history_t *adc = &instr_history[instr_history_count - 2];
                instr_history_t *sta = &instr_history[instr_history_count - 1];
                
                if (lda->opcode == 0xA5 || lda->opcode == 0xAD || 
                    lda->opcode == 0xB5 || lda->opcode == 0xBD) {
                    /* LDA from memory */
                    if (adc->opcode == 0x69 && adc->operand == 1) {
                        /* ADC #1 */
                        if ((sta->opcode == 0x85 || sta->opcode == 0x8D ||
                             sta->opcode == 0x95 || sta->opcode == 0x9D) &&
                            sta->operand == lda->operand) {
                            /* STA to same address */
                            if (replacement_count < MAX_REPLACEMENTS) {
                                replacement_t *r = &replacements[replacement_count];
                                strcpy(r->type, "INC");
                                r->line_num = lda->line_num;
                                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                                r->filename[sizeof(r->filename) - 1] = '\0';
                                if (lda->opcode == 0xA5 && sta->opcode == 0x85) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; ADC #1; STA $%02X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "INC $%02X", sta->operand);
                                    r->bytes_saved = 4; /* LDA zp (2) + ADC #1 (2) + STA zp (2) = 6, INC zp (2) = 2, saves 4 */
                                } else if (lda->opcode == 0xB5 && sta->opcode == 0x95) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X,X; ADC #1; STA $%02X,X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "INC $%02X,X", sta->operand);
                                    r->bytes_saved = 4; /* LDA zp,X (2) + ADC #1 (2) + STA zp,X (2) = 6, INC zp,X (2) = 2, saves 4 */
                                } else if (lda->opcode == 0xAD && sta->opcode == 0x8D) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; ADC #1; STA $%04X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "INC $%04X", sta->operand);
                                    r->bytes_saved = 5; /* LDA abs (3) + ADC #1 (2) + STA abs (3) = 8, INC abs (3) = 3, saves 5 */
                                } else if (lda->opcode == 0xBD && sta->opcode == 0x9D) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X,X; ADC #1; STA $%04X,X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "INC $%04X,X", sta->operand);
                                    r->bytes_saved = 5; /* LDA abs,X (3) + ADC #1 (2) + STA abs,X (3) = 8, INC abs,X (3) = 3, saves 5 */
                                }
                                replacement_count++;
                            }
                        }
                    }
                    
                    /* Check for LDA addr; SBC #1; STA addr -> DEC addr */
                    if (adc->opcode == 0xE9 && adc->operand == 1) {
                        /* SBC #1 */
                        if ((sta->opcode == 0x85 || sta->opcode == 0x8D ||
                             sta->opcode == 0x95 || sta->opcode == 0x9D) &&
                            sta->operand == lda->operand) {
                            /* STA to same address */
                            if (replacement_count < MAX_REPLACEMENTS) {
                                replacement_t *r = &replacements[replacement_count];
                                strcpy(r->type, "DEC");
                                r->line_num = lda->line_num;
                                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                                r->filename[sizeof(r->filename) - 1] = '\0';
                                if (lda->opcode == 0xA5 && sta->opcode == 0x85) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; SBC #1; STA $%02X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "DEC $%02X", sta->operand);
                                    r->bytes_saved = 4; /* LDA zp (2) + SBC #1 (2) + STA zp (2) = 6, DEC zp (2) = 2, saves 4 */
                                } else if (lda->opcode == 0xB5 && sta->opcode == 0x95) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X,X; SBC #1; STA $%02X,X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "DEC $%02X,X", sta->operand);
                                    r->bytes_saved = 4; /* LDA zp,X (2) + SBC #1 (2) + STA zp,X (2) = 6, DEC zp,X (2) = 2, saves 4 */
                                } else if (lda->opcode == 0xAD && sta->opcode == 0x8D) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; SBC #1; STA $%04X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "DEC $%04X", sta->operand);
                                    r->bytes_saved = 5; /* LDA abs (3) + SBC #1 (2) + STA abs (3) = 8, DEC abs (3) = 3, saves 5 */
                                } else if (lda->opcode == 0xBD && sta->opcode == 0x9D) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X,X; SBC #1; STA $%04X,X", 
                                            sta->operand, sta->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "DEC $%04X,X", sta->operand);
                                    r->bytes_saved = 5; /* LDA abs,X (3) + SBC #1 (2) + STA abs,X (3) = 8, DEC abs,X (3) = 3, saves 5 */
                                }
                                replacement_count++;
                            }
                        }
                    }
                    
                }
                
                /* Check for TSB: LDA addr; ORA #mask; STA addr -> TSB addr (if mask is power of 2) */
                if (instr_history_count >= 3) {
                    instr_history_t *lda_tsb = &instr_history[instr_history_count - 3];
                    instr_history_t *ora = &instr_history[instr_history_count - 2];
                    instr_history_t *sta_tsb = &instr_history[instr_history_count - 1];
                    
                    if ((lda_tsb->opcode == 0xA5 || lda_tsb->opcode == 0xAD) &&
                        ora->opcode == 0x09 &&
                        (sta_tsb->opcode == 0x85 || sta_tsb->opcode == 0x8D) &&
                        sta_tsb->operand == lda_tsb->operand) {
                        /* Check if mask is a power of 2 (single bit set) */
                        uint8_t mask = ora->operand & 0xFF;
                        if (mask != 0 && (mask & (mask - 1)) == 0) {
                            if (replacement_count < MAX_REPLACEMENTS) {
                                replacement_t *r = &replacements[replacement_count];
                                strcpy(r->type, "TSB");
                                r->line_num = lda_tsb->line_num;
                                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                                r->filename[sizeof(r->filename) - 1] = '\0';
                                if (sta_tsb->opcode == 0x85) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; ORA #$%02X; STA $%02X", 
                                            sta_tsb->operand, mask, sta_tsb->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "TSB $%02X", sta_tsb->operand);
                                    r->bytes_saved = 4; /* LDA zp (2) + ORA # (2) + STA zp (2) = 6, TSB zp (2) = 2, saves 4 */
                                } else {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; ORA #$%02X; STA $%04X", 
                                            sta_tsb->operand, mask, sta_tsb->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "TSB $%04X", sta_tsb->operand);
                                    r->bytes_saved = 5; /* LDA abs (3) + ORA # (2) + STA abs (3) = 8, TSB abs (3) = 3, saves 5 */
                                }
                                replacement_count++;
                            }
                        }
                    }
                    
                    /* Check for TRB: LDA addr; AND #~mask; STA addr -> TRB addr (if mask is power of 2) */
                    if ((lda_tsb->opcode == 0xA5 || lda_tsb->opcode == 0xAD) &&
                        ora->opcode == 0x29 &&
                        (sta_tsb->opcode == 0x85 || sta_tsb->opcode == 0x8D) &&
                        sta_tsb->operand == lda_tsb->operand) {
                        /* Check if ~mask is a power of 2 (single bit clear) */
                        uint8_t and_mask = ora->operand & 0xFF;
                        uint8_t mask = (~and_mask) & 0xFF;
                        if (mask != 0 && (mask & (mask - 1)) == 0) {
                            if (replacement_count < MAX_REPLACEMENTS) {
                                replacement_t *r = &replacements[replacement_count];
                                strcpy(r->type, "TRB");
                                r->line_num = lda_tsb->line_num;
                                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                                r->filename[sizeof(r->filename) - 1] = '\0';
                                if (sta_tsb->opcode == 0x85) {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; AND #$%02X; STA $%02X", 
                                            sta_tsb->operand, and_mask, sta_tsb->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "TRB $%02X", sta_tsb->operand);
                                    r->bytes_saved = 4; /* LDA zp (2) + AND # (2) + STA zp (2) = 6, TRB zp (2) = 2, saves 4 */
                                } else {
                                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; AND #$%02X; STA $%04X", 
                                            sta_tsb->operand, and_mask, sta_tsb->operand);
                                    snprintf(r->new_code, sizeof(r->new_code), "TRB $%04X", sta_tsb->operand);
                                    r->bytes_saved = 5; /* LDA abs (3) + AND # (2) + STA abs (3) = 8, TRB abs (3) = 3, saves 5 */
                                }
                                replacement_count++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    /* Check for JMP that could be BRA */
    if (opcode == 0x4C) {  /* JMP absolute */
        extern uint16_t pc;
        /* Calculate offset from byte after BRA instruction
         * JMP is at pc-3, BRA would be at pc-3, offset calculated from pc-1 */
        int16_t offset = (int16_t)(operand - (pc - 1));
        if (offset >= -128 && offset <= 127) {
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "BRA");
                r->line_num = line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                
                /* Use the stored expression if it's a label, otherwise show offset */
                if (instr_history_count > 0) {
                    instr_history_t *jmp_hist = &instr_history[instr_history_count - 1];
                    if (jmp_hist->expression[0] != '\0') {
                        /* Check if expression looks like a label (starts with letter) vs numeric (starts with $ or digit) */
                        char first_char = jmp_hist->expression[0];
                        int is_label = ((first_char >= 'A' && first_char <= 'Z') || 
                                       (first_char >= 'a' && first_char <= 'z') || 
                                       first_char == '_');
                        if (is_label) {
                            /* It's a label, use it */
                            snprintf(r->old_code, sizeof(r->old_code), "JMP %s", jmp_hist->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "BRA %s", jmp_hist->expression);
                        } else {
                            /* It's a numeric expression, show offset */
                            snprintf(r->old_code, sizeof(r->old_code), "JMP %s", jmp_hist->expression);
                            if (offset >= 0) {
                                snprintf(r->new_code, sizeof(r->new_code), "BRA *+%d", offset);
                            } else {
                                snprintf(r->new_code, sizeof(r->new_code), "BRA *%d", offset);
                            }
                        }
                    } else {
                        snprintf(r->old_code, sizeof(r->old_code), "JMP $%04X", operand);
                        if (offset >= 0) {
                            snprintf(r->new_code, sizeof(r->new_code), "BRA *+%d", offset);
                        } else {
                            snprintf(r->new_code, sizeof(r->new_code), "BRA *%d", offset);
                        }
                    }
                } else {
                    snprintf(r->old_code, sizeof(r->old_code), "JMP $%04X", operand);
                    if (offset >= 0) {
                        snprintf(r->new_code, sizeof(r->new_code), "BRA *+%d", offset);
                    } else {
                        snprintf(r->new_code, sizeof(r->new_code), "BRA *%d", offset);
                    }
                }
                r->bytes_saved = 1; /* JMP abs (3 bytes), BRA rel (2 bytes), saves 1 */
                replacement_count++;
            }
        }
    }
}

void stats_print_report(void) {
    printf("\n=== Binary Statistics ===\n");
    printf("Total bytes in binary: %d\n", binary_size);
    printf("========================\n");
    
    printf("\n=== Opcode Statistics ===\n");
    printf("Total opcodes emitted: %d\n\n", total_opcodes);
    
    int found_any = 0;
    for (int i = 0; i < NUM_OPCODES; i++) {
        if (opcode_counts[i] > 0) {
            found_any = 1;
            const char *name = opcode_names[i];
            if (name) {
                printf("$%02X (%s): %d\n", i, name, opcode_counts[i]);
            } else {
                printf("$%02X (unknown): %d\n", i, opcode_counts[i]);
            }
        }
    }
    
    if (!found_any) {
        printf("No opcodes were emitted.\n");
    }
    
    /* Separate 65C02 statistics */
    int c02_found = 0;
    if (c02_opcode_count > 0) {
        printf("\n=== 65C02 Opcode Statistics ===\n");
        printf("Total 65C02 opcodes: %d\n\n", c02_opcode_count);
        
        for (int i = 0; i < NUM_OPCODES; i++) {
            if (opcode_counts[i] > 0 && stats_is_c02_opcode(i)) {
                c02_found = 1;
                const char *name = opcode_names[i];
                if (name) {
                    printf("$%02X (%s): %d\n", i, name, opcode_counts[i]);
                } else {
                    printf("$%02X (unknown C02): %d\n", i, opcode_counts[i]);
                }
            }
        }
        
        if (!c02_found) {
            printf("No 65C02 opcodes were emitted.\n");
        }
        printf("==============================\n");
    }
    
    printf("========================\n");
    
    /* Print zero transfer statistics */
    if (zero_transfer_count > 0) {
        printf("\n=== Zero Constant Transfers ===\n");
        printf("Total zero transfers: %d\n\n", zero_transfer_count);
        
        for (int i = 0; i < zero_transfer_count; i++) {
            zero_transfer_t *zt = &zero_transfers[i];
            if (zt->is_register) {
                printf("  %s -> register\n", zt->instruction);
            } else {
                if (zt->address < 256) {
                    printf("  %s -> memory ($%02X)\n", zt->instruction, zt->address);
                } else {
                    printf("  %s -> memory ($%04X)\n", zt->instruction, zt->address);
                }
            }
        }
        printf("================================\n");
    }
    
    /* Print replacement opportunities */
    if (replacement_count > 0) {
        int total_bytes_saved = 0;
        for (int i = 0; i < replacement_count; i++) {
            total_bytes_saved += replacements[i].bytes_saved;
        }
        
        printf("\n=== 65C02 Replacement Opportunities ===\n");
        printf("Total possible replacements: %d\n", replacement_count);
        printf("Total bytes saved: %d", total_bytes_saved);
        if (binary_size > 0) {
            double percent = (double)total_bytes_saved * 100.0 / (double)binary_size;
            printf(" (%.1f%% of %d bytes)", percent, binary_size);
        }
        printf("\n\n");
        
        /* Group by type */
        int stz_count = 0, phx_count = 0, phy_count = 0, plx_count = 0, ply_count = 0, bra_count = 0;
        int inc_count = 0, dec_count = 0, tsb_count = 0, trb_count = 0;
        
        for (int i = 0; i < replacement_count; i++) {
            replacement_t *r = &replacements[i];
            if (strcmp(r->type, "STZ") == 0) stz_count++;
            else if (strcmp(r->type, "PHX") == 0) phx_count++;
            else if (strcmp(r->type, "PHY") == 0) phy_count++;
            else if (strcmp(r->type, "PLX") == 0) plx_count++;
            else if (strcmp(r->type, "PLY") == 0) ply_count++;
            else if (strcmp(r->type, "BRA") == 0) bra_count++;
            else if (strcmp(r->type, "INC") == 0) inc_count++;
            else if (strcmp(r->type, "DEC") == 0) dec_count++;
            else if (strcmp(r->type, "TSB") == 0) tsb_count++;
            else if (strcmp(r->type, "TRB") == 0) trb_count++;
        }
        
        if (stz_count > 0) printf("  STZ replacements: %d\n", stz_count);
        if (phx_count > 0) printf("  PHX replacements: %d\n", phx_count);
        if (phy_count > 0) printf("  PHY replacements: %d\n", phy_count);
        if (plx_count > 0) printf("  PLX replacements: %d\n", plx_count);
        if (ply_count > 0) printf("  PLY replacements: %d\n", ply_count);
        if (bra_count > 0) printf("  BRA replacements: %d\n", bra_count);
        if (inc_count > 0) printf("  INC replacements: %d\n", inc_count);
        if (dec_count > 0) printf("  DEC replacements: %d\n", dec_count);
        if (tsb_count > 0) printf("  TSB replacements: %d\n", tsb_count);
        if (trb_count > 0) printf("  TRB replacements: %d\n", trb_count);
        
        printf("\nDetailed replacements:\n");
        for (int i = 0; i < replacement_count; i++) {
            replacement_t *r = &replacements[i];
            printf("  %s: %s:%d\n", r->type, r->filename, r->line_num);
            printf("    Old: %s\n", r->old_code);
            printf("    New: %s\n", r->new_code);
        }
        printf("========================================\n");
    }
}

void stats_print_report_custom(int print_stats, int show_suggestions) {
    if (print_stats) {
        /* Print binary statistics */
        printf("\n=== Binary Statistics ===\n");
        printf("Total bytes in binary: %d\n", binary_size);
        printf("========================\n");
        
        /* Print opcode statistics */
        printf("\n=== Opcode Statistics ===\n");
        printf("Total opcodes emitted: %d\n\n", total_opcodes);
        
        int found_any = 0;
        for (int i = 0; i < NUM_OPCODES; i++) {
            if (opcode_counts[i] > 0) {
                found_any = 1;
                const char *name = opcode_names[i];
                if (name) {
                    printf("$%02X (%s): %d\n", i, name, opcode_counts[i]);
                } else {
                    printf("$%02X (unknown): %d\n", i, opcode_counts[i]);
                }
            }
        }
        
        if (!found_any) {
            printf("No opcodes were emitted.\n");
        }
        
        /* Separate 65C02 statistics */
        int c02_found = 0;
        if (c02_opcode_count > 0) {
            printf("\n=== 65C02 Opcode Statistics ===\n");
            printf("Total 65C02 opcodes: %d\n\n", c02_opcode_count);
            
            for (int i = 0; i < NUM_OPCODES; i++) {
                if (opcode_counts[i] > 0 && stats_is_c02_opcode(i)) {
                    c02_found = 1;
                    const char *name = opcode_names[i];
                    if (name) {
                        printf("$%02X (%s): %d\n", i, name, opcode_counts[i]);
                    } else {
                        printf("$%02X (unknown C02): %d\n", i, opcode_counts[i]);
                    }
                }
            }
            
            if (!c02_found) {
                printf("No 65C02 opcodes were emitted.\n");
            }
            printf("==============================\n");
        }
        
        printf("========================\n");
        
        /* Print zero transfer statistics */
        if (zero_transfer_count > 0) {
            printf("\n=== Zero Constant Transfers ===\n");
            printf("Total zero transfers: %d\n", zero_transfer_count);
            printf("================================\n");
        }
        
        /* Print replacement count summary */
        if (replacement_count > 0) {
            int total_bytes_saved = 0;
            for (int i = 0; i < replacement_count; i++) {
                total_bytes_saved += replacements[i].bytes_saved;
            }
            
            printf("\n=== 65C02 Replacement Opportunities ===\n");
            printf("Total possible replacements: %d\n", replacement_count);
            printf("Total bytes saved: %d", total_bytes_saved);
            if (binary_size > 0) {
                double percent = (double)total_bytes_saved * 100.0 / (double)binary_size;
                printf(" (%.1f%% of %d bytes)", percent, binary_size);
            }
            printf("\n");
            
            /* Group by type */
            int stz_count = 0, phx_count = 0, phy_count = 0, plx_count = 0, ply_count = 0, bra_count = 0;
            int inc_count = 0, dec_count = 0, tsb_count = 0, trb_count = 0;
            
            for (int i = 0; i < replacement_count; i++) {
                replacement_t *r = &replacements[i];
                if (strcmp(r->type, "STZ") == 0) stz_count++;
                else if (strcmp(r->type, "PHX") == 0) phx_count++;
                else if (strcmp(r->type, "PHY") == 0) phy_count++;
                else if (strcmp(r->type, "PLX") == 0) plx_count++;
                else if (strcmp(r->type, "PLY") == 0) ply_count++;
                else if (strcmp(r->type, "BRA") == 0) bra_count++;
                else if (strcmp(r->type, "INC") == 0) inc_count++;
                else if (strcmp(r->type, "DEC") == 0) dec_count++;
                else if (strcmp(r->type, "TSB") == 0) tsb_count++;
                else if (strcmp(r->type, "TRB") == 0) trb_count++;
            }
            
            if (stz_count > 0) printf("  STZ replacements: %d\n", stz_count);
            if (phx_count > 0) printf("  PHX replacements: %d\n", phx_count);
            if (phy_count > 0) printf("  PHY replacements: %d\n", phy_count);
            if (plx_count > 0) printf("  PLX replacements: %d\n", plx_count);
            if (ply_count > 0) printf("  PLY replacements: %d\n", ply_count);
            if (bra_count > 0) printf("  BRA replacements: %d\n", bra_count);
            if (inc_count > 0) printf("  INC replacements: %d\n", inc_count);
            if (dec_count > 0) printf("  DEC replacements: %d\n", dec_count);
            if (tsb_count > 0) printf("  TSB replacements: %d\n", tsb_count);
            if (trb_count > 0) printf("  TRB replacements: %d\n", trb_count);
            
            printf("========================================\n");
        }
    }
    
    if (show_suggestions && replacement_count > 0) {
        printf("\n=== 65C02 Replacement Suggestions ===\n");
        for (int i = 0; i < replacement_count; i++) {
            replacement_t *r = &replacements[i];
            printf("  %s: %s:%d\n", r->type, r->filename, r->line_num);
            printf("    Old: %s\n", r->old_code);
            printf("    New: %s\n", r->new_code);
        }
        printf("======================================\n");
    }
}

int stats_get_count(uint8_t opcode) {
    return opcode_counts[opcode];
}

int stats_is_c02_opcode(uint8_t opcode) {
    for (int i = 0; i < NUM_C02_OPCODES; i++) {
        if (c02_opcodes[i] == opcode) {
            return 1;
        }
    }
    return 0;
}

int stats_get_c02_count(void) {
    return c02_opcode_count;
}

void stats_record_zero_to_register(const char *instruction) {
    if (zero_transfer_count >= MAX_ZERO_TRANSFERS) {
        return; /* Silently ignore if buffer is full */
    }
    
    zero_transfer_t *zt = &zero_transfers[zero_transfer_count];
    strncpy(zt->instruction, instruction, sizeof(zt->instruction) - 1);
    zt->instruction[sizeof(zt->instruction) - 1] = '\0';
    zt->address = 0xFFFF; /* Marker for register transfer */
    zt->is_register = 1;
    zero_transfer_count++;
}

void stats_record_zero_to_memory(const char *instruction, uint16_t address) {
    if (zero_transfer_count >= MAX_ZERO_TRANSFERS) {
        return; /* Silently ignore if buffer is full */
    }
    
    zero_transfer_t *zt = &zero_transfers[zero_transfer_count];
    strncpy(zt->instruction, instruction, sizeof(zt->instruction) - 1);
    zt->instruction[sizeof(zt->instruction) - 1] = '\0';
    zt->address = address;
    zt->is_register = 0;
    zero_transfer_count++;
}


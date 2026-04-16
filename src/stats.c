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
static int immediate_zero_counts[NUM_OPCODES];
static int total_opcodes = 0;
static int total_opcode_bytes = 0;  /* Total bytes used by opcodes (1, 2, or 3 bytes each) */
static int total_immediate_zero = 0;
static int sta_zero_count = 0;
static int c02_opcode_count = 0;
static char *current_filename = NULL;
static int binary_size = 0;
static int total_jmp_count = 0;  /* Total number of JMP instructions */
static int total_jsr_count = 0;  /* Total number of JSR instructions */
static int total_lines = 0;  /* Total number of lines in source file */
static int non_blank_lines = 0;  /* Number of non-blank lines */
static int total_characters = 0;  /* Total number of characters in source file */

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
    char old_code[256];
    char new_code[256];
    int bytes_saved;  /* Number of bytes saved by this replacement */
    uint16_t instr_addr;  /* Address of the instruction (for BRA replacements) */
    uint16_t target_addr;  /* Target address (for BRA replacements) */
} replacement_t;

static replacement_t replacements[MAX_REPLACEMENTS];
static int replacement_count = 0;

/* Optimizations (more complex pattern replacements) */
static replacement_t optimizations[MAX_REPLACEMENTS];
static int optimization_count = 0;

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
    [0x16] = "ASL zp,X", [0x18] = "CLC", [0x19] = "ORA abs,Y", [0x1A] = "INC A (C02)", [0x1D] = "ORA abs,X",
    [0x1E] = "ASL abs,X", [0x20] = "JSR", [0x21] = "AND (ind,X)", [0x24] = "BIT zp",
    [0x25] = "AND zp", [0x26] = "ROL zp", [0x28] = "PLP", [0x29] = "AND #",
    [0x2A] = "ROL A", [0x2C] = "BIT abs", [0x2D] = "AND abs", [0x2E] = "ROL abs",
    [0x30] = "BMI", [0x31] = "AND (ind),Y", [0x35] = "AND zp,X", [0x36] = "ROL zp,X",
    [0x38] = "SEC", [0x39] = "AND abs,Y", [0x3A] = "DEC A (C02)", [0x3D] = "AND abs,X", [0x3E] = "ROL abs,X",
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
    [0xBE] = "LDX abs,Y", [0xC0] = "CPY #", [0xC1] = "CMP (ind,X)", [0xC2] = "INW (C02)", [0xC3] = "DEW (C02)", [0xC4] = "CPY zp",
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
    [0xDA] = "PHX (C02)", [0xDB] = "STP (C02)", [0xF4] = "PHW (C02)", [0xFA] = "PLX (C02)"
};

/* 65C02 opcodes */
static const uint8_t c02_opcodes[] = {
    0x04, 0x0C, 0x14, 0x1A, 0x1C, 0x3A, 0x5A, 0x64, 0x74, 0x7A,
    0x80, 0x9C, 0x9E, 0xC2, 0xC3, 0xCB, 0xDA, 0xDB, 0xF4, 0xFA
};
#define NUM_C02_OPCODES (sizeof(c02_opcodes) / sizeof(c02_opcodes[0]))

void stats_init(void) {
    memset(opcode_counts, 0, sizeof(opcode_counts));
    memset(immediate_zero_counts, 0, sizeof(immediate_zero_counts));
    total_opcodes = 0;
    total_opcode_bytes = 0;
    total_immediate_zero = 0;
    sta_zero_count = 0;
    zero_transfer_count = 0;
    c02_opcode_count = 0;
    instr_history_count = 0;
    replacement_count = 0;
    optimization_count = 0;
    total_jmp_count = 0;
    total_jsr_count = 0;
    /* Note: current_filename and binary_size are not reset - they're set externally */
}

void stats_set_binary_size(int size) {
    binary_size = size;
}

/* Count assembler statistics from source file */
void stats_count_source_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        total_lines = 0;
        non_blank_lines = 0;
        total_characters = 0;
        return;
    }
    
    total_lines = 0;
    non_blank_lines = 0;
    total_characters = 0;
    
    char line[4096];
    while (fgets(line, sizeof(line), f)) {
        total_lines++;
        total_characters += strlen(line);
        
        /* Check if line is non-blank (contains at least one non-whitespace character) */
        int has_non_blank = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r') {
                has_non_blank = 1;
                break;
            }
        }
        if (has_non_blank) {
            non_blank_lines++;
        }
    }
    
    fclose(f);
}

void stats_set_filename(const char *filename) {
    if (current_filename) {
        free(current_filename);
    }
    current_filename = filename ? strdup(filename) : NULL;
}

/* Track PC at start of instruction for size calculation */
uint16_t instruction_start_pc = 0xFFFF;

void stats_record_opcode(uint8_t opcode) {
    extern uint16_t pc;
    if (instruction_start_pc == 0xFFFF) {
        instruction_start_pc = pc;  /* Record PC before opcode is emitted */
    }
    opcode_counts[opcode]++;
    total_opcodes++;
    if (stats_is_c02_opcode(opcode)) {
        c02_opcode_count++;
    }
}

/* Call this after an instruction is complete to record its actual size */
void stats_record_instruction_size(void) {
    extern uint16_t pc;
    if (instruction_start_pc != 0xFFFF) {
        int size = pc - instruction_start_pc;
        if (size > 0 && size <= 3) {  /* Sanity check: instructions are 1-3 bytes */
            total_opcode_bytes += size;
        }
        instruction_start_pc = 0xFFFF;  /* Reset for next instruction */
    }
}

void stats_record_immediate_zero(uint8_t opcode) {
    immediate_zero_counts[opcode]++;
    total_immediate_zero++;
}

void stats_record_sta_zero(void) {
    sta_zero_count++;
}

void stats_record_instruction(uint8_t opcode, const char *instr_name, uint16_t operand, int line_num, const char *filename, const char *expression) {
    /* Count JMP and JSR instructions */
    if (opcode == 0x4C) {  /* JMP absolute */
        total_jmp_count++;
    } else if (opcode == 0x20) {  /* JSR absolute */
        total_jsr_count++;
    }
    
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
    
    /* Check for branch-over-JMP optimization: branch followed by JMP where JMP target is within branch range */
    /* This check must be AFTER the current instruction is added to history */
    if (opcode == 0x4C && instr_history_count >= 2) {  /* JMP absolute */
        instr_history_t *branch = &instr_history[instr_history_count - 2];  /* Branch is 2 instructions back */
        
        /* Check if previous instruction was a branch */
        uint8_t branch_opcodes[] = {0x10, 0x30, 0x50, 0x70, 0x90, 0xB0, 0xD0, 0xF0};  /* BPL, BMI, BVC, BVS, BCC, BCS, BNE, BEQ */
        int is_branch = 0;
        for (int i = 0; i < 8; i++) {
            if (branch->opcode == branch_opcodes[i]) {
                is_branch = 1;
                break;
            }
        }
        
        if (is_branch) {
            /* Calculate offset from branch instruction to JMP target */
            extern uint16_t pc;
            /* branch->pc_at_instruction is PC after the branch (branch_addr + 2) */
            uint16_t branch_addr = branch->pc_at_instruction - 2;  /* Address of branch instruction */
            /* Current PC is after JMP, so JMP address is pc - 3 */
            uint16_t jmp_target = operand;
            
            /* Calculate offset from branch instruction to JMP target */
            /* Offset is calculated from the byte after the branch instruction (branch_addr + 2) */
            int16_t offset = (int16_t)(jmp_target - (branch_addr + 2));
            
            /* Check if JMP target is within branch range */
            if (offset >= -128 && offset <= 127) {
                if (optimization_count < MAX_REPLACEMENTS) {
                    replacement_t *r = &optimizations[optimization_count];
                    
                    /* Determine inverted branch name */
                    const char *inverted_name = NULL;
                    const char *branch_name = branch->instr_name;
                    
                    if (branch->opcode == 0xF0) { /* BEQ -> BNE */
                        inverted_name = "BNE";
                    } else if (branch->opcode == 0xD0) { /* BNE -> BEQ */
                        inverted_name = "BEQ";
                    } else if (branch->opcode == 0x90) { /* BCC -> BCS */
                        inverted_name = "BCS";
                    } else if (branch->opcode == 0xB0) { /* BCS -> BCC */
                        inverted_name = "BCC";
                    } else if (branch->opcode == 0x10) { /* BPL -> BMI */
                        inverted_name = "BMI";
                    } else if (branch->opcode == 0x30) { /* BMI -> BPL */
                        inverted_name = "BPL";
                    } else if (branch->opcode == 0x50) { /* BVC -> BVS */
                        inverted_name = "BVS";
                    } else if (branch->opcode == 0x70) { /* BVS -> BVC */
                        inverted_name = "BVC";
                    }
                    
                    if (inverted_name) {
                        strcpy(r->type, "Branch+JMP");
                        r->line_num = branch->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        
                        /* Build old and new code strings */
                        const char *jmp_expr = expression ? expression : "";
                        if (branch->expression[0] != '\0' && jmp_expr[0] != '\0') {
                            snprintf(r->old_code, sizeof(r->old_code), "%s %s; JMP %s", branch_name, branch->expression, jmp_expr);
                            snprintf(r->new_code, sizeof(r->new_code), "%s %s", inverted_name, jmp_expr);
                        } else {
                            /* Calculate branch target (skip over JMP) */
                            uint16_t branch_target_calc = branch_addr + 2 + (int8_t)(branch->operand & 0xFF);
                            snprintf(r->old_code, sizeof(r->old_code), "%s $%04X; JMP $%04X", branch_name, branch_target_calc, jmp_target);
                            snprintf(r->new_code, sizeof(r->new_code), "%s $%04X", inverted_name, jmp_target);
                        }
                        r->bytes_saved = 3; /* Branch (2 bytes) + JMP (3 bytes) = 5, Inverted branch (2 bytes) = 2, saves 3 */
                        optimization_count++;
                    }
                }
            }
        }
    }
    
    /* Check for replacement patterns */
    if (instr_history_count >= 2) {
        /* Check for LDA #0 followed by STA -> STZ */
        if (instr_history_count >= 2) {
            instr_history_t *prev = &instr_history[instr_history_count - 2];
            instr_history_t *curr = &instr_history[instr_history_count - 1];
            
            /* Check if LDA has explicit #0 or #$0 (not just a symbol that evaluates to zero) */
            int is_explicit_zero = 0;
            if (prev->opcode == 0xA9 && prev->operand == 0 && prev->expression[0] != '\0') {
                /* Check if expression is explicitly 0, $0, $00 (the # is a separate token) */
                const char *expr = prev->expression;
                /* Expression for immediate instructions will be "0", "$0", "$00", etc. (without #) */
                if (strcmp(expr, "0") == 0 || 
                    strcmp(expr, "$0") == 0 || 
                    strcmp(expr, "$00") == 0) {
                    is_explicit_zero = 1;
                }
            }
            
            if (prev->opcode == 0xA9 && is_explicit_zero && 
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
            
            /* Simple 65C02 replacements: ADC #1 -> INA, SBC #1 -> DEA */
            if (instr_history_count >= 1) {
                instr_history_t *instr = &instr_history[instr_history_count - 1];
                
                if (instr->opcode == 0x69 && instr->operand == 1) {
                    /* ADC #1 -> INA */
                    if (replacement_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &replacements[replacement_count];
                        strcpy(r->type, "INA");
                        r->line_num = instr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "ADC #1");
                        snprintf(r->new_code, sizeof(r->new_code), "INA");
                        r->bytes_saved = 1; /* ADC #1 (2 bytes), INA (1 byte), saves 1 */
                        replacement_count++;
                    }
                } else if (instr->opcode == 0xE9 && instr->operand == 1) {
                    /* SBC #1 -> DEA */
                    if (replacement_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &replacements[replacement_count];
                        strcpy(r->type, "DEA");
                        r->line_num = instr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "SBC #1");
                        snprintf(r->new_code, sizeof(r->new_code), "DEA");
                        r->bytes_saved = 1; /* SBC #1 (2 bytes), DEA (1 byte), saves 1 */
                        replacement_count++;
                    }
                }
            }
            
            /* Optimizations: LDA addr; ADC #1; STA addr -> INC addr */
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
                            if (optimization_count < MAX_REPLACEMENTS) {
                                replacement_t *r = &optimizations[optimization_count];
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
                                optimization_count++;
                            }
                        }
                    }
                    
                    /* Optimizations: LDA addr; SBC #1; STA addr -> DEC addr */
                    if (adc->opcode == 0xE9 && adc->operand == 1) {
                        /* SBC #1 */
                        if ((sta->opcode == 0x85 || sta->opcode == 0x8D ||
                             sta->opcode == 0x95 || sta->opcode == 0x9D) &&
                            sta->operand == lda->operand) {
                            /* STA to same address */
                            if (optimization_count < MAX_REPLACEMENTS) {
                                replacement_t *r = &optimizations[optimization_count];
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
                                optimization_count++;
                            }
                        }
                    }
                }
            }
            
            /* Optimizations: LDA #value; LDX #value -> LDA #value; TAX (if same value) */
            if (instr_history_count >= 2) {
                instr_history_t *lda = &instr_history[instr_history_count - 2];
                instr_history_t *ldx = &instr_history[instr_history_count - 1];
                
                if (lda->opcode == 0xA9 && ldx->opcode == 0xA2 && lda->operand == ldx->operand) {
                    /* LDA #value followed by LDX #value with same value */
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "TAX");
                        r->line_num = lda->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (lda->expression[0] != '\0') {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA #%s; LDX #%s", lda->expression, ldx->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "LDA #%s; TAX", lda->expression);
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA #$%02X; LDX #$%02X", lda->operand, ldx->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDA #$%02X; TAX", lda->operand);
                        }
                        r->bytes_saved = 1; /* LDX # (2 bytes), TAX (1 byte), saves 1 */
                        optimization_count++;
                    }
                }
            }
            
            /* Optimizations: LDA #value; LDY #value -> LDA #value; TAY (if same value) */
            if (instr_history_count >= 2) {
                instr_history_t *lda = &instr_history[instr_history_count - 2];
                instr_history_t *ldy = &instr_history[instr_history_count - 1];
                
                if (lda->opcode == 0xA9 && ldy->opcode == 0xA0 && lda->operand == ldy->operand) {
                    /* LDA #value followed by LDY #value with same value */
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "TAY");
                        r->line_num = lda->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (lda->expression[0] != '\0') {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA #%s; LDY #%s", lda->expression, ldy->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "LDA #%s; TAY", lda->expression);
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA #$%02X; LDY #$%02X", lda->operand, ldy->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDA #$%02X; TAY", lda->operand);
                        }
                        r->bytes_saved = 1; /* LDY # (2 bytes), TAY (1 byte), saves 1 */
                        optimization_count++;
                    }
                }
            }
            
            /* Check for redundant logical operations */
            if (instr_history_count >= 1) {
                instr_history_t *curr = &instr_history[instr_history_count - 1];
                
                /* AND #$FF -> remove (redundant) */
                if (curr->opcode == 0x29 && (curr->operand & 0xFF) == 0xFF) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Redundant");
                        r->line_num = curr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "AND #$FF");
                        snprintf(r->new_code, sizeof(r->new_code), "(remove - redundant)");
                        r->bytes_saved = 2; /* AND # (2 bytes) */
                        optimization_count++;
                    }
                }
                
                /* ORA #0 -> remove (redundant) */
                if (curr->opcode == 0x09 && curr->operand == 0) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Redundant");
                        r->line_num = curr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "ORA #0");
                        snprintf(r->new_code, sizeof(r->new_code), "(remove - redundant)");
                        r->bytes_saved = 2; /* ORA # (2 bytes) */
                        optimization_count++;
                    }
                }
                
                /* EOR #0 -> remove (redundant) */
                if (curr->opcode == 0x49 && curr->operand == 0) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Redundant");
                        r->line_num = curr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "EOR #0");
                        snprintf(r->new_code, sizeof(r->new_code), "(remove - redundant)");
                        r->bytes_saved = 2; /* EOR # (2 bytes) */
                        optimization_count++;
                    }
                }
            }
            
            /* Check for register transfer pairs */
            if (instr_history_count >= 2) {
                instr_history_t *prev = &instr_history[instr_history_count - 2];
                instr_history_t *curr = &instr_history[instr_history_count - 1];
                
                /* TAX, TXA -> TAX */
                if (prev->opcode == 0xAA && curr->opcode == 0x8A) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Register");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "TAX; TXA");
                        snprintf(r->new_code, sizeof(r->new_code), "TAX");
                        r->bytes_saved = 1; /* TXA (1 byte) */
                        optimization_count++;
                    }
                }
                
                /* TXA, TAX -> TXA */
                if (prev->opcode == 0x8A && curr->opcode == 0xAA) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Register");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "TXA; TAX");
                        snprintf(r->new_code, sizeof(r->new_code), "TXA");
                        r->bytes_saved = 1; /* TAX (1 byte) */
                        optimization_count++;
                    }
                }
                
                /* TAY, TYA -> TAY */
                if (prev->opcode == 0xA8 && curr->opcode == 0x98) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Register");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "TAY; TYA");
                        snprintf(r->new_code, sizeof(r->new_code), "TAY");
                        r->bytes_saved = 1; /* TYA (1 byte) */
                        optimization_count++;
                    }
                }
                
                /* TYA, TAY -> TYA */
                if (prev->opcode == 0x98 && curr->opcode == 0xA8) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Register");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "TYA; TAY");
                        snprintf(r->new_code, sizeof(r->new_code), "TYA");
                        r->bytes_saved = 1; /* TAY (1 byte) */
                        optimization_count++;
                    }
                }
                
                /* TXS, TSX -> TXS */
                if (prev->opcode == 0x9A && curr->opcode == 0xBA) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Register");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "TXS; TSX");
                        snprintf(r->new_code, sizeof(r->new_code), "TXS");
                        r->bytes_saved = 1; /* TSX (1 byte) */
                        optimization_count++;
                    }
                }
                
                /* TSX, TXS -> TSX */
                if (prev->opcode == 0xBA && curr->opcode == 0x9A) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Register");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        snprintf(r->old_code, sizeof(r->old_code), "TSX; TXS");
                        snprintf(r->new_code, sizeof(r->new_code), "TSX");
                        r->bytes_saved = 1; /* TXS (1 byte) */
                        optimization_count++;
                    }
                }
            }
            
            /* Check for load/store pairs (same address) */
            if (instr_history_count >= 2) {
                instr_history_t *prev = &instr_history[instr_history_count - 2];
                instr_history_t *curr = &instr_history[instr_history_count - 1];
                
                /* LDA addr, STA addr -> LDA addr */
                if ((prev->opcode == 0xA5 || prev->opcode == 0xAD || prev->opcode == 0xB5 || prev->opcode == 0xBD || prev->opcode == 0xB9) &&
                    (curr->opcode == 0x85 || curr->opcode == 0x8D || curr->opcode == 0x95 || curr->opcode == 0x9D || curr->opcode == 0x99) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; STA $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDA $%02X", prev->operand);
                            r->bytes_saved = 2; /* STA zp (2 bytes) */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; STA $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDA $%04X", prev->operand);
                            r->bytes_saved = 3; /* STA abs (3 bytes) */
                        }
                        optimization_count++;
                    }
                }
                
                /* STA addr, LDA addr -> STA addr */
                if ((prev->opcode == 0x85 || prev->opcode == 0x8D || prev->opcode == 0x95 || prev->opcode == 0x9D || prev->opcode == 0x99) &&
                    (curr->opcode == 0xA5 || curr->opcode == 0xAD || curr->opcode == 0xB5 || curr->opcode == 0xBD || curr->opcode == 0xB9) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "STA $%02X; LDA $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STA $%02X", prev->operand);
                            r->bytes_saved = 2; /* LDA zp (2 bytes) */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "STA $%04X; LDA $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STA $%04X", prev->operand);
                            r->bytes_saved = 3; /* LDA abs (3 bytes) */
                        }
                        optimization_count++;
                    }
                }
                
                /* LDX addr, STX addr -> LDX addr */
                if ((prev->opcode == 0xA6 || prev->opcode == 0xAE || prev->opcode == 0xB6 || prev->opcode == 0xBE) &&
                    (curr->opcode == 0x86 || curr->opcode == 0x8E || curr->opcode == 0x96) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "LDX $%02X; STX $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDX $%02X", prev->operand);
                            r->bytes_saved = 2; /* STX zp (2 bytes) */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LDX $%04X; STX $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDX $%04X", prev->operand);
                            r->bytes_saved = 3; /* STX abs (3 bytes) */
                        }
                        optimization_count++;
                    }
                }
                
                /* LDY addr, STY addr -> LDY addr */
                if ((prev->opcode == 0xA4 || prev->opcode == 0xAC || prev->opcode == 0xB4 || prev->opcode == 0xBC) &&
                    (curr->opcode == 0x84 || curr->opcode == 0x8C || curr->opcode == 0x94) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "LDY $%02X; STY $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDY $%02X", prev->operand);
                            r->bytes_saved = 2; /* STY zp (2 bytes) */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LDY $%04X; STY $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "LDY $%04X", prev->operand);
                            r->bytes_saved = 3; /* STY abs (3 bytes) */
                        }
                        optimization_count++;
                    }
                }
                
                /* STA addr, LDX addr -> STA addr, TAX (if same address) */
                if ((prev->opcode == 0x85 || prev->opcode == 0x8D || prev->opcode == 0x95 || prev->opcode == 0x9D || prev->opcode == 0x99) &&
                    (curr->opcode == 0xA6 || curr->opcode == 0xAE || curr->opcode == 0xB6 || curr->opcode == 0xBE) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "STA $%02X; LDX $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STA $%02X; TAX", prev->operand);
                            r->bytes_saved = 1; /* LDX zp (2 bytes) -> TAX (1 byte), saves 1 */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "STA $%04X; LDX $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STA $%04X; TAX", prev->operand);
                            r->bytes_saved = 2; /* LDX abs (3 bytes) -> TAX (1 byte), saves 2 */
                        }
                        optimization_count++;
                    }
                }
                
                /* STA addr, LDY addr -> STA addr, TAY (if same address) */
                if ((prev->opcode == 0x85 || prev->opcode == 0x8D || prev->opcode == 0x95 || prev->opcode == 0x9D || prev->opcode == 0x99) &&
                    (curr->opcode == 0xA4 || curr->opcode == 0xAC || curr->opcode == 0xB4 || curr->opcode == 0xBC) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "STA $%02X; LDY $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STA $%02X; TAY", prev->operand);
                            r->bytes_saved = 1; /* LDY zp (2 bytes) -> TAY (1 byte), saves 1 */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "STA $%04X; LDY $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STA $%04X; TAY", prev->operand);
                            r->bytes_saved = 2; /* LDY abs (3 bytes) -> TAY (1 byte), saves 2 */
                        }
                        optimization_count++;
                    }
                }
                
                /* STX addr, LDA addr -> STX addr, TXA (if same address) */
                if ((prev->opcode == 0x86 || prev->opcode == 0x8E || prev->opcode == 0x96) &&
                    (curr->opcode == 0xA5 || curr->opcode == 0xAD || curr->opcode == 0xB5 || curr->opcode == 0xBD || curr->opcode == 0xB9) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "STX $%02X; LDA $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STX $%02X; TXA", prev->operand);
                            r->bytes_saved = 1; /* LDA zp (2 bytes) -> TXA (1 byte), saves 1 */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "STX $%04X; LDA $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STX $%04X; TXA", prev->operand);
                            r->bytes_saved = 2; /* LDA abs (3 bytes) -> TXA (1 byte), saves 2 */
                        }
                        optimization_count++;
                    }
                }
                
                /* STY addr, LDA addr -> STY addr, TYA (if same address) */
                if ((prev->opcode == 0x84 || prev->opcode == 0x8C || prev->opcode == 0x94) &&
                    (curr->opcode == 0xA5 || curr->opcode == 0xAD || curr->opcode == 0xB5 || curr->opcode == 0xBD || curr->opcode == 0xB9) &&
                    prev->operand == curr->operand) {
                    if (optimization_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &optimizations[optimization_count];
                        strcpy(r->type, "Load/Store");
                        r->line_num = prev->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        if (prev->operand < 256) {
                            snprintf(r->old_code, sizeof(r->old_code), "STY $%02X; LDA $%02X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STY $%02X; TYA", prev->operand);
                            r->bytes_saved = 1; /* LDA zp (2 bytes) -> TYA (1 byte), saves 1 */
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "STY $%04X; LDA $%04X", prev->operand, curr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "STY $%04X; TYA", prev->operand);
                            r->bytes_saved = 2; /* LDA abs (3 bytes) -> TYA (1 byte), saves 2 */
                        }
                        optimization_count++;
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
    
    /* Check for 65CE02 long branch opportunities: Conditional branch over JMP */
    if (opcode == 0x4C) {  /* JMP absolute */
        /* Pattern: [conditional branch +3] [JMP addr] -> [inverted_branch addr (16-bit)] */
        if (instr_history_count >= 1) {
            instr_history_t *prev = &instr_history[instr_history_count - 1];
            /* Check if previous instruction is a conditional branch with offset of +3 */
            uint8_t prev_opcode = prev->opcode;
            int is_conditional_branch = (prev_opcode == 0x10 || prev_opcode == 0x30 || prev_opcode == 0x50 || 
                                        prev_opcode == 0x70 || prev_opcode == 0x90 || prev_opcode == 0xB0 || 
                                        prev_opcode == 0xD0 || prev_opcode == 0xF0);
            
            if (is_conditional_branch && prev->operand == 3) {
                /* Found the pattern! Record as 65CE02 long branch opportunity */
                if (replacement_count < MAX_REPLACEMENTS) {
                    replacement_t *r = &replacements[replacement_count];
                    strcpy(r->type, "LONG_BRANCH");
                    r->line_num = line_num;
                    strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                    r->filename[sizeof(r->filename) - 1] = '\0';
                    r->instr_addr = (uint16_t)(pc - 5);  /* Address of the branch instruction */
                    r->target_addr = operand;  /* Target of the JMP */
                    
                    /* Determine inverse branch opcode name */
                    const char *branch_name = "";
                    const char *inverse_name = "";
                    switch (prev_opcode) {
                        case 0x10: branch_name = "BPL"; inverse_name = "BMI"; break;  /* Branch on Plus */
                        case 0x30: branch_name = "BMI"; inverse_name = "BPL"; break;  /* Branch on Minus */
                        case 0x50: branch_name = "BVC"; inverse_name = "BVS"; break;  /* Branch on Overflow Clear */
                        case 0x70: branch_name = "BVS"; inverse_name = "BVC"; break;  /* Branch on Overflow Set */
                        case 0x90: branch_name = "BCC"; inverse_name = "BCS"; break;  /* Branch on Carry Clear */
                        case 0xB0: branch_name = "BCS"; inverse_name = "BCC"; break;  /* Branch on Carry Set */
                        case 0xD0: branch_name = "BNE"; inverse_name = "BEQ"; break;  /* Branch on Not Equal */
                        case 0xF0: branch_name = "BEQ"; inverse_name = "BNE"; break;  /* Branch on Equal */
                    }
                    
                    /* Use the stored expression if it's a label, otherwise show numeric offset */
                    if (instr_history_count > 0 && instr_history[instr_history_count - 1].expression[0] != '\0') {
                        snprintf(r->old_code, sizeof(r->old_code), "%s +3; JMP %s", branch_name, instr_history[instr_history_count - 1].expression);
                        snprintf(r->new_code, sizeof(r->new_code), "%s %s", inverse_name, instr_history[instr_history_count - 1].expression);
                    } else {
                        snprintf(r->old_code, sizeof(r->old_code), "%s +3; JMP $%04X", branch_name, operand);
                        snprintf(r->new_code, sizeof(r->new_code), "%s $%04X", inverse_name, operand);
                    }
                    r->bytes_saved = 2; /* Branch rel (2) + JMP abs (3) = 5, 16-bit branch = 3, saves 2 */
                    replacement_count++;
                }
            }
        }
    }
    
    /* Check for JMP that could be BRA */
    if (opcode == 0x4C) {  /* JMP absolute */
        extern uint16_t pc;
        /* Calculate offset from byte after BRA instruction
         * JMP is at pc-3, BRA would be at pc-3, offset calculated from pc-1 */
        uint16_t jmp_addr = pc - 3;  /* Address of the JMP instruction */
        int16_t offset = (int16_t)(operand - (pc - 1));
        if (offset >= -128 && offset <= 127) {
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "BRA");
                r->line_num = line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = jmp_addr;
                r->target_addr = operand;
                
                /* Calculate offset from byte after BRA instruction */
                int16_t bra_offset = (int16_t)(operand - (jmp_addr + 2));
                
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
                            /* It's a label - prefer BRA *-LABEL format, fallback to numeric offset */
                            snprintf(r->old_code, sizeof(r->old_code), "JMP %s", jmp_hist->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "BRA *-%s", jmp_hist->expression);
                        } else {
                            /* It's a numeric expression, show offset */
                            snprintf(r->old_code, sizeof(r->old_code), "JMP %s", jmp_hist->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "BRA %+d", bra_offset);
                        }
                    } else {
                        snprintf(r->old_code, sizeof(r->old_code), "JMP $%04X", operand);
                        snprintf(r->new_code, sizeof(r->new_code), "BRA %+d", bra_offset);
                    }
                } else {
                    snprintf(r->old_code, sizeof(r->old_code), "JMP $%04X", operand);
                    snprintf(r->new_code, sizeof(r->new_code), "BRA %+d", bra_offset);
                }
                r->bytes_saved = 1; /* JMP abs (3 bytes), BRA rel (2 bytes), saves 1 */
                replacement_count++;
            }
        }
    }
    
    /* Check for JSR that could be BSR */
    if (opcode == 0x20) {  /* JSR absolute */
        extern uint16_t pc;
        /* Calculate offset from byte after BSR instruction
         * JSR is at pc-3, BSR would be at pc-3, offset calculated from pc-1 */
        uint16_t jsr_addr = pc - 3;  /* Address of the JSR instruction */
        int16_t offset = (int16_t)(operand - (pc - 1));
        if (offset >= -128 && offset <= 127) {
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "BRS");
                r->line_num = line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = jsr_addr;
                r->target_addr = operand;
                
                /* Calculate offset from byte after BRS instruction */
                int16_t brs_offset = (int16_t)(operand - (jsr_addr + 2));
                
                /* Use the stored expression if it's a label, otherwise show offset */
                if (instr_history_count > 0) {
                    instr_history_t *jsr_hist = &instr_history[instr_history_count - 1];
                    if (jsr_hist->expression[0] != '\0') {
                        /* Check if expression looks like a label (starts with letter) vs numeric (starts with $ or digit) */
                        char first_char = jsr_hist->expression[0];
                        int is_label = ((first_char >= 'A' && first_char <= 'Z') || 
                                       (first_char >= 'a' && first_char <= 'z') || 
                                       first_char == '_');
                        if (is_label) {
                            /* It's a label - prefer BRS *-LABEL format, fallback to numeric offset */
                            snprintf(r->old_code, sizeof(r->old_code), "JSR %s", jsr_hist->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "BRS *-%s", jsr_hist->expression);
                        } else {
                            /* It's a numeric expression, show offset */
                            snprintf(r->old_code, sizeof(r->old_code), "JSR %s", jsr_hist->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "BRS %+d", brs_offset);
                        }
                    } else {
                        snprintf(r->old_code, sizeof(r->old_code), "JSR $%04X", operand);
                        snprintf(r->new_code, sizeof(r->new_code), "BRS %+d", brs_offset);
                    }
                } else {
                    snprintf(r->old_code, sizeof(r->old_code), "JSR $%04X", operand);
                    snprintf(r->new_code, sizeof(r->new_code), "BRS %+d", brs_offset);
                }
                r->bytes_saved = 1; /* JSR abs (3 bytes), BRS rel (2 bytes), saves 1 */
                replacement_count++;
            }
        }
    }
    
    /* Check for INW pattern: LDA addr; ADC #1; STA addr; LDA addr+1; ADC #0; STA addr+1 -> INW addr */
    if (opcode == 0x85 && instr_history_count >= 6) {  /* STA zp (second one) */
        instr_history_t *sta2 = &instr_history[instr_history_count - 1];  /* Current STA (addr+1) */
        instr_history_t *adc2 = &instr_history[instr_history_count - 2];  /* ADC #0 */
        instr_history_t *lda2 = &instr_history[instr_history_count - 3];  /* LDA addr+1 */
        instr_history_t *sta1 = &instr_history[instr_history_count - 4];  /* STA addr */
        instr_history_t *adc1 = &instr_history[instr_history_count - 5];  /* ADC #1 */
        instr_history_t *lda1 = &instr_history[instr_history_count - 6];  /* LDA addr */
        
        /* Check pattern: LDA addr; ADC #1; STA addr; LDA addr+1; ADC #0; STA addr+1 */
        if ((lda1->opcode == 0xA5) && adc1->opcode == 0x69 && adc1->operand == 1 &&  /* ADC #1 */
            (sta1->opcode == 0x85) && sta1->operand == lda1->operand &&
            (lda2->opcode == 0xA5) && lda2->operand == lda1->operand + 1 &&
            adc2->opcode == 0x69 && adc2->operand == 0 &&  /* ADC #0 */
            (sta2->opcode == 0x85) && sta2->operand == lda2->operand) {
            
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "INW");
                r->line_num = lda1->line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = lda1->pc_at_instruction;
                r->target_addr = lda1->operand;
                
                if (lda1->expression[0] != '\0') {
                    snprintf(r->old_code, sizeof(r->old_code), "LDA %s; ADC #1; STA %s; LDA %s+1; ADC #0; STA %s+1", 
                            lda1->expression, lda1->expression, lda1->expression, lda1->expression);
                    snprintf(r->new_code, sizeof(r->new_code), "INW %s", lda1->expression);
                } else {
                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; ADC #1; STA $%02X; LDA $%02X; ADC #0; STA $%02X", 
                            lda1->operand, sta1->operand, lda2->operand, sta2->operand);
                    snprintf(r->new_code, sizeof(r->new_code), "INW $%02X", lda1->operand);
                }
                
                /* LDA (2) + ADC # (2) + STA (2) + LDA (2) + ADC # (2) + STA (2) = 12 bytes -> INW (3 bytes), saves 9 bytes */
                r->bytes_saved = 9;
                replacement_count++;
            }
        }
    }
    
    /* Check for DEW pattern: LDA addr; SEC; SBC #1; STA addr; LDA addr+1; SBC #0; STA addr+1 -> DEW addr */
    /* Also handles: LDA addr; SBC #1; STA addr; LDA addr+1; SBC #0; STA addr+1 (if SEC was elsewhere) */
    if (opcode == 0x85 && instr_history_count >= 6) {  /* STA zp (second one) */
        instr_history_t *sta2 = &instr_history[instr_history_count - 1];  /* Current STA (addr+1) */
        instr_history_t *sbc2 = &instr_history[instr_history_count - 2];  /* SBC #0 */
        instr_history_t *lda2 = &instr_history[instr_history_count - 3];  /* LDA addr+1 */
        instr_history_t *sta1 = &instr_history[instr_history_count - 4];  /* STA addr */
        instr_history_t *sbc1 = &instr_history[instr_history_count - 5];  /* SBC #1 */
        instr_history_t *lda1 = &instr_history[instr_history_count - 6];  /* LDA addr */
        
        /* Check pattern: LDA addr; SBC #1; STA addr; LDA addr+1; SBC #0; STA addr+1 */
        if ((lda1->opcode == 0xA5) && sbc1->opcode == 0xE9 && sbc1->operand == 1 &&  /* SBC #1 */
            (sta1->opcode == 0x85) && sta1->operand == lda1->operand &&
            (lda2->opcode == 0xA5) && lda2->operand == lda1->operand + 1 &&
            sbc2->opcode == 0xE9 && sbc2->operand == 0 &&  /* SBC #0 */
            (sta2->opcode == 0x85) && sta2->operand == lda2->operand) {
            
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "DEW");
                r->line_num = lda1->line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = lda1->pc_at_instruction;
                r->target_addr = lda1->operand;
                
                if (lda1->expression[0] != '\0') {
                    snprintf(r->old_code, sizeof(r->old_code), "LDA %s; SBC #1; STA %s; LDA %s+1; SBC #0; STA %s+1", 
                            lda1->expression, lda1->expression, lda1->expression, lda1->expression);
                    snprintf(r->new_code, sizeof(r->new_code), "DEW %s", lda1->expression);
                } else {
                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%02X; SBC #1; STA $%02X; LDA $%02X; SBC #0; STA $%02X", 
                            lda1->operand, sta1->operand, lda2->operand, sta2->operand);
                    snprintf(r->new_code, sizeof(r->new_code), "DEW $%02X", lda1->operand);
                }
                
                /* LDA (2) + SBC # (2) + STA (2) + LDA (2) + SBC # (2) + STA (2) = 12 bytes -> DEW (3 bytes), saves 9 bytes */
                r->bytes_saved = 9;
                replacement_count++;
            }
        }
    }

    /* Check for NEG A pattern: EOR #$FF; INC A -> negate accumulator (two's complement) */
    if (opcode == 0x1A && instr_history_count >= 2) {  /* INC A */
        instr_history_t *inca = &instr_history[instr_history_count - 1];  /* Current INC A */
        instr_history_t *eor = &instr_history[instr_history_count - 2];   /* Previous EOR #$FF */
        
        /* Check pattern: EOR #$FF; INC A */
        if (eor->opcode == 0x49 && eor->operand == 0xFF && inca->opcode == 0x1A) {
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "NEG_A");
                r->line_num = eor->line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = eor->pc_at_instruction;
                r->target_addr = 0;  /* No address target */
                
                /* Build old/new code strings */
                strcpy(r->old_code, "EOR #$FF; INC A");
                strcpy(r->new_code, "NEG A (accumulator negate)");
                
                /* EOR #$FF + INC A = 4 bytes (2+2), documented optimization opportunity */
                r->bytes_saved = 0;  /* No actual savings, but documents the pattern */
                replacement_count++;
            }
        }
    }

    /* Check for NEG (memory) pattern: LDA addr; EOR #$FF; ADC #1; STA addr -> NEG addr */
    if (opcode == 0x85 && instr_history_count >= 4) {  /* STA zp */
        instr_history_t *sta = &instr_history[instr_history_count - 1];    /* Current STA */
        instr_history_t *adc = &instr_history[instr_history_count - 2];    /* ADC #1 */
        instr_history_t *eor = &instr_history[instr_history_count - 3];    /* EOR #$FF */
        instr_history_t *lda = &instr_history[instr_history_count - 4];    /* LDA addr */
        
        /* Check pattern: LDA zp; EOR #$FF; ADC #1; STA zp (same address) */
        if ((lda->opcode == 0xA5 || lda->opcode == 0xAD) &&  /* LDA zp or abs */
            eor->opcode == 0x49 && eor->operand == 0xFF &&    /* EOR #$FF */
            adc->opcode == 0x69 && adc->operand == 0x01 &&    /* ADC #1 */
            (sta->opcode == 0x85 || sta->opcode == 0x8D) &&   /* STA zp or abs */
            lda->operand == sta->operand) {  /* Same address */
            
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "NEG_MEM");
                r->line_num = lda->line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = lda->pc_at_instruction;
                r->target_addr = lda->operand;
                
                /* Build old/new code strings */
                if (lda->expression[0] != '\0') {
                    snprintf(r->old_code, sizeof(r->old_code), "LDA %s; EOR #$FF; ADC #1; STA %s", 
                            lda->expression, lda->expression);
                    snprintf(r->new_code, sizeof(r->new_code), "NEG %s", lda->expression);
                } else {
                    snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; EOR #$FF; ADC #1; STA $%04X", 
                            lda->operand, sta->operand);
                    snprintf(r->new_code, sizeof(r->new_code), "NEG $%04X", lda->operand);
                }
                
                /* LDA + EOR + ADC + STA = 8 bytes -> NEG = would be 3 bytes, saves 5 bytes */
                r->bytes_saved = 5;
                replacement_count++;
            }
        }
    }

    /* Check for ASR pattern: CMP #$80; LSR; BCC +3; ORA #$80 -> arithmetic shift right */
    if (opcode == 0x09 && instr_history_count >= 4) {  /* ORA (either #, $00, abs, etc) */
        instr_history_t *ora = &instr_history[instr_history_count - 1];     /* Current ORA */
        instr_history_t *bcc = &instr_history[instr_history_count - 2];     /* BCC +3 */
        instr_history_t *lsr = &instr_history[instr_history_count - 3];     /* LSR */
        instr_history_t *cmp = &instr_history[instr_history_count - 4];     /* CMP #$80 */
        
        /* Check pattern: CMP #$80; LSR; BCC +3; ORA #$80 */
        if (cmp->opcode == 0xC9 && cmp->operand == 0x80 &&   /* CMP #$80 */
            lsr->opcode == 0x4A &&                             /* LSR A */
            (bcc->opcode == 0x90) &&                           /* BCC (forward branch) */
            ora->opcode == 0x09 && ora->operand == 0x80) {     /* ORA #$80 */
            
            if (replacement_count < MAX_REPLACEMENTS) {
                replacement_t *r = &replacements[replacement_count];
                strcpy(r->type, "ASR");
                r->line_num = cmp->line_num;
                strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                r->filename[sizeof(r->filename) - 1] = '\0';
                r->instr_addr = cmp->pc_at_instruction;
                r->target_addr = 0;  /* No address target */
                
                /* Build old/new code strings */
                strcpy(r->old_code, "CMP #$80; LSR; BCC +3; ORA #$80");
                strcpy(r->new_code, "ASR A (arithmetic shift right)");
                
                /* This sequence = 8 bytes -> ASR would be single byte, saves 7 bytes */
                r->bytes_saved = 7;
                replacement_count++;
            }
        }
    }

    /* Check for 16-bit branch pattern: (branch condition); JMP addr16 */
    if (opcode == 0x4C && instr_history_count >= 2) {  /* JMP abs */
        instr_history_t *jmp = &instr_history[instr_history_count - 1];    /* Current JMP */
        instr_history_t *branch = &instr_history[instr_history_count - 2]; /* Previous branch */
        
        /* Check if previous instruction was a conditional branch (not unconditional BRA) */
        uint8_t branch_opcodes[] = {0x10, 0x30, 0x50, 0x70, 0x90, 0xB0, 0xD0, 0xF0};  /* BPL, BMI, BVC, BVS, BCC, BCS, BNE, BEQ */
        int is_branch = 0;
        for (int i = 0; i < 8; i++) {
            if (branch->opcode == branch_opcodes[i]) {
                is_branch = 1;
                break;
            }
        }
        
        /* Pattern: conditional branch followed by JMP (workaround for 8-bit branch limit) */
        if (is_branch && replacement_count < MAX_REPLACEMENTS) {
            replacement_t *r = &replacements[replacement_count];
            strcpy(r->type, "BRANCH_16BIT");
            r->line_num = branch->line_num;
            strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
            r->filename[sizeof(r->filename) - 1] = '\0';
            r->instr_addr = branch->pc_at_instruction;
            r->target_addr = jmp->operand;
            
            /* Map branch opcode to name */
            const char *branch_name = "branch";
            switch (branch->opcode) {
                case 0x10: branch_name = "BPL"; break;
                case 0x30: branch_name = "BMI"; break;
                case 0x50: branch_name = "BVC"; break;
                case 0x70: branch_name = "BVS"; break;
                case 0x90: branch_name = "BCC"; break;
                case 0xB0: branch_name = "BCS"; break;
                case 0xD0: branch_name = "BNE"; break;
                case 0xF0: branch_name = "BEQ"; break;
            }
            
            snprintf(r->old_code, sizeof(r->old_code), "%s +3; JMP $%04X", branch_name, jmp->operand);
            snprintf(r->new_code, sizeof(r->new_code), "%s $%04X (16-bit branch)", branch_name, jmp->operand);
            
            /* branch + JMP = 5 bytes -> 16-bit branch would be 3 bytes, saves 2 bytes */
            r->bytes_saved = 2;
            replacement_count++;
        }
    }

    /* Check for PHW pattern: LDA addr+1; PHA; LDA addr; PHA -> PHW addr */
    if (opcode == 0x48 && instr_history_count >= 4) {  /* PHA */
        instr_history_t *pha2 = &instr_history[instr_history_count - 1];  /* Current PHA */
        instr_history_t *lda2 = &instr_history[instr_history_count - 2];  /* Second LDA (low byte) */
        instr_history_t *pha1 = &instr_history[instr_history_count - 3];  /* First PHA */
        instr_history_t *lda1 = &instr_history[instr_history_count - 4];  /* First LDA (high byte) */
        
        /* Check pattern: LDA addr+1; PHA; LDA addr; PHA */
        if ((lda1->opcode == 0xA5 || lda1->opcode == 0xAD) &&  /* LDA zp or LDA abs */
            pha1->opcode == 0x48 &&  /* PHA */
            (lda2->opcode == 0xA5 || lda2->opcode == 0xAD) &&  /* LDA zp or LDA abs */
            pha2->opcode == 0x48) {  /* PHA */
            /* Check if operands are consecutive: lda1 should be lda2 + 1 */
            if (lda1->operand == lda2->operand + 1) {
                if (replacement_count < MAX_REPLACEMENTS) {
                    replacement_t *r = &replacements[replacement_count];
                    strcpy(r->type, "PHW");
                    r->line_num = lda1->line_num;
                    strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                    r->filename[sizeof(r->filename) - 1] = '\0';
                    r->instr_addr = lda1->pc_at_instruction;
                    r->target_addr = lda2->operand;  /* Base address (low byte address) */
                    
                    /* Build old code string */
                    if (lda1->expression[0] != '\0') {
                        snprintf(r->old_code, sizeof(r->old_code), "LDA %s+1; PHA; LDA %s; PHA", 
                                lda1->expression, lda1->expression);
                        snprintf(r->new_code, sizeof(r->new_code), "PHW %s", lda1->expression);
                    } else {
                        snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X; PHA; LDA $%04X; PHA", 
                                lda1->operand, lda2->operand);
                        snprintf(r->new_code, sizeof(r->new_code), "PHW $%04X", lda2->operand);
                    }
                    
                    /* LDA+PHA+LDA+PHA = 5 bytes -> PHW = 3 bytes, saves 2 bytes */
                    r->bytes_saved = 2;
                    replacement_count++;
                }
            }
        }
    }

    /* Check for return with pop patterns that can use RTN in 65CE02 */
    if (opcode == 0x60) {  /* RTS */
        /* Pattern: One or more PLA/PLX/PLY followed by RTS -> RTN (combine into single instruction) */
        /* Note: RTS has already been added to history, so -2 is the instruction before RTS */
        
        /* Count consecutive pop instructions before RTS */
        int pop_count = 0;
        int history_idx = instr_history_count - 2;  /* Start at instruction before RTS */
        
        /* Look back for consecutive pop instructions */
        while (history_idx >= 0) {
            instr_history_t *instr = &instr_history[history_idx];
            if (instr->opcode == 0x68 || instr->opcode == 0xFA || instr->opcode == 0x7A) {  /* PLA, PLX, PLY */
                pop_count++;
                history_idx--;
            } else {
                break;  /* Stop at first non-pop instruction */
            }
        }
        
        /* If we found at least one pop before RTS, record as replacement opportunity */
        if (pop_count > 0 && replacement_count < MAX_REPLACEMENTS) {
            replacement_t *r = &replacements[replacement_count];
            strcpy(r->type, "RETURN_POP");
            
            /* First pop instruction's line number */
            instr_history_t *first_pop = &instr_history[instr_history_count - 2 - pop_count + 1];
            r->line_num = first_pop->line_num;
            strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
            r->filename[sizeof(r->filename) - 1] = '\0';
            r->instr_addr = first_pop->pc_at_instruction;
            
            /* Build old code string with all pops */
            char old_code_buf[256] = "";
            for (int i = pop_count - 1; i >= 0; i--) {
                instr_history_t *pop_instr = &instr_history[instr_history_count - 2 - i];
                const char *pop_name = pop_instr->instr_name[0] != '\0' ? pop_instr->instr_name : 
                                      (pop_instr->opcode == 0x68 ? "PLA" : 
                                       (pop_instr->opcode == 0xFA ? "PLX" : "PLY"));
                if (i == pop_count - 1) {
                    snprintf(old_code_buf, sizeof(old_code_buf), "%s", pop_name);
                } else {
                    strncat(old_code_buf, "; ", sizeof(old_code_buf) - strlen(old_code_buf) - 1);
                    strncat(old_code_buf, pop_name, sizeof(old_code_buf) - strlen(old_code_buf) - 1);
                }
            }
            strncat(old_code_buf, "; RTS", sizeof(old_code_buf) - strlen(old_code_buf) - 1);
            strncpy(r->old_code, old_code_buf, sizeof(r->old_code) - 1);
            r->old_code[sizeof(r->old_code) - 1] = '\0';
            
            snprintf(r->new_code, sizeof(r->new_code), "RTN (65CE02)");
            
            /* pop_count pops (1 each) + RTS (1) = pop_count + 1 bytes -> RTN (1 byte), saves pop_count bytes */
            r->bytes_saved = pop_count;
            replacement_count++;
        }
    }
    
    /* Check for 16-bit shift/rotate patterns that can use ASW/ROW in 65CE02 */
    /* Pattern 1: ROL zp / ASL zp+1 -> ROW (rotate word - left) */
    if (opcode == 0x06 || opcode == 0x0E || opcode == 0x16 || opcode == 0x1E || opcode == 0x0A) {  /* ASL variants */
        if (instr_history_count >= 2) {
            instr_history_t *asl_instr = &instr_history[instr_history_count - 1];
            instr_history_t *prev_instr = &instr_history[instr_history_count - 2];
            
            /* Check if this is ASL and previous is ROL, and operands are consecutive */
            if ((prev_instr->opcode == 0x2A || prev_instr->opcode == 0x26 || 
                 prev_instr->opcode == 0x2E || prev_instr->opcode == 0x36 || 
                 prev_instr->opcode == 0x3E) &&  /* ROL variants: A, zp, abs, zp,X, abs,X */
                (asl_instr->opcode == 0x0A || asl_instr->opcode == 0x06 || 
                 asl_instr->opcode == 0x0E || asl_instr->opcode == 0x16 || 
                 asl_instr->opcode == 0x1E)) {  /* ASL variants: A, zp, abs, zp,X, abs,X */
                /* Check if operands are consecutive (high/low bytes of same address) */
                if (prev_instr->operand + 1 == asl_instr->operand) {
                    if (replacement_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &replacements[replacement_count];
                        strcpy(r->type, "SHIFT_16BIT");
                        r->line_num = prev_instr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        r->instr_addr = prev_instr->pc_at_instruction;
                        r->target_addr = prev_instr->operand;  /* Base address of 16-bit value */
                        
                        /* Build old code - detected as ROL/ASL on consecutive addresses */
                        if (prev_instr->expression[0] != '\0') {
                            snprintf(r->old_code, sizeof(r->old_code), "ROL %s; ASL %s+1", 
                                    prev_instr->expression, prev_instr->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "ROW %s", prev_instr->expression);
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "ROL $%04X; ASL $%04X", 
                                    prev_instr->operand, asl_instr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "ROW $%04X", prev_instr->operand);
                        }
                        
                        /* ROL (3) + ASL (3) = 6 bytes -> ROW (3 bytes), saves 3 bytes */
                        r->bytes_saved = 3;
                        replacement_count++;
                    }
                }
            }
        }
    }
    
    /* Pattern 2: LSR zp / ROR zp+1 -> ASW (arithmetic shift word - right) */
    if (opcode == 0x66 || opcode == 0x6E || opcode == 0x76 || opcode == 0x7E || opcode == 0x6A) {  /* ROR variants */
        if (instr_history_count >= 2) {
            instr_history_t *ror_instr = &instr_history[instr_history_count - 1];
            instr_history_t *prev_instr = &instr_history[instr_history_count - 2];
            
            /* Check if this is ROR and previous is LSR, and operands are consecutive */
            if ((prev_instr->opcode == 0x4A || prev_instr->opcode == 0x46 || 
                 prev_instr->opcode == 0x4E || prev_instr->opcode == 0x56 || 
                 prev_instr->opcode == 0x5E) &&  /* LSR variants: A, zp, abs, zp,X, abs,X */
                (ror_instr->opcode == 0x6A || ror_instr->opcode == 0x66 || 
                 ror_instr->opcode == 0x6E || ror_instr->opcode == 0x76 || 
                 ror_instr->opcode == 0x7E)) {  /* ROR variants: A, zp, abs, zp,X, abs,X */
                /* Check if operands are consecutive (high/low bytes of same address) */
                if (prev_instr->operand + 1 == ror_instr->operand) {
                    if (replacement_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &replacements[replacement_count];
                        strcpy(r->type, "SHIFT_16BIT");
                        r->line_num = prev_instr->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        r->instr_addr = prev_instr->pc_at_instruction;
                        r->target_addr = prev_instr->operand;  /* Base address of 16-bit value */
                        
                        /* Build old code - detected as LSR/ROR on consecutive addresses */
                        if (prev_instr->expression[0] != '\0') {
                            snprintf(r->old_code, sizeof(r->old_code), "LSR %s; ROR %s+1", 
                                    prev_instr->expression, prev_instr->expression);
                            snprintf(r->new_code, sizeof(r->new_code), "ASW %s", prev_instr->expression);
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LSR $%04X; ROR $%04X", 
                                    prev_instr->operand, ror_instr->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "ASW $%04X", prev_instr->operand);
                        }
                        
                        /* LSR (3) + ROR (3) = 6 bytes -> ASW (3 bytes), saves 3 bytes */
                        r->bytes_saved = 3;
                        replacement_count++;
                    }
                }
            }
        }
    }
    
    /* Check for JMP (abs,X) replacement patterns when RTS is encountered */
    if (opcode == 0x60) {  /* RTS */
        /* Pattern 1: ASL -> TAX -> LDA TABLE+1,X -> PHA -> LDA TABLE,X -> PHA -> RTS */
        if (instr_history_count >= 7) {
            instr_history_t *asl = &instr_history[instr_history_count - 7];
            instr_history_t *tax = &instr_history[instr_history_count - 6];
            instr_history_t *lda_high = &instr_history[instr_history_count - 5];
            instr_history_t *pha1 = &instr_history[instr_history_count - 4];
            instr_history_t *lda_low = &instr_history[instr_history_count - 3];
            instr_history_t *pha2 = &instr_history[instr_history_count - 2];
            instr_history_t *rts = &instr_history[instr_history_count - 1];
            
            /* Check if pattern matches: ASL (0x0A), TAX (0xAA), LDA abs,X (0xBD) or zp,X (0xB5), PHA (0x48), LDA abs,X (0xBD) or zp,X (0xB5), PHA (0x48), RTS (0x60) */
            if ((asl->opcode == 0x0A || asl->opcode == 0x06 || asl->opcode == 0x0E || 
                 asl->opcode == 0x16 || asl->opcode == 0x1E) &&  /* ASL variants */
                tax->opcode == 0xAA &&  /* TAX */
                (lda_high->opcode == 0xBD || lda_high->opcode == 0xB5) &&  /* LDA abs,X or zp,X */
                pha1->opcode == 0x48 &&  /* PHA */
                (lda_low->opcode == 0xBD || lda_low->opcode == 0xB5) &&  /* LDA abs,X or zp,X */
                pha2->opcode == 0x48 &&  /* PHA */
                rts->opcode == 0x60) {  /* RTS */
                
                /* Check if the two LDA operands differ by 1 (TABLE+1 and TABLE) */
                /* Also check expressions if available */
                int operand_match = (lda_high->operand == lda_low->operand + 1);
                int expr_match = 0;
                if (lda_high->expression[0] != '\0' && lda_low->expression[0] != '\0') {
                    /* Check if high expression contains "+1" and low expression is the base */
                    if (strstr(lda_high->expression, "+1") != NULL || 
                        strstr(lda_high->expression, "+ 1") != NULL) {
                        /* Extract base name from high expression */
                        char base_name[64];
                        strncpy(base_name, lda_high->expression, sizeof(base_name) - 1);
                        base_name[sizeof(base_name) - 1] = '\0';
                        char *plus_pos = strstr(base_name, "+1");
                        if (!plus_pos) plus_pos = strstr(base_name, "+ 1");
                        if (plus_pos) *plus_pos = '\0';
                        /* Trim whitespace */
                        while (strlen(base_name) > 0 && base_name[strlen(base_name) - 1] == ' ') {
                            base_name[strlen(base_name) - 1] = '\0';
                        }
                        if (strcmp(base_name, lda_low->expression) == 0) {
                            expr_match = 1;
                        }
                    }
                }
                if (operand_match || expr_match) {
                    if (replacement_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &replacements[replacement_count];
                        strcpy(r->type, "JMP (abs,X)");
                        r->line_num = asl->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        
                        /* Build old code string */
                        const char *asl_name = asl->instr_name;
                        if (lda_low->expression[0] != '\0') {
                            /* Try to extract table name from expression */
                            char table_name[64];
                            strncpy(table_name, lda_low->expression, sizeof(table_name) - 1);
                            table_name[sizeof(table_name) - 1] = '\0';
                            snprintf(r->old_code, sizeof(r->old_code), "%s; TAX; LDA %s+1,X; PHA; LDA %s,X; PHA; RTS",
                                    asl_name, table_name, table_name);
                            snprintf(r->new_code, sizeof(r->new_code), "%s; TAX; JMP (%s,X)", asl_name, table_name);
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "%s; TAX; LDA $%04X,X; PHA; LDA $%04X,X; PHA; RTS",
                                    asl_name, lda_high->operand, lda_low->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "%s; TAX; JMP ($%04X,X)", asl_name, lda_low->operand);
                        }
                        /* ASL (1) + TAX (1) + LDA abs,X (3) + PHA (1) + LDA abs,X (3) + PHA (1) + RTS (1) = 11 bytes
                         * ASL (1) + TAX (1) + JMP (abs,X) (3) = 5 bytes, saves 6 */
                        r->bytes_saved = 6;
                        replacement_count++;
                    }
                }
            }
        }
        
        /* Pattern 2: LDA TABLEH,X -> PHA -> LDA TABLEL,X -> PHA -> RTS */
        if (instr_history_count >= 5) {
            instr_history_t *lda_high = &instr_history[instr_history_count - 5];
            instr_history_t *pha1 = &instr_history[instr_history_count - 4];
            instr_history_t *lda_low = &instr_history[instr_history_count - 3];
            instr_history_t *pha2 = &instr_history[instr_history_count - 2];
            instr_history_t *rts = &instr_history[instr_history_count - 1];
            
            /* Check if pattern matches: LDA abs,X (0xBD) or zp,X (0xB5), PHA (0x48), LDA abs,X (0xBD) or zp,X (0xB5), PHA (0x48), RTS (0x60) */
            if ((lda_high->opcode == 0xBD || lda_high->opcode == 0xB5) &&  /* LDA abs,X or zp,X */
                pha1->opcode == 0x48 &&  /* PHA */
                (lda_low->opcode == 0xBD || lda_low->opcode == 0xB5) &&  /* LDA abs,X or zp,X */
                pha2->opcode == 0x48 &&  /* PHA */
                rts->opcode == 0x60) {  /* RTS */
                
                /* Check if expressions suggest TABLEH and TABLEL pattern */
                /* We'll check if the expressions end with 'H' and 'L' or contain 'H'/'L' */
                int is_tableh_tabl = 0;
                if (lda_high->expression[0] != '\0' && lda_low->expression[0] != '\0') {
                    /* Check if expressions suggest high/low table pattern */
                    char *high_expr = lda_high->expression;
                    char *low_expr = lda_low->expression;
                    size_t high_len = strlen(high_expr);
                    size_t low_len = strlen(low_expr);
                    
                    /* Check if one ends with 'H' and the other with 'L' */
                    if (high_len > 0 && low_len > 0) {
                        if ((high_expr[high_len - 1] == 'H' || high_expr[high_len - 1] == 'h') &&
                            (low_expr[low_len - 1] == 'L' || low_expr[low_len - 1] == 'l')) {
                            /* Check if base names match (without H/L suffix) */
                            if (high_len == low_len && 
                                strncmp(high_expr, low_expr, high_len - 1) == 0) {
                                is_tableh_tabl = 1;
                            }
                        }
                    }
                }
                
                /* Also check if operands are close (within reasonable range for separate tables) */
                /* For pattern 2, the tables are separate, so we don't require operand relationship */
                if (is_tableh_tabl || (lda_high->operand != lda_low->operand && 
                                      lda_high->operand != lda_low->operand + 1)) {
                    if (replacement_count < MAX_REPLACEMENTS) {
                        replacement_t *r = &replacements[replacement_count];
                        strcpy(r->type, "JMP (abs,X)");
                        r->line_num = lda_high->line_num;
                        strncpy(r->filename, filename ? filename : "unknown", sizeof(r->filename) - 1);
                        r->filename[sizeof(r->filename) - 1] = '\0';
                        
                        if (is_tableh_tabl && lda_high->expression[0] != '\0') {
                            /* Extract base table name (remove 'H' suffix) */
                            char table_name[64];
                            size_t len = strlen(lda_high->expression);
                            if (len > 0 && len < sizeof(table_name)) {
                                strncpy(table_name, lda_high->expression, len - 1);
                                table_name[len - 1] = '\0';
                                snprintf(r->old_code, sizeof(r->old_code), "LDA %s,X; PHA; LDA %s,X; PHA; RTS",
                                        lda_high->expression, lda_low->expression);
                                snprintf(r->new_code, sizeof(r->new_code), "JMP (%s,X)", table_name);
                            } else {
                                snprintf(r->old_code, sizeof(r->old_code), "LDA %s,X; PHA; LDA %s,X; PHA; RTS",
                                        lda_high->expression, lda_low->expression);
                                snprintf(r->new_code, sizeof(r->new_code), "JMP ($%04X,X)", lda_low->operand);
                            }
                        } else {
                            snprintf(r->old_code, sizeof(r->old_code), "LDA $%04X,X; PHA; LDA $%04X,X; PHA; RTS",
                                    lda_high->operand, lda_low->operand);
                            snprintf(r->new_code, sizeof(r->new_code), "JMP ($%04X,X)", lda_low->operand);
                        }
                        /* LDA abs,X (3) + PHA (1) + LDA abs,X (3) + PHA (1) + RTS (1) = 9 bytes
                         * JMP (abs,X) (3) = 3 bytes, saves 6 */
                        r->bytes_saved = 6;
                        replacement_count++;
                    }
                }
            }
        }
    }
}

/* Helper function to print assembler statistics */
static void print_assembler_statistics(void) {
    printf("\n=== Assembler Statistics ===\n");
    printf("Total lines: %d\n", total_lines);
    printf("Non-blank lines: %d\n", non_blank_lines);
    printf("Total characters: %d\n", total_characters);
    printf("===========================\n");
}

static void print_binary_statistics(int include_data_labels) {
    extern uint16_t min_address;
    extern uint16_t max_address;
    extern uint16_t min_opcode_address;
    extern uint16_t max_opcode_address;
    extern uint16_t org_address;

    int opcode_region_size = 0;
    if (min_opcode_address != 0xFFFF && max_opcode_address != 0) {
        opcode_region_size = max_opcode_address - min_opcode_address + 1;
    }

    printf("\n=== Binary Statistics ===\n");
    if (opcode_region_size > 0) {
        printf("Total bytes in binary (opcode region): %d\n", opcode_region_size);
    } else {
        printf("Total bytes in binary: %d\n", binary_size);
    }
    if (min_opcode_address != 0xFFFF && max_opcode_address != 0) {
        printf("Lowest opcode address: $%04X\n", min_opcode_address);
        printf("Highest opcode address: $%04X\n", max_opcode_address);
    }
   if (min_address != 0xFFFF && max_address != 0) {
        if (include_data_labels) {
            printf("Lowest emitted address (includes data bytes): $%04X\n", min_address);
            printf("Highest emitted address (includes data bytes): $%04X\n", max_address);
        } else {
            printf("Lowest emitted address: $%04X\n", min_address);
            printf("Highest emitted address: $%04X\n", max_address);
        }
    } else if (binary_size > 0) {
        if (include_data_labels) {
            printf("Lowest emitted address (includes data bytes): $%04X\n", org_address);
            printf("Highest emitted address (includes data bytes): $%04X\n", org_address + binary_size - 1);
        } else {
            printf("Lowest emitted address: $%04X\n", org_address);
            printf("Highest emitted address: $%04X\n", org_address + binary_size - 1);
        }
    }
     printf("========================\n");
}

typedef struct {
    uint8_t opcode;
    int count;
    const char *name;
} opcode_entry_t;

static void sort_opcode_entries(opcode_entry_t *entries, int entry_count) {
    for (int i = 0; i < entry_count - 1; i++) {
        for (int j = i + 1; j < entry_count; j++) {
            const char *name_i = entries[i].name ? entries[i].name : "unknown";
            const char *name_j = entries[j].name ? entries[j].name : "unknown";
            if (strcmp(name_i, name_j) > 0) {
                opcode_entry_t temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

static void print_opcode_statistics(void) {
    opcode_entry_t entries[256];
    int entry_count = 0;

    printf("\n=== Opcode Statistics ===\n");
    printf("Total opcodes emitted: %d\n", total_opcodes);
    printf("Total opcodes bytes emitted: %d\n\n", total_opcode_bytes);

    for (int i = 0; i < NUM_OPCODES; i++) {
        if (opcode_counts[i] > 0) {
            entries[entry_count].opcode = i;
            entries[entry_count].count = opcode_counts[i];
            entries[entry_count].name = opcode_names[i];
            entry_count++;
        }
    }

    sort_opcode_entries(entries, entry_count);

    if (entry_count > 0) {
        for (int i = 0; i < entry_count; i++) {
            if (entries[i].name) {
                printf("$%02X (%s): %d\n", entries[i].opcode, entries[i].name, entries[i].count);
            } else {
                printf("$%02X (unknown): %d\n", entries[i].opcode, entries[i].count);
            }
        }
    } else {
        printf("No opcodes were emitted.\n");
    }

    if (c02_opcode_count > 0) {
        opcode_entry_t c02_entries[256];
        int c02_entry_count = 0;

        printf("\n=== 65C02 Opcode Statistics ===\n");
        printf("Total 65C02 opcodes: %d\n\n", c02_opcode_count);

        for (int i = 0; i < NUM_OPCODES; i++) {
            if (opcode_counts[i] > 0 && stats_is_c02_opcode(i)) {
                c02_entries[c02_entry_count].opcode = i;
                c02_entries[c02_entry_count].count = opcode_counts[i];
                c02_entries[c02_entry_count].name = opcode_names[i];
                c02_entry_count++;
            }
        }

        sort_opcode_entries(c02_entries, c02_entry_count);

        if (c02_entry_count > 0) {
            for (int i = 0; i < c02_entry_count; i++) {
                if (c02_entries[i].name) {
                    printf("$%02X (%s): %d\n", c02_entries[i].opcode, c02_entries[i].name, c02_entries[i].count);
                } else {
                    printf("$%02X (unknown C02): %d\n", c02_entries[i].opcode, c02_entries[i].count);
                }
            }
        } else {
            printf("No 65C02 opcodes were emitted.\n");
        }
        printf("==============================\n");
    }

    printf("========================\n");
}

static void print_code_optimization_summary(void) {
    if (optimization_count == 0) {
        return;
    }

    int total_bytes_saved = 0;
    for (int i = 0; i < optimization_count; i++) {
        total_bytes_saved += optimizations[i].bytes_saved;
    }

    printf("\n=== Code Optimization Summary ===\n");
    printf("Total possible optimizations: %d\n", optimization_count);
    printf("Total bytes saved: %d", total_bytes_saved);
    if (total_opcode_bytes > 0) {
        double percent = (double)total_bytes_saved * 100.0 / (double)total_opcode_bytes;
        printf(" (%.1f%% of %d opcode bytes)", percent, total_opcode_bytes);
    }
    printf("\n");

    int inc_count = 0, dec_count = 0;
    int tax_count = 0, tay_count = 0, branch_jmp_count = 0;
    int redundant_count = 0, register_count = 0, load_store_count = 0;

    for (int i = 0; i < optimization_count; i++) {
        replacement_t *r = &optimizations[i];
        if (strcmp(r->type, "INC") == 0) inc_count++;
        else if (strcmp(r->type, "DEC") == 0) dec_count++;
        else if (strcmp(r->type, "TAX") == 0) tax_count++;
        else if (strcmp(r->type, "TAY") == 0) tay_count++;
        else if (strcmp(r->type, "Branch+JMP") == 0) branch_jmp_count++;
        else if (strcmp(r->type, "Redundant") == 0) redundant_count++;
        else if (strcmp(r->type, "Register") == 0) register_count++;
        else if (strcmp(r->type, "Load/Store") == 0) load_store_count++;
    }

    if (inc_count > 0) printf("  INC optimizations: %d (LDA/ADC #1/STA -> INC addr)\n", inc_count);
    if (dec_count > 0) printf("  DEC optimizations: %d (LDA/SBC #1/STA -> DEC addr)\n", dec_count);
    if (tax_count > 0) printf("  TAX optimizations: %d (LDA #/LDX # -> LDA #/TAX)\n", tax_count);
    if (tay_count > 0) printf("  TAY optimizations: %d (LDA #/LDY # -> LDA #/TAY)\n", tay_count);
    if (branch_jmp_count > 0) printf("  Branch+JMP optimizations: %d\n", branch_jmp_count);
    if (redundant_count > 0) printf("  Redundant instruction removals: %d\n", redundant_count);
    if (register_count > 0) printf("  Register transfer optimizations: %d\n", register_count);
    if (load_store_count > 0) printf("  Load/Store optimizations: %d\n", load_store_count);
    printf("===================================\n");
}

static void print_immediate_zero_statistics(void) {
    if (total_immediate_zero == 0 && sta_zero_count == 0) {
        return;
    }

    printf("\n=== Immediate Zero Opcodes ===\n");
    printf("Total immediate zero opcodes: %d", total_immediate_zero);
    if (sta_zero_count > 0) {
        printf(" (plus %d STA $00)", sta_zero_count);
    }
    printf("\n");

    opcode_entry_t zero_entries[256];
    int zero_entry_count = 0;
    for (int i = 0; i < NUM_OPCODES; i++) {
        if (immediate_zero_counts[i] > 0) {
            zero_entries[zero_entry_count].opcode = i;
            zero_entries[zero_entry_count].count = immediate_zero_counts[i];
            zero_entries[zero_entry_count].name = opcode_names[i];
            zero_entry_count++;
        }
    }

    sort_opcode_entries(zero_entries, zero_entry_count);

    int found_any = 0;
    if (zero_entry_count > 0) {
        found_any = 1;
        for (int i = 0; i < zero_entry_count; i++) {
            if (zero_entries[i].name) {
                printf("$%02X (%s): %d\n", zero_entries[i].opcode, zero_entries[i].name, zero_entries[i].count);
            } else {
                printf("$%02X (unknown): %d\n", zero_entries[i].opcode, zero_entries[i].count);
            }
        }
    }

    if (sta_zero_count > 0) {
        found_any = 1;
        printf("STA $00: %d\n", sta_zero_count);
    }

    if (!found_any) {
        printf("No immediate zero opcodes were emitted.\n");
    }
    printf("==============================\n");
}

static void print_65CE02_replacement_opportunities(int use_ina_dea, int include_zero_savings, int include_other_improvements) {
    int lda_zero_count = immediate_zero_counts[0xA9];
    //int ldx_zero_count = immediate_zero_counts[0xA2];
    //int ldy_zero_count = immediate_zero_counts[0xA0];
    int ce02_zero_savings = lda_zero_count;// they don't have TZX or TZY

    if (replacement_count == 0 && !include_zero_savings && !include_other_improvements) {
        return;
    }

    printf("\n=== 65C02 Replacement Opportunities ===\n");

    int stz_count = 0, phx_count = 0, phy_count = 0, plx_count = 0, ply_count = 0, bra_count = 0;
    int inc_count = 0, dec_count = 0, ina_count = 0, dea_count = 0;
    int tsb_count = 0, trb_count = 0, jmp_indx_count = 0, brs_count = 0, long_branch_count = 0;
    int return_pop_count = 0, shift_16bit_count = 0, phw_count = 0, inw_count = 0, dew_count = 0;
    int neg_a_count = 0, neg_mem_count = 0, asr_count = 0, branch_16bit_count = 0;

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
        else if (strcmp(r->type, "INA") == 0) ina_count++;
        else if (strcmp(r->type, "DEA") == 0) dea_count++;
        else if (strcmp(r->type, "TSB") == 0) tsb_count++;
        else if (strcmp(r->type, "TRB") == 0) trb_count++;
        else if (strcmp(r->type, "JMP (abs,X)") == 0) jmp_indx_count++;
        else if (strcmp(r->type, "BRS") == 0) brs_count++;
        else if (strcmp(r->type, "LONG_BRANCH") == 0) long_branch_count++;
        else if (strcmp(r->type, "RETURN_POP") == 0) return_pop_count++;
        else if (strcmp(r->type, "SHIFT_16BIT") == 0) shift_16bit_count++;
        else if (strcmp(r->type, "PHW") == 0) phw_count++;
        else if (strcmp(r->type, "INW") == 0) inw_count++;
        else if (strcmp(r->type, "DEW") == 0) dew_count++;
        else if (strcmp(r->type, "NEG_A") == 0) neg_a_count++;
        else if (strcmp(r->type, "NEG_MEM") == 0) neg_mem_count++;
        else if (strcmp(r->type, "ASR") == 0) asr_count++;
        else if (strcmp(r->type, "BRANCH_16BIT") == 0) branch_16bit_count++;
    }

    {
        int c02_total_count = 0;
        int c02_total_bytes_saved = 0;
        for (int i = 0; i < replacement_count; i++) {
            replacement_t *r = &replacements[i];
            if (strcmp(r->type, "STZ") == 0 || strcmp(r->type, "PHX") == 0 || strcmp(r->type, "PHY") == 0 ||
                strcmp(r->type, "PLX") == 0 || strcmp(r->type, "PLY") == 0 || strcmp(r->type, "BRA") == 0 ||
                strcmp(r->type, "TSB") == 0 || strcmp(r->type, "TRB") == 0 || strcmp(r->type, "JMP (abs,X)") == 0 ||
                (use_ina_dea ? (strcmp(r->type, "INA") == 0 || strcmp(r->type, "DEA") == 0)
                             : (strcmp(r->type, "INC") == 0 || strcmp(r->type, "DEC") == 0))) {
                c02_total_count++;
                c02_total_bytes_saved += r->bytes_saved;
            }
        }
        printf("Total possible replacements: %d\n", c02_total_count);
        printf("Total bytes saved: %d", c02_total_bytes_saved);
        if (total_opcode_bytes > 0) {
            double percent = (double)c02_total_bytes_saved * 100.0 / (double)total_opcode_bytes;
            printf(" (%.1f%% of %d opcode bytes)", percent, total_opcode_bytes);
        }
        printf("\n");
    }

    if (bra_count > 0) printf("  BRA replacements: %d (from %d JMP instructions)\n", bra_count, total_jmp_count);
    if (stz_count > 0) printf("  STZ replacements: %d\n", stz_count);
    if (phx_count > 0) printf("  PHX replacements: %d\n", phx_count);
    if (phy_count > 0) printf("  PHY replacements: %d\n", phy_count);
    if (plx_count > 0) printf("  PLX replacements: %d\n", plx_count);
    if (ply_count > 0) printf("  PLY replacements: %d\n", ply_count);
    if (use_ina_dea) {
        if (ina_count > 0) printf("  INA replacements: %d\n", ina_count);
        if (dea_count > 0) printf("  DEA replacements: %d\n", dea_count);
    } else {
        if (inc_count > 0) printf("  INC replacements: %d\n", inc_count);
        if (dec_count > 0) printf("  DEC replacements: %d\n", dec_count);
    }
    if (tsb_count > 0) printf("  TSB replacements: %d\n", tsb_count);
    if (trb_count > 0) printf("  TRB replacements: %d\n", trb_count);
    if (jmp_indx_count > 0) printf("  JMP (abs,X) replacements: %d\n", jmp_indx_count);

    if (bra_count > 0 || stz_count > 0 || phx_count > 0 || phy_count > 0 || plx_count > 0 || ply_count > 0 ||
        ((use_ina_dea ? (ina_count || dea_count) : (inc_count || dec_count))) ||
        tsb_count > 0 || trb_count > 0 || jmp_indx_count > 0) {
        printf("========================================\n");
    }

    printf("\n=== 65CE02 Replacement Opportunities ===\n");

    int ce02_total_count = 0;
    int ce02_total_bytes_saved = 0;
    for (int i = 0; i < replacement_count; i++) {
        replacement_t *r = &replacements[i];
        if (strcmp(r->type, "RETURN_POP") == 0 || strcmp(r->type, "SHIFT_16BIT") == 0 ||
            strcmp(r->type, "PHW") == 0 || strcmp(r->type, "INW") == 0 || strcmp(r->type, "DEW") == 0 ||
            strcmp(r->type, "NEG_A") == 0 || strcmp(r->type, "NEG_MEM") == 0 ||
            strcmp(r->type, "ASR") == 0 || strcmp(r->type, "BRANCH_16BIT") == 0) {
            ce02_total_count++;
            ce02_total_bytes_saved += r->bytes_saved;
        }
    }
    if (include_zero_savings) {
        ce02_total_bytes_saved += ce02_zero_savings;
    }

    if (ce02_total_count > 0 || (include_zero_savings && ce02_zero_savings > 0)) {
        printf("Total possible replacements: %d\n", ce02_total_count);
        printf("Total bytes saved: %d", ce02_total_bytes_saved);
        if (total_opcode_bytes > 0) {
            double percent = (double)ce02_total_bytes_saved * 100.0 / (double)total_opcode_bytes;
            printf(" (%.1f%% of %d opcode bytes)", percent, total_opcode_bytes);
        }
        printf("\n");
    }

    if (brs_count > 0) printf("  BSR replacements: %d (from %d JSR instructions)\n", brs_count, total_jsr_count);
    if (long_branch_count > 0) printf("  Long branch replacements: %d (branch +3; JMP)\n", long_branch_count);
    if (branch_16bit_count > 0) printf("  16-bit branches: %d (branch to JMP)\n", branch_16bit_count);
    if (return_pop_count > 0) printf("  Return with pop (RTN): %d (PLA/PLX/PLY followed by RTS)\n", return_pop_count);
    if (shift_16bit_count > 0) printf("  16-bit shift/rotate (ASW/ROW): %d (consecutive shift operations on memory)\n", shift_16bit_count);
    if (phw_count > 0) printf("  Push word (PHW): %d (LDA high; PHA; LDA low; PHA pattern)\n", phw_count);
    if (inw_count > 0) printf("  Increment word (INW): %d (LDA/ADC/STA 16-bit pattern)\n", inw_count);
    if (dew_count > 0) printf("  Decrement word (DEW): %d (LDA/SBC/STA 16-bit pattern)\n", dew_count);
    if (neg_a_count > 0) printf("  Negate accumulator (NEG A): %d (EOR #$FF; INC A pattern)\n", neg_a_count);
    if (neg_mem_count > 0) printf("  Negate memory (NEG addr): %d (LDA/EOR #$FF/ADC #1/STA pattern)\n", neg_mem_count);
    if (asr_count > 0) printf("  Arithmetic shift right (ASR): %d (CMP #$80; LSR; BCC +3; ORA #$80 pattern)\n", asr_count);

    int cmp_zero_count = immediate_zero_counts[0xC9];
    if (cmp_zero_count > 0) printf("  CMP #0 opportunities: %d\n", cmp_zero_count);

    if (include_zero_savings && ce02_zero_savings > 0) {
        printf("  LDA #0 -> TZA: %d", ce02_zero_savings);
        if (total_opcode_bytes > 0) {
            double percent = (double)ce02_zero_savings * 100.0 / (double)total_opcode_bytes;
            printf(" (%.1f%% of total opcode bytes)", percent);
        }
        printf("\n");
    }

    if (include_other_improvements) {
        printf("========================================\n");
        printf("\n=== Other Possible Improvements ===\n");
        if (lda_zero_count > 0) {
            printf("\n  LDZ #0 -> TZA: %d\n", lda_zero_count);
        }
        if (brs_count > 0) {
            printf("  BRS replacements: %d (from %d JSR instructions) (NOTE: BRS opcode does not exist)\n", brs_count, total_jsr_count);
        }
        printf("========================================\n");
    } else {
        printf("========================================\n");
    }
}

static void print_65C02_replacement_suggestions(void) {
    if (replacement_count == 0) {
        return;
    }

    printf("\n=== 65C02 Replacement Suggestions ===\n");
    for (int i = 0; i < replacement_count; i++) {
        replacement_t *r = &replacements[i];
        if (strcmp(r->type, "BRS") == 0) continue;
        printf("  %s: %s:%d\n", r->type, r->filename, r->line_num);
        if (strcmp(r->type, "BRA") == 0) {
            int16_t offset = (int16_t)(r->target_addr - (r->instr_addr + 2));
            printf("    Instruction address: $%04X, Target address: $%04X, Offset: %+d\n",
                   r->instr_addr, r->target_addr, offset);
        }
        printf("    Old: %s\n", r->old_code);
        printf("    New: %s\n", r->new_code);
    }
    printf("======================================\n");
}

static void print_code_optimization_suggestions(void) {
    if (optimization_count == 0) {
        return;
    }

    printf("\n=== Code Optimization Suggestions ===\n");
    for (int i = 0; i < optimization_count; i++) {
        replacement_t *r = &optimizations[i];
        printf("  %s: %s:%d\n", r->type, r->filename, r->line_num);
        printf("    Old: %s\n", r->old_code);
        printf("    New: %s\n", r->new_code);
    }
    printf("=====================================\n");
}

void stats_print_report(void) {
    print_assembler_statistics();
    print_binary_statistics(0);
    print_opcode_statistics();
    print_code_optimization_summary();
    print_immediate_zero_statistics();
    print_65CE02_replacement_opportunities(0, 1, 0);
}

void stats_print_report_custom(int print_stats, int show_suggestions) {
    if (print_stats) {
        print_assembler_statistics();
        print_binary_statistics(1);
        print_opcode_statistics();
        print_immediate_zero_statistics();
        print_65CE02_replacement_opportunities(1, 0, 1);
        print_code_optimization_summary();
    }

    if (show_suggestions) {
        print_65C02_replacement_suggestions();
        print_code_optimization_suggestions();
    }
}

int stats_get_count(uint8_t opcode) {
    return opcode_counts[opcode];
}

int stats_is_c02_opcode(uint8_t opcode) {
    for (int i = 0; i < (int)NUM_C02_OPCODES; i++) {
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

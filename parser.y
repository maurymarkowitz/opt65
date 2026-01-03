%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "stats.h"

extern FILE *yyin;
extern int yylex(void);
extern int yyparse(void);
extern int yylineno;
char *yyfilename = NULL;

/* Flex buffer functions for macro expansion */
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *str);
extern void yypush_buffer_state(YY_BUFFER_STATE new_buffer);
extern void yypop_buffer_state(void);

void yyerror(const char *s);

/* Symbol table */
typedef struct {
    char *name;
    uint16_t value;
} symbol_t;

#define MAX_SYMBOLS 4096
symbol_t symbols[MAX_SYMBOLS];
int symbol_count = 0;

/* Macro table */
typedef struct {
    char *name;
    char *body;  /* Macro body as text */
    int body_len;
} macro_t;

#define MAX_MACROS 256
macro_t macros[MAX_MACROS];
int macro_count = 0;
int in_macro_definition = 0;
char *current_macro_name = NULL;
char *current_macro_body = NULL;
int current_macro_body_size = 0;
int current_macro_body_len = 0;

/* Conditional compilation stack */
#define MAX_IF_DEPTH 32
int if_stack[MAX_IF_DEPTH];
int if_stack_depth = 0;

/* Forward declaration */
int is_conditional_active(void);

/* Output buffer */
uint8_t output[65536];
uint16_t pc = 0;
uint16_t org_address = 0;
uint16_t min_address = 0xFFFF;  /* Track minimum address where code was emitted */
uint16_t max_address = 0;       /* Track maximum address where code was emitted */
uint16_t min_opcode_address = 0xFFFF;  /* Track minimum address where opcodes were emitted */
uint16_t max_opcode_address = 0;       /* Track maximum address where opcodes were emitted */

/* Two-pass assembly support */
int pass = 1;  /* 1 = symbol collection, 2 = code generation */

/* Forward declarations */
uint16_t eval_expr(char *expr);
void add_symbol(char *name, uint16_t value);
uint16_t get_symbol(char *name);
void emit_byte(uint8_t byte);
void emit_word(uint16_t word);
void emit_indexed(uint8_t zp_op, uint8_t abs_op, char *expr);
void emit_addr(uint8_t zp_op, uint8_t abs_op, char *expr);
void emit_opcode(uint8_t opcode);
void check_zero_transfer(const char *instr, uint8_t opcode, char *expr);
void add_macro(char *name, char *body);
macro_t *get_macro(char *name);
void start_macro_definition(char *name);
void append_to_macro_body(const char *text);
void end_macro_definition(void);
%}

%union {
    int ival;
    char *sval;
}

%token <sval> IDENTIFIER HEX_NUMBER DEC_NUMBER
%token ADC AND ASL BCC BCS BEQ BIT BMI BNE BPL BRK BVC BVS
%token CLC CLD CLI CLV CMP CPX CPY DEC DEX DEY EOR INC INX INY
%token JMP JSR LDA LDX LDY LSR NOP ORA PHA PHP PLA PLP
%token ROL ROR RTI RTS SBC SEC SED SEI STA STX STY
%token TAX TAY TSX TXA TXS TYA
%token BRA PHX PHY PLX PLY STZ TRB TSB WAI STP
%token ORG BYTE WORD RES EQU MACRO ENDM PAGE TITLE LIST IF ENDIF END
%token LOW HIGH
%token AND_OP OR_OP
%token <sval> MACRO_BODY
%token HASH LPAREN RPAREN COMMA COLON EQUALS XREG YREG NEWLINE
%token PLUS MINUS MULTIPLY DIVIDE ORG_EQUALS
%left PLUS MINUS
%left MULTIPLY DIVIDE AND_OP OR_OP
%right UMINUS

%type <sval> expression
%type <ival> expr_value

%%

program:
    | program line
    ;

line:
    NEWLINE
    | label NEWLINE
    | instruction NEWLINE
    | directive NEWLINE
    | label instruction NEWLINE
    | label directive NEWLINE
    | assignment NEWLINE
    | label assignment NEWLINE
    | org_equals NEWLINE
    | label org_equals NEWLINE
    | TITLE { /* Title directive - no-op, rest of line will be consumed by lexer */ }
    | LIST IDENTIFIER NEWLINE { /* List directive - no-op */ }
    | macro_start
    | macro_invocation
    | if_block
    | endif_directive
    | END { 
        if (pass == 2) {
            YYACCEPT;  /* End of file - stop parsing in pass 2 only */
        }
        /* In pass 1, continue to build complete symbol table */
    }
    | END NEWLINE { 
        if (pass == 2) {
            YYACCEPT;  /* End of file - stop parsing in pass 2 only */
        }
        /* In pass 1, continue to build complete symbol table */
    }
    ;

if_block:
    IF expr_value NEWLINE {
        int condition = $2 != 0;
        if (if_stack_depth >= MAX_IF_DEPTH) {
            fprintf(stderr, "Error: IF nesting too deep at line %d\n", yylineno);
        } else {
            if_stack[if_stack_depth++] = condition ? 1 : 0;
        }
    }
    ;

endif_directive:
    ENDIF NEWLINE {
        if (if_stack_depth == 0) {
            fprintf(stderr, "Error: ENDIF without matching IF at line %d\n", yylineno);
        } else {
            if_stack_depth--;
        }
    }
    ;

label:
    IDENTIFIER COLON
    {
        if (is_conditional_active()) {
            add_symbol($1, pc);
        }
    }
    ;

assignment:
    IDENTIFIER EQU expr_value { 
        if (is_conditional_active()) {
            add_symbol($1, $3); 
        }
    }
    | IDENTIFIER EQUALS expr_value { 
        if (is_conditional_active()) {
            add_symbol($1, $3); 
        }
    }
    | IDENTIFIER EQUALS MULTIPLY { 
        if (is_conditional_active()) {
            add_symbol($1, pc); 
        }
    }  /* =* location counter */
    ;

org_equals:
    ORG_EQUALS expr_value { 
        if (is_conditional_active()) {
            /* *= only sets PC, not org_address (org_address is set by first .ORG) */
            if (org_address == 0) {
                org_address = $2;  /* Only set org_address if not already set */
            }
            pc = $2; 
        }
    }
    ;

instruction:
    implied_instruction
    | accumulator_instruction
    | immediate_instruction
    | address_instruction
    | indexed_instruction
    | indirect_instruction
    | relative_instruction
    | c02_instruction
    ;

implied_instruction:
    BRK { emit_opcode(0x00); }
    | CLC { emit_opcode(0x18); }
    | CLD { emit_opcode(0xD8); }
    | CLI { emit_opcode(0x58); }
    | CLV { emit_opcode(0xB8); }
    | DEX { emit_opcode(0xCA); }
    | DEY { emit_opcode(0x88); }
    | INX { emit_opcode(0xE8); }
    | INY { emit_opcode(0xC8); }
    | NOP { emit_opcode(0xEA); }
    | PHA { 
        emit_opcode(0x48);
        extern char *yyfilename;
        stats_record_instruction(0x48, "PHA", 0, yylineno, yyfilename, NULL);
    }
    | PHP { emit_opcode(0x08); }
    | PLA { 
        emit_opcode(0x68);
        extern char *yyfilename;
        stats_record_instruction(0x68, "PLA", 0, yylineno, yyfilename, NULL);
    }
    | PLP { emit_opcode(0x28); }
    | RTI { emit_opcode(0x40); }
    | RTI IDENTIFIER { emit_opcode(0x40); }  /* Allow optional label annotation */
    | RTS { emit_opcode(0x60); }
    | RTS IDENTIFIER { emit_opcode(0x60); }  /* Allow optional label annotation like RTS RETURN */
    | RTS ADC { emit_opcode(0x60); }  /* Ignore any token after RTS */
    | RTS AND { emit_opcode(0x60); }  /* Ignore any token after RTS */
    | RTS ASL { emit_opcode(0x60); }
    | RTS BCC { emit_opcode(0x60); }
    | RTS BCS { emit_opcode(0x60); }
    | RTS BEQ { emit_opcode(0x60); }
    | RTS BIT { emit_opcode(0x60); }
    | RTS BMI { emit_opcode(0x60); }
    | RTS BNE { emit_opcode(0x60); }
    | RTS BPL { emit_opcode(0x60); }
    | RTS BRK { emit_opcode(0x60); }
    | RTS BVC { emit_opcode(0x60); }
    | RTS BVS { emit_opcode(0x60); }
    | RTS CLC { emit_opcode(0x60); }
    | RTS CLD { emit_opcode(0x60); }
    | RTS CLI { emit_opcode(0x60); }
    | RTS CLV { emit_opcode(0x60); }
    | RTS CMP { emit_opcode(0x60); }
    | RTS CPX { emit_opcode(0x60); }
    | RTS CPY { emit_opcode(0x60); }
    | RTS DEC { emit_opcode(0x60); }
    | RTS DEX { emit_opcode(0x60); }
    | RTS DEY { emit_opcode(0x60); }
    | RTS EOR { emit_opcode(0x60); }
    | RTS INC { emit_opcode(0x60); }
    | RTS INX { emit_opcode(0x60); }
    | RTS INY { emit_opcode(0x60); }
    | RTS JMP { emit_opcode(0x60); }
    | RTS JSR { emit_opcode(0x60); }
    | RTS LDA { emit_opcode(0x60); }
    | RTS LDX { emit_opcode(0x60); }
    | RTS LDY { emit_opcode(0x60); }
    | RTS LSR { emit_opcode(0x60); }
    | RTS NOP { emit_opcode(0x60); }
    | RTS ORA { emit_opcode(0x60); }
    | RTS PHA { emit_opcode(0x60); }
    | RTS PHP { emit_opcode(0x60); }
    | RTS PLA { emit_opcode(0x60); }
    | RTS PLP { emit_opcode(0x60); }
    | RTS ROL { emit_opcode(0x60); }
    | RTS ROR { emit_opcode(0x60); }
    | RTS RTI { emit_opcode(0x60); }
    | RTS RTS { emit_opcode(0x60); }
    | RTS SBC { emit_opcode(0x60); }
    | RTS SEC { emit_opcode(0x60); }
    | RTS SED { emit_opcode(0x60); }
    | RTS SEI { emit_opcode(0x60); }
    | RTS STA { emit_opcode(0x60); }
    | RTS STX { emit_opcode(0x60); }
    | RTS STY { emit_opcode(0x60); }
    | RTS TAX { emit_opcode(0x60); }
    | RTS TAY { emit_opcode(0x60); }
    | RTS TSX { emit_opcode(0x60); }
    | RTS TXA { emit_opcode(0x60); }
    | RTS TXS { emit_opcode(0x60); }
    | RTS TYA { emit_opcode(0x60); }
    | RTS BRA { emit_opcode(0x60); }
    | RTS PHX { emit_opcode(0x60); }
    | RTS PHY { emit_opcode(0x60); }
    | RTS PLX { emit_opcode(0x60); }
    | RTS PLY { emit_opcode(0x60); }
    | RTS STZ { emit_opcode(0x60); }
    | RTS TRB { emit_opcode(0x60); }
    | RTS TSB { emit_opcode(0x60); }
    | RTS WAI { emit_opcode(0x60); }
    | RTS STP { emit_opcode(0x60); }
    | SEC { emit_opcode(0x38); }
    | SED { emit_opcode(0xF8); }
    | SEI { emit_opcode(0x78); }
    | TAX { 
        emit_opcode(0xAA);
        extern char *yyfilename;
        stats_record_instruction(0xAA, "TAX", 0, yylineno, yyfilename, NULL);
    }
    | TAY { 
        emit_opcode(0xA8);
        extern char *yyfilename;
        stats_record_instruction(0xA8, "TAY", 0, yylineno, yyfilename, NULL);
    }
    | TSX { emit_opcode(0xBA); }
    | TXA { emit_opcode(0x8A); }
    | TXS { emit_opcode(0x9A); }
    | TYA { emit_opcode(0x98); }
    ;

accumulator_instruction:
    ASL { emit_opcode(0x0A); }
    | LSR { emit_opcode(0x4A); }
    | ROL { emit_opcode(0x2A); }
    | ROR { emit_opcode(0x6A); }
    ;

immediate_instruction:
    ADC HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0x69); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("ADC #0", 0x69, $3);
            stats_record_immediate_zero(0x69);
        }
        extern char *yyfilename;
        stats_record_instruction(0x69, "ADC", val, yylineno, yyfilename, NULL);
    }
    | AND HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0x29); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("AND #0", 0x29, $3);
            stats_record_immediate_zero(0x29);
        }
        extern char *yyfilename;
        stats_record_instruction(0x29, "AND", val, yylineno, yyfilename, NULL);
    }
    | CMP HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xC9); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("CMP #0", 0xC9, $3);
            stats_record_immediate_zero(0xC9);
        }
    }
    | CPX HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xE0); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("CPX #0", 0xE0, $3);
            stats_record_immediate_zero(0xE0);
        }
    }
    | CPY HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xC0); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("CPY #0", 0xC0, $3);
            stats_record_immediate_zero(0xC0);
        }
    }
    | EOR HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0x49); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("EOR #0", 0x49, $3);
            stats_record_immediate_zero(0x49);
        }
    }
    | LDA HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xA9); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("LDA #0", 0xA9, $3);
            stats_record_immediate_zero(0xA9);
        }
        extern char *yyfilename;
        stats_record_instruction(0xA9, "LDA", val, yylineno, yyfilename, $3);
    }
    | LDX HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xA2); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("LDX #0", 0xA2, $3);
            stats_record_immediate_zero(0xA2);
        }
    }
    | LDY HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xA0); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("LDY #0", 0xA0, $3);
            stats_record_immediate_zero(0xA0);
        }
    }
    | ORA HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0x09); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("ORA #0", 0x09, $3);
            stats_record_immediate_zero(0x09);
        }
        extern char *yyfilename;
        stats_record_instruction(0x09, "ORA", val, yylineno, yyfilename, NULL);
    }
    | SBC HASH expression { 
        uint8_t val = eval_expr($3) & 0xFF;
        emit_opcode(0xE9); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("SBC #0", 0xE9, $3);
            stats_record_immediate_zero(0xE9);
        }
        extern char *yyfilename;
        stats_record_instruction(0xE9, "SBC", val, yylineno, yyfilename, NULL);
    }
    ;

address_instruction:
    ADC expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x65, 0x6D, $2);
        if (addr == 0) check_zero_transfer("ADC $00", 0x65, $2);
    }
    | AND expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x25, 0x2D, $2);
        if (addr == 0) check_zero_transfer("AND $00", 0x25, $2);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x25 : 0x2D;
        stats_record_instruction(op, "AND", addr, yylineno, yyfilename, NULL);
    }
    | ASL expression { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ($2 && strcasecmp($2, "A") == 0) {
            emit_opcode(0x0A);  /* ASL A is same as ASL */
        } else {
            emit_addr(0x06, 0x0E, $2);
        }
    }
    | BIT expression { emit_addr(0x24, 0x2C, $2); }
    | CMP expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xC5, 0xCD, $2);
        if (addr == 0) check_zero_transfer("CMP $00", 0xC5, $2);
    }
    | CPX expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xE4, 0xEC, $2);
        if (addr == 0) check_zero_transfer("CPX $00", 0xE4, $2);
    }
    | CPY expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xC4, 0xCC, $2);
        if (addr == 0) check_zero_transfer("CPY $00", 0xC4, $2);
    }
    | DEC expression { emit_addr(0xC6, 0xCE, $2); }
    | EOR expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x45, 0x4D, $2);
        if (addr == 0) check_zero_transfer("EOR $00", 0x45, $2);
    }
    | INC expression { emit_addr(0xE6, 0xEE, $2); }
    | JMP expression { 
        if (pass == 2) {
            uint16_t addr = eval_expr($2);
            emit_opcode(0x4C);
            emit_word(addr);
            extern char *yyfilename;
            stats_record_instruction(0x4C, "JMP", addr, yylineno, yyfilename, $2);
        } else {
            emit_opcode(0x4C);
            emit_word(0);
        }
    }
    | JSR expression { 
        if (pass == 2) {
            uint16_t addr = eval_expr($2);
            emit_opcode(0x20);
            emit_word(addr);
        } else {
            emit_opcode(0x20);
            emit_word(0);
        }
    }
    | LDA expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xA5, 0xAD, $2);
        if (addr == 0) check_zero_transfer("LDA $00", 0xA5, $2);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0xA5 : 0xAD;
        stats_record_instruction(op, "LDA", addr, yylineno, yyfilename, NULL);
    }
    | LDX expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xA6, 0xAE, $2);
        if (addr == 0) check_zero_transfer("LDX $00", 0xA6, $2);
    }
    | LDY expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xA4, 0xAC, $2);
        if (addr == 0) check_zero_transfer("LDY $00", 0xA4, $2);
    }
    | LSR expression { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ($2 && strcasecmp($2, "A") == 0) {
            emit_opcode(0x4A);  /* LSR A is same as LSR */
        } else {
            emit_addr(0x46, 0x4E, $2);
        }
    }
    | ORA expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x05, 0x0D, $2);
        if (addr == 0) check_zero_transfer("ORA $00", 0x05, $2);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x05 : 0x0D;
        stats_record_instruction(op, "ORA", addr, yylineno, yyfilename, NULL);
    }
    | ROL expression { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ($2 && strcasecmp($2, "A") == 0) {
            emit_opcode(0x2A);  /* ROL A is same as ROL */
        } else {
            emit_addr(0x26, 0x2E, $2);
        }
    }
    | ROR expression { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ($2 && strcasecmp($2, "A") == 0) {
            emit_opcode(0x6A);  /* ROR A is same as ROR */
        } else {
            emit_addr(0x66, 0x6E, $2);
        }
    }
    | SBC expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0xE5, 0xED, $2);
        if (addr == 0) check_zero_transfer("SBC $00", 0xE5, $2);
    }
    | STA expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x85, 0x8D, $2);
        if (addr == 0) {
            check_zero_transfer("STA $00", 0x85, $2);
            stats_record_sta_zero();
        }
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x85 : 0x8D;
        stats_record_instruction(op, "STA", addr, yylineno, yyfilename, NULL);
    }
    | STX expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x86, 0x8E, $2);
        if (addr == 0) check_zero_transfer("STX $00", 0x86, $2);
    }
    | STY expression { 
        uint16_t addr = eval_expr($2);
        emit_addr(0x84, 0x8C, $2);
        if (addr == 0) check_zero_transfer("STY $00", 0x84, $2);
    }
    ;

indexed_instruction:
    ADC expression COMMA XREG { emit_indexed(0x75, 0x7D, $2); }
    | ADC expression COMMA YREG { emit_indexed(0x79, 0x79, $2); }
    | AND expression COMMA XREG { emit_indexed(0x35, 0x3D, $2); }
    | AND expression COMMA YREG { emit_indexed(0x39, 0x39, $2); }
    | ASL expression COMMA XREG { emit_indexed(0x16, 0x1E, $2); }
    | CMP expression COMMA XREG { emit_indexed(0xD5, 0xDD, $2); }
    | CMP expression COMMA YREG { emit_indexed(0xD9, 0xD9, $2); }
    | DEC expression COMMA XREG { emit_indexed(0xD6, 0xDE, $2); }
    | EOR expression COMMA XREG { emit_indexed(0x55, 0x5D, $2); }
    | EOR expression COMMA YREG { emit_indexed(0x59, 0x59, $2); }
    | INC expression COMMA XREG { emit_indexed(0xF6, 0xFE, $2); }
    | LDA expression COMMA XREG { 
        uint16_t addr = eval_expr($2);
        emit_indexed(0xB5, 0xBD, $2);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0xB5 : 0xBD;
        stats_record_instruction(op, "LDA", addr, yylineno, yyfilename, NULL);
    }
    | LDA expression COMMA YREG { 
        uint16_t addr = eval_expr($2);
        emit_indexed(0xB9, 0xB9, $2);
        extern char *yyfilename;
        stats_record_instruction(0xB9, "LDA", addr, yylineno, yyfilename, NULL);
    }
    | LDX expression COMMA YREG { emit_indexed(0xB6, 0xBE, $2); }
    | LDY expression COMMA XREG { emit_indexed(0xB4, 0xBC, $2); }
    | LSR expression COMMA XREG { emit_indexed(0x56, 0x5E, $2); }
    | ORA expression COMMA XREG { emit_indexed(0x15, 0x1D, $2); }
    | ORA expression COMMA YREG { emit_indexed(0x19, 0x19, $2); }
    | ROL expression COMMA XREG { emit_indexed(0x36, 0x3E, $2); }
    | ROR expression COMMA XREG { emit_indexed(0x76, 0x7E, $2); }
    | SBC expression COMMA XREG { emit_indexed(0xF5, 0xFD, $2); }
    | SBC expression COMMA YREG { emit_indexed(0xF9, 0xF9, $2); }
    | STA expression COMMA XREG { 
        uint16_t addr = eval_expr($2);
        emit_indexed(0x95, 0x9D, $2);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x95 : 0x9D;
        stats_record_instruction(op, "STA", addr, yylineno, yyfilename, NULL);
    }
    | STA expression COMMA YREG { 
        uint16_t addr = eval_expr($2);
        emit_indexed(0x99, 0x99, $2);
        extern char *yyfilename;
        stats_record_instruction(0x99, "STA", addr, yylineno, yyfilename, NULL);
    }
    | STX expression COMMA YREG { 
        uint16_t addr = eval_expr($2);
        if (addr >= 256) {
            fprintf(stderr, "Error: STX,Y only supports zero page addressing\n");
        }
        emit_opcode(0x96);
        emit_byte(addr & 0xFF);
    }
    | STY expression COMMA XREG { 
        uint16_t addr = eval_expr($2);
        if (addr >= 256) {
            fprintf(stderr, "Error: STY,X only supports zero page addressing\n");
        }
        emit_opcode(0x94);
        emit_byte(addr & 0xFF);
    }
    ;

indirect_instruction:
    JMP LPAREN expression RPAREN { 
        if (pass == 2) {
            emit_opcode(0x6C);
            emit_word(eval_expr($3));
        } else {
            emit_opcode(0x6C);
            emit_word(0);
        }
    }
    | ADC LPAREN expression COMMA XREG RPAREN { emit_opcode(0x61); emit_byte(eval_expr($3) & 0xFF); }
    | AND LPAREN expression COMMA XREG RPAREN { emit_opcode(0x21); emit_byte(eval_expr($3) & 0xFF); }
    | CMP LPAREN expression COMMA XREG RPAREN { emit_opcode(0xC1); emit_byte(eval_expr($3) & 0xFF); }
    | EOR LPAREN expression COMMA XREG RPAREN { emit_opcode(0x41); emit_byte(eval_expr($3) & 0xFF); }
    | LDA LPAREN expression COMMA XREG RPAREN { emit_opcode(0xA1); emit_byte(eval_expr($3) & 0xFF); }
    | ORA LPAREN expression COMMA XREG RPAREN { emit_opcode(0x01); emit_byte(eval_expr($3) & 0xFF); }
    | SBC LPAREN expression COMMA XREG RPAREN { emit_opcode(0xE1); emit_byte(eval_expr($3) & 0xFF); }
    | STA LPAREN expression COMMA XREG RPAREN { emit_opcode(0x81); emit_byte(eval_expr($3) & 0xFF); }
    | ADC LPAREN expression RPAREN COMMA YREG { emit_opcode(0x71); emit_byte(eval_expr($3) & 0xFF); }
    | AND LPAREN expression RPAREN COMMA YREG { emit_opcode(0x31); emit_byte(eval_expr($3) & 0xFF); }
    | CMP LPAREN expression RPAREN COMMA YREG { emit_opcode(0xD1); emit_byte(eval_expr($3) & 0xFF); }
    | EOR LPAREN expression RPAREN COMMA YREG { emit_opcode(0x51); emit_byte(eval_expr($3) & 0xFF); }
    | LDA LPAREN expression RPAREN COMMA YREG { emit_opcode(0xB1); emit_byte(eval_expr($3) & 0xFF); }
    | ORA LPAREN expression RPAREN COMMA YREG { emit_opcode(0x11); emit_byte(eval_expr($3) & 0xFF); }
    | SBC LPAREN expression RPAREN COMMA YREG { emit_opcode(0xF1); emit_byte(eval_expr($3) & 0xFF); }
    | STA LPAREN expression RPAREN COMMA YREG { emit_opcode(0x91); emit_byte(eval_expr($3) & 0xFF); }
    ;

relative_instruction:
    BCC expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0x90); 
            emit_byte(offset & 0xFF);
        } else {
            /* Pass 1: Just advance PC */
            emit_opcode(0x90);
            emit_byte(0);
        }
    }
    | BCS expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0xB0); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0xB0);
            emit_byte(0);
        }
    }
    | BEQ expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0xF0); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0xF0);
            emit_byte(0);
        }
    }
    | BMI expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0x30); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0x30);
            emit_byte(0);
        }
    }
    | BNE expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0xD0); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0xD0);
            emit_byte(0);
        }
    }
    | BPL expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0x10); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0x10);
            emit_byte(0);
        }
    }
    | BVC expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0x50); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0x50);
            emit_byte(0);
        }
    }
    | BVS expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0x70); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0x70);
            emit_byte(0);
        }
    }
    ;

c02_instruction:
    BRA expression { 
        if (pass == 2) {
            uint16_t target = eval_expr($2);
            int16_t offset = (int16_t)(target - (pc + 1));
            if (offset < -128 || offset > 127) {
                fprintf(stderr, "Error: Branch offset out of range at line %d (target address: $%04X, offset: %d)\n", yylineno, target, offset);
            }
            emit_opcode(0x80); 
            emit_byte(offset & 0xFF);
        } else {
            emit_opcode(0x80);
            emit_byte(0);
        }
    }
    | PHX { emit_opcode(0xDA); }
    | PHY { emit_opcode(0x5A); }
    | PLX { emit_opcode(0xFA); }
    | PLY { emit_opcode(0x7A); }
    | WAI { emit_opcode(0xCB); }
    | STP { emit_opcode(0xDB); }
    | STZ expression { 
        uint16_t addr = eval_expr($2);
        if (addr < 256) {
            emit_opcode(0x64);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x9C);
            emit_word(addr);
        }
    }
    | STZ expression COMMA XREG { 
        uint16_t addr = eval_expr($2);
        if (addr < 256) {
            emit_opcode(0x74);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x9E);
            emit_word(addr);
        }
    }
    | TRB expression { 
        uint16_t addr = eval_expr($2);
        if (addr < 256) {
            emit_opcode(0x14);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x1C);
            emit_word(addr);
        }
    }
    | TSB expression { 
        uint16_t addr = eval_expr($2);
        if (addr < 256) {
            emit_opcode(0x04);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x0C);
            emit_word(addr);
        }
    }
    ;

directive:
    ORG expression { org_address = eval_expr($2); pc = org_address; }
    | ORG_EQUALS expression { 
        uint16_t new_pc = eval_expr($2);
        /* *= only sets PC, not org_address (org_address is set by first .ORG) */
        if (org_address == 0) {
            org_address = new_pc;  /* Only set org_address if not already set */
        }
        pc = new_pc; 
    }
    | BYTE byte_list { /* byte_list handles emitting */ }
    | WORD word_list { /* word_list handles emitting */ }
    | RES expression { pc += eval_expr($2); }
    | EQU expression { /* .EQU handled in assignment rule */ }
    | PAGE { /* Page break - no-op */ }
    | TITLE { /* Title directive - no-op, ignore the string (handled as any expression) */ }
    | LIST { /* List directive - no-op, ignore the parameter */ }
    | LIST IDENTIFIER { /* List directive with parameter - no-op, ignore parameter */ }
    | LIST XREG { /* List directive with X parameter - no-op, ignore parameter */ }
    | LIST YREG { /* List directive with Y parameter - no-op, ignore parameter */ }
    | LIST expression { /* List directive with expression - no-op, ignore parameter */ }
    | END { 
        if (pass == 2) {
            YYACCEPT;  /* End of file - stop parsing in pass 2 only */
        }
        /* In pass 1, continue to build complete symbol table */
    }
    ;

byte_list:
    expression { 
        if (is_conditional_active()) {
            emit_byte(eval_expr($1) & 0xFF); 
        }
    }
    | byte_list COMMA expression { 
        if (is_conditional_active()) {
            emit_byte(eval_expr($3) & 0xFF); 
        }
    }
    ;

word_list:
    expression { 
        if (is_conditional_active()) {
            emit_word(eval_expr($1)); 
        }
    }
    | word_list COMMA expression { 
        if (is_conditional_active()) {
            emit_word(eval_expr($3)); 
        }
    }
    ;

macro_start:
    MACRO IDENTIFIER NEWLINE { 
        start_macro_definition($2);
        /* Read lines until ENDM - we need to read from the file directly */
        /* This is a bit of a hack, but it works */
        extern FILE *yyin;
        char line[1024];
        int found_endm = 0;
        while (!found_endm && fgets(line, sizeof(line), yyin)) {
            /* Check if this line is ENDM */
            char *p = line;
            while (*p == ' ' || *p == '\t') p++; /* Skip whitespace */
            if (strncasecmp(p, ".ENDM", 5) == 0 || strncasecmp(p, "ENDM", 4) == 0 ||
                strncasecmp(p, ".ENDMACRO", 9) == 0 || strncasecmp(p, "ENDMACRO", 8) == 0) {
                /* Found ENDM, stop reading */
                found_endm = 1;
                break;
            }
            /* Remove trailing newline and add to macro body */
            int len = strlen(line);
            if (len > 0 && line[len-1] == '\n') {
                line[len-1] = '\0';
            }
            if (len > 0) {
                append_to_macro_body(line);
            }
        }
        end_macro_definition();
    }
    | ENDM NEWLINE { /* This handles ENDM when not in a macro definition (error case) */ }
    ;

macro_invocation:
    IDENTIFIER { 
        macro_t *m = get_macro($1);
        if (m) {
            /* Expand macro using Flex's string scanning */
            extern YY_BUFFER_STATE yy_scan_string(const char *);
            extern void yypush_buffer_state(YY_BUFFER_STATE);
            
            YY_BUFFER_STATE macro_buffer = yy_scan_string(m->body);
            yypush_buffer_state(macro_buffer);
            /* The lexer will now read from the macro body */
            /* Continue parsing - the macro body will be parsed as regular lines */
        } else {
            /* Not a macro - treat as error for now */
            fprintf(stderr, "Error: Unknown identifier '%s' (not a macro or label) at line %d\n", $1, yylineno);
        }
    }
    ;

expression:
    IDENTIFIER { $$ = $1; }
    | HEX_NUMBER { $$ = $1; }
    | DEC_NUMBER { $$ = $1; }
    | MULTIPLY { 
        /* Current location counter - convert to string */
        char *result = malloc(16);
        snprintf(result, 16, "%d", pc);
        $$ = result;
    }
    | LOW IDENTIFIER {
        /* Extract low byte of address */
        uint16_t addr = eval_expr($2);
        uint8_t low_byte = addr & 0xFF;
        char *result = malloc(16);
        snprintf(result, 16, "$%02X", low_byte);
        $$ = result;
    }
    | HIGH IDENTIFIER {
        /* Extract high byte of address */
        uint16_t addr = eval_expr($2);
        uint8_t high_byte = (addr >> 8) & 0xFF;
        char *result = malloc(16);
        snprintf(result, 16, "$%02X", high_byte);
        $$ = result;
    }
    | MINUS expression { 
        uint16_t val = eval_expr($2);
        int16_t neg_val = -(int16_t)val;
        /* For 8-bit values, we want the two's complement */
        uint8_t byte_val = (uint8_t)neg_val;
        char *result = malloc(16);
        /* Always format as hex for immediate values to ensure eval_expr can parse it */
        snprintf(result, 16, "$%02X", byte_val);
        $$ = result;
    }
    | PLUS expression { $$ = $2; }  /* Unary plus (no-op) */
    | expression PLUS expression { 
        uint16_t left = eval_expr($1);
        uint16_t right = eval_expr($3);
        char *result = malloc(16);
        snprintf(result, 16, "%d", left + right);
        $$ = result;
    }
    | expression MINUS expression { 
        uint16_t left = eval_expr($1);
        uint16_t right = eval_expr($3);
        char *result = malloc(16);
        snprintf(result, 16, "%d", left - right);
        $$ = result;
    }
    | expression MULTIPLY expression { 
        uint16_t left = eval_expr($1);
        uint16_t right = eval_expr($3);
        char *result = malloc(16);
        snprintf(result, 16, "%d", left * right);
        $$ = result;
    }
    | expression DIVIDE expression { 
        uint16_t left = eval_expr($1);
        uint16_t right = eval_expr($3);
        if (right == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            right = 1;
        }
        char *result = malloc(16);
        snprintf(result, 16, "%d", left / right);
        $$ = result;
    }
    | expression AND_OP expression {
        uint16_t left = eval_expr($1);
        uint16_t right = eval_expr($3);
        uint16_t result_val = left & right;
        char *result = malloc(16);
        /* Format as hex if either operand was hex */
        if ((strlen($1) > 0 && $1[0] == '$') || (strlen($3) > 0 && $3[0] == '$')) {
            snprintf(result, 16, "$%02X", result_val & 0xFF);
        } else {
            snprintf(result, 16, "%d", result_val);
        }
        $$ = result;
    }
    | expression OR_OP expression {
        uint16_t left = eval_expr($1);
        uint16_t right = eval_expr($3);
        uint16_t result_val = left | right;
        char *result = malloc(16);
        /* Format as hex if either operand was hex */
        if ((strlen($1) > 0 && $1[0] == '$') || (strlen($3) > 0 && $3[0] == '$')) {
            snprintf(result, 16, "$%02X", result_val & 0xFF);
        } else {
            snprintf(result, 16, "%d", result_val);
        }
        $$ = result;
    }
    | LPAREN expression RPAREN { $$ = $2; }
    ;

expr_value:
    IDENTIFIER { $$ = eval_expr($1); }
    | HEX_NUMBER { $$ = eval_expr($1); }
    | DEC_NUMBER { $$ = eval_expr($1); }
    | MULTIPLY { $$ = pc; }  /* Current location counter */
    | LOW IDENTIFIER {
        /* Extract low byte of address */
        uint16_t addr = eval_expr($2);
        $$ = addr & 0xFF;
    }
    | HIGH IDENTIFIER {
        /* Extract high byte of address */
        uint16_t addr = eval_expr($2);
        $$ = (addr >> 8) & 0xFF;
    }
    | MINUS expr_value %prec UMINUS { $$ = -$2; }  /* Unary minus */
    | PLUS expr_value { $$ = $2; }  /* Unary plus (no-op) */
    | expr_value PLUS expr_value { $$ = $1 + $3; }
    | expr_value MINUS expr_value { $$ = $1 - $3; }
    | expr_value MULTIPLY expr_value { $$ = $1 * $3; }
    | expr_value DIVIDE expr_value { 
        if ($3 == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            $$ = $1;
        } else {
            $$ = $1 / $3;
        }
    }
    | expr_value AND_OP expr_value {
        $$ = $1 & $3;
    }
    | expr_value OR_OP expr_value {
        $$ = $1 | $3;
    }
    | LPAREN expr_value RPAREN { $$ = $2; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

uint16_t eval_expr(char *expr) {
    if (!expr) return 0;
    
    /* Check if it's a hex number */
    if (expr[0] == '$') {
        return (uint16_t)strtol(expr + 1, NULL, 16);
    }
    
    /* Check if it's a decimal number */
    if (expr[0] >= '0' && expr[0] <= '9') {
        return (uint16_t)strtol(expr, NULL, 10);
    }
    
    /* Otherwise it's a symbol */
    return get_symbol(expr);
}

void add_symbol(char *name, uint16_t value) {
    if (!is_conditional_active()) return;  /* Skip if in false conditional block */
    if (symbol_count >= MAX_SYMBOLS) {
        fprintf(stderr, "Error: Too many symbols\n");
        return;
    }
    
    /* Check if symbol already exists */
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0) {
            symbols[i].value = value;
            return;
        }
    }
    
    symbols[symbol_count].name = strdup(name);
    symbols[symbol_count].value = value;
    symbol_count++;
}

uint16_t get_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbols[i].name, name) == 0) {
            return symbols[i].value;
        }
    }
    
    /* In pass 1, forward references are expected - don't warn */
    if (pass == 2) {
        fprintf(stderr, "Warning: Undefined symbol '%s' at line %d, assuming 0\n", name, yylineno);
    }
    return 0;
}

int is_conditional_active(void) {
    /* If we're in any false conditional block, return 0 */
    for (int i = 0; i < if_stack_depth; i++) {
        if (if_stack[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void emit_byte(uint8_t byte) {
    if (!is_conditional_active()) return;  /* Skip if in false conditional block */
    if (pc > 65535) {
        fprintf(stderr, "Error: Program counter overflow\n");
        return;
    }
    if (pass == 2) {
        output[pc] = byte;  /* Only write to output in pass 2 */
        /* Track actual address range where bytes were emitted */
        if (pc < min_address) min_address = pc;
        if (pc > max_address) max_address = pc;
    }
    pc++;  /* Always advance PC in both passes */
}

void emit_opcode(uint8_t opcode) {
    if (!is_conditional_active()) return;  /* Skip if in false conditional block */
    stats_record_opcode(opcode);
    if (pass == 2) {
        /* Track opcode address range */
        if (pc < min_opcode_address) min_opcode_address = pc;
        if (pc > max_opcode_address) max_opcode_address = pc;
    }
    emit_byte(opcode);
}

void emit_word(uint16_t word) {
    emit_byte(word & 0xFF);
    emit_byte((word >> 8) & 0xFF);
}

void emit_indexed(uint8_t zp_op, uint8_t abs_op, char *expr) {
    uint16_t addr = eval_expr(expr);
    if (addr < 256) {
        /* Zero page indexed */
        emit_opcode(zp_op);
        emit_byte(addr & 0xFF);
    } else {
        /* Absolute indexed */
        emit_opcode(abs_op);
        emit_word(addr);
    }
}

void emit_addr(uint8_t zp_op, uint8_t abs_op, char *expr) {
    uint16_t addr = eval_expr(expr);
    if (addr < 256) {
        /* Zero page */
        emit_opcode(zp_op);
        emit_byte(addr & 0xFF);
    } else {
        /* Absolute */
        emit_opcode(abs_op);
        emit_word(addr);
    }
}

void check_zero_transfer(const char *instr, uint8_t opcode, char *expr) {
    /* Check if this is a load to register (immediate) */
    if (opcode == 0xA9 || opcode == 0xA2 || opcode == 0xA0) {
        /* LDA #0, LDX #0, LDY #0 */
        stats_record_zero_to_register(instr);
    } else if (opcode == 0x85 || opcode == 0x86 || opcode == 0x84 ||
               opcode == 0x8D || opcode == 0x8E || opcode == 0x8C) {
        /* STA, STX, STY to address 0 */
        uint16_t addr = eval_expr(expr);
        stats_record_zero_to_memory(instr, addr);
    }
    /* Note: We could also track other operations with zero, but the main
       transfers are loads to registers and stores to memory */
}

/* Macro management functions */
void start_macro_definition(char *name) {
    in_macro_definition = 1;
    current_macro_name = strdup(name);
    current_macro_body = malloc(4096);
    current_macro_body_size = 4096;
    current_macro_body_len = 0;
    current_macro_body[0] = '\0';
}

void append_to_macro_body(const char *text) {
    if (!in_macro_definition || !current_macro_body) return;
    
    int text_len = strlen(text);
    while (current_macro_body_len + text_len + 2 >= current_macro_body_size) {
        current_macro_body_size *= 2;
        current_macro_body = realloc(current_macro_body, current_macro_body_size);
    }
    if (current_macro_body_len > 0) {
        strcat(current_macro_body, "\n");
        current_macro_body_len++;
    }
    strcat(current_macro_body, text);
    current_macro_body_len += text_len;
}

void end_macro_definition(void) {
    if (!in_macro_definition) return;
    
    if (macro_count >= MAX_MACROS) {
        fprintf(stderr, "Error: Too many macros\n");
        free(current_macro_name);
        free(current_macro_body);
        in_macro_definition = 0;
        return;
    }
    
    /* Check if macro already exists */
    for (int i = 0; i < macro_count; i++) {
        if (strcmp(macros[i].name, current_macro_name) == 0) {
            free(macros[i].body);
            macros[i].body = current_macro_body;
            macros[i].body_len = current_macro_body_len;
            free(current_macro_name);
            in_macro_definition = 0;
            return;
        }
    }
    
    macros[macro_count].name = current_macro_name;
    macros[macro_count].body = current_macro_body;
    macros[macro_count].body_len = current_macro_body_len;
    macro_count++;
    in_macro_definition = 0;
}

macro_t *get_macro(char *name) {
    for (int i = 0; i < macro_count; i++) {
        if (strcmp(macros[i].name, name) == 0) {
            return &macros[i];
        }
    }
    return NULL;
}

void add_macro(char *name, char *body) {
    if (macro_count >= MAX_MACROS) {
        fprintf(stderr, "Error: Too many macros\n");
        return;
    }
    
    macros[macro_count].name = strdup(name);
    macros[macro_count].body = strdup(body);
    macros[macro_count].body_len = strlen(body);
    macro_count++;
}


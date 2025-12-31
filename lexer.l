%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

extern int in_macro_definition;
%}

%option noyywrap
%option case-insensitive

%x COMMENT

%%

[ \t]+                { /* ignore whitespace */ }
\n                    { return NEWLINE; }

";"                   { BEGIN(COMMENT); }
<COMMENT>[^\n]*       { /* eat comment text */ }
<COMMENT>\n           {
                          BEGIN(INITIAL);
                          return NEWLINE;
                      }

"ADC"   { return ADC; }
"AND"   { return AND; }
"ASL"   { return ASL; }
"BCC"   { return BCC; }
"BCS"   { return BCS; }
"BEQ"   { return BEQ; }
"BIT"   { return BIT; }
"BMI"   { return BMI; }
"BNE"   { return BNE; }
"BPL"   { return BPL; }
"BRK"   { return BRK; }
"BVC"   { return BVC; }
"BVS"   { return BVS; }
"CLC"   { return CLC; }
"CLD"   { return CLD; }
"CLI"   { return CLI; }
"CLV"   { return CLV; }
"CMP"   { return CMP; }
"CPX"   { return CPX; }
"CPY"   { return CPY; }
"DEC"   { return DEC; }
"DEX"   { return DEX; }
"DEY"   { return DEY; }
"EOR"   { return EOR; }
"INC"   { return INC; }
"INX"   { return INX; }
"INY"   { return INY; }
"JMP"   { return JMP; }
"JSR"   { return JSR; }
"LDA"   { return LDA; }
"LDX"   { return LDX; }
"LDY"   { return LDY; }
"LSR"   { return LSR; }
"NOP"   { return NOP; }
"ORA"   { return ORA; }
"PHA"   { return PHA; }
"PHP"   { return PHP; }
"PLA"   { return PLA; }
"PLP"   { return PLP; }
"ROL"   { return ROL; }
"ROR"   { return ROR; }
"RTI"   { return RTI; }
"RTS"   { return RTS; }
"SBC"   { return SBC; }
"SEC"   { return SEC; }
"SED"   { return SED; }
"SEI"   { return SEI; }
"STA"   { return STA; }
"STX"   { return STX; }
"STY"   { return STY; }
"TAX"   { return TAX; }
"TAY"   { return TAY; }
"TSX"   { return TSX; }
"TXA"   { return TXA; }
"TXS"   { return TXS; }
"TYA"   { return TYA; }

"BRA"   { return BRA; }
"PHX"   { return PHX; }
"PHY"   { return PHY; }
"PLX"   { return PLX; }
"PLY"   { return PLY; }
"STZ"   { return STZ; }
"WAI"   { return WAI; }
"STP"   { return STP; }

"TRB"   { return TRB; }
"TSB"   { return TSB; }

"\.ORG"|"ORG"         { return ORG; }
"\.BYTE"|"BYTE"       { return BYTE; }
"\.WORD"|"WORD"       { return WORD; }
"\.RES"|"RES"         { return RES; }
"\.EQU"|"EQU"         { return EQU; }
"\.PAGE"|"PAGE"       { return PAGE; }
"\.TITLE"|"TITLE"     { return TITLE; }
"\.LIST"|"LIST"       { return LIST; }
"\.MACRO"|"MACRO"     { return MACRO; }
"\.ENDM"|"ENDM"|"\.ENDMACRO"|"ENDMACRO" { return ENDM; }

"#"     { return HASH; }
"("     { return LPAREN; }
")"     { return RPAREN; }
","     { return COMMA; }
":"     { return COLON; }
"="     { return EQUALS; }
"+"     { return PLUS; }
"-"     { return MINUS; }

"*="    { return ORG_EQUALS; }
"*"     { return MULTIPLY; }

"/"     { return DIVIDE; }

"X"     { return XREG; }
"Y"     { return YREG; }

<INITIAL>'[A-Za-z0-9]' {
    char c = yytext[1];
    char *result = malloc(16);
    snprintf(result, 16, "$%02X", (unsigned char)c);
    yylval.sval = result;
    return HEX_NUMBER;
}

<INITIAL>'[A-Za-z0-9][^A-Za-z0-9] {
    yyless(yyleng - 1);
    char c = yytext[1];
    char *result = malloc(16);
    snprintf(result, 16, "$%02X", (unsigned char)c);
    yylval.sval = result;
    return HEX_NUMBER;
}

<INITIAL>'[A-Za-z0-9] {
    char c = yytext[1];
    char *result = malloc(16);
    snprintf(result, 16, "$%02X", (unsigned char)c);
    yylval.sval = result;
    return HEX_NUMBER;
}

<INITIAL>'[^']*'                { /* skip */ }

[A-Za-z_][A-Za-z0-9_]* {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

\$[0-9A-F]+ {
    yylval.sval = strdup(yytext);
    return HEX_NUMBER;
}

[0-9]+ {
    yylval.sval = strdup(yytext);
    return DEC_NUMBER;
}

. {
    fprintf(stderr, "Unknown character: '%c'\n", yytext[0]);
}

%%

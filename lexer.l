%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
%}

%option yylineno
%option noyywrap
%option case-insensitive

%x COMMENT
%x MACROBODY

%%

 /* whitespace */
[ \t]+                { /* ignore whitespace */ }

\n                    { return NEWLINE; }

 /* comment handling */
<INITIAL,MACROBODY>";" { BEGIN(COMMENT); }
<COMMENT>[^\n]*        { /* eat comment */ }
<COMMENT>\n            { BEGIN(INITIAL); return NEWLINE; }

 /* title directive is like a comment, we need to use a mode to catch 's */
 <INITIAL,MACROBODY>"\.TITLE"|"TITLE" { BEGIN(COMMENT); }

 /* macro handling */
"\.MACRO"|"MACRO"      { BEGIN(MACROBODY); return MACRO; }

<MACROBODY>"\.ENDM"|"ENDM"|"\.ENDMACRO"|"ENDMACRO" {
                          BEGIN(INITIAL);
                          return ENDM;
                        }
 /* 6502 opcodes */
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

 /* 65C02 opcodes */
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

 /* directives - must come before identifiers */
"\.IF"|"IF"           { return IF; }
"\.END"|"END"         { return END; }
"\.ENDIF"|"ENDIF"     { return ENDIF; }
"\.ORG"|"ORG"         { return ORG; }
"\.BYTE"|"BYTE"       { return BYTE; }
"\.WORD"|"WORD"       { return WORD; }
"\.RES"|"RES"         { return RES; }
"\.EQU"|"EQU"         { return EQU; }
"\.PAGE"|"PAGE"       { return PAGE; }
"\.LIST"|"LIST"       { return LIST; }
"\.LOW\."|"LOW\."     { return LOW; }
"\.HIGH\."|"HIGH\."   { return HIGH; }
"\.AND\."|"AND\."     { return AND_OP; }
"\.OR\."|"OR\."       { return OR_OP; }

 /* operators / punctuation */
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

 /* string literals */
'.*' {
    char c = yytext[1];
    char *result = malloc(255);
    snprintf(result, 16, "$%02X", (unsigned char)c);
    yylval.sval = result;
    return HEX_NUMBER;
}

 /* single character literals, which return a byte code */
'. {
    char c = yytext[1];
    char *result = malloc(16);
    snprintf(result, 16, "$%02X", (unsigned char)c);
    yylval.sval = result;
    return HEX_NUMBER;
}

 /* identifiers and numbers */
[A-Za-z_][A-Za-z0-9_?]* {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

 /* numbers in hex and decimal (is the octal?) */
\$[0-9A-F]+ {
    yylval.sval = strdup(yytext);
    return HEX_NUMBER;
}

[0-9]+ {
    yylval.sval = strdup(yytext);
    return DEC_NUMBER;
}

 /* catch-all */
. {
    fprintf(stderr, "Unknown character: '%c' at line %d\n", yytext[0], yylineno);
}

%%

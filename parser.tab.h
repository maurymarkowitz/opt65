/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     HEX_NUMBER = 259,
     DEC_NUMBER = 260,
     ADC = 261,
     AND = 262,
     ASL = 263,
     BCC = 264,
     BCS = 265,
     BEQ = 266,
     BIT = 267,
     BMI = 268,
     BNE = 269,
     BPL = 270,
     BRK = 271,
     BVC = 272,
     BVS = 273,
     CLC = 274,
     CLD = 275,
     CLI = 276,
     CLV = 277,
     CMP = 278,
     CPX = 279,
     CPY = 280,
     DEC = 281,
     DEX = 282,
     DEY = 283,
     EOR = 284,
     INC = 285,
     INX = 286,
     INY = 287,
     JMP = 288,
     JSR = 289,
     LDA = 290,
     LDX = 291,
     LDY = 292,
     LSR = 293,
     NOP = 294,
     ORA = 295,
     PHA = 296,
     PHP = 297,
     PLA = 298,
     PLP = 299,
     ROL = 300,
     ROR = 301,
     RTI = 302,
     RTS = 303,
     SBC = 304,
     SEC = 305,
     SED = 306,
     SEI = 307,
     STA = 308,
     STX = 309,
     STY = 310,
     TAX = 311,
     TAY = 312,
     TSX = 313,
     TXA = 314,
     TXS = 315,
     TYA = 316,
     BRA = 317,
     PHX = 318,
     PHY = 319,
     PLX = 320,
     PLY = 321,
     STZ = 322,
     TRB = 323,
     TSB = 324,
     WAI = 325,
     STP = 326,
     ORG = 327,
     BYTE = 328,
     WORD = 329,
     RES = 330,
     EQU = 331,
     MACRO = 332,
     ENDM = 333,
     PAGE = 334,
     TITLE = 335,
     LIST = 336,
     IF = 337,
     ENDIF = 338,
     END = 339,
     LOW = 340,
     HIGH = 341,
     AND_OP = 342,
     OR_OP = 343,
     MACRO_BODY = 344,
     HASH = 345,
     LPAREN = 346,
     RPAREN = 347,
     COMMA = 348,
     COLON = 349,
     EQUALS = 350,
     XREG = 351,
     YREG = 352,
     NEWLINE = 353,
     PLUS = 354,
     MINUS = 355,
     MULTIPLY = 356,
     DIVIDE = 357,
     ORG_EQUALS = 358,
     UMINUS = 359
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define HEX_NUMBER 259
#define DEC_NUMBER 260
#define ADC 261
#define AND 262
#define ASL 263
#define BCC 264
#define BCS 265
#define BEQ 266
#define BIT 267
#define BMI 268
#define BNE 269
#define BPL 270
#define BRK 271
#define BVC 272
#define BVS 273
#define CLC 274
#define CLD 275
#define CLI 276
#define CLV 277
#define CMP 278
#define CPX 279
#define CPY 280
#define DEC 281
#define DEX 282
#define DEY 283
#define EOR 284
#define INC 285
#define INX 286
#define INY 287
#define JMP 288
#define JSR 289
#define LDA 290
#define LDX 291
#define LDY 292
#define LSR 293
#define NOP 294
#define ORA 295
#define PHA 296
#define PHP 297
#define PLA 298
#define PLP 299
#define ROL 300
#define ROR 301
#define RTI 302
#define RTS 303
#define SBC 304
#define SEC 305
#define SED 306
#define SEI 307
#define STA 308
#define STX 309
#define STY 310
#define TAX 311
#define TAY 312
#define TSX 313
#define TXA 314
#define TXS 315
#define TYA 316
#define BRA 317
#define PHX 318
#define PHY 319
#define PLX 320
#define PLY 321
#define STZ 322
#define TRB 323
#define TSB 324
#define WAI 325
#define STP 326
#define ORG 327
#define BYTE 328
#define WORD 329
#define RES 330
#define EQU 331
#define MACRO 332
#define ENDM 333
#define PAGE 334
#define TITLE 335
#define LIST 336
#define IF 337
#define ENDIF 338
#define END 339
#define LOW 340
#define HIGH 341
#define AND_OP 342
#define OR_OP 343
#define MACRO_BODY 344
#define HASH 345
#define LPAREN 346
#define RPAREN 347
#define COMMA 348
#define COLON 349
#define EQUALS 350
#define XREG 351
#define YREG 352
#define NEWLINE 353
#define PLUS 354
#define MINUS 355
#define MULTIPLY 356
#define DIVIDE 357
#define ORG_EQUALS 358
#define UMINUS 359




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 85 "parser.y"
{
    int ival;
    char *sval;
}
/* Line 1529 of yacc.c.  */
#line 262 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


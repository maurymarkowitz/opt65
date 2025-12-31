/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     MACRO_BODY = 337,
     HASH = 338,
     LPAREN = 339,
     RPAREN = 340,
     COMMA = 341,
     COLON = 342,
     EQUALS = 343,
     XREG = 344,
     YREG = 345,
     NEWLINE = 346,
     PLUS = 347,
     MINUS = 348,
     MULTIPLY = 349,
     DIVIDE = 350,
     ORG_EQUALS = 351
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
#define MACRO_BODY 337
#define HASH 338
#define LPAREN 339
#define RPAREN 340
#define COMMA 341
#define COLON 342
#define EQUALS 343
#define XREG 344
#define YREG 345
#define NEWLINE 346
#define PLUS 347
#define MINUS 348
#define MULTIPLY 349
#define DIVIDE 350
#define ORG_EQUALS 351




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

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

#define MAX_SYMBOLS 1024
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

/* Output buffer */
uint8_t output[65536];
uint16_t pc = 0;
uint16_t org_address = 0;

/* Forward declarations */
uint16_t eval_expr(char *expr);
void add_symbol(char *name, uint16_t value);
uint16_t get_symbol(char *name);
void emit_byte(uint8_t byte);
void emit_word(uint16_t word);
void emit_indexed(uint8_t zp_op, uint8_t abs_op, char *expr, int is_x);
void emit_addr(uint8_t zp_op, uint8_t abs_op, char *expr);
void emit_opcode(uint8_t opcode);
void check_zero_transfer(const char *instr, uint8_t opcode, char *expr);
void add_macro(char *name, char *body);
macro_t *get_macro(char *name);
void start_macro_definition(char *name);
void append_to_macro_body(const char *text);
void end_macro_definition(void);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 70 "parser.y"
{
    int ival;
    char *sval;
}
/* Line 193 of yacc.c.  */
#line 362 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 375 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   634

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNRULES -- Number of states.  */
#define YYNSTATES  337

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    22,
      26,    29,    33,    36,    40,    42,    46,    48,    50,    53,
      57,    61,    65,    68,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    94,    96,    98,   100,
     102,   104,   106,   108,   110,   112,   114,   116,   118,   120,
     122,   124,   126,   128,   130,   132,   134,   136,   138,   140,
     142,   146,   150,   154,   158,   162,   166,   170,   174,   178,
     182,   186,   189,   192,   195,   198,   201,   204,   207,   210,
     213,   216,   219,   222,   225,   228,   231,   234,   237,   240,
     243,   246,   249,   252,   255,   260,   265,   270,   275,   280,
     285,   290,   295,   300,   305,   310,   315,   320,   325,   330,
     335,   340,   345,   350,   355,   360,   365,   370,   375,   380,
     385,   390,   397,   404,   411,   418,   425,   432,   439,   446,
     453,   460,   467,   474,   481,   488,   495,   502,   505,   508,
     511,   514,   517,   520,   523,   526,   529,   531,   533,   535,
     537,   539,   541,   544,   549,   552,   555,   558,   561,   564,
     567,   570,   573,   575,   577,   579,   583,   586,   588,   590,
     592,   594,   596,   600,   604,   608,   612,   616,   618,   620,
     622,   624,   628,   632,   636,   640
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      98,     0,    -1,    -1,    98,    99,    -1,    91,    -1,   100,
      91,    -1,   103,    91,    -1,   112,    91,    -1,   100,   103,
      91,    -1,   100,   112,    91,    -1,   101,    91,    -1,   100,
     101,    91,    -1,   102,    91,    -1,   100,   102,    91,    -1,
      80,    -1,    81,     3,    91,    -1,   113,    -1,   114,    -1,
       3,    87,    -1,     3,    76,   116,    -1,     3,    88,   116,
      -1,     3,    88,    94,    -1,    96,   116,    -1,   104,    -1,
     105,    -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,
     110,    -1,   111,    -1,    16,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    27,    -1,    28,    -1,    31,    -1,
      32,    -1,    39,    -1,    41,    -1,    42,    -1,    43,    -1,
      44,    -1,    47,    -1,    48,    -1,    50,    -1,    51,    -1,
      52,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,     8,    -1,    38,    -1,    45,    -1,
      46,    -1,     6,    83,   115,    -1,     7,    83,   115,    -1,
      23,    83,   115,    -1,    24,    83,   115,    -1,    25,    83,
     115,    -1,    29,    83,   115,    -1,    35,    83,   115,    -1,
      36,    83,   115,    -1,    37,    83,   115,    -1,    40,    83,
     115,    -1,    49,    83,   115,    -1,     6,   115,    -1,     7,
     115,    -1,     8,   115,    -1,    12,   115,    -1,    23,   115,
      -1,    24,   115,    -1,    25,   115,    -1,    26,   115,    -1,
      29,   115,    -1,    30,   115,    -1,    33,   115,    -1,    34,
     115,    -1,    35,   115,    -1,    36,   115,    -1,    37,   115,
      -1,    38,   115,    -1,    40,   115,    -1,    45,   115,    -1,
      46,   115,    -1,    49,   115,    -1,    53,   115,    -1,    54,
     115,    -1,    55,   115,    -1,     6,   115,    86,    89,    -1,
       6,   115,    86,    90,    -1,     7,   115,    86,    89,    -1,
       7,   115,    86,    90,    -1,     8,   115,    86,    89,    -1,
      23,   115,    86,    89,    -1,    23,   115,    86,    90,    -1,
      26,   115,    86,    89,    -1,    29,   115,    86,    89,    -1,
      29,   115,    86,    90,    -1,    30,   115,    86,    89,    -1,
      35,   115,    86,    89,    -1,    35,   115,    86,    90,    -1,
      36,   115,    86,    90,    -1,    37,   115,    86,    89,    -1,
      38,   115,    86,    89,    -1,    40,   115,    86,    89,    -1,
      40,   115,    86,    90,    -1,    45,   115,    86,    89,    -1,
      46,   115,    86,    89,    -1,    49,   115,    86,    89,    -1,
      49,   115,    86,    90,    -1,    53,   115,    86,    89,    -1,
      53,   115,    86,    90,    -1,    54,   115,    86,    90,    -1,
      55,   115,    86,    89,    -1,    33,    84,   115,    85,    -1,
       6,    84,   115,    86,    89,    85,    -1,     7,    84,   115,
      86,    89,    85,    -1,    23,    84,   115,    86,    89,    85,
      -1,    29,    84,   115,    86,    89,    85,    -1,    35,    84,
     115,    86,    89,    85,    -1,    40,    84,   115,    86,    89,
      85,    -1,    49,    84,   115,    86,    89,    85,    -1,    53,
      84,   115,    86,    89,    85,    -1,     6,    84,   115,    85,
      86,    90,    -1,     7,    84,   115,    85,    86,    90,    -1,
      23,    84,   115,    85,    86,    90,    -1,    29,    84,   115,
      85,    86,    90,    -1,    35,    84,   115,    85,    86,    90,
      -1,    40,    84,   115,    85,    86,    90,    -1,    49,    84,
     115,    85,    86,    90,    -1,    53,    84,   115,    85,    86,
      90,    -1,     9,   115,    -1,    10,   115,    -1,    11,   115,
      -1,    13,   115,    -1,    14,   115,    -1,    15,   115,    -1,
      17,   115,    -1,    18,   115,    -1,    62,   115,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    70,    -1,    71,
      -1,    67,   115,    -1,    67,   115,    86,    89,    -1,    68,
     115,    -1,    69,   115,    -1,    72,   115,    -1,    96,   115,
      -1,    73,   115,    -1,    74,   115,    -1,    75,   115,    -1,
      76,   115,    -1,    79,    -1,    80,    -1,    81,    -1,    77,
       3,    91,    -1,    78,    91,    -1,     3,    -1,     3,    -1,
       4,    -1,     5,    -1,    94,    -1,   115,    92,   115,    -1,
     115,    93,   115,    -1,   115,    94,   115,    -1,   115,    95,
     115,    -1,    84,   115,    85,    -1,     3,    -1,     4,    -1,
       5,    -1,    94,    -1,   116,    92,   116,    -1,   116,    93,
     116,    -1,   116,    94,   116,    -1,   116,    95,   116,    -1,
      84,   116,    85,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    92,    92,    93,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   114,   121,
     122,   123,   127,   131,   132,   133,   134,   135,   136,   137,
     138,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   157,   158,   163,   164,   165,   166,   167,   168,
     169,   174,   179,   180,   181,   182,   186,   187,   188,   189,
     193,   201,   209,   215,   221,   227,   233,   241,   247,   253,
     261,   272,   277,   285,   286,   287,   292,   297,   302,   303,
     308,   309,   316,   321,   329,   334,   339,   340,   348,   349,
     350,   355,   363,   368,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   394,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   416,   422,   430,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   461,   470,   479,
     488,   497,   506,   515,   524,   536,   545,   546,   547,   548,
     549,   550,   551,   561,   571,   581,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   606,   634,   638,   657,   658,
     659,   660,   666,   673,   680,   687,   698,   702,   703,   704,
     705,   706,   707,   708,   709,   717
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "HEX_NUMBER", "DEC_NUMBER",
  "ADC", "AND", "ASL", "BCC", "BCS", "BEQ", "BIT", "BMI", "BNE", "BPL",
  "BRK", "BVC", "BVS", "CLC", "CLD", "CLI", "CLV", "CMP", "CPX", "CPY",
  "DEC", "DEX", "DEY", "EOR", "INC", "INX", "INY", "JMP", "JSR", "LDA",
  "LDX", "LDY", "LSR", "NOP", "ORA", "PHA", "PHP", "PLA", "PLP", "ROL",
  "ROR", "RTI", "RTS", "SBC", "SEC", "SED", "SEI", "STA", "STX", "STY",
  "TAX", "TAY", "TSX", "TXA", "TXS", "TYA", "BRA", "PHX", "PHY", "PLX",
  "PLY", "STZ", "TRB", "TSB", "WAI", "STP", "ORG", "BYTE", "WORD", "RES",
  "EQU", "MACRO", "ENDM", "PAGE", "TITLE", "LIST", "MACRO_BODY", "HASH",
  "LPAREN", "RPAREN", "COMMA", "COLON", "EQUALS", "XREG", "YREG",
  "NEWLINE", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "ORG_EQUALS",
  "$accept", "program", "line", "label", "assignment", "org_equals",
  "instruction", "implied_instruction", "accumulator_instruction",
  "immediate_instruction", "address_instruction", "indexed_instruction",
  "indirect_instruction", "relative_instruction", "c02_instruction",
  "directive", "macro_start", "macro_invocation", "expression",
  "expr_value", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   101,
     101,   101,   102,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   110,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   116,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     3,     3,
       2,     3,     2,     3,     1,     3,     1,     1,     2,     3,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     2,     4,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,   167,     0,     0,    56,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,    32,    33,    34,
      35,     0,     0,     0,     0,    36,    37,     0,     0,    38,
      39,     0,     0,     0,     0,     0,    57,    40,     0,    41,
      42,    43,    44,    58,    59,    45,    46,     0,    47,    48,
      49,     0,     0,     0,    50,    51,    52,    53,    54,    55,
       0,   146,   147,   148,   149,     0,     0,     0,   150,   151,
       0,     0,     0,     0,     0,     0,     0,   162,    14,   164,
       4,     0,     3,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,     0,    16,    17,     0,    18,
       0,   168,   169,   170,     0,     0,   171,    71,     0,     0,
      72,     0,    73,   137,   138,   139,    74,   140,   141,   142,
     143,   144,     0,     0,    75,     0,    76,     0,    77,    78,
       0,     0,    79,    80,     0,    81,    82,     0,     0,    83,
       0,    84,     0,    85,    86,     0,     0,    87,    88,    89,
       0,     0,    90,     0,    91,    92,    93,   145,   152,   154,
     155,   156,   158,   159,   160,   161,     0,   166,     0,   168,
     169,   170,     0,   171,   157,    22,     0,   163,   164,     5,
       0,     0,     0,     0,    10,    12,     6,     7,   177,   178,
     179,     0,   180,    19,   180,    20,    60,     0,     0,     0,
       0,     0,     0,    61,     0,     0,     0,     0,    62,     0,
       0,    63,    64,     0,    65,     0,     0,     0,     0,    66,
       0,     0,    67,     0,    68,     0,     0,    69,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
     165,    15,     0,     0,     0,     0,     0,    11,    13,     8,
       9,   176,     0,    94,    95,   172,   173,   174,   175,   176,
       0,    96,    97,   176,    98,   176,     0,    99,   100,   101,
     176,     0,   102,   103,   104,   176,   176,     0,   105,   106,
     107,   108,   109,   176,     0,   110,   111,   112,   113,   176,
       0,   114,   115,   176,     0,   116,   117,   118,   119,   153,
     185,   181,   182,   183,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   121,   130,   122,   131,   123,   132,   124,   133,
     125,   134,   126,   135,   127,   136,   128
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   206,   242
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -76
static const yytype_int16 yypact[] =
{
     -76,   199,   -76,   -66,    41,    68,   369,   369,   369,   369,
     369,   369,   369,   369,   -76,   369,   369,   -76,   -76,   -76,
     -76,    71,    75,    80,   369,   -76,   -76,    83,   369,   -76,
     -76,   372,   369,    88,    92,   106,   369,   -76,   109,   -76,
     -76,   -76,   -76,   369,   369,   -76,   -76,   284,   -76,   -76,
     -76,   380,   369,   369,   -76,   -76,   -76,   -76,   -76,   -76,
     369,   -76,   -76,   -76,   -76,   369,   369,   369,   -76,   -76,
     369,   369,   369,   369,   369,    23,     3,   -76,   -76,    35,
     -76,   384,   -76,   290,    15,    16,    17,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,    24,   -76,   -76,   387,   -76,
     391,   -76,   -76,   -76,   369,   369,   -76,   413,   369,   369,
     423,   369,   427,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   369,   369,   437,   369,   -40,   369,   -40,   441,
     369,   369,   451,   455,   369,   -40,   -40,   369,   369,   465,
     369,   469,   369,   479,   483,   369,   369,   493,   497,   507,
     369,   369,   511,   369,   521,   525,   535,   -40,   539,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,    25,   -76,    26,   -76,
     -76,   -76,   384,   -76,   -40,   189,   -63,   -76,   -76,   -76,
      29,    31,    37,    38,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   387,   -76,   189,    40,   189,   -40,   -35,   -75,   369,
     369,   369,   369,   -40,   312,   -53,   394,    43,   -40,   316,
     -48,   -40,   -40,    48,   -40,   327,   -25,    50,   398,   -40,
     331,    -8,   -40,    53,   -40,    51,    55,   -40,   342,     0,
      56,    59,   -40,   346,     9,   357,    13,    60,    64,    67,
     -76,   -76,   409,   387,   387,   387,   387,   -76,   -76,   -76,
     -76,    74,    72,   -76,   -76,   -40,   -40,   -40,   -40,    82,
      81,   -76,   -76,   -76,   -76,    87,    94,   -76,   -76,   -76,
      98,    96,   -76,   -76,   -76,    66,   101,    99,   -76,   -76,
     -76,   -76,   -76,   105,   112,   -76,   -76,   -76,   -76,   108,
     115,   -76,   -76,   200,   196,   -76,   -76,   -76,   -76,   -76,
     -76,   189,   189,   189,   189,   201,   207,   204,   294,   292,
     295,   303,   314,   310,   318,   324,   330,   328,   344,   340,
     348,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   -76,   361,   362,   363,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   364,   -76,   -76,    -4,   -65
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -121
static const yytype_int16 yytable[] =
{
     107,   110,   112,   113,   114,   115,   116,   117,   118,   119,
      98,   120,   121,    98,   253,   254,   175,   124,   126,   128,
     129,    99,   100,   132,   133,   100,   166,   135,   136,   139,
     141,   143,   144,   193,   147,   195,   261,   262,   168,   148,
     149,   267,   268,   152,   101,   102,   103,   154,   155,   156,
     251,   252,   199,   200,   201,   202,   157,   199,   200,   201,
     202,   158,   159,   160,   272,   273,   161,   162,   163,   164,
     165,   101,   102,   103,   101,   102,   103,   174,   101,   102,
     103,   278,   279,   101,   102,   103,   101,   102,   103,   285,
     286,   101,   102,   103,   167,   101,   102,   103,   291,   292,
     196,   197,   295,   296,   203,   204,   184,   185,   186,   101,
     102,   103,   101,   102,   103,   187,   240,   241,   208,   209,
     247,   211,   248,   212,   104,   105,   214,   215,   249,   250,
     218,   -21,   264,   219,   220,   106,   222,   269,   224,   274,
     281,   227,   228,   280,   282,   287,   232,   233,   288,   235,
     297,   108,   109,   298,   122,   123,   299,  -120,   125,   111,
     305,   306,   106,   127,   111,   106,   130,   131,   307,   106,
     308,   137,   138,   309,   106,   140,   111,   106,   301,   302,
     303,   304,   106,   310,   311,   312,   106,   313,   314,   142,
     111,   315,   145,   146,   317,   255,   256,   257,   258,     2,
     106,   316,     3,   106,   318,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,   243,   244,   245,   246,   320,   319,   101,   102,   103,
      80,   321,   322,   176,   323,    81,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   150,   151,    77,
     177,   178,   101,   102,   103,   101,   102,   103,   106,   324,
     326,   179,   325,   101,   102,   103,    81,   169,   170,   171,
     188,   189,   190,   327,   188,   189,   190,   259,   260,   328,
     329,   265,   266,   330,   199,   200,   201,   202,   199,   200,
     201,   202,   270,   271,   331,   332,   276,   277,   333,   199,
     200,   201,   202,   199,   200,   201,   202,   283,   284,   334,
     335,   289,   290,   336,   199,   200,   201,   202,   199,   200,
     201,   202,   293,   294,   180,   181,   182,   183,     0,   199,
     200,   201,   202,   111,     0,     0,   134,     0,     0,     0,
       0,     0,     0,   106,   153,     0,   106,     0,   172,     0,
       0,   191,     0,     0,   106,   191,     0,     0,   173,   263,
       0,   192,     0,   275,     0,   194,   199,   200,   201,   202,
     199,   200,   201,   202,   300,     0,     0,     0,     0,   198,
       0,   243,   244,   245,   246,   199,   200,   201,   202,   205,
       0,     0,     0,   207,     0,   199,   200,   201,   202,   199,
     200,   201,   202,   210,     0,     0,     0,   213,     0,   199,
     200,   201,   202,   199,   200,   201,   202,   216,     0,     0,
       0,   217,     0,   199,   200,   201,   202,   199,   200,   201,
     202,   221,     0,     0,     0,   223,     0,   199,   200,   201,
     202,   199,   200,   201,   202,   225,     0,     0,     0,   226,
       0,   199,   200,   201,   202,   199,   200,   201,   202,   229,
       0,     0,     0,   230,     0,   199,   200,   201,   202,   199,
     200,   201,   202,   231,     0,     0,     0,   234,     0,   199,
     200,   201,   202,   199,   200,   201,   202,   236,     0,     0,
       0,   237,     0,   199,   200,   201,   202,   199,   200,   201,
     202,   238,     0,     0,     0,   239,     0,   199,   200,   201,
     202,   199,   200,   201,   202
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      76,    15,    16,    76,    89,    90,    81,    21,    22,    23,
      24,    87,    88,    27,    28,    88,     3,    31,    32,    33,
      34,    35,    36,    98,    38,   100,    89,    90,     3,    43,
      44,    89,    90,    47,     3,     4,     5,    51,    52,    53,
      85,    86,    92,    93,    94,    95,    60,    92,    93,    94,
      95,    65,    66,    67,    89,    90,    70,    71,    72,    73,
      74,     3,     4,     5,     3,     4,     5,    81,     3,     4,
       5,    89,    90,     3,     4,     5,     3,     4,     5,    89,
      90,     3,     4,     5,    91,     3,     4,     5,    89,    90,
     104,   105,    89,    90,   108,   109,    91,    91,    91,     3,
       4,     5,     3,     4,     5,    91,    91,    91,   122,   123,
      91,   125,    91,   127,    83,    84,   130,   131,    91,    91,
     134,    91,    89,   137,   138,    94,   140,    89,   142,    89,
      89,   145,   146,    90,    89,    89,   150,   151,    89,   153,
      90,    83,    84,    89,    83,    84,    89,    91,    83,    84,
      86,    89,    94,    83,    84,    94,    83,    84,    86,    94,
      89,    83,    84,    86,    94,    83,    84,    94,   243,   244,
     245,   246,    94,    89,    86,    89,    94,    86,    89,    83,
      84,    86,    83,    84,    86,   199,   200,   201,   202,     0,
      94,    89,     3,    94,    89,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    92,    93,    94,    95,    89,    86,     3,     4,     5,
      91,    90,    85,     3,    90,    96,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    83,    84,    79,
      80,    81,     3,     4,     5,     3,     4,     5,    94,    85,
      85,    91,    90,     3,     4,     5,    96,     3,     4,     5,
       3,     4,     5,    90,     3,     4,     5,    85,    86,    85,
      90,    85,    86,    85,    92,    93,    94,    95,    92,    93,
      94,    95,    85,    86,    90,    85,    85,    86,    90,    92,
      93,    94,    95,    92,    93,    94,    95,    85,    86,    85,
      90,    85,    86,    85,    92,    93,    94,    95,    92,    93,
      94,    95,    85,    86,    83,    83,    83,    83,    -1,    92,
      93,    94,    95,    84,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    84,    -1,    94,    -1,    84,    -1,
      -1,    84,    -1,    -1,    94,    84,    -1,    -1,    94,    85,
      -1,    94,    -1,    85,    -1,    94,    92,    93,    94,    95,
      92,    93,    94,    95,    85,    -1,    -1,    -1,    -1,    86,
      -1,    92,    93,    94,    95,    92,    93,    94,    95,    86,
      -1,    -1,    -1,    86,    -1,    92,    93,    94,    95,    92,
      93,    94,    95,    86,    -1,    -1,    -1,    86,    -1,    92,
      93,    94,    95,    92,    93,    94,    95,    86,    -1,    -1,
      -1,    86,    -1,    92,    93,    94,    95,    92,    93,    94,
      95,    86,    -1,    -1,    -1,    86,    -1,    92,    93,    94,
      95,    92,    93,    94,    95,    86,    -1,    -1,    -1,    86,
      -1,    92,    93,    94,    95,    92,    93,    94,    95,    86,
      -1,    -1,    -1,    86,    -1,    92,    93,    94,    95,    92,
      93,    94,    95,    86,    -1,    -1,    -1,    86,    -1,    92,
      93,    94,    95,    92,    93,    94,    95,    86,    -1,    -1,
      -1,    86,    -1,    92,    93,    94,    95,    92,    93,    94,
      95,    86,    -1,    -1,    -1,    86,    -1,    92,    93,    94,
      95,    92,    93,    94,    95
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    98,     0,     3,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      91,    96,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    76,    87,
      88,     3,     4,     5,    83,    84,    94,   115,    83,    84,
     115,    84,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,    83,    84,   115,    83,   115,    83,   115,   115,
      83,    84,   115,   115,    84,   115,   115,    83,    84,   115,
      83,   115,    83,   115,   115,    83,    84,   115,   115,   115,
      83,    84,   115,    84,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,     3,    91,     3,     3,
       4,     5,    84,    94,   115,   116,     3,    80,    81,    91,
     101,   102,   103,   112,    91,    91,    91,    91,     3,     4,
       5,    84,    94,   116,    94,   116,   115,   115,    86,    92,
      93,    94,    95,   115,   115,    86,   115,    86,   115,   115,
      86,   115,   115,    86,   115,   115,    86,    86,   115,   115,
     115,    86,   115,    86,   115,    86,    86,   115,   115,    86,
      86,    86,   115,   115,    86,   115,    86,    86,    86,    86,
      91,    91,   116,    92,    93,    94,    95,    91,    91,    91,
      91,    85,    86,    89,    90,   115,   115,   115,   115,    85,
      86,    89,    90,    85,    89,    85,    86,    89,    90,    89,
      85,    86,    89,    90,    89,    85,    85,    86,    89,    90,
      90,    89,    89,    85,    86,    89,    90,    89,    89,    85,
      86,    89,    90,    85,    86,    89,    90,    90,    89,    89,
      85,   116,   116,   116,   116,    86,    89,    86,    89,    86,
      89,    86,    89,    86,    89,    86,    89,    86,    89,    86,
      89,    90,    85,    90,    85,    90,    85,    90,    85,    90,
      85,    90,    85,    90,    85,    90,    85
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 14:
#line 107 "parser.y"
    { /* Title directive - no-op, rest of line will be consumed by lexer */ ;}
    break;

  case 15:
#line 108 "parser.y"
    { /* List directive - no-op */ ;}
    break;

  case 18:
#line 115 "parser.y"
    {
        add_symbol((yyvsp[(1) - (2)].sval), pc);
    ;}
    break;

  case 19:
#line 121 "parser.y"
    { add_symbol((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].ival)); ;}
    break;

  case 20:
#line 122 "parser.y"
    { add_symbol((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].ival)); ;}
    break;

  case 21:
#line 123 "parser.y"
    { add_symbol((yyvsp[(1) - (3)].sval), pc); ;}
    break;

  case 22:
#line 127 "parser.y"
    { org_address = (yyvsp[(2) - (2)].ival); pc = org_address; ;}
    break;

  case 31:
#line 142 "parser.y"
    { emit_opcode(0x00); ;}
    break;

  case 32:
#line 143 "parser.y"
    { emit_opcode(0x18); ;}
    break;

  case 33:
#line 144 "parser.y"
    { emit_opcode(0xD8); ;}
    break;

  case 34:
#line 145 "parser.y"
    { emit_opcode(0x58); ;}
    break;

  case 35:
#line 146 "parser.y"
    { emit_opcode(0xB8); ;}
    break;

  case 36:
#line 147 "parser.y"
    { emit_opcode(0xCA); ;}
    break;

  case 37:
#line 148 "parser.y"
    { emit_opcode(0x88); ;}
    break;

  case 38:
#line 149 "parser.y"
    { emit_opcode(0xE8); ;}
    break;

  case 39:
#line 150 "parser.y"
    { emit_opcode(0xC8); ;}
    break;

  case 40:
#line 151 "parser.y"
    { emit_opcode(0xEA); ;}
    break;

  case 41:
#line 152 "parser.y"
    { 
        emit_opcode(0x48);
        extern char *yyfilename;
        stats_record_instruction(0x48, "PHA", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 42:
#line 157 "parser.y"
    { emit_opcode(0x08); ;}
    break;

  case 43:
#line 158 "parser.y"
    { 
        emit_opcode(0x68);
        extern char *yyfilename;
        stats_record_instruction(0x68, "PLA", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 44:
#line 163 "parser.y"
    { emit_opcode(0x28); ;}
    break;

  case 45:
#line 164 "parser.y"
    { emit_opcode(0x40); ;}
    break;

  case 46:
#line 165 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 47:
#line 166 "parser.y"
    { emit_opcode(0x38); ;}
    break;

  case 48:
#line 167 "parser.y"
    { emit_opcode(0xF8); ;}
    break;

  case 49:
#line 168 "parser.y"
    { emit_opcode(0x78); ;}
    break;

  case 50:
#line 169 "parser.y"
    { 
        emit_opcode(0xAA);
        extern char *yyfilename;
        stats_record_instruction(0xAA, "TAX", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 51:
#line 174 "parser.y"
    { 
        emit_opcode(0xA8);
        extern char *yyfilename;
        stats_record_instruction(0xA8, "TAY", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 52:
#line 179 "parser.y"
    { emit_opcode(0xBA); ;}
    break;

  case 53:
#line 180 "parser.y"
    { emit_opcode(0x8A); ;}
    break;

  case 54:
#line 181 "parser.y"
    { emit_opcode(0x9A); ;}
    break;

  case 55:
#line 182 "parser.y"
    { emit_opcode(0x98); ;}
    break;

  case 56:
#line 186 "parser.y"
    { emit_opcode(0x0A); ;}
    break;

  case 57:
#line 187 "parser.y"
    { emit_opcode(0x4A); ;}
    break;

  case 58:
#line 188 "parser.y"
    { emit_opcode(0x2A); ;}
    break;

  case 59:
#line 189 "parser.y"
    { emit_opcode(0x6A); ;}
    break;

  case 60:
#line 193 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x69); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("ADC #0", 0x69, (yyvsp[(3) - (3)].sval));
        extern char *yyfilename;
        stats_record_instruction(0x69, "ADC", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 61:
#line 201 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x29); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("AND #0", 0x29, (yyvsp[(3) - (3)].sval));
        extern char *yyfilename;
        stats_record_instruction(0x29, "AND", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 62:
#line 209 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xC9); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("CMP #0", 0xC9, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 63:
#line 215 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xE0); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("CPX #0", 0xE0, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 64:
#line 221 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xC0); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("CPY #0", 0xC0, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 65:
#line 227 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x49); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("EOR #0", 0x49, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 66:
#line 233 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xA9); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("LDA #0", 0xA9, (yyvsp[(3) - (3)].sval));
        extern char *yyfilename;
        stats_record_instruction(0xA9, "LDA", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 67:
#line 241 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xA2); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("LDX #0", 0xA2, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 68:
#line 247 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xA0); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("LDY #0", 0xA0, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 69:
#line 253 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x09); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("ORA #0", 0x09, (yyvsp[(3) - (3)].sval));
        extern char *yyfilename;
        stats_record_instruction(0x09, "ORA", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 70:
#line 261 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xE9); 
        emit_byte(val);
        if (val == 0) check_zero_transfer("SBC #0", 0xE9, (yyvsp[(3) - (3)].sval));
        extern char *yyfilename;
        stats_record_instruction(0xE9, "SBC", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 71:
#line 272 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x65, 0x6D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("ADC $00", 0x65, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 72:
#line 277 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x25, 0x2D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("AND $00", 0x25, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x25 : 0x2D;
        stats_record_instruction(op, "AND", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 73:
#line 285 "parser.y"
    { emit_addr(0x06, 0x0E, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 74:
#line 286 "parser.y"
    { emit_addr(0x24, 0x2C, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 75:
#line 287 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xC5, 0xCD, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("CMP $00", 0xC5, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 76:
#line 292 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xE4, 0xEC, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("CPX $00", 0xE4, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 77:
#line 297 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xC4, 0xCC, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("CPY $00", 0xC4, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 78:
#line 302 "parser.y"
    { emit_addr(0xC6, 0xCE, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 79:
#line 303 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x45, 0x4D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("EOR $00", 0x45, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 80:
#line 308 "parser.y"
    { emit_addr(0xE6, 0xEE, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 81:
#line 309 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_opcode(0x4C);
        emit_word(addr);
        extern char *yyfilename;
        stats_record_instruction(0x4C, "JMP", addr, yylineno, yyfilename, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 82:
#line 316 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_opcode(0x20);
        emit_word(addr);
    ;}
    break;

  case 83:
#line 321 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xA5, 0xAD, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("LDA $00", 0xA5, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0xA5 : 0xAD;
        stats_record_instruction(op, "LDA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 84:
#line 329 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xA6, 0xAE, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("LDX $00", 0xA6, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 85:
#line 334 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xA4, 0xAC, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("LDY $00", 0xA4, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 86:
#line 339 "parser.y"
    { emit_addr(0x46, 0x4E, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 87:
#line 340 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x05, 0x0D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("ORA $00", 0x05, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x05 : 0x0D;
        stats_record_instruction(op, "ORA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 88:
#line 348 "parser.y"
    { emit_addr(0x26, 0x2E, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 89:
#line 349 "parser.y"
    { emit_addr(0x66, 0x6E, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 90:
#line 350 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xE5, 0xED, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("SBC $00", 0xE5, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 91:
#line 355 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x85, 0x8D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("STA $00", 0x85, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x85 : 0x8D;
        stats_record_instruction(op, "STA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 92:
#line 363 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x86, 0x8E, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("STX $00", 0x86, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 93:
#line 368 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x84, 0x8C, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("STY $00", 0x84, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 94:
#line 376 "parser.y"
    { emit_indexed(0x75, 0x7D, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 95:
#line 377 "parser.y"
    { emit_indexed(0x79, 0x79, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 96:
#line 378 "parser.y"
    { emit_indexed(0x35, 0x3D, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 97:
#line 379 "parser.y"
    { emit_indexed(0x39, 0x39, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 98:
#line 380 "parser.y"
    { emit_indexed(0x16, 0x1E, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 99:
#line 381 "parser.y"
    { emit_indexed(0xD5, 0xDD, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 100:
#line 382 "parser.y"
    { emit_indexed(0xD9, 0xD9, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 101:
#line 383 "parser.y"
    { emit_indexed(0xD6, 0xDE, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 102:
#line 384 "parser.y"
    { emit_indexed(0x55, 0x5D, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 103:
#line 385 "parser.y"
    { emit_indexed(0x59, 0x59, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 104:
#line 386 "parser.y"
    { emit_indexed(0xF6, 0xFE, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 105:
#line 387 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0xB5, 0xBD, (yyvsp[(2) - (4)].sval), 1);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0xB5 : 0xBD;
        stats_record_instruction(op, "LDA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 106:
#line 394 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0xB9, 0xB9, (yyvsp[(2) - (4)].sval), 0);
        extern char *yyfilename;
        stats_record_instruction(0xB9, "LDA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 107:
#line 400 "parser.y"
    { emit_indexed(0xB6, 0xBE, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 108:
#line 401 "parser.y"
    { emit_indexed(0xB4, 0xBC, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 109:
#line 402 "parser.y"
    { emit_indexed(0x56, 0x5E, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 110:
#line 403 "parser.y"
    { emit_indexed(0x15, 0x1D, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 111:
#line 404 "parser.y"
    { emit_indexed(0x19, 0x19, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 112:
#line 405 "parser.y"
    { emit_indexed(0x36, 0x3E, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 113:
#line 406 "parser.y"
    { emit_indexed(0x76, 0x7E, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 114:
#line 407 "parser.y"
    { emit_indexed(0xF5, 0xFD, (yyvsp[(2) - (4)].sval), 1); ;}
    break;

  case 115:
#line 408 "parser.y"
    { emit_indexed(0xF9, 0xF9, (yyvsp[(2) - (4)].sval), 0); ;}
    break;

  case 116:
#line 409 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0x95, 0x9D, (yyvsp[(2) - (4)].sval), 1);
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x95 : 0x9D;
        stats_record_instruction(op, "STA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 117:
#line 416 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0x99, 0x99, (yyvsp[(2) - (4)].sval), 0);
        extern char *yyfilename;
        stats_record_instruction(0x99, "STA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 118:
#line 422 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        if (addr >= 256) {
            fprintf(stderr, "Error: STX,Y only supports zero page addressing\n");
        }
        emit_opcode(0x96);
        emit_byte(addr & 0xFF);
    ;}
    break;

  case 119:
#line 430 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        if (addr >= 256) {
            fprintf(stderr, "Error: STY,X only supports zero page addressing\n");
        }
        emit_opcode(0x94);
        emit_byte(addr & 0xFF);
    ;}
    break;

  case 120:
#line 441 "parser.y"
    { emit_opcode(0x6C); emit_word(eval_expr((yyvsp[(3) - (4)].sval))); ;}
    break;

  case 121:
#line 442 "parser.y"
    { emit_opcode(0x61); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 122:
#line 443 "parser.y"
    { emit_opcode(0x21); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 123:
#line 444 "parser.y"
    { emit_opcode(0xC1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 124:
#line 445 "parser.y"
    { emit_opcode(0x41); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 125:
#line 446 "parser.y"
    { emit_opcode(0xA1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 126:
#line 447 "parser.y"
    { emit_opcode(0x01); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 127:
#line 448 "parser.y"
    { emit_opcode(0xE1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 128:
#line 449 "parser.y"
    { emit_opcode(0x81); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 129:
#line 450 "parser.y"
    { emit_opcode(0x71); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 130:
#line 451 "parser.y"
    { emit_opcode(0x31); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 131:
#line 452 "parser.y"
    { emit_opcode(0xD1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 132:
#line 453 "parser.y"
    { emit_opcode(0x51); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 133:
#line 454 "parser.y"
    { emit_opcode(0xB1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 134:
#line 455 "parser.y"
    { emit_opcode(0x11); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 135:
#line 456 "parser.y"
    { emit_opcode(0xF1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 136:
#line 457 "parser.y"
    { emit_opcode(0x91); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 137:
#line 461 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0x90); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 138:
#line 470 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0xB0); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 139:
#line 479 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0xF0); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 140:
#line 488 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0x30); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 141:
#line 497 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0xD0); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 142:
#line 506 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0x10); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 143:
#line 515 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0x50); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 144:
#line 524 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0x70); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 145:
#line 536 "parser.y"
    { 
        uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t offset = (int16_t)(target - (pc + 1));
        if (offset < -128 || offset > 127) {
            fprintf(stderr, "Error: Branch offset out of range\n");
        }
        emit_opcode(0x80); 
        emit_byte(offset & 0xFF); 
    ;}
    break;

  case 146:
#line 545 "parser.y"
    { emit_opcode(0xDA); ;}
    break;

  case 147:
#line 546 "parser.y"
    { emit_opcode(0x5A); ;}
    break;

  case 148:
#line 547 "parser.y"
    { emit_opcode(0xFA); ;}
    break;

  case 149:
#line 548 "parser.y"
    { emit_opcode(0x7A); ;}
    break;

  case 150:
#line 549 "parser.y"
    { emit_opcode(0xCB); ;}
    break;

  case 151:
#line 550 "parser.y"
    { emit_opcode(0xDB); ;}
    break;

  case 152:
#line 551 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        if (addr < 256) {
            emit_opcode(0x64);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x9C);
            emit_word(addr);
        }
    ;}
    break;

  case 153:
#line 561 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        if (addr < 256) {
            emit_opcode(0x74);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x9E);
            emit_word(addr);
        }
    ;}
    break;

  case 154:
#line 571 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        if (addr < 256) {
            emit_opcode(0x14);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x1C);
            emit_word(addr);
        }
    ;}
    break;

  case 155:
#line 581 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        if (addr < 256) {
            emit_opcode(0x04);
            emit_byte(addr & 0xFF);
        } else {
            emit_opcode(0x0C);
            emit_word(addr);
        }
    ;}
    break;

  case 156:
#line 594 "parser.y"
    { org_address = eval_expr((yyvsp[(2) - (2)].sval)); pc = org_address; ;}
    break;

  case 157:
#line 595 "parser.y"
    { org_address = eval_expr((yyvsp[(2) - (2)].sval)); pc = org_address; ;}
    break;

  case 158:
#line 596 "parser.y"
    { emit_byte(eval_expr((yyvsp[(2) - (2)].sval)) & 0xFF); ;}
    break;

  case 159:
#line 597 "parser.y"
    { emit_word(eval_expr((yyvsp[(2) - (2)].sval))); ;}
    break;

  case 160:
#line 598 "parser.y"
    { pc += eval_expr((yyvsp[(2) - (2)].sval)); ;}
    break;

  case 161:
#line 599 "parser.y"
    { /* .EQU handled in assignment rule */ ;}
    break;

  case 162:
#line 600 "parser.y"
    { /* Page break - no-op */ ;}
    break;

  case 163:
#line 601 "parser.y"
    { /* Title directive - no-op, ignore the string (handled as any expression) */ ;}
    break;

  case 164:
#line 602 "parser.y"
    { /* List directive - no-op, ignore the parameter */ ;}
    break;

  case 165:
#line 606 "parser.y"
    { 
        start_macro_definition((yyvsp[(2) - (3)].sval));
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
    ;}
    break;

  case 166:
#line 634 "parser.y"
    { /* This handles ENDM when not in a macro definition (error case) */ ;}
    break;

  case 167:
#line 638 "parser.y"
    { 
        macro_t *m = get_macro((yyvsp[(1) - (1)].sval));
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
            fprintf(stderr, "Error: Unknown identifier '%s' (not a macro or label)\n", (yyvsp[(1) - (1)].sval));
        }
    ;}
    break;

  case 168:
#line 657 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 169:
#line 658 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 170:
#line 659 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 171:
#line 660 "parser.y"
    { 
        /* Current location counter - convert to string */
        char *result = malloc(16);
        snprintf(result, 16, "%d", pc);
        (yyval.sval) = result;
    ;}
    break;

  case 172:
#line 666 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        char *result = malloc(16);
        snprintf(result, 16, "%d", left + right);
        (yyval.sval) = result;
    ;}
    break;

  case 173:
#line 673 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        char *result = malloc(16);
        snprintf(result, 16, "%d", left - right);
        (yyval.sval) = result;
    ;}
    break;

  case 174:
#line 680 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        char *result = malloc(16);
        snprintf(result, 16, "%d", left * right);
        (yyval.sval) = result;
    ;}
    break;

  case 175:
#line 687 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        if (right == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            right = 1;
        }
        char *result = malloc(16);
        snprintf(result, 16, "%d", left / right);
        (yyval.sval) = result;
    ;}
    break;

  case 176:
#line 698 "parser.y"
    { (yyval.sval) = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 177:
#line 702 "parser.y"
    { (yyval.ival) = eval_expr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 178:
#line 703 "parser.y"
    { (yyval.ival) = eval_expr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 179:
#line 704 "parser.y"
    { (yyval.ival) = eval_expr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 180:
#line 705 "parser.y"
    { (yyval.ival) = pc; ;}
    break;

  case 181:
#line 706 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 182:
#line 707 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 183:
#line 708 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 184:
#line 709 "parser.y"
    { 
        if ((yyvsp[(3) - (3)].ival) == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            (yyval.ival) = (yyvsp[(1) - (3)].ival);
        } else {
            (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival);
        }
    ;}
    break;

  case 185:
#line 717 "parser.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3148 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 720 "parser.y"


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
    
    fprintf(stderr, "Warning: Undefined symbol '%s', assuming 0\n", name);
    return 0;
}

void emit_byte(uint8_t byte) {
    if (pc >= 65536) {
        fprintf(stderr, "Error: Program counter overflow\n");
        return;
    }
    output[pc] = byte;
    pc++;
}

void emit_opcode(uint8_t opcode) {
    stats_record_opcode(opcode);
    emit_byte(opcode);
}

void emit_word(uint16_t word) {
    emit_byte(word & 0xFF);
    emit_byte((word >> 8) & 0xFF);
}

void emit_indexed(uint8_t zp_op, uint8_t abs_op, char *expr, int is_x) {
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



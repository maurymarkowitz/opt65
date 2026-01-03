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
#line 83 "parser.y"
{
    int ival;
    char *sval;
}
/* Line 193 of yacc.c.  */
#line 391 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 404 "parser.tab.c"

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
#define YYLAST   1021

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNRULES -- Number of states.  */
#define YYNSTATES  455

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

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
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    15,    18,    22,
      26,    29,    33,    36,    40,    42,    46,    48,    50,    52,
      54,    56,    59,    63,    66,    69,    73,    77,    81,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   102,   104,
     106,   108,   110,   112,   114,   116,   118,   120,   122,   124,
     126,   128,   130,   133,   135,   138,   141,   144,   147,   150,
     153,   156,   159,   162,   165,   168,   171,   174,   177,   180,
     183,   186,   189,   192,   195,   198,   201,   204,   207,   210,
     213,   216,   219,   222,   225,   228,   231,   234,   237,   240,
     243,   246,   249,   252,   255,   258,   261,   264,   267,   270,
     273,   276,   279,   282,   285,   288,   291,   294,   297,   300,
     303,   306,   309,   312,   315,   318,   321,   324,   327,   330,
     333,   336,   338,   340,   342,   344,   346,   348,   350,   352,
     354,   356,   358,   360,   362,   366,   370,   374,   378,   382,
     386,   390,   394,   398,   402,   406,   409,   412,   415,   418,
     421,   424,   427,   430,   433,   436,   439,   442,   445,   448,
     451,   454,   457,   460,   463,   466,   469,   472,   475,   480,
     485,   490,   495,   500,   505,   510,   515,   520,   525,   530,
     535,   540,   545,   550,   555,   560,   565,   570,   575,   580,
     585,   590,   595,   600,   605,   610,   617,   624,   631,   638,
     645,   652,   659,   666,   673,   680,   687,   694,   701,   708,
     715,   722,   725,   728,   731,   734,   737,   740,   743,   746,
     749,   751,   753,   755,   757,   759,   761,   764,   769,   772,
     775,   778,   781,   784,   787,   790,   793,   795,   797,   799,
     802,   805,   808,   811,   813,   815,   819,   821,   825,   829,
     832,   834,   836,   838,   840,   842,   845,   848,   851,   854,
     858,   862,   866,   870,   874,   878,   882,   884,   886,   888,
     890,   893,   896,   899,   902,   906,   910,   914,   918,   922,
     926
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,    -1,   106,   107,    -1,    98,    -1,   110,
      98,    -1,   113,    98,    -1,   122,    98,    -1,   110,   113,
      98,    -1,   110,   122,    98,    -1,   111,    98,    -1,   110,
     111,    98,    -1,   112,    98,    -1,   110,   112,    98,    -1,
      80,    -1,    81,     3,    98,    -1,   125,    -1,   126,    -1,
     108,    -1,   109,    -1,    84,    -1,    84,    98,    -1,    82,
     128,    98,    -1,    83,    98,    -1,     3,    94,    -1,     3,
      76,   128,    -1,     3,    95,   128,    -1,     3,    95,   101,
      -1,   103,   128,    -1,   114,    -1,   115,    -1,   116,    -1,
     117,    -1,   118,    -1,   119,    -1,   120,    -1,   121,    -1,
      16,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      27,    -1,    28,    -1,    31,    -1,    32,    -1,    39,    -1,
      41,    -1,    42,    -1,    43,    -1,    44,    -1,    47,    -1,
      47,     3,    -1,    48,    -1,    48,     3,    -1,    48,     6,
      -1,    48,     7,    -1,    48,     8,    -1,    48,     9,    -1,
      48,    10,    -1,    48,    11,    -1,    48,    12,    -1,    48,
      13,    -1,    48,    14,    -1,    48,    15,    -1,    48,    16,
      -1,    48,    17,    -1,    48,    18,    -1,    48,    19,    -1,
      48,    20,    -1,    48,    21,    -1,    48,    22,    -1,    48,
      23,    -1,    48,    24,    -1,    48,    25,    -1,    48,    26,
      -1,    48,    27,    -1,    48,    28,    -1,    48,    29,    -1,
      48,    30,    -1,    48,    31,    -1,    48,    32,    -1,    48,
      33,    -1,    48,    34,    -1,    48,    35,    -1,    48,    36,
      -1,    48,    37,    -1,    48,    38,    -1,    48,    39,    -1,
      48,    40,    -1,    48,    41,    -1,    48,    42,    -1,    48,
      43,    -1,    48,    44,    -1,    48,    45,    -1,    48,    46,
      -1,    48,    47,    -1,    48,    48,    -1,    48,    49,    -1,
      48,    50,    -1,    48,    51,    -1,    48,    52,    -1,    48,
      53,    -1,    48,    54,    -1,    48,    55,    -1,    48,    56,
      -1,    48,    57,    -1,    48,    58,    -1,    48,    59,    -1,
      48,    60,    -1,    48,    61,    -1,    48,    62,    -1,    48,
      63,    -1,    48,    64,    -1,    48,    65,    -1,    48,    66,
      -1,    48,    67,    -1,    48,    68,    -1,    48,    69,    -1,
      48,    70,    -1,    48,    71,    -1,    50,    -1,    51,    -1,
      52,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,     8,    -1,    38,    -1,    45,    -1,
      46,    -1,     6,    90,   127,    -1,     7,    90,   127,    -1,
      23,    90,   127,    -1,    24,    90,   127,    -1,    25,    90,
     127,    -1,    29,    90,   127,    -1,    35,    90,   127,    -1,
      36,    90,   127,    -1,    37,    90,   127,    -1,    40,    90,
     127,    -1,    49,    90,   127,    -1,     6,   127,    -1,     7,
     127,    -1,     8,   127,    -1,    12,   127,    -1,    23,   127,
      -1,    24,   127,    -1,    25,   127,    -1,    26,   127,    -1,
      29,   127,    -1,    30,   127,    -1,    33,   127,    -1,    34,
     127,    -1,    35,   127,    -1,    36,   127,    -1,    37,   127,
      -1,    38,   127,    -1,    40,   127,    -1,    45,   127,    -1,
      46,   127,    -1,    49,   127,    -1,    53,   127,    -1,    54,
     127,    -1,    55,   127,    -1,     6,   127,    93,    96,    -1,
       6,   127,    93,    97,    -1,     7,   127,    93,    96,    -1,
       7,   127,    93,    97,    -1,     8,   127,    93,    96,    -1,
      23,   127,    93,    96,    -1,    23,   127,    93,    97,    -1,
      26,   127,    93,    96,    -1,    29,   127,    93,    96,    -1,
      29,   127,    93,    97,    -1,    30,   127,    93,    96,    -1,
      35,   127,    93,    96,    -1,    35,   127,    93,    97,    -1,
      36,   127,    93,    97,    -1,    37,   127,    93,    96,    -1,
      38,   127,    93,    96,    -1,    40,   127,    93,    96,    -1,
      40,   127,    93,    97,    -1,    45,   127,    93,    96,    -1,
      46,   127,    93,    96,    -1,    49,   127,    93,    96,    -1,
      49,   127,    93,    97,    -1,    53,   127,    93,    96,    -1,
      53,   127,    93,    97,    -1,    54,   127,    93,    97,    -1,
      55,   127,    93,    96,    -1,    33,    91,   127,    92,    -1,
       6,    91,   127,    93,    96,    92,    -1,     7,    91,   127,
      93,    96,    92,    -1,    23,    91,   127,    93,    96,    92,
      -1,    29,    91,   127,    93,    96,    92,    -1,    35,    91,
     127,    93,    96,    92,    -1,    40,    91,   127,    93,    96,
      92,    -1,    49,    91,   127,    93,    96,    92,    -1,    53,
      91,   127,    93,    96,    92,    -1,     6,    91,   127,    92,
      93,    97,    -1,     7,    91,   127,    92,    93,    97,    -1,
      23,    91,   127,    92,    93,    97,    -1,    29,    91,   127,
      92,    93,    97,    -1,    35,    91,   127,    92,    93,    97,
      -1,    40,    91,   127,    92,    93,    97,    -1,    49,    91,
     127,    92,    93,    97,    -1,    53,    91,   127,    92,    93,
      97,    -1,     9,   127,    -1,    10,   127,    -1,    11,   127,
      -1,    13,   127,    -1,    14,   127,    -1,    15,   127,    -1,
      17,   127,    -1,    18,   127,    -1,    62,   127,    -1,    63,
      -1,    64,    -1,    65,    -1,    66,    -1,    70,    -1,    71,
      -1,    67,   127,    -1,    67,   127,    93,    96,    -1,    68,
     127,    -1,    69,   127,    -1,    72,   127,    -1,   103,   127,
      -1,    73,   123,    -1,    74,   124,    -1,    75,   127,    -1,
      76,   127,    -1,    79,    -1,    80,    -1,    81,    -1,    81,
       3,    -1,    81,    96,    -1,    81,    97,    -1,    81,   127,
      -1,    84,    -1,   127,    -1,   123,    93,   127,    -1,   127,
      -1,   124,    93,   127,    -1,    77,     3,    98,    -1,    78,
      98,    -1,     3,    -1,     3,    -1,     4,    -1,     5,    -1,
     101,    -1,    85,     3,    -1,    86,     3,    -1,   100,   127,
      -1,    99,   127,    -1,   127,    99,   127,    -1,   127,   100,
     127,    -1,   127,   101,   127,    -1,   127,   102,   127,    -1,
     127,    87,   127,    -1,   127,    88,   127,    -1,    91,   127,
      92,    -1,     3,    -1,     4,    -1,     5,    -1,   101,    -1,
      85,     3,    -1,    86,     3,    -1,   100,   128,    -1,    99,
     128,    -1,   128,    99,   128,    -1,   128,   100,   128,    -1,
     128,   101,   128,    -1,   128,   102,   128,    -1,   128,    87,
     128,    -1,   128,    88,   128,    -1,    91,   128,    92,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   110,   110,   111,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   137,   146,   157,   167,   176,   181,   186,   194,   206,
     207,   208,   209,   210,   211,   212,   213,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   232,   233,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   317,   322,   323,   324,   325,
     329,   330,   331,   332,   336,   347,   358,   367,   376,   385,
     394,   405,   414,   423,   434,   448,   453,   461,   469,   470,
     475,   480,   485,   486,   491,   492,   504,   514,   522,   527,
     532,   540,   548,   556,   564,   569,   580,   585,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     611,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   633,   639,   647,   658,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   686,   701,   715,   729,   743,   757,   771,   785,   802,
     816,   817,   818,   819,   820,   821,   822,   832,   842,   852,
     865,   866,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   885,   894,   899,   907,   912,   920,   948,
     952,   971,   972,   973,   974,   980,   988,   996,  1006,  1007,
    1014,  1021,  1028,  1039,  1052,  1065,  1069,  1070,  1071,  1072,
    1073,  1078,  1083,  1084,  1085,  1086,  1087,  1088,  1096,  1099,
    1102
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
  "EQU", "MACRO", "ENDM", "PAGE", "TITLE", "LIST", "IF", "ENDIF", "END",
  "LOW", "HIGH", "AND_OP", "OR_OP", "MACRO_BODY", "HASH", "LPAREN",
  "RPAREN", "COMMA", "COLON", "EQUALS", "XREG", "YREG", "NEWLINE", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "ORG_EQUALS", "UMINUS", "$accept",
  "program", "line", "if_block", "endif_directive", "label", "assignment",
  "org_equals", "instruction", "implied_instruction",
  "accumulator_instruction", "immediate_instruction",
  "address_instruction", "indexed_instruction", "indirect_instruction",
  "relative_instruction", "c02_instruction", "directive", "byte_list",
  "word_list", "macro_start", "macro_invocation", "expression",
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
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   109,   110,   111,   111,   111,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     2,     2,     3,     3,
       2,     3,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     2,     3,     2,     2,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     4,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     3,     1,     3,     3,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       2,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,   250,     0,     0,   130,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    38,    39,    40,
      41,     0,     0,     0,     0,    42,    43,     0,     0,    44,
      45,     0,     0,     0,     0,     0,   131,    46,     0,    47,
      48,    49,    50,   132,   133,    51,    53,     0,   121,   122,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
       0,   220,   221,   222,   223,     0,     0,     0,   224,   225,
       0,     0,     0,     0,     0,     0,     0,   236,    14,   238,
       0,     0,    20,     4,     0,     3,    18,    19,     0,     0,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,    16,    17,     0,    24,     0,   251,   252,   253,     0,
       0,     0,     0,     0,     0,   254,   145,     0,     0,   146,
       0,   147,   211,   212,   213,   148,   214,   215,   216,   217,
     218,     0,     0,   149,     0,   150,     0,   151,   152,     0,
       0,   153,   154,     0,   155,   156,     0,     0,   157,     0,
     158,     0,   159,   160,     0,     0,   161,   162,   163,    52,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,   164,
       0,   165,   166,   167,   219,   226,   228,   229,   230,   232,
     244,   233,   246,   234,   235,     0,   249,   251,   240,   241,
     242,   266,   267,   268,     0,     0,     0,     0,     0,   269,
       0,    23,    21,   251,   252,   253,     0,     0,     0,     0,
       0,   254,   231,    28,     0,   237,   238,   243,     5,     0,
       0,     0,     0,    10,    12,     6,     7,    25,   269,    26,
     255,   256,   134,     0,   258,   257,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,     0,   136,     0,
       0,   137,   138,     0,   139,     0,     0,     0,     0,   140,
       0,     0,   141,     0,   142,     0,     0,   143,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   248,    15,   270,   271,     0,   273,   272,     0,
       0,    22,     0,     0,     0,     0,   255,   256,   251,    11,
      13,     8,     9,   265,     0,   263,   264,   168,   169,   259,
     260,   261,   262,   265,     0,   170,   171,   265,   172,   265,
       0,   173,   174,   175,   265,     0,   176,   177,   178,   265,
     265,     0,   179,   180,   181,   182,   183,   265,     0,   184,
     185,   186,   187,   265,     0,   188,   189,   265,     0,   190,
     191,   192,   193,   227,   245,   247,   280,   278,   279,   274,
     275,   276,   277,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   203,
     195,   204,   196,   205,   197,   206,   198,   207,   199,   208,
     200,   209,   201,   210,   202
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   239,   241,
     101,   102,   250,   346
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int16 yypact[] =
{
     -82,   332,   -82,   -50,   116,   119,   190,   190,   190,   190,
     190,   190,   190,   190,   -82,   190,   190,   -82,   -82,   -82,
     -82,   152,   169,   187,   190,   -82,   -82,   224,   190,   -82,
     -82,   535,   190,   227,   422,   512,   190,   -82,   515,   -82,
     -82,   -82,   -82,   190,   190,    10,   662,   532,   -82,   -82,
     -82,   539,   190,   190,   -82,   -82,   -82,   -82,   -82,   -82,
     190,   -82,   -82,   -82,   -82,   190,   190,   190,   -82,   -82,
     190,   190,   190,   190,   190,    18,   -73,   -82,   -82,    68,
     556,   -60,   -56,   -82,   559,   -82,   -82,   -82,   430,   -52,
     -24,   -15,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
       2,   -82,   -82,   556,   -82,   563,   -82,   -82,   -82,   112,
     122,   190,   190,   190,   190,   -82,     4,   190,   190,   492,
     190,   721,    61,    61,    61,    61,    61,    61,    61,    61,
      61,   190,   190,   731,   190,    61,   190,    61,   741,   190,
     190,   751,   761,   190,    61,    61,   190,   190,   771,   190,
     781,   190,   791,   801,   190,   190,   811,   821,   831,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   190,   190,   841,
     190,   851,   861,   871,    61,   881,    61,    61,    61,    33,
      61,    36,    61,    61,    61,    35,   -82,    39,   -82,   -82,
      61,   -82,   -82,   -82,   128,   131,   556,   556,   556,   -82,
     -23,   -82,   -82,   -82,   -82,   -82,   135,   137,   559,   559,
     559,   -82,    61,   220,   -54,   -82,    85,   -82,   -82,    43,
      46,    48,    54,   -82,   -82,   -82,   -82,   220,    60,   220,
     -82,   -82,    61,    -6,   -51,   -51,   190,   190,   -81,   190,
     190,   190,   190,    61,   147,   -44,   897,    70,    61,   482,
     -42,    61,    61,    79,    61,   647,   -39,    81,   903,    61,
     663,   -37,    61,    82,    61,    84,    87,    61,   679,     5,
      93,   100,    61,   695,    15,   711,    21,   101,   107,   115,
     190,   190,   -82,   -82,   -82,   -82,   919,    -3,   -82,   556,
     556,   -82,   556,   556,   556,   556,   -82,   -82,    80,   -82,
     -82,   -82,   -82,   104,   117,   -82,   -82,   -82,   -82,   -51,
     -51,   -82,   -82,   121,   125,   -82,   -82,   -82,   -82,   129,
     140,   -82,   -82,   -82,   132,   145,   -82,   -82,   -82,   110,
     151,   149,   -82,   -82,   -82,   -82,   -82,   157,   160,   -82,
     -82,   -82,   -82,   164,   162,   -82,   -82,   168,   166,   -82,
     -82,   -82,   -82,   -82,    61,    61,   -82,   -82,   -82,    -3,
      -3,   -82,   -82,   136,   120,   170,   171,   174,   182,   197,
     207,   203,   209,   205,   211,   208,   212,   214,   237,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -82,   -82,   -82,   -82,   -82,   -82,   218,   228,   242,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   243,   -82,   -82,
     -82,   -82,    -4,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -240
static const yytype_int16 yytable[] =
{
     116,   119,   121,   122,   123,   124,   125,   126,   127,   128,
     260,   129,   130,   159,   273,   367,   368,   133,   135,   137,
     138,   245,   103,   141,   142,   246,   103,   144,   145,   148,
     150,   152,   153,   287,   156,   289,   296,   297,   261,   157,
     158,   105,   262,   229,   104,   105,   283,   231,   232,   233,
     301,   302,   375,   376,   381,   382,   234,   386,   387,   392,
     393,   235,   236,   237,   349,   350,   238,   240,   242,   243,
     244,   247,   107,   108,   284,   351,   352,   353,   354,   355,
     272,   296,   297,   285,   349,   350,   363,   364,   358,   107,
     108,   296,   297,   299,   300,   301,   302,   298,   354,   355,
     286,   399,   400,   299,   300,   301,   302,   292,   293,   294,
     295,   405,   406,   303,   304,   290,   306,   409,   410,   106,
     107,   108,   106,   107,   108,   291,   340,   308,   309,   341,
     311,   344,   312,   342,   345,   314,   315,   343,   356,   318,
     357,   359,   319,   320,   360,   322,   361,   324,   296,   297,
     327,   328,   362,   109,   110,   106,   107,   108,   -27,   120,
     299,   300,   301,   302,   248,   249,   378,   113,   114,   115,
     109,   110,   106,   107,   108,   383,   120,   388,  -239,   394,
     395,   248,   249,   396,   113,   114,   115,   347,   348,   401,
     106,   107,   108,   106,   107,   108,   402,   423,   411,   347,
     348,   109,   110,   412,   109,   110,   111,   112,  -194,   117,
     118,   413,   440,   424,   425,   113,   114,   115,   113,   114,
     115,   426,   427,   332,   333,   429,   335,   106,   107,   108,
     106,   107,   108,   439,   296,   297,   428,   109,   110,   373,
     374,   430,   131,   132,   431,   432,   299,   300,   301,   302,
     433,   113,   114,   115,   109,   110,   434,   435,   436,   134,
     120,   437,   438,   442,   306,   294,   295,   441,   113,   114,
     115,   443,   109,   110,   444,   109,   110,   136,   120,   417,
     418,   120,   419,   420,   421,   422,   113,   114,   115,   113,
     114,   115,   365,   366,   445,   369,   370,   371,   372,   446,
     447,   448,   449,   450,   452,   451,   279,   349,   350,   109,
     110,   453,   109,   110,   139,   140,   280,   146,   147,   352,
     353,   354,   355,   113,   114,   115,   113,   114,   115,   454,
     281,   282,     2,     0,     0,     3,   414,   415,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,   108,     0,     0,
      83,     0,     0,   274,     0,    84,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   109,   110,    77,
     275,   276,   149,   120,   277,   106,   107,   108,   106,   107,
     108,   113,   114,   115,     0,     0,     0,     0,   278,     0,
       0,     0,     0,    84,     0,   106,   107,   108,   106,   107,
     108,     0,   106,   107,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   251,
     252,   253,   263,   264,   265,     0,   251,   252,   253,   296,
     297,     0,     0,     0,   379,   380,     0,     0,     0,   296,
     297,   299,   300,   301,   302,   305,     0,     0,     0,     0,
       0,   299,   300,   301,   302,     0,     0,   109,   110,     0,
     109,   110,   151,   120,     0,   154,   155,     0,     0,     0,
       0,   113,   114,   115,   113,   114,   115,   109,   110,     0,
     109,   110,   227,   228,   109,   110,   143,     0,     0,     0,
     230,   113,   114,   115,   113,   114,   115,     0,   113,   114,
     115,   254,   255,     0,   266,   267,     0,   256,   254,   255,
     268,     0,     0,     0,   256,   257,   258,   259,   269,   270,
     271,     0,   257,   258,   288,   160,     0,     0,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   296,   297,     0,     0,     0,   384,
     385,     0,     0,     0,     0,     0,   299,   300,   301,   302,
     296,   297,     0,     0,     0,   390,   391,     0,     0,     0,
       0,     0,   299,   300,   301,   302,   296,   297,     0,     0,
       0,   397,   398,     0,     0,     0,     0,     0,   299,   300,
     301,   302,   296,   297,     0,     0,     0,   403,   404,     0,
       0,     0,     0,     0,   299,   300,   301,   302,   296,   297,
       0,     0,     0,   407,   408,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   307,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   310,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   313,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   316,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   317,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   321,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   323,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   325,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   326,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   329,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   330,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   331,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   334,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   336,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   337,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   338,     0,     0,     0,   296,   297,
     299,   300,   301,   302,   339,     0,     0,     0,     0,     0,
     299,   300,   301,   302,   296,   297,     0,     0,     0,   377,
     296,   297,     0,     0,     0,   389,   299,   300,   301,   302,
       0,     0,   299,   300,   301,   302,   349,   350,     0,     0,
       0,   416,     0,     0,     0,     0,     0,     0,   352,   353,
     354,   355
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      80,    15,    16,     3,    84,    96,    97,    21,    22,    23,
      24,     3,    76,    27,    28,    98,    76,    31,    32,    33,
      34,    35,    36,   103,    38,   105,    87,    88,    98,    43,
      44,    95,    98,    47,    94,    95,    98,    51,    52,    53,
     101,   102,    96,    97,    96,    97,    60,    96,    97,    96,
      97,    65,    66,    67,    87,    88,    70,    71,    72,    73,
      74,     3,     4,     5,    98,    98,    99,   100,   101,   102,
      84,    87,    88,    98,    87,    88,    92,    93,     3,     4,
       5,    87,    88,    99,   100,   101,   102,    93,   101,   102,
      98,    96,    97,    99,   100,   101,   102,   111,   112,   113,
     114,    96,    97,   117,   118,     3,   120,    96,    97,     3,
       4,     5,     3,     4,     5,     3,    93,   131,   132,    93,
     134,     3,   136,    98,     3,   139,   140,    98,     3,   143,
       3,    98,   146,   147,    98,   149,    98,   151,    87,    88,
     154,   155,    98,    85,    86,     3,     4,     5,    98,    91,
      99,   100,   101,   102,    96,    97,    96,    99,   100,   101,
      85,    86,     3,     4,     5,    96,    91,    96,    98,    97,
      96,    96,    97,    96,    99,   100,   101,   257,   258,    96,
       3,     4,     5,     3,     4,     5,    96,    93,    97,   269,
     270,    85,    86,    96,    85,    86,    90,    91,    98,    90,
      91,    96,    92,    96,    93,    99,   100,   101,    99,   100,
     101,    96,    93,   227,   228,    93,   230,     3,     4,     5,
       3,     4,     5,    97,    87,    88,    96,    85,    86,    92,
      93,    96,    90,    91,    93,    96,    99,   100,   101,   102,
      93,    99,   100,   101,    85,    86,    96,    93,    96,    90,
      91,    93,    96,    92,   268,   269,   270,    97,    99,   100,
     101,    97,    85,    86,    92,    85,    86,    90,    91,   349,
     350,    91,   352,   353,   354,   355,    99,   100,   101,    99,
     100,   101,   296,   297,    97,   299,   300,   301,   302,    92,
      97,    92,    97,    92,    92,    97,    88,    87,    88,    85,
      86,    97,    85,    86,    90,    91,    88,    90,    91,    99,
     100,   101,   102,    99,   100,   101,    99,   100,   101,    92,
      88,    88,     0,    -1,    -1,     3,   340,   341,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      98,    -1,    -1,     3,    -1,   103,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    85,    86,    79,
      80,    81,    90,    91,    84,     3,     4,     5,     3,     4,
       5,    99,   100,   101,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,   103,    -1,     3,     4,     5,     3,     4,
       5,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     3,     4,     5,    -1,     3,     4,     5,    87,
      88,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    87,
      88,    99,   100,   101,   102,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,   102,    -1,    -1,    85,    86,    -1,
      85,    86,    90,    91,    -1,    90,    91,    -1,    -1,    -1,
      -1,    99,   100,   101,    99,   100,   101,    85,    86,    -1,
      85,    86,    90,    91,    85,    86,    91,    -1,    -1,    -1,
      91,    99,   100,   101,    99,   100,   101,    -1,    99,   100,
     101,    85,    86,    -1,    85,    86,    -1,    91,    85,    86,
      91,    -1,    -1,    -1,    91,    99,   100,   101,    99,   100,
     101,    -1,    99,   100,   101,     3,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    87,    88,    -1,    -1,    -1,    92,
      93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
      87,    88,    -1,    -1,    -1,    92,    93,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101,   102,    87,    88,    -1,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102,    87,    88,    -1,    -1,    -1,    92,    93,    -1,
      -1,    -1,    -1,    -1,    99,   100,   101,   102,    87,    88,
      -1,    -1,    -1,    92,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    87,    88,
      99,   100,   101,   102,    93,    -1,    -1,    -1,    -1,    -1,
      99,   100,   101,   102,    87,    88,    -1,    -1,    -1,    92,
      87,    88,    -1,    -1,    -1,    92,    99,   100,   101,   102,
      -1,    -1,    99,   100,   101,   102,    87,    88,    -1,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,
     101,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   106,     0,     3,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    98,   103,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   125,   126,    76,    94,    95,     3,     4,     5,    85,
      86,    90,    91,    99,   100,   101,   127,    90,    91,   127,
      91,   127,   127,   127,   127,   127,   127,   127,   127,   127,
     127,    90,    91,   127,    90,   127,    90,   127,   127,    90,
      91,   127,   127,    91,   127,   127,    90,    91,   127,    90,
     127,    90,   127,   127,    90,    91,   127,   127,   127,     3,
       3,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    90,    91,   127,
      91,   127,   127,   127,   127,   127,   127,   127,   127,   123,
     127,   124,   127,   127,   127,     3,    98,     3,    96,    97,
     127,     3,     4,     5,    85,    86,    91,    99,   100,   101,
     128,    98,    98,     3,     4,     5,    85,    86,    91,    99,
     100,   101,   127,   128,     3,    80,    81,    84,    98,   111,
     112,   113,   122,    98,    98,    98,    98,   128,   101,   128,
       3,     3,   127,   127,   127,   127,    87,    88,    93,    99,
     100,   101,   102,   127,   127,    93,   127,    93,   127,   127,
      93,   127,   127,    93,   127,   127,    93,    93,   127,   127,
     127,    93,   127,    93,   127,    93,    93,   127,   127,    93,
      93,    93,   127,   127,    93,   127,    93,    93,    93,    93,
      93,    93,    98,    98,     3,     3,   128,   128,   128,    87,
      88,    98,    99,   100,   101,   102,     3,     3,     3,    98,
      98,    98,    98,    92,    93,   127,   127,    96,    97,   127,
     127,   127,   127,    92,    93,    96,    97,    92,    96,    92,
      93,    96,    97,    96,    92,    93,    96,    97,    96,    92,
      92,    93,    96,    97,    97,    96,    96,    92,    93,    96,
      97,    96,    96,    92,    93,    96,    97,    92,    93,    96,
      97,    97,    96,    96,   127,   127,    92,   128,   128,   128,
     128,   128,   128,    93,    96,    93,    96,    93,    96,    93,
      96,    93,    96,    93,    96,    93,    96,    93,    96,    97,
      92,    97,    92,    97,    92,    97,    92,    97,    92,    97,
      92,    97,    92,    97,    92
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
#line 125 "parser.y"
    { /* Title directive - no-op, rest of line will be consumed by lexer */ ;}
    break;

  case 15:
#line 126 "parser.y"
    { /* List directive - no-op */ ;}
    break;

  case 20:
#line 131 "parser.y"
    { 
        if (pass == 2) {
            YYACCEPT;  /* End of file - stop parsing in pass 2 only */
        }
        /* In pass 1, continue to build complete symbol table */
    ;}
    break;

  case 21:
#line 137 "parser.y"
    { 
        if (pass == 2) {
            YYACCEPT;  /* End of file - stop parsing in pass 2 only */
        }
        /* In pass 1, continue to build complete symbol table */
    ;}
    break;

  case 22:
#line 146 "parser.y"
    {
        int condition = (yyvsp[(2) - (3)].ival) != 0;
        if (if_stack_depth >= MAX_IF_DEPTH) {
            fprintf(stderr, "Error: IF nesting too deep at line %d\n", yylineno);
        } else {
            if_stack[if_stack_depth++] = condition ? 1 : 0;
        }
    ;}
    break;

  case 23:
#line 157 "parser.y"
    {
        if (if_stack_depth == 0) {
            fprintf(stderr, "Error: ENDIF without matching IF at line %d\n", yylineno);
        } else {
            if_stack_depth--;
        }
    ;}
    break;

  case 24:
#line 168 "parser.y"
    {
        if (is_conditional_active()) {
            add_symbol((yyvsp[(1) - (2)].sval), pc);
        }
    ;}
    break;

  case 25:
#line 176 "parser.y"
    { 
        if (is_conditional_active()) {
            add_symbol((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].ival)); 
        }
    ;}
    break;

  case 26:
#line 181 "parser.y"
    { 
        if (is_conditional_active()) {
            add_symbol((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].ival)); 
        }
    ;}
    break;

  case 27:
#line 186 "parser.y"
    { 
        if (is_conditional_active()) {
            add_symbol((yyvsp[(1) - (3)].sval), pc); 
        }
    ;}
    break;

  case 28:
#line 194 "parser.y"
    { 
        if (is_conditional_active()) {
            /* *= only sets PC, not org_address (org_address is set by first .ORG) */
            if (org_address == 0) {
                org_address = (yyvsp[(2) - (2)].ival);  /* Only set org_address if not already set */
            }
            pc = (yyvsp[(2) - (2)].ival); 
        }
    ;}
    break;

  case 37:
#line 217 "parser.y"
    { emit_opcode(0x00); ;}
    break;

  case 38:
#line 218 "parser.y"
    { emit_opcode(0x18); ;}
    break;

  case 39:
#line 219 "parser.y"
    { emit_opcode(0xD8); ;}
    break;

  case 40:
#line 220 "parser.y"
    { emit_opcode(0x58); ;}
    break;

  case 41:
#line 221 "parser.y"
    { emit_opcode(0xB8); ;}
    break;

  case 42:
#line 222 "parser.y"
    { emit_opcode(0xCA); ;}
    break;

  case 43:
#line 223 "parser.y"
    { emit_opcode(0x88); ;}
    break;

  case 44:
#line 224 "parser.y"
    { emit_opcode(0xE8); ;}
    break;

  case 45:
#line 225 "parser.y"
    { emit_opcode(0xC8); ;}
    break;

  case 46:
#line 226 "parser.y"
    { emit_opcode(0xEA); ;}
    break;

  case 47:
#line 227 "parser.y"
    { 
        emit_opcode(0x48);
        extern char *yyfilename;
        stats_record_instruction(0x48, "PHA", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 48:
#line 232 "parser.y"
    { emit_opcode(0x08); ;}
    break;

  case 49:
#line 233 "parser.y"
    { 
        emit_opcode(0x68);
        extern char *yyfilename;
        stats_record_instruction(0x68, "PLA", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 50:
#line 238 "parser.y"
    { emit_opcode(0x28); ;}
    break;

  case 51:
#line 239 "parser.y"
    { emit_opcode(0x40); ;}
    break;

  case 52:
#line 240 "parser.y"
    { emit_opcode(0x40); ;}
    break;

  case 53:
#line 241 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 54:
#line 242 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 55:
#line 243 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 56:
#line 244 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 57:
#line 245 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 58:
#line 246 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 59:
#line 247 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 60:
#line 248 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 61:
#line 249 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 62:
#line 250 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 63:
#line 251 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 64:
#line 252 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 65:
#line 253 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 66:
#line 254 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 67:
#line 255 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 68:
#line 256 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 69:
#line 257 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 70:
#line 258 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 71:
#line 259 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 72:
#line 260 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 73:
#line 261 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 74:
#line 262 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 75:
#line 263 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 76:
#line 264 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 77:
#line 265 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 78:
#line 266 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 79:
#line 267 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 80:
#line 268 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 81:
#line 269 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 82:
#line 270 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 83:
#line 271 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 84:
#line 272 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 85:
#line 273 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 86:
#line 274 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 87:
#line 275 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 88:
#line 276 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 89:
#line 277 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 90:
#line 278 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 91:
#line 279 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 92:
#line 280 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 93:
#line 281 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 94:
#line 282 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 95:
#line 283 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 96:
#line 284 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 97:
#line 285 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 98:
#line 286 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 99:
#line 287 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 100:
#line 288 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 101:
#line 289 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 102:
#line 290 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 103:
#line 291 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 104:
#line 292 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 105:
#line 293 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 106:
#line 294 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 107:
#line 295 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 108:
#line 296 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 109:
#line 297 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 110:
#line 298 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 111:
#line 299 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 112:
#line 300 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 113:
#line 301 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 114:
#line 302 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 115:
#line 303 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 116:
#line 304 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 117:
#line 305 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 118:
#line 306 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 119:
#line 307 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 120:
#line 308 "parser.y"
    { emit_opcode(0x60); ;}
    break;

  case 121:
#line 309 "parser.y"
    { emit_opcode(0x38); ;}
    break;

  case 122:
#line 310 "parser.y"
    { emit_opcode(0xF8); ;}
    break;

  case 123:
#line 311 "parser.y"
    { emit_opcode(0x78); ;}
    break;

  case 124:
#line 312 "parser.y"
    { 
        emit_opcode(0xAA);
        extern char *yyfilename;
        stats_record_instruction(0xAA, "TAX", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 125:
#line 317 "parser.y"
    { 
        emit_opcode(0xA8);
        extern char *yyfilename;
        stats_record_instruction(0xA8, "TAY", 0, yylineno, yyfilename, NULL);
    ;}
    break;

  case 126:
#line 322 "parser.y"
    { emit_opcode(0xBA); ;}
    break;

  case 127:
#line 323 "parser.y"
    { emit_opcode(0x8A); ;}
    break;

  case 128:
#line 324 "parser.y"
    { emit_opcode(0x9A); ;}
    break;

  case 129:
#line 325 "parser.y"
    { emit_opcode(0x98); ;}
    break;

  case 130:
#line 329 "parser.y"
    { emit_opcode(0x0A); ;}
    break;

  case 131:
#line 330 "parser.y"
    { emit_opcode(0x4A); ;}
    break;

  case 132:
#line 331 "parser.y"
    { emit_opcode(0x2A); ;}
    break;

  case 133:
#line 332 "parser.y"
    { emit_opcode(0x6A); ;}
    break;

  case 134:
#line 336 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x69); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("ADC #0", 0x69, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0x69);
        }
        extern char *yyfilename;
        stats_record_instruction(0x69, "ADC", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 135:
#line 347 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x29); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("AND #0", 0x29, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0x29);
        }
        extern char *yyfilename;
        stats_record_instruction(0x29, "AND", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 136:
#line 358 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xC9); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("CMP #0", 0xC9, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xC9);
        }
    ;}
    break;

  case 137:
#line 367 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xE0); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("CPX #0", 0xE0, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xE0);
        }
    ;}
    break;

  case 138:
#line 376 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xC0); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("CPY #0", 0xC0, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xC0);
        }
    ;}
    break;

  case 139:
#line 385 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x49); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("EOR #0", 0x49, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0x49);
        }
    ;}
    break;

  case 140:
#line 394 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xA9); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("LDA #0", 0xA9, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xA9);
        }
        extern char *yyfilename;
        stats_record_instruction(0xA9, "LDA", val, yylineno, yyfilename, (yyvsp[(3) - (3)].sval));
    ;}
    break;

  case 141:
#line 405 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xA2); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("LDX #0", 0xA2, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xA2);
        }
    ;}
    break;

  case 142:
#line 414 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xA0); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("LDY #0", 0xA0, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xA0);
        }
    ;}
    break;

  case 143:
#line 423 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0x09); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("ORA #0", 0x09, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0x09);
        }
        extern char *yyfilename;
        stats_record_instruction(0x09, "ORA", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 144:
#line 434 "parser.y"
    { 
        uint8_t val = eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF;
        emit_opcode(0xE9); 
        emit_byte(val);
        if (val == 0) {
            check_zero_transfer("SBC #0", 0xE9, (yyvsp[(3) - (3)].sval));
            stats_record_immediate_zero(0xE9);
        }
        extern char *yyfilename;
        stats_record_instruction(0xE9, "SBC", val, yylineno, yyfilename, NULL);
    ;}
    break;

  case 145:
#line 448 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x65, 0x6D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("ADC $00", 0x65, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 146:
#line 453 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x25, 0x2D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("AND $00", 0x25, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x25 : 0x2D;
        stats_record_instruction(op, "AND", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 147:
#line 461 "parser.y"
    { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ((yyvsp[(2) - (2)].sval) && strcasecmp((yyvsp[(2) - (2)].sval), "A") == 0) {
            emit_opcode(0x0A);  /* ASL A is same as ASL */
        } else {
            emit_addr(0x06, 0x0E, (yyvsp[(2) - (2)].sval));
        }
    ;}
    break;

  case 148:
#line 469 "parser.y"
    { emit_addr(0x24, 0x2C, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 149:
#line 470 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xC5, 0xCD, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("CMP $00", 0xC5, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 150:
#line 475 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xE4, 0xEC, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("CPX $00", 0xE4, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 151:
#line 480 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xC4, 0xCC, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("CPY $00", 0xC4, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 152:
#line 485 "parser.y"
    { emit_addr(0xC6, 0xCE, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 153:
#line 486 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x45, 0x4D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("EOR $00", 0x45, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 154:
#line 491 "parser.y"
    { emit_addr(0xE6, 0xEE, (yyvsp[(2) - (2)].sval)); ;}
    break;

  case 155:
#line 492 "parser.y"
    { 
        if (pass == 2) {
            uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
            emit_opcode(0x4C);
            emit_word(addr);
            extern char *yyfilename;
            stats_record_instruction(0x4C, "JMP", addr, yylineno, yyfilename, (yyvsp[(2) - (2)].sval));
        } else {
            emit_opcode(0x4C);
            emit_word(0);
        }
    ;}
    break;

  case 156:
#line 504 "parser.y"
    { 
        if (pass == 2) {
            uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
            emit_opcode(0x20);
            emit_word(addr);
        } else {
            emit_opcode(0x20);
            emit_word(0);
        }
    ;}
    break;

  case 157:
#line 514 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xA5, 0xAD, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("LDA $00", 0xA5, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0xA5 : 0xAD;
        stats_record_instruction(op, "LDA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 158:
#line 522 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xA6, 0xAE, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("LDX $00", 0xA6, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 159:
#line 527 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xA4, 0xAC, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("LDY $00", 0xA4, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 160:
#line 532 "parser.y"
    { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ((yyvsp[(2) - (2)].sval) && strcasecmp((yyvsp[(2) - (2)].sval), "A") == 0) {
            emit_opcode(0x4A);  /* LSR A is same as LSR */
        } else {
            emit_addr(0x46, 0x4E, (yyvsp[(2) - (2)].sval));
        }
    ;}
    break;

  case 161:
#line 540 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x05, 0x0D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("ORA $00", 0x05, (yyvsp[(2) - (2)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x05 : 0x0D;
        stats_record_instruction(op, "ORA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 162:
#line 548 "parser.y"
    { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ((yyvsp[(2) - (2)].sval) && strcasecmp((yyvsp[(2) - (2)].sval), "A") == 0) {
            emit_opcode(0x2A);  /* ROL A is same as ROL */
        } else {
            emit_addr(0x26, 0x2E, (yyvsp[(2) - (2)].sval));
        }
    ;}
    break;

  case 163:
#line 556 "parser.y"
    { 
        /* Check if expression is just "A" - if so, use accumulator form */
        if ((yyvsp[(2) - (2)].sval) && strcasecmp((yyvsp[(2) - (2)].sval), "A") == 0) {
            emit_opcode(0x6A);  /* ROR A is same as ROR */
        } else {
            emit_addr(0x66, 0x6E, (yyvsp[(2) - (2)].sval));
        }
    ;}
    break;

  case 164:
#line 564 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0xE5, 0xED, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("SBC $00", 0xE5, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 165:
#line 569 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x85, 0x8D, (yyvsp[(2) - (2)].sval));
        if (addr == 0) {
            check_zero_transfer("STA $00", 0x85, (yyvsp[(2) - (2)].sval));
            stats_record_sta_zero();
        }
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x85 : 0x8D;
        stats_record_instruction(op, "STA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 166:
#line 580 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x86, 0x8E, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("STX $00", 0x86, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 167:
#line 585 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        emit_addr(0x84, 0x8C, (yyvsp[(2) - (2)].sval));
        if (addr == 0) check_zero_transfer("STY $00", 0x84, (yyvsp[(2) - (2)].sval));
    ;}
    break;

  case 168:
#line 593 "parser.y"
    { emit_indexed(0x75, 0x7D, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 169:
#line 594 "parser.y"
    { emit_indexed(0x79, 0x79, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 170:
#line 595 "parser.y"
    { emit_indexed(0x35, 0x3D, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 171:
#line 596 "parser.y"
    { emit_indexed(0x39, 0x39, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 172:
#line 597 "parser.y"
    { emit_indexed(0x16, 0x1E, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 173:
#line 598 "parser.y"
    { emit_indexed(0xD5, 0xDD, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 174:
#line 599 "parser.y"
    { emit_indexed(0xD9, 0xD9, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 175:
#line 600 "parser.y"
    { emit_indexed(0xD6, 0xDE, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 176:
#line 601 "parser.y"
    { emit_indexed(0x55, 0x5D, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 177:
#line 602 "parser.y"
    { emit_indexed(0x59, 0x59, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 178:
#line 603 "parser.y"
    { emit_indexed(0xF6, 0xFE, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 179:
#line 604 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0xB5, 0xBD, (yyvsp[(2) - (4)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0xB5 : 0xBD;
        stats_record_instruction(op, "LDA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 180:
#line 611 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0xB9, 0xB9, (yyvsp[(2) - (4)].sval));
        extern char *yyfilename;
        stats_record_instruction(0xB9, "LDA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 181:
#line 617 "parser.y"
    { emit_indexed(0xB6, 0xBE, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 182:
#line 618 "parser.y"
    { emit_indexed(0xB4, 0xBC, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 183:
#line 619 "parser.y"
    { emit_indexed(0x56, 0x5E, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 184:
#line 620 "parser.y"
    { emit_indexed(0x15, 0x1D, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 185:
#line 621 "parser.y"
    { emit_indexed(0x19, 0x19, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 186:
#line 622 "parser.y"
    { emit_indexed(0x36, 0x3E, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 187:
#line 623 "parser.y"
    { emit_indexed(0x76, 0x7E, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 188:
#line 624 "parser.y"
    { emit_indexed(0xF5, 0xFD, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 189:
#line 625 "parser.y"
    { emit_indexed(0xF9, 0xF9, (yyvsp[(2) - (4)].sval)); ;}
    break;

  case 190:
#line 626 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0x95, 0x9D, (yyvsp[(2) - (4)].sval));
        extern char *yyfilename;
        uint8_t op = (addr < 256) ? 0x95 : 0x9D;
        stats_record_instruction(op, "STA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 191:
#line 633 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        emit_indexed(0x99, 0x99, (yyvsp[(2) - (4)].sval));
        extern char *yyfilename;
        stats_record_instruction(0x99, "STA", addr, yylineno, yyfilename, NULL);
    ;}
    break;

  case 192:
#line 639 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        if (addr >= 256) {
            fprintf(stderr, "Error: STX,Y only supports zero page addressing\n");
        }
        emit_opcode(0x96);
        emit_byte(addr & 0xFF);
    ;}
    break;

  case 193:
#line 647 "parser.y"
    { 
        uint16_t addr = eval_expr((yyvsp[(2) - (4)].sval));
        if (addr >= 256) {
            fprintf(stderr, "Error: STY,X only supports zero page addressing\n");
        }
        emit_opcode(0x94);
        emit_byte(addr & 0xFF);
    ;}
    break;

  case 194:
#line 658 "parser.y"
    { 
        if (pass == 2) {
            emit_opcode(0x6C);
            emit_word(eval_expr((yyvsp[(3) - (4)].sval)));
        } else {
            emit_opcode(0x6C);
            emit_word(0);
        }
    ;}
    break;

  case 195:
#line 667 "parser.y"
    { emit_opcode(0x61); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 196:
#line 668 "parser.y"
    { emit_opcode(0x21); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 197:
#line 669 "parser.y"
    { emit_opcode(0xC1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 198:
#line 670 "parser.y"
    { emit_opcode(0x41); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 199:
#line 671 "parser.y"
    { emit_opcode(0xA1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 200:
#line 672 "parser.y"
    { emit_opcode(0x01); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 201:
#line 673 "parser.y"
    { emit_opcode(0xE1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 202:
#line 674 "parser.y"
    { emit_opcode(0x81); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 203:
#line 675 "parser.y"
    { emit_opcode(0x71); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 204:
#line 676 "parser.y"
    { emit_opcode(0x31); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 205:
#line 677 "parser.y"
    { emit_opcode(0xD1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 206:
#line 678 "parser.y"
    { emit_opcode(0x51); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 207:
#line 679 "parser.y"
    { emit_opcode(0xB1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 208:
#line 680 "parser.y"
    { emit_opcode(0x11); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 209:
#line 681 "parser.y"
    { emit_opcode(0xF1); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 210:
#line 682 "parser.y"
    { emit_opcode(0x91); emit_byte(eval_expr((yyvsp[(3) - (6)].sval)) & 0xFF); ;}
    break;

  case 211:
#line 686 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 212:
#line 701 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 213:
#line 715 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 214:
#line 729 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 215:
#line 743 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 216:
#line 757 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 217:
#line 771 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 218:
#line 785 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 219:
#line 802 "parser.y"
    { 
        if (pass == 2) {
            uint16_t target = eval_expr((yyvsp[(2) - (2)].sval));
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
    ;}
    break;

  case 220:
#line 816 "parser.y"
    { emit_opcode(0xDA); ;}
    break;

  case 221:
#line 817 "parser.y"
    { emit_opcode(0x5A); ;}
    break;

  case 222:
#line 818 "parser.y"
    { emit_opcode(0xFA); ;}
    break;

  case 223:
#line 819 "parser.y"
    { emit_opcode(0x7A); ;}
    break;

  case 224:
#line 820 "parser.y"
    { emit_opcode(0xCB); ;}
    break;

  case 225:
#line 821 "parser.y"
    { emit_opcode(0xDB); ;}
    break;

  case 226:
#line 822 "parser.y"
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

  case 227:
#line 832 "parser.y"
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

  case 228:
#line 842 "parser.y"
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

  case 229:
#line 852 "parser.y"
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

  case 230:
#line 865 "parser.y"
    { org_address = eval_expr((yyvsp[(2) - (2)].sval)); pc = org_address; ;}
    break;

  case 231:
#line 866 "parser.y"
    { 
        uint16_t new_pc = eval_expr((yyvsp[(2) - (2)].sval));
        /* *= only sets PC, not org_address (org_address is set by first .ORG) */
        if (org_address == 0) {
            org_address = new_pc;  /* Only set org_address if not already set */
        }
        pc = new_pc; 
    ;}
    break;

  case 232:
#line 874 "parser.y"
    { /* byte_list handles emitting */ ;}
    break;

  case 233:
#line 875 "parser.y"
    { /* word_list handles emitting */ ;}
    break;

  case 234:
#line 876 "parser.y"
    { pc += eval_expr((yyvsp[(2) - (2)].sval)); ;}
    break;

  case 235:
#line 877 "parser.y"
    { /* .EQU handled in assignment rule */ ;}
    break;

  case 236:
#line 878 "parser.y"
    { /* Page break - no-op */ ;}
    break;

  case 237:
#line 879 "parser.y"
    { /* Title directive - no-op, ignore the string (handled as any expression) */ ;}
    break;

  case 238:
#line 880 "parser.y"
    { /* List directive - no-op, ignore the parameter */ ;}
    break;

  case 239:
#line 881 "parser.y"
    { /* List directive with parameter - no-op, ignore parameter */ ;}
    break;

  case 240:
#line 882 "parser.y"
    { /* List directive with X parameter - no-op, ignore parameter */ ;}
    break;

  case 241:
#line 883 "parser.y"
    { /* List directive with Y parameter - no-op, ignore parameter */ ;}
    break;

  case 242:
#line 884 "parser.y"
    { /* List directive with expression - no-op, ignore parameter */ ;}
    break;

  case 243:
#line 885 "parser.y"
    { 
        if (pass == 2) {
            YYACCEPT;  /* End of file - stop parsing in pass 2 only */
        }
        /* In pass 1, continue to build complete symbol table */
    ;}
    break;

  case 244:
#line 894 "parser.y"
    { 
        if (is_conditional_active()) {
            emit_byte(eval_expr((yyvsp[(1) - (1)].sval)) & 0xFF); 
        }
    ;}
    break;

  case 245:
#line 899 "parser.y"
    { 
        if (is_conditional_active()) {
            emit_byte(eval_expr((yyvsp[(3) - (3)].sval)) & 0xFF); 
        }
    ;}
    break;

  case 246:
#line 907 "parser.y"
    { 
        if (is_conditional_active()) {
            emit_word(eval_expr((yyvsp[(1) - (1)].sval))); 
        }
    ;}
    break;

  case 247:
#line 912 "parser.y"
    { 
        if (is_conditional_active()) {
            emit_word(eval_expr((yyvsp[(3) - (3)].sval))); 
        }
    ;}
    break;

  case 248:
#line 920 "parser.y"
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

  case 249:
#line 948 "parser.y"
    { /* This handles ENDM when not in a macro definition (error case) */ ;}
    break;

  case 250:
#line 952 "parser.y"
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
            fprintf(stderr, "Error: Unknown identifier '%s' (not a macro or label) at line %d\n", (yyvsp[(1) - (1)].sval), yylineno);
        }
    ;}
    break;

  case 251:
#line 971 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 252:
#line 972 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 253:
#line 973 "parser.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval); ;}
    break;

  case 254:
#line 974 "parser.y"
    { 
        /* Current location counter - convert to string */
        char *result = malloc(16);
        snprintf(result, 16, "%d", pc);
        (yyval.sval) = result;
    ;}
    break;

  case 255:
#line 980 "parser.y"
    {
        /* Extract low byte of address */
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        uint8_t low_byte = addr & 0xFF;
        char *result = malloc(16);
        snprintf(result, 16, "$%02X", low_byte);
        (yyval.sval) = result;
    ;}
    break;

  case 256:
#line 988 "parser.y"
    {
        /* Extract high byte of address */
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        uint8_t high_byte = (addr >> 8) & 0xFF;
        char *result = malloc(16);
        snprintf(result, 16, "$%02X", high_byte);
        (yyval.sval) = result;
    ;}
    break;

  case 257:
#line 996 "parser.y"
    { 
        uint16_t val = eval_expr((yyvsp[(2) - (2)].sval));
        int16_t neg_val = -(int16_t)val;
        /* For 8-bit values, we want the two's complement */
        uint8_t byte_val = (uint8_t)neg_val;
        char *result = malloc(16);
        /* Always format as hex for immediate values to ensure eval_expr can parse it */
        snprintf(result, 16, "$%02X", byte_val);
        (yyval.sval) = result;
    ;}
    break;

  case 258:
#line 1006 "parser.y"
    { (yyval.sval) = (yyvsp[(2) - (2)].sval); ;}
    break;

  case 259:
#line 1007 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        char *result = malloc(16);
        snprintf(result, 16, "%d", left + right);
        (yyval.sval) = result;
    ;}
    break;

  case 260:
#line 1014 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        char *result = malloc(16);
        snprintf(result, 16, "%d", left - right);
        (yyval.sval) = result;
    ;}
    break;

  case 261:
#line 1021 "parser.y"
    { 
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        char *result = malloc(16);
        snprintf(result, 16, "%d", left * right);
        (yyval.sval) = result;
    ;}
    break;

  case 262:
#line 1028 "parser.y"
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

  case 263:
#line 1039 "parser.y"
    {
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        uint16_t result_val = left & right;
        char *result = malloc(16);
        /* Format as hex if either operand was hex */
        if ((strlen((yyvsp[(1) - (3)].sval)) > 0 && (yyvsp[(1) - (3)].sval)[0] == '$') || (strlen((yyvsp[(3) - (3)].sval)) > 0 && (yyvsp[(3) - (3)].sval)[0] == '$')) {
            snprintf(result, 16, "$%02X", result_val & 0xFF);
        } else {
            snprintf(result, 16, "%d", result_val);
        }
        (yyval.sval) = result;
    ;}
    break;

  case 264:
#line 1052 "parser.y"
    {
        uint16_t left = eval_expr((yyvsp[(1) - (3)].sval));
        uint16_t right = eval_expr((yyvsp[(3) - (3)].sval));
        uint16_t result_val = left | right;
        char *result = malloc(16);
        /* Format as hex if either operand was hex */
        if ((strlen((yyvsp[(1) - (3)].sval)) > 0 && (yyvsp[(1) - (3)].sval)[0] == '$') || (strlen((yyvsp[(3) - (3)].sval)) > 0 && (yyvsp[(3) - (3)].sval)[0] == '$')) {
            snprintf(result, 16, "$%02X", result_val & 0xFF);
        } else {
            snprintf(result, 16, "%d", result_val);
        }
        (yyval.sval) = result;
    ;}
    break;

  case 265:
#line 1065 "parser.y"
    { (yyval.sval) = (yyvsp[(2) - (3)].sval); ;}
    break;

  case 266:
#line 1069 "parser.y"
    { (yyval.ival) = eval_expr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 267:
#line 1070 "parser.y"
    { (yyval.ival) = eval_expr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 268:
#line 1071 "parser.y"
    { (yyval.ival) = eval_expr((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 269:
#line 1072 "parser.y"
    { (yyval.ival) = pc; ;}
    break;

  case 270:
#line 1073 "parser.y"
    {
        /* Extract low byte of address */
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        (yyval.ival) = addr & 0xFF;
    ;}
    break;

  case 271:
#line 1078 "parser.y"
    {
        /* Extract high byte of address */
        uint16_t addr = eval_expr((yyvsp[(2) - (2)].sval));
        (yyval.ival) = (addr >> 8) & 0xFF;
    ;}
    break;

  case 272:
#line 1083 "parser.y"
    { (yyval.ival) = -(yyvsp[(2) - (2)].ival); ;}
    break;

  case 273:
#line 1084 "parser.y"
    { (yyval.ival) = (yyvsp[(2) - (2)].ival); ;}
    break;

  case 274:
#line 1085 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) + (yyvsp[(3) - (3)].ival); ;}
    break;

  case 275:
#line 1086 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) - (yyvsp[(3) - (3)].ival); ;}
    break;

  case 276:
#line 1087 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (3)].ival) * (yyvsp[(3) - (3)].ival); ;}
    break;

  case 277:
#line 1088 "parser.y"
    { 
        if ((yyvsp[(3) - (3)].ival) == 0) {
            fprintf(stderr, "Error: Division by zero\n");
            (yyval.ival) = (yyvsp[(1) - (3)].ival);
        } else {
            (yyval.ival) = (yyvsp[(1) - (3)].ival) / (yyvsp[(3) - (3)].ival);
        }
    ;}
    break;

  case 278:
#line 1096 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (3)].ival) & (yyvsp[(3) - (3)].ival);
    ;}
    break;

  case 279:
#line 1099 "parser.y"
    {
        (yyval.ival) = (yyvsp[(1) - (3)].ival) | (yyvsp[(3) - (3)].ival);
    ;}
    break;

  case 280:
#line 1102 "parser.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 4089 "parser.tab.c"
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


#line 1105 "parser.y"


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



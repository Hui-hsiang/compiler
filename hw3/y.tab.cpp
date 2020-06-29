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
     INC = 258,
     DEC = 259,
     LE = 260,
     GE = 261,
     EQ = 262,
     NEQ = 263,
     ADD = 264,
     OR = 265,
     SUB = 266,
     MUL = 267,
     DIV = 268,
     BOOLEAN = 269,
     BREAK = 270,
     CHAR = 271,
     CASE = 272,
     CLASS = 273,
     CONTINUE = 274,
     DEF = 275,
     DO = 276,
     ELSE = 277,
     READ = 278,
     EXIT = 279,
     FALSE = 280,
     FLOAT = 281,
     FOR = 282,
     IF = 283,
     INT = 284,
     _NULL = 285,
     OBJECT = 286,
     PRINT = 287,
     PRINTLN = 288,
     REPEAT = 289,
     RETURN = 290,
     STRING = 291,
     TO = 292,
     TRUE = 293,
     TYPE = 294,
     VAL = 295,
     VAR = 296,
     WHILE = 297,
     INT_CONST = 298,
     REAL_CONST = 299,
     BOOL_CONST = 300,
     STR_CONST = 301,
     CHAR_CONST = 302,
     ID = 303,
     SEMICOLON = 304,
     AND = 305,
     UMIUNS = 306
   };
#endif
/* Tokens.  */
#define INC 258
#define DEC 259
#define LE 260
#define GE 261
#define EQ 262
#define NEQ 263
#define ADD 264
#define OR 265
#define SUB 266
#define MUL 267
#define DIV 268
#define BOOLEAN 269
#define BREAK 270
#define CHAR 271
#define CASE 272
#define CLASS 273
#define CONTINUE 274
#define DEF 275
#define DO 276
#define ELSE 277
#define READ 278
#define EXIT 279
#define FALSE 280
#define FLOAT 281
#define FOR 282
#define IF 283
#define INT 284
#define _NULL 285
#define OBJECT 286
#define PRINT 287
#define PRINTLN 288
#define REPEAT 289
#define RETURN 290
#define STRING 291
#define TO 292
#define TRUE 293
#define TYPE 294
#define VAL 295
#define VAR 296
#define WHILE 297
#define INT_CONST 298
#define REAL_CONST 299
#define BOOL_CONST 300
#define STR_CONST 301
#define CHAR_CONST 302
#define ID 303
#define SEMICOLON 304
#define AND 305
#define UMIUNS 306




/* Copy the first part of user declarations.  */
#line 1 "parser.y"


#include "Assembler.hpp"
#include "lex.yy.cpp"
#define Trace(t)    if (Opt_P) cout << t << endl


symbolTableList  tables;
Assembler assember;
int Opt_P = 1;
void yyerror(string s);



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
#line 15 "parser.y"
{
    int ival;
    double dval;
    bool bval;
    char cval;
    string* sval;
    valueInfo *value;
    idInfo *info;
    int type;
    vector<idInfo*>* argInfo;
    vector<valueInfo*> * expInfo;
}
/* Line 193 of yacc.c.  */
#line 225 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "y.tab.cpp"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   409

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  199

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,     2,     2,     2,
      61,    62,    56,    54,    64,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
      52,    65,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    12,    14,    17,    18,    24,    25,
      33,    34,    35,    45,    46,    49,    53,    55,    59,    61,
      64,    65,    67,    69,    71,    73,    75,    79,    86,    87,
      93,    94,   100,   101,   105,   106,   110,   113,   115,   118,
     119,   124,   125,   130,   133,   134,   138,   141,   142,   143,
     144,   153,   154,   155,   164,   166,   168,   169,   170,   178,
     179,   180,   193,   195,   197,   199,   201,   202,   210,   215,
     216,   222,   225,   233,   234,   242,   243,   249,   253,   258,
     262,   264,   268,   270,   274,   278,   282,   286,   289,   293,
     297,   301,   305,   309,   313,   317,   321,   324,   326,   331,
     333,   335,   337,   339,   341,   343,   345,   347,   349,   351
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      69,     0,    -1,    -1,    31,    48,    70,    59,    80,    71,
      60,    -1,    72,    -1,    72,    71,    -1,    -1,    20,    48,
      77,    73,    89,    -1,    -1,    20,    48,    61,    62,    77,
      74,    89,    -1,    -1,    -1,    20,    48,    61,    75,    79,
      62,    77,    76,    89,    -1,    -1,    63,   116,    -1,    48,
      63,   116,    -1,    78,    -1,    78,    64,    79,    -1,    81,
      -1,    81,    80,    -1,    -1,    82,    -1,   105,    -1,   112,
      -1,    93,    -1,    99,    -1,    48,    65,   114,    -1,    48,
      66,   114,    67,    65,   114,    -1,    -1,    32,    83,    61,
     114,    62,    -1,    -1,    33,    84,    61,   114,    62,    -1,
      -1,    32,    85,   114,    -1,    -1,    33,    86,   114,    -1,
      23,    48,    -1,    35,    -1,    35,   114,    -1,    -1,    59,
      88,    80,    60,    -1,    -1,    59,    90,    80,    60,    -1,
      22,    87,    -1,    -1,    22,    92,    82,    -1,    22,    93,
      -1,    -1,    -1,    -1,    28,    61,   114,    62,    94,    87,
      95,    91,    -1,    -1,    -1,    28,    61,   114,    62,    96,
      82,    97,    91,    -1,    82,    -1,    89,    -1,    -1,    -1,
      42,   100,    61,   114,    62,   101,    98,    -1,    -1,    -1,
      27,    61,    48,   102,    52,    55,   114,    37,   114,    62,
     103,   104,    -1,    82,    -1,    89,    -1,   109,    -1,   106,
      -1,    -1,    41,    48,   107,    63,   116,    65,   114,    -1,
      41,    48,    63,   116,    -1,    -1,    41,    48,   108,    65,
     114,    -1,    41,    48,    -1,    41,    48,    63,   116,    66,
      43,    67,    -1,    -1,    40,    48,   110,    63,   116,    65,
     114,    -1,    -1,    40,    48,   111,    65,   114,    -1,    48,
      61,    62,    -1,    48,    61,   113,    62,    -1,   114,    64,
     113,    -1,   114,    -1,    61,   114,    62,    -1,   112,    -1,
     114,    54,   114,    -1,   114,    55,   114,    -1,   114,    56,
     114,    -1,   114,    57,   114,    -1,    55,   114,    -1,   114,
      10,   114,    -1,   114,    50,   114,    -1,   114,    52,   114,
      -1,   114,    53,   114,    -1,   114,     7,   114,    -1,   114,
       6,   114,    -1,   114,     5,   114,    -1,   114,     8,   114,
      -1,    51,   114,    -1,    48,    -1,    48,    66,   114,    67,
      -1,   115,    -1,    46,    -1,    43,    -1,    45,    -1,    44,
      -1,    47,    -1,    16,    -1,    36,    -1,    29,    -1,    14,
      -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    55,    75,    77,    86,    86,   110,   110,
     135,   137,   135,   163,   163,   167,   176,   181,   187,   190,
     193,   198,   198,   198,   198,   198,   200,   219,   224,   224,
     256,   256,   290,   290,   324,   324,   358,   359,   360,   365,
     365,   375,   375,   382,   386,   386,   390,   391,   394,   394,
     394,   401,   409,   401,   417,   417,   419,   419,   419,   432,
     432,   432,   464,   464,   467,   467,   472,   472,   491,   504,
     504,   521,   534,   549,   549,   564,   564,   577,   599,   622,
     628,   636,   640,   641,   660,   679,   698,   717,   736,   752,
     767,   780,   793,   821,   834,   848,   876,   891,   910,   926,
     933,   937,   941,   945,   949,   955,   958,   961,   964,   967
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INC", "DEC", "LE", "GE", "EQ", "NEQ",
  "ADD", "OR", "SUB", "MUL", "DIV", "BOOLEAN", "BREAK", "CHAR", "CASE",
  "CLASS", "CONTINUE", "DEF", "DO", "ELSE", "READ", "EXIT", "FALSE",
  "FLOAT", "FOR", "IF", "INT", "_NULL", "OBJECT", "PRINT", "PRINTLN",
  "REPEAT", "RETURN", "STRING", "TO", "TRUE", "TYPE", "VAL", "VAR",
  "WHILE", "INT_CONST", "REAL_CONST", "BOOL_CONST", "STR_CONST",
  "CHAR_CONST", "ID", "SEMICOLON", "AND", "'!'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "UMIUNS", "'{'", "'}'", "'('", "')'", "':'", "','",
  "'='", "'['", "']'", "$accept", "PROGRAM", "@1", "METHODS", "METHOD",
  "@2", "@3", "@4", "@5", "FUNC_OPTIONAL", "ARG", "comma_seperated_ARG",
  "STMTS", "STMT", "SIMPLE", "@6", "@7", "@8", "@9", "BLOCK", "@10",
  "FUC_BLOCK", "@11", "CONDTIONAL_OPTIONAL", "@12", "CONDITIONAL", "@13",
  "@14", "@15", "@16", "LOOP_CONDTIONAL", "LOOP", "@17", "@18", "@19",
  "@20", "FOR_OPTIONAL", "V_DEC", "VAR_DEC", "@21", "@22", "CONST_DEC",
  "@23", "@24", "FUNCTION_INVOCATION", "comma_seperated_EXP", "EXP",
  "VALUE", "DATA_TYPE", 0
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
     305,    33,    60,    62,    43,    45,    42,    47,   306,   123,
     125,    40,    41,    58,    44,    61,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    70,    69,    71,    71,    73,    72,    74,    72,
      75,    76,    72,    77,    77,    78,    79,    79,    80,    80,
      80,    81,    81,    81,    81,    81,    82,    82,    83,    82,
      84,    82,    85,    82,    86,    82,    82,    82,    82,    88,
      87,    90,    89,    91,    92,    91,    91,    91,    94,    95,
      93,    96,    97,    93,    98,    98,   100,   101,    99,   102,
     103,    99,   104,   104,   105,   105,   107,   106,   106,   108,
     106,   106,   106,   110,   109,   111,   109,   112,   112,   113,
     113,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   116
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     1,     2,     0,     5,     0,     7,
       0,     0,     9,     0,     2,     3,     1,     3,     1,     2,
       0,     1,     1,     1,     1,     1,     3,     6,     0,     5,
       0,     5,     0,     3,     0,     3,     2,     1,     2,     0,
       4,     0,     4,     2,     0,     3,     2,     0,     0,     0,
       8,     0,     0,     8,     1,     1,     0,     0,     7,     0,
       0,    12,     1,     1,     1,     1,     0,     7,     4,     0,
       5,     2,     7,     0,     7,     0,     5,     3,     4,     3,
       1,     3,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,    20,     0,     0,     0,
      32,    34,    37,     0,     0,    56,     0,     0,    18,    21,
      24,    25,    22,    65,    64,    23,    36,     0,     0,     0,
       0,     0,     0,   101,   103,   102,   100,   104,    97,     0,
       0,     0,    82,    38,    99,    73,    71,     0,     0,     0,
       0,     0,     0,     4,    19,    59,     0,     0,    33,     0,
      35,     0,    96,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,    80,    26,     0,    13,     3,
       5,     0,    51,     0,     0,     0,    81,    94,    93,    92,
      95,    88,    89,    90,    91,    83,    84,    85,    86,     0,
       0,   108,   105,   109,   107,   106,    68,     0,     0,     0,
      78,     0,     0,    10,     0,     6,     0,     0,     0,    29,
      31,    98,     0,    76,     0,     0,    70,    57,    79,     0,
      13,     0,    14,     0,     0,    39,    49,     0,    52,     0,
       0,     0,     0,    27,     8,     0,    16,     0,    41,     7,
       0,    20,    47,    47,    74,    72,    67,    54,    55,    58,
       0,     0,     0,    13,    20,     0,     0,    44,    50,    53,
       9,    15,    17,    11,     0,     0,    40,    43,     0,    46,
       0,    42,    60,    45,    12,     0,    62,    63,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    52,    53,   143,   170,   141,   190,   125,
     156,   157,    17,    18,    19,    29,    31,    30,    32,   146,
     161,   159,   174,   178,   188,    20,   127,   162,   128,   163,
     169,    21,    47,   152,    91,   195,   198,    22,    23,    80,
      81,    24,    77,    78,    42,    84,    85,    44,   116
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -147
static const yytype_int16 yypact[] =
{
     -27,   -37,    22,  -147,  -147,   -33,   322,    -1,     8,    11,
      12,    14,   348,    28,    30,  -147,   -56,    66,   322,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,    45,   348,    34,
     348,    36,   348,  -147,  -147,  -147,  -147,  -147,   -48,   348,
     348,   348,  -147,   261,  -147,    33,   -38,    39,   328,   348,
     348,    55,    44,    66,  -147,  -147,   136,   348,   261,   348,
     261,   348,   287,  -147,   155,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   348,   348,    46,    47,   121,
      56,    53,   348,  -147,    58,   117,   261,    27,     5,  -147,
    -147,    77,    71,   170,   189,    35,  -147,    60,    60,    60,
      60,   281,   287,    60,    60,   -42,   -42,  -147,  -147,   121,
     348,  -147,  -147,  -147,  -147,  -147,    65,   121,   348,   208,
    -147,   348,    69,    74,   121,  -147,    84,    89,    78,  -147,
    -147,  -147,    86,   261,   106,    87,   261,  -147,  -147,   348,
      90,   108,  -147,    95,   348,  -147,  -147,   -13,  -147,   348,
      92,   348,    73,   261,  -147,   103,   115,   120,  -147,  -147,
     247,   322,   161,   161,   261,  -147,   261,  -147,  -147,  -147,
      95,   121,   108,    90,   322,   348,   124,    -8,  -147,  -147,
    -147,  -147,  -147,  -147,   125,   223,  -147,  -147,    78,  -147,
      95,  -147,  -147,  -147,  -147,    73,  -147,  -147,  -147
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,  -147,   134,  -147,  -147,  -147,  -147,  -147,  -137,
    -147,    29,   -16,  -147,  -121,  -147,  -147,  -147,  -147,    23,
    -147,  -146,  -147,    40,  -147,    25,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,    -6,    83,   -11,  -147,  -101
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      25,    43,    54,   154,     1,    48,   168,   148,   132,    49,
      50,     3,    25,    48,    75,    76,   135,    56,    61,    58,
       9,    60,     4,   142,   180,    79,     6,   -69,    62,    63,
      64,   167,    65,    66,    67,    68,   183,    69,    86,    87,
      65,    66,    67,    68,   194,    69,    93,    26,    94,   197,
      95,   145,    49,    50,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   123,   193,   124,    27,
     181,   119,    28,   -28,   196,   -30,    45,    70,    46,    71,
      72,    73,    74,    75,    76,    70,    51,    71,    72,    73,
      74,    75,    76,    55,   122,    57,     7,    59,   -75,   133,
      82,     7,   131,    88,    89,    10,    11,   136,    12,   109,
      10,    11,   110,    12,    73,    74,    75,    76,   118,   117,
     120,   147,    65,    66,    67,    68,   147,    69,   153,   126,
     -48,   134,   158,   160,   139,   111,   140,   112,   164,   144,
     166,    65,    66,    67,    68,   176,    69,   113,   145,   150,
     114,   149,   151,   124,   158,    25,   155,   115,   184,   165,
      65,    66,    67,    68,   185,    69,   171,    70,    25,    71,
      72,    73,    74,    75,    76,    65,    66,    67,    68,   172,
      69,   121,   173,   177,   186,   191,    70,    90,    71,    72,
      73,    74,    75,    76,    65,    66,    67,    68,    92,    69,
     187,   182,   189,   179,   138,    70,     0,    71,    72,    73,
      74,    75,    76,    65,    66,    67,    68,    96,    69,     0,
      70,     0,    71,    72,    73,    74,    75,    76,    65,    66,
      67,    68,   129,    69,     0,     0,     0,     0,     0,    70,
       0,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,   130,    65,    66,    67,    68,     0,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    65,    66,    67,    68,
     137,    69,     0,    70,     0,    71,    72,    73,    74,    75,
      76,     0,     0,     0,   175,   192,    65,    66,    67,    68,
       0,     0,    65,    66,    67,    68,     0,    70,     0,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    70,     0,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,    71,    72,    73,    74,    75,    76,    71,
      72,    73,    74,    75,    76,     7,     0,     0,     0,     8,
       9,     0,     0,     0,    10,    11,     0,    12,     0,     0,
       0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
      16,    33,    34,    35,    36,    37,    38,     0,     0,    39,
       0,     0,     0,    40,     0,     0,     0,     0,     0,    41,
      83,    33,    34,    35,    36,    37,    38,     0,     0,    39,
       0,     0,     0,    40,     0,     0,     0,     0,     0,    41
};

static const yytype_int16 yycheck[] =
{
       6,    12,    18,   140,    31,    61,   152,   128,   109,    65,
      66,    48,    18,    61,    56,    57,   117,    28,    66,    30,
      28,    32,     0,   124,   170,    63,    59,    65,    39,    40,
      41,   152,     5,     6,     7,     8,   173,    10,    49,    50,
       5,     6,     7,     8,   190,    10,    57,    48,    59,   195,
      61,    59,    65,    66,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    61,   188,    63,    61,
     171,    82,    61,    61,   195,    61,    48,    50,    48,    52,
      53,    54,    55,    56,    57,    50,    20,    52,    53,    54,
      55,    56,    57,    48,    67,    61,    23,    61,    65,   110,
      61,    23,    67,    48,    60,    32,    33,   118,    35,    63,
      32,    33,    65,    35,    54,    55,    56,    57,    65,    63,
      62,    48,     5,     6,     7,     8,    48,    10,   139,    52,
      59,    66,    59,   144,    65,    14,    62,    16,   149,    55,
     151,     5,     6,     7,     8,   161,    10,    26,    59,    43,
      29,    65,    65,    63,    59,   161,    48,    36,   174,    67,
       5,     6,     7,     8,   175,    10,    63,    50,   174,    52,
      53,    54,    55,    56,    57,     5,     6,     7,     8,    64,
      10,    64,    62,    22,    60,    60,    50,    53,    52,    53,
      54,    55,    56,    57,     5,     6,     7,     8,    62,    10,
     177,   172,   177,   163,   121,    50,    -1,    52,    53,    54,
      55,    56,    57,     5,     6,     7,     8,    62,    10,    -1,
      50,    -1,    52,    53,    54,    55,    56,    57,     5,     6,
       7,     8,    62,    10,    -1,    -1,    -1,    -1,    -1,    50,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    62,     5,     6,     7,     8,    -1,    10,    50,    -1,
      52,    53,    54,    55,    56,    57,     5,     6,     7,     8,
      62,    10,    -1,    50,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    37,    62,     5,     6,     7,     8,
      -1,    -1,     5,     6,     7,     8,    -1,    50,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    52,    53,    54,    55,    56,    57,    52,
      53,    54,    55,    56,    57,    23,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    32,    33,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    43,    44,    45,    46,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    69,    48,     0,    70,    59,    23,    27,    28,
      32,    33,    35,    40,    41,    42,    48,    80,    81,    82,
      93,    99,   105,   106,   109,   112,    48,    61,    61,    83,
      85,    84,    86,    43,    44,    45,    46,    47,    48,    51,
      55,    61,   112,   114,   115,    48,    48,   100,    61,    65,
      66,    20,    71,    72,    80,    48,   114,    61,   114,    61,
     114,    66,   114,   114,   114,     5,     6,     7,     8,    10,
      50,    52,    53,    54,    55,    56,    57,   110,   111,    63,
     107,   108,    61,    62,   113,   114,   114,   114,    48,    60,
      71,   102,    62,   114,   114,   114,    62,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,    63,
      65,    14,    16,    26,    29,    36,   116,    63,    65,   114,
      62,    64,    67,    61,    63,    77,    52,    94,    96,    62,
      62,    67,   116,   114,    66,   116,   114,    62,   113,    65,
      62,    75,   116,    73,    55,    59,    87,    48,    82,    65,
      43,    65,   101,   114,    77,    48,    78,    79,    59,    89,
     114,    88,    95,    97,   114,    67,   114,    82,    89,    98,
      74,    63,    64,    62,    90,    37,    80,    22,    91,    91,
      89,   116,    79,    77,    80,   114,    60,    87,    92,    93,
      76,    60,    62,    82,    89,   103,    82,    89,   104
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
        case 2:
#line 55 "parser.y"
    {
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (2)].sval), objectType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                assember.objinitial(*(yyvsp[(2) - (2)].sval));
            }
    break;

  case 3:
#line 63 "parser.y"
    {
                assember.objFinish();
                if (tables.lookup("main") == NULL){
                    yyerror("have no main function!!");
                }else{
                    if(tables.lookup("main")->idType != functionType){
                        yyerror("have no main function!!");
                    }
                }
            }
    break;

  case 4:
#line 75 "parser.y"
    {
            Trace("METHOD");
        }
    break;

  case 5:
#line 77 "parser.y"
    {
            Trace("METHOD METHODS");
        }
    break;

  case 6:
#line 86 "parser.y"
    {
            
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (3)].sval), functionType, (yyvsp[(3) - (3)].type));
            if (result == -1){
                yyerror("id has been uesd");
            }
            if(*(yyvsp[(2) - (3)].sval) == "main"){
                assember.mainDEC();
            }else{
                assember.funDEC(*(yyvsp[(2) - (3)].sval), (yyvsp[(3) - (3)].type));
            }
            tables.push();
        }
    break;

  case 7:
#line 99 "parser.y"
    {
            if(*(yyvsp[(2) - (5)].sval) == "main"){
                assember.mainFinish();
            }
            else{
                assember.funFinish();
            }
            assember.leaveBlock(*(yyvsp[(2) - (5)].sval));
            tables.dump();
            tables.pop();
        }
    break;

  case 8:
#line 110 "parser.y"
    {
            
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (5)].sval), functionType,(yyvsp[(5) - (5)].type));
            if (result == -1){
                yyerror("id has been uesd");
            }
            if(*(yyvsp[(2) - (5)].sval) == "main"){
                assember.mainDEC();
            }
            else{
                assember.funDEC(*(yyvsp[(2) - (5)].sval), (yyvsp[(5) - (5)].type));
            }
            tables.push();
        }
    break;

  case 9:
#line 124 "parser.y"
    {
            if(*(yyvsp[(2) - (7)].sval) == "main"){
                assember.mainFinish();
            }
            else{
                assember.funFinish();
            }
            assember.leaveBlock(*(yyvsp[(2) - (7)].sval));
            tables.dump();
            tables.pop();
        }
    break;

  case 10:
#line 135 "parser.y"
    {
            tables.push(); 
        }
    break;

  case 11:
#line 137 "parser.y"
    {
            Trace("ARG METHOD");
            int result =  tables.list[tables.top - 1].insert(*(yyvsp[(2) - (7)].sval), functionType,(yyvsp[(7) - (7)].type));
            if (result == -1){
                yyerror("id has been uesd");
            }
            idInfo* tmp = tables.lookup(*(yyvsp[(2) - (7)].sval));
            tmp->arg = *(yyvsp[(5) - (7)].argInfo);
            if(*(yyvsp[(2) - (7)].sval) == "main"){
                assember.mainDEC();
            }
            else{
                assember.funDEC(*(yyvsp[(2) - (7)].sval), (yyvsp[(5) - (7)].argInfo), (yyvsp[(7) - (7)].type));
            }
        }
    break;

  case 12:
#line 151 "parser.y"
    {
            if(*(yyvsp[(2) - (9)].sval) == "main"){
                assember.mainFinish();
            }
            else{
                assember.funFinish();
            }
            assember.leaveBlock(*(yyvsp[(2) - (9)].sval));
            tables.dump();
            tables.pop();
        }
    break;

  case 13:
#line 163 "parser.y"
    {(yyval.type) = unknowType; }
    break;

  case 14:
#line 163 "parser.y"
    { (yyval.type) = (yyvsp[(2) - (2)].type); }
    break;

  case 15:
#line 167 "parser.y"
    {
            int result =  tables.list[tables.top].insert(*(yyvsp[(1) - (3)].sval),variableType, (yyvsp[(3) - (3)].type));
            if (result == -1){
                yyerror("id has been uesd");
            }
            (yyval.info) = tables.lookup(*(yyvsp[(1) - (3)].sval));
        }
    break;

  case 16:
#line 176 "parser.y"
    {
                        vector<idInfo*>* tmp = new vector<idInfo*>();
                        tmp->push_back((yyvsp[(1) - (1)].info));
                        (yyval.argInfo) = tmp;
                    }
    break;

  case 17:
#line 181 "parser.y"
    {
                        vector<idInfo*>* tmp = (yyvsp[(3) - (3)].argInfo);
                        tmp->push_back((yyvsp[(1) - (3)].info));
                        (yyval.argInfo) = tmp;
                    }
    break;

  case 18:
#line 187 "parser.y"
    {
            Trace("STMT");
        }
    break;

  case 19:
#line 190 "parser.y"
    {
            Trace("STMT STMTS");
        }
    break;

  case 26:
#line 200 "parser.y"
    {

            Trace("ID = EXP");
            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (3)].sval));
            if ( (yyvsp[(3) - (3)].value)->valueType != tmp->value->valueType){
                if (tmp->value->valueType == valueTypeError){tmp->value->valueType = (yyvsp[(3) - (3)].value)->valueType;}
                else if (((yyvsp[(3) - (3)].value)->valueType == floatType && tmp->value->valueType == intType) || ((yyvsp[(3) - (3)].value)->valueType == intType && tmp->value->valueType == floatType)){}
                else{
                    yyerror("Type error ");
                }
            }


            if (tmp->symbolTable_index != 0){
                assember.putLocal(tmp);
            }else{
                assember.putGlobal(tmp);
            }
        }
    break;

  case 27:
#line 219 "parser.y"
    {
            if ((yyvsp[(3) - (6)].value)->valueType != intType){
                yyerror("index must be INT");
            }
        }
    break;

  case 28:
#line 224 "parser.y"
    {

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }
    break;

  case 29:
#line 228 "parser.y"
    {
            switch ((yyvsp[(4) - (5)].value)->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
            }
        }
    break;

  case 30:
#line 256 "parser.y"
    {

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }
    break;

  case 31:
#line 260 "parser.y"
    {

            switch ((yyvsp[(4) - (5)].value)->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
            }

        }
    break;

  case 32:
#line 290 "parser.y"
    {

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }
    break;

  case 33:
#line 294 "parser.y"
    {

            switch ((yyvsp[(3) - (3)].value)->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.print(int)\n";
                    break;
            }

        }
    break;

  case 34:
#line 324 "parser.y"
    {

            assember.output << "getstatic java.io.PrintStream java.lang.System.out\n";

        }
    break;

  case 35:
#line 328 "parser.y"
    {

            switch ((yyvsp[(3) - (3)].value)->valueType){
                case intType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                case floatType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(float)\n";
                    break;
                case boolType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                case charType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(char)\n";
                    break;
                case stringType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(java.lang.String)\n";
                    break;
                case unknowType:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                case valueTypeError:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
                default:
                    assember.output << "invokevirtual void java.io.PrintStream.println(int)\n";
                    break;
            }

        }
    break;

  case 37:
#line 359 "parser.y"
    {Trace("return");}
    break;

  case 38:
#line 360 "parser.y"
    {Trace("return EXP");}
    break;

  case 39:
#line 365 "parser.y"
    {
            Trace("BLOCK");
            assember.enterBlock();
            tables.push();
        }
    break;

  case 40:
#line 370 "parser.y"
    { 

            tables.dump();
            tables.pop();
        }
    break;

  case 41:
#line 375 "parser.y"
    {
                assember.enterBlock();

            }
    break;

  case 42:
#line 378 "parser.y"
    { 
                Trace("FUN_BLOCK");
            }
    break;

  case 43:
#line 382 "parser.y"
    { 
                        Trace("ELSE BLOCK");
                        assember.elseFinish();
                    }
    break;

  case 44:
#line 386 "parser.y"
    {Trace("ESLE");tables.push();}
    break;

  case 45:
#line 386 "parser.y"
    { 
                        Trace("ELSE SIMPLE");tables.dump();
                        assember.elseFinish();
                        tables.pop();
                    }
    break;

  case 46:
#line 390 "parser.y"
    { Trace("ELSE CONDITION");}
    break;

  case 47:
#line 391 "parser.y"
    { assember.elseFinish(); }
    break;

  case 48:
#line 394 "parser.y"
    { assember.ifCondition();}
    break;

  case 49:
#line 394 "parser.y"
    {
                    Trace("IF BLOCK");
                    if ((yyvsp[(3) - (6)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    assember.ifFinish();
                }
    break;

  case 51:
#line 401 "parser.y"
    {
                    Trace("IF SIMPLE ");
                    if ((yyvsp[(3) - (4)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    tables.push();
                    assember.ifCondition();
                }
    break;

  case 52:
#line 409 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                    assember.ifFinish();
                }
    break;

  case 56:
#line 419 "parser.y"
    {assember.whileLoopBegin();}
    break;

  case 57:
#line 419 "parser.y"
    {
            tables.push();
            Trace("WHILE LOOP");
            if ((yyvsp[(4) - (5)].value)->valueType != boolType ){
                yyerror("CONDITION SHOULD BE BOOL TYPE");
            }
            assember.whileLoopIn();
        }
    break;

  case 58:
#line 427 "parser.y"
    {
            tables.dump();
            tables.pop();
            assember.whileLoopexit();
        }
    break;

  case 59:
#line 432 "parser.y"
    {assember.fp = assember.output.tellp();}
    break;

  case 60:
#line 432 "parser.y"
    {
            tables.push();

            idInfo* tmp = tables.lookup(*(yyvsp[(3) - (10)].sval));
            if(tmp->idType == constType){
                yyerror("const Type error!");
            }
            if((yyvsp[(7) - (10)].value)->valueType != intType || (yyvsp[(9) - (10)].value)->valueType != intType){
                yyerror("range should be intType!");
            }
            assember.output.seekp(assember.fp);

            if (tmp->symbolTable_index != 0){
                assember.forLoopBegin(0, tmp, (yyvsp[(7) - (10)].value), (yyvsp[(9) - (10)].value));
            }else{
                assember.forLoopBegin(1, tmp, (yyvsp[(7) - (10)].value), (yyvsp[(9) - (10)].value));
            }
        
            Trace("FOR LOOP");
        }
    break;

  case 61:
#line 452 "parser.y"
    {
            idInfo* tmp = tables.lookup(*(yyvsp[(3) - (12)].sval));
            if (tmp->symbolTable_index != 0){
                assember.forLoopFinish(0, tmp, (yyvsp[(7) - (12)].value), (yyvsp[(9) - (12)].value));
            }else{
                assember.forLoopFinish(1, tmp, (yyvsp[(7) - (12)].value), (yyvsp[(9) - (12)].value));
            }

            tables.dump();
            tables.pop();
        }
    break;

  case 66:
#line 472 "parser.y"
    {assember.fp = assember.output.tellp();}
    break;

  case 67:
#line 472 "parser.y"
    {
                Trace("VAR ID : DATA_TYPE = EXP");
                if ((yyvsp[(5) - (7)].type) != (yyvsp[(7) - (7)].value)->valueType){
                    if((yyvsp[(5) - (7)].type) != floatType && (yyvsp[(7) - (7)].value)->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (7)].sval), variableType, (yyvsp[(7) - (7)].value));
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    assember.output.seekp(assember.fp);
                    assember.globalVar((yyvsp[(7) - (7)].value)->valueType, *(yyvsp[(2) - (7)].sval), (yyvsp[(7) - (7)].value));
                }
                else{
                    assember.localVar(*(yyvsp[(2) - (7)].sval), (yyvsp[(7) - (7)].value));
                }
            }
    break;

  case 68:
#line 491 "parser.y"
    {
                Trace("VAR ID : DATA_TYPE");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (4)].sval), variableType, (yyvsp[(4) - (4)].type));
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    assember.globalVar((yyvsp[(4) - (4)].type), *(yyvsp[(2) - (4)].sval));
                }
                else{
                    assember.localVar(*(yyvsp[(2) - (4)].sval));
                }
            }
    break;

  case 69:
#line 504 "parser.y"
    {assember.fp = assember.output.tellp();}
    break;

  case 70:
#line 504 "parser.y"
    {
                Trace("VAR ID  = EXP");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (5)].sval), variableType, (yyvsp[(5) - (5)].value));
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if ((yyvsp[(5) - (5)].value)->valueType == unknowType){
                    yyerror("valueType ERROR");
                }
                if (tables.top == 0){
                    assember.output.seekp(assember.fp);
                    assember.globalVar((yyvsp[(5) - (5)].value)->valueType, *(yyvsp[(2) - (5)].sval), (yyvsp[(5) - (5)].value));
                }
                else{
                    assember.localVar(*(yyvsp[(2) - (5)].sval), (yyvsp[(5) - (5)].value));
                }
            }
    break;

  case 71:
#line 521 "parser.y"
    {
                Trace("VAR ID");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (2)].sval), variableType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    assember.globalVar(intType, *(yyvsp[(2) - (2)].sval));
                }
                else{
                    assember.localVar(*(yyvsp[(2) - (2)].sval));
                }
            }
    break;

  case 72:
#line 534 "parser.y"
    {
                Trace("VAR ID : DATA_TYPE [NUM]");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (7)].sval), arrayType, (yyvsp[(4) - (7)].type), (yyvsp[(6) - (7)].ival));
                if (result == -1){
                   yyerror("id has been uesd");
                }
                if (tables.top == 0){
                    
                }
                else{
                    
                }
            }
    break;

  case 73:
#line 549 "parser.y"
    {
                assember.fp = assember.output.tellp();
                }
    break;

  case 74:
#line 551 "parser.y"
    {
                Trace("VAL ID : DATA_TYPE = EXP");
                if ((yyvsp[(5) - (7)].type) != (yyvsp[(7) - (7)].value)->valueType){
                    if((yyvsp[(5) - (7)].type) != floatType && (yyvsp[(7) - (7)].value)->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (7)].sval), constType, (yyvsp[(7) - (7)].value));
                if (result == -1){
                   yyerror("id has been uesd");
                }
                assember.output.seekp(assember.fp);
            }
    break;

  case 75:
#line 564 "parser.y"
    {
                assember.fp = assember.output.tellp();
            }
    break;

  case 76:
#line 566 "parser.y"
    {
                Trace("VAL ID = EXP");
                int result = tables.list[tables.top].insert(*(yyvsp[(2) - (5)].sval) ,constType, (yyvsp[(5) - (5)].value));
                
                if (result == -1){
                    yyerror("id has been uesd");
                }
                assember.output.seekp(assember.fp);
            }
    break;

  case 77:
#line 577 "parser.y"
    {
                            Trace("ID()");
                            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (3)].sval));
                            if (tmp == NULL){
                                yyerror("CANT FIND ID");
                            }
                            if(tmp->idType != functionType){
                                yyerror("ID IS NOT A FUNCTION");
                            }
                            if(tmp->arg.size() != 0){
                                yyerror("ARG ERROR");
                            }
                            valueInfo* v = new valueInfo();
                            v->valueType = tmp->returnType;

                            assember.funInvke(*(yyvsp[(1) - (3)].sval),tmp->returnType);

                            (yyval.value) = v;

   

                        }
    break;

  case 78:
#line 599 "parser.y"
    {
                            Trace("ID COMMA SEPERATED EXP");
                            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (4)].sval));
                            vector<valueInfo*>* texp = (yyvsp[(3) - (4)].expInfo);
                            if (tmp == NULL){
                                yyerror("CANT FIND ID");
                            }
                            if(tmp->idType != functionType){
                                yyerror("ID IS NOT A FUNCTION");
                            }
                            valueInfo* v = new valueInfo();
                            v->valueType = tmp->returnType;

                            for (int i=0;i<(yyvsp[(3) - (4)].expInfo)->size();i++){
                                if ((*texp)[i]->valueType != tmp->arg[i]->value->valueType){
                                    yyerror("arg not match");
                                }
                            }
                            assember.funInvke(*(yyvsp[(1) - (4)].sval),tmp->returnType, (yyvsp[(3) - (4)].expInfo));

                            (yyval.value) = v;
                        }
    break;

  case 79:
#line 622 "parser.y"
    {
                            Trace("COMMA SEPREATED EXP");
                            vector<valueInfo*>* tmp = (yyvsp[(3) - (3)].expInfo);
                            tmp->push_back((yyvsp[(1) - (3)].value));
                            (yyval.expInfo) = tmp;
                        }
    break;

  case 80:
#line 628 "parser.y"
    {
                            Trace("EXP");
                            vector<valueInfo*>* tmp = new vector<valueInfo*>();
                            tmp->push_back((yyvsp[(1) - (1)].value));
                            (yyval.expInfo) = tmp;
                        }
    break;

  case 81:
#line 636 "parser.y"
    {
            Trace("( EXP )");
            (yyval.value) = (yyvsp[(2) - (3)].value);
        }
    break;

  case 82:
#line 640 "parser.y"
    {Trace("FUNINVOKE");}
    break;

  case 83:
#line 641 "parser.y"
    {
            Trace("EXP '+' EXP");
            valueInfo* tmp = new valueInfo();
            if ((yyvsp[(1) - (3)].value)->valueType == intType && (yyvsp[(3) - (3)].value)->valueType == intType){
                tmp->valueType = intType;
                tmp->intval = ((yyvsp[(1) - (3)].value)->intval + (yyvsp[(3) - (3)].value)->intval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == floatType && (yyvsp[(3) - (3)].value)->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ((yyvsp[(1) - (3)].value)->floatval + (yyvsp[(3) - (3)].value)->floatval);
            }
            else{
                yyerror("EXP + EXP Type ERROR");
            }

            assember.output << "iadd\n";

            (yyval.value) = tmp;
        }
    break;

  case 84:
#line 660 "parser.y"
    {
            Trace("EXP '-' EXP");
            valueInfo* tmp = new valueInfo();
            if ((yyvsp[(1) - (3)].value)->valueType == intType && (yyvsp[(3) - (3)].value)->valueType == intType){
                tmp->valueType = intType;
                tmp->intval = ((yyvsp[(1) - (3)].value)->intval - (yyvsp[(3) - (3)].value)->intval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == floatType && (yyvsp[(3) - (3)].value)->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ((yyvsp[(1) - (3)].value)->floatval - (yyvsp[(3) - (3)].value)->floatval);
            }
            else{
                yyerror("EXP - EXP Type ERROR");
            }

            assember.output << "isub\n";

            (yyval.value) = tmp;
        }
    break;

  case 85:
#line 679 "parser.y"
    {
            Trace("EXP '*' EXP");
            valueInfo* tmp = new valueInfo();
            if ((yyvsp[(1) - (3)].value)->valueType == intType && (yyvsp[(3) - (3)].value)->valueType == intType){
                tmp->valueType = intType;
                tmp->intval = ((yyvsp[(1) - (3)].value)->intval * (yyvsp[(3) - (3)].value)->intval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == floatType && (yyvsp[(3) - (3)].value)->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ((yyvsp[(1) - (3)].value)->floatval * (yyvsp[(3) - (3)].value)->floatval);
            }
            else{
                yyerror("EXP * EXP Type ERROR");
            }

            assember.output << "imul\n";

            (yyval.value) = tmp;
        }
    break;

  case 86:
#line 698 "parser.y"
    {
            Trace("EXP '/' EXP");
            valueInfo* tmp = new valueInfo();
            if ((yyvsp[(1) - (3)].value)->valueType == intType && (yyvsp[(3) - (3)].value)->valueType == intType){
                tmp->valueType = floatType;
                tmp->floatval = ((yyvsp[(1) - (3)].value)->intval / (yyvsp[(3) - (3)].value)->intval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == floatType && (yyvsp[(3) - (3)].value)->valueType == floatType){
                tmp->valueType = floatType;
                tmp->floatval = ((yyvsp[(1) - (3)].value)->floatval * (yyvsp[(3) - (3)].value)->floatval);
            }
            else{
                yyerror("EXP * EXP Type ERROR");
            }

            assember.output << "idiv\n";

            (yyval.value) = tmp;
        }
    break;

  case 87:
#line 717 "parser.y"
    {
            Trace("- EXP");
            valueInfo* tmp = new valueInfo();
            if ((yyvsp[(2) - (2)].value)->valueType == intType){
                *tmp = *(yyvsp[(2) - (2)].value);
                tmp->intval = -1 * tmp->intval;
            }
            else if((yyvsp[(2) - (2)].value)->valueType == floatType){
                *tmp = *(yyvsp[(2) - (2)].value);
                tmp->floatval = -1 * tmp->floatval;
            }
            else {
                yyerror("- EXP ERROR");
            }

            assember.output << "ineg\n";

            (yyval.value) = tmp;
        }
    break;

  case 88:
#line 736 "parser.y"
    {
            Trace("EXP || EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != boolType || (yyvsp[(3) - (3)].value)->valueType != boolType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ((yyvsp[(1) - (3)].value)->boolval || (yyvsp[(3) - (3)].value)->boolval);
            }

            assember.output << "ior\n";

            (yyval.value) = tmp;

        }
    break;

  case 89:
#line 752 "parser.y"
    {
            Trace("EXP && EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != boolType || (yyvsp[(3) - (3)].value)->valueType != boolType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ((yyvsp[(1) - (3)].value)->boolval && (yyvsp[(3) - (3)].value)->boolval);
            }

            assember.output << "iand\n";

            (yyval.value) = tmp;
        }
    break;

  case 90:
#line 767 "parser.y"
    {
            Trace("EXP '<' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType !=  (yyvsp[(3) - (3)].value)->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ((yyvsp[(1) - (3)].value)->boolval < (yyvsp[(3) - (3)].value)->boolval);
            }
            assember.ls();
            (yyval.value) = tmp;
        }
    break;

  case 91:
#line 780 "parser.y"
    {
            Trace("EXP '>' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType !=  (yyvsp[(3) - (3)].value)->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = ((yyvsp[(1) - (3)].value)->boolval > (yyvsp[(3) - (3)].value)->boolval);
            }
            assember.gt();
            (yyval.value) = tmp;
        }
    break;

  case 92:
#line 793 "parser.y"
    {
            Trace("EXP '==' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
                yyerror("Type NOT MATCH ERROR");
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == intType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->intval == (yyvsp[(3) - (3)].value)->intval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == boolType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->boolval == (yyvsp[(3) - (3)].value)->boolval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == floatType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->floatval == (yyvsp[(3) - (3)].value)->floatval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == stringType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->stringval == (yyvsp[(3) - (3)].value)->stringval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == charType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->charval == (yyvsp[(3) - (3)].value)->charval);
            }
            else{
                yyerror("EXP == EXP ERROR");
            }
            assember.eq();
            (yyval.value) = tmp;
        }
    break;

  case 93:
#line 821 "parser.y"
    {
            Trace("EXP '>=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = (yyvsp[(1) - (3)].value)->boolval >= (yyvsp[(3) - (3)].value)->boolval;
            }
            assember.ge();
            (yyval.value) = tmp;
        }
    break;

  case 94:
#line 834 "parser.y"
    {
            Trace("EXP '<=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
                if((yyvsp[(1) - (3)].value)->valueType == floatType &&  (yyvsp[(3) - (3)].value)->valueType == intType || (yyvsp[(1) - (3)].value)->valueType == intType && (yyvsp[(3) - (3)].value)->valueType == floatType){break;}
                yyerror("Type ERROR");
            }

            tmp->boolval = (yyvsp[(1) - (3)].value)->boolval <= (yyvsp[(3) - (3)].value)->boolval;

            assember.le();
            (yyval.value) = tmp;
        }
    break;

  case 95:
#line 848 "parser.y"
    {
            Trace("EXP '!=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
                yyerror("Type NOT MATCH ERROR");
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == intType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->intval != (yyvsp[(3) - (3)].value)->intval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == boolType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->boolval != (yyvsp[(3) - (3)].value)->boolval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == floatType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->floatval != (yyvsp[(3) - (3)].value)->floatval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == stringType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->stringval != (yyvsp[(3) - (3)].value)->stringval);
            }
            else if ((yyvsp[(1) - (3)].value)->valueType == charType){
                tmp->boolval = ((yyvsp[(1) - (3)].value)->charval != (yyvsp[(3) - (3)].value)->charval);
            }
            else{
                yyerror("EXP != EXP ERROR");
            }
            assember.ne();
            (yyval.value) = tmp;
        }
    break;

  case 96:
#line 876 "parser.y"
    {
            Trace("EXP '!' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(2) - (2)].value)->valueType != boolType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = !((yyvsp[(2) - (2)].value)->boolval);
            }

            assember.output << "ixor\n";

            (yyval.value) = tmp;
        }
    break;

  case 97:
#line 891 "parser.y"
    {
            Trace("ID");
            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (1)].sval));
            if (tmp == NULL){
                yyerror("ID DOSENT EXIST");
            }
            if (tmp->idType == arrayType){
                yyerror("ID CANT NOT BE ARRAY");
            }
            if (tmp->idType == constType){
                assember.pushConstant(tmp->value);
            }
            else if (tmp->symbolTable_index != 0){
                assember.pushLocal(tmp);
            }else{
                assember.pushGlobal(tmp);
            }
            (yyval.value) = tmp->value;
        }
    break;

  case 98:
#line 910 "parser.y"
    {
            Trace("ID [EXP]");
            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (4)].sval));
            if (tmp == NULL){
                yyerror("ID DOSENT EXIST");
            }
            if (tmp->idType != arrayType){
                yyerror("ID IS NOT A ARRAY");
            }
            if ((yyvsp[(3) - (4)].value)->valueType != intType){
                yyerror("index must be int");
            }

            (yyval.value) = tmp->arrayValue[(yyvsp[(3) - (4)].value)->intval];
            
        }
    break;

  case 99:
#line 926 "parser.y"
    {
            assember.pushConstant((yyvsp[(1) - (1)].value));
            Trace("VALUE");
            (yyval.value) = (yyvsp[(1) - (1)].value);
        }
    break;

  case 100:
#line 933 "parser.y"
    {
            Trace("string constance");
            (yyval.value) = stringValue((yyvsp[(1) - (1)].sval));
        }
    break;

  case 101:
#line 937 "parser.y"
    {
            Trace("integer constance");
            (yyval.value) = intValue((yyvsp[(1) - (1)].ival));
        }
    break;

  case 102:
#line 941 "parser.y"
    {
            Trace("bool constance");
            (yyval.value) = boolValue((yyvsp[(1) - (1)].bval));
        }
    break;

  case 103:
#line 945 "parser.y"
    {
            Trace("real number constance");
            (yyval.value) = floatValue((yyvsp[(1) - (1)].dval));
        }
    break;

  case 104:
#line 949 "parser.y"
    {
            Trace("char constance");
            (yyval.value) = charValue((yyvsp[(1) - (1)].cval));
        }
    break;

  case 105:
#line 955 "parser.y"
    {
                (yyval.type) = charType;
            }
    break;

  case 106:
#line 958 "parser.y"
    {
                (yyval.type) = stringType;
            }
    break;

  case 107:
#line 961 "parser.y"
    {
                (yyval.type) = intType;
            }
    break;

  case 108:
#line 964 "parser.y"
    {
                (yyval.type) = boolType;
            }
    break;

  case 109:
#line 967 "parser.y"
    {
                (yyval.type) = floatType;
            }
    break;


/* Line 1267 of yacc.c.  */
#line 2913 "y.tab.cpp"
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


#line 973 "parser.y"



void yyerror(string s){
    cerr << "line " << linenum << ": " << s << endl;
    exit(1);
}



int main(int argc, char* argv[]){
    if (argc == 1){
        yyin = stdin;
    }
    else if (argc == 2){
        yyin = fopen(argv[1], "r");
    }

    yyparse();
    tables.dump();
    return 0;
}

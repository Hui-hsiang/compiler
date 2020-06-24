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
     ID = 302,
     SEMICOLON = 303,
     AND = 304,
     UMIUNS = 305
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
#define ID 302
#define SEMICOLON 303
#define AND 304
#define UMIUNS 305




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include "symbolTable.hpp"
#include "lex.yy.cpp"
#define Trace(t)    if (Opt_P) cout << t << endl


symbolTableList  tables;
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
#line 13 "parser.y"
{
    int ival;
    double dval;
    bool bval;
    string* sval;
    valueInfo *value;
    idInfo *info;
    int type;
}
/* Line 193 of yacc.c.  */
#line 218 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 231 "y.tab.cpp"

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
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,     2,     2,     2,
      60,    61,    55,    53,    63,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,     2,
      51,    64,    52,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    12,    15,    16,    21,    22,    29,
      30,    31,    40,    41,    48,    49,    50,    61,    65,    67,
      71,    73,    76,    77,    79,    81,    83,    85,    87,    91,
      98,   103,   108,   111,   113,   116,   117,   122,   126,   132,
     133,   140,   151,   152,   164,   165,   166,   179,   180,   181,
     182,   196,   204,   205,   214,   215,   216,   226,   227,   228,
     229,   240,   246,   247,   254,   265,   266,   278,   280,   282,
     289,   294,   299,   302,   310,   317,   322,   326,   331,   335,
     337,   341,   343,   347,   351,   355,   359,   362,   366,   370,
     374,   378,   382,   386,   390,   394,   397,   399,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    31,    47,    58,    80,    69,    59,    -1,
      70,    -1,    70,    69,    -1,    -1,    20,    47,    71,    85,
      -1,    -1,    20,    47,    60,    61,    72,    85,    -1,    -1,
      -1,    20,    47,    73,    60,    79,    61,    74,    85,    -1,
      -1,    20,    47,    62,   110,    75,    85,    -1,    -1,    -1,
      20,    47,    60,    76,    79,    61,    62,   110,    77,    85,
      -1,    47,    62,   110,    -1,    78,    -1,    78,    63,    79,
      -1,    81,    -1,    81,    80,    -1,    -1,    82,    -1,   103,
      -1,   106,    -1,    86,    -1,   100,    -1,    47,    64,   108,
      -1,    47,    65,   108,    66,    64,   108,    -1,    32,    60,
     108,    61,    -1,    33,    60,   108,    61,    -1,    23,    47,
      -1,    35,    -1,    35,   108,    -1,    -1,    58,    84,    80,
      59,    -1,    58,    80,    59,    -1,    28,    60,   108,    61,
      83,    -1,    -1,    28,    60,   108,    61,    87,    82,    -1,
      28,    60,   108,    61,    83,    22,    60,   108,    61,    83,
      -1,    -1,    28,    60,   108,    61,    83,    22,    60,   108,
      61,    88,    82,    -1,    -1,    -1,    28,    60,   108,    61,
      89,    82,    90,    22,    60,   108,    61,    83,    -1,    -1,
      -1,    -1,    28,    60,   108,    61,    91,    82,    92,    22,
      60,   108,    61,    93,    82,    -1,    28,    60,   108,    61,
      83,    22,    83,    -1,    -1,    28,    60,   108,    61,    83,
      22,    94,    82,    -1,    -1,    -1,    28,    60,   108,    61,
      95,    82,    96,    22,    83,    -1,    -1,    -1,    -1,    28,
      60,   108,    61,    97,    82,    98,    22,    99,    82,    -1,
      42,    60,   108,    61,    83,    -1,    -1,    42,    60,   108,
      61,   101,    82,    -1,    27,    60,    47,    51,    54,    43,
      37,    43,    61,    83,    -1,    -1,    27,    60,    47,    51,
      54,    43,    37,    43,    61,   102,    82,    -1,   105,    -1,
     104,    -1,    41,    47,    62,   110,    64,   108,    -1,    41,
      47,    62,   110,    -1,    41,    47,    64,   108,    -1,    41,
      47,    -1,    41,    47,    62,   110,    65,    43,    66,    -1,
      40,    47,    62,   110,    64,   108,    -1,    40,    47,    64,
     108,    -1,    47,    60,    61,    -1,    47,    60,   107,    61,
      -1,   108,    63,   107,    -1,   108,    -1,    60,   108,    61,
      -1,   106,    -1,   108,    53,   108,    -1,   108,    54,   108,
      -1,   108,    55,   108,    -1,   108,    56,   108,    -1,    54,
     108,    -1,   108,    10,   108,    -1,   108,    49,   108,    -1,
     108,    51,   108,    -1,   108,    52,   108,    -1,   108,     7,
     108,    -1,   108,     6,   108,    -1,   108,     5,   108,    -1,
     108,     8,   108,    -1,    50,   108,    -1,    47,    -1,    47,
      65,   108,    66,    -1,   109,    -1,    46,    -1,    43,    -1,
      45,    -1,    44,    -1,    16,    -1,    36,    -1,    29,    -1,
      14,    -1,    26,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    47,    47,    57,    57,    64,    64,    75,    75,    86,
      86,    86,    96,    96,   107,   110,   107,   123,   131,   131,
     133,   136,   139,   144,   144,   144,   144,   144,   146,   147,
     148,   149,   150,   151,   152,   157,   157,   165,   169,   175,
     175,   186,   192,   192,   203,   210,   203,   219,   226,   230,
     219,   241,   247,   247,   259,   266,   259,   273,   280,   284,
     273,   292,   298,   298,   309,   312,   312,   322,   322,   327,
     339,   346,   353,   360,   369,   381,   391,   405,   409,   412,
     417,   421,   422,   438,   454,   470,   486,   502,   515,   527,
     539,   551,   575,   587,   599,   623,   635,   646,   664,   670,
     674,   678,   682,   688,   691,   694,   697,   700
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
  "WHILE", "INT_CONST", "REAL_CONST", "BOOL_CONST", "STR_CONST", "ID",
  "SEMICOLON", "AND", "'!'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "UMIUNS", "'{'", "'}'", "'('", "')'", "':'", "','", "'='", "'['", "']'",
  "$accept", "PROGRAM", "METHODS", "METHOD", "@1", "@2", "@3", "@4", "@5",
  "@6", "@7", "ARG", "comma_seperated_ARG", "STMTS", "STMT", "SIMPLE",
  "BLOCK", "@8", "FUC_BLOCK", "CONDITIONAL", "@9", "@10", "@11", "@12",
  "@13", "@14", "@15", "@16", "@17", "@18", "@19", "@20", "@21", "LOOP",
  "@22", "@23", "V_DEC", "VAR_DEC", "CONST_DEC", "FUNCTION_INVOCATION",
  "comma_seperated_EXP", "EXP", "VALUE", "DATA_TYPE", 0
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
      33,    60,    62,    43,    45,    42,    47,   305,   123,   125,
      40,    41,    58,    44,    61,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    71,    70,    72,    70,    73,
      74,    70,    75,    70,    76,    77,    70,    78,    79,    79,
      80,    80,    80,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    84,    83,    85,    86,    87,
      86,    86,    88,    86,    89,    90,    86,    91,    92,    93,
      86,    86,    94,    86,    95,    96,    86,    97,    98,    99,
      86,   100,   101,   100,   100,   102,   100,   103,   103,   104,
     104,   104,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   109,   109,   110,   110,   110,   110,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     0,     4,     0,     6,     0,
       0,     8,     0,     6,     0,     0,    10,     3,     1,     3,
       1,     2,     0,     1,     1,     1,     1,     1,     3,     6,
       4,     4,     2,     1,     2,     0,     4,     3,     5,     0,
       6,    10,     0,    11,     0,     0,    12,     0,     0,     0,
      13,     7,     0,     8,     0,     0,     9,     0,     0,     0,
      10,     5,     0,     6,    10,     0,    11,     1,     1,     6,
       4,     4,     2,     7,     6,     4,     3,     4,     3,     1,
       3,     1,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    22,     0,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,    20,    23,    26,
      27,    24,    68,    67,    25,    32,     0,     0,     0,     0,
     100,   102,   101,    99,    96,     0,     0,     0,    81,    34,
      98,     0,    72,     0,     0,     0,     0,     0,     0,     3,
      21,     0,     0,     0,     0,     0,    95,    86,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,     0,    79,    28,
       0,     5,     2,     4,     0,    39,    30,    31,     0,    80,
      93,    92,    91,    94,    87,    88,    89,    90,    82,    83,
      84,    85,   106,   103,   107,   105,   104,     0,    75,    70,
      71,    62,    77,     0,     0,    14,     0,     0,     0,     0,
      35,    38,     0,     0,     0,     0,     0,    97,     0,     0,
       0,    61,     0,    78,     0,     7,     0,    12,    22,     6,
       0,     0,    22,    52,     0,    40,    45,    48,    55,    58,
      74,    69,     0,    63,    29,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,    73,     8,     0,     0,     0,    13,    37,    10,     0,
      36,     0,    53,     0,     0,     0,    59,    17,    19,     0,
       0,    65,    42,     0,     0,    56,     0,    15,    11,    64,
       0,    41,     0,     0,     0,    60,     0,    66,    43,     0,
      49,    16,    46,     0,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    48,    49,   117,   155,   118,   190,   159,   136,
     206,   157,   158,    16,    17,    18,   121,   142,   139,    19,
     122,   202,   123,   167,   124,   168,   213,   166,   125,   169,
     126,   170,   196,    20,   132,   200,    21,    22,    23,    38,
      77,    78,    40,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
     -17,   -27,    60,     6,  -145,    49,    31,    20,    37,    38,
      40,   346,    36,    52,    41,   -37,    82,    49,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,    58,   346,   346,   346,
    -145,  -145,  -145,  -145,   -22,   346,   346,   346,  -145,   297,
    -145,   -56,   -52,   346,   334,   346,   346,    59,    48,    82,
    -145,    57,   158,   179,   193,   346,   320,  -145,   210,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,    -7,   346,    -7,   346,   231,  -145,    54,   141,   297,
     106,   -21,  -145,  -145,    56,    61,  -145,  -145,   125,  -145,
      39,    39,    39,    39,   314,   320,    39,    39,    15,    15,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,    62,   297,     9,
     297,    61,  -145,   346,    63,    64,    -7,    71,    76,    78,
    -145,   100,    -2,    -2,    -2,    -2,    -2,  -145,   346,   346,
      94,  -145,    -2,  -145,   346,  -145,    93,  -145,    49,  -145,
      93,   104,    49,   -18,    23,  -145,  -145,  -145,  -145,  -145,
     297,   297,    84,  -145,   297,    71,    80,    81,    91,    71,
      95,   108,   124,   111,   346,  -145,    -2,   149,   151,   153,
     166,  -145,  -145,    -7,    93,   140,  -145,  -145,  -145,   144,
    -145,   245,  -145,   146,   148,    61,  -145,  -145,  -145,    -7,
      71,    61,    61,   346,   346,  -145,    -2,  -145,  -145,  -145,
      -2,  -145,    -2,   262,   283,  -145,    71,  -145,  -145,    61,
    -145,  -145,  -145,    -2,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   172,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -138,   -14,  -145,   -57,  -106,  -145,  -144,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,    -4,
     109,   -11,  -145,   -69
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      39,    24,   161,    50,   109,   131,    71,   102,    72,   103,
      73,   172,    74,    24,     1,   176,    52,    53,    54,   104,
       3,     6,   105,    44,    56,    57,    58,    45,    46,   106,
       9,    10,    75,    11,    79,    80,   188,   165,    44,   115,
     120,   116,   164,    55,    88,   144,   198,   137,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
       4,   108,   211,   110,     5,   145,   146,   147,   148,   149,
      69,    70,     6,   129,   130,   153,     7,     8,    25,   195,
      26,     9,    10,    41,    11,   199,   201,    45,    46,    12,
      13,    14,    67,    68,    69,    70,    15,    27,    28,    42,
      29,    43,    47,   212,   187,    51,    81,    82,    84,   182,
     119,    59,    60,    61,    62,   112,    63,   150,   151,   120,
     197,   141,   143,   154,   160,   135,   128,   134,   163,   138,
      59,    60,    61,    62,    24,    63,   140,   152,    24,   205,
     156,   162,   173,   207,   174,   208,    59,    60,    61,    62,
     171,    63,   175,   181,   177,    64,   214,    65,    66,    67,
      68,    69,    70,    59,    60,    61,    62,   179,    63,   178,
     180,   183,   114,   184,    64,   185,    65,    66,    67,    68,
      69,    70,   203,   204,    59,    60,    61,    62,   186,    63,
      64,   127,    65,    66,    67,    68,    69,    70,    59,    60,
      61,    62,   189,    63,   113,   191,   193,    64,   194,    65,
      66,    67,    68,    69,    70,    59,    60,    61,    62,    85,
      63,    83,   133,     0,     0,     0,     0,     0,    64,     0,
      65,    66,    67,    68,    69,    70,    59,    60,    61,    62,
      86,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      59,    60,    61,    62,    87,    63,     0,     0,     0,    64,
       0,    65,    66,    67,    68,    69,    70,    59,    60,    61,
      62,    89,    63,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,    66,    67,    68,    69,    70,    59,    60,
      61,    62,   111,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    59,    60,    61,    62,   192,    63,     0,     0,
       0,    64,     0,    65,    66,    67,    68,    69,    70,    59,
      60,    61,    62,   209,     0,    59,    60,    61,    62,     0,
       0,     0,    64,     0,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,   210,     0,    64,     0,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,    66,    67,    68,    69,
      70,    65,    66,    67,    68,    69,    70,    30,    31,    32,
      33,    34,     0,     0,    35,     0,     0,     0,    36,    30,
      31,    32,    33,    34,    37,    76,    35,     0,     0,     0,
      36,     0,     0,     0,     0,     0,    37
};

static const yytype_int16 yycheck[] =
{
      11,     5,   140,    17,    73,   111,    62,    14,    64,    16,
      62,   155,    64,    17,    31,   159,    27,    28,    29,    26,
      47,    23,    29,    60,    35,    36,    37,    64,    65,    36,
      32,    33,    43,    35,    45,    46,   174,   143,    60,    60,
      58,    62,    60,    65,    55,    47,   190,   116,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    72,   206,    74,    58,   122,   123,   124,   125,   126,
      55,    56,    23,    64,    65,   132,    27,    28,    47,   185,
      60,    32,    33,    47,    35,   191,   192,    64,    65,    40,
      41,    42,    53,    54,    55,    56,    47,    60,    60,    47,
      60,    60,    20,   209,   173,    47,    47,    59,    51,   166,
      54,     5,     6,     7,     8,    61,    10,   128,   129,    58,
     189,    43,    22,   134,   138,    61,    64,    64,   142,    58,
       5,     6,     7,     8,   138,    10,    60,    43,   142,   196,
      47,    37,    62,   200,    63,   202,     5,     6,     7,     8,
      66,    10,    61,   164,    59,    49,   213,    51,    52,    53,
      54,    55,    56,     5,     6,     7,     8,    43,    10,    61,
      59,    22,    66,    22,    49,    22,    51,    52,    53,    54,
      55,    56,   193,   194,     5,     6,     7,     8,    22,    10,
      49,    66,    51,    52,    53,    54,    55,    56,     5,     6,
       7,     8,    62,    10,    63,    61,    60,    49,    60,    51,
      52,    53,    54,    55,    56,     5,     6,     7,     8,    61,
      10,    49,   113,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,     5,     6,     7,     8,
      61,    10,    49,    -1,    51,    52,    53,    54,    55,    56,
       5,     6,     7,     8,    61,    10,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,     5,     6,     7,
       8,    61,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,     5,     6,
       7,     8,    61,    10,    49,    -1,    51,    52,    53,    54,
      55,    56,     5,     6,     7,     8,    61,    10,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,     5,
       6,     7,     8,    61,    -1,     5,     6,     7,     8,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    51,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    -1,    -1,    50,    -1,    -1,    -1,    54,    43,
      44,    45,    46,    47,    60,    61,    50,    -1,    -1,    -1,
      54,    -1,    -1,    -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    68,    47,     0,    58,    23,    27,    28,    32,
      33,    35,    40,    41,    42,    47,    80,    81,    82,    86,
     100,   103,   104,   105,   106,    47,    60,    60,    60,    60,
      43,    44,    45,    46,    47,    50,    54,    60,   106,   108,
     109,    47,    47,    60,    60,    64,    65,    20,    69,    70,
      80,    47,   108,   108,   108,    65,   108,   108,   108,     5,
       6,     7,     8,    10,    49,    51,    52,    53,    54,    55,
      56,    62,    64,    62,    64,   108,    61,   107,   108,   108,
     108,    47,    59,    69,    51,    61,    61,    61,   108,    61,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,    14,    16,    26,    29,    36,   110,   108,   110,
     108,    61,    61,    63,    66,    60,    62,    71,    73,    54,
      58,    83,    87,    89,    91,    95,    97,    66,    64,    64,
      65,    83,   101,   107,    64,    61,    76,   110,    58,    85,
      60,    43,    84,    22,    47,    82,    82,    82,    82,    82,
     108,   108,    43,    82,   108,    72,    47,    78,    79,    75,
      80,    79,    37,    80,    60,    83,    94,    90,    92,    96,
      98,    66,    85,    62,    63,    61,    85,    59,    61,    43,
      59,   108,    82,    22,    22,    22,    22,   110,    79,    62,
      74,    61,    61,    60,    60,    83,    99,   110,    85,    83,
     102,    83,    88,   108,   108,    82,    77,    82,    82,    61,
      61,    85,    83,    93,    82
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
#line 49 "parser.y"
    {
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (6)].sval), objectType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 5:
#line 64 "parser.y"
    {
            tables.push();
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (2)].sval), functionType);
            if (result == -1){
                yyerror("id has been uesd");
            }
        }
    break;

  case 6:
#line 71 "parser.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 7:
#line 75 "parser.y"
    {
            tables.push();
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (4)].sval), functionType);
            if (result == -1){
                yyerror("id has been uesd");
            }
        }
    break;

  case 8:
#line 82 "parser.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 9:
#line 86 "parser.y"
    {tables.push();}
    break;

  case 10:
#line 86 "parser.y"
    {
            Trace("ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (6)].sval), functionType);
            if (result == -1){
                yyerror("id has been uesd");
            }
        }
    break;

  case 11:
#line 92 "parser.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 12:
#line 96 "parser.y"
    {
            tables.push();
            Trace("NO ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (4)].sval), functionType , (yyvsp[(4) - (4)].type));
            if (result == -1){
                yyerror("id has been uesd");
            }
        }
    break;

  case 13:
#line 103 "parser.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 14:
#line 107 "parser.y"
    {
            Trace("hi");
            tables.push(); 
        }
    break;

  case 15:
#line 110 "parser.y"
    {
            Trace("ARG METHOD");
            int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (8)].sval), functionType, (yyvsp[(8) - (8)].type));
            if (result == -1){
                yyerror("id has been uesd");
            } 
        }
    break;

  case 16:
#line 116 "parser.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 17:
#line 123 "parser.y"
    {
            int result =  tables.list[tables.top].insert(*(yyvsp[(1) - (3)].sval),variableType, (yyvsp[(3) - (3)].type));
            if (result == -1){
                yyerror("id has been uesd");
            }
        }
    break;

  case 20:
#line 133 "parser.y"
    {
            Trace("STMT");
        }
    break;

  case 21:
#line 136 "parser.y"
    {
            Trace("STMT STMTS");
        }
    break;

  case 28:
#line 146 "parser.y"
    {Trace("ID = EXP");}
    break;

  case 33:
#line 151 "parser.y"
    {Trace("return");}
    break;

  case 34:
#line 152 "parser.y"
    {Trace("return EXP");}
    break;

  case 35:
#line 157 "parser.y"
    {
            Trace("BLOCK");
            tables.push();
        }
    break;

  case 36:
#line 161 "parser.y"
    { 
            tables.dump();
            tables.pop();
        }
    break;

  case 37:
#line 165 "parser.y"
    { Trace("FUN_BLOCK");
}
    break;

  case 38:
#line 169 "parser.y"
    {
                    Trace("IF CONDITION");
                    if ((yyvsp[(3) - (5)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 39:
#line 175 "parser.y"
    {
                    Trace("IF CONDITION");
                    if ((yyvsp[(3) - (4)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    tables.push();
                }
    break;

  case 40:
#line 182 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 41:
#line 186 "parser.y"
    {
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (10)].value)->valueType != boolType || (yyvsp[(8) - (10)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 42:
#line 192 "parser.y"
    {
                    tables.push();
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (9)].value)->valueType != boolType || (yyvsp[(8) - (9)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 43:
#line 199 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 44:
#line 203 "parser.y"
    {
                    tables.push();
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (4)].value)->valueType != boolType ){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 45:
#line 210 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 46:
#line 214 "parser.y"
    {
                    if ((yyvsp[(3) - (12)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 47:
#line 219 "parser.y"
    {
                    tables.push();
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (4)].value)->valueType != boolType ){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 48:
#line 226 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 49:
#line 230 "parser.y"
    {
                    tables.push();
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (11)].value)->valueType != boolType ){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 50:
#line 237 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 51:
#line 241 "parser.y"
    {
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (7)].value)->valueType != boolType){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 52:
#line 247 "parser.y"
    {
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (6)].value)->valueType != boolType ){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    tables.push();
                }
    break;

  case 53:
#line 254 "parser.y"
    {
                    
                    tables.dump();
                    tables.pop();
                }
    break;

  case 54:
#line 259 "parser.y"
    {
                    tables.push();
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (4)].value)->valueType != boolType ){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                }
    break;

  case 55:
#line 266 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 56:
#line 270 "parser.y"
    {
                    
                }
    break;

  case 57:
#line 273 "parser.y"
    {
                    Trace("IF ELSE CONDITION");
                    if ((yyvsp[(3) - (4)].value)->valueType != boolType ){
                        yyerror("CONDITION SHOULD BE BOOL TYPE");
                    }
                    tables.push();
                }
    break;

  case 58:
#line 280 "parser.y"
    {
                    tables.dump();
                    tables.pop();
                }
    break;

  case 59:
#line 284 "parser.y"
    {
                    tables.push();
                }
    break;

  case 60:
#line 286 "parser.y"
    {
                    
                    tables.dump();
                    tables.pop();
                }
    break;

  case 61:
#line 292 "parser.y"
    {
            Trace("WHILE LOOP");
            if ((yyvsp[(3) - (5)].value)->valueType != boolType ){
                yyerror("CONDITION SHOULD BE BOOL TYPE");
            }
        }
    break;

  case 62:
#line 298 "parser.y"
    {
            tables.push();
            Trace("WHILE LOOP");
            if ((yyvsp[(3) - (4)].value)->valueType != boolType ){
                yyerror("CONDITION SHOULD BE BOOL TYPE");
            }
        }
    break;

  case 63:
#line 305 "parser.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 64:
#line 309 "parser.y"
    {
            Trace("FOR LOOP");
        }
    break;

  case 65:
#line 312 "parser.y"
    {
            tables.push();
            Trace("FOR LOOP");
        }
    break;

  case 66:
#line 316 "parser.y"
    {
            
            tables.dump();
            tables.pop();
        }
    break;

  case 69:
#line 327 "parser.y"
    {
                Trace("VAR ID : DATA_TYPE = EXP");
                if ((yyvsp[(4) - (6)].type) != (yyvsp[(6) - (6)].value)->valueType){
                    if((yyvsp[(4) - (6)].type) != floatType && (yyvsp[(6) - (6)].value)->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (6)].sval), variableType, (yyvsp[(6) - (6)].value));
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 70:
#line 339 "parser.y"
    {
                Trace("VAR ID : DATA_TYPE");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (4)].sval), variableType, (yyvsp[(4) - (4)].type));
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 71:
#line 346 "parser.y"
    {
                Trace("VAR ID  = EXP");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (4)].sval), variableType, (yyvsp[(4) - (4)].value));
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 72:
#line 353 "parser.y"
    {
                Trace("VAR ID");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (2)].sval), variableType);
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 73:
#line 360 "parser.y"
    {
                Trace("VAR ID : DATA_TYPE [NUM]");
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (7)].sval), arrayType, (yyvsp[(4) - (7)].type), (yyvsp[(6) - (7)].ival));
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 74:
#line 369 "parser.y"
    {
                Trace("VAL ID : DATA_TYPE = EXP");
                if ((yyvsp[(4) - (6)].type) != (yyvsp[(6) - (6)].value)->valueType){
                    if((yyvsp[(4) - (6)].type) != floatType && (yyvsp[(6) - (6)].value)->valueType != floatType){
                        yyerror("TYPE ERROR");
                    }
                }
                int result =  tables.list[tables.top].insert(*(yyvsp[(2) - (6)].sval), constType, (yyvsp[(6) - (6)].value));
                if (result == -1){
                   yyerror("id has been uesd");
                }
            }
    break;

  case 75:
#line 381 "parser.y"
    {
                Trace("VAL ID = EXP");
                int result = tables.list[tables.top].insert(*(yyvsp[(2) - (4)].sval) ,constType, (yyvsp[(4) - (4)].value));
                
                if (result == -1){
                    yyerror("id has been uesd");
                }
            }
    break;

  case 76:
#line 391 "parser.y"
    {
                            Trace("ID()");
                            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (3)].sval));
                            if (tmp == NULL){
                                yyerror("CANT FIND ID");
                            }
                            if(tmp->idType != functionType){
                                yyerror("ID IS NOT A FUNCTION");
                            }
                            

   

                        }
    break;

  case 77:
#line 405 "parser.y"
    {
                            Trace("ID COMMA SEPERATED EXP");
                        }
    break;

  case 78:
#line 409 "parser.y"
    {
                            Trace("COMMA SEPREATED EXP");
                        }
    break;

  case 79:
#line 412 "parser.y"
    {
                            Trace("EXP");
                        }
    break;

  case 80:
#line 417 "parser.y"
    {
            Trace("( EXP )");
            (yyval.value) = (yyvsp[(2) - (3)].value);
        }
    break;

  case 82:
#line 422 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 83:
#line 438 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 84:
#line 454 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 85:
#line 470 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 86:
#line 486 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 87:
#line 502 "parser.y"
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
            (yyval.value) = tmp;

        }
    break;

  case 88:
#line 515 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 89:
#line 527 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 90:
#line 539 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 91:
#line 551 "parser.y"
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
            else{
                yyerror("EXP == EXP ERROR");
            }
            (yyval.value) = tmp;
        }
    break;

  case 92:
#line 575 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 93:
#line 587 "parser.y"
    {
            Trace("EXP '<=' EXP");
            valueInfo* tmp = new valueInfo();
            tmp->valueType = boolType;
            if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
                yyerror("Type ERROR");
            }
            else{
                tmp->boolval = (yyvsp[(1) - (3)].value)->boolval <= (yyvsp[(3) - (3)].value)->boolval;
            }
            (yyval.value) = tmp;
        }
    break;

  case 94:
#line 599 "parser.y"
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
            else{
                yyerror("EXP != EXP ERROR");
            }
            (yyval.value) = tmp;
        }
    break;

  case 95:
#line 623 "parser.y"
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
            (yyval.value) = tmp;
        }
    break;

  case 96:
#line 635 "parser.y"
    {
            Trace("ID");
            idInfo* tmp = tables.lookup(*(yyvsp[(1) - (1)].sval));
            if (tmp == NULL){
                yyerror("ID DOSENT EXIST");
            }
            if (tmp->idType == arrayType){
                yyerror("ID CANT NOT BE ARRAY");
            }
            (yyval.value) = tmp->value;
        }
    break;

  case 97:
#line 646 "parser.y"
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
            if ((yyvsp[(3) - (4)].value)->intval >= tmp->arraySize || (yyvsp[(3) - (4)].value)->intval < 0){
                yyerror("access out of range");
            }
            (yyval.value) = tmp->arrayValue[(yyvsp[(3) - (4)].value)->intval];
            
        }
    break;

  case 98:
#line 664 "parser.y"
    {
            Trace("VALUE");
            (yyval.value) = (yyvsp[(1) - (1)].value);
        }
    break;

  case 99:
#line 670 "parser.y"
    {
            Trace("string constance");
            (yyval.value) = stringValue((yyvsp[(1) - (1)].sval));
        }
    break;

  case 100:
#line 674 "parser.y"
    {
            Trace("integer constance");
            (yyval.value) = intValue((yyvsp[(1) - (1)].ival));
        }
    break;

  case 101:
#line 678 "parser.y"
    {
            Trace("bool constance");
            (yyval.value) = boolValue((yyvsp[(1) - (1)].bval));
        }
    break;

  case 102:
#line 682 "parser.y"
    {
            Trace("real number constance");
            (yyval.value) = floatValue((yyvsp[(1) - (1)].dval));
        }
    break;

  case 103:
#line 688 "parser.y"
    {
                (yyval.type) = charType;
            }
    break;

  case 104:
#line 691 "parser.y"
    {
                (yyval.type) = stringType;
            }
    break;

  case 105:
#line 694 "parser.y"
    {
                (yyval.type) = intType;
            }
    break;

  case 106:
#line 697 "parser.y"
    {
                (yyval.type) = boolType;
            }
    break;

  case 107:
#line 700 "parser.y"
    {
                (yyval.type) = floatType;
            }
    break;


/* Line 1267 of yacc.c.  */
#line 2632 "y.tab.cpp"
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


#line 706 "parser.y"



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

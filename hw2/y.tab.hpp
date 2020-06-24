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
/* Line 1529 of yacc.c.  */
#line 159 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


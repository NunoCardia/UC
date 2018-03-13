/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BITWISEAND = 258,
    BITWISEOR = 259,
    BITWISEXOR = 260,
    AND = 261,
    OR = 262,
    EQ = 263,
    ASSIGN = 264,
    NOT = 265,
    NE = 266,
    GT = 267,
    LT = 268,
    GE = 269,
    LE = 270,
    COMMA = 271,
    SEMI = 272,
    LBRACE = 273,
    RBRACE = 274,
    LPAR = 275,
    RPAR = 276,
    PLUS = 277,
    MINUS = 278,
    MUL = 279,
    DIV = 280,
    MOD = 281,
    INT = 282,
    CHAR = 283,
    VOID = 284,
    IF = 285,
    ELSE = 286,
    RETURN = 287,
    RESERVED = 288,
    SHORT = 289,
    DOUBLE = 290,
    WHILE = 291,
    ID = 292,
    INTLIT = 293,
    CHRLIT = 294,
    REALLIT = 295
  };
#endif
/* Tokens.  */
#define BITWISEAND 258
#define BITWISEOR 259
#define BITWISEXOR 260
#define AND 261
#define OR 262
#define EQ 263
#define ASSIGN 264
#define NOT 265
#define NE 266
#define GT 267
#define LT 268
#define GE 269
#define LE 270
#define COMMA 271
#define SEMI 272
#define LBRACE 273
#define RBRACE 274
#define LPAR 275
#define RPAR 276
#define PLUS 277
#define MINUS 278
#define MUL 279
#define DIV 280
#define MOD 281
#define INT 282
#define CHAR 283
#define VOID 284
#define IF 285
#define ELSE 286
#define RETURN 287
#define RESERVED 288
#define SHORT 289
#define DOUBLE 290
#define WHILE 291
#define ID 292
#define INTLIT 293
#define CHRLIT 294
#define REALLIT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 91 "uccompiler.y" /* yacc.c:1915  */

    char*   id;
    char*   intlit;
    char*   chrlit;
    char*   reallit;
    struct _tree_node* node;

#line 142 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

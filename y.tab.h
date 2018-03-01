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
    RESERVED = 258,
    WHILE = 259,
    BITWISEAND = 260,
    AND = 261,
    BITWISEOR = 262,
    OR = 263,
    BITWISEXOR = 264,
    EQ = 265,
    ASSIGN = 266,
    NOT = 267,
    NE = 268,
    GT = 269,
    LT = 270,
    GE = 271,
    LE = 272,
    COMMA = 273,
    SEMI = 274,
    LBRACE = 275,
    RBRACE = 276,
    LPAR = 277,
    RPAR = 278,
    PLUS = 279,
    MINUS = 280,
    MUL = 281,
    DIV = 282,
    MOD = 283,
    INT = 284,
    CHAR = 285,
    VOID = 286,
    IF = 287,
    SHORT = 288,
    DOUBLE = 289,
    ELSE = 290,
    RETURN = 291,
    ID = 292,
    INTLIT = 293,
    CHRLIT = 294,
    REALLIT = 295,
    AST = 297,
    AMP = 301,
    LSQ = 302,
    RSQ = 303,
    expression = 304
  };
#endif
/* Tokens.  */
#define RESERVED 258
#define WHILE 259
#define BITWISEAND 260
#define AND 261
#define BITWISEOR 262
#define OR 263
#define BITWISEXOR 264
#define EQ 265
#define ASSIGN 266
#define NOT 267
#define NE 268
#define GT 269
#define LT 270
#define GE 271
#define LE 272
#define COMMA 273
#define SEMI 274
#define LBRACE 275
#define RBRACE 276
#define LPAR 277
#define RPAR 278
#define PLUS 279
#define MINUS 280
#define MUL 281
#define DIV 282
#define MOD 283
#define INT 284
#define CHAR 285
#define VOID 286
#define IF 287
#define SHORT 288
#define DOUBLE 289
#define ELSE 290
#define RETURN 291
#define ID 292
#define INTLIT 293
#define CHRLIT 294
#define REALLIT 295
#define AST 297
#define AMP 301
#define LSQ 302
#define RSQ 303
#define expression 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 59 "uccompiler.y" /* yacc.c:1915  */

    char*   id;
    char*   intlit;
    char*   chrlit;
    char*   reallit;
    struct _tree_node* node;

#line 152 "y.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

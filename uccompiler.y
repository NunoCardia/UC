%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "ast.h"

    extern int yylineno;
    extern char * yytext;

    extern int columnNumber;

    void print(char *s);
    void yyerror (char *s);
    extern int yylex();

    int flag_error = 0;
    int stat_list = 0;

    tree_node* root = NULL;
%}

%token BITWISEAND
%token BITWISEOR
%token BITWISEXOR
%token AND
%token OR
%token EQ
%token ASSIGN
%token NOT
%token NE
%token GT
%token LT
%token GE
%token LE
%token COMMA
%token SEMI
%token LBRACE
%token RBRACE
%token LPAR
%token RPAR
%token PLUS
%token MINUS
%token MUL
%token DIV
%token MOD
%token INT
%token CHAR
%token VOID
%token IF
%token ELSE
%token RETURN
%token RESERVED
%token SHORT
%token DOUBLE
%token WHILE

%token <id> ID
%token <intlit> INTLIT
%token <chrlit> CHRLIT
%token <reallit> REALLIT

%type <node> Start
%type <node> Restart
%type <node> FunctionDefinition
%type <node> FunctionDeclaration
%type <node> FunctionDeclarator
%type <node> FunctionBody
%type <node> Declaration
%type <node> Redeclaration
%type <node> TypeSpec
%type <node> Declarator
%type <node> CommaDeclarator
%type <node> Statement
%type <node> ParameterList
%type <node> ParameterDeclaration
%type <node> CommaParameterDeclaration
%type <node> ZUAssignExpr
%type <node> StatementSpecial
%type <node> StatList
%type <node> ReSpecialStatement
%type <node> Restatement
%type <node> Expr
%type <node> ExprSpecial
%type <node> ZUExprZMComma
%type <node> ZMComma
%type <node> ZUid
%type <node> ZUExpr
%type <node> Empty


%union{
    char*   id;
    char*   intlit;
    char*   chrlit;
    char*   reallit;
    struct _tree_node* node;
}


%left COMMA
%right ASSIGN
%left OR
%left AND
%left BITWISEOR
%left BITWISEXOR
%left EQ NE
%left GE LE GT LT
%left PLUS MINUS
%left MUL DIV MOD
%right NOT BITWISEAND
%left LPAR RPAR LBRACE RBRACE
%nonassoc ELSE

%%

Start:  FunctionDefinition Restart                                              {}
    |   FunctionDeclaration Restart                                             {}
    |   Declaration Restart                                                     {}
    ;

Restart:    Empty                                                               {}
    |       FunctionDefinition Restart                                          {}
    |       FunctionDeclaration Restart                                         {}
    |       Declaration Restart                                                 {}
    ;


FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody                    {}
                ;


FunctionDeclaration: TypeSpec FunctionDeclarator SEMI                           {}
                ;


FunctionDeclarator: ID LPAR ParameterList RPAR                                  {}
                ;


FunctionBody: LBRACE Redeclaration ReSpecialStatement  RBRACE                   {}
        |     LBRACE error  RBRACE                                              {}
        ;


ParameterList: ParameterDeclaration CommaParameterDeclaration                   {}
            ;


ParameterDeclaration: TypeSpec ZUid                                             {}
                ;

CommaParameterDeclaration:COMMA ParameterDeclaration CommaParameterDeclaration  {}
                    |     Empty                                                 {}
                    ;


Declaration:    TypeSpec Declarator CommaDeclarator SEMI                        {}
        |       error SEMI                                                      {}
        ;

Redeclaration:  Empty                                                           {}
        |       Declaration Redeclaration                                       {}
        ;


TypeSpec:   INT                                                                 {}
    |       CHAR                                                                {}
    |       VOID                                                                {}
    |       SHORT                                                               {}
    |       DOUBLE                                                              {}
    ;


Declarator: ID ZUAssignExpr                                                     {}
        ;

ZUAssignExpr: ASSIGN Expr                                                       {}
        | Empty                                                                 {}
        ;

CommaDeclarator:    Empty                                                       {}
            |       COMMA Declarator CommaDeclarator                            {}
            ;


Statement:      error SEMI                                                      {}
        |       StatementSpecial                                                {}
        ;

StatementSpecial:   ZUExpr SEMI                                                 {}
        |           LBRACE StatList RBRACE                                      {}
        |           LBRACE Statement RBRACE                                     {}
        |           LBRACE RBRACE                                               {}
        |           LBRACE error RBRACE                                         {}
        |           IF LPAR Expr RPAR Statement                                 {}
        |           IF LPAR Expr RPAR Statement ELSE Statement                  {}
        |           WHILE LPAR Expr RPAR Statement                              {}
        |           RETURN ZUExpr SEMI                                          {}
        ;


StatList:       Statement Statement Restatement                                 {}
    ;

ReSpecialStatement: Empty                                                       {}

                |   StatementSpecial ReSpecialStatement                         {}
                ;

Restatement:    Empty                                                           {}

        |       Statement Restatement                                           {}
        ;

Expr:    ExprSpecial                                                            {}
    |    Expr COMMA ExprSpecial                                                 {}
    ;

ExprSpecial:    ExprSpecial ASSIGN ExprSpecial                                  {}
        |       ExprSpecial AND ExprSpecial                                     {}
        |       ExprSpecial OR ExprSpecial                                      {}
        |       ExprSpecial BITWISEAND ExprSpecial                              {}
        |       ExprSpecial BITWISEOR ExprSpecial                               {}
        |       ExprSpecial BITWISEXOR ExprSpecial                              {}
        |       ExprSpecial EQ ExprSpecial                                      {}
        |       ExprSpecial NE ExprSpecial                                      {}
        |       ExprSpecial LT ExprSpecial                                      {}
        |       ExprSpecial GT ExprSpecial                                      {}
        |       ExprSpecial LE ExprSpecial                                      {}
        |       ExprSpecial GE ExprSpecial                                      {}
        |       ExprSpecial PLUS ExprSpecial                                    {}
        |       ExprSpecial MINUS ExprSpecial                                   {}
        |       ExprSpecial MUL ExprSpecial                                     {}
        |       ExprSpecial DIV ExprSpecial                                     {}
        |       ExprSpecial MOD ExprSpecial                                     {}
        |       NOT ExprSpecial                                                 {}
        |       MINUS ExprSpecial                                               {}
        |       PLUS ExprSpecial                                                {}
        |       MUL ExprSpecial                                                 {}
        |       ID                                                              {}
        |       INTLIT                                                          {}
        |       CHRLIT                                                          {}
        |       REALLIT                                                         {}
        |       LPAR Expr RPAR                                                  {}
        |       LPAR error RPAR                                                 {}
        |       ID LPAR ZUExprZMComma RPAR                                      {}
        |       ID LPAR error RPAR                                              {}
        ;

ZUExprZMComma:  Empty                                                           {}
            |   ExprSpecial ZMComma                                             {}
            ;

ZMComma:    Empty                                                               {}
    |       COMMA ExprSpecial ZMComma                                           {}
    ;

 //Caracteres repetidos


 //Zero ou um ID
ZUid:   Empty                                                                   {}
    |   ID                                                                      {}
    ;

ZUExpr: Empty                                                                   {}
    |   Expr                                                                    {}
    ;

 // Carateres especiais

Empty:                                                                          {}
    ;

%%

/* A função main() está do lado do lex */

void yyerror (char *s) {

    flag_error = 1;

    printf ("Line %d, col %d: %s: %s\n", yylineno, (int)(columnNumber - strlen(yytext)), s, yytext);
}

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

%token RESERVED
%token WHILE
%token BITWISEAND
%token AND
%token BITWISEOR
%token OR
%token BITWISEXOR
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
%token SHORT
%token DOUBLE
%token ELSE
%token RETURN


%token <id> ID
%token <intlit> INTLIT
%token <chrlit> CHRLIT
%token <reallit> REALLIT

%union{
    char*   id;
    char*   intlit;
    char*   chrlit;
    char*   reallit;
    struct _tree_node* node;
}

%nonassoc "then"


%left COMMA
%right ASSIGN
%left OR
%left AND
%left EQ NE
%left GE LE GT LT
%left PLUS MINUS
%left AST DIV MOD
%nonassoc "pos" "neg" "pointer"
%right NOT AMP
%left LPAR RPAR LSQ RSQ LBRACE RBRACE
%nonassoc ELSE

%token expression

%%
//calc expression so estao aqui para isto nao dar erro
calc : expression {}

%%

void yyerror (char *s) {

    flag_error = 1;

    printf ("Line %d, col %d: %s: %s\n", yylineno, (int)(columnNumber - strlen(yytext)), s, yytext);
}

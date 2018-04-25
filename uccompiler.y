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
    tree_node* auxId = NULL;
    tree_node* auxNull = NULL;
    tree_node* auxIntLit = NULL;
    tree_node* auxChrLit = NULL;
    tree_node* auxStrLit = NULL;
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
%type <node> Expr
%type <node> ExprSpecial
%type <node> ZUExprZMComma
%type <node> ZMComma
%type <node> ZUid
%type <node> ZUExpr
%type <node> Empty
%type <node> FandD
%type <node> Restatement


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
%left BITWISEAND
%left EQ NE
%left GE LE GT LT
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc "pos" "neg"
%right NOT
%left LPAR RPAR LBRACE RBRACE
%nonassoc ELSE

%%

Start:  FunctionDefinition Restart                                              {
                                                                                    $$ = create_simple_node("Program",yylineno,(int)(columnNumber));
                                                                                    root = $$;
                                                                                    if($1 != NULL) {
                                                                                        add_child($$, $1);
                                                                                        add_brother($1, $2);
                                                                                    }
                                                                                }
    |   FunctionDeclaration Restart                                             {
                                                                                    $$ = create_simple_node("Program", yylineno, (int)(columnNumber));
                                                                                    root = $$;
                                                                                    if($1 != NULL) {
                                                                                        add_child($$, $1);
                                                                                        add_brother($1, $2);
                                                                                    }
                                                                                }
    |   Declaration Restart                                                     {
                                                                                    $$ = create_simple_node("Program", yylineno, (int)(columnNumber));
                                                                                    root = $$;
                                                                                    if($1 != NULL) {
                                                                                        add_child($$, $1);
                                                                                        add_brother($1, $2);
                                                                                    }
                                                                                }
    ;

Restart:    Empty                                                               {$$ = $1;}
    |       FunctionDefinition Restart                                          {
                                                                                  $$ = $1;
                                                                                  if($1 != NULL) {
                                                                                      add_brother($1, $2);
                                                                                  }
                                                                                }
    |       FunctionDeclaration Restart                                         {
                                                                                  $$ = $1;
                                                                                  if($1 != NULL) {
                                                                                      add_brother($1, $2);
                                                                                  }
                                                                                }
    |       Declaration Restart                                                 {
                                                                                  $$ = $1;
                                                                                  if($1 != NULL) {
                                                                                      add_brother($1, $2);
                                                                                  }
                                                                                }
    ;


FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody                    {
                                                                                    $$ = create_simple_node("FuncDefinition", yylineno, (int)(columnNumber));
                                                                                    add_child($$, $1);
                                                                                    add_brother($1,$2);
                                                                                    add_brother($1,$3);
                                                                                }
                ;


FunctionDeclaration: TypeSpec FunctionDeclarator SEMI                           {
                                                                                    $$ = create_simple_node("FuncDeclaration", yylineno, (int)(columnNumber));
                                                                                    add_child($$, $1);
                                                                                    add_brother($$->son,$2);
                                                                                }
                ;


FunctionDeclarator: ID LPAR ParameterList RPAR                                  {
                                                                                  $$ = create_value_node("Id", $1, yylineno, (int)($3->col - strlen($1)));
                                                                                  add_brother($$, $3);
                                                                                }
                ;


FunctionBody: LBRACE  FandD RBRACE                                              {
                                                                                    $$ = create_simple_node("FuncBody", yylineno, (int)(columnNumber));
                                                                                    if($2 != NULL){
                                                                                      add_child($$,$2);
                                                                                    }
                                                                                }
        ;

FandD:  StatementSpecial FandD                                                  {
                                                                                  $$ = $1;
                                                                                  if($1 != NULL) {
                                                                                        add_brother($1, $2);
                                                                                  }
                                                                                  else{
                                                                                        $$ = $2;
                                                                                    }
                                                                                }
      | Declaration FandD                                                       {
                                                                                  $$ = $1;
                                                                                  if($1 != NULL) {
                                                                                        add_brother($1, $2);
                                                                                  }
                                                                                }
      | Empty                                                                   {$$ = $1;}
      ;


ParameterList: ParameterDeclaration CommaParameterDeclaration                   {
                                                                                    $$ = create_simple_node("ParamList", yylineno, (int)($1->col - 1));
                                                                                    add_child($$,$1);
                                                                                    add_brother($1,$2);
                                                                                }
            ;


ParameterDeclaration: TypeSpec ZUid                                             {
                                                                                    $$ = create_simple_node("ParamDeclaration", yylineno, (int)(columnNumber - (columnNumber - $1->col)));
                                                                                    add_child($$,$1);
                                                                                    add_brother($1,$2);
                                                                                }
                ;

CommaParameterDeclaration:COMMA ParameterDeclaration CommaParameterDeclaration  {
                                                                                  $$ = $2;
                                                                                  add_brother($2,$3);
                                                                                }
      |     Empty                                                               {$$ = $1;}
      ;


Declaration:    TypeSpec Declarator CommaDeclarator SEMI                        {
                                                                                      $$ = $2;
                                                                                      if($3 != NULL) {
                                                                                          add_brother($$, $3);
                                                                                      }
                                                                                      tree_node* aux = $$;
                                                                                      tree_node aux2 = *$1;
                                                                                      while(aux != NULL) {
                                                                                          aux2.next_brother = aux->son;
                                                                                          aux2.father = aux;
                                                                                          aux->son = (tree_node*) malloc(sizeof(tree_node));
                                                                                          *(aux->son) = aux2;

                                                                                          aux = aux->next_brother;
                                                                                      }
                                                                                }
        |       error SEMI                                                      {$$ = NULL;}
        ;




TypeSpec:   INT                                                                 { $$ = create_simple_node("Int", yylineno, (int)(columnNumber - 3));}
    |       CHAR                                                                { $$ = create_simple_node("Char", yylineno, (int)(columnNumber - 4));}
    |       VOID                                                                { $$ = create_simple_node("Void", yylineno, (int)(columnNumber - 4));}
    |       SHORT                                                               { $$ = create_simple_node("Short", yylineno, (int)(columnNumber - 5));}
    |       DOUBLE                                                              { $$ = create_simple_node("Double", yylineno, (int)(columnNumber - 6));}
    ;


Declarator: ID ZUAssignExpr                                                     {
                                                                                  $$ = create_simple_node("Declaration", yylineno, (int)(columnNumber));
                                                                                  auxId = create_value_node("Id",$1, yylineno, (int)(columnNumber - strlen($1) - 1));
                                                                                  if($2 != NULL){
                                                                                    add_child($$,auxId);
                                                                                    add_brother($$->son,$2);
                                                                                  }
                                                                                  else{
                                                                                    add_child($$,auxId);
                                                                                  }

                                                                                }
        ;

ZUAssignExpr: ASSIGN Expr                                                       {$$ = $2;}
        | Empty                                                                 {$$ = $1;}
        ;

CommaDeclarator:    Empty                                                       {$$ = $1;}
            |       COMMA Declarator CommaDeclarator                            {
                                                                                  $$ = $2;
                                                                                  add_brother($2, $3);
                                                                                }
            ;


Statement:      error SEMI                                                      {$$ = NULL;}
        |       StatementSpecial                                                {$$ = $1;}
        ;

StatementSpecial:   ZUExpr SEMI                                                 {$$ = $1;}
        |           LBRACE StatList RBRACE                                      {$$ = $2;}
        |           LBRACE Statement RBRACE                                     {$$ = $2;}
        |           LBRACE RBRACE                                               {$$ = NULL;}
        |           LBRACE error RBRACE                                         {$$ = NULL;}
        |           IF LPAR Expr RPAR Statement                                 {
                                                                                      if($3 != NULL) {
                                                                                          $$ = create_simple_node("If", yylineno, (int)(columnNumber));

                                                                                          add_child($$,$3);
                                                                                          if($5 != NULL) {
                                                                                              add_brother($3,$5);
                                                                                          }else {
                                                                                              add_brother($3,create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                          }
                                                                                          add_brother($3,create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                      } else {
                                                                                          $$ = NULL;
                                                                                      }
                                                                                }
        |           IF LPAR Expr RPAR Statement ELSE Statement                  {
                                                                                    if( $3 != NULL ) {
                                                                                        $$ = create_simple_node("If", yylineno, (int)(columnNumber));
                                                                                        add_child($$, $3);
                                                                                        if($5 != NULL) {
                                                                                            add_brother($3,$5);
                                                                                        }else {
                                                                                            add_brother($3,create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                        }

                                                                                        if($7 != NULL) {
                                                                                            add_brother($3,$7);
                                                                                        }else {
                                                                                            add_brother($3,create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                        }
                                                                                    } else {
                                                                                        $$ = NULL;
                                                                                    }
                                                                                }
        |           WHILE LPAR Expr RPAR Statement                              {
                                                                                    $$ = create_simple_node("While", yylineno, (int)(columnNumber));
                                                                                    if($3 != NULL) {
                                                                                      add_child($$,$3);
                                                                                    } else {
                                                                                      auxNull = create_simple_node("Null", yylineno, (int)(columnNumber));
                                                                                      add_child($$,auxNull);
                                                                                    }
                                                                                    if($5 != NULL) {
                                                                                        add_brother($$->son,$5);
                                                                                    }else {
                                                                                        add_brother($$->son,create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                    }
                                                                                }

        |           RETURN ZUExpr SEMI                                          {
                                                                                    $$ = create_simple_node("Return", yylineno, (int)(columnNumber));
                                                                                    if($2 == NULL){
                                                                                        add_child($$, create_simple_node("Null", yylineno, (int)(columnNumber)));
                                                                                    }
                                                                                    else{
                                                                                        add_child($$,$2);
                                                                                    }
                                                                                }
        ;


StatList:       Statement Statement Restatement                                 {
                                                                                    int stat_num = 0;
                                                                                    tree_node * stat_aux = $3;
                                                                                    while (stat_aux != NULL) {
                                                                                        stat_num +=1;
                                                                                        stat_aux = stat_aux -> next_brother;
                                                                                    }
                                                                                    if($1 != NULL && $2 != NULL) {
                                                                                        $$ = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                        add_child($$,$1);
                                                                                        add_brother($$->son,$2);
                                                                                        add_brother($$->son,$3);
                                                                                    } else {
                                                                                        if($1 != NULL && $2 == NULL && stat_num >=1) {
                                                                                            $$ = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                            add_child($$,$1);
                                                                                            add_brother($$->son, $3);
                                                                                        }else if($2 != NULL && $1 == NULL && stat_num >=1){
                                                                                            $$ = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                            add_child($$,$2);
                                                                                            add_brother($$->son, $3);
                                                                                        }else if($2 != NULL && $1 == NULL) {
                                                                                            $$ = $2;
                                                                                            add_brother($$, $3);
                                                                                        }else if($1 != NULL && $2 == NULL){
                                                                                            $$ = $1;
                                                                                            add_brother($$, $3);
                                                                                        }else if($2 == NULL && $1 == NULL && stat_num >=2) {
                                                                                            $$ = create_simple_node("StatList", yylineno, (int)(columnNumber));
                                                                                            add_child($$,$3);
                                                                                        }
                                                                                    }
                                                                                }
    ;

Restatement:    Empty                                                           {$$ = $1;}
        |       Statement Restatement                                           {
                                                                                    if($1 != NULL){
                                                                                        $$ = $1;
                                                                                        add_brother($$,$2);
                                                                                    }
                                                                                    else{
                                                                                        $$ = $2;
                                                                                    }
                                                                                }
        ;



Expr:    ExprSpecial                                                            {$$ = $1;}
    |    Expr COMMA ExprSpecial                                                 {
                                                                                  $$ = create_simple_node("Comma", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($$->son,$3);
                                                                                }
    ;

ExprSpecial:    ExprSpecial ASSIGN ExprSpecial                                  {
                                                                                  $$ = create_simple_node("Store", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial AND ExprSpecial                                     {
                                                                                  $$ = create_simple_node("And", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial OR ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Or", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial BITWISEAND ExprSpecial                              {
                                                                                  $$ = create_simple_node("BitWiseAnd", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial BITWISEOR ExprSpecial                               {
                                                                                  $$ = create_simple_node("BitWiseOr", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial BITWISEXOR ExprSpecial                              {
                                                                                  $$ = create_simple_node("BitWiseXor", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial EQ ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Eq", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial NE ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Ne", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial LT ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Lt", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial GT ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Gt", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial LE ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Le", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial GE ExprSpecial                                      {
                                                                                  $$ = create_simple_node("Ge", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial PLUS ExprSpecial                                    {
                                                                                  $$ = create_simple_node("Add", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial MINUS ExprSpecial                                   {
                                                                                  $$ = create_simple_node("Sub", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial MUL ExprSpecial                                     {
                                                                                  $$ = create_simple_node("Mul", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial DIV ExprSpecial                                     {
                                                                                  $$ = create_simple_node("Div", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       ExprSpecial MOD ExprSpecial                                     {
                                                                                  $$ = create_simple_node("Mod", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$1);
                                                                                  add_brother($1,$3);
                                                                                }
        |       NOT ExprSpecial                                                 {
                                                                                  $$ = create_simple_node("Not", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$2);
                                                                                }
        |       MINUS ExprSpecial  %prec "neg"                                  {
                                                                                  $$ = create_simple_node("Minus", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$2);
                                                                                }
        |       PLUS ExprSpecial  %prec "pos"                                   {
                                                                                  $$ = create_simple_node("Plus", yylineno, (int)(columnNumber));
                                                                                  add_child($$,$2);
                                                                                }
        |       ID                                                              { $$ = create_value_node("Id",$1, yylineno, (int)(columnNumber- strlen($1)-2));}
        |       INTLIT                                                          { $$ = create_value_node("IntLit",$1, yylineno, (int)(columnNumber - strlen($1)));}
        |       CHRLIT                                                          { $$ = create_value_node("ChrLit",$1, yylineno, (int)(columnNumber - strlen($1)));}
        |       REALLIT                                                         { $$ = create_value_node("RealLit",$1, yylineno, (int)(columnNumber - strlen($1)));}
        |       LPAR Expr RPAR                                                  {$$ = $2;}
        |       LPAR error RPAR                                                 {$$ = NULL;}
        |       ID LPAR ZUExprZMComma RPAR                                      {
                                                                                  $$ = create_simple_node("Call", yylineno, (int)(columnNumber - strlen($1)));
                                                                                  add_child($$, create_value_node("Id",$1, yylineno, (int)(columnNumber- strlen($1)-2)));
                                                                                  add_brother($$->son,$3);
                                                                                }
        |       ID LPAR error RPAR                                              {$$ = NULL;}
        ;

ZUExprZMComma:  Empty                                                           {$$ = $1;}
            |   ExprSpecial ZMComma                                             {
                                                                                  $$ = $1;
                                                                                  add_brother($$,$2);
                                                                                }
            ;

ZMComma:    Empty                                                               {$$ = $1;}
    |       COMMA ExprSpecial ZMComma                                           {
                                                                                  $$ = $2;
                                                                                  add_brother($$,$3);
                                                                                }
    ;

ZUid:   Empty                                                                   {$$ = NULL;}
    |   ID                                                                      {$$ = create_value_node("Id",$1, yylineno, (int)(columnNumber - strlen($1)));}
    ;

ZUExpr: Empty                                                                   {$$ = NULL;}
    |   Expr                                                                    {$$ = $1;}
    ;


Empty:                                                                          {$$ = NULL;}
    ;

%%

/* A função main() está do lado do lex */

void yyerror (char *s) {

    flag_error = 1;

    printf ("Line %d, col %d: %s: %s\n", yylineno, (int)(columnNumber - strlen(yytext)), s, yytext);
}

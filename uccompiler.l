%{

    //NUNO FERREIRA 2013153319
    #define YY_USER_ACTION columnNumber += yyleng;
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include "y.tab.h"
    #include "ast.h"
    #include "symbol_table.h"


    int flag = 0;
    int lineNumber = 1;
    int columnNumber = 1;
    int colComment;
    int lineComment;
    extern int flag_error;
    extern tree_node* root;

    int yyparse();
    bool check_flag();
    void print_text(char* text);
    void print_with_content(char* text, char* content);
%}

%option yylineno
%X MULTICOMMENT
%X COMMENT

id                  ([a-z]|[A-Z]|"_")+([a-z]|[A-Z]|"_"|[0-9])*
intlit              [0-9]+


escape              \\(\\|\"|\'|n|t|[0-7]{1,3})
chrlit              '({escape}|[^'\n\\])'
invalid_chr         '([^'\n\\]*|\\[^'\n]|\\')*'
unterminated_chr    '([^'\n\\]?|\\[^'\n]|{escape})*\\?

exponent            [eE][+-]?[0-9]+
reallit             [0-9]+"."([0-9]+)?({exponent})?|"."([0-9]+)({exponent})?|[0-9]+{exponent}

empty               ("\n"|"\t"|" ")
reserved            ("["|"]"|"--"|"++"|auto|break|case|const|continue|default|do|enum|extern|float|for|goto|inline|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|_Bool|_Complex|_Imaginary)

/* rules */
%%

"//"                            {BEGIN COMMENT;}
<COMMENT>.                      {;}
<COMMENT>"\n"                   {BEGIN 0;columnNumber = 1;}



"/*"                            {BEGIN MULTICOMMENT ;colComment = columnNumber-2 ;lineComment = yylineno;}
<MULTICOMMENT>"*/"              { BEGIN 0; }
<MULTICOMMENT>"\n"              { columnNumber = 1;}
<MULTICOMMENT>.                 { ; }
<MULTICOMMENT><<EOF>>           {
                                    printf("Line %d, col %d: unterminated comment\n", lineComment,  colComment);
                                    yyterminate();
                                }

"\n"|"\r"|"\r\n"                { columnNumber = 1;}

{reserved}                      {
                                    print_with_content("RESERVED", yytext);
                                    if( check_flag() ) { return RESERVED; }
                                }

while                           {
                                    print_text("WHILE");
                                    if( check_flag() ) { return WHILE; }
                                }

"&"                             {
                                    print_text("BITWISEAND");
                                    if( check_flag() ) { return BITWISEAND; }
                                }

"&&"                            {
                                    print_text("AND");
                                    if( check_flag() ) { return AND; }
                                }

"|"                             {
                                    print_text("BITWISEOR");
                                    if( check_flag() ) { return BITWISEOR; }
                                }

"||"                            {
                                    print_text("OR");
                                    if( check_flag() ) { return OR; }
                                }


"^"                             {
                                    print_text("BITWISEXOR");
                                    if( check_flag() ) { return BITWISEXOR; }
                                }

"=="                            {
                                    print_text("EQ");
                                    if( check_flag() ) { return EQ; }
                                }
"="                             {
                                    print_text("ASSIGN");
                                    if( check_flag() ) { return ASSIGN; }
                                }
"!"                             {
                                    print_text("NOT");
                                    if( check_flag() ) { return NOT; }
                                }
"!="                            {
                                    print_text("NE");
                                    if( check_flag() ) { return NE; }
                                }
">"                             {
                                    print_text("GT");
                                    if( check_flag() ) { return GT; }
                                }
"<"                             {
                                    print_text("LT");
                                    if( check_flag() ) { return LT; }
                                }
">="                            {
                                    print_text("GE");
                                    if( check_flag() ) { return GE; }
                                }
"<="                            {
                                    print_text("LE");
                                    if( check_flag() ) { return LE; }
                                }
","                             {
                                    print_text("COMMA");
                                    if( check_flag() ) { return COMMA; }
                                }
";"                             {
                                    print_text("SEMI");
                                    if( check_flag() ) { return SEMI; }
                                }
"{"                             {
                                    print_text("LBRACE");
                                    if( check_flag() ) { return LBRACE; }
                                }
"}"                             {
                                    print_text("RBRACE");
                                    if( check_flag() ) { return RBRACE; }
                                }
"("                             {
                                    print_text("LPAR");
                                    if( check_flag() ) { return LPAR; }
                                }
")"                             {
                                    print_text("RPAR");
                                    if( check_flag() ) { return RPAR; }
                                }
"+"                             {
                                    print_text("PLUS");
                                    if( check_flag() ) { return PLUS; }
                                }
"-"                             {
                                    print_text("MINUS");
                                    if( check_flag() ) { return MINUS; }
                                }
"*"                             {
                                    print_text("MUL");
                                    if( check_flag() ) { return MUL; }
                                }
"/"                             {
                                    print_text("DIV");
                                    if( check_flag() ) { return DIV; }
                                }
"%"                             {
                                    print_text("MOD");
                                    if( check_flag() ) { return MOD; }
                                }
int                             {
                                    print_text("INT");
                                    if( check_flag() ) { return INT; }
                                }
char                            {
                                    print_text("CHAR");
                                    if( check_flag() ) { return CHAR; }
                                }
void                            {
                                    print_text("VOID");
                                    if( check_flag() ) { return VOID; }
                                }
if                              {
                                    print_text("IF");
                                    if( check_flag() ) { return IF; }
                                }

short                           {
                                    print_text("SHORT");
                                    if( check_flag() ) { return SHORT; }
                                }

double                          {
                                    print_text("DOUBLE");
                                    if( check_flag() ) { return DOUBLE; }
                                }

else                            {
                                    print_text("ELSE");
                                    if( check_flag() ) { return ELSE; }
                                }
return                          {
                                    print_text("RETURN");
                                    if( check_flag() ) { return RETURN; }
                                }
{id}                            {
                                    print_with_content("ID", yytext);
                                    yylval.id = strdup(yytext);
                                    if( check_flag() ) { return ID; }
                                }
{intlit}                        {
                                    print_with_content("INTLIT", yytext);
                                    yylval.intlit = strdup(yytext);
                                    if( check_flag() ) { return INTLIT; }
                                }
{chrlit}                        {
                                    print_with_content("CHRLIT", yytext);
                                    yylval.chrlit = strdup(yytext);
                                    if( check_flag() ) { return CHRLIT; }

                                }

{reallit}                       {
                                    print_with_content("REALLIT",yytext);
                                    yylval.reallit = strdup(yytext);
                                    if( check_flag() ) { return REALLIT; }
                                }

{unterminated_chr}              {
                                    printf("Line %d, col %d: unterminated char constant\n", yylineno, (int)(columnNumber-yyleng));
                                }
{invalid_chr}                   {
                                    printf("Line %d, col %d: invalid char constant (%s)\n", yylineno, (int)(columnNumber-yyleng), yytext);
                                }

{empty}                        {;}


.                               {
                                    printf("Line %d, col %d: illegal character (%s)\n", yylineno, (int)(columnNumber-yyleng), yytext);
                                }

%%

/* simple printing function that checks for -l flag */
void print_text(char* text) {
    if (flag == 1) {
        printf("%s\n", text);
    }
}

/* printing function that checks for -l flag */
void print_with_content(char* text, char* content) {
    if (flag == 1) {
        printf("%s(%s)\n", text, content);
    }
}

int yywrap() {
    return 1;
}

bool check_flag() {
    return (flag == 0 || flag >= 3);
}

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            flag = 1;
        }else if(strcmp(argv[1], "-t") == 0) {
            flag = 3;
        }else if(strcmp(argv[1],"-s") == 0){
            flag = 5;
        }
    }
    if (check_flag()) {
        yyparse();
        if(flag == 3 && flag_error == 0) {
            print_tree(root, 0);
        }
        if(flag == 5 && flag_error == 0){
          init_sym_table();
          semantics(root,st,NULL,1,0);
          //st_print_table(st);
          //printf("\n");
          //print_anotated_tree(root,0,1);
        }

    } else {
        yylex();
    }
    return 0;
}

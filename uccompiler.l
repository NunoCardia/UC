%{
    #define YY_USER_ACTION columnNumber += yyleng;

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    int flag = 0;
    int lineNumber = 1;
    int columnNumber = 1;
    int colComment;
    int lineComment;

    int yyparse();

    bool check_flag();

    void print_text(char* text);
    void print_with_content(char* text, char* content);
    void print_unterminated_error(char* error, int line, int col);
    void print_invalid_error(char* error, int line, int col, char* token);
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
<COMMENT>"\n"                   {BEGIN 0;}



"/*"                            {BEGIN MULTICOMMENT ;colComment = columnNumber - 1;lineComment = yylineno;}
<MULTICOMMENT>"*/"              { BEGIN 0; }
<MULTICOMMENT>"\n"              { columnNumber = 1;}
<MULTICOMMENT>.                 { ; }
<MULTICOMMENT><<EOF>>           {
                                    printf("Line %d, col %d: unterminated comment\n", lineComment,  colComment);
                                    yyterminate();
                                }

"\n"                            { columnNumber = 1; }

{reserved}                      {
                                    print_with_content("RESERVED", yytext);
                                }

while                           {
                                    print_text("WHILE");
                                }

"&"                             {
                                    print_text("BITWISEAND");
                                }

"&&"                            {
                                    print_text("AND");
                                }

"|"                             {
                                    print_text("BITWISEOR");
                                }

"||"                            {
                                    print_text("OR");
                                }


"^"                             {
                                    print_text("BITWISEXOR");
                                }

"=="                            {
                                    print_text("EQ");
                                }
"="                             {
                                    print_text("ASSIGN");
                                }
"!"                             {
                                    print_text("NOT");
                                }
"!="                            {
                                    print_text("NE");
                                }
">"                             {
                                    print_text("GT");
                                }
"<"                             {
                                    print_text("LT");
                                }
">="                            {
                                    print_text("GE");
                                }
"<="                            {
                                    print_text("LE");
                                }
","                             {
                                    print_text("COMMA");
                                }
";"                             {
                                    print_text("SEMI");
                                }
"{"                             {
                                    print_text("LBRACE");
                                }
"}"                             {
                                    print_text("RBRACE");
                                }
"("                             {
                                    print_text("LPAR");
                                }
")"                             {
                                    print_text("RPAR");
                                }
"+"                             {
                                    print_text("PLUS");
                                }
"-"                             {
                                    print_text("MINUS");
                                }
"*"                             {
                                    print_text("MUL");
                                }
"/"                             {
                                    print_text("DIV");
                                }
"%"                             {
                                    print_text("MOD");
                                }
int                             {
                                    print_text("INT");
                                }
char                            {
                                    print_text("CHAR");
                                }
void                            {
                                    print_text("VOID");
                                }
if                              {
                                    print_text("IF");
                                }

short                           {
                                    print_text("SHORT");
                                }

double                          {
                                    print_text("DOUBLE");
                                }

else                            {
                                    print_text("ELSE");
                                }
return                          {
                                    print_text("RETURN");
                                }
{id}                            {
                                    print_with_content("ID", yytext);
                                }
{intlit}                        {
                                    print_with_content("INTLIT", yytext);
                                }
{chrlit}                        {
                                    print_with_content("CHRLIT", yytext);

                                }

{reallit}                       {
                                    print_with_content("REALLIT",yytext);
                                }

{unterminated_chr}              {
                                    printf("Line %d, col %d: unterminated char constant\n", yylineno, (int)(columnNumber-yyleng));
                                }
{invalid_chr}                   {
                                    printf("Line %d, col %d: invalid char constant (%s)\n", yylineno, (int)(columnNumber-yyleng), yytext);
                                }

{empty}                        { ; }
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
        }
    }
    yylex();
    return 0;
}

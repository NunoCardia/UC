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
%X COMMENT

/* variables */
id                  ([a-z]|[A-Z]|"_")+([a-z]|[A-Z]|"_"|[0-9])*
intlit              [0-9]+

valid_stuff         \\n|\\t|\\\\|\\\'|\\\"|(\\([0-7]{1,3}))
invalid_stuff       \\.|\\[8-9]{1,3}

valid_chr           ([^\n\'\\]|{valid_stuff})
inval_chr           ([^'\n\\]|{invalid_stuff})

chrlit              \'{valid_chr}\'
invalid_chr         \'{inval_chr}*\'
unterminated_chr    \'({valid_stuff}*|(\\.|[^'\n\\]))*\\?

empty              ("\n"|"\t"|" ")
reserved            ("["|"]"|"--"|"++"|auto|break|case|const|continue|default|do|double|enum|extern|float|for|goto|inline|long|register|restrict|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile)

/* rules */
%%

"/*"                            {
                                    BEGIN (COMMENT);
                                    {
                                        colComment = columnNumber - 1;
                                    }
                                    lineComment = yylineno;
                                }
<COMMENT>"*/"                   { BEGIN (0); }
<COMMENT>"\n"                   { columnNumber = 1; }
<COMMENT>.                      { ; }
<COMMENT><<EOF>>                {
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

"&&"                            {
                                    print_text("AND");
                                }
"||"                            {
                                    print_text("OR");
                                }
"&"                             {
                                    print_text("AMP");
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
                                    print_text("AST");
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
{unterminated_chr}              {
                                    print_unterminated_error("Line %d, col %d: unterminated char constant\n", yylineno, (int)(columnNumber-yyleng));
                                }
{invalid_chr}                   {
                                    print_invalid_error("Line %d, col %d: invalid char constant (%s)\n", yylineno, (int)(columnNumber-yyleng), yytext);
                                }

{empty}                        { ; }
.                               {
                                    print_invalid_error("Line %d, col %d: illegal character (%s)\n", yylineno, (int)(columnNumber-yyleng), yytext);
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

void print_unterminated_error(char* error, int line, int col) {
    printf(error, line, col);
}

void print_invalid_error(char* error, int line, int col, char* token) {
    printf(error, line, col, token);
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

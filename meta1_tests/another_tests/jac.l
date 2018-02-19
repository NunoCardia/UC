%{
#include <stdio.h>
#include <string.h>
int line = 1, col = 1;
int inv_line, inv_col;
int flag = 0;

%}
NUMBER										[0-9]
LETTER										[a-zA-Z]
ID										  	({LETTER}|"_"|"$")({LETTER}|{NUMBER}|"_"|"$")*
REALLIT										({ODD_NUMBER}("e"|"E")("+"|"-")?{ODD_NUMBER})|({ODD_NUMBER}"."{ODD_NUMBER}?(("e"|"E")("+"|"-")?{ODD_NUMBER})?)|({ODD_NUMBER}?"."{ODD_NUMBER}(("e"|"E")("+"|"-")?{ODD_NUMBER})?)
DECLIT										0|([1-9](({NUMBER}|"_")*{NUMBER}+)?)
ODD_NUMBER						    {NUMBER}+(("_"|{NUMBER})*{NUMBER}+)?
STRLIT										\"([^"\n\r\\]|{ESCAPE})*\"
ESCAPE										"\\f"|"\\n"|"\\r"|"\\t"|"\\\\"|"\\\""
RESERVED					 				"System"|"Integer"|"++"|"--"|"null"|"abstract"|"assert"|"break"|"byte"|"case"|"catch"|"char"|"const"|"continue"|"default"|"enum"|"extends"|"final"|"finally"|"float"|"for"|"goto"|"implements"|"import"|"instanceof"|"interface"|"native"|"long"|"new"|"package"|"private"|"protected"|"short"|"strictfp"|"super"|"switch"|"synchronized"|"this"|"throw"|"throws"|"transient"|"try"|"volatile"
SPACE								   		" "|"\t"|"\f"
NEWLINE										"\n"|"\r"|"\r\n"

%X COMMENT
%X COMMENT2
%X INV_STRING
%%

{STRLIT}					       	              			{if(flag==1)printf("STRLIT(%s)\n", yytext);col+=yyleng;}
\"							                       				{BEGIN INV_STRING;inv_line = line; inv_col = col;col+=yyleng;}
<INV_STRING>\"	                 							{BEGIN 0;col+=yyleng;}
<INV_STRING>{ESCAPE}                          {col+=yyleng;}
<INV_STRING>\\|\\.        	           				{printf("Line %d, col %d: invalid escape sequence (%s)\n", line, col, yytext); col+=yyleng;}
<INV_STRING><<EOF>>				               			{printf("Line %d, col %d: unterminated string literal\n", inv_line, inv_col); col+=yyleng; BEGIN 0;}
<INV_STRING>{NEWLINE}		               				{printf("Line %d, col %d: unterminated string literal\n", inv_line, inv_col); line++; col=1; BEGIN 0;}
<INV_STRING>.					                   			{col+=yyleng;}

"boolean"					                    				{if(flag==1)printf("BOOL\n");col+=yyleng;}
"true"|"false"		                						{if(flag==1)printf("BOOLLIT(%s)\n", yytext);col+=yyleng;}
"class"					                    					{if(flag==1)printf("CLASS\n");col+=yyleng;}
"do"					                       					{if(flag==1)printf("DO\n");col+=yyleng;}
".length"					                    				{if(flag==1)printf("DOTLENGTH\n");col+=yyleng;}
"double"			                    						{if(flag==1)printf("DOUBLE\n");col+=yyleng;}
"else"							                     			{if(flag==1)printf("ELSE\n");col+=yyleng;}
"if"								                      		{if(flag==1)printf("IF\n");col+=yyleng;}
"int"								                       		{if(flag==1)printf("INT\n");col+=yyleng;}
"Integer.parseInt"		              					{if(flag==1)printf("PARSEINT\n");col+=yyleng;}
"System.out.println"	               					{if(flag==1)printf("PRINT\n");col+=yyleng;}
"public"						                    			{if(flag==1)printf("PUBLIC\n");col+=yyleng;}
"return"					                     				{if(flag==1)printf("RETURN\n");col+=yyleng;}
"static"				                    					{if(flag==1)printf("STATIC\n");col+=yyleng;}
"String"					                     				{if(flag==1)printf("STRING\n");col+=yyleng;}
"void"						                    				{if(flag==1)printf("VOID\n");col+=yyleng;}
"while"					                    					{if(flag==1)printf("WHILE\n");col+=yyleng;}
"("							                      				{if(flag==1)printf("OCURV\n");col+=yyleng;}
")"							                      				{if(flag==1)printf("CCURV\n");col+=yyleng;}
"{"							                      				{if(flag==1)printf("OBRACE\n");col+=yyleng;}
"}"							                      				{if(flag==1)printf("CBRACE\n");col+=yyleng;}
"["								                         		{if(flag==1)printf("OSQUARE\n");col+=yyleng;}
"]"								                       			{if(flag==1)printf("CSQUARE\n");col+=yyleng;}
"&&"							                       			{if(flag==1)printf("AND\n");col+=yyleng;}
"||"							                         		{if(flag==1)printf("OR\n");col+=yyleng;}
"<"								                       			{if(flag==1)printf("LT\n");col+=yyleng;}
">"								                       			{if(flag==1)printf("GT\n");col+=yyleng;}
"=="							                         		{if(flag==1)printf("EQ\n");col+=yyleng;}
"!="							                       			{if(flag==1)printf("NEQ\n");col+=yyleng;}
"<="						                          		{if(flag==1)printf("LEQ\n");col+=yyleng;}
">="						                      				{if(flag==1)printf("GEQ\n");col+=yyleng;}
"+"							                        			{if(flag==1)printf("PLUS\n");col+=yyleng;}
"-"							                      				{if(flag==1)printf("MINUS\n");col+=yyleng;}
"*"								                       			{if(flag==1)printf("STAR\n");col+=yyleng;}
"/"								                         		{if(flag==1)printf("DIV\n");col+=yyleng;}
"%"									                        	{if(flag==1)printf("MOD\n");col+=yyleng;}
"!"									                      		{if(flag==1)printf("NOT\n");col+=yyleng;}
"="								                       			{if(flag==1)printf("ASSIGN\n");col+=yyleng;}
";"								                       			{if(flag==1)printf("SEMI\n");col+=yyleng;}
","								                     		  	{if(flag==1)printf("COMMA\n");col+=yyleng;}
"/*"									                       	{BEGIN COMMENT;inv_col = col; inv_line = line;col+=yyleng;}
<COMMENT>"*/"						                     	{BEGIN 0;col+=yyleng;}
<COMMENT>{NEWLINE}				                 		{line++;col=1;}
<COMMENT><<EOF>>				                			{printf("Line %d, col %d: unterminated comment\n", inv_line, inv_col); BEGIN 0;}
<COMMENT>.							                     	{col+=yyleng;}
"//"											                 		{BEGIN COMMENT2;col+=yyleng;}
<COMMENT2>{NEWLINE}					                	{BEGIN 0;line++;col=1;}
<COMMENT2>.							                			{col+=yyleng;}
{RESERVED}							                 			{if(flag==1)printf("RESERVED(%s)\n", yytext);col+=yyleng;}
{REALLIT}								                   		{if(flag==1)printf("REALLIT(%s)\n", yytext);col+=yyleng;}
{DECLIT}							               			   	{if(flag==1)printf("DECLIT(%s)\n", yytext);col+=yyleng;}
{ID}									                 				{if(flag==1)printf("ID(%s)\n", yytext);col+=yyleng;}
{SPACE}								                 				{col+=yyleng;}
{NEWLINE}							                				{line++;col=1;}
. 										                				{printf("Line %d, col %d: illegal character (%s)\n", line, col, yytext);col+=yyleng;}

%%
int main(int argc, char** argv){
	if(argc != 1){
		if(strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "-1") == 0)
			flag = 1;
	}
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}

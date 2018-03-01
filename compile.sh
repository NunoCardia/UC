lex uccompiler.l
yacc -d uccompiler.y
cc -o uccompiler y.tab.c lex.yy.c ast.c  -ll -ly
zip uccompiler.zip uccompiler.l uccompiler.y ast.h ast.c

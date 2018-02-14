lex uccompiler.l
clang-3.8 -o uccompiler lex.yy.c
rm mccompiler.zip
zip mccompiler.zip uccompiler.l

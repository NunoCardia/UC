lex uccompiler.l
clang-3.8 -o uccompiler lex.yy.c
rm uccompiler.zip
zip uccompiler.zip uccompiler.l

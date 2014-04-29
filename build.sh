#!/bin/bash

if [ -f parser/parser.tab.c ]
	then
		rm parser/parser.tab.c
fi

if [ -f parser/parser.tab.h ]
	then
		rm parser/parser.tab.h
fi

if [ -f parser/lex.yy.c ]
	then
		rm parser/lex.yy.c
fi

bison -d parser/parser.y
flex parser/lexer.l

mv lex.yy.c parser/
mv parser.tab.c parser/
mv parser.tab.h parser/



gcc -Wall -g  -c parser/lex.yy.c -o lex.yy.o
gcc -Wall -g  -c instruction/block.c -o block.o
gcc -Wall -g  -c instruction/eval.c -o eval.o
gcc -Wall -g  -c parser/parser.tab.c -o parser.tab.o

gcc -o app.exe *.o

chmod +x ./app.exe

./app.exe
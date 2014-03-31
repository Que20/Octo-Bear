#!/bin/bash


if [ -f parser.tab.c ]
	then
		rm parser.tab.c
fi

if [ -f parser.tab.h ]
	then
		rm parser.tab.h
fi

if [ -f lex.yy.c ]
	then
		rm lex.yy.c
fi

bison -d parser/parser.y
flex parser/lexer.l

gcc -Wall -g  -c lex.yy.c -o binary/lex.yy.o
gcc -Wall -g  -c node.c -o binary/node.o
gcc -Wall -g  -c parser.tab.c -o binary/parser.tab.o

gcc -o app.exe binary/lex.yy.o binary/node.o binary/parser.tab.o

./app.exe
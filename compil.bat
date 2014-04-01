@echo off
echo ===== Compilation =====

gcc -c node/node.c
gcc -c parser/parser.tab.c
gcc -c parser/parser.yy.c

gcc node.o parser.yy.o parser.tab.o -o octo-bear.exe

del node.o
del parser.yy.o
del parser.tab.o

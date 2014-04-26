@echo off
echo ===== Compilation =====

gcc -c instruction/block.c
gcc -c parser/parser.tab.c
gcc -c parser/parser.yy.c

gcc block.o parser.yy.o parser.tab.o -o octo-bear.exe

del block.o
del parser.yy.o
del parser.tab.o

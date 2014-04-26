@echo off
echo ===== Compilation =====

gcc -c instruction/block.c
gcc -c instruction/eval.c
gcc -c parser/parser.tab.c
gcc -c parser/parser.yy.c

gcc *.o -o octo-bear.exe

del eval.o
del block.o
del parser.yy.o
del parser.tab.o

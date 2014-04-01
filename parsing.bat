@echo off
echo ===== Parsing en cours =====

del parser\parser.yy.c

win_bison -d parser/parser.y
win_flex parser/lexer.l

move lex.yy.c parser\parser.yy.c
move parser.tab.c parser\parser.tab.c
move parser.tab.h parser\parser.tab.h

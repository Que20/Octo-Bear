%option noyywrap
%option nounput
%option noinput

%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "../parser/parser.tab.h"
	#include "../instruction/block.h"

%}

white_char	[ \t]+
number		[0-9]
charac		[_a-zA-Z]

plus		"+"
minus		"-"
multiply	"*"
divide		"/"
eoi			";"
com_line	"//"
com_start	"/*"
com_end		"*/"
line_end	"\n"|"\r"|"\n\r"|"\r\n"

integer		{number}+
float		{number}*"."{number}+
boolean		"true"|"false"

var_name	{charac}({charac}|{number})*

%%

{plus}		{ return(PLUS); }
{minus}		{ return(MINUS); }
{integer}	{ return(INT); }
{float}		{ return(FLOAT); }

"="			{ return(EQUAL); }

{eoi}		{ return(EOI); }
{line_end}	{ return(NEW_LINE); }
"{"			{ return(START_BLOCK); }
"}"			{ return(END_BLOCK); }

"if"		{ return(IFC); }
"else"		{ return(IFS); }
"=="		{ return(EQUALS); }

{boolean}	{ return(BOOLEAN); }
{var_name}	{ return(VAR_NAME); }

.			{ }

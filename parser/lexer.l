%option noyywrap
%option nounput
%option noinput

%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "../parser/parser.tab.h"
	#include "../node/node.h"

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

integer		{number}+
float		{number}*"."{number}+
boolean		"true"|"false"

var_name	{charac}({charac|number})*

%%

{plus}		{ return(PLUS); }
{eoi}		{ return(EOI); }
"{"			{ return(START_BLOCK); }
"}"			{ return(END_BLOCK); }
"if"		{ return(IFC); }
"else"		{ return(IFS); }
"=="		{ return(EQUALS); }
{boolean}	{ return(BOOLEAN); }
.			{ }

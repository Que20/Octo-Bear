%option noyywrap
%option nounput
%option noinput
%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "parser.tab.h"
	#include "node.h"
%}

white_char	[ \t]+
number 		[0-9]
integer		{number}+

charac 		[_a-zA-Z]
var_name	{charac}({charac}|{integer})*

%%

"+"			{ return(PLUS); }
"-"			{ return(MINUS); }
"/"			{ return(SLASH); }
"*"			{ return(STAR); }
"="			{ return(EQUAL); }

{var_name}	{ yylval.var_name = strdup(yytext); 	return(VAR_NAME); }
{integer}	{ yylval.var_value = atoi(yytext); 		return(VALUE); }

"\n"|"\r\n"	{ return(NEW_LINE); }

.			{  }
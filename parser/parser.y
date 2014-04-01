%{
	#define YYERROR_VERBOSE

	#include <stdio.h>
	#include <stdlib.h>

	#include "../node/node.h"

	int yylex(void);
	int yyerror(const char* s);
%}

%union {
	char* var_name;
	float var_value;
};

%token PLUS MINUS STAR SLASH EQUAL BOOLEAN
%token EQUALS NEQUALS GEQUALS LEQUALS GREATER LESS NOT
%token VAR_NAME VAR_VALUE
%token NEW_LINE
%token IFC IFS
%token START_BLOCK END_BLOCK
%token EOI

%left EQUAL
%left PLUS MINUS
%left STAR SLASH
%left EQUALS NEQUALS GEQUALS LEQUALS GREATER LESS
%left NOT
%left VAR_NAME VAR_VALUE

%type <var_name> VAR_NAME
%type <var_value> VAR_VALUE

%start Input
%%

Input:
	| Input Instruction EOI {
		printf("Test instruction\n");
	}
	| Input Conditionline {
		printf("Test condition\n");
	}
	| Input START_BLOCK {
		printf("Debut d'un nouveau bloc d'instruction\n");
	}
	| Input END_BLOCK {
		printf("Fin d'un nouveau bloc d'instruction\n");
	}
	;

Instruction:
	PLUS {
		printf("Instruction plus\n");
	}
	;

Conditionline:
	IFC Condition {
		printf("Debut de la condition\n");
	}
	;

Condition:
	Condition EQUALS Condition {
		printf("operande_1 == operande_2\n");
	}
	| BOOLEAN {
		printf("Result\n");
	}
	;

%%

int yyerror(const char* s) {
	printf("Error : %s\n", s);
	return 0;
}

int main(int argc, char** argv) {

	// Initialising ...

	// Parsing ...
	if (argc > 1) {
		printf("Parametre : %s\n", argv[1]);
	} else {
		yyparse();
	}

	return 0;
}

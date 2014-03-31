%{
	#define YYERROR_VERBOSE

	#include <stdio.h>
	#include <stdlib.h>

	#include "node.h"

	int yylex(void);
	int yyerror(const char *s);
%}

%union {
	char* var_name;
	int var_value;
	struct s_Node* node;
};

%token PLUS MINUS SLASH STAR EQUAL
%token VAR_NAME VALUE
%token NEW_LINE

%left EQUAL
%left PLUS MINUS
%left STAR SLASH
%left VAR_NAME VALUE

%type <var_name> VAR_NAME
%type <var_value> VALUE
%type <node> PLUS MINUS SLASH STAR EQUAL Expression

%start Input
%%

Input:
	| Input Expression NEW_LINE {
		puts("Tree Value : ");
		node_debug($2, 0);
		printf("RESULT : %d\n",node_eval($2));
	 }
	;

Expression:
	 VALUE {
		$$ = node_new(NULL, NULL, NT_VALUE, variable_new($1, NULL));
	 }
	| VAR_NAME {
		$$ = node_new(NULL, NULL, NT_VAR_ACC, variable_new(0, $1));
	 }
	| Expression PLUS Expression {
		$$ = node_new($1, $3, NT_ADD, NULL);
	 }
	| Expression MINUS Expression {
		$$ = node_new($1, $3, NT_SUB, NULL);
	 }
	| Expression STAR Expression {
		$$ = node_new($1, $3, NT_MULT, NULL);
	 }
	| Expression SLASH Expression {
		$$ = node_new($1, $3, NT_DIV, NULL);
	 }
	| Expression EQUAL Expression {
		$$ = node_new($1, $3, NT_EQUAL, NULL);
	 }
	;

%%

int yyerror(const char* s){
	printf("Error : %s\n", s);
	return 0;
}

int main(void){
	yyparse();
	return 0;
}

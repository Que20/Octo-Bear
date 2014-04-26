%{
	#define YYERROR_VERBOSE

	#include <stdio.h>
	#include <stdlib.h>

	#include "../instruction/block.h"
	#include "../instruction/eval.h"

	int yylex(void);
	int yyerror(const char* s);

	extern FILE* yyin;

	struct s_Block* root;
%}

%union {
	char* var_name;
	float var_value;
	struct s_Table* table;
	struct s_Expression* expression;
	struct s_Instruction* instruction;
	struct s_Block* block;
};

%token PLUS MINUS STAR SLASH EQUAL
%token INT FLOAT BOOLEAN
%token EQUALS NEQUALS GEQUALS LEQUALS GREATER LESS NOT
%token VAR_NAME VAR_VALUE
%token NEW_LINE
%token IFC IFS
%token START_BLOCK END_BLOCK
%token EOI EOP

%left EQUAL
%left PLUS MINUS
%left STAR SLASH
%left EQUALS NEQUALS GEQUALS LEQUALS GREATER LESS
%left NOT
%left VAR_NAME VAR_VALUE

%type <var_name> VAR_NAME
%type <var_value> VAR_VALUE Expression
%type <instruction> PLUS MINUS STAR SLASH EQUAL BOOLEAN EQUALS NEQUALS GEQUALS LEQUALS GREATER LESS NOT NEW_LINE Command
%type <block> START_BLOCK END_BLOCK Line

%start Input
%%

Input:
	{ /* empty */}
	| Input Line {
		printf("Analyse de la ligne 1!\n");
	}
	| Input error {
		yyerrok;
	}
	;

Line:
	EOI {
		printf("Analyse de la ligne 2!\n");
	}
	| Command Line {
		printf("Analyse de la ligne 3!\n");
	}
	| START_BLOCK Line {
		printf("Analyse de la ligne 4!\n");
	}
	| END_BLOCK Line {
		printf("Analyse de la ligne 5!\n");
	}
	;

Command:
	NEW_LINE {
		printf("EOP\n");
	}
	| Expression Command {
		printf("Analyse de la ligne 7!\n");
	}
	;

Expression:
	INT {
		printf("Analyse de la ligne 8!\n");
	}
	| FLOAT {
		printf("Analyse de la ligne 9!\n");
	}
	| VAR_NAME {
		printf("Analyse de la variable !\n");
	}
	| Expression PLUS Expression {
		printf("Analyse de la ligne 10!\n");
	}
	| Expression MINUS Expression {
		printf("Analyse de la ligne 11!\n");
	}
	| Expression EQUAL Expression {
		printf("Affectation !\n");
	}
	;

%%

int yyerror(const char* s) {
	printf("Erreur : %s\n", s);
	return 0;
}

int main(int argc, char** argv) {

	// Initialising ...
	root = newBlock(NULL, NULL, NULL);

	// Parsing ...
	/*
	if (argc > 1) {
		printf("Parametre : %s\n", argv[1]);
		FILE *f = fopen(argv[1], "r+");
		yyin = f;
		yyparse();
		fclose(f);
	} else {
		yyparse();
	}
	*/
	//Expression* condLeft = newExpression(NULL, NULL, )

	Expression* left = newExpression(NULL, NULL, TE_VALUE, 4);
	Expression* right = newExpression(NULL, NULL, TE_VALUE, 5);
	Expression* expressionComplet1 = newExpression(left, right, TE_PLUS, 0);
	Instruction* testExpression = newInstruction(NULL, NULL, expressionComplet1, TI_EXPRESSION);

	root->instruction = testExpression;

	printf("===== Starting debug ======\n");
	debugBlock(root, 0);

	printf("===== Starting evaluation ======\n");
	evalBlock(root);

	return 0;
}

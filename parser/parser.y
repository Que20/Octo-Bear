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
%type <var_value> VAR_VALUE INT
%type <expression> Expression
%type <instruction> PLUS MINUS STAR SLASH EQUAL BOOLEAN EQUALS NEQUALS GEQUALS LEQUALS GREATER LESS NOT NEW_LINE Command
%type <block> START_BLOCK END_BLOCK Line

%start Input
%%

Input:
	{ /* empty */}
	| Line Input {
		printf("Analyse de la ligne 1!\n");
	}
	| error Input {
		yyerrok;
	}
	;

Line:
	NEW_LINE {
		printf("Analyse de la ligne 2!\n");
	}
	| Command Line {
		printf("Analyse de la ligne 3!\n");
		root->instruction = (Instruction*) $1;
	}
	| START_BLOCK Line {
		printf("Analyse de la ligne 4!\n");
	}
	| END_BLOCK Line {
		printf("Analyse de la ligne 5!\n");
	}
	;

Command:
	EOI {
		printf("EOP\n");
	}
	| Expression Command {
		printf("Analyse de la ligne 7!\n");
		$$ = (Instruction*) newInstruction(NULL, NULL, (Expression*) $1, TI_EXPRESSION);
	}
	;

Expression:
	INT {
		printf("Analyse de la ligne 8!\n");
		$$ = (Expression*) newExpression(NULL, NULL, TE_VALUE, $1);
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
	| Expression EQUALS Expression {
		printf("Egualite ?\n");
		$$ = (Expression*) newExpression((Expression*) $1, (Expression*) $3, TE_EQUALS, 0);
	}
	| "(" Expression ")" {
		printf("DIGRESSSSSSSSSSSS ...\n");
		$$ = (Expression*) newExpression((Expression*) $2, NULL, TE_DIGRESS, 0);
	}
	;

%%

int yyerror(const char* s) {
	printf("Erreur : %s\n", s);
	return 0;
}

int main(int argc, char** argv) {

	// Initialising ...
	struct s_Table* tableVide = NULL;

	setVariable(&tableVide, "abc", 1, TV_BOOL);

	root = newBlock(NULL, NULL, NULL, tableVide);

	setVariable(&tableVide, "def", 2.2, TV_FLOAT);

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
	
	//Expression* condLeft = newExpression(NULL, NULL, ) (a == (b == c)) {

	Expression* right = newExpression(newExpression(NULL, NULL, TE_VALUE, 37), newExpression(NULL, NULL, TE_VALUE, 37), TE_NEQUALS, 0);
	Expression* left = newExpression(newExpression(NULL, NULL, TE_VALUE, 45), newExpression(NULL, NULL, TE_VALUE, 45), TE_EQUALS, 0);
	Expression* expressionComplet1 = newExpression(left, right, TE_EQUALS, 0);
	Instruction* testExpression = newInstruction(NULL, NULL, expressionComplet1, TI_EXPRESSION);

	root->instruction = testExpression;

	printf("===== Starting debug ======\n");
	debugBlock(root, 0);

	printf("===== Starting evaluation ======\n");
	evalBlocks(root);

	return 0;
}

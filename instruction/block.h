#ifndef H_BLOCK
#define H_BLOCK

#include <stdio.h>
#include <stdlib.h>

enum e_TypeVariable {
	TV_BOOL = 1,
	TV_INT = 2,
	TV_FLOAT = 4,
	TV_STRING = 8
};
typedef enum e_TypeVariable TypeVariable;

enum e_TypeInstruction {
	TI_DECLARATION = 1,
	TI_AFFECTATION = 2,
	TI_RECUPERATION = 4,
	TI_CONDITION = 8,
	TI_CALLFUNCTION = 16,
	TI_EXPRESSION = 32,
};
typedef enum e_TypeInstruction TypeInstruction;

enum e_TypeExpression {
	TE_EQUALS = 1,
	TE_NEQUALS = 2,
	
	TE_LESS = 4,
	TE_GREATER = 8,
	TE_LESS_EQUALS = 16,
	TE_GREATER_EQUALS = 32,

	TE_AND = 64,
	TE_OR = 128,
	TE_NOT = 256,

	TE_PLUS = 512,
	TE_MINUS = 1024,
	TE_STAR = 2048,
	TE_DIVIDE = 4096,
	TE_MODULO = 8192,

	TE_VARIABLE = 16384,
	TE_VALUE = 32768
};
typedef enum e_TypeExpression TypeExpression;

struct s_Table {
	struct s_Table* next;

	char* name;
	float value;
	TypeVariable type;
};
typedef struct s_Table Table;

struct s_Expression {
	struct s_Expression* right;
	struct s_Expression* left;
	struct s_Table* liste;

	TypeExpression type;
};
typedef struct s_Expression Expression;

struct s_Instruction {
	struct s_Instruction* right;
	struct s_Instruction* left;
	struct s_Expression* expression;

	TypeInstruction type;
};
typedef struct s_Instruction Instruction;

struct s_Block {
	struct s_Block* child;
	struct s_Instruction* condition;
	struct s_Instruction* instruction;
};
typedef struct s_Block Block;

/* Function */
Instruction* newInstruction(Instruction* left, Instruction* right, Expression* expression, TypeInstruction type);
Block* newBlock(Block* child, Instruction* cond, Instruction* inst);
Expression* newExpression(Expression* left, Expression* right, TypeExpression type, float valueVariable);

void printSpace(int space);

void debugBlock(Block* debugBlocks, int leftSpacer);
void debugInstruction(Instruction* instruction, int leftSpacer);
void debugExpression(Expression* expression, int leftSpacer);
void debugTable()

#endif /* H_BLOCK */

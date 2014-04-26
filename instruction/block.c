#include "block.h"

Instruction* newInstruction(Instruction* left, Instruction* right, Expression* expression, TypeInstruction type) {
	Instruction* temp = (Instruction*) malloc( sizeof(Instruction) );

	if (temp != NULL) {
		temp->left = left;
		temp->right = right;
		temp->expression = expression;
		temp->type = type;
	}

	return temp;
}

Block* newBlock(Block* child, Instruction* cond, Instruction* inst) {
	Block* temp = (Block*) malloc( sizeof(Block) );

	if (temp != NULL) {
		temp->child = child;
		temp->condition = cond;
		temp->instruction = inst;
	}

	return temp;
}

Expression* newExpression(Expression* left, Expression* right, TypeExpression type, float value) {
	Expression* temp = (Expression*) malloc( sizeof(Expression) );

	if (temp != NULL) {
		temp->left = left;
		temp->right = right;
		temp->type = type;
		temp->value = value;
	}

	return temp;
}

void printSpace(int space) {
	int i = 0;

	for (i = 0; i <= space; i += 1) {
		if (i < space) {
			printf("   |");
		} else {
			printf("   +");
		}
	}

	printf(" ");
}

void debugBlock(Block* debugBlocks, int leftSpacer) {
	
	if (debugBlocks != NULL) {
		debugBlock(debugBlocks->child, leftSpacer + 1);
		debugInstruction(debugBlocks->condition, leftSpacer + 1);
		debugInstruction(debugBlocks->instruction, leftSpacer + 1);
	} else {
		printSpace(leftSpacer);
		printf("block null\n");
	}

}

void debugInstruction(Instruction* instruction, int leftSpacer) {
	
	if (instruction != NULL) {
		printSpace(leftSpacer);
		printf("Type instruction : %d\n", instruction->type);

		if (instruction->type == TI_EXPRESSION) {
			debugExpression(instruction->expression, leftSpacer + 1);
		}

		debugInstruction(instruction->left, leftSpacer + 1);
		debugInstruction(instruction->right, leftSpacer + 1);
	} else {
		printSpace(leftSpacer);
		printf("instruction null\n");
	}
}

void debugExpression(Expression* expression, int leftSpacer) {

	if (expression != NULL) {
		printSpace(leftSpacer);
		printf("Type expression : %d\n", expression->type);

		printSpace(leftSpacer);
		printf("Value expression : %f\n", expression->value);

		debugExpression(expression->left, leftSpacer + 1);
		debugExpression(expression->right, leftSpacer + 1);
	} else {
		printSpace(leftSpacer);
		printf("expression null\n");
	}
}

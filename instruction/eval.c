#include "eval.h"

Block* evalBlock(Block* debugBlocks) {
	Block* blocks = NULL;
	Instruction* condition = NULL;
	Instruction* instruction = NULL;

	if (debugBlocks != NULL) {
		blocks = evalBlock(debugBlocks->child);
		condition = evalInstruction(debugBlocks->condition);
		instruction = evalInstruction(debugBlocks->instruction);
	}

}

Instruction* evalInstruction(Instruction* instruction) {
	Instruction* final = newInstruction;

	if (instruction != NULL) {
		if (instruction->type == TI_EXPRESSION) {
			debugExpression(instruction->expression, leftSpacer + 1);
		}

		debugInstruction(instruction->left, leftSpacer + 1);
		debugInstruction(instruction->right, leftSpacer + 1);
	}
}

Expression* evalExpression(Expression* expression) {

	if (expression != NULL) {
		debugExpression(expression->left, leftSpacer + 1);
		debugExpression(expression->right, leftSpacer + 1);
	}
}

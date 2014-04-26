#include "eval.h"

Block* evalBlocks(Block* debugBlocks) {
	Block* blocks = NULL;
	Instruction* condition = NULL;
	Instruction* instruction = NULL;

	if (debugBlocks != NULL) {
		printf("Debug block ...\n");
		blocks = evalBlocks(debugBlocks->child);
		condition = evalInstruction(debugBlocks, debugBlocks->condition);
		instruction = evalInstruction(debugBlocks, debugBlocks->instruction);
	}

	return blocks;
}

Instruction* evalInstruction(Block* blocks, Instruction* instruction) {
	Instruction* final = newInstruction(NULL, NULL, NULL, 0);
	Expression* e = NULL;

	if (instruction != NULL) {
		printf("Debug instruction ...\n");
		if (instruction->type == TI_EXPRESSION) {
			e = evalExpression(instruction->expression);

			if (e != NULL && e->type == TE_VALUE) {
				printf("Valeur de l'expression (I): %f\n", e->value);
			}
		}

		evalInstruction(blocks, instruction->left);
		evalInstruction(blocks, instruction->right);
	}

	return final;
}

Expression* evalExpression(Expression* expression) {
	Expression* final = NULL;

	Expression* left = NULL;
	Expression* right = NULL;

	float leftValue = 0.0;
	float rightValue = 0.0;

	if (expression != NULL) {
		printf("Debug expression ...\n");
		left = evalExpression(expression->left);
		right = evalExpression(expression->right);

		final = newExpression(NULL, NULL, TE_VALUE, 0.0);

		leftValue = (left != NULL) ? left->value : 0.0;
		rightValue = (right != NULL) ? right->value : 0.0;
		printf("leftValue : %f\n", leftValue);
		printf("rightValue : %f\n", rightValue);

		switch(expression->type) {
			case TE_EQUALS:
				printf("%f == %f\n", leftValue, rightValue);
				final->value = (leftValue == rightValue) ? 1.0 : 0.0;
				break;
			case TE_VALUE:
				printf("[VAL]: %f\n", expression->value);
				final->value = expression->value;
				break;
			case TE_DIGRESS:
				printf("[VAL]: %f\n", leftValue);
				final->value = leftValue;
				break;
		}
	}

	return final;
}

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
		temp->liste = (Table*) malloc( sizeof(Table) );
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

void setVariable(Table *root, char* name, float value, TypeVariable type) {

}

Table* getVariable(Table *root, char* name) {
	Table *retour = NULL;
	Table *temp = root;

	while (temp != NULL) {
		if (strcmp(name, temp->name) == 0) {
			retour = temp;
			temp = NULL;
		}
		temp = temp->next;
	}

	if (retour == NULL) {
		retour = (Table*) malloc( sizeof(Table) );
		retour->name = NULL;
		retour->value = 0.0;
		retour->next = NULL;
		retour->type = TV_NONE;
	}

	return retour;
}

Table* removeVariable(Table *root, char *name) {
	Table* tmpLast = root;
	Table* tmpTest = root;

	if (root != NULL) {
		if (strcmp(root->name, name) == 0) {

		} else {
			while (tmpLast != NULL) {
				tmpTest = tmpTest->next;

				if (tmpTest != NULL && strcmp(root->name, name) == 0) {

				}

				tmpLast = tmpTest;
			}
		}
	}
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

void debugTable() {
	
}

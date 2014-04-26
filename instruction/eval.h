#ifndef H_EVAL
#define H_EVAL

#include "block.h"

Block* evalBlocks(Block* debugBlocks);
Instruction* evalInstruction(Block* blocks, Instruction* instruction);
Expression* evalExpression(Expression* expression);

#endif /* H_EVAL */

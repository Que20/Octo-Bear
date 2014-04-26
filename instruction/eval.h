#ifndef H_EVAL
#define H_EVAL

#include "block.h"

Block* evalBlock(Block* debugBlocks);
Instruction* evalInstruction(Instruction* instruction);
Expression* evalExpression(Expression* expression);

#endif /* H_EVAL */

#ifndef H_NODE
#define H_NODE

#include <stdio.h>
#include <stdlib.h>

enum e_node_type {
    NT_ADD,
    NT_SUB,
    NT_MULT,
    NT_POW,
    NT_DIV,
    NT_EQUAL,
    NT_P_UNARY,
    NT_M_UNARY,
    NT_VALUE,
    NT_VAR_DEC,
    NT_VAR_ACC
};

typedef enum e_node_type node_type;

struct s_Variable {
    int value;
    char* name;
};

typedef struct s_Variable Variable;

struct s_Node {
    struct s_Node* right;
    struct s_Node* left;
    node_type type;
    Variable* v;
};

typedef struct  s_Node Node;

Node* node_new(Node* left, Node* right, node_type type, Variable* v);
Variable* variable_new(int value, char* nom);
void print_space(unsigned int i);
void node_debug(Node* n, unsigned int i);
void variables_debug(Variable* v, unsigned int i);

#endif // H_NODE

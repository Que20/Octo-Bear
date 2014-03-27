#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node* node_new(Node* left, Node* right, node_type type, Variable* v){
    Node* n = malloc(sizeof(Node));
    n->left = left;
    n->right = right;
    n->type = type;
    n->v = v;

    return n;
}

Variable* variable_new(int value, char* name){
    Variable* v = malloc(sizeof(Variable));
    v->value = value;
    v->name = name;

    return v;
}

void print_space(unsigned int i){
    for(; i > 0 ; i--){
        fputc(' ',stdout);
    }
}

void node_debug(Node* n, unsigned int i){
    print_space(i), puts("Node :");
    print_space(i), printf("    type :%d\n",n->type);
    if(n->v){
        variables_debug(n->v, i+4);
    }
    if(n->right){
        node_debug(n->right, i+4);
    }
    if(n->left){
        node_debug(n->left, i+4);
    }
}

void variables_debug(Variable* v, unsigned int i){
    print_space(i), puts("Variable :");
    print_space(i), printf("    name  : %s\n", v->name);
    print_space(i), printf("    value : %d\n", v->value);
}


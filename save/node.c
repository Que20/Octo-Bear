#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int node_eval(Node* n){
    int left;
    int right;
    if(n->v){
        printf("VALUE : %d\n",n->v->value);
        return n->v->value;
    }else{
        if(n->left){
            left = node_eval(n->left);
        }else{
            left = 0;
        }
        if(n->right){
            right = node_eval(n->right);
        }else{
            right = 0;
        }
        printf("LEFT  : %d\n",left);
        printf("RIGHT : %d\n",right);
        switch(n->type){
            case NT_ADD :
                return left + right;
                break;
            case NT_SUB :
                return left - right;
                break;
            case NT_MULT :
                return left * right;
                break;
            case NT_POW :
                return pow(left, right);
                break;
            case NT_DIV :
                return left / right;
                break;
            case NT_EQUAL :
                return 0;
                break;
            case NT_P_UNARY :
                return +right;
                break;
            case NT_M_UNARY :
                return -right;
                break;
            case NT_VALUE :
                return left;
                break;
            case NT_VAR_DEC :
                return 1;
                break;
            case NT_VAR_ACC :
                return 0;
                break;
            default :
                return 0;
                break;
        }
    }
}

void variables_debug(Variable* v, unsigned int i){
    print_space(i), puts("Variable :");
    print_space(i), printf("    name  : %s\n", v->name);
    print_space(i), printf("    value : %d\n", v->value);
}


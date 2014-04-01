#include "list_chain.h"

t_list_chain * list_chain_new(Variable value) {
    t_list_chain * node = (t_list_chain *)malloc(sizeof(t_list_chain));
    node->next=NULL;
    node->value = value;
    return node;
}
/*
void list_chain_dispaly(t_list_chain * list_chain) {
    while (list_chain) {
        printf("%i\n", list_chain->value);
        list_chain = list_chain->next;
    }
}
*/
unsigned int list_chain_size(t_list_chain * list_chain) {
    unsigned int i=0;
    while (list_chain) {
        i++;
        list_chain = list_chain->next;
    }
    return i;
}

t_list_chain * list_chain_append(t_list_chain * list_chain, Variable value) {
    if (list_chain) {
        t_list_chain * node = list_chain;
        while(node->next != NULL) {
            node = node->next;
        }
        node->next = list_chain_new(value);
    } else {
        list_chain = list_chain_new(value);
    }
    return list_chain;
}
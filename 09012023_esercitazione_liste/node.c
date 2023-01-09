#include "node.h"

node_t* create_node(int value){
    node_t *new = (node_t*) malloc(sizeof(node_t)); 
    new->value = value; 
    new->next = NULL; 

    return new;
}

#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_t;

node_t* create_node(int value);

#endif

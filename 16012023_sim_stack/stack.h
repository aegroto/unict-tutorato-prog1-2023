#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

struct node {
    char value;
    struct node* next;
};
typedef struct node node_t;

struct stack {
    node_t* top;
};
typedef struct stack stack_t;

#endif

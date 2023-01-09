#ifndef LIST_H
#define LIST_H

#include "node.h"

struct list {
    node_t* head;
};

typedef struct list list_t;

list_t* create_list();
void insert(list_t* list, int value);
void print_list(list_t* list);

#endif

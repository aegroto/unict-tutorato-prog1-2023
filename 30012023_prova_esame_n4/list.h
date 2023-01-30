#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

//Riga
struct riga{
    char word[100];
    int count;
};
typedef struct riga riga_t;

//Nodo
struct node {
    riga_t r;
    struct node *next;
}; 
typedef struct node node_t;

//Lista
struct list {
    node_t* head;
    node_t* tail;
};
typedef struct list list_t;


list_t* createList();
void addNode(list_t*, riga_t);
void printList(list_t *l);
void filterList(list_t* l, int n);
void deallocateList(list_t* list);

#endif
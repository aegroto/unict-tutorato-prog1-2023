#include <stdio.h>
#include "list.h"

list_t* create_list() {
    list_t* new = (list_t*) malloc(sizeof(list_t));
    new->head = NULL;
    return new;
}

void insert(list_t* list, int value) {
    node_t* new_node = create_node(value);
    if(list->head == NULL) {
        list->head = new_node;
    } else {
        node_t* tail = list->head;
        while(tail->next != NULL) {
            tail = tail->next;
        }

        tail->next = new_node;
    }
}

void print_list(list_t* list) {
    node_t* current = list->head;
    while(current != NULL) {
        printf("%i ", current->value);
        current = current->next;
    }
    printf("\n");
}
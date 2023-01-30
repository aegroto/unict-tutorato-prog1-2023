#include "list.h"

list_t* createList(){
    list_t* list = (list_t*) malloc(sizeof(list_t)); 
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addNode(list_t* list, riga_t r){
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    new_node->r = r;
    new_node->next=NULL;

    if(list->head==NULL){
        list->head = new_node;
    }
    else{
        list->tail->next=new_node;
    }

    list->tail = new_node;
}

void printList(list_t *l)
{
    node_t *current = l->head;
    while (current)
    {
        printf("%s %d\n", current->r.word, current->r.count);
        current = current->next;
    }
}

void filterList(list_t* l,int n){
    node_t* prev = NULL;
    node_t* current = l->head;
    while(current != NULL){
        node_t* next=current->next;
        if(current->r.count < n){
            if(prev != NULL) {
                prev->next=next;
            } else {
                l->head = next;
            }

            free(current);
        } else {
            prev = current;
        }

        current = next;
    }

    l->tail = prev;

}

void deallocateList(list_t* list) {
    node_t* current = list->head;
    while(current != NULL) {
        node_t* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
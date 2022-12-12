#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node_t;

node_t* allocate_node(int value) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->value = value;
    return node;
}

void link(node_t* node, node_t* next_node) {
    node->next = next_node;
}

int main() {
    printf("Hello World!\n");

    node_t* first = allocate_node(5);
    node_t* second = allocate_node(8);
    node_t* third = allocate_node(-3);

    link(first, second);
    link(second, third);
    link(third, NULL);

    node_t* cursor = first;
    while(cursor != NULL) {
        printf("Element: %d\n", cursor->value);
        cursor = cursor->next;
    }


    return 0;
}

#include "stack.h"

stack_t init() {
    stack_t stack;
    stack.top = NULL;
    return stack;
}

void push(stack_t* stack, char value) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->value = value;

    if(stack->top == NULL) {
        stack->top = new_node;
    } else {
        new_node->next = stack->top;
        stack->top = new_node;
    }
}

char pop(stack_t* stack) {
    if(stack->top == NULL) {
        fprintf(stderr, "pop con stack vuoto\n");
        exit(1);
    }

    char value_to_pop = stack->top->value;
    node_t* popped_node = stack->top;
    stack->top = popped_node->next;
    free(popped_node);

    return value_to_pop;
}
void print_stack(stack_t* stack){
    node_t *cursor = stack->top;
    printf("[");
    while(cursor != NULL) {
        char value = cursor->value;
        printf("%c (%d) | ", value, value);
        cursor = cursor->next;
    }
    printf("]\n");
}
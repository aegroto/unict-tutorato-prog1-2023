#include <stdlib.h>
#include <stdio.h>

struct queue {
    size_t max_elements;
    int* values;
    int H;
    int T;
};

typedef struct queue queue_t;

queue_t* init_queue(size_t max_elements) {
    queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
    queue->max_elements = max_elements;
    queue->values = (int*) malloc(sizeof(int) * max_elements);
    queue->H = 0;
    queue->T = -1;
    return queue;
}

void enqueue(queue_t* queue, int element) {
    queue->T = (queue->T + 1) % queue->max_elements;
    queue->values[queue->T] = element;
}

int dequeue(queue_t* queue) {
    int extracted_element = queue->values[queue->H];
    queue->H = (queue->H + 1) % queue->max_elements;
    return extracted_element;
}

void print_queue(queue_t* queue) {
    printf("H = %d, T = %d\n", queue->H, queue->T);
    for(int i = 0; i < queue->max_elements; ++i) {
        printf("%d ", queue->values[i]);
    }
    printf("\n");
}

// TODO: Gestire i casi in cui la coda è piena o vuota
int main() {
    queue_t* queue = init_queue(4);
    print_queue(queue);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 5);
    print_queue(queue);

    printf("Extracted element: %d\n", dequeue(queue));
    print_queue(queue);

    enqueue(queue, 1);
    print_queue(queue);

    printf("Extracted element: %d\n", dequeue(queue));
    printf("Extracted element: %d\n", dequeue(queue));
    printf("Extracted element: %d\n", dequeue(queue));

    print_queue(queue);

    enqueue(queue, 7);
    print_queue(queue);

    printf("Extracted element: %d\n", dequeue(queue));
    print_queue(queue);

    return 0;
}
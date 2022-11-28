#include <stdio.h>

void modify(int* value_pointer) {
    printf("value_pointer address (in method): %p\n", &value_pointer);

    printf("value address (in method): %p\n", value_pointer);
    *value_pointer = 10;
    printf("Modified value in method: %d\n", *value_pointer);
}

int main() {
    int value = 0;
    int* value_address = &value;
    printf("value address: %p\n", value_address);

    printf("value_address address: %p\n", &value_address);

    modify(value_address);

    printf("Modified value: %d\n", value);
    return 0;
}
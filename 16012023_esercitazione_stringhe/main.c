#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* str = "Hello World!\n";

    // Ciclo con variabile di iterazione
    for (int i = 0; str[i] != '\0'; i++) {
        char current_char = str[i];
        printf("%c (%d)\n", current_char, current_char);
    }

    // Ciclo con aritmetica dei puntatori
    char* ptr = str;
    while(*ptr != '\0') {
        printf("%c (%d)\n", *ptr, *ptr);
        ++ptr;
    }

    return 0;
}
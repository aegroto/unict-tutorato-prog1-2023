#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char name[100];
    char surname[100];
    unsigned int age;
};

void print_person(struct person* person) {
    printf("%s %s - %u\n", person->name, person->surname, person->age);
}

int main() {
    struct person aldo;
    strcpy(aldo.name, "aldo");
    strcpy(aldo.surname, "catania");
    aldo.age = 18;

    print_person(&aldo);

    printf("%lu\n", sizeof(aldo));

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char* name;
    char* surname;
    unsigned int age;
};

void print_person(struct person* person) {
    printf("%s %s - %u\n", person->name, person->surname, person->age);
}

void allocate(struct person* person_ptr) {
    person_ptr->name = (char*) malloc(sizeof(char) * 256);
    person_ptr->surname = (char*) malloc(sizeof(char) * 256);
}

void deallocate(struct person* person_ptr) {
    free(person_ptr->name);
    free(person_ptr->surname);
}

int main() {
    struct person aldo;
    allocate(&aldo);

    strcpy(aldo.name, "aldo");
    strcpy(aldo.surname, "catania");
    aldo.age = 18;

    print_person(&aldo);

    printf("%lu\n", sizeof(aldo));

    deallocate(&aldo);

    return 0;
}
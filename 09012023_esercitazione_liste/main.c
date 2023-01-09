/*
    1) Implementare una funzione che esegua l'inserimento in testa alla lista.
    2) Aggiungere un puntatore alla coda della lista ed ottimizzare la funzione insert() sfruttandolo. Assicurarsi che venga aggiornato ad ogni inserimento
    3) Implementare l'operazione di cancellazione della lista
    4) Implementare l'operazione di deallocazione dell'intera lista
*/
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
    printf("Hello world!\n");
    list_t* list = create_list();

    insert(list, 5);
    print_list(list);
    insert(list, 3);
    print_list(list);
    insert(list, -1);
    print_list(list);
    return 0;
}

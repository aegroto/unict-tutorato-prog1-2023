// valgrind --leak-check=full --show-leak-kinds=all ./a.out 3

#include "utils.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data s_data;
struct data{
    int N;
};


void readInput(s_data* params, int argc, char** argv){
    if(argc != 2) {
        fprintf(stderr,"numero di parametri errati\n");
        exit(-1);
    }

    char *end;

    params->N=strtol(argv[1], &end, 10);

    if(*end != '\0' || params->N < 0){
        fprintf(stderr,"il numero N non e' positivo, arresto\n");
        exit(-1);
    }
}

list_t* readFile(){
    FILE* fp=fopen("input.txt","r");
    if(fp == NULL){
        fprintf(stderr,"errore apertura file\n");
        exit(-1);
    }

    char B[1000];
    list_t *list = createList();

    while(fgets(B, 1000, fp) != NULL) {
        char* first_word = strtok(B, " ");
        char* word = first_word;
        int count=0;
        do{
            if(strcmp(first_word,word)==0){
                count++;
            }
        } while((word = strtok(NULL, " \n")));

        riga_t riga;
        strcpy(riga.word, first_word);
        riga.count = count;
        addNode(list, riga);
    }

    fclose(fp);

    return list;
}

int main(int argc, char** argv)
{
    s_data params;
    readInput(&params, argc, argv);
    printf("N: %d\n", params.N);

    list_t* list = readFile();

    filterList(list, params.N);
    printList(list);

    deallocateList(list);

    return 0;
}

/* Codificare una funzione in C che prenda in input un parametroù
formale matrice S di puntatori a carattere di dimensione N×M (S quindi contiene stringhe), 
uno short w ed uno short k, e restituisca il valore booleano true(1) se in S 
sono presenti almeno una riga ed almeno una colonna che presentano ciascuna almeno 
w stringhe di lunghezza minore di k*/

/*
    Esercizio 1: Modificare la funzione in modo che vengano contati il numero di stringhe di 
    cui si misura la lunghezza.
    Ottimizzare la funzione riducendo il numero di confronti.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(char ***S, int n, int m, short w, short k){
    int rows_condition = 0;
    for(int i = 0; i < n; ++i) {
        int strings_shorter_than_k = 0;
        for(int j = 0; j < m; ++j) {
            char* str = S[i][j];
            if(strlen(str) < k) {
                strings_shorter_than_k++;
            }
        }

        if(strings_shorter_than_k >= w) {
            rows_condition = 1;
            break;
        }
    }

    int columns_condition = 0;
    for(int j = 0; j < m; ++j) {
        int strings_shorter_than_k = 0;
        for(int i = 0; i < n; ++i) {
            char* str = S[i][j];
            if(strlen(str) < k) {
                strings_shorter_than_k++;
            }
        }

        if(strings_shorter_than_k >= w) {
            columns_condition = 1;
            break;
        }
    }

    return rows_condition && columns_condition;
}

#define N 2
#define M 3

int main(){
    char*** mat = malloc(sizeof(char**) * N);
    for(int r = 0; r < N; ++r) {
        mat[r] = malloc(sizeof(char*) * M);
    }

    mat[0][0] = "enrico";
    mat[0][1] = "gio";
    mat[0][2] = "mattia";
    mat[1][0] = "davide";
    mat[1][1] = "daniele";
    mat[1][2] = "lorenzo";

    /*char* mat[N][M] = {
        {"enrico", "giorgio", "mattia"},
        {"davide", "daniele", "lorenzo"},
    };*/

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            printf("%s ", mat[i][j]);
        }
        printf("\n");
    }

    int result = comp(mat, N, M, 2, 7);
    printf("Result: %d\n", result);
}
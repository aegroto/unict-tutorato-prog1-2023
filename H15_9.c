/* Codificare una funzione in C che prenda in input un array bidimensionale di dimensioni n × n di interi, ovvero una matrice quadrata. La funzione restituisca la differenza, in valore assoluto, tra la media aritmetica degli elementi della diagonale principale, 
e la media aritmetica degli elementi della diagonale secondaria. */

#include <stdio.h>
#include <math.h>

#define D 3

int matrice(int** a, int N) {
    // Diagonale principale
    int principale_sum = 0;
    for(int i=0; i<N; ++i) {
        int element = a[i][i];
        principale_sum += element;
    }
    int principale_mean = principale_sum / N;

    // Diagonale secondaria
    int secondaria_sum = 0;
    int max_column_index = N-1;
    for(int row=0; row<N; ++row) {
        int element = a[row][max_column_index-row];
        secondaria_sum += element;
    }
    int secondaria_mean = secondaria_sum / N;

    if(principale_sum > secondaria_sum) {
        return principale_sum - secondaria_sum;
    } else {
        return secondaria_sum - principale_sum ;
    }
}

// TODO: Realizzare un main di test
int main () {

}


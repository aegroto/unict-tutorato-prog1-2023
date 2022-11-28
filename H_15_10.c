/* Codificare una funzione in C che prenda in input un array bidimensionale di dimensioni n × m di interi senza segno, due short unsigned a e b (si assuma 0 ≤ a < b ≤ n), 
ed un terzo parametro in virgola mobile α. La funzione restituisca il numero di righe della matrice per cui vale la seguente proprietà: la media aritmetica degli elementi Aik (i rappresenta l’indice della generica riga) tali che a ≤ k ≤ b è un numero minore di α.
*/

#include <stdlib.h>

int func(unsigned int **A, unsigned int n, unsigned int m, short unsigned a, short unsigned b, float alfa)
{
    int count=0;

    for (int i=0; i<n; i++)
    {
        unsigned int somma=0;
        for (int j=a; j<=b; j++)
        {
            somma += A[i][j]; 
        }
        float media= ((float) somma) / (b-a+1);
        if (media<=alfa)
        {
            count+=1;
        }
    }
    
    return count;

}

// TODO: Completare il main
int main()
{
    int n = 6;
    int m = 4;
    int** A = (int**) malloc(n * sizeof(int*));
    for (int j = 0; j < m; ++j) {
        A[j] = (int*) malloc(m * sizeof(int));
    }

}
/*
(Lancio dei dadi) Scrivete un programma che simuli il lancio di due dadi. Il programma deve 
usare due volte rand per lanciare, rispettivamente, il primo dado e il secondo dado. Poi deve 
calcolare la somma dei due valori. [Nota: poiché ogni dado può mostrare sulla faccia supe riore un valore intero da 1 a 6, la somma dei due valori varierà allora da 2 a 12, con 7 che è 
la somma più frequente e 2 e 12 che sono le somme meno frequenti.] La Figura 6.24 mostra 
36 possibili combinazioni dei due dadi. Il vostro programma deve lanciare i due dadi 36.000 
volte. Usate un array unidimensionale per annotare il numero delle volte in cui compare ogni 
possibile somma. Stampate i risultati in un formato tabellare. Stabilite inoltre se i totali sono 
ragionevoli; cioè, vi sono sei modi di ottenere un risultato 7, così, approssimativamente, un 
sesto di tutti i lanci deve avere come somma 7.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    const int RUNS = 36000;
    int results[11] = { 0 };

    for(int i = 1; i <= RUNS; ++i) {
        printf(" --- Lancio #%d...\n", i);

        // valori randomici da 'min' a 'max':
        // min + (rand() % (min-max + 1))
        int first_dice = 1 + (rand() % 6);
        int second_dice = 1 + (rand() % 6);
        printf("Primo dado: %d\n", first_dice);
        printf("Secondo dado: %d\n", second_dice);
        int score = first_dice + second_dice;
        printf("Punteggio: %d\n", score);

        // passiamo dal range [2, 12] dei punteggi
        // al range [0, 10] degli indici nell'array
        int index = score - 2;

        results[index] += 1;
    }

    for(int s = 2; s <= 12; s++) {
        printf("[%d] \t| %d\n", s, results[s - 2]);
    }




    return 0;
}

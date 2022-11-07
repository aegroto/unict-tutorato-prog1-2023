/*
    Codificare un programma in linguaggio C che chieda all’utente di inserire
    da tastiera il proprio nome e cognome.
    Successivamente il programma dovr`a stampare le seguenti informazioni:

    1. il primo e l’ultimo carattere del nome, il secondo ed il terzo carattere del cognome.
    2. una stringa formata da tutti i caratteri che sono presenti sia nel nome che nel cognome.

    ES: se nome=”Mario”, cognome= ”Rossi” lo output sarà ”io”.

    3. le seg. ulteriori informazioni:
    a) un messaggio che comunica all’utente se la prima lettera del nome `e uguale all’ultima lettera del cognome.
    b) un messaggio che comunica all’utente se il numero di caratteri del nome `e uguale al numero di caratteri del cognome.
    c) il numero di consonanti del nome e del cognome.
*/

#include <stdio.h>
#include <string.h>

int main()
{

    char nome[20];    // Dichiarazione Stringa per il nome
    char cognome[20]; // Dichiarazione stringa per il cognome

    // Lettura nome
    printf("Nome: ");
    scanf("%[A-Za-z ]c", nome); // Inserimento cognome

    // Flush
    char f;
    do { 
        f = fgetc(stdin);
    } while(f != '\n' && f != EOF);

    // Lettura cognome
    printf("Cognome: ");
    scanf("%[A-Za-z ]c", cognome); // Inserimento cognome

    printf("\nNome : %s\nCognome: %s", nome, cognome); // Stampa nome e cognome

    int caratteri_Nome = 0; // Assegnazione variabile per conteggio dei caratteri del nome, inseriti dall'utente

    while (nome[caratteri_Nome] != '\0')
    { // Ciclo di conteggio caratteri del Nome.
        caratteri_Nome++;
    }

    printf("\nPrimo carattere del nome: \"%c\" , ultimo carattere del nome: \"%c\" \n", nome[0], nome[caratteri_Nome - 1]); // Stampa Primo ed Ultimo carattere del cognome.

    int caratteri_Cognome = 0; // Assegnazione variabile per conteggio dei caratteri del cognome, inseriti dall'utente

    while (cognome[caratteri_Cognome] != '\0')
    { // Ciclo di conteggio caratteri del cognome.
        caratteri_Cognome++;
    }

    printf("\nSecondo carattere del cognome: \"%c\" , terzo carattere: \"%c\"\n", cognome[1], cognome[2]); // Stampa Secondo e terzo carattere del cognome

    // STAMPA I CARATTERI DEL NOME E DEL COGNOME IN UN UNICO VETTORE.

    char totale_Caratteri[40]; // Dichiarazione stringa unica contenente tutti i caratteri del nome e del cognome
    for(int k = 0; k < 40; ++k) {
        totale_Caratteri[k] = '@';
    }

    int i = 0; // Variabile contatore per ciclo inserimento in unica stringa.

    while (nome[i] != '\0')
    {

        totale_Caratteri[i] = nome[i];
        i++;
    }

    int j = 0;

    while (cognome[j] != '\0')
    {

        totale_Caratteri[i] = cognome[j];
        j++;
        i++;
    }
    totale_Caratteri[i] = '\0';

    printf("Nome e cognome uniti: %s\n", totale_Caratteri);

    // CONTORLLO SE LA PRIMA LETTERA DEL NOME E' UGUALE ALL'ULTIMA LETTERA DEL COGNOME

    if (nome[0] == cognome[caratteri_Cognome - 1])
        printf("la prima lettera del nome è uguale all'ultima lettera del cognome\n");

    else
        printf("La prima lettera del nome NON è uguale all'ultima lettera del cognome\n");

    // SE IL NUMERO DI CARATTERI DEL NOME è UGUALE A QUELLO DEI CARATTERI DEL COGNOME

    if (caratteri_Nome == caratteri_Cognome)
        printf("Il nome ed il cognome hanno lo stesso numero di caratteri\n");
}

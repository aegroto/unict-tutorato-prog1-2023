#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// 0 = giusto
// 1 = answer > secret
// -1 = answer < secret
int compare_answer(int answer, int secret) {
    if(secret == answer) {
        return 0;
    } else if (answer > secret) {
        return 1;
    } else {
        return -1;
    }
}

void naive_player(int secret, int range_min, int range_max) {
    int attempts = 0;
    while(1) {
        ++attempts;
        int answer = rand_range(range_min, range_max);

        if(compare_answer(answer, secret) == 0) {
            printf("Giusto! Tentativi: %d\n", attempts);
            break;
        }
    }
}

void random_range_resize_player(int secret, int start_range_min, int start_range_max) {
    int range_min = start_range_min;
    int range_max = start_range_max;

    int attempts = 0;
    while(1) {
        ++attempts;
        int answer = rand_range(range_min, range_max);

        int result = compare_answer(answer, secret);
        if(result == 0) {
            printf("Giusto! Tentativi: %d\n", attempts);
            break;
        } else if(result == 1) {
            range_max = answer - 1;
        } else if(result == -1) {
            range_min = answer + 1;
        }
    }
}

void average_bet_range_resize_player(int secret, int start_range_min, int start_range_max) {
    int range_min = start_range_min;
    int range_max = start_range_max;

    int attempts = 0;
    while(1) {
        ++attempts;
        int answer = range_min + (range_max - range_min) / 2;

        int result = compare_answer(answer, secret);
        if(result == 0) {
            printf("Giusto! Tentativi: %d\n", attempts);
            break;
        } else if(result == 1) {
            range_max = answer - 1;
        } else if(result == -1) {
            range_min = answer + 1;
        }
    }
}

int main() {
    srand(time(0));

    const int SECRET_MIN = 0;
    const int SECRET_MAX = 100;

    // L'oracolo genera un numero segreto a caso
    int secret = rand_range(SECRET_MIN, SECRET_MAX);
    printf("Numero segreto: %d\n", secret);

    // I giocatori devono indovinare il numero
    printf("Giocatore banale: \n");
    naive_player(secret, SECRET_MIN, SECRET_MAX);
    printf("Giocatore che tira a caso ma ridimensiona il range: \n");
    random_range_resize_player(secret, SECRET_MIN, SECRET_MAX);
    printf("Giocatore che risponde con il numero a metà del range e lo ridimensiona: \n");
    average_bet_range_resize_player(secret, SECRET_MIN, SECRET_MAX);
    return 0;
}

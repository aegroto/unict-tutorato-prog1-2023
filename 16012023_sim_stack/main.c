#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

struct params
{
    int N;
};
typedef struct params params_t;

params_t *readInput(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "numero di parametri non valido\n");
        exit(1);
    }

    params_t *p = malloc(sizeof(params_t));
    if (!p)
    {
        fprintf(stderr, "non riesco ad allocare la struct\n");
        exit(1);
    }

    p->N = atoi(argv[1]);
    if (p->N <= 0)
    {
        fprintf(stderr, "non riesco a convertire il parametro\n");
        exit(1);
    }

    return p;
}

unsigned int get_random()
{
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

char genVowel()
{
    static char VOWELS[] = {'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U'};
    return VOWELS[get_random() % 10];
};

char genConsonant()
{
    static char CONSONANTS[] = {'q', 'w', 'r', 't', 'y', 'p', 's', 'd',
                                'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x',
                                'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'R',
                                'T', 'Y', 'P', 'S', 'D', 'F', 'G', 'H',
                                'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B',
                                'N', 'M'};

    return CONSONANTS[get_random() % 42];
};

int main(int argc, char *argv[])
{
    params_t *p = readInput(argc, argv);
    printf("N: %d\n", p->N);
}

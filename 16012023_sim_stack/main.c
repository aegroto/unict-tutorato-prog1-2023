#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "stack.h"

struct params
{
    int N;
    char v, w;
};
typedef struct params params_t;

int is_vowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == '0' || c == 'u');
}

params_t *readInput(int argc, char *argv[])
{
    if (argc != 4)
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
    if (p->N < 5 || p->N > 9)
    {
        fprintf(stderr, "non riesco a convertire il parametro\n");
        exit(1);
    }

    char v = argv[2][0];
    if (strlen(argv[2]) != 1 || !isalpha(v) || !is_vowel(v))
    {
        fprintf(stderr, "Non hai inserito una vocale minuscola come parametro v!");
        exit(-1);
    }
    p->v = v;

    char w = argv[3][0];
    if (strlen(argv[3]) != 1 || !isalpha(w) || is_vowel(w))
    {
        fprintf(stderr, "Non hai inserito una consonante minuscola come parametro w!");
        exit(-1);
    }
    p->w = w;

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

params_t* puntoA(int argc, char** argv) {
    params_t *p = readInput(argc, argv);
    printf("N: %d\n", p->N);
    printf("v: %c\n", p->v);
    printf("w: %c\n", p->w);

    return p;
}

void puntoB(params_t *p, stack_t *stack)
{
    for (size_t i = 0; i < p->N; i++)
    {
        char x = (char)(get_random() % 9 + 1);
        if (x < 5)
        {
            for (size_t j = 0; j < x; j++)
            {
                char c = genVowel();
                if (c == p->v)
                    c = '*';
                push(stack, c);
            }
        }
        else
        {
            for (size_t i = 0; i < x; i++)
            {
                char c = genConsonant();
                if (c == p->w)
                    c = '?';
                push(stack, c);
            }
        }
        push(stack, x);
    }
    push(stack, (char)p->N);

    print_stack(stack);
}

char** puntoC(stack_t* stack) {

    int N=(int)pop(stack);
    char** strings=malloc(sizeof(char*)*N);

    for (int i = 0; i < N; ++i)
    {    
        int x = (int)pop(stack);
        strings[i]=malloc(sizeof(char)*(x+2));
        strings[i][0] = (char) x;
        for(int q = 1; q <= x; ++q)
        {
            strings[i][q]=pop(stack);
        }
        strings[i][x + 1]='\0';
    }

    return strings; 
}
void puntoD(char** array, int n){
    
    for(int i=0;i<n;i++){
        printf("[%d] = %s\n", i, array[i]);
    }
}
int main(int argc, char *argv[])
{
    params_t *p = puntoA(argc, argv);
    stack_t stack = init();
    puntoB(p, &stack);
    char** array=puntoC(&stack);
    puntoD(array,p->N);
}
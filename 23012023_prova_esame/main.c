#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct parameters {

    char input[255];
    char output[255];

};
typedef struct parameters parameters_t;

struct fmatrix
{
    int n, m;
    float ***A;
};
typedef struct fmatrix fmatrix_t;

parameters_t readParameters(int argc, char*argv[]) {
    if (argc!=3) {

        fprintf(stderr,"Numero di parametri inseriti errato.");
        exit(-1);

    }

    parameters_t params;

    strcpy(params.input,argv[1]);
    strcpy(params.output,argv[2]);
    
    return params;
    
}

unsigned int get_random()
{
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

fmatrix_t createMatrix(parameters_t p)
{
    FILE *f = fopen(p.input, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Non sono riuscito ad aprire il file!");
        exit(-1);
    }

    int n = 0, m = 0, i = 0;
    
    while (!feof(f))
    {
        char line[255];
        fgets(line, 255, f);
        char *tok = strtok(line, " ");
        n++;
        if(i == 0)
        {
            do
            {
                i = 1;
                m++;
            } while ((tok = strtok(NULL, " ")));
        }
    }
    fseek(f, 0, 0);
    printf("n: %d\nm: %d\n", n, m);

    float ***A = malloc(sizeof(float**)*n);
    for (size_t i = 0; i < n; i++)
    {
        char line[255];
        fgets(line, 255, f);
        char *tok = strtok(line, " ");
        A[i] = malloc(sizeof(float*)*m);
        for (size_t j = 0; j < m; j++)
        {
            A[i][j] = malloc(sizeof(float));
            *(A[i][j]) = atof(tok);
            tok = strtok(NULL, " ");
        }
    }

    fmatrix_t fmatrix;
    fmatrix.A = A;
    fmatrix.n = n;
    fmatrix.m = m;
    return fmatrix;
}

void printMatrix(fmatrix_t f)
{
    for (size_t i = 0; i < f.n; i++)
    {
        for (size_t j = 0; j < f.m; j++)
        {
            printf("%.2f\t", *(f.A[i][j]));
        }
        puts("");
    }
    
}



int main(int argc, char **argv)
{

    parameters_t param =readParameters(argc,argv);
    printf("%s\t%s\n",param.input,param.output);
    fmatrix_t f = createMatrix(param);
    printMatrix(f);

    return 0;
}
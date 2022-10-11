#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    int matricula;
    char nome[50];
    float nota;
}Pessoa;

void quickSortMatricula(Pessoa [], int, int);
int partitionMatricula(Pessoa [], int, int, int *);
void quickSortNota(Pessoa [], int, int);
int partitionNota(Pessoa [], int, int, int *);
void quickSortNome(Pessoa [], int, int);
int partitionNome(Pessoa [], int, int, int *);

int main(int argc, char const *argv[])
{
    int N, op;
    Pessoa *pessoas;

    printf("Digite a quantidade de pessoas\n");
    scanf("%d", &N);

    pessoas = (Pessoa *) malloc(sizeof(Pessoa) * N);

    if(pessoas == NULL)
    {
        printf("Deu erro na alocacao\n");
        exit(-1);
    }

    for(int i = 0; i < N; i++)
    {
        printf("Digite o numero da matricula\n");
        scanf("%d", &pessoas[i].matricula);

        printf("Digite o nome\n");
        scanf("%s", pessoas[i].nome);
        setbuf(stdin, NULL);

        printf("Digite a nota\n");
        scanf("%f", &pessoas[i].nota);

        system("cls");
    }
    
    printf("Digite a opcao de ordenacao\n");
    printf("1 - Ordenar pela matricula\n");
    printf("2 - Ordenar pelo nome\n");
    printf("3 - Ordenar pela nota\n");
    scanf("%d", &op);

    switch(op)
    {
        case 1:
            quickSortMatricula(pessoas, 0, N - 1);
            break;
        case 2:
            quickSortNome(pessoas, 0, N - 1);
            break;
        case 3:
            quickSortNota(pessoas, 0, N - 1);
            break;
        default:
            printf("opcao invalida.\n");
    }

    for(int i = 0; i < N; i++)
    {
        printf("Matricula = %d,  Nome = %s,   Nota = %.2f.\n", pessoas[i].matricula, pessoas[i].nome, pessoas[i].nota);
    }

    return 0;
}

void quickSortMatricula(Pessoa pessoas[], int inicio, int final)
{
    int pos;

    if(inicio >= final)
        return;
    
    partitionMatricula(pessoas, inicio, final, &pos);
    quickSortMatricula(pessoas, inicio, pos - 1);
    quickSortMatricula(pessoas, pos + 1, final);
    
}

int partitionMatricula(Pessoa pessoas[], int inicio, int final, int *pos)
{
    Pessoa *pivo = &pessoas[inicio];
    int down = inicio, up = final;
    Pessoa buff;
   
    while(down <= up)
    {
        while((pessoas[down].matricula <= pivo->matricula) && (down <= up))
            down++;
        while(pessoas[up].matricula > pivo->matricula)
            up--;
        if(down < up)
        {
            buff = pessoas[down];
            pessoas[down] = pessoas[up];
            pessoas[up] = buff;
        }
    }

    *pos = up;
    buff = pessoas[up];
    pessoas[up] = pessoas[inicio];
    pessoas[inicio] = buff;  
}

void quickSortNota(Pessoa pessoas[], int inicio, int final)
{
    int pos;

    if(inicio >= final)
        return;
    
    partitionNota(pessoas, inicio, final, &pos);
    quickSortNota(pessoas, inicio, pos - 1);
    quickSortNota(pessoas, pos + 1, final);
}

int partitionNota(Pessoa pessoas[], int inicio, int final, int *pos)
{
    Pessoa *pivo = &pessoas[inicio];
    int down = inicio, up = final;
    Pessoa buff;
   
    while(down <= up)
    {
        while((pessoas[down].nota <= pivo->nota) && (down <= up))
            down++;
        while(pessoas[up].nota > pivo->nota)
            up--;
        if(down < up)
        {
            buff = pessoas[down];
            pessoas[down] = pessoas[up];
            pessoas[up] = buff;
        }
    }

    *pos = up;
    buff = pessoas[up];
    pessoas[up] = pessoas[inicio];
    pessoas[inicio] = buff; 
}

void quickSortNome(Pessoa pessoas[], int inicio, int final)
{
    int pos;

    if(inicio >= final)
        return;
    
    partitionNome(pessoas, inicio, final, &pos);
    quickSortNome(pessoas, inicio, pos - 1);
    quickSortNome(pessoas, pos + 1, final);
}

int partitionNome(Pessoa pessoas[], int inicio, int final, int *pos)
{
    Pessoa *pivo = &pessoas[inicio];
    int down = inicio, up = final;
    Pessoa buff;
   
    while(down <= up)
    {
        while((strcmp(pessoas[down].nome, pivo->nome)) != 1 && (down <= up))
            down++;
        while(strcmp(pessoas[up].nome, pivo->nome) == 1)
            up--;
        if(down < up)
        {
            buff = pessoas[down];
            pessoas[down] = pessoas[up];
            pessoas[up] = buff;
        }
    }

    *pos = up;
    buff = pessoas[up];
    pessoas[up] = pessoas[inicio];
    pessoas[inicio] = buff; 
}


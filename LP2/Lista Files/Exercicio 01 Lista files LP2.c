#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void escreve(int *, int );
void ler(int *, int , int *, int *, int *);

int main()
{
    int vetor[TAM] = {0,1,2,3,4}, vetorAux[TAM], maior, menor, media, i;

    escreve(vetor, TAM);
    ler(vetorAux, TAM, &maior, &menor, &media);

    for(i = 0; i < TAM; i++)
        printf("%d ", vetorAux[i]);

    printf("Media = %d\n", media);
    printf("Maior = %d\n", maior);
    printf("Menor = %d\n", menor);

    return 0;
}

void escreve(int *v, int tam)
{
    FILE *arquivo;
    int i;
    arquivo = fopen("MediaVetor.txt", "w");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir.\n");
        exit(-1);
    }

    for(i = 0; i < tam; i++)
       fprintf(arquivo, "%d\n", v[i]);

    fclose(arquivo);
}
void ler(int *v, int tam, int *pMaior, int *pMenor, int *pMedia)
{
    FILE *arquivo;
    int i = 0;
    arquivo = fopen("MediaVetor.txt", "r");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir.\n");
        exit(-1);
    }

    fscanf(arquivo, "%d", &v[i]);
    *pMaior = v[i];
    *pMenor = v[i];
    *pMedia = v[i];

    for(i = 1; i < tam; i++)
    {
       fscanf(arquivo, "%d", &v[i]);

        if(*pMaior < v[i])
            *pMaior = v[i];

        if(*pMenor > v[i])
            *pMenor = v[i];

       *pMedia += v[i];
    }

    *pMedia /= tam;

    fclose(arquivo);
}

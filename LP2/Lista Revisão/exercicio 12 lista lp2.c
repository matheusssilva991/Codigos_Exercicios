/*
    Exercício Revisão
    
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tamanhoVetor, *vetor, *vetorAux;

    printf("digite o tamanho do vetor:\n");
    scanf("%d", &tamanhoVetor);

    vetor = (int *) malloc(sizeof(int) * tamanhoVetor);
    vetorAux = (int *) malloc(sizeof(int) * tamanhoVetor);

    srand(time(NULL));

    for(int i = 0; i < tamanhoVetor; i++)
    {
        vetor[i] = rand() % 10;

        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
    printf("\n");

    for(int i = 0; i < tamanhoVetor; i++)
    {
        vetorAux[i] = vetor[tamanhoVetor - i - 1];
        printf("Vetor[%d] = %d\n", i, vetorAux[i]);
    }

    free(vetor);
    free(vetorAux);

    return 0;
}

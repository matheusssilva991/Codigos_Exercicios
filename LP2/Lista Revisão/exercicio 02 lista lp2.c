/*
    Exercício de revisão 
    Média de 3 notas
*/

#include <stdio.h>
#include <stdlib.h>
#define QUANTIDADENOTAS 3

int main()
{
    float notas[3];
    float media = 0;

    for(int i = 1; i <= QUANTIDADENOTAS; i++)
    {
        printf("Digite a %d nota \n", i);
        scanf("%f", &notas[i - 1]);

        media += notas[i - 1];
    }
    
    media /= QUANTIDADENOTAS;

    printf("Media: %.3f", media);

    return 0;
}

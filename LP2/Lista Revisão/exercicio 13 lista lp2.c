#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tamanho, deslocamento;
    int *array, *auxArray;

    printf("Digite o tamanho do array\n");
    scanf("%d", &tamanho);

    printf("Digite o deslocamento a esquerda do array\n");
    scanf("%d", &deslocamento);
    setbuf(stdin, NULL);

    array = (int *) malloc(sizeof(int) * tamanho);
    auxArray = (int *) malloc(sizeof(int) * tamanho);

    if(array == NULL || auxArray == NULL)
        exit(-1);

    srand(time(NULL));

    deslocamento--;

    for(int i = 0; i < tamanho; i++)
    {
        array[i] = rand() % 50;

        for(int j = 0; j < tamanho; j++)
            if(array[i] == array[j])
                array[i] = rand() % 50;

        printf(" [ %d ]", array[i]);
    }

    if(deslocamento >= tamanho)
        deslocamento = deslocamento % tamanho;

    printf("\n\n");

    for(int i = tamanho - 1; i >= 0; i--)
    {
        if(i - deslocamento >= 0)
            auxArray[i - deslocamento] = array[i];
        else
            auxArray[i + tamanho - deslocamento] = array[i];
    }
    printf("Apos o deslocamento \n\n");

    for(int i = 0; i < tamanho; i++)
        printf(" [ %d ]", auxArray[i]);

    return 0;
}


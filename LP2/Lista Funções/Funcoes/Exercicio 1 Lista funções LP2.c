#include <stdio.h>
#include <stdlib.h>

int *decToBin(int );
void printBinary(int *const);

int main(int argc, char *argv[])
{
	int decimal, *binary;

	printf("Digite o decimal: \n");
	scanf("%d", &decimal);
	setbuf(stdin, NULL);

	binary = decToBin(decimal);
    printBinary(binary);

    free(binary);

	return 0;
}

int *decToBin(int decimal)
{
    int i = 0, j, *ptrBinary;

    if(decimal < 255) // alocar o minimo de memoria
        ptrBinary = (int *) malloc(8 * sizeof(int));
    else
        ptrBinary = (int *) malloc(16 * sizeof(int));

    if(ptrBinary == NULL)
        exit(-1);

    while(decimal > 0)
    {
        ptrBinary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    ptrBinary[i] = -1;

    return ptrBinary;
}

void printBinary(int *const ptr)
{
    int i;

    for(i = 0; ptr[i] != -1; i++);

    for(i = i - 1; i >= 0; i--)
        printf("%d", ptr[i]);

    printf("\n");
}

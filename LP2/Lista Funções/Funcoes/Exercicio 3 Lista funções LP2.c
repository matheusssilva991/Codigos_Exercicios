#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverse(char *const);

int main(int argc, char *argv[])
{
    char numero[20];

    printf("Digite o numero: \n");
    scanf("%s", &numero);
    setbuf(stdin, NULL);

    inverse(numero);

    printf("Numero invertido: %s\n", numero);

	return 0;
}

void inverse(char *const num)
{
    int i, j, tam = strlen(num);
    char aux;

	for(i = 1; i < tam - 1; i++)
   		for(j = 0; j < tam - 1; j++)
        {
            aux = num[j];
            num[j] = num[j + 1];
            num[j + 1] = aux;
        }
	
	aux = num[0];
	num[0] = num[1];
	num[1] = aux;
	
}

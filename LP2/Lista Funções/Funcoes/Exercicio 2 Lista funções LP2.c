#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int binaryToDecimal(char *const);

int main(int argc, char *argv[])
{
	int dec;
    char bin[16];

	printf("Digite o numero binario: \n");
	gets(bin);
	setbuf(stdin, NULL);

    dec = binaryToDecimal(bin);

    printf("%d", dec);

	return 0;
}

int binaryToDecimal(char *const b)
{
    int i, j, aux = 0;

    for(i = strlen(b) - 1, j = 0; i >=0; i--, j++)
        aux += pow(2, j) * (b[i] - '0');

    return aux;
}


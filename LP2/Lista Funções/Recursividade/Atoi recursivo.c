#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int potencia(int , int );
int atoiRec(char *, int );

int main()
{
    char numeroChar[] = "7546"; /// ele era uma string
    int numero = 0, tamanho;

    tamanho = strlen(numeroChar) - 1; // pega o tamanho da string

    printf("Numero antes da funcao Atoi = %d\n", numero);

    numero = atoiRec(numeroChar, tamanho);

    printf("depois da funcao atoi = %d", numero);

    return 0;
}

int atoiRec(char *num, int tam)
{
    int aux;

    if(*num == '\0')
        return 0;

    aux = *num - '0'; // transformaar o caracter em int
    aux *=  potencia(10, tam); // multiplica o numero por 10 ^ tamanho

    return aux + atoiRec(++num, --tam);

}

int potencia(int base, int exp) ///
{
    if(exp == 0)
        return 1;

    else
        return base * potencia(base, exp - 1);
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int palindromo(char *, char *);
int main()
{
    char palavra[] = "ana";
    char *pInicio, *pFinal;

    //printf("digite a palavra a ser testada:\n");
    //scanf("%[^n]", palavra);

    pInicio = palavra;

    pFinal = &palavra[strlen(palavra) - 1]; 

    if(palindromo(pInicio, pFinal))
        printf("e paliondromo");

    else
        printf("nao e");

    return 0;
}

int palindromo(char *inicio, char *fim)
{
    if(*inicio == '\0')
        return 1;

    if(*inicio != *fim)
        return 0;
    else
        return palindromo(++inicio, --fim);
}


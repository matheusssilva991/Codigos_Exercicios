#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inversorRec(char *);

int main(void)
{
    char numero[] = "1975", *numeroInvertido, tamanhoNumero;

    numeroInvertido = inversorRec(numero);
    tamanhoNumero = strlen(numero);

    while(tamanhoNumero > 0)
    {
        printf("%c", *numeroInvertido);
        tamanhoNumero--;
        numeroInvertido--;
    }
    return 0;
}

char *inversorRec(char *s)
{
    if(*s == '\0')
        return --s;
    else
        return inversorRec(++s);
}

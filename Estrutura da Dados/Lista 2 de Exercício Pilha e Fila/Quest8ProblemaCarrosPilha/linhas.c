#include "linhas.h"

LINHAENTRADA* createEntrada()
{
    LINHAENTRADA *linha;

    linha = (LINHAENTRADA *) malloc(sizeof(LINHAENTRADA));

    if(linha == NULL)
    {
        printf("erro ao alocar.");
        return NULL;
    }

    linha->next = NULL;

    return linha;
}

void freeLinha(LINHAENTRADA *linha)
{
    free(linha);
}
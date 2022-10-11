#if !defined(LINHAS_H)
#define LINHAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct linhasEntrada
{
    char escolha;
    int placaCarro;
    struct linhasEntrada *next;
}LINHAENTRADA;

LINHAENTRADA* createEntrada();
void freeLinha(LINHAENTRADA*);

#endif // LINHAS_H

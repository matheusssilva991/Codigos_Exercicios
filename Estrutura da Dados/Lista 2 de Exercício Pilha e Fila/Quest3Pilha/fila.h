#if !defined(FILA_H)
#define FILA_H

#include "element.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct fila{
    int size;
    ELEMENT* first;
}PILHA;

void initialize(PILHA*);
int isEmpty(PILHA*);
int pop(PILHA*);
void push(PILHA*, int);
ELEMENT* findLast(PILHA* ptrLista);

#endif // FILA_H

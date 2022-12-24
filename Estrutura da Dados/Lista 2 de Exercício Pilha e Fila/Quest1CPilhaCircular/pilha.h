#if !defined(pilha_H)
#define pilha_H

#include "element.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct pilha{
    int size;
    ELEMENT* top;
}PILHA;

void initialize(PILHA*);
int isEmpty(PILHA*);
void push(PILHA*, int);
int pop(PILHA*);
ELEMENT* findFirst(PILHA* ptrLista);

#endif // pilha_H

#if !defined(PILHA_H)
#define PILHA_H

#include "element.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct pilha{
    int size;
    ELEMENT* top;
}PILHA;

void initialize(PILHA*);
int isEmpty(PILHA*);
void insLeft(PILHA*, int);
int remLeft(PILHA*);
void insRight(PILHA*, int);
int remRight(PILHA*);
ELEMENT* findRight(PILHA* ptrLista);

#endif // "PILHA_H"


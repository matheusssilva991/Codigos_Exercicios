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
void push(PILHA*, int);
int pop(PILHA*);

#endif // PILHA_H

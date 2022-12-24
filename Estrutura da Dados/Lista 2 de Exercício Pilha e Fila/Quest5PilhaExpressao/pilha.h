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
void push(PILHA*, char);
char pop(PILHA*);
void colocaExpressao(PILHA *, char *);
void limpaExpressao(PILHA *);
int verificaExpressao(PILHA *);

#endif // PILHA_H

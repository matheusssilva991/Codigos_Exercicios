#if !defined(FILA_H)
#define FILA_H

#include "element.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct fila{
    int size;
    ELEMENT* top;
}FILA;

void initialize(FILA*);
int isEmpty(FILA*);
void toQueue(FILA*, int);
int deQueue(FILA*);
void printLista(FILA *);

#endif // STACKELEMENT_H

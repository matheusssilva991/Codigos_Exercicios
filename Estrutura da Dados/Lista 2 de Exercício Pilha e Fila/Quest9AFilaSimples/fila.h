#if !defined(FILA_H)
#define FILA_H

#include "element.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct fila{
    int size;
    ELEMENT* first;
}FILA;

void initialize(FILA*);
int isEmpty(FILA*);
int deQueue(FILA*);
void toQueue(FILA*, int);
ELEMENT* findLast(FILA* ptrLista);
void printLista(FILA *);

#endif // FILA_H

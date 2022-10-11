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
void insLeft(FILA*, int);
int remLeft(FILA*);
void insRight(FILA*, int);
int remRight(FILA*);
ELEMENT* findRight(FILA* ptrLista);
void printLista(FILA *ptrLista);

#endif // FILA_H

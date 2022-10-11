#if !defined(RUACOLCIC_H)
#define RUACOLCIC_H

#include "linhas.h"

typedef struct ruaColcic
{
    int quantidade;
    LINHAENTRADA *first;
}RUACOLCIC;

void initializeRuaColcic(RUACOLCIC*);
int isEmptyRuaColcic(RUACOLCIC*);
void toQueue(RUACOLCIC*, char, int);
int deQueue(RUACOLCIC*);
void printEntradas(RUACOLCIC *);

#endif // RUACOLCIC_H

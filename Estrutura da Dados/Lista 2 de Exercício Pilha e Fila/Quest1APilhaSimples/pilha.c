#include "pilha.h"

/*
definições da biblioteca stackElement.c
*/
void initialize(PILHA* ptrLista){
    ptrLista->size = 0;
    ptrLista->top = NULL;
}

int isEmpty(PILHA* ptrLista){
    return (ptrLista->top == NULL) ? 1 : 0;
}


void push(PILHA* ptrLista, int value){
    ELEMENT *newElement;

    newElement = createElement();

    newElement->info = value;
    newElement->next = ptrLista->top;

    ptrLista->top = newElement;

    ptrLista->size++;
}

int pop(PILHA* ptrLista)
{
    int info;
    ELEMENT *elementRemove;

    if(isEmpty(ptrLista))
        return -1;

    elementRemove = ptrLista->top;
    info = elementRemove->info;

    ptrLista->top = elementRemove->next;    

	ptrLista->size--;

    freeElement(elementRemove);
	
    return info;
}

int popn(PILHA* ptrLista, int valorRemovido)
{
    FILA *aux;
    ELEMENT *elementRemove;
    int infoGuarda;

    elementRemove = ptrLista->top;

    while(elementRemove->info != valorRemovido)
    {
        toqueue(aux, pop(ptrLista));
        elementRemove = ptrLista->top;
    }

    infoGuarda = elementRemove->info;
    pop(ptrLista);

    while(!isEmpty(aux))
    {
        push(ptrLista, dequeue(aux));
    }

    return infoGuarda;
}
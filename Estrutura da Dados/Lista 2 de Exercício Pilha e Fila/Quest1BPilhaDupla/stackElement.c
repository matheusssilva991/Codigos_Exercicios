#include "stackElement.h"

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

    if(!isEmpty(ptrLista))
        newElement->next->previous = newElement;

    ptrLista->top = newElement;
    ptrLista->size++;
}

int pop(PILHA* ptrLista)
{
    int infoTemp;
    ELEMENT *elementRemove;

    if(isEmpty(ptrLista))
    {
        printf("Lista vazia.\n");
        return -1;
    }

    elementRemove = ptrLista->top;
    infoTemp = elementRemove->info;

    if(ptrLista->size == 1)
        ptrLista->top = NULL;
    else
    {
        ptrLista->top = elementRemove->next; 
        ptrLista->top->previous = NULL;
    }

    freeElement(elementRemove);

	--ptrLista->size;

    return infoTemp;
}
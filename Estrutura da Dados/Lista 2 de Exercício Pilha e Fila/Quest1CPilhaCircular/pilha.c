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
    ELEMENT *lastElement;

    newElement = createElement();
    newElement->info = value;

    if(isEmpty(ptrLista)) 
        newElement->next = newElement;
    else
        newElement->next = ptrLista->top;

    ptrLista->top = newElement;

    lastElement = findFirst(ptrLista);
    lastElement->previous = ptrLista->top;

    newElement->next->previous = newElement;
    newElement->previous = lastElement;
  
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
        ptrLista->top->previous = findFirst(ptrLista);

        freeElement(elementRemove);

        elementRemove = findFirst(ptrLista);
        elementRemove->previous = ptrLista->top;
    } 

	--ptrLista->size;

    return infoTemp;
}

ELEMENT* findFirst(PILHA* ptrLista){
	ELEMENT* auxElement;

	if(isEmpty(ptrLista))
        return NULL;

	auxElement = ptrLista->top;
	
	for(int i = 0; i < ptrLista->size - 1; ++i)
        auxElement = auxElement->next;
	
	return auxElement;
}
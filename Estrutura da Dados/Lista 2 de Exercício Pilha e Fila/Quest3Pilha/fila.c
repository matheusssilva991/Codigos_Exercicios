#include "fila.h"

/*
definições da biblioteca fila.c
*/
void initialize(PILHA* ptrLista){
    ptrLista->size = 0;
    ptrLista->first = NULL;
}

int isEmpty(PILHA* ptrLista){
    return (ptrLista->first == NULL) ? 1 : 0;
}

ELEMENT* findLast(PILHA* ptrLista){
	ELEMENT* auxElement;

	if(isEmpty(ptrLista))
        return NULL;

	auxElement = ptrLista->first;
	
	while(auxElement->next != NULL)
		auxElement = auxElement->next;
	
	return auxElement;
}

int pop(PILHA* ptrLista)
{
    int info;
    ELEMENT *elementRemove;
    ELEMENT *lastElement;

    if(isEmpty(ptrLista))
        return -1;   

    lastElement = findLast(ptrLista);

    while(ptrLista->first != lastElement)
    {
        elementRemove = ptrLista->first; 
        info = elementRemove->info; 

        ptrLista->first = elementRemove->next; 

        push(ptrLista, info); 
        ptrLista->size--;

        freeElement(elementRemove);
    }

    elementRemove = ptrLista->first; 
    info = elementRemove->info; // pega a info

    ptrLista->first = elementRemove->next;

	ptrLista->size--;

    freeElement(elementRemove);
	
    return info;
}

void push(PILHA* ptrLista, int newInfo)
{
    ELEMENT* newElement;
    ELEMENT* topElement;
    
    topElement = findLast(ptrLista);
    
	newElement = createElement();
    newElement->info = newInfo;
    
    if(topElement == NULL)
    {
        topElement = newElement;
        ptrLista->first = topElement;
    }      
    else
        topElement->next = newElement;

    ptrLista->size++;
}


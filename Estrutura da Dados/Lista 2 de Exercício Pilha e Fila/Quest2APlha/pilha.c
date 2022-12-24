#include "pilha.h"

/*
definições da biblioteca pilha.c
*/
void initialize(PILHA* ptrLista){
    ptrLista->size = 0;
    ptrLista->top = NULL;
}

int isEmpty(PILHA* ptrLista){
    return (ptrLista->top == NULL) ? 1 : 0;
}

ELEMENT* findRight(PILHA* ptrLista){
	ELEMENT* auxElement;

	if(isEmpty(ptrLista))
        return NULL;

	auxElement = ptrLista->top;
	
	while(auxElement->next != NULL)
		auxElement = auxElement->next;
	
	return auxElement;
}

void insLeft(PILHA* ptrLista, int value){
    ELEMENT *newElement;

    newElement = createElement();

    newElement->info = value;
    newElement->next = ptrLista->top;

    ptrLista->top = newElement;

    ptrLista->size++;
}

int remLeft(PILHA* ptrLista)
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

void insRight(PILHA* ptrLista, int newInfo)
{
    ELEMENT* newElement;
    ELEMENT* rightElement;
    
    rightElement = findRight(ptrLista);
    
	newElement = createElement();
    newElement->info = newInfo;
    
    if(rightElement == NULL)
    {
        rightElement = newElement;
        ptrLista->top = rightElement;
    }      
    else
        rightElement->next = newElement;

    ptrLista->size++;
}

int remRight(PILHA* ptrLista)
{
    ELEMENT* rightElement;
    ELEMENT* tempElement;
    int info;

    if(isEmpty(ptrLista))
    {
        printf("lista vazia.");
        return -1;
    }

    rightElement = findRight(ptrLista);
    
	tempElement = ptrLista->top;
	
	if(tempElement == rightElement)
		ptrLista->top = NULL;
	else
		while(tempElement->next != rightElement)
			tempElement = tempElement->next;
    
    info = rightElement->info;
    
    tempElement->next = NULL;
    
    freeElement(rightElement);
	
	ptrLista->size--;
	
    return info;

}
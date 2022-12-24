#include "fila.h"

/*
definições da biblioteca fila.c
*/
void initialize(FILA* ptrLista){
    ptrLista->size = 0;
    ptrLista->first = NULL;
}

int isEmpty(FILA* ptrLista){
    return (ptrLista->first == NULL) ? 1 : 0;
}

ELEMENT* findLast(FILA* ptrLista){
	ELEMENT* auxElement;

	if(isEmpty(ptrLista))
        return NULL;

	auxElement = ptrLista->first;
	
	for(int i = 0; i < ptrLista->size - 1; ++i)
        auxElement = auxElement->next;
	
	return auxElement;
}


int deQueue(FILA* ptrLista)
{
    int info;
    ELEMENT *elementRemove;

    if(isEmpty(ptrLista))
        return -1;

    elementRemove = ptrLista->first;
    info = elementRemove->info;

    ptrLista->first = elementRemove->next;   

	ptrLista->size--;

    freeElement(elementRemove);

    elementRemove = findLast(ptrLista);
    elementRemove->next = ptrLista->first;
    ptrLista->first->previous = elementRemove;

    return info;
}

void toQueue(FILA* ptrLista, int newInfo)
{
    ELEMENT* newElement;
    ELEMENT* lastElement;
    
    lastElement = findLast(ptrLista);
    
	newElement = createElement();
    newElement->info = newInfo;
    
    if(lastElement == NULL)
    {
        newElement->previous = newElement;
        newElement->next = newElement;
        ptrLista->first = newElement;  
    }      
    else
    {
        newElement->next = ptrLista->first;
        lastElement->next = newElement;
        newElement->previous = lastElement;
        ptrLista->first->previous = newElement;
    }

    ptrLista->size++;
}

void printLista(FILA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->first;

    while(aux != NULL)
    {
        printf("current = %d\n",  aux->info); 
        aux = aux->next;
    }

    printf("\n");
}
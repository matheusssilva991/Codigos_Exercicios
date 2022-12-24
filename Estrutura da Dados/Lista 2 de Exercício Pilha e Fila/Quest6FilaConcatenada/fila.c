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
	
	while(auxElement->next != NULL)
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
	
    return info;
}

void toQueue(FILA* ptrLista, int newInfo)
{
    ELEMENT* newElement;
    ELEMENT* LastElement;
    
    LastElement = findLast(ptrLista);
    
	newElement = createElement();
    newElement->info = newInfo;
    
    if(LastElement == NULL)
    {
        LastElement = newElement;
        ptrLista->first = LastElement;
    }      
    else
        LastElement->next = newElement;

    ptrLista->size++;
}

void printLista(FILA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->first;

    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->next;
    }

    printf("\n");
}

FILA* filaConcatenada(FILA *F1, FILA *F2)
{
    while (!isEmpty(F2))
    {
        toQueue(F1, deQueue(F2));
    }
    return F1;  
}

FILA *filaConcatenadaRecursiva(FILA *F1, FILA *F2)
{  
    if(!isEmpty(F2))
    {
        toQueue(F1, deQueue(F2));
        filaConcatenadaRecursiva(F1,F2);
    }

    return F1;
}

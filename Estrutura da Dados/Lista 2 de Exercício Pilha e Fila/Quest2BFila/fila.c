#include "fila.h"

/*
definições da biblioteca stackElement.c
*/
void initialize(FILA* ptrLista){
    ptrLista->size = 0;
    ptrLista->first = NULL;
}

int isEmpty(FILA* ptrLista){
    return (ptrLista->first == NULL) ? 1 : 0;
}

ELEMENT* findRight(FILA* ptrLista){
	ELEMENT* auxElement;

	if(isEmpty(ptrLista))
        return NULL;

	auxElement = ptrLista->first;
	
	while(auxElement->next != NULL)
		auxElement = auxElement->next;
	
	return auxElement;
}

void insLeft(FILA* ptrLista, int value){
    ELEMENT *newElement;

    newElement = createElement();

    newElement->info = value;
    newElement->next = ptrLista->first;

    ptrLista->first = newElement;

    ptrLista->size++;
}

int remLeft(FILA* ptrLista)
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

void insRight(FILA* ptrLista, int newInfo)
{
    ELEMENT* newElement;
    ELEMENT* rightElement;
    
    rightElement = findRight(ptrLista);
    
	newElement = createElement();
    newElement->info = newInfo;
    
    if(rightElement == NULL)
    {
        rightElement = newElement;
        ptrLista->first = rightElement;
    }      
    else
        rightElement->next = newElement;

    ptrLista->size++;
}

int remRight(FILA* ptrLista)
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
    
	tempElement = ptrLista->first;
	
	if(tempElement == rightElement)
		ptrLista->first = NULL;
	else
		while(tempElement->next != rightElement)
			tempElement = tempElement->next;
    
    info = rightElement->info;
    
    tempElement->next = NULL;
    
    freeElement(rightElement);
	
	ptrLista->size--;
	
    return info;

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
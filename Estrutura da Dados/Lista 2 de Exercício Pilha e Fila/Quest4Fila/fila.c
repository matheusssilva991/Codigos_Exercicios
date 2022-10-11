#include "fila.h"

/*
definições da biblioteca stackElement.c
*/
void initialize(FILA* ptrLista){
    ptrLista->size = 0;
    ptrLista->top = NULL;
}

int isEmpty(FILA* ptrLista){
    return (ptrLista->top == NULL) ? 1 : 0;
}

void toQueue(FILA* ptrLista, int value){
    ELEMENT *newElement;

    newElement = createElement();

    newElement->info = value;
    newElement->previous = ptrLista->top;

    ptrLista->top = newElement;

    ptrLista->size++;
}

int deQueue(FILA* ptrLista)
{
    int info, infoRemovida = 0;
    ELEMENT *elementRemove;
    FILA *auxLista;

    if(isEmpty(ptrLista))
        return -1;

    auxLista = (FILA *) malloc(sizeof(FILA));

    if(auxLista == NULL)
        return -1;

    initialize(auxLista);

    while(ptrLista->top != NULL)
    {
        elementRemove = ptrLista->top; // pega o ponteiro para o ultimo elemento
        info = elementRemove->info; // guarda a informação dele

        toQueue(auxLista, info); // passa a info para a outra lista

        ptrLista->top = elementRemove->previous; // aponta para o antepenultimo

        freeElement(elementRemove); // remove o ultimo da lista
    }   

    elementRemove = auxLista->top; // pega o ponteiro para o primeiro
    infoRemovida = elementRemove->info; // guarda a informação dele

    auxLista->top = elementRemove->previous; // aponta para o segundo
    freeElement(elementRemove); // remove o primeiro da lista

    ptrLista->size--;
    
    while (!isEmpty(auxLista))
    {
        elementRemove = auxLista->top; // pega o ponteiro para o ultimo elemento
        info = elementRemove->info; // guarda a informação dele

        toQueue(ptrLista, info); // passa a info para a outra lista
        ptrLista->size--;

        auxLista->top = elementRemove->previous;

        freeElement(elementRemove); // remove o ultimo da lista
    }
	
    return infoRemovida;
}

void printLista(FILA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->top;

    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->previous;
    }

    printf("\n");
}
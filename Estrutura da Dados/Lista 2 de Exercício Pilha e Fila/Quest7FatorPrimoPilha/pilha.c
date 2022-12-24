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

void printLista(PILHA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->top;

    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->next;

        if(aux != NULL)
            printf("* ");
    }

    printf("\n");
}

void fatoresPrimos(int numero)
{
    PILHA *primos;

    primos = (PILHA *) malloc(sizeof(PILHA));

    if (primos == NULL)
    {
        printf("Erro ao alocar");
        return;
    }

    initialize(primos);
    
    while(numero != 1)
    {
        for(int i = 2; i <= numero; ++i)
        {
            if(numero % i == 0)
            {
                push(primos, i);
                numero /= i;
                break;
            }
        }
    }

    printLista(primos);
    liberaLista(primos);
}

void liberaLista(PILHA *ptrPilha)
{
    while(!isEmpty(ptrPilha))
        pop(ptrPilha);  
}

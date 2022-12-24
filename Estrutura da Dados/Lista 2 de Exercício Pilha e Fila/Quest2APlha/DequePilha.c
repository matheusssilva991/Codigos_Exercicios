#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pilha.h"

void printLista(PILHA *ptrLista);

int main(){

    PILHA lista;

    initialize(&lista);

    insLeft(&lista, 10);
    insLeft(&lista, 20);
    insLeft(&lista, 30);
    insRight(&lista, 5);
    printLista(&lista);
    printf("saiu o %d\n", remLeft(&lista));
    printLista(&lista);
    printf("saiu o %d\n", remRight(&lista));
    printLista(&lista);
    printf("saiu o %d\n", remLeft(&lista));
    printLista(&lista);
    printf("saiu o %d\n", remLeft(&lista));

	return 0;
}

void printLista(PILHA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->top;

    while(aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->next;
    }

    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "fila.h"

void printLista(PILHA *ptrLista);

int main(){

    PILHA lista;

    initialize(&lista);

    push(&lista, 10);
    printLista(&lista);
    push(&lista, 20);
    printLista(&lista);
    push(&lista, 30);
    printLista(&lista);
    push(&lista, 40);
    
    printLista(&lista);
    printf("saiu o %d\n", pop(&lista));
    printLista(&lista);
    printf("saiu o %d\n", pop(&lista));
    printLista(&lista);
    printf("saiu o %d\n", pop(&lista));
    printLista(&lista);
    printf("saiu o %d\n", pop(&lista));

	return 0;
}

void printLista(PILHA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->first;

    while(aux != NULL)
    {
        printf("%d  ", aux->info);
        aux = aux->next;
    }

    printf("\n");
}
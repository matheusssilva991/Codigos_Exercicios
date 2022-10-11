#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pilha.h"

int main(){

    PILHA lista;
    ELEMENT* aux;

    initialize(&lista);

    push(&lista, 10);
    push(&lista, 20);
    aux = lista.top;
    push(&lista, 30);
    push(&lista, 40);
    printf("saiu o %d\n", pop(&lista));

    printf("topo = %d\n", lista.top->info);
    printf("topo = %d\n", aux->info);
    printf("topo = %d\n", aux->next->next == NULL ? 1 : 0);
    printf("saiu o %d\n", pop(&lista));
    printf("saiu o %d\n", pop(&lista));
    printf("saiu o %d\n", pop(&lista));

	return 0;
}
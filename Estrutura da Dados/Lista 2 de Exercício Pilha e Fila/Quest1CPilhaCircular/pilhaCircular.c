#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pilha.h"

int main(){

    PILHA lista;

    initialize(&lista);

    push(&lista, 10);
    push(&lista, 20);
    push(&lista, 30);
    printf("ultimo = %d\n", findFirst(&lista)->info);
    printf("esse saiu %d\n", pop(&lista)); 
    printf("esse saiu %d\n", pop(&lista));
    printf("e = %d\n", lista.top == NULL ? 1: 0);
    printf("esse saiu %d\n", pop(&lista));

    printf("is empty ? %d\n", isEmpty(&lista));

	return 0;
}
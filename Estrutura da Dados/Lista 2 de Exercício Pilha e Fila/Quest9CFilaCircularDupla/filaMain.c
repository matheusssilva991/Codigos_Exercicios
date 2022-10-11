#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "fila.h"

int main(){

    FILA filaDoSus;
    ELEMENT *aux;

    initialize(&filaDoSus);

    toQueue(&filaDoSus, 1);
    toQueue(&filaDoSus, 2);
    toQueue(&filaDoSus, 3);
    toQueue(&filaDoSus, 4);
    toQueue(&filaDoSus, 5);

    aux = filaDoSus.first;

    for(int i = 0; i < 7; ++i)
    {
        printf("previous = %d, current = %d, next = %d\n", aux->previous->info, aux->info, aux->next->info);
        aux = aux->next;
    }

    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    
	return 0;
}


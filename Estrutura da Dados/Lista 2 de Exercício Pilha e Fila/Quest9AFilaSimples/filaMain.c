#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "fila.h"

int main(){

    FILA filaDoSus;

    initialize(&filaDoSus);

    toQueue(&filaDoSus, 1);
    printLista(&filaDoSus);
    toQueue(&filaDoSus, 2);
    printLista(&filaDoSus);
    toQueue(&filaDoSus, 3);
    printLista(&filaDoSus);
    toQueue(&filaDoSus, 4);
    printLista(&filaDoSus);
    toQueue(&filaDoSus, 5);
    printLista(&filaDoSus);

    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    printf("saiu %d \n", deQueue(&filaDoSus));
    
	return 0;
}


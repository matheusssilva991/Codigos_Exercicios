#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "fila.h"

int main(){

    FILA lista;

    initialize(&lista);

    toQueue(&lista, 10); 
    toQueue(&lista, 20);
    toQueue(&lista, 30);
    toQueue(&lista, 40);

    printLista(&lista);
    printf("saiu o %d\n", deQueue(&lista));
    printLista(&lista);
    printf("saiu o %d\n", deQueue(&lista));
    printLista(&lista);
    printf("saiu o %d\n", deQueue(&lista));
    printLista(&lista);
    printf("saiu o %d\n", deQueue(&lista));
    
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "fila.h"

int main(){

    FILA fila1, fila2;
    FILA *filaCat;

    initialize(&fila1);
    initialize(&fila2);
    
    toQueue(&fila1, 10);
    toQueue(&fila1, 20);
    toQueue(&fila1, 30);
    toQueue(&fila2, 40);
    toQueue(&fila2, 50);
    toQueue(&fila2, 60);

    printLista(&fila1);
    printLista(&fila2);

    filaCat = filaConcatenadaRecursiva(&fila1, &fila2);

    printf("F1 ta vazia ? %d\n", isEmpty(&fila1));
    printf("F2 ta vazia ? %d\n", isEmpty(&fila2));

    printf("\n Lista concatenada\n");
    printLista(filaCat);

    while (!isEmpty(filaCat))
    {
        int i = deQueue(filaCat);
    }

    printf("\nfilaCat ta vazia ? %d\n", isEmpty(filaCat));
    
	return 0;
}


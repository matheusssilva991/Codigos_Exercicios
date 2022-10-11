#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "fila.h"



int main(){

    FILA lista;

    initialize(&lista);

    insRight(&lista, 10);
    insRight(&lista, 20);
    insRight(&lista, 30);
    insLeft(&lista, 5);
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

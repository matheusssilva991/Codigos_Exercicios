#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"

int main(){

    LIST lista;
    NODE* aux;

    initialize(&lista);

    insertFirst(&lista, 10); // segundo
    insertFirst(&lista, 20); // primeiro
    insertLast(&lista, 30); // terceiro
    aux = findLast(&lista);

    printf("ta na lista ? %d\n", onthelistRecursiva(&lista, aux));

	return 0;
}
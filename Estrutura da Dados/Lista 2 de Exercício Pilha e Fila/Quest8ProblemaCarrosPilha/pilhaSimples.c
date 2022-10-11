#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "pilha.h"
#include "ruacolcic.h"
#include "linhas.h"

int main(){

    PILHA lista;
    RUACOLCIC flanela;
    ELEMENT* aux;

    initialize(&lista);
    initializeRuaColcic(&flanela);

    toQueue(&flanela, 'E', 1);
    toQueue(&flanela, 'E', 2);
    toQueue(&flanela, 'E', 3);
    toQueue(&flanela, 'S', 1);
    toQueue(&flanela, 'E', 4);
    toQueue(&flanela, 'E', 5);
    toQueue(&flanela, 'E', 6);
    toQueue(&flanela, 'E', 7);
    toQueue(&flanela, 'E', 8);
    toQueue(&flanela, 'E', 9);
    toQueue(&flanela, 'E', 10);
    toQueue(&flanela, 'S', 6);
    toQueue(&flanela, 'S', 7);
    toQueue(&flanela, 'S', 3);
    toQueue(&flanela, 'S', 2);
    toQueue(&flanela, 'S', 8);
    toQueue(&flanela, 'S', 9);
    toQueue(&flanela, 'S', 4);
    toQueue(&flanela, 'S', 5);
    toQueue(&flanela, 'S', 10);

    //printEntradas(&flanela);

    flanelinha(&flanela, &lista);

    printf("flanela ta vazio ? %d\n", isEmptyRuaColcic(&flanela));
    printf("a pilha esta vazia ? %d\n", isEmpty(&lista));

	return 0;
}
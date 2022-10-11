#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    LIST lista;
    NODE* aux;

    char *palavra = "A";
    char *palavra2 = "B";
    char *palavra3 = "C";
    char *palavra4 = "D";
    char *palavra5 = "E";

    initialize(&lista);

    insertFirst(&lista, palavra5);
    insertFirst(&lista, palavra4);
    insertFirst(&lista, palavra3);
    insertFirst(&lista, palavra2);
    insertFirst(&lista, palavra); 

    aux = roletaRomana(&lista);
    
    printf("\nSoldado sobrevivente = %s", aux->nome);  

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    LIST lista;
    NODE *aux;

    initialize(&lista);

    insertFirst(&lista, 'a');
    insertFirst(&lista, 'r');
    insertFirst(&lista, 'a');
    insertFirst(&lista, 'r');
    insertFirst(&lista, 'a');
    
    printf("e palindromo iterativo ? %d\n", ehPalindromoIterativa(&lista));
    printf("e palindromo recursivo ? %d\n", ehPalindromoRecursiva(&lista, lista.first, findLast(&lista)));
    printf("delete este %c\n", deleteFirst(&lista));
    printf("delete este %c\n", deleteFirst(&lista));
    printf("delete este %c\n", deleteFirst(&lista));
    printf("delete este %c\n", deleteFirst(&lista));
    //printf("delete este %d\n", deleteFirst(&lista));

    /*aux = lista.first;

    for(int i = 0 ; i < 3; i++)
    {
        printf(" current = %c\n", aux->letra);
        aux = aux->next;
    }
   */
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    LIST lista;
    NODE* aux;

    if(initialize(&lista))
    {
        printf("Sucesso\n");
    }

    insertFirst(&lista, 4);
    insertFirst(&lista, 3);
    insertFirst(&lista, 2);
    insertFirst(&lista, 1);
    aux = lista.first;
    insertLast(&lista, 5);
    
    printf("eliminado = %d\n", deleteAfter(&lista, aux));

    for(int i = 0; i < 10; i++)
    {
        printf("dado = %d, ", aux->dado);
        aux = aux->next;
    } 

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    LIST l;
    NODE *aux;

    if(initialize(&l))
    {
        printf("sucesso\n");
    }

    insertFirst(&l, 5); //ultimo
    insertFirst(&l, 4);
    insertFirst(&l, 3);
    insertFirst(&l, 2);
    insertFirst(&l, 1); //primeiro
    insertLast(&l, 6); // novo ultimo
    //deleteLast(&l);
    
    //printf("list first = %d\n", l.first->previous->dado);
    //printf("%d\n", findLast(&l)->dado); 

    //printf("%d ta na lista ? %d", aux->dado, onthelist(&l, aux));

    aux = l.first;

    for(int i = 0; i < 7; i++)
    {
        printf("previous = %d,  current = %d,  next = %d\n", aux->previous->dado, aux->dado, aux->next->dado);
        aux = aux->next;
    } 
    
    return 0;
}

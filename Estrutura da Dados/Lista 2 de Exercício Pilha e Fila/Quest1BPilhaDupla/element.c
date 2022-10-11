#include "element.h"
#include <stdio.h>
#include <stdlib.h>

/*
definições da biblioteca element.c
*/
ELEMENT* createElement(){
    ELEMENT* p;

    p = (ELEMENT*) malloc(sizeof(ELEMENT));
    p->next = NULL;
    p->previous = NULL;

    return p;
}

void freeElement(ELEMENT* p){
    free(p);
}

//---- fim das definições de element.c

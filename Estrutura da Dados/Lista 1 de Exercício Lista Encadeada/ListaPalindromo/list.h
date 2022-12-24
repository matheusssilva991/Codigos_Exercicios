#if !defined(LIST_H)
#define LIST_H

#include "node.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct list_c{
    int sizeList;
    NODE* first;
}LIST;

void initialize(LIST*);
int isEmpty(LIST*);
void insertFirst(LIST*, char);
char deleteFirst(LIST*);
void insertAfter(LIST*, NODE*, char);
char deleteAfter(LIST*, NODE*);
NODE* findLast(LIST*);
void insertLast(LIST*, char);
char deleteLast(LIST*);
int onthelist(LIST*, NODE*);
int ehPalindromoIterativa(LIST *);
int ehPalindromoRecursiva(LIST *, NODE *, NODE *);

#endif // LIST_H
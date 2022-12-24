#if !defined(LIST_H)
#define LIST_H

#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct list
{
    int sizeList;
    NODE *first;
}LIST;

void initialize(LIST *);
int isEmpty(LIST*);
void insertFirst(LIST*, char *);
char *deleteFirst(LIST*);
int onthelist(LIST*, NODE*);
void insertAfter(LIST*, NODE*, char*);
char *deleteAfter(LIST*, NODE*);
NODE *findLast(LIST*);
void insertLast(LIST*, char *);
char *deleteLast(LIST*);
NODE *sorteaPessoa(LIST*);
NODE *roletaRomana(LIST *);
void showList(LIST *);

#endif // LIST_H
#if !defined(ELEMENT_H)
#define ELEMENT_H

typedef struct element{
    int info;
    struct element* next;
    struct element* previous;
}ELEMENT;

ELEMENT* createElement();
void freeElement(ELEMENT*);

#endif // ELEMENT_H

//---- fim da biblioteca element.h

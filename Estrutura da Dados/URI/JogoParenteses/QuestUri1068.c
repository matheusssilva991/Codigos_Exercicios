#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Estruturas
typedef struct element
{
    char letra;
    struct element *next;
} ELEMENT;

typedef struct fila
{
    int size;
    ELEMENT *first;
} FILA;
// Fim Estruturas

// Protótipos
ELEMENT *createElement();
void freeElement(ELEMENT *);

void initialize(FILA *);
int isEmpty(FILA *);
void deQueue(FILA *);
void toQueue(FILA *, char);
ELEMENT *findLast(FILA *ptrLista);
void printFila(FILA *);
void liberaFila(FILA *);

void stringToFILA(FILA *, char *);
// Fim Protótipos

// Funções
ELEMENT *createElement()
{
    ELEMENT *p;

    p = (ELEMENT *)malloc(sizeof(ELEMENT));
    p->next = NULL;

    return p;
}

void freeElement(ELEMENT *p)
{
    free(p);
}

void initialize(FILA *ptrLista)
{
    ptrLista->size = 0;
    ptrLista->first = NULL;
}

int isEmpty(FILA *ptrLista)
{
    return (ptrLista->first == NULL) ? 1 : 0;
}

ELEMENT *findLast(FILA *ptrLista)
{
    ELEMENT *auxElement;

    if (isEmpty(ptrLista))
        return NULL;

    auxElement = ptrLista->first;

    while (auxElement->next != NULL)
        auxElement = auxElement->next;

    return auxElement;
}

void deQueue(FILA *ptrLista)
{
    ELEMENT *elementRemove;

    if (isEmpty(ptrLista))
        return;

    elementRemove = ptrLista->first;

    ptrLista->first = elementRemove->next;

    ptrLista->size--;

    freeElement(elementRemove);
}

void toQueue(FILA *ptrLista, char novaLetra)
{
    ELEMENT *newElement;
    ELEMENT *lastElement;

    lastElement = findLast(ptrLista);

    newElement = createElement();
    newElement->letra = novaLetra;

    if (lastElement == NULL)
    {
        lastElement = newElement;
        ptrLista->first = lastElement;
    }
    else
        lastElement->next = newElement;

    ptrLista->size++;
}

void printFila(FILA *ptrLista)
{
    ELEMENT *aux;

    aux = ptrLista->first;

    while (aux != NULL)
    {
        printf("%c ", aux->letra);
        aux = aux->next;
    }

    printf("\n");
}

void stringToFILA(FILA *ptrFila, char *palavra)
{
    for (int i = 0; i < strlen(palavra); i++)
    {
        toQueue(ptrFila, palavra[i]);
    }
}

void liberaFila(FILA *ptrFila)
{
    while (!isEmpty(ptrFila))
        deQueue(ptrFila);
}

// Main
int main()
{
    char expressao[1001];
    FILA fila;

    initialize(&fila);

    while(scanf("%1000s", expressao) != EOF)
    {
        stringToFILA(&fila, expressao);

        if(verificaExpressao(&fila))
            printf("correct\n");
        else
            printf("incorrect\n");

        liberaFila(&fila);

    }
    
    return 0;
}

int verificaExpressao(FILA *fila)
{
    int quantidadeParenteses = 0;
    ELEMENT *aux;

    aux = fila->first;

    if(fila->first->letra == ')' || findLast(fila)->letra == '(')
        return 0;

    while(aux->next != NULL)
    {
        if(aux->letra == '(')
            quantidadeParenteses++;
        else if(aux->letra == ')')
            quantidadeParenteses--;

        aux = aux->next;
    }

    if(quantidadeParenteses == 0)
        return 1;
    else 
        return 0;
}

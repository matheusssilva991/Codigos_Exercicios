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
void isSubsequencia(FILA *ptrFila, char *query);
void sequencia();
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
int main(int argc, char const *argv[])
{
    sequencia();

    return 0;
}

void sequencia()
{
    FILA fila;
    int Q, N;
    char palavra[100010];
    char query[110];

    initialize(&fila);

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%s", palavra);

        stringToFILA(&fila, palavra);

        scanf("%d", &Q);

        for (int j = 0; j < Q; j++)
        {
            scanf("%s", query);

            isSubsequencia(&fila, query);
        }

        liberaFila(&fila);
    }
}

void isSubsequencia(FILA *ptrFila, char *query)
{
    ELEMENT *inicio = NULL;
    ELEMENT *aux = NULL;
    ELEMENT *fim = findLast(ptrFila);
    int tamanhoQuery = strlen(query);
    int isSub = 0;

    if (strlen(query) > ptrFila->size)
    {
        printf("No\n");
        return;
    }

    inicio = ptrFila->first;

    while (inicio != fim)
    {
        aux = inicio;

        for (int i = 0; i < tamanhoQuery; i++)
        {
            isSub = 1;

            if (aux->letra != query[i])
            {
                isSub = 0;
                break;
            }

            aux = aux->next;
        }

        if (isSub)
        {
            printf("Yes\n");
            return;
        }

        inicio = inicio->next;
    }

    printf("No\n");
}

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
int main(int argc, char const *argv[])
{
    FILA fila;
    char areiaDiamante[1000];
    int n;

    initialize(&fila);
    
    scanf("%d", &n);  

    for(int i = 0; i < n; i++)
    {
        scanf("%s", areiaDiamante);
        stringToFILA(&fila, areiaDiamante);

        printf("%d\n", extraiDiamantes(&fila));

        liberaFila(&fila);
    }
    
    return 0;
}

int extraiDiamantes(FILA *fila)
{
    int quantidadeDiamantes = 0;
    ELEMENT *aux1, *aux2;

    aux1 = fila->first;

    while(aux1 != NULL)
    {
        if(aux1->letra == '<')
        {
            aux2 = aux1->next;

            while(aux2 != NULL)
            {
                if (aux2->letra == '>')
                {
                    aux2->letra = "c";
                    quantidadeDiamantes++;
                    break;
                }

                aux2 = aux2->next;   
            }
        }
        aux1 = aux1->next;
    }

    return quantidadeDiamantes;
}



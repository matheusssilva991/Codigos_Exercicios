#include <stdio.h>
#include <stdlib.h>

// Estruturas
typedef struct element
{
    int info;
    struct element *next;
} ELEMENT;

typedef struct pilha
{
    int size;
    ELEMENT *top;
} PILHA;
// Fim Estruturas

// Protótipos
ELEMENT *createElement();
void freeElement(ELEMENT *);

void initialize(PILHA *);
int isEmpty(PILHA *);
void push(PILHA *, int);
int pop(PILHA *);
void liberaPilha(PILHA *);
void printPilha(PILHA *);
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

void initialize(PILHA *ptrLista)
{
    ptrLista->size = 0;
    ptrLista->top = NULL;
}

int isEmpty(PILHA *ptrLista)
{
    return (ptrLista->top == NULL) ? 1 : 0;
}

void push(PILHA *ptrLista, int value)
{
    ELEMENT *newElement;

    newElement = createElement();

    newElement->info = value;
    newElement->next = ptrLista->top;

    ptrLista->top = newElement;

    ptrLista->size++;
}

int pop(PILHA *ptrLista)
{
    int info;
    ELEMENT *elementRemove;

    if (isEmpty(ptrLista))
        return -1;

    elementRemove = ptrLista->top;
    info = elementRemove->info;

    ptrLista->top = elementRemove->next;

    ptrLista->size--;

    freeElement(elementRemove);

    return info;
}

void liberaPilha(PILHA *ptrPilha)
{
    while (!isEmpty(ptrPilha))
        pop(ptrPilha);
}

void printPilha(PILHA *ptrPilha)
{
    ELEMENT *aux;

    aux = ptrPilha->top;

    while (aux != NULL)
    {
        printf("%d ", aux->info);
        aux = aux->next;
    }

    printf("\n");
}

int main()
{

    PILHA pilhaA, estacao, pilhaB;
    int N, vagao;

    initialize(&pilhaA);
    initialize(&pilhaB);
    initialize(&estacao);

    while (1) // loop até N ser igual a zero
    {
        scanf("%d", &N); // Pego o numero N, que é a quantidade de vagões

        if (N == 0) // Verifico se é igual a Zero e termino o code
            break;

        while (1) // faço um loop para pegar os testes de trens com vagões de Tamanho N, irá terminar qnd o primeiro vagão ser igual a zero
        {
            for (int i = 0; i < N; i++) // loop para pegar os vagões
            {
                scanf("%d", &vagao); // pego vagões

                if (vagao == 0 && i == 0) // verifico se o vagão tem 0 e é o inicio do teste
                    break;

                push(&pilhaA, vagao); // coloco na pilha
            }

            if (vagao == 0) // termino o teste se o vagão é 0
                break;

            while (!isEmpty(&pilhaA))
            {
                if(!isEmpty(&estacao) && estacao.top->info > biggest(&pilhaA))
                    push(&pilhaB, pop(&estacao));
                else if(pilhaA.top->info == biggest(&pilhaA))// verifica se o topo da pilha é o maior
                    push(&pilhaB, pop(&pilhaA));     // se for coloca no B                 
                else      
                    push(&estacao, pop(&pilhaA)); // senão coloca na estação
            }

            while(!isEmpty(&estacao) && estacao.top->info == biggest(&estacao))
                push(&pilhaB, pop(&estacao));

            if (isEmpty(&estacao))
                printf("Yes\n");
            else
                printf("No\n");

            liberaPilha(&estacao);
            liberaPilha(&pilhaB);
            liberaPilha(&pilhaA);
        }
    }

    return 0;
}

int biggest(PILHA *ptrPilha)
{
    int maior;
    ELEMENT *aux;

    if (isEmpty(ptrPilha))
        return 0;

    aux = ptrPilha->top;
    maior = aux->info;

    while (aux != NULL)
    {
        if (maior < aux->info)
            maior = aux->info;

        aux = aux->next;
    }

    return maior;
}
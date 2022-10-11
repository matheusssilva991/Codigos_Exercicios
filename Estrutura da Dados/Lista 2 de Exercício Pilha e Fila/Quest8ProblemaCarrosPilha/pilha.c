#include "pilha.h"

/*
definições da biblioteca stackElement.c
*/
void initialize(PILHA* ptrLista){
    ptrLista->size = 0;
    ptrLista->top = NULL;
}

int isEmpty(PILHA* ptrLista){
    return (ptrLista->top == NULL) ? 1 : 0;
}


void push(PILHA* ptrLista, int value){
    ELEMENT *newElement;

    if(ptrLista->size == 10)
    {
        printf("Nao ha vagas\n");
        return ;
    }

    newElement = createElement();

    newElement->info = value;
    newElement->next = ptrLista->top;

    ptrLista->top = newElement;

    ptrLista->size++;
}

int pop(PILHA* ptrLista)
{
    int info;
    ELEMENT *elementRemove;

    if(isEmpty(ptrLista))
        return -1;

    elementRemove = ptrLista->top;
    info = elementRemove->info;

    ptrLista->top = elementRemove->next;    

	ptrLista->size--;

    freeElement(elementRemove);
	
    return info;
}

int retiraCarro(PILHA *estacionamento, int placaCarro)
{
    PILHA *pilhaAux;
    int placaCarroRemovido, vezesManobrado = 0;

    if(isEmpty(estacionamento) || buscaCarro(estacionamento, placaCarro) == NULL)
    {
        printf("carro foi roubado, nao esta no estacionamento.\n");
        return -1;
    }

    pilhaAux = (PILHA *) malloc(sizeof(PILHA));

    if(pilhaAux == NULL)
    {
        printf("nao alocado.\n");
        return -1;
    }

    initialize(pilhaAux);

    while(estacionamento->top->info != placaCarro)
    {
        push(pilhaAux, pop(estacionamento)); 
        vezesManobrado++;
    }

    placaCarroRemovido = pop(estacionamento);
    estacionamento->size--;

    while (!isEmpty(pilhaAux))
    {
        push(estacionamento, pop(pilhaAux)); 
        estacionamento->size--;
    }

    printf("Foram manobrado %d vezes para que o carro %d saísse\n", vezesManobrado, placaCarroRemovido);

    free(pilhaAux);

    return placaCarroRemovido;
}

ELEMENT *buscaCarro(PILHA *estacionamento, int placaCarro)
{
    ELEMENT *aux;

    aux = estacionamento->top;

    while(aux != NULL)
    {
        if(aux->info == placaCarro)
            return aux;

        aux = aux->next;
    }

    return NULL;
}

void flanelinha(RUACOLCIC* rua, PILHA *estacionamento)
{
    while(!isEmptyRuaColcic(rua))
    {
        switch (rua->first->escolha)
        {
        case 'E':
            case 'e':
                printf("carro %d entrou no estacionamento.\n", rua->first->placaCarro);
                push(estacionamento, rua->first->placaCarro);
                deQueue(rua);

                break;
        case 'S':
            case 's':
                printf("carro %d saiu do estacionamento.\n", rua->first->placaCarro);
                retiraCarro(estacionamento, rua->first->placaCarro);
                deQueue(rua);
                
                break;
        default:
            printf("carro %d passou direto\n", rua->first->placaCarro);
            deQueue(rua);
            break;
        } 
    }
}

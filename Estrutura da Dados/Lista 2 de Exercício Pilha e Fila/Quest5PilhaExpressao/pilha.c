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


void push(PILHA* ptrLista, char value){
    ELEMENT *newElement;

    newElement = createElement();

    newElement->info = value;
    newElement->next = ptrLista->top;

    ptrLista->top = newElement;

    ptrLista->size++;
}

char pop(PILHA* ptrLista)
{
    char info;
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

void colocaExpressao(PILHA *ptrPilha, char *expressao)
{
    for (size_t i = 0; expressao[i] != '\0'; ++i)
        push(ptrPilha, expressao[i]);  
}

void limpaExpressao(PILHA *ptrPilha)
{
    while(!isEmpty(ptrPilha))
        pop(ptrPilha);
}

int verificaExpressao(PILHA *ptrPilha)
{
    ELEMENT *letra;
    int chaves = 0, colchetes = 0, parentese = 0;

    letra = ptrPilha->top;

    while(letra != NULL)
    {
        switch (letra->info)
        {
        case '{':
            chaves++;
            break;

        case '[':
            colchetes++;
            break;

        case '(':
            parentese++;
            break;

        case '}':
            chaves--;
            break;

        case ']':
            colchetes--;
            break;

        case ')':
            parentese--;
            break;
        
        default:
            break;
        }

        letra = letra->next;
    }

    if(parentese != 0 || colchetes != 0 || chaves != 0)
    {
        printf("expressao valida nao e valida.\n");
        return 0;
    }
    else
    {
        printf("expressao valida.\n");
        return 1;
    }
        
}
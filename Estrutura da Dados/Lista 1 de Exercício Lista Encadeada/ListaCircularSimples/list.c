#include "list.h"

int initialize(LIST *ptrList)
{
    if(ptrList == NULL)
    {
        return 0;
    }

    ptrList->sizeList = 0;
    ptrList->first = NULL;

    return 1;
} // fim da função inicialize

int isEmpty(LIST *ptrList)
{
    if(ptrList->first == NULL)
    {
        return 1;
    }
    return 0;
} // fim da função isEmpty

void insertFirst(LIST *ptrList, int value)
{
    NODE *nodeAux, *nodeAuxFinal;

    nodeAux = createNode(); // Cria um nó

    nodeAux->dado = value; // seta um dado no nó

    if(isEmpty(ptrList))// verifica se a lista ta vazia, o ponteiro para o próximo nó vai apontar para ele mesmo.
        nodeAux->next = nodeAux;
    else
        nodeAux->next = ptrList->first;

    ptrList->first = nodeAux;
    ++ptrList->sizeList;
    nodeAuxFinal = findLast(ptrList);
    nodeAuxFinal->next = ptrList->first; 
      
} // fim da função insertFirst

NODE* findLast(LIST *ptrList)
{
    NODE *nodeAux;

    nodeAux = ptrList->first; 

    for(int i = 0; i < ptrList->sizeList - 1; i++)
        nodeAux = nodeAux->next;
    
    return nodeAux;
}

int deleteFirst(LIST *ptrList)
{
    NODE *nodeAux;
    int value;

    if(isEmpty(ptrList))
    {
        printf("Error, LISTA VAZIA\n");
        exit(-1);
    }

    nodeAux = ptrList->first; 
    value = nodeAux->dado;

    ptrList->first = nodeAux->next;

    freeNode(nodeAux);

    nodeAux = findLast(ptrList);
    nodeAux->next = ptrList->first;

    ptrList->sizeList--;

    return value;
}

int onthelist(LIST* ptrList, NODE* ptrNode)
{
    LIST listAux;

    listAux.first = ptrList->first; 

    if(listAux.first->dado == ptrNode->dado) // Verifica se é o node procurado
        return 1;

    if(listAux.first->next == ptrList->first) // Condição de parada, verifica se o próximo node é igual a NULL
        return 0;
    else
    {
        listAux.first = ptrList->first->next; // faz aux.first apontar para o próximo node da lista

        onthelist(&listAux, ptrNode); // faz chamada recursiva da função 
    }     
}

void insertAfter(LIST* ptrList, NODE* ptrNode, int value)
{
    if(ptrNode == NULL || !onthelist(ptrList, ptrNode))
    {
        printf("Erro, lista vazia.\n");
        exit(-1);
    }

    NODE *nodeAux;

    nodeAux = createNode(); // Cria o nó
    nodeAux->dado = value; // passa a informação para o nó

    nodeAux->next = ptrNode->next; 
    ptrNode->next = nodeAux; 

    ptrList->sizeList++;
}

int deleteAfter(LIST *ptrList, NODE *ptrNode)
{
    if(ptrNode == NULL || ptrNode->next == NULL ||!onthelist(ptrList, ptrNode))
    {
        printf("Erro, lista vazia.\n");
        exit(-1);
    }

    NODE *nodeAux;
    int value;

    nodeAux = ptrNode->next;

     if(nodeAux == ptrList->first)
        ptrList->first = nodeAux->next;

    value = nodeAux->dado;
    ptrNode->next = nodeAux->next;

    free(nodeAux);

    ptrList->sizeList--;

    return value;
}

void insertLast(LIST *ptrList, int value)
{
    NODE *last;
    NODE *new;

    last = findLast(ptrList);

    new = createNode();
    new->dado = value;

    new->next = last->next;
    last->next = new;

    ptrList->sizeList++;      
}

int deleteLast(LIST *ptrList)
{
    NODE *last;
    NODE *temp;
    int value;

    last = findLast(ptrList);
    value = last->dado;

    temp = ptrList->first;

    if(temp == last)
        ptrList->first == NULL;
    else
        while(temp != last)
            temp = temp->next;
    
    temp->next = last->next;

    freeNode(last);

    ptrList->sizeList--; 

    return value;
}
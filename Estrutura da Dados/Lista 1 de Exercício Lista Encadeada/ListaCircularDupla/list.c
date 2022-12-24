#include "list.h"

int initialize(LIST *ptrList)
{
    if(ptrList == NULL)
    {
        return -1;
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
    NODE *ptrNewNode, *ptrNodeLast;

    ptrNewNode = createNode(); // cria o novo nó
    ptrNewNode->dado = value;  // seta o valor do novo nó

    if(isEmpty(ptrList))// verifica se a lista ta vazia, o ponteiro para o próximo nó vai apontar para ele mesmo.
        ptrNewNode->next = ptrNewNode;
    else
        ptrNewNode->next = ptrList->first; // Se não tiver vazia, o ponteiro para o proximo elemento do novo nó vai aponta para o antigo primeiro elemento

    ptrList->first = ptrNewNode; // faz o ponteiro para o primeiro membro da lista apontar para o novo nó
    (ptrList->sizeList)++; // aumenta o tamanho da lista

    ptrNodeLast = findLast(ptrList); // faz a variavel auxFinal apontar para o ultimo nó
    ptrNodeLast->next = ptrList->first; // o ultimo ponteiro para o próximo elemento contido no ultimo nó vai receber a referencia para o novo  primeiro nó

    ptrNewNode->next->previous = ptrNewNode; // faz o ponteiro previous do antigo primeiro nó apontar para o novoPrimeiro nó.
    ptrNewNode->previous = ptrNodeLast; // faz o ponteiro previous do novo primeiro nó apontar para o final.
      
} // fim da função insertFirst

NODE* findLast(LIST *ptrList)
{
    NODE *nodeAux;

    nodeAux = ptrList->first; 

    for(int i = 0; i < ptrList->sizeList - 1; i++)
        nodeAux = nodeAux->next;
    
    return nodeAux;
} // fim da função findLast

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

    ptrList->first->previous = nodeAux;

    ptrList->sizeList--;

    return value;
} // fim da função deleteFirst

int onthelist(LIST* ptrList, NODE* ptrNode)
{
    LIST listAux;

    listAux.first = ptrList->first; 

    if(listAux.first->dado == ptrNode->dado) // Verifica se é o node procurado
        return 1;

    if(listAux.first->next == ptrList->first) // Condição de parada, verifica se o próximo node é igual a NULL
        return 0;
    
    listAux.first = ptrList->first->next; // faz aux.first apontar para o próximo node da lista

    onthelist(&listAux, ptrNode); // faz chamada recursiva da função
       
} // fim da função onthelist

void insertAfter(LIST* ptrList, NODE* currentNode, int value)
{
    if(currentNode == NULL || !onthelist(ptrList, currentNode))
    {
        printf("Erro, lista vazia.\n");
        exit(-1);
    }

    NODE *newNode;

    newNode = createNode(); // cria um novo nó
    newNode->dado = value;  // seta o novo nó

    newNode->next = currentNode->next;  // faz o next do novo nó apontar para o próximo nó que queremos inserir após
    currentNode->next->previous = newNode;
    currentNode->next = newNode; // faz o next do nó que queremos inserir após apontar para o novo nó inserido.

    newNode->previous = currentNode; 

    ptrList->sizeList++;
} // fim da função insertAfter

int deleteAfter(LIST *ptrList, NODE *currentNode)
{
    if(currentNode == NULL || !onthelist(ptrList, currentNode))
    {
        printf("Erro, lista vazia.\n");
        exit(-1);
    }

    NODE *nodeAux;
    int value;

    nodeAux = currentNode->next;
    value = nodeAux->dado;

    currentNode->next = nodeAux->next;
    currentNode->next->previous = currentNode;

    free(nodeAux);

    ptrList->sizeList--;

    return value;
} // fim da função deleteAfter

void insertLast(LIST *ptrList, int value)
{
    NODE *ptrLastNode;
    NODE *new;

    ptrLastNode = findLast(ptrList); // last recebe a referencia para o ultimo nó

    new = createNode(); // cria um novo nó
    new->dado = value; // seta o dado do novo nó

    new->next = ptrLastNode->next; // faz o novo ultimo nó apontar para o primeiro nó
    ptrLastNode->next = new; // faz o antigo ultimo nó apontar para o novo ultimo

    new->previous = ptrLastNode; // faz o ponteiro previous do novo ultimo nó apontar para  o antigo ultimo nó
    new->next->previous = new; // faz o ponteiro previous do primeiro nó apontar para o novo ultimo nó.

    ptrList->sizeList++; // aumenta em um o contador de nós
} // fim da função InsertLAst

int deleteLast(LIST *ptrList)
{
    NODE *ptrLastNode;
    NODE *temp;
    int value;

    ptrLastNode = findLast(ptrList); // last vai receber a referencia para o ultimo nó
    value = ptrLastNode->dado;  // a variavel  value vai guardar o dado do ultimo nó

    temp = ptrList->first; // a variavel temp vai receber a referencia para o primeiro nó

    if(temp == ptrLastNode) // se temp é igual ao ultimo nó isso indica que a lista só tem um nó.
        ptrList->first == NULL;
    else // se last for diferente, então temp vai receber a referencia para o penultimo nó
        temp = ptrLastNode->previous;
    
    temp->next = ptrLastNode->next; // faz o ponteiro para o próximo elemento de temp(novo ultimo) apontar para o primeiro elemento.
    ptrList->first->previous = temp; // faz o ponteiro previous do primeiro elemento apontar para temp(novo ultimo).

    freeNode(ptrLastNode); // libero o antigo ultimo elemento

    ptrList->sizeList--;  // diminuo o tamanho da lista em 1.

    return value;
} // fim da função deleteLast
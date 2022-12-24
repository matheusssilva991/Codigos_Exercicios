#include "list.h"

void initialize(LIST *ptrList)
{
    ptrList->sizeList = 0;
    ptrList->first = NULL;
} // fim da função inicialize

int isEmpty(LIST *ptrList)
{
    if(ptrList->first == NULL)
    {
        return 1;
    }
    return 0;
} // fim da função isEmpty

void insertFirst(LIST *ptrList, char *ptrName)
{
    NODE *ptrNoAux, *auxFinal;

    ptrNoAux = createNode(); // Cria um nó

    ptrNoAux->nome = ptrName; // seta um dado no nó

    if(isEmpty(ptrList))// verifica se a lista ta vazia, o ponteiro para o próximo nó vai apontar para ele mesmo.
        ptrNoAux->next = ptrNoAux;
    else
        ptrNoAux->next = ptrList->first;

    ptrList->first = ptrNoAux;
    ++(ptrList->sizeList);

    auxFinal = findLast(ptrList);
    auxFinal->next = ptrList->first; 
      
} // fim da função insertFirst

NODE* findLast(LIST *ptrList)
{
    NODE *aux;

    aux = ptrList->first; 

    for(int i = 0; i < ptrList->sizeList - 1; i++)
        aux = aux->next;
    
    return aux;
}

char *deleteFirst(LIST *ptrList)
{
    NODE *aux;
    char *ptrAuxNome;

    if(isEmpty(ptrList))
    {
        printf("Error, LISTA VAZIA\n");
        exit(-1);
    }

    aux = ptrList->first; 
    ptrAuxNome = aux->nome;

    ptrList->first = aux->next;

    freeNode(aux);

    aux = findLast(ptrList);
    aux->next = ptrList->first;

    ptrList->sizeList--;

    return ptrAuxNome;
}

int onthelist(LIST* ptrList, NODE* ptrNode)
{
    LIST listAux;

    listAux.first = ptrList->first; 

    if(!strcmp(listAux.first->nome, ptrNode->nome)) // Verifica se é o node procurado
        return 1;

    if(listAux.first->next == ptrList->first) // Condição de parada, verifica se o próximo node é igual ao primeiro
        return 0;
    
    listAux.first = ptrList->first->next; // faz aux.first apontar para o próximo node da lista

    onthelist(&listAux, ptrNode); // faz chamada recursiva da função     
}

void insertAfter(LIST* ptrList, NODE* ptrNode, char *ptrNome)
{
    if(ptrNode == NULL || !onthelist(ptrList, ptrNode))
    {
        printf("Erro, lista vazia.\n");
        exit(-1);
    }

    NODE *nodeAux;

    nodeAux = createNode(); 
    nodeAux->nome = ptrNome;

    nodeAux->next = ptrNode->next; 
    ptrNode->next = nodeAux; 

    ptrList->sizeList++;
}

char *deleteAfter(LIST *ptrList, NODE *ptrNode)
{
    if(ptrNode == NULL || ptrNode->next == NULL || !onthelist(ptrList, ptrNode))
    {
        printf("Erro, impossivel remover.\n");
        exit(-1);
    }

    NODE *nodeAux;
    char *ptrNome;

    nodeAux = ptrNode->next; // guarda a referencia para o proxímo nó

    if(nodeAux == ptrList->first)
        ptrList->first = nodeAux->next;

    ptrNome = nodeAux->nome; // guarda o dado do nó a ser excluido
    ptrNode->next = nodeAux->next; // faz o nó atual a apontar o proximo do nó que vai ser excluido

    --(ptrList->sizeList);

    free(nodeAux); // libera o nó que vai ser excluido

    return ptrNome;
}

void insertLast(LIST *ptrList, char *ptrAuxNome)
{
    NODE *ptrLastNode;
    NODE *new;

    ptrLastNode = findLast(ptrList);

    new = createNode();
    new->nome = ptrAuxNome;

    new->next = ptrLastNode->next;
    ptrLastNode->next = new;

    ptrList->sizeList++;      
}

char *deleteLast(LIST *ptrList)
{
    NODE *last;
    NODE *temp;
    char *ptrNome;

    last = findLast(ptrList);
    ptrNome = last->nome;

    temp = ptrList->first;

    if(temp == last)
        ptrList->first == NULL;
    else
        while(temp != last)
            temp = temp->next;
    
    temp->next = last->next;

    freeNode(last);

    ptrList->sizeList--; 

    return ptrNome;
}

NODE* sorteaPessoa(LIST *ptrLista)
{
    NODE *nodeAux;
    int numeroSorteado;

    if(isEmpty(ptrLista))
    {
        printf("Lista Vazia.\n");
        return NULL;
    }

    srand(time(NULL));

    numeroSorteado = 1 +  rand() % ptrLista->sizeList;

    nodeAux = ptrLista->first;

    for(int i = 0; i < numeroSorteado; i++)
        nodeAux = nodeAux->next;

    return nodeAux; 
}

NODE *roletaRomana(LIST *ptrLista)
{
    NODE *soldadoSorteado;
    int numeroSorteado;

    srand(time(NULL));
    
    //numeroSorteado = 3;
    numeroSorteado = 1 + rand() % 10;
    printf("numero N = %d\n", numeroSorteado);

    soldadoSorteado = sorteaPessoa(ptrLista);
    //soldadoSorteado = ptrLista->first;
    
    printf("nome da pessoa sorteada = %s\n", soldadoSorteado->nome);
    showList(ptrLista);  

    while(ptrLista->sizeList > 1)
    {
        for(int i = 1; i < numeroSorteado - 1; ++i) // faz a contagem sequencial de quem vai ser eliminado 
            soldadoSorteado = soldadoSorteado->next;  

        if(!isEmpty(ptrLista))  //se a lista não tiver vazia elimina pessoa
            printf("Soldado eliminado =  %s\n", deleteAfter(ptrLista, soldadoSorteado));
        
        soldadoSorteado = soldadoSorteado->next;
    } 
    return soldadoSorteado;
}

void showList(LIST *ptrLista)
{
    NODE *aux;
    NODE *last;

    aux = ptrLista->first;
    last = findLast(ptrLista);

    while(aux != last)
    {
        printf("%s ", aux->nome);
        aux = aux->next;
    }
    printf("%s\n", aux->nome);
}

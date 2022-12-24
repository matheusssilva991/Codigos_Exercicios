#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estruturas 
typedef struct presente{
    int valorPresente;
    struct presente* proximoPresente;
}PRESENTE;

typedef struct sacolaPapaiNoel{
    int numeroPresentes;
    PRESENTE* topoSacola;
}SACOLAPAPAINOEL;
// Fim das Estruturas

// Prototipos de funções
PRESENTE* criarPresente();
void liberarPresente(PRESENTE*);

void initialize(SACOLAPAPAINOEL*);
int isEmpty(SACOLAPAPAINOEL*);
void push(SACOLAPAPAINOEL*, int);
void pop(SACOLAPAPAINOEL*);
void min(SACOLAPAPAINOEL*);
//Fim dos Prototipos

//Main
int main()
{
    SACOLAPAPAINOEL presentes;
    int numeroOperacoes;
    initialize(&presentes);

    scanf("%d", &numeroOperacoes);
    operacoes(&presentes, numeroOperacoes);

    return 0;
}

//Funções
PRESENTE* criarPresente(){
    PRESENTE* p;

    p = (PRESENTE*) malloc(sizeof(PRESENTE));
    p->proximoPresente = NULL;

    return p;
}

void liberarPresente(PRESENTE* p)
{
    free(p);
}

void initialize(SACOLAPAPAINOEL* ptrSacolaPresente)
{
    ptrSacolaPresente->numeroPresentes = 0;
    ptrSacolaPresente->topoSacola = NULL;
}

int isEmpty(SACOLAPAPAINOEL* ptrSacolaPresente)
{
    if(ptrSacolaPresente->topoSacola == NULL)
    {
        printf("EMPTY\n");
        return 1;
    }

    return 0;
}

void push(SACOLAPAPAINOEL* ptrSacolaPresente, int valorPresente){
    PRESENTE *novoPresente;

    novoPresente = criarPresente();

    novoPresente->valorPresente = valorPresente;
    novoPresente->proximoPresente = ptrSacolaPresente->topoSacola;

    ptrSacolaPresente->topoSacola = novoPresente;

    ptrSacolaPresente->numeroPresentes++;
}

void pop(SACOLAPAPAINOEL* ptrSacolaPresente)
{
    PRESENTE *PresenteRemover;

    if(isEmpty(ptrSacolaPresente))
        return;
    
    PresenteRemover = ptrSacolaPresente->topoSacola;

    ptrSacolaPresente->topoSacola = PresenteRemover->proximoPresente;    

	ptrSacolaPresente->numeroPresentes--;

    liberarPresente(PresenteRemover);
	
    return;
}

void min(SACOLAPAPAINOEL *ptrSacolaPresente)
{
    int menorPresente;
    PRESENTE *presenteAux;

    if(isEmpty(ptrSacolaPresente))
        return;

    presenteAux = ptrSacolaPresente->topoSacola;
    menorPresente = presenteAux->valorPresente;

    while(presenteAux->proximoPresente != NULL)
    {
        presenteAux = presenteAux->proximoPresente;

        if(menorPresente > presenteAux->valorPresente)
            menorPresente = presenteAux->valorPresente;
    }
    printf("%d\n", menorPresente);

    return;
}

void operacoes(SACOLAPAPAINOEL *ptrSacolaPresente, int numeroOperacoes)
{
    char operacao[20];
    int valor;
    char *bancoPalavra[3] = {{"POP"}, {"MIN"}, {"PUSH"}};
    
    for(int i = numeroOperacoes; i > 0; --i)
    {
        scanf("%s", operacao);

        if(strcmp(bancoPalavra[0], operacao) == 0)
            pop(ptrSacolaPresente);

        else if(strcmp(bancoPalavra[1], operacao) == 0)
            min(ptrSacolaPresente);

        else if(strcmp(operacao, bancoPalavra[2]) == 0)
        {
            scanf("%d", &valor);
            push(ptrSacolaPresente, valor);
        }
    }   
}
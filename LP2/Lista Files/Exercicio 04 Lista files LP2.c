#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct
{
    SYSTEMTIME data_hora;

    int codigo, quantidade;
    char descricao[100];
    float valor;

}Tproduto;

void escreve(FILE *, Tproduto *);
void printa(Tproduto *);

int main()
{
    FILE *arquivo;
    int op;
    Tproduto prod;

    arquivo = fopen("quest4.txt", "a");

    if(arquivo == NULL)
    {
        printf("erro ao abrir.\n");
        exit(-1);
    }

    do{
        printa(&prod);
        escreve(arquivo, &prod);

        printf("Digite 1 para continuar\nDigite 0 para Sair\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        system("cls");

    }while(op);

    fclose(arquivo);

    return 0;
}

void escreve(FILE *arq, Tproduto *produto)
{
    GetLocalTime(&produto->data_hora);

    fprintf(arq, "%d:%d  %d/%d/%d   ", produto->data_hora.wHour, produto->data_hora.wMinute, produto->data_hora.wDay, produto->data_hora.wMonth, produto->data_hora.wYear);
    fprintf(arq, "%d    %s  %d  %.2f\n", produto->codigo, produto->descricao, produto->quantidade, produto->valor);
}

void printa(Tproduto *produto)
{
    printf("Digite o codigo do produto:\n");
    scanf("%d", &produto->codigo);
    setbuf(stdin, NULL);

    printf("Digite a descricao do produto:\n");
    gets(produto->descricao);
    setbuf(stdin, NULL);

    printf("Digite a quantidade do produto:\n");
    scanf("%d", &produto->quantidade);
    setbuf(stdin, NULL);

    printf("Digite o valor do produto:\n");
    scanf("%f", &produto->valor);
    setbuf(stdin, NULL);
}

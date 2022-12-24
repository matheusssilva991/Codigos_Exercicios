#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct
{
    int codigo, quantidade;
    char descricao[100];
    float valor;

}Tproduto;

void ler(FILE *);

int main()
{
    FILE *arquivo;

    arquivo = fopen("quest4.txt", "r");

    if(arquivo == NULL)
    {
        printf("erro ao abrir.\n");
        exit(-1);
    }

    ler(arquivo);
    fclose(arquivo);

    return 0;
}

void ler(FILE *arq)
{
    Tproduto produto;
    int numeroVendas = 0, vendeuMais = 0;
    float caixa = 0;
    int hora, minuto, dia, mes, ano , i;
    char aux, aux1, aux2;

    rewind(arq);

    fscanf(arq, "%d %c %d %d %c %d %c %d %d %s %d %f", &hora, &aux, &minuto, &dia, &aux1, &mes, &aux2, &ano, &produto.codigo, &produto.descricao, &produto.quantidade, &produto.valor);

    while(!feof(arq))
    {
        printf("Horario: %d%c%d  Data: %d%c%d%c%d   Codigo: %d   Descricao: %s       Quantidade: %d      Valor: %.2f\n", hora, aux, minuto, dia, aux1, mes, aux2, ano, produto.codigo, produto.descricao, produto.quantidade, produto.valor);
        numeroVendas ++;
        caixa += produto.valor * produto.quantidade;

        fscanf(arq, "%d %c %d %d %c %d %c %d %d %s %d %f", &hora, &aux, &minuto, &dia, &aux1, &mes, &aux2, &ano, &produto.codigo, &produto.descricao, &produto.quantidade, &produto.valor);
    }

    printf("Caixa = %.2f\nNumero de Vendas = %d", caixa, numeroVendas);
}

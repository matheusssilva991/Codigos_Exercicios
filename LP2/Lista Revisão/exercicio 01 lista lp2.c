/*
    Exercício de revisão
    Armazenar nome e número e printar esses dados
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Dados
{
    char nome[80];
    char numero[20];

}dados;

int main()
{
    dados cadastro; // cria struct dados chamada Cadastro

    printf("digite o nome\n");
    gets(cadastro.nome);

    printf("digite o numero de telefone\n");
    gets(cadastro.numero);

    printf("Nome: %s\nTelefone: %s\n", cadastro.nome, cadastro.numero);

    return 0;
}

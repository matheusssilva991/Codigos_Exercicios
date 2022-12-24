#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[255];
    char numero[13];

}Taluno;

void escreve(FILE *);

int main()
{
    FILE *arquivo;

    arquivo = fopen("CadastroQuest2.txt", "w");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(-1);
    }

    escreve(arquivo);
    fclose(arquivo);

    return 0;
}

void escreve(FILE *arquivo)
{
    Taluno aluno;

    do{
        printf("Digite o nome do aluno:\n");
        gets(aluno.nome);
        setbuf(stdin, NULL);

        printf("Digite o numero do aluno:\n");
        gets(aluno.numero);
        setbuf(stdin, NULL);

        fprintf(arquivo, "%s %10s\n", aluno.nome, aluno.numero);

        system("cls");

    }while(strcmp(aluno.nome, ""));
}

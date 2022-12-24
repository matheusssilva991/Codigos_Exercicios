#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    long int matricula;
    char nome[30];
    float cr;

}Taluno;

int main()
{
    FILE *arquivo;
    Taluno aluno;
    int op = 1;

    arquivo = fopen("Quest12.dat", "ab");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir.\n");
        exit(-1);
    }

    while(op)
    {
        printf("Digite o numero de matricula do Aluno:\n");
        scanf("%ld", &aluno.matricula);
        setbuf(stdin, NULL);

        printf("Digite o nome do Aluno:\n");
        gets(aluno.nome);
        setbuf(stdin, NULL);

        printf("Digite o CR do aluno:\n");
        scanf("%f", &aluno.cr);
        setbuf(stdin, NULL);

        fwrite(&aluno, sizeof(Taluno), 1, arquivo);

        printf("Digite 1 para Continuar\nDigite 0 Para Sair\n\nDigite a opcao: \n");
        scanf("%d", &op);
        fflush(stdin);

        system("cls");

    }

    fclose(arquivo);

    return 0;
}

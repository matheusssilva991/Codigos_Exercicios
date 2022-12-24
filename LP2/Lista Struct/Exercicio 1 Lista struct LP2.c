#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[20];
	char sobrenome[30];
	int idade;
	long int telefone;
	char sexo;
	char email[100];

}Tcadastro;

int main(void)
{
    int quantidadeAlunos, i;
    Tcadastro *alunos, *ptrAlunos = NULL;

    printf("Digite a quantidade de alunos:\n");
    scanf("%d", &quantidadeAlunos);
    fflush(stdin);

    system("cls");

    alunos = (Tcadastro *) malloc(quantidadeAlunos * sizeof(Tcadastro));
    if(alunos == NULL)
        exit(-1);

    ptrAlunos = alunos;

    for(i = 0; i < quantidadeAlunos; i++)
    {
        printf("Aluno %d\n", i + 1);

        printf("Digite o nome:\n");
        scanf("%s", &alunos[i].nome);
        printf("\n");
        fflush(stdin);

        printf("Digite o sobrenome:\n");
        scanf("%s", &alunos[i].sobrenome);
        printf("\n");
        fflush(stdin);

        printf("Digite a idade:\n");
        scanf("%d", &alunos[i].idade);
        printf("\n");
        fflush(stdin);

        printf("Digite o numero do telefone:\n");
        scanf("%ld", &alunos[i].telefone);
        printf("\n");
        fflush(stdin);

        printf("Digite o Sexo:\n [M] masculino   [F] feminino\n");
        scanf("%c", &alunos[i].sexo);
        printf("\n");
        fflush(stdin);

        printf("Digite o endereco de Email:\n");
        scanf("%s", &alunos[i].email);
        printf("\n");
        fflush(stdin);

        system("cls");
    }

    for(i = 0; i < quantidadeAlunos; i++)
    {
        printf("Nome do Aluno: %s\n", (*ptrAlunos).nome);
        printf("Sobrenome do Aluno: %s\n", (*ptrAlunos).sobrenome);
        printf("Idade do aluno: %d\n", (*ptrAlunos).idade);
        printf("Numero de telefone do aluno: %ld\n", (*ptrAlunos).telefone);
        printf("Sexo do Aluno: [%c]\n", (*ptrAlunos).sexo);
        printf("Email do aluno: %s\n", (*ptrAlunos).email);
        printf("\n\n");

        ptrAlunos++;
    }

    free(alunos);

	return 0;
}

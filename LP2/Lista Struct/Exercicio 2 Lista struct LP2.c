#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int matricula;
	char nome[20];
	char sobrenome[20];
	float nota;		
}Taluno;

int main(void)
{
	
	int quantidadeAlunos, i;	
	float media = 0;
	Taluno *alunos, *pior = NULL, *melhor = NULL;
	
	printf("Digite a quantidade de alunos:\n");
	scanf("%d", &quantidadeAlunos);
	
	setbuf(stdin, NULL);
	system("cls");
	
	alunos = (Taluno *) malloc(quantidadeAlunos * sizeof(Taluno));
	
	if(alunos == NULL)
		exit(-1);
	
	for(i = 0; i < quantidadeAlunos; i++)
	{
		printf("Aluno %d:\n\n", i + 1);
		
		printf("Digite o numero da matrica do aluno:\n");
		scanf("%d", &alunos[i].matricula);
		setbuf(stdin, NULL);
		printf("\n");
			
		printf("Digite o nome do aluno:\n");
		scanf("%s", &alunos[i].nome);
		setbuf(stdin, NULL);
		printf("\n");
		
		printf("Digite o sobrenome do aluno:\n");
		scanf("%s", &alunos[i].sobrenome);
		setbuf(stdin, NULL);
		printf("\n");
		
		printf("Digite o nota do aluno:\n");
		scanf("%f", &alunos[i].nota);
		setbuf(stdin, NULL);
		printf("\n");
		
		if (i == 0){
			pior = &alunos[i];
			melhor = &alunos[i];
		}

		media += alunos[i].nota;
		
		if(alunos[i].nota >= melhor -> nota)
			melhor = &alunos[i];
		else if(alunos[i].nota <= pior -> nota)
			pior = &alunos[i];
			
		system("cls");			
	}
	
	media /= quantidadeAlunos;
	
	printf("O melhor aluno: %s\n", melhor -> nome);
	printf("O pior aluno: %s\n", pior -> nome);
	printf("Media turma: %.2f\n", media);
	
	free(alunos);
	
	return 0;
}

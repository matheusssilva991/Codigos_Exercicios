#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 	float mediaTurma = 0, mediaTurma2 = 0;
 	int i, qtdAlunos;
 	
 	printf("Digite a quantidade de Alunos\n");
 	scanf("%d", &qtdAlunos);
 	
 	setbuf(stdin, NULL);
 	
 	system("cls");
 	
 	float *nota1 = (float *) malloc(qtdAlunos * sizeof(float));
 	float *nota2= (float *) malloc(qtdAlunos * sizeof(float));
 	float *mediaAlunos = (float *) malloc(qtdAlunos * sizeof(float));
 	
 	if(nota1 == NULL || nota2 == NULL || mediaAlunos == NULL)
 		exit(-1);
 		
 	for(i = 0; i < qtdAlunos; i++)
 	{
 		printf("Digite as duas notas do Aluno[%d]\n", i + 1);
 		scanf("%f %f", &nota1[i], &nota2[i]);
 		
 		mediaAlunos[i] = (nota1[i] + nota2[i]) / 2;
 		mediaTurma += nota1[i];
		mediaTurma2 += nota2[i]; 
 		
 		printf("Media Aluno[%d] = %.1f\n", i + 1, mediaAlunos[i]);
 		
 		if(mediaAlunos[i] >= 7)
 			printf("Aluno Aprovado\n");
 		else
 			printf("Aluno Reprovado\n");
 			
 		setbuf(stdin, NULL);
 				
 		printf("\n");
 		
	}
 	
 	mediaTurma /= qtdAlunos;
 	mediaTurma2 /= qtdAlunos;
	
	printf("Media Turma Prova 1 = %.1f\n", mediaTurma);
	printf("Media Turma Prova 2 = %.1f\n", mediaTurma2);
	
	free(nota1);
	free(nota2);
	free(mediaAlunos);
	
	return 0;
}

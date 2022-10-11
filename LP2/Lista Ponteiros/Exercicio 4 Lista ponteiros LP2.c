#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float *nota1 = (float *) malloc(30 * sizeof(float));
	float *nota2 = (float *) malloc(30 * sizeof(float));
	float *mediaAluno = (float *) malloc(30 * sizeof(float));
 	float mediaNota1 = 0, mediaNota2 = 0;
 	int i;
 	
 	if(nota1 == NULL || nota2 == NULL || mediaAluno == NULL)
 		exit(-1);
 		
 	for(i = 0; i < 30; i++)
 	{
 		printf("Digite as duas notas do Aluno[%d]\n", i + 1);
 		scanf("%f %f", &nota1[i], &nota2[i]);
 		
 		mediaAluno[i] = (nota1[i] + nota2[i]) / 2;
 		mediaNota1 += nota1[i];
		mediaNota2 += nota2[i]; 
 		
 		printf("Media Aluno[%d] = %.1f\n", i + 1, mediaAluno[i]);
 		
 		if(mediaAluno[i] >= 7)
 			printf("Aluno Aprovado\n");
 		else
 			printf("Aluno Reprovado\n");
 			
 		setbuf(stdin, NULL);
 				
 		printf("\n");
 		
	}
 	
 	mediaNota1 /= 30;
 	mediaNota2 /= 30;
	
	printf("Media Turma Prova 1 = %.1f\n", mediaNota1);
	printf("Media Turma Prova 2 = %.1f\n", mediaNota2);
	
	free(nota1);
	free(nota2);
	free(mediaAluno);
	
	return 0;
}

/*
	Exercício Revisão
	Retorna o maior e o segundo maior elemento de um vetor aleatório de tamanho 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	
	int i, vetor[10] = {0}, maior, menor;
	
	srand(time(NULL));
	
	for(i = 0, maior = vetor[i], menor = vetor[i]; i < 10; i++)
	{
		vetor[i] = rand () % 50;
		
		if(vetor [i] > maior)
		{
			menor = maior;
			maior = vetor[i];		
		}
		else if(vetor[i] < maior && vetor [i] > menor)
			menor = vetor[i];
		
		printf("%d ", vetor[i]);	
	}
	printf("\n\n");
	
	printf("Maior Elemento: %d\nSegundo Maior Elemento: %d\n", maior, menor);
	
	return 0;
}

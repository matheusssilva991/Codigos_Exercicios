#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int valorA, valorB, valorC, *ptrValorA = &valorA, *ptrValorB = &valorB, *ptrValorC = &valorC;
	
	printf("Digite tres valores\n");
	scanf("%d %d %d", &valorA, &valorB, &valorC);
	
	printf("Valor apontado por ptrA = %d\n", *ptrValorA);
	printf("Valor apontado por ptrB = %d\n", *ptrValorB);
	printf("Valor apontado por ptrC = %d\n", *ptrValorC);
	
	return 0;
}

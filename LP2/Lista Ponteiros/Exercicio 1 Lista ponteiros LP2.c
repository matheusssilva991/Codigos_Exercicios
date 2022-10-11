#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	float valorA, *ptrValorA = &valorA;
	
	printf("Digite um valor\n");
	scanf("%f", &valorA);
	
	printf("a = %.1f\nptrA = %.1f\n\n", valorA, *ptrValorA);
	printf("Endereco de a = %p\nEndereco apontado por ptrA = %p\n", &valorA, ptrValorA);
	
	return 0;
}

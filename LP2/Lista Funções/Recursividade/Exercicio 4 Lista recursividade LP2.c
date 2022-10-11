#include <stdlib.h>
#include <stdio.h>

int acumSum(int );
int acumSumRec(int ); 

int main()
{
	int numero;

	printf("Digite um numero: \n");
	scanf("%d", &numero);

	numero = acumSum(numero);
	printf("Numero = %d\n", numero);

	return 0;
}

int acumSum(int numero)
{
	int i;

	for(i = numero; i > 0; i--)
		numero += i - 1;

	return numero;
}
int acumSumRec(int numero)
{
	if(numero == 0)
		return 0;

	return (numero + acumSum(numero - 1));
}

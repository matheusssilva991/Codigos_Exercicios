#include <stdlib.h>
#include <stdio.h>

int fibonacci(int , int* );

int main ()
{
	int numero = 4, soma = 0;
	numero = fibonacci(numero, &soma);

	printf("%d = %d", numero, soma);

	return 0;
}

int fibonacci(int numero, int* soma)
{
	if(numero == 1 || numero == 2)
		return 1;

	++*soma;
	return fibonacci(numero - 1, soma) + fibonacci(numero - 2, soma);
}


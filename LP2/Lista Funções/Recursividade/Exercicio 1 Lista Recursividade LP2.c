#include <stdio.h>
#include <stdlib.h>

int fatorial(int );
int fibonacci(int );
int *buscaBin(int , int *, int);

int main(void)
{
	int numero, i, array[5] = {1, 2, 3, 4, 5}, tamanho, *ptrNum;
	tamanho = sizeof(array) / sizeof(int);
	
	printf("Digite o numero: \n");
	scanf("%d", &numero);
	setbuf(stdin, NULL);
	
	printf("%d! = %d\n", numero, fatorial(numero));	
	
	ptrNum = buscaBin(numero, array, tamanho);
	
	if(ptrNum == NULL)
		printf("Numero nao encontrado.\n");	
	else
		printf("Numero encontrado: %d\n", *ptrNum);
		
	printf("%d\n", fibonacci(numero));
    
    return 0;
}

int fatorial(int num)
{
	if(num == 0)
		return 1;	
	else
		return num * fatorial(num - 1);	
}

int fibonacci(int num)
{
	if(num == 1 || num == 2)
		return 1;	
	else
		return fibonacci(num - 1) + fibonacci(num - 2);		
}

int *buscaBin(int num, int *p, int tam)
{
	if(tam == 0 )
		return NULL;		
	
	if(*p == num)
		return p;	
	else
		return buscaBin(num, ++p, tam - 1);		
}

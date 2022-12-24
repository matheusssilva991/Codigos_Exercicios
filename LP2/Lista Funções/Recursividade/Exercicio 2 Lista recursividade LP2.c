#include <stdlib.h>
#include <stdio.h>

int multiplica(int , int );

int main ()
{
	unsigned int numeroA, numeroB;
	
	printf("Digite Dois numero: \n");
	scanf("%d %d", &numeroA, &numeroB);
	
//	printf("%d * %d = %d\n", numeroA, numeroB, multiplica(numeroA, numeroB));	
	printf("%d * %d = %d\n", numeroA, numeroB, multiplicaRec(numeroA, numeroB));
	
	return 0;
}

int multiplica(int numA, int numB)
{
	int i, aux = 0;
	
	for(i = 0; i < numA; i++)
		aux += numB;
	
	return aux;	
}

int multiplicaRec(int numA, int numB)
{
	if(numA == 1)
		return numB;	
	else
		return numB + multiplicaRec(numA - 1, numB);	
}

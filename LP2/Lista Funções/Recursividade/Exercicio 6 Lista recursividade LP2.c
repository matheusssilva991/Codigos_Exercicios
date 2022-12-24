#include <stdlib.h>
#include <stdio.h>

int pA(int, int, int);

int main(void)
{
	int first, razao, last;
	
	printf("Digite o primeiro termo: \n");
	scanf("%d", &first);
	setbuf(stdin, NULL);
	
	printf("Digite a razao: \n");
	scanf("%d", &razao);
	setbuf(stdin, NULL);
	
	printf("Digite o enesimo termo: \n");
	scanf("%d", &last);
	setbuf(stdin, NULL);
	
	printf("N = %d\n", pA(first, razao, last));
	
	return 0;
}

int pA(int a, int r, int n)
{
	if(n == 1)
		return a;
		
	else
		return pA(a + r, r, n - 1);	
}

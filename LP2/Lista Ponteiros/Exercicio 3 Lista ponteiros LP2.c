#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	
	int a, b, c, *ptrALL = NULL;
	
	printf("Digite 3 valores \n");
	scanf("%d %d %d", &a, &b, &c);
	
	ptrALL = &a;
	printf("Valor de a apontado por ptrALL e = %d\n", *ptrALL);
	
	ptrALL = &b;
	printf("Valor de b apontado por ptrALL e = %d\n", *ptrALL);
	
	ptrALL = &c;
	printf("Valor de c apontado por ptrALL e = %d\n", *ptrALL);
	
	return 0;
}

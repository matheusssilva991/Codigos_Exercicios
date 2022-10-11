#include <stdlib.h>
#include <stdio.h>

int mdc(int, int);

int main(void)
{
	int numX, numY;
	
	printf("Digite x e y:\n");
	scanf("%d %d", &numX, &numY);
	fflush(stdin);
	
	printf("mdc (x,y) = %d\n", mdc(numX, numY));
	
	return 0;
}

int mdc(int x, int y)
{
	if(y <= x && x % y == 0)
		return y;
		
	if(x < y)
		return mdc(y, x);
		
	else
		return mdc(y, x % y);
}

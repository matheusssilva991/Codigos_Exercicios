#include <stdio.h>

void torre_hanoi(int, char, char, char);

int main(void)
{
    torre_hanoi(3,'A','C','B');
    return 0;
}

void torre_hanoi(int discos, char orig, char dest, char aux)
{
    if(discos == 1)
    {
        printf("Mova disco de %c para %c\n",orig, dest);
        return;
    }

    torre_hanoi(discos-1,orig, aux, dest);
    torre_hanoi(1,orig, dest, aux);
    torre_hanoi(discos-1,aux, dest, orig);
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    FILE *arquivo;
    int guardaTempo, tempoAnterior = 0;
    char c, aux;


    arquivo = fopen("quest15.dat", "wb");

    if(arquivo == NULL)
    {
        printf("erro\n");
        exit(-1);
    }
    printf("digite um caractere:\n");
    c = getchar();
    fflush(stdin);

    while(c != '0') //armazena os caractere no arquivo
    {
        fwrite(&c, sizeof(char), 1, arquivo);

        printf("digite um caractere:\n");
        c = getchar();
        fflush(stdin);

        system("cls");
    }

    fclose(arquivo);

    arquivo = fopen("quest15.dat", "rb");

    if(arquivo == NULL)
    {
        printf("erro\n");
        exit(-1);
    }

    rewind(arquivo);

    guardaTempo = (clock() / CLOCKS_PER_SEC);

    for(;!feof(arquivo);)
    {
        if(guardaTempo != tempoAnterior)
        {
            fread(&aux, sizeof(char), 1, arquivo);
            printf("%c\n", aux);

            tempoAnterior = guardaTempo;
        }
        guardaTempo = (clock() / CLOCKS_PER_SEC);
    }

    fclose(arquivo);

    return 0;
}

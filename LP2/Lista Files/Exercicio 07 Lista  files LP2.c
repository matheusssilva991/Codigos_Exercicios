#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

typedef struct
{
    SYSTEMTIME data_hora;

    int numeroMaq;
    int pecas;
}Tmaquina;

void abrirArquivo(FILE *, FILE *, FILE *);
void escreve(FILE *, Tmaquina *);

int main()
{
    int op = 1;
    FILE *arquivo1, *arquivo2, *arquivo3;
    Tmaquina makina;

    arquivo1 = fopen("Maq1.txt", "a");
    arquivo2 = fopen("Maq2.txt", "a");
    arquivo3 = fopen("Maq3.txt", "a");

    if(arquivo1 == NULL || arquivo2 == NULL || arquivo3 == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    while(op)
    {
        printf("Digite o numero da maquina:\n");
        scanf("%d", &makina.numeroMaq);
        setbuf(stdin, NULL);

        printf("Digite o numero de pecas:\n");
        scanf("%d", &makina.pecas);
        setbuf(stdin, NULL);

        switch(makina.numeroMaq)
        {
            case 1:
                escreve(arquivo1, &makina);
                break;
            case 2:
                escreve(arquivo2, &makina);
                break;
            case 3:
                escreve(arquivo2, &makina);
                break;
            default:
                printf("Numero de maquina inexistente.\n");
        }

        printf("Digite 1 para Continuar.\nDigite 0 para Sair.\n\nDigite a opcao:\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        printf("\n\n");
        system("pause");
        system("cls");
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    return 0;
}


void escreve(FILE *arq, Tmaquina *maquina)
{
    GetLocalTime(&maquina->data_hora);

    fprintf(arq, "%d   %d/%d/%d  %d\n", maquina->numeroMaq, maquina->data_hora.wDay, maquina->data_hora.wMonth, maquina->data_hora.wYear, maquina->pecas);
}

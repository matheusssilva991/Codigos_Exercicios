#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int conta;
    char nome[20];
    float saldo;

}Tclientes;

void escreveArquivo();
void listaSaldo();

int main()
{
    int op;
    void (*escolha[2])() = {escreveArquivo, listaSaldo};

    while(1)
    {
        printf("Digite a opcao:\n");
        printf("1 - Escrever no arquivo.\n");
        printf("2 - Listar saldos.\n");
        printf("3 - Sair.\n");
        scanf("%d", &op);
        printf("\n\n");

        if(op == 3)
            break;

        escolha[op - 1]();
    }

    return 0;
}

void escreveArquivo()
{
    int op = 0;
    Tclientes cliente;
    FILE *arquivo;

    arquivo = fopen("clientes.txt", "a+");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    do
    {
        printf("Digite o numero da conta:\n");
        scanf("%d", &cliente.conta);
        setbuf(stdin, NULL);

        printf("Digite o nome:\n");
        gets(cliente.nome);
        setbuf(stdin, NULL);

        printf("Digite o saldo:\n");
        scanf("%f", &cliente.saldo);
        setbuf(stdin, NULL);

        printf("Digite -1 para sair e qualquer tecla para continuar.\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        fprintf(arquivo, "%d %10s %10.2f\n", cliente.conta, cliente.nome, cliente.saldo);

        system("cls");

    }while(op != -1);

    fclose(arquivo);

    return;
}

void listaSaldo()
{
    Tclientes cliente;
    FILE *arquivo;
    int op = 0;

    arquivo = fopen("clientes.txt", "r+");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    do
    {
        printf("digite a opcao:\n");
        printf("1 - listar contas com saldo zero:\n");
        printf("2 - listar contas com saldo credor:\n");
        printf("3 - listar contas com saldo devedor:\n");
        printf("4 - Sair:\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        fscanf(arquivo, "%d %s %f", &cliente.conta, &cliente.nome, &cliente.saldo);

        switch(op)
        {
            case 1:

                printf("Contas com saldo zero:\n\n");

                while(!feof(arquivo))
                {
                    if(cliente.saldo == 0)
                        printf ("%-10d%-13s%7.2f \n", cliente.conta, cliente.nome, cliente.saldo);

                    fscanf(arquivo, "%d %s %f", &cliente.conta, &cliente.nome, &cliente.saldo);
                }
                break;

            case 2:

                printf("Contas com saldo credor:\n\n");

                while(!feof(arquivo))
                {
                    if(cliente.saldo > 0)
                         printf ("%-10d%-13s%7.2f \n", cliente.conta, cliente.nome, cliente.saldo);

                    fscanf(arquivo, "%d %s %f", &cliente.conta, &cliente.nome, &cliente.saldo);
                }
                break;

            case 3:

                printf("Contas com saldo devedor:\n\n");

                while(!feof(arquivo))
                {
                    if(cliente.saldo < 0)
                        printf ("%-10d%-13s%7.2f \n", cliente.conta, cliente.nome, cliente.saldo);

                    fscanf(arquivo, "%d %s %f", &cliente.conta, &cliente.nome, &cliente.saldo);
                }
                break;
        }
        rewind(arquivo);

        system("pause");
        system("cls");

    }while(op != 4);

    fclose(arquivo);
}

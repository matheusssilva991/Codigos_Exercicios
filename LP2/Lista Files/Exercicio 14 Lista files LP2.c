#include <stdlib.h>
#include <stdio.h>

typedef struct
{
   long int conta;
   char nome[30];
   float saldo;

}Tcliente;

void inserir(FILE *);
void atualizar(FILE *);
void credor(FILE *);
void devedor(FILE *);

int main()
{
    FILE *arquivo;
    int op = 1;
    void (*ptr[4])(FILE *) = {inserir, atualizar, credor, devedor};

    arquivo = fopen("quest14.dat", "rb+");

    if(arquivo == NULL)
    {
        printf("criar arquivo\n");
        arquivo = fopen("quest14.dat", "wb+");

        if(arquivo == NULL)
        {
            printf("Erro\n");
            exit(1);
        }
    }

    while(1)
    {
        printf("[1] Inserir Conta\n[2] Atualizar Saldo\n[3] Listar Clientes Credores\n[4] Listar Clientes Devedores\n[5]Sair\n");
        scanf("%d", &op);
        fflush(stdin);

        if(op == 5)
            break;

        ptr[op - 1](arquivo);

        system("cls");
    }

    fclose(arquivo);

    return 0;
}

void inserir(FILE *arquivo)
{

    Tcliente cliente, aux = {0, "", 0.0};

    printf("Digite o numero da conta: "); ///pego o numero da conta
    scanf("%ld", &cliente.conta);
    fflush(stdin);
    printf("\n");

    fseek(arquivo, sizeof(Tcliente) * (cliente.conta - 1), SEEK_SET);///movo o cursor para a posição da conta
    fread(&aux, sizeof(Tcliente), 1, arquivo); /// pego as informações da conta com uma variavel auxiliar

    if(aux.conta != 0)
    {
        printf("Numero de conta ja existente.\n\n");
        system("pause");
        system("cls");
            return;
    }
    printf("Digite o nome do cliente:\n");
    gets(cliente.nome);
    fflush(stdin);

    printf("Digite o saldo do cliente:\n");
    scanf("%f", &cliente.saldo);
    fflush(stdin);

    fseek(arquivo, sizeof(Tcliente) * (cliente.conta - 1), SEEK_SET);
    fwrite(&cliente, sizeof(Tcliente), 1, arquivo);

    system("cls");
}

void atualizar(FILE *arquivo)
{
    Tcliente cliente;
    long int auxConta;

    rewind(arquivo);

    printf("Digite o numero da conta:  "); /// eu uso uma variavel auxiliar pra guardar a conta
    scanf("%d", &auxConta);
    fflush(stdin);
    printf("\n");

    fseek(arquivo, (auxConta - 1)* sizeof(Tcliente), SEEK_SET); /// eu localizo a conta que quero modificar e aponto pra ela
    fread(&cliente, sizeof(Tcliente), 1, arquivo); /// pego os dados dela na minha struct

    if(auxConta != cliente.conta) ///verifico se minha conta existe
    {
        printf("Conta nao existe.\n\n");
        system("pause");
        system("cls");
        return;
    }
    printf("Digite o novo saldo da conta:\n"); ///faço a modificação do saldo
    scanf("%f", &cliente.saldo);
    setbuf(stdin, NULL);

    fseek(arquivo, (cliente.conta - 1)* sizeof(Tcliente), SEEK_SET); /// boto o cursor novamente na conta que quero atualizar
    fwrite(&cliente, sizeof(Tcliente), 1, arquivo); /// faço a modificação

    system("cls");
}

void credor(FILE *arquivo)
{
    Tcliente cliente;

    rewind(arquivo);

    fread(&cliente, sizeof(Tcliente), 1, arquivo);

    while(!feof(arquivo))
    {
        if(cliente.saldo > 0)
            printf("Numero da conta: %ld\nNome: %s\nSaldo: %.2f\n\n\n", cliente.conta, cliente.nome, cliente.saldo);

        fread(&cliente, sizeof(Tcliente), 1, arquivo);

    }

    printf("\n\n");
    system("pause");
}

void devedor(FILE *arquivo)
{
    Tcliente cliente;

    rewind(arquivo);

    fread(&cliente, sizeof(Tcliente), 1, arquivo);

    while(!feof(arquivo))
    {
        if(cliente.saldo < 0)
            printf("Numero da conta: %ld\nNome: %s\nSaldo: %.2f\n\n\n", cliente.conta, cliente.nome, cliente.saldo);

        fread(&cliente, sizeof(Tcliente), 1, arquivo);
    }

    printf("\n\n");
    system("pause");
}

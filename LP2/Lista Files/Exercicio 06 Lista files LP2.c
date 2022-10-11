#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int numeroInscricao;
    char nome[30];
    char sexo[2];
    char curso[20];

}Tcadastro;

void mostra();
void escreve();
void procura();

int main()
{
    int op;
    void (*ptrOp[3])() = {escreve, procura, mostra};

    while(1)
    {
        printf("[1]Inserir Candidato\n[2]Mostrar um Candidato\n[3]Listar todos os Candidatos\n[4]Sair\n\nDigite a opcao:\n\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        if(op == 4)
            break;

        ptrOp[op - 1]();

        system("cls");
    }

    return 0;
}

void escreve()
{
    FILE *arquivo;
    Tcadastro cadastro;
    int op = 1;

    arquivo = fopen("quest6.txt", "a+");

    if(arquivo == NULL)
    {
        printf("Erro");
        exit(-1);
    }

    while(op)
    {
        printf("Digite o numero de inscricao:\n");
        scanf("%d", &cadastro.numeroInscricao);
        setbuf(stdin, NULL);

        printf("Digite o nome do candidato:\n");
        gets(cadastro.nome);
        setbuf(stdin, NULL);

        printf("Digite o Sexo do Candidato:   [M] [F]\n");
        gets(cadastro.sexo);
        setbuf(stdin, NULL);

        printf("Digite o curso do Candidato:\n");
        gets(cadastro.curso);
        setbuf(stdin, NULL);

        fprintf(arquivo, "%d%13s%5s%13s\n", cadastro.numeroInscricao, cadastro.nome, cadastro.sexo, cadastro.curso);
        fflush(arquivo);

        printf("Digite 1 para Continuar.\nDigite 0 para Sair.\n ? ");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        system("cls");
    }

    fclose(arquivo);
}

void procura()
{
    FILE *arquivo;
    Tcadastro cadastro;
    int numero;

    arquivo = fopen("quest6.txt", "r");

    if(arquivo == NULL)
    {
        printf("Erro");
        return ;
    }

    rewind(arquivo);

    printf("Digite o numero de inscricao:\n");
    scanf("%d", &numero);
    setbuf(stdin, NULL);

    while(!feof(arquivo))
    {
        fscanf(arquivo, "%d %s %s %s", &cadastro.numeroInscricao, &cadastro.nome, &cadastro.sexo, &cadastro.curso);

        if(numero == cadastro.numeroInscricao)
        {
            printf("Numero de inscricao:%d\nNome:%s\nSexo: [%s]\nCurso: %s\n\n\n", cadastro.numeroInscricao, cadastro.nome, cadastro.sexo, cadastro.curso);
            system("pause");
            break;
        }
    }

    fclose(arquivo);
}

void mostra()
{
    FILE *arquivo;
    Tcadastro cadastro;

    arquivo = fopen("quest6.txt", "r");

    if(arquivo == NULL)
    {
        printf("Erro");
        return;
    }

    rewind(arquivo);

    fscanf(arquivo, "%d %s %s %s", &cadastro.numeroInscricao, &cadastro.nome, &cadastro.sexo, &cadastro.curso);

    while(!feof(arquivo))
    {
        printf("Numero de inscricao:%d\nNome:%s\nSexo: [%s]\nCurso: %s\n\n", cadastro.numeroInscricao, cadastro.nome, cadastro.sexo, cadastro.curso);
        fscanf(arquivo, "%d %s %s %s", &cadastro.numeroInscricao, &cadastro.nome, &cadastro.sexo, &cadastro.curso);
    }
    
    printf("\n\n");
    system("pause");
    system("cls");

    fclose(arquivo);
}

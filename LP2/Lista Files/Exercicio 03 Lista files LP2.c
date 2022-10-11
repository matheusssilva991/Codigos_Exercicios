#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char nome[20];
    long int matricula;
    char sexo;
    int idade;
    char email[100];

}Tcadastro;

void escreve(FILE *, Tcadastro *);

int main()
{
    FILE *arquivo;
    Tcadastro cadastro;
    int op;

    arquivo = fopen("Quest3.txt", "w");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(-1);
    }

    do{
        escreve(arquivo, &cadastro);

        printf("Digite a opcao: 1 para continuar e 0 para sair:\n");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        system("cls");

    }while(op);

    fclose(arquivo);

    return 0;
}

void escreve(FILE *arq, Tcadastro *cad)
{

    printf("Digite o nome:\n");
    gets(cad -> nome);
    setbuf(stdin, NULL);

    printf("Digite o numero da matricula:\n");
    scanf("%ld", &(cad -> matricula));
    setbuf(stdin, NULL);

    printf("Digite o sexo:   [M] or [F]\n");
    cad -> sexo = getchar();
    setbuf(stdin, NULL);

    printf("Digite a idade:\n");
    scanf("%d", &(cad -> idade));
    setbuf(stdin, NULL);

    printf("Digite o email:\n");
    gets(cad -> email);
    setbuf(stdin, NULL);

    fprintf(arq, "%-10s%8ld%5c%5d%16s\n", cad -> nome, cad -> matricula, cad -> sexo, cad -> idade, cad -> email);
}

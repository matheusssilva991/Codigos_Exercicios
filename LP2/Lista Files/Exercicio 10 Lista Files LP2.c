#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int placa;
    float km, combustivel;

}Tveiculo;

int main()
{
    FILE *arquivo;
    Tveiculo veiculo;
    int op = 1;

    arquivo = fopen("Quest10.dat", "ab");

    if(arquivo == NULL)
    {
        printf("erro ao abrir\n");
        exit(-1);

    }
    while(op)
    {
        printf("Digite a placa do carro:\n");
        scanf("%d", &veiculo.placa);
        setbuf(stdin, NULL);

        printf("Digite a quilometragem do carro:\n");
        scanf("%f", &veiculo.km);
        setbuf(stdin, NULL);

        printf("Digite a quantidade de combustivel do carro:\n");
        scanf("%f", &veiculo.combustivel);
        setbuf(stdin, NULL);

        fwrite(&veiculo, sizeof(Tveiculo), 1, arquivo);

        printf("Digite 1 para Continuar\nDigite 0 para Sair\n\nDigite a opcao:  ");
        scanf("%d", &op);
        setbuf(stdin, NULL);

        system("cls");

    }

    fclose(arquivo);

    return 0;
}

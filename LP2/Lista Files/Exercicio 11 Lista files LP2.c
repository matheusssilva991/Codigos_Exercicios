#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int placa;
    float km, combustivel;

}Tveiculo;

int main()
{
    FILE *arquivo, *arquivo2;
    Tveiculo veiculo;
    float media;

    arquivo = fopen("Quest10.dat", "rb");
    arquivo2 = fopen("Quest11.txt", "w");

    if(arquivo == NULL || arquivo2 == NULL)
    {
        printf("erro ao abrir\n");
        exit(-1);

    }

    fread(&veiculo, sizeof(Tveiculo), 1, arquivo);

    while(!feof(arquivo))
    {
        media = veiculo.km / veiculo.combustivel;

        fprintf(arquivo2, "Placa: %d     Quilometragem: %.2f Quantidade de Combustivel %.2f  Media Quilometro/Combustivel: %.2f\n", veiculo.placa, veiculo.km, veiculo.combustivel, media);

        fread(&veiculo, sizeof(Tveiculo), 1, arquivo);
    }

    fclose(arquivo);
    fclose(arquivo2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR 100
#define QUANTIDADE_VETORES 1024
#define NUMEROEXECUCOES 1024

void salvarTempoExecucao(char *nomeArquivo, double *vetor);
void printaVetores(int **vetores);
int **gerarVetores();
void liberaVetores(int **vetores);
void insertionSort(int array[], int size);
void limpaArquivo(char *nomeArquivo);

int main(int argc, char const *argv[])
{
    int **vetores;
    clock_t t_start, t_end;
    double time_spent;
    double *temposExecucao;
    FILE *file;

    temposExecucao = (double *) malloc(sizeof(double) * NUMEROEXECUCOES);

    srand(time(NULL));

    limpaArquivo("amostras_c.txt"); 
    file = fopen("amostras_c.txt", "a");

    if (file == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
        exit(-1);
    }

    for (int j = 0; j < NUMEROEXECUCOES; j++){
        vetores = gerarVetores();

        //Salva a amostra atual no arquivo
        for(int linha = 0; linha < QUANTIDADE_VETORES; linha++){
            for(int coluna = 0; coluna < TAM_VETOR; coluna++)
                fprintf(file, "%d ", vetores[linha][coluna]);
        
            fprintf(file, "\n");
        }

        // Ordena os vetores e pega o tempo de execução
        t_start = clock();
        for (int i = 0; i < QUANTIDADE_VETORES; i++)
            insertionSort(vetores[i], TAM_VETOR);
        t_end = clock();

        // calcula o tempo de execução e salva ele no vetor
        time_spent = (double)(t_end - t_start) / CLOCKS_PER_SEC;
        temposExecucao[j] = time_spent;

        liberaVetores(vetores);
    }

    fclose(file);
    salvarTempoExecucao("tempoExecucao_c.txt", temposExecucao);
    free(temposExecucao);
    
    return 0;
}

void salvarTempoExecucao(char *nomeArquivo, double *vetor){
    FILE *file = fopen(nomeArquivo, "w");

    if (file == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
        exit(-1);
    }

    fprintf(file, "%d\n", NUMEROEXECUCOES);

    for(int i = 0; i < NUMEROEXECUCOES; i++)
        fprintf(file, "%lf\n", vetor[i]);

    fclose(file);
}

void printaVetores(int **vetores){
     for (int i = 0; i < QUANTIDADE_VETORES; i++){
        for (int j = 0; j < TAM_VETOR; j++)
            printf("%d ", vetores[i][j]);

        printf("\n");
    }
}

int **gerarVetores(){
    int **vetores;

    vetores =  (int **) malloc(sizeof(int*) * QUANTIDADE_VETORES);

    if (vetores == NULL){
        printf("Erro, vetor nao alocado.\n");
        exit(-1);
    }

    for(int i = 0; i < QUANTIDADE_VETORES; i++)
    {
        vetores[i] = (int *) malloc(sizeof(int) * TAM_VETOR);

        if (vetores[i] == NULL){
            printf("Erro, vetor nao alocado.\n");
            exit(-1);
        }
    }
        
    for (int i = 0; i < QUANTIDADE_VETORES; i++)
        for (int j = 0; j < TAM_VETOR; j++)
            vetores[i][j] = rand() % 1000;
        
    return vetores;
}

void liberaVetores(int **vetores){
    for(int i = 0; i < QUANTIDADE_VETORES; i++)
        free(vetores[i]);
    free(vetores);
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void limpaArquivo(char *nomeArquivo){
    FILE *file = fopen(nomeArquivo, "w");

    if (file == NULL){
        printf("ERRO! O arquivo não foi aberto!\n");
        exit(-1);
    }

    fclose(file);
}
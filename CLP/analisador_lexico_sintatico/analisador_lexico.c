#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void analisador_lexico(char *palavra, char *gramatica);
int in_gramatica(char caractere, char *gramatica);
void escrever_arquivo();

int main()
{
    FILE *file;
    char *palavra,*gramatica;
    int op;

    //escrever_arquivo();

    while (1){
        printf("Escolha a gramatica:\n1. Binaria\n2. Decimal\n>> ");
        scanf(" %d", &op);

        if (op == 1){
            gramatica = "01";
            break;
        }
        else if (op == 2){
            gramatica = "0123456789";
            break;
        }
    }
    printf("\n");

    file = fopen("palavras_teste.txt", "r");

    if (file == NULL){
        printf("Erro ao abrir o arquivo para leitura.\n");
        exit(-1);
    }

    while (fscanf(file, "%s", palavra) != -1) {
        printf("Palavra: %s\n", palavra);
        analisador_lexico(palavra, gramatica);
    }

    fclose(file);

    return 0; 
}

void analisador_lexico(char *palavra, char *gramatica){
    int tam_palavra = strlen(palavra);
    int q_state = 0;
    char token, word[512], rejected[512];
    int index_word = -1, index_rejected = -1;

    for (int i = 0; i < tam_palavra; i++){
        token = palavra[i];

        if (in_gramatica(token, gramatica)){
            index_word++;
            word[index_word] = token;
            q_state = 1;
        } 
        else if (q_state == 0){
            printf("Palavra %s nao reconhecida.\n\n", palavra);
            break;
        }
        else{
            index_rejected++;
            rejected[index_rejected] = token;
        }      
    }

    index_word++;
    word[index_word] = '\0';
    index_rejected++;
    rejected[index_rejected] = '\0';

    if (q_state == 1){
        printf("Caracteres Rejeitados: %s\n", rejected);
        printf("A palavra %s foi reconhecida.\n\n", word); 
    }          
}

int in_gramatica(char caractere, char *gramatica){
    int tam_gramatica = strlen(gramatica);

    for (int i = 0; i < tam_gramatica; i++)
        if (caractere == gramatica[i])
            return 1;  
    return 0;
}

void escrever_arquivo(){
    FILE *file;
    char *palavra;
    int op;

    file = fopen("palavras_teste.txt", "w");

    if (file == NULL){
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    while(1){
        printf("Digite a palavra a ser escrita:\n>> ");
        scanf(" %s", palavra);
        fflush(stdin);
        printf("\n");

        fprintf(file, "%s\n", palavra);

        printf("Digite -1 para sair ou qualquer outro numero para continuar...:\n>> ");
        scanf("%d", &op);

        if (op == -1)
            break;  
    }
    
    fclose(file);
}
import java.util.Random;
import java.io.*;

public class ordenacaoOO {

    public static void main(String[] args) throws IOException {
        int tam_vetor = 100;
        int quantidade_vetor = 1024;
        int numeroExecucoes = 1024;
        long temposExecucoes[] = new long[numeroExecucoes];
        int matriz[][] = new int [quantidade_vetor][tam_vetor];
        long start, elapsed;
        BufferedWriter br = new BufferedWriter(new FileWriter("amostras_java.txt"));
        
        for (int i = 0; i < numeroExecucoes; i++){
            gerarVetores(matriz, quantidade_vetor, tam_vetor);

            // Escreve os vetores utilizados no arquivo
            for(int linha = 0; linha < quantidade_vetor; linha++){
                for(int coluna = 0; coluna < tam_vetor; coluna++){
                    br.write(matriz[linha][coluna] + " ");
                }
                br.newLine();
            }

            //Ordena os vetores e pegar o tempo de execução
            start = System.currentTimeMillis();
            for(int j = 0; j < quantidade_vetor; j++)
                insertionSort(matriz[j]);
            elapsed = System.currentTimeMillis() - start; 

            temposExecucoes[i] = elapsed;
        }

        br.close();
        // Escreve os tempos de execução gasto na ordenação de cada vetor
        salvarTempoExececucao(temposExecucoes, numeroExecucoes); 
        //printaMatriz(matriz, quantidade_vetor, tam_vetor);

    }

    public static void gerarVetores(int matriz[][], int quantidade_vetor, int tam_vetor){
        Random random = new Random();

        for (int i = 0; i < quantidade_vetor; i++){
            for(int j = 0; j < tam_vetor; j++){
                matriz[i][j] = random.nextInt(1000);
            }
        }
    }

    public static void salvarTempoExececucao(long vetorExecucao[], int numeroExecucoes) throws IOException{
        BufferedWriter br = new BufferedWriter(new FileWriter("tempoExecucao_java.txt"));
        String temp;

        br.write(Integer.toString(numeroExecucoes));
        br.newLine();

        for(int i = 0; i < numeroExecucoes; i++){
            temp = Long.toString(vetorExecucao[i]);
            br.write(temp);
            br.newLine();
        }
        br.close();
    }

    public static void printaMatriz(int matriz[][], int quantidade_vetor, int tam_vetor){
        for (int i = 0; i < quantidade_vetor; i++){
            for(int j = 0; j < tam_vetor; j++){
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void insertionSort(int array[]) {
        int size = array.length;
    
        for (int step = 1; step < size; step++) {
          int key = array[step];
          int j = step - 1;
    
          while (j >= 0 && key < array[j]) {
            array[j + 1] = array[j];
            --j;
          }
    
          array[j + 1] = key;
        }
      }
}
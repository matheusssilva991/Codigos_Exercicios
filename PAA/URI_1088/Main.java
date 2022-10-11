import java.util.Scanner;

public class Main {
    
    public static void merge(int[] leftArray,int[] rightArray, int[] array,int left_size, int right_size, int count_swap[]){
      
        int k=0,indexLeft=0,indexRight = 0;
        while(indexLeft<left_size && indexRight<right_size){
            
            if(leftArray[indexLeft]<rightArray[indexRight]){
                array[k++] = leftArray[indexLeft++];
            }
            else{
                array[k++] = rightArray[indexRight++];
                //count_swap[0] += left_size - indexLeft;
                count_swap[0] += 1;
            }
        }
        while(indexLeft<left_size){
            array[k++] = leftArray[indexLeft++];
        }
        while(indexRight<right_size){
          array[k++] = rightArray[indexRight++];
        }
    }
  
    public static void mergeSort(int [] array, int lenArray, int count_swap[]){
        if(lenArray > 1)
        {
            int mid = lenArray / 2;
            int [] left_arr = new int[mid];
            int [] right_arr = new int[lenArray-mid];
        
            int k = 0;
            for(int i = 0;i<lenArray;++i){
                if(i<mid){
                    left_arr[i] = array[i];
                }
                else{
                    right_arr[k] = array[i];
                    k = k+1;
                }
            }   
            mergeSort(left_arr,mid, count_swap);
            mergeSort(right_arr,lenArray-mid, count_swap);
            merge(left_arr,right_arr,array,mid,lenArray-mid, count_swap);
       }   
    }

    public static void main(String[] args) {
        int count_swap[] = new int[1];
        String buffer;
        int sequence [];
        Scanner input = new Scanner(System.in);
        count_swap[0] = 0;

        while(true){
            count_swap[0] = 0;
            buffer = input.nextLine();

            if(buffer.charAt(0) == '0')
                break;

            String [] arrayTemp = buffer.split(" ");
            sequence = new int[arrayTemp.length - 1];

            for(int i = 0; i < sequence.length; i++)
                sequence[i] = Integer.parseInt(arrayTemp[i + 1]);

            mergeSort(sequence, sequence.length, count_swap);
            
            if(count_swap[0] % 2 == 0)
                System.out.println("Carlos");
            else
                System.out.println("Marcelo");
        }  
        input.close();
    }
}
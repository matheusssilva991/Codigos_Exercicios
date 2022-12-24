def merge_sort(array):
    if len(array) > 1:

        r = len(array)//2
        L = array[:r]
        M = array[r:]

        merge_sort(L)
        merge_sort(M)

        i = j = k = 0
        
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                global count_swaps
                array[k] = M[j]
                j += 1
                print(len(L))
                count_swaps += len(L) - i  
            k += 1

        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1

while(1):
    count_swaps = 0
   
    sequence = input().split(" ")
    number_elements = int(sequence[0]) 
    
    if(number_elements == 0):
        break  
    sequence = sequence[1:]
    
    merge_sort(sequence)
    
    if(count_swaps % 2 == 0):
        print("Carlos")
    else:
        print("Marcelo")
def merge_sort(array, count_swaps):
    lenghtVetor = len(array)
   
    if(lenghtVetor > 1):
        mid = lenghtVetor // 2
        arrayLeft = array[:mid]
        arrayRight = array[mid:lenghtVetor]
        
        merge_sort(arrayLeft, count_swaps)
        merge_sort(arrayRight, count_swaps)
        merge(arrayLeft, arrayRight, array, count_swaps) 
   
def merge(arrayLeft, arrayRight, array, count_swaps):
    indiceLeft = indiceRight = 0
    lenghtArrayLeft = len(arrayLeft)
   
    while indiceLeft + indiceRight < len(array):
        if indiceRight == len(arrayRight) or (indiceLeft < lenghtArrayLeft and arrayLeft[indiceLeft] < arrayRight[indiceRight]):
            array[indiceLeft+indiceRight] = arrayLeft[indiceLeft]
            indiceLeft += 1
        else:
            array[indiceLeft+indiceRight] = arrayRight[indiceRight]
            indiceRight += 1
            count_swaps[0] += lenghtArrayLeft - indiceLeft

while(1):
    count_swaps = [0]  
   
    sequence = input().split(" ")
     
    if(sequence[0] == '0'):
        break 
    
    sequence = sequence[1:]   
      
    merge_sort(sequence, count_swaps)
    
    if(count_swaps[0] % 2 == 0):
        print("Carlos")
    else:
        print("Marcelo")
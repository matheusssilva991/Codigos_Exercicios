def heapify(arr, lenghtTree, currentNode, count_swaps):
    largest = currentNode
    leftNode = 2 * currentNode + 1
    rightNode = 2 * currentNode + 2
    
    if leftNode < lenghtTree and arr[currentNode] < arr[leftNode]:
        largest = leftNode
        
    if rightNode < lenghtTree and arr[largest] < arr[rightNode]:
        largest = rightNode

    if largest != currentNode:
        arr[currentNode],arr[largest] = arr[largest],arr[currentNode]
        count_swaps[0] += 1
        heapify(arr, lenghtTree, largest, count_swaps)

def heapSort(arr, count_swaps):
    lenghtTree = len(arr)

    for i in range(lenghtTree // 2 - 1, -1, -1):
        heapify(arr, lenghtTree, i, count_swaps)

    for i in range(lenghtTree-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0, count_swaps)
        count_swaps[0] += 1

while(1):
    count_swaps = [0]  
   
    sequence = input().split(" ")
     
    if(sequence[0] == '0'):
        break 
    
    sequence.pop(0)   
      
    heapSort(sequence, count_swaps)
    
    if(count_swaps[0] % 2 == 0):
        print("Carlos")
    else:
        print("Marcelo")
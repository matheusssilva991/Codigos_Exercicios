import copy

def reboot(seq_data, index):
    """Desfaz a otimização"""
    elementAux = seq_data[index][0]
    
    for i in range(index, -1, -1):
        if(seq_data[i][0] == elementAux):
            seq_data[i][0] -= 1
    for i in range(index + 1, len(seq_data)):
        seq_data[i][1] += 1       
       
def decreasePrefix(seq_data, index):
    """Diminui a quantidade de bits dos prefixos do sub-vetor a direia"""
    for i in range(index + 1, len(seq_data)):
        seq_data[i][1] -= 1
       
def increaseData(seq_data, index):
    """Aumenta a quantidade de bits dos dados a esquerda com a mesma quantidade de bits"""
    elementAux = seq_data[index][0]
   
    for i in range(index, -1, -1):
        if(seq_data[i][0] == elementAux):
            seq_data[i][0] += 1
         
def optimizer(sequence, seq_data, seq_data2):
    """Realiza a otimização de uma sequência de elementos codificado com a codificação Gamma Elias"""
    sequence_aux = list(set(sequence))
    sequence_aux.sort()
   
    while(sequence_aux != []):
        analyzeElement = sequence_aux[0]
        index = []
       
        if(sequence.count(analyzeElement) == 1):
            index.append(sequence.index(analyzeElement))
        else:
            for i in range(len(sequence)): #Caso não seja único pega os indices
                if sequence[i] == analyzeElement:
                    index.append(i)
       
        for i in index: #Itera sobre os elementos
            if (i == len(sequence) - 1):
                continue
            elif sequence[i] == 0:
                decreasePrefix(seq_data, i)
                decreasePrefix(seq_data2, i)
            elif((seq_data[i][0] + 1) == (seq_data[i + 1][0])):
                checkSum(sequence, seq_data, i, 1)
            elif(seq_data2[i][0] + 1) == (seq_data2[i + 1][0]):
                checkSum(sequence, seq_data2, i, 2)
        sequence_aux.remove(analyzeElement)
       
def checkSum(sequence, seq_data, index, op):
    """Verifica se o decremento do prefixo vai gerar uma otimização"""
    total = 0
    total_aux = 0
   
    for i in range(0, len(sequence)):
        total += sequence[i] * (seq_data[i][0] + seq_data[i][1])
        
    increaseData(seq_data, index)
    decreasePrefix(seq_data, index)   
        
    for i in range(0, len(sequence)):
        total_aux += sequence[i] * (seq_data[i][0] + seq_data[i][1])
    
    if (op == 1 and total > total_aux):
        return   
    elif (op == 2 and total >= total_aux):
        return
    else:
        reboot(seq_data, index)
        
while(True):
    sequence = []
    seq_data = []
    total = 0
    total2 = 0
       
    number_elements = int(input()) # pega a quantidade de elementos na sequência
   
    if(number_elements == 0):
        break
   
    sequence = input().split(" ") # pega os elementos da sequência
   
    for i in range(1, number_elements + 1): # Converte para Int e constroi a lista com os dados e o prefixo
        sequence[i - 1] = int(sequence[i - 1])
        seq_data.append([i, i])  
     
    seq_data2 = copy.deepcopy(seq_data)
    optimizer(sequence, seq_data, seq_data2) # Chama a função de otimização
   
    for i in range(len(sequence)):
        total += sequence[i] * (seq_data[i][0] + seq_data[i][1])
        total2 += sequence[i] * (seq_data2[i][0] + seq_data2[i][1])
        
    if(total < total2):
        print(total)
    else:
        print(total2)
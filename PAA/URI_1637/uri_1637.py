def reboot(seq_data, index):
    """Desfaz a otimização"""
    elementAux = seq_data[index][0]
    
    for i in range(index, -1, -1):
        if(seq_data[i][0] == elementAux):
            seq_data[i][0] -= 1
    for i in range(index + 1, len(seq_data)):
        seq_data[i][1] += 1 

def printaSeq(sequence, seq_data):
    data = [seq_data[i][0] for i in range(len(seq_data))]
    prefix =  [seq_data[i][1] for i in range(len(seq_data))]
    
    print("| ",sequence, " |")
    print("| ", data, " |")
    print("| ", prefix, " |\n")
        
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
         
def optimizer(sequence, seq_data):
    """Realiza a otimização de uma sequência de elementos codificado com a codificação Gamma Elias"""
    
    sequence_aux = list(set(sequence)) # coloca os elementos como valores únicos em uma sequência auxiliar
    sequence_aux.sort()
        
    while(sequence_aux != []):
        analyzeElement = sequence_aux[0] # faz a escolha gulosa e pega o menor elemento
        indexes = []
            
        if(sequence.count(analyzeElement) == 1): # Verifica se o elemento em analise é único
            indexes.append(sequence.index(analyzeElement))
        else:
            for i in range(len(sequence)): #Caso não seja único pega os indices
                if sequence[i] == analyzeElement:
                    indexes.append(i)
            
        for i in indexes: #Itera sobre os elementos
            if (i == len(sequence) - 1): 
                continue
            elif sequence[i] == 0: 
                decreasePrefix(seq_data, i)
            elif((seq_data[i][0] + 1) == (seq_data[i + 1][0])): 
                checkSum(sequence, seq_data, i)
        sequence_aux.remove(analyzeElement) 
          
        
def checkSum(sequence, seq_data, index):
    """Verifica se o decremento do prefixo vai gerar uma otimização"""
    total = 0
    total_aux = 0
    
    for i in range(0, len(sequence)):
        total += sequence[i] * (seq_data[i][0] + seq_data[i][1]) 
        
    increaseData(seq_data, index)
    decreasePrefix(seq_data, index)
    
    for i in range(0, len(sequence)):
        total_aux += sequence[i] * (seq_data[i][0] + seq_data[i][1])
    
    if total > total_aux:
        return
    else:
        reboot(seq_data, index)
       
while(True):
    sequence = []
    seq_data = []
    total = 0
        
    number_elements = int(input()) # pega a quantidade de elementos na sequência
    
    if(number_elements == 0):
        break
    
    sequence = input().split(" ") # pega os elementos da sequência
    
    for i in range(1, number_elements + 1): # Converte para Int e constroi a lista com os dados e o prefixo
        sequence[i - 1] = int(sequence[i - 1])
        seq_data.append([i, i])  
               
    optimizer(sequence, seq_data) # Chama a função de otimização

    for i in range(len(sequence)):
        total += sequence[i] * (seq_data[i][0] + seq_data[i][1])
        
    print(total)
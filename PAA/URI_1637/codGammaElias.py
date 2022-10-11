def dec2bin(decimal):
    """Retorna a representação binaria de um numero""" 
    binary = []
    
    if(decimal == 0):
        binary.append(0)
        return binary
    
    while(decimal != 0):
        binary.append(decimal % 2)
        decimal = decimal // 2
    binary.reverse()
    return binary

def preFix(numBits):
    """Retorna o preFixo de um número binario"""
    pre_fix = [0 for i in range(numBits - 1)]
    pre_fix.append(1)
    return pre_fix

def encodeGammaElias(number):
    """Retorna um numero com a codificação Gamma Elias"""
    binary = dec2bin(number)
    pre_fix = preFix(len(binary))
    encoded = pre_fix + binary
    return encoded

def main():
    number_elements = -1
    
    while(number_elements != 0):
        sequency = []
        seq_data = []
        total = 0
        
        number_elements = int(input()) # pega a quantidade de elementos na sequência
        
        for i in range(1, number_elements + 1): # pega os elementos da sequência
            element = int(input())
            sequency.append(element)
            seq_data.append([i, i])
                
        #otimizer(sequency, seq_data) # Chama a função de otimização

        for i in range(len(sequency)):
            total += sequency[i] * (seq_data[i][0] + seq_data[i][1])
        
        print(total)
main() 
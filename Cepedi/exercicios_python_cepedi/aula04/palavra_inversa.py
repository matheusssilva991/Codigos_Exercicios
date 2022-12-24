if __name__ == "__main__":
    palavra = input("Digite a palavra a ser invertida: ")
    # palavra_inversa = palavra[::-1]
    palavra_inversa = ''

    for i in range(len(palavra) - 1, -1, -1):
        palavra_inversa += palavra[i]

    print(f'{palavra} inversa é {palavra_inversa}')

if __name__ == "__main__":
    palavra = input("Digite a palavra a ser testada: ")
    paliondromo = True

    for i, j in zip(range(len(palavra) // 2), range(len(palavra) - 1, len(palavra) // 2, -1)):
        if palavra[i] != palavra[j]:
            paliondromo = False
            break

    if paliondromo:
        print(f"a palavra {palavra} é um paliondromo")
    else:
        print(f"a palavra {palavra} não é um paliondromo")

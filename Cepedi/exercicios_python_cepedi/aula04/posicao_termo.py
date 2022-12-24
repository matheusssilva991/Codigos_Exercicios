if __name__ == "__main__":
    texto = input("Digite o texto: ")
    termo = input("Digite o termo: ")

    if termo in texto:
        posicao = texto.index(termo)
    else:
        posicao = -1

    print(f"O termo '{termo}' foi encontrado na posição {posicao} do texto {texto}")

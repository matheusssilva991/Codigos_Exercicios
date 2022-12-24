if __name__ == '__main__':
    valor = int(input("digite o valor: "))

    valores_notas = [200, 100, 50, 20, 10, 5, 2, 1]
    notas = {}

    for nota_atual in valores_notas:
        notas[f'nota_{nota_atual}'] = valor // nota_atual
        valor = valor % nota_atual

        print(f"{notas[f'nota_{nota_atual}']} nota(s) de R$ {nota_atual},00")


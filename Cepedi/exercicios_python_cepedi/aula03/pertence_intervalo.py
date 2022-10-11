if __name__ == '__main__':
    valor = int(input("Digite o numero: "))
    intervalos = ['[0, 25)', '[25, 50)', '[50, 75)', '[75, 100]']

    if 0 <= valor < 25:
        print(f"{valor} pertence ao intervalo {intervalos[0]}")
    elif 25 <= valor < 50:
        print(f"{valor} pertence ao intervalo {intervalos[1]}")
    elif 50 <= valor < 75:
        print(f"{valor} pertence ao intervalo {intervalos[2]}")
    elif 75 <= valor <= 100:
        print(f"{valor} pertence ao intervalo {intervalos[3]}")
    else:
        print(f"Valor inválido: {valor} não pertence ao intervalo[0, 100]")
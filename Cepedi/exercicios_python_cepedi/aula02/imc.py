if __name__ == '__main__':
    peso = float(input("Digite o seu peso: "))
    altura = float(input("Digite a sua altura: "))

    imc = peso / altura ** 2

    print(f"IMC: {imc:.2f}")

if __name__ == '__main__':
    numerador, denominador = list(map(int, input("digite o numerador e o denominador: "). split()))

    if numerador < denominador:
        numerador, denominador = denominador, numerador

    if numerador % denominador == 0:
        print("São multiplos")
    else:
        print("Não são multiplos")

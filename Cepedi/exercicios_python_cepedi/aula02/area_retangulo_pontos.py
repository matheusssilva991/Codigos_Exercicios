if __name__ == '__main__':
    ponto1 = tuple(map(float, input("").split(" ")))
    ponto2 = tuple(map(float, input("").split(" ")))

    base = abs(ponto1[0] - ponto2[0])
    altura = abs(ponto1[1] - ponto2[0])
    area = base * altura

    print(f"Área: {area:.2f}")

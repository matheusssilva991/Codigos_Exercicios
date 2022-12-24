import math

if __name__ == '__main__':
    x_circuferencia, y_circuferencia, raio = list(map(float, input("digite xc, yc e raio").split()))
    x_ponto, y_ponto = list(map(float, input("digite xp, yp").split()))

    distance = math.sqrt((x_circuferencia - x_ponto) ** 2 + (y_circuferencia - y_ponto) ** 2)

    print("está dentro") if distance <= raio else print("fora")



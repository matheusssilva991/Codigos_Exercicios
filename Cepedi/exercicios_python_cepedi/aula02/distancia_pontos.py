import math

if __name__ == "__main__":
    class Ponto:
        def __init__(self, x, y):
            self.x = x
            self.y = y

        def __str__(self):
            return f"({self.x}, {self.y})"

        def distancia_entre_dois_pontos(self, ponto):
            distancia = math.sqrt((self.x - ponto.x) ** 2 + (self.y - ponto.y) ** 2)

            return f"Distância entre {self} e {ponto}: {distancia:.2f}"

    x1, y1 = list(map(float, input("Digite as coordenada do ponto 1: ").split()))
    x2, y2 = list(map(float, input("Digite as coordenada do ponto 2: ").split()))

    ponto1 = Ponto(x1, y1)
    ponto2 = Ponto(x2, y2)

    print(ponto1.distancia_entre_dois_pontos(ponto2))

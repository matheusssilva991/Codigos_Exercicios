class Pessoa:
    def __init__(self, nome, altura, peso):
        self.__nome = nome
        self.__altura = altura
        self.__peso = peso

    @property
    def imc(self):
        return round(self.__peso / (self.__altura ** 2), 2)


if __name__ == "__main__":
    pessoa = Pessoa("matheus", 1.75, 75)
    print(pessoa.imc)

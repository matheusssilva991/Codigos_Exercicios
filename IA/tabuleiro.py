from time import sleep
from random import randint

class Jogador:
    def __init__(self, nome: str, marcador: str) -> None:
        self.nome = nome
        self.marcador = marcador

class Tabuleiro:
    def __init__(self):
        self.tabuleiro = [[1, 2, 3],
                          [4, 5, 6],
                          [7, 8, 9]]
        
        self.mapa_jogadas = {'1': (0, 0), '2': (0, 1), '3': (0, 2),
                             '4': (1, 0), '5': (1, 1), '6': (1, 2),
                             '7': (2, 0), '8': (2, 1), '9': (2, 2)}
        
    def pega_jogadas_disponiveis(self):
        return [str(self.tabuleiro[i][j]) for i in range(3) for j in range(3) 
            if self.tabuleiro[i][j] not in ['X', 'O']]
         
    def checa_vitoria(self, marcador):
        for i in range(3):
            if [self.tabuleiro[i][0], self.tabuleiro[i][1], self.tabuleiro[i][2]] == [marcador, marcador, marcador]:
                return True
            if [self.tabuleiro[0][i], self.tabuleiro[1][i], self.tabuleiro[2][i]] == [marcador, marcador, marcador]:
                return True
        if [self.tabuleiro[0][0], self.tabuleiro[1][1], self.tabuleiro[2][2]] == [marcador, marcador, marcador]:
            return True
        if [self.tabuleiro[0][2], self.tabuleiro[1][1], self.tabuleiro[2][0]] == [marcador, marcador, marcador]:
            return True
        return False
    
    def printa_tabuleiro(self):
        print("--TABULEIRO--")
        for i in range(3):
            for j in range(3):
                if self.tabuleiro[i][j] == "O" or self.tabuleiro[i][j] == "X":
                    print(f"| {self.tabuleiro[i][j]} ", end="")
                else:
                    print(f"|   ", end="")
            print("|")
        print("")
        
    def faz_jogada(self, marcador, jogada):
        linha, coluna = self.mapa_jogadas[jogada]
        self.tabuleiro[linha][coluna] = marcador
from time import sleep
from random import randint

class Jogador:
    def __init__(self, nome: str, marcador: str) -> None:
        self.nome = nome
        self.marcador = marcador
        
tabuleiro = [[1, 2, 3],
             [4, 5, 6],
             [7, 8, 9]]
    
mapa_jogadas = {'1': (0, 0), '2': (0, 1), '3': (0, 2),
                '4': (1, 0), '5': (1, 1), '6': (1, 2),
                '7': (2, 0), '8': (2, 1), '9': (2, 2)}

def pega_jogadas_disponiveis():
    return [str(tabuleiro[i][j]) for i in range(3) for j in range(3) 
            if tabuleiro[i][j] not in ['X', 'O']]
         
def checa_vitoria(marcador):
    for i in range(3):
        if [tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]] == [marcador, marcador, marcador]:
            return True
        if [tabuleiro[0][i], tabuleiro[1][i], tabuleiro[2][i]] == [marcador, marcador, marcador]:
            return True
    if [tabuleiro[0][0], tabuleiro[1][1], tabuleiro[2][2]] == [marcador, marcador, marcador]:
        return True
    if [tabuleiro[0][2], tabuleiro[1][1], tabuleiro[2][0]] == [marcador, marcador, marcador]:
        return True
    return False


def faz_jogada(jogador_atual):
    global tabuleiro
    jogadas_disponiveis = pega_jogadas_disponiveis()
    marcador = jogador_atual.marcador
    marcador_contra = "O" if marcador == "X" else "X"
    
    while True:
        if jogador_atual.nome != "Maquina":
            print(f"Vez do jogador {jogador_atual.nome}")
            jogada = input(f"Jogada: ")
            print("")
        
        else:
            print(f"Vez do jogador {jogador_atual.nome}")
            delay = 1 # 1 segundo de delay
            sleep(delay)
            
            jogada = None
            pontuacao = -2
            for jogada_teste in jogadas_disponiveis:
                linha, coluna = mapa_jogadas[jogada_teste] 
                aux, tabuleiro[linha][coluna] = tabuleiro[linha][coluna], marcador
        
                v = minimax(tabuleiro, marcador_contra)
                print(v)
                if v > pontuacao:
                    pontuacao = v
                    jogada = jogada_teste
                
                tabuleiro[linha][coluna] = aux
            print(f"Jogada: {jogada}\n")
            
        if jogada in list(mapa_jogadas.keys()):
            linha, coluna = mapa_jogadas[jogada]
            
            if tabuleiro[linha][coluna] != 'O' and tabuleiro[linha][coluna] != 'X':
                tabuleiro[linha][coluna] = marcador
                return
            else:
                print("Posição não disponível, repita a jogada.")  
        else:
            print("Jogada invalida, repita a jogada.")  
                     
def printa_tabuleiro():
    print("--TABULEIRO--")
    for i in range(3):
        for j in range(3):
            if tabuleiro[i][j] == "O" or tabuleiro[i][j] == "X":
                print(f"| {tabuleiro[i][j]} ", end="")
            else:
                print(f"|   ", end="")
        print("|")
    print("")
    
def minimax(tabuleiro, marcador):
    marcador_contra = "O" if marcador == "X" else "X"
    jogadas_disponiveis = pega_jogadas_disponiveis()
    
    if len(jogadas_disponiveis) == 0:
        return 0
    elif checa_vitoria(marcador):
        return 1
    elif checa_vitoria(marcador_contra):
        return -1
    
    pontuacao = -2 if marcador == "O" else 2
    
    for jogada in jogadas_disponiveis:
        linha, coluna = mapa_jogadas[jogada] 
        aux, tabuleiro[linha][coluna] = tabuleiro[linha][coluna], marcador
        
        if marcador == "O":
            v = max(pontuacao, minimax(tabuleiro, marcador_contra))
        else:
            v = min(pontuacao, minimax(tabuleiro, marcador_contra))
            
        tabuleiro[linha][coluna] = aux
        
        return v
        
def jogo_velha():
    
    nome_jogador = input("Digite o nome do jogador: ")
    print("")
    
    jogador_1 = Jogador(nome_jogador, 'X')
    jogador_2 = Jogador('Maquina', 'O')
    
    total_jogadas = 9
    condicao_loop = True
    numero_jogadas = 0
    
    while condicao_loop and numero_jogadas < total_jogadas:
        jogador_atual = jogador_1 if numero_jogadas % 2 == 0 else jogador_2
        
        printa_tabuleiro()
        faz_jogada(jogador_atual)
        
        if checa_vitoria(jogador_atual.marcador):
            condicao_loop = False
            print(f"Parabens, jogador {jogador_atual.nome} ganhou!!!")
            printa_tabuleiro()
               
        numero_jogadas += 1
        
    if numero_jogadas == 9 and condicao_loop:
        print("Deu Velha!!!!")
        printa_tabuleiro()
        
if __name__ == "__main__":
    jogo_velha()

    """ tabuleiro = [["X", "X", 3],
                 [  4, "O", 6],
                 [  7,   8, 9]]
    
    tabuleiro = [["X", "X", "O"],
                 ["O", "O", "X"],
                 ["X", "X", "O"]]
    
    v = minimax(tabuleiro, "O")
    print(v) """

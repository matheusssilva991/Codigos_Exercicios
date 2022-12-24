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

def condicoes_checa_iminente(linha, coluna, marcador, marcador_contra, acertos, jogada):
    if tabuleiro[linha][coluna] not in [marcador, marcador_contra]:
        jogada = str(tabuleiro[linha][coluna])
            
    if tabuleiro[linha][coluna] == marcador:
        acertos += 1
                
    if linha == 2 and acertos == 2 and tabuleiro[linha][coluna] == marcador_contra:
        acertos = 0
    
    return jogada, acertos

def checa_iminente(marcador, marcador_contra): 
    for linha in range(3): #Verifica as linhas
        if tabuleiro[linha].count(marcador) == 2 and tabuleiro[linha].count(marcador_contra) == 0:
            jogada = [tabuleiro[linha][coluna] for coluna in range(3) if tabuleiro[linha][coluna] not in [marcador, marcador_contra]] 
            if jogada:
                return str(jogada[0])
          
    for coluna in range(3): #Verifica as colunas
        acertos = 0
        jogada = None
        for linha in range(3):
            jogada, acertos = condicoes_checa_iminente(linha, coluna, marcador, marcador_contra, acertos, jogada)
                           
        if acertos == 2:
            return jogada
    
    acertos = 0
    jogada = None    
    for linha_coluna in range(3): #Verifica diagonal principal
        jogada, acertos = condicoes_checa_iminente(linha_coluna, linha_coluna, marcador, marcador_contra, acertos, jogada)
    
    if acertos == 2:
        return jogada
    
    acertos = 0
    jogada = None
    for linha, coluna in zip(range(3), range(2, -1, -1)): #Verifica diagonal secundaria
        jogada, acertos = condicoes_checa_iminente(linha, coluna, marcador, marcador_contra, acertos, jogada)
            
    if acertos == 2:
        return jogada
    
    return None    
         
def checa_vitoria(marcador, jogada):
    linha, coluna = mapa_jogadas[jogada]
    vitoria_linha = True
    vitoria_coluna = True
    vitoria_diagonal_principal = True
    vitoria_diagonal_secundaria = True
    
    for i, j in zip(range(3), range(2,-1,-1)):
        if tabuleiro[linha][i] != marcador:
            vitoria_linha = False
        if tabuleiro[i][coluna] != marcador:    
            vitoria_coluna = False
        if tabuleiro[i][i] != marcador: 
            vitoria_diagonal_principal = False
        if tabuleiro[i][j] != marcador:
            vitoria_diagonal_secundaria = False
            
    if vitoria_linha or vitoria_coluna or vitoria_diagonal_principal or vitoria_diagonal_secundaria:
        return True
    else:
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
            
            iminente_vitoria = checa_iminente(marcador, marcador_contra)
            iminente_derrota = checa_iminente(marcador_contra, marcador)
            
            if iminente_vitoria is not None:
                jogada = iminente_vitoria
            elif iminente_derrota is not None:
                jogada = iminente_derrota
            else:
                jogada = randint(0, len(jogadas_disponiveis) - 1)
                jogada = jogadas_disponiveis[jogada]
            print(f"Jogada: {jogada}\n")
            
        if jogada in list(mapa_jogadas.keys()):
            linha, coluna = mapa_jogadas[jogada]
            
            if tabuleiro[linha][coluna] != 'O' and tabuleiro[linha][coluna] != 'X':
                tabuleiro[linha][coluna] = marcador
                return jogada
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
    
def minimax(tabuleiro, jogador, jogada):
    marcador = jogador.marcador
    marcador_contra = "O" if marcador == "X" else "X"
    
    if pega_jogadas_disponiveis() == 0:
        return 0
    elif checa_vitoria(marcador, jogada):
        return 1
    elif checa_vitoria(marcador_contra, jogada):
        return -1
    
    melhor_pontuacao = None
    
        
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
        jogada = faz_jogada(jogador_atual)
        
        if checa_vitoria(jogador_atual.marcador, jogada):
            condicao_loop = False
            print(f"Parabens, jogador {jogador_atual.nome} ganhou!!!")
            printa_tabuleiro()
               
        numero_jogadas += 1
        
    if numero_jogadas == 9 and condicao_loop:
        print("Deu Velha!!!!")
        printa_tabuleiro()
        
if __name__ == "__main__":
    jogo_velha()

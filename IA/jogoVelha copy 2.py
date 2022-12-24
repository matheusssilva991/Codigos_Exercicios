from tabuleiro import *
import math
      
def make_best_move(tabuleiro, marcador):
    bestScore = -math.inf
    bestMove = None
    
    for jogada in tabuleiro.pega_jogadas_disponiveis():
        linha, coluna = tabuleiro.mapa_jogadas[jogada]
        tmp = tabuleiro.tabuleiro[linha][coluna]

        tabuleiro.faz_jogada(marcador, jogada) # Faz jogada
        score = minimax(False, marcador, tabuleiro) # Chama o algoritmo min e max
        
        tabuleiro.faz_jogada(tmp, jogada) # Restaura o tabuleiro
        
        if (score > bestScore):
            bestScore = score
            bestMove = jogada
    print(f"Jogada: {bestMove}\n")
    tabuleiro.faz_jogada(marcador, bestMove)
                            
def minimax(isMaxTurn, marcador, tabuleiro):
    marcador_contra = "X" if marcador == 'O' else "X"
    
    if len(tabuleiro.pega_jogadas_disponiveis()) == 0:
        return 0
    elif tabuleiro.checa_vitoria(marcador) and isMaxTurn:
        return 1
    elif tabuleiro.checa_vitoria(marcador_contra) and not isMaxTurn:
        return -1

    scores = []
    for jogada in tabuleiro.pega_jogadas_disponiveis():
        linha, coluna = tabuleiro.mapa_jogadas[jogada]
        tmp = tabuleiro.tabuleiro[linha][coluna]
        
        tabuleiro.faz_jogada(marcador, jogada)
        scores.append(minimax(not isMaxTurn, marcador, tabuleiro))
        
        tabuleiro.faz_jogada(tmp, jogada) # Restaura o tabuleiro

    return max(scores) if isMaxTurn else min(scores)                            
                            
def jogo_velha():
    tabuleiro = Tabuleiro()
    jogador_1 = Jogador("Humano", 'X')
    jogador_2 = Jogador("Maquina", 'O')
    
    total_jogadas = 9
    condicao_loop = True
    numero_jogadas = 0
    
    while condicao_loop and numero_jogadas < total_jogadas:
        jogador_atual = jogador_1 if numero_jogadas % 2 == 0 else jogador_2
        
        tabuleiro.printa_tabuleiro()
        print(f"Vez do jogador {jogador_atual.nome}")
        
        if jogador_atual == jogador_1:
            while True:
                jogadas_disponiveis = tabuleiro.pega_jogadas_disponiveis()
    
                jogada = input(f"Jogada: ")
                print("")
                
                if jogada in jogadas_disponiveis:
                    tabuleiro.faz_jogada(jogador_atual.marcador, jogada)
                    break
                else:
                    print("Posição não disponível, repita a jogada.")            
        else:
            delay = 1 # 1 segundo de delay
            #sleep(delay)
            #jogada = jogadas_disponiveis[randint(0, len(jogadas_disponiveis) - 1)]
            make_best_move(tabuleiro, jogador_atual.marcador)
     
        if tabuleiro.checa_vitoria(jogador_atual.marcador):
            condicao_loop = False
            print(f"Parabens, jogador {jogador_atual.nome} ganhou!!!")
            tabuleiro.printa_tabuleiro()
               
        numero_jogadas += 1
        
    if numero_jogadas == 9 and condicao_loop:
        print("Deu Velha!!!!")
        tabuleiro.printa_tabuleiro()
        
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

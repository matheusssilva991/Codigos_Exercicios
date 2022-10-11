local tabuleiro = {
    {1, 2, 2, 3, 1, 4, 5, 3},
    {3, 7, 7, 2, 2, 4, 4, 7},
    {3, 2, 6, 3, 4, 4, 5, 7},
    {7, 2, 5, 6, 1, 1, 6, 4},
    {7, 1, 4, 6, 6, 4, 5, 6},
    {5, 1, 4, 3, 7, 4, 5, 2},
    {6, 2, 4, 3, 7, 3, 2, 1},
    {1, 3, 2, 3, 4, 4, 5, 7}
}

local function marca_tabuleiro(tabuleiro, direcao, x, y, deslocamento)
    if direcao == 'direita' then
        for i=1,deslocamento do
            tabuleiro[x][y - i] = -1
        end
    elseif direcao == 'baixo' then
        for i=1,deslocamento do
            tabuleiro[x + i][y] = -1
        end
    end
end

local function bejeweled(tabuleiro)
    local direita, baixo
    direita, baixo = 0, 0
    local pontuacao = 0

    local row = #tabuleiro
    local col = #tabuleiro[1]

    for i=1, row do
        for j=1, col do
            if tabuleiro[i][j] ~= -1 then
                while i + baixo < row and tabuleiro[i + baixo][j] == tabuleiro[i][j] do
                    baixo = baixo + 1
                end

                while j + direita < col and tabuleiro[i][j + direita] == tabuleiro[i][j] do
                    direita = direita + 1
                end
        
                --Calcula pontuacao
                if baixo >= 3 then
                    marca_tabuleiro(tabuleiro, "baixo", i, j, baixo - 1)
                    pontuacao = pontuacao + baixo
                end

                if direita >= 3 then
                    marca_tabuleiro(tabuleiro, "direita", i, j, direita)
                    pontuacao = pontuacao + direita
                end

                direita = 0
                baixo = 0
            end
        end
    end

    return pontuacao
end
    
print(bejeweled(tabuleiro))
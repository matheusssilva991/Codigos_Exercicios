math.randomseed(os.time())

local function pedra_papel_tesoura()
    local jogadas_possiveis = {'pedra', 'papel', 'tesoura'}

    local jogada = io.read()
    jogada =  string.lower(jogada)

    local jogada_npc = jogadas_possiveis[math.random(1, 3)]

    if jogada == jogada_npc then
        return "Deu Empate, ambos jogaram " .. jogada
    elseif  jogada == 'pedra' then
        if jogada_npc == 'papel' then
            return 'Computador ganhou, Papel ganha de Pedra'
        else
            return 'Voce ganhou, Pedra ganha de Tesoura'
        end
    elseif  jogada == 'papel' then
        if jogada_npc == 'tesoura' then
            return 'Computador ganhou, Tesoura ganha de Papel'
        else
            return 'Voce ganhou, Papel ganha de Pedra'
        end
    else
        if jogada_npc == 'pedra' then
            return 'Computador ganhou, Pedra ganha de Tesoura'
        else
            return 'Voce ganhou, Tesoura ganha de Papel'
        end
    end
end

print(pedra_papel_tesoura())
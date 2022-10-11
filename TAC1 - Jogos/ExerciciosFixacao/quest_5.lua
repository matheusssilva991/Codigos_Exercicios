math.randomseed(os.time())

local sequencia = {}

for i=1,5 do
    sequencia[i] = math.random(1, 5)
end

local function to_string_seq()
    local seq = '['..sequencia[1] .. ', ' .. sequencia[2] .. ', ' .. sequencia[3] .. ', ' .. sequencia[4] .. ', '..
                sequencia[5] .. ']'
    return seq
end

local function game_Simon(sequence)
    local jogada

    for i=1, #sequence do
        jogada = io.read("*number")

        if jogada ~= sequence[i] then
            return "O Jogador perdeu, a sequencia correta era " .. to_string_seq()
        end
    end 
    
    return "Jogador Ganhou!!!!"
end

print("Trapaca: " .. to_string_seq())
print(game_Simon(sequencia))
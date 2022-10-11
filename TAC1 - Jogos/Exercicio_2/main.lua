LARGURA_TELA, ALTURA_TELA = love.graphics.getDimensions()

function love.load()
    Classe = require "classes/classic"
    Vetor = require "classes/vector"

    require "classes/roda"
    require "classes/personagem"

    roda = Roda()
    personagem = Personagem()
end

function love.update(dt)
    personagem:update(dt)
    roda:update(dt)

    if #roda.pratos > 0 then
        for i, _ in pairs(roda.pratos) do
            if colisao_lingua(personagem, roda.pratos[i]) then
                roda.pratos[i] = nil
            end
        end
    end
end
 
function love.draw()
    personagem:draw()
    roda:draw()
end

function colisao_lingua(A, B)
    if B.posicao.dist(A.posicao_lingua, B.posicao) < (A.raio_lingua + B.raio) then
        return true
    else
        return false
    end   
end
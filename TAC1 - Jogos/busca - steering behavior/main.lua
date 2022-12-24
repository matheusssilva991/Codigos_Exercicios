LARGURA_TELA, ALTURA_TELA = love.graphics.getDimensions()

function love.load()
    Classe = require "classes/classic"
    Vetor = require "classes/vector"

    require "classes/pursuit"
    require "classes/wandering"

    wander = Wandering(1)
    pursuer = Pursuit(1)
end

function love.update(dt)
    mouse = {}
    mouse.posicao = Vetor(love.mouse.getPosition())
    
    wander:update(dt)
    --pursuer:update(dt, mouse)
    pursuer:update(dt, wander)
end

function love.draw()
    wander:draw()
    pursuer:draw()
end


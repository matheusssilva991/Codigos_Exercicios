Personagem = Classe:extend()

function Personagem:new()
    self.img = love.graphics.newImage("recursos/imagens/personagem.png")
    self.posicao = Vetor(LARGURA_TELA / 2, ALTURA_TELA / 2)

    self.velMax = 120

    self.comp_lingua = 0
    self.raio_lingua = 10
    self.is_delay = false
    self.is_press = false
end

function Personagem:update(dt)
    self.mouse = Vetor(love.mouse.getPosition())

    self.direcao = self.mouse - self.posicao

    self.angulo = -self.direcao:heading()

    local p_centro = Vetor(LARGURA_TELA / 2, ALTURA_TELA / 2)
    local p_nova_posicao = self.posicao + self.direcao:limit(self.velMax) * dt

    if (p_nova_posicao.dist(p_nova_posicao, p_centro) < 170) then
        self.posicao = p_nova_posicao
    end
    
    if love.mouse.isDown(1) and not self.is_delay then
        self.is_press = true
    end
    
    if self.is_press and self.comp_lingua < 100 then
        self.comp_lingua = self.comp_lingua + (300 * dt)
    elseif self.comp_lingua >= 100 then
        self.is_delay = true
        self.is_press = false
    end

    if self.is_delay and self.comp_lingua > 0 then
        self.comp_lingua = self.comp_lingua - (300 * dt)
    elseif self.comp_lingua <= 0 then
        self.is_delay = false
        self.comp_lingua = 0
    end

    local x_lingua = self.posicao.x + (self.direcao:norm().x * self.comp_lingua)
    local y_lingua = self.posicao.y + (self.direcao:norm().y * self.comp_lingua)
    self.posicao_lingua = Vetor(x_lingua, y_lingua)
end

function Personagem:draw()
    love.graphics.draw(self.img, self.posicao.x, self.posicao.y, self.angulo)

    love.graphics.setColor(1, 0, 0)
    love.graphics.circle("fill", self.posicao_lingua.x, self.posicao_lingua.y, self.raio_lingua)
    love.graphics.setColor(1, 1, 1)
end
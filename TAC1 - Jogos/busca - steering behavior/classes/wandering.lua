Wandering = Classe:extend()

function Wandering:new(massa)
    self.posicao = Vetor(400, 300)
    self.velocidade = Vetor(50, 50)
    self.vel_desejada = Vetor()
    self.forca_direcao = Vetor()
    self.massa = massa

    self.circ = self.velocidade

    self.angulo = 0
    self.alvo = Vetor()
end

function Wandering:update(dt)
    self.vel_desejada = self.alvo - self.posicao

    self.forca_direcao = self.vel_desejada - self.velocidade
    self.forca_direcao:setmag(20)

    self.velocidade = self.velocidade + self.forca_direcao/self.massa
    self.velocidade:maxMag(80)

    self.posicao = self.posicao + self.velocidade * dt

    self.circ = self.velocidade
    self.circ:setmag(200)
    self.circ = self.circ + self.posicao

    self.angulo = love.math.random(0, 360)
    self.alvo.x = math.sin(self.angulo)
    self.alvo.y = math.cos(self.angulo)

    self.alvo = self.alvo * 50

    self.alvo = self.alvo + self.posicao + self.velocidade

end

function Wandering:draw()
    love.graphics.setColor(0, 1, 0)
    love.graphics.circle("fill", self.posicao.x, self.posicao.y, 5)

    --[[ love.graphics.setColor(1, 1, 1)
    love.graphics.circle("line", self.circ.x, self.circ.y, 50)
    love.graphics.line(self.posicao.x, self.posicao.y, self.circ.x, self.circ.y)

    love.graphics.setColor(1, 0, 0)
    love.graphics.circle("fill", self.alvo.x, self.alvo.y, 5)
    love.graphics.setColor(1, 1, 1) ]]
end
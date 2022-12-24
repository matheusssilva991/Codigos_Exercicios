Pursuit = Classe:extend()

function Pursuit:new(massa)
    self.raio = 10
    self.posicao = Vetor(600, 300)
    self.velocidade = Vetor(60, 60)
    self.vel_desejada = Vetor()
    self.forca_direcao = Vetor()
    self.massa = massa

    self.color = 'RED'
    self.time_to_change = 0
end

function Pursuit:update(dt, fleer)
    self.vel_desejada = (fleer.posicao + fleer.velocidade * dt * 10) - self.posicao

    self.forca_direcao = self.vel_desejada - self.velocidade
    self.forca_direcao:setmag(20)

    self.velocidade = self.velocidade + self.forca_direcao/self.massa
    self.velocidade:maxMag(100)

    self.posicao = self.posicao + self.velocidade * dt

    if self.time_to_change > 0.1 then
        if self.color == 'RED' then
            self.color = 'BLUE'
        else
            self.color = 'RED'
        end

        self.time_to_change = 0
    end
    self.time_to_change = self.time_to_change + dt
end

function Pursuit:draw()
    if self.color == 'RED' then
        love.graphics.setColor(1, 0, 0)
    else
        love.graphics.setColor(0, 0, 1)
    end
    
    love.graphics.circle("fill", self.posicao.x, self.posicao.y, self.raio)
    love.graphics.setColor(0, 0, 0)
end
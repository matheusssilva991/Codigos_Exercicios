Roda = Classe:extend()

function Roda:new()
    self.vel = 20
    self.posicao_roda = Vetor(LARGURA_TELA / 2, ALTURA_TELA / 2)
    self.raio = 250

    self.pratos = {}

    local ang = 0
    --[[ local cores_pratos = {{0, 0, 1}, {0, 1, 0}, {0, 1, 1}, {1, 0, 0}, {1, 0, 1}, {1, 1, 1}} ]] 
    for i=1, 12 do
        self.pratos[i] = {angulo = ang, raio = 15, posicao = Vetor(0, 0)}
        ang = ang + 30
    end

end

function Roda:update(dt)
    if #self.pratos > 0 then
        for i=#self.pratos, 1, -1 do
            self.pratos[i].angulo = self.pratos[i].angulo + self.vel * dt
        
            self.pratos[i].posicao.x =  math.cos(math.rad(self.pratos[i].angulo)) * (self.raio - 25)
            self.pratos[i].posicao.y =  math.sin(math.rad(self.pratos[i].angulo)) * (self.raio - 25)
        
            self.pratos[i].posicao = self.pratos[i].posicao + self.posicao_roda 
        end
    end    
end

function Roda:draw()
    love.graphics.circle("line", self.posicao_roda.x, self.posicao_roda.y, self.raio)
    love.graphics.circle("line", self.posicao_roda.x, self.posicao_roda.y, self.raio - 50)

    love.graphics.setColor(0, 1, 0)
    for i=#self.pratos, 1, -1 do
        if self.pratos[i] ~= nil then
            love.graphics.circle("fill", self.pratos[i].posicao.x, self.pratos[i].posicao.y, self.pratos[i].raio)
        end
    end
    love.graphics.setColor(1, 1, 1)
    
end

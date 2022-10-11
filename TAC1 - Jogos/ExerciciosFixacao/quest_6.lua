local function agario(celula_1, celula_2)
    local distancia_celulas = math.sqrt(((celula_1.x - celula_2.x)^2) + ((celula_1.y - celula_2.y)^2))
    local soma_raios = celula_1.raio + celula_2.raio

    return distancia_celulas <= soma_raios and true or false
end

local celula_1 = {x=1, y=2, raio=3}
local celula_2 = {x=2, y=3, raio=4}

print(agario(celula_1, celula_2))
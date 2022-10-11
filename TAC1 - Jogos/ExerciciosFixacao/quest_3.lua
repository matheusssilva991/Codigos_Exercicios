local function quadratica(a, b, c)
    local delta = b^2 - 4 * a * c

    if delta < 0 then
        return "sem raizes reais para a funcao, delta < 0"
    else
        local x1 = (-b + math.sqrt(delta)) / (2 * a)
        local x2 = (-b - math.sqrt(delta)) / (2 * a)
        return "X1: " .. x1 .."\nX2: " .. x2
    end
end

print(quadratica(4, 2, -6))

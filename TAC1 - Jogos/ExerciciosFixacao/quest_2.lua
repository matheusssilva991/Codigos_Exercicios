local function odd_interval_for(a, b)
    local sum = 0

    print("\nfor")
    for i=a, b do
        if i % 2 ~= 0 then
            sum = sum + i
            print("numero impar: " .. i .. ", soma: " .. sum)
        end
    end
end

local function odd_interval_while(a, b)
    local sum = 0

    print("\nwhile")
    while a < b do
        if a % 2 ~= 0 then
            sum = sum + a
            print("numero impar: " .. a .. ", soma: " .. sum)
        end
        a = a + 1
    end
end

local function odd_interval_repeat(a, b)
    local sum = 0

    print("\nrepeat")
    repeat
        if a % 2 ~= 0 then
            sum = sum + a
            print("numero impar: " .. a .. ", soma: " .. sum)
        end

        a = a + 1
    until a >= b
end

--odd_interval_repeat(1, 100)
--odd_interval_for(1, 100)
odd_interval_while(1, 100)
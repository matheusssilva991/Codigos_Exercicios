path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

tb <- gerar_tdf(m1=201920070,
                m2=201920235,
                m3=201920235)

frequencia <- make.fdt(tb$f, start = 10, end = 100)
frequencia

#Amplitude Total
round((max(frequencia$table$f) - min(frequencia$table$f)), 2)
round(amplitudeTotal(max(frequencia$table$f), max(frequencia$table$rf),
                     max(frequencia$table$`rf(%)`), max(frequencia$table$cf),
                     max(frequencia$table$`cf(%)`),
                     min(frequencia$table$f), min(frequencia$table$rf),
                     min(frequencia$table$`rf(%)`), min(frequencia$table$cf),
                     min(frequencia$table$`cf(%)`)), 2)

# Variancia
round(var(frequencia), 2)

# Desvio padrao
round(sd(frequencia), 2)

# Coeficiente de variacao
round(coeficienteVariacao(frequencia), 2)


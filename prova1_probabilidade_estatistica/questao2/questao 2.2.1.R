path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

tb <- gerar_tdf(m1=201920070,
                m2=201920235,
                m3=201920235)

frequencia <- make.fdt(tb$f, start = 10, end = 100)
frequencia

#-----------TENDENCIA CENTRAL------------------
round((mean(frequencia)), 2) #Media
round(median(frequencia), 2) #Mediana
round(mfv(frequencia), 2) #Moda

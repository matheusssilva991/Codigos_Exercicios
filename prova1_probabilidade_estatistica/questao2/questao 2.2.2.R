path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

tb <- gerar_tdf(m1=201920070,
                m2=201920235,
                m3=201920235)

frequencia <- make.fdt(tb$f, start = 10, end = 100)
frequencia

#-----------POSICAOL------------------
#QUARTIS
quartil <- numeric()
for(n in 1:3)
  quartil[n] <- quantile(frequencia, i=n, probs=seq(0, 1, .25))

names(quartil) <- paste0(c(25, 50, 75), '%')
round(quartil, 2)

#DECIS
decil <- numeric()
for(n in 1:9)
  decil[n] <- quantile(frequencia, i=n, probs=seq(0, 1, .1))

names(decil) <- paste0(c(10, 20, 30, 40, 50, 60, 70, 80, 90), '%')
round(decil, 2)

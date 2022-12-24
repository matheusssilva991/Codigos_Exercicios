path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad <- gerar_dados(m1=201920070,
                   m2=201920235,
                   m3=201920235)

str(dad)

dadSemOutlier <- remove_outlier(dad)

dadFeminino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'F')
dadMasculino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'M')
dadMasculino <- remove_outlier(dadMasculino)
dadFeminino <- remove_outlier(dadFeminino)

### HISTOGRAMA
#----------------------Masculino------------------------------
tabelaMasculina <- fdt(dadMasculino$Y1)

par(mfrow = c(1, 2), oma = c(4, 1, 1, 1))
plot(tabelaMasculina, ylab="Frequência", xlab = "Y1", type="fh")
plot(tabelaMasculina, ylab="Frequência acumulada", xlab="Y1",type="cfp", col="black")

#----------------------Feminino-----------------------------
tabelaFeminina <- fdt(dadFeminino$Y1)

par(mfrow = c(1, 2), oma = c(4, 1, 1, 1))
plot(tabelaFeminina, ylab="Frequência", xlab = "Y1", type="fh")
plot(tabelaFeminina, ylab="Frequência acumulada", xlab="Y1",type="cfp", col="black")


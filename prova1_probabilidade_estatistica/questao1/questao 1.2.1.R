path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad <- gerar_dados(m1=201920070,
                   m2=201920235,
                   m3=201920235)

str(dad)

dadSemOutlier <- remove_outlier(dad)
par(mfrow = c(1, 2), oma = c(4, 1, 1, 1))

dadFeminino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'F')
dadMasculino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'M')

dadMasculino <- remove_outlier(dadMasculino)
dadFeminino <- remove_outlier(dadFeminino)

summary(dadSemOutlier)
tabelaMasculina <- fdt(dadMasculino$Y1)
tabelaMasculina
tabelaFeminina <- fdt(dadFeminino$Y1)
tabelaFeminina

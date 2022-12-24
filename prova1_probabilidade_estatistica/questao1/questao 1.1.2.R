path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad <- gerar_dados(m1=201920070,
                   m2=201920235,
                   m3=201920235)
str(dad)

dadSemOutlier <- remove_outlier(dad)
dadSemOutlier <- remove_outlier(dad)

dadFeminino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'F')
dadMasculino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'M')

dadMasculino <- remove_outlier(dadMasculino)
dadFeminino <- remove_outlier(dadFeminino)

par(mfrow = c(1, 2), oma = c(4, 1, 1, 1))
boxplot(dadMasculino$Y1, dadMasculino$Y2, names=c('Y1', 'Y2'), main='Masculino')
boxplot(dadFeminino$Y1, dadFeminino$Y2, names = c('Y1', 'Y2'), main='Feminino')

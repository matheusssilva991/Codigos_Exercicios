path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad <- gerar_dados(m1=201920070,
                   m2=201920235,
                   m3=201920235)

dadSemOutlier <- remove_outlier(dad)

dadFeminino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'F')
dadMasculino <- subset(dadSemOutlier, dadSemOutlier$Sexo == 'M')
dadMasculino <- remove_outlier(dadMasculino)
dadFeminino <- remove_outlier(dadFeminino)

#Medidas de Posição Masculino
round(quantile(dadMasculino$Y1)[2:4], 2) # quartil masculino
round(quantile(dadMasculino$Y2)[2:4], 2) # quartil masculino
round(quantile(dadMasculino$Y1, p=seq(0, 1, .1))[2:10], 2) # decil masculino
round(quantile(dadMasculino$Y2, p=seq(0, 1, .1))[2:10], 2) # decil masculino

#Medidas de Posição Feminino
round(quantile(dadFeminino$Y1)[2:4], 2)  # quartil feminino
round(quantile(dadFeminino$Y2)[2:4], 2)  # quartil feminino
round(quantile(dadFeminino$Y1, p=seq(0, 1, .1))[2:10], 2)  # decil feminino
round(quantile(dadFeminino$Y2, p=seq(0, 1, .1))[2:10],2 )  # decil feminino

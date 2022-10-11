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

#----------Medidas de Dispersão - Masculino----------
#amplitude total
round(max(dadMasculino$Y1) - min(dadMasculino$Y1), 2)
round(max(dadMasculino$Y2) - min(dadMasculino$Y2), 2)

#variancia
round(var(dadMasculino$Y1), 2)
round(var(dadMasculino$Y2), 2)

#desvio padrao
round(sd(dadMasculino$Y1), 2)
round(sd(dadMasculino$Y2), 2)

#coeficiente de variacao
CVmacho1 <- coeficienteVariacao(dadMasculino$Y1)
CVmacho2 <- coeficienteVariacao(dadMasculino$Y2)
round(CVmacho1, 2)
round(CVmacho2, 2)

#----------Medidas de Dispersão - Feminino----------
#amplitude total
round(max(dadFeminino$Y1) - min(dadFeminino$Y1), 2)
round(max(dadFeminino$Y2) - min(dadFeminino$Y2), 2)

#variancia
round(var(dadFeminino$Y1), 2)
round(var(dadFeminino$Y2), 2)

#desvio padrao
round(sd(dadFeminino$Y1), 2)
round(sd(dadFeminino$Y2), 2)

#coeficiente de variacao
CVfemea1 <- coeficienteVariacao(dadFeminino$Y1)
CVfemea2 <- coeficienteVariacao(dadFeminino$Y2)
round(CVfemea1, 2)
round(CVfemea2, 2)

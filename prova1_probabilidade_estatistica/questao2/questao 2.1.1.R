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

#Tendencia central Masculina
mediaM1 <- round(mean(dadMasculino$Y1), 2)
mediaM2 <- round(mean(dadMasculino$Y2), 2)
medianaM1 <- round(median(dadMasculino$Y1), 2)
medianaM2 <- round(median(dadMasculino$Y2), 2)
modaM1 <- round(mfv(dadMasculino$Y1), 2)
modaM2 <- round(mfv(dadMasculino$Y2), 2)

col1masculino <- c(length(dadMasculino$Y1), length(dadMasculino$Y2))
col2masculino <- c(mediaM1, mediaM2)
col3masculino <- c(medianaM1, medianaM2)
col4masculino <- c(modaM1, modaM2)
df_masc <- data.frame(col1masculino, col2masculino, col3masculino,col4masculino,
                      row.names = c("Y1", "Y2"))
colnames(df_masc) <- c("n", "m", "md", "mo")
df_masc

#Tendencia central Feminina
mediaF1 <- round(mean(dadFeminino$Y1), 2)
mediaF2 <- round(mean(dadFeminino$Y2), 2)
medianaF1 <- round(median(dadFeminino$Y1), 2)
medianaF2 <- round(median(dadFeminino$Y2), 2)
modaF1 <- round(mfv(dadFeminino$Y1), 2)
modaF2 <- round(mfv(dadFeminino$Y2), 2)

col1feminino <- c(length(dadFeminino$Y1), length(dadFeminino$Y2))
col2feminino <- c(mediaF1, mediaF2)
col3feminino <- c(medianaF1, medianaF2)
col4feminino <- c(modaF1, modaF2)
df_fem <- data.frame(col1feminino, col2feminino, col3feminino, col4feminino,
                      row.names = c("Y1", "Y2"))
colnames(df_fem) <- c("n", "m", "md", "mo")
df_fem

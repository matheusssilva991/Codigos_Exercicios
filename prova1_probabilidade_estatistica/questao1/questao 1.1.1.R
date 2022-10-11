path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad <- gerar_dados(m1=201920070,
                   m2=201920235,
                   m3=201920235)
str(dad)

dadSemOutlier <- remove_outlier(dad)
dadSemOutlier <- remove_outlier(dad)

par(mfrow = c(1, 2), oma = c(4, 1, 1, 1))
boxplot(dad$Y1, dad$Y2, names=c('Y1', 'Y2'), main='Antes')
boxplot(dadSemOutlier$Y1, dadSemOutlier$Y2, names=c('Y1', 'Y2'), main='Após')


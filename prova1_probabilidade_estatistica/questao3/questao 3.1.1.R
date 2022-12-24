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

#DataFrames de Covariança
df_cov_masculina <- make_df_cov(dadMasculino)
df_cov_masculina
df_cov_feminino <- make_df_cov(dadFeminino)
df_cov_feminino

#DataFrames de Correlação
df_cor_masculina <- make_df_cor(dadMasculino)
df_cor_masculina
df_cor_feminino <- make_df_cor(dadFeminino)
df_cor_feminino

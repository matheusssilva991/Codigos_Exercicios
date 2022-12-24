path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad_rl <- gerar_dados_rl(m1=201920070, 
                         m2=201920235, 
                         m3=201920235)

dad_rl # DataFrame

# x e y para realizar operacoes com funcoes
x = dad_rl$X
y = dad_rl$Y

# Polinomio de grau 1
funcaoAfim = lm(y ~ x)
summary(funcaoAfim)
tabelaFuncaoAfim = summary(funcaoAfim)$coefficients
round(tabelaFuncaoAfim, 2)

# Polinomio de grau 2
funcaoQuadratica = lm(y ~ x + I(x^2))
summary(funcaoQuadratica)
tabelaFuncaoQuadratica = summary(funcaoQuadratica)$coefficients
round(tabelaFuncaoQuadratica, 2)

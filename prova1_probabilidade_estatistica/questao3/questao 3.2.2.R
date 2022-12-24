path = paste(getwd(),"/funcoesProva.R", sep="")
source(path)

dad_rl <- gerar_dados_rl(m1=201920070, 
                         m2=201920235, 
                         m3=201920235)

# x e y para realizar operacoes com funcoes
x = dad_rl$X
y = dad_rl$Y

df = data.frame(X = x, y = y)
write.csv(df, "dados.csv", row.names = FALSE)

par(mfrow = c(1, 2), oma = c(4, 1, 1, 1)) # Dois plot, uma tela
# >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
eixoX_afim = cbind(1, x)
eixoX_quadratico = cbind(1, x, x^2)
# >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
eixoY = cbind(y)

# Parte da funcao Afim >>>>>>>>>>>>
X_linha_vezes_X_afim = t(eixoX_afim) %*% eixoX_afim
X_linha_vezes_X_inverso_afim = solve(X_linha_vezes_X_afim)
X_linha_vezes_Y_afim = t(eixoX_afim) %*% eixoY
beta_estimado_afim = X_linha_vezes_X_inverso_afim %*% X_linha_vezes_Y_afim
Y_estimado_afim =  eixoX_afim %*% beta_estimado_afim
resultado_afim = eixoY - Y_estimado_afim

# Parte da funcaoquadratica >>>>>>>
X_linha_vezes_X_quadratico = t(eixoX_quadratico) %*% eixoX_quadratico
X_linha_vezes_X_inverso_quadratico = solve(X_linha_vezes_X_quadratico)
X_linha_vezes_Y_quadratico = t(eixoX_quadratico) %*% eixoY
beta_estimado_quadratico = X_linha_vezes_X_inverso_quadratico %*% X_linha_vezes_Y_quadratico
Y_estimado_quadratico =  eixoX_quadratico %*% beta_estimado_quadratico
resultado_quadratico = eixoY - Y_estimado_quadratico

# A
plot(y ~ x, pch = 20, xlim = c(0, 10), ylim = c(0, 14), col = "blue",
     xlab = "x", ylab = "y", main = "A: Polinomio de I grau")
text(3, 13.7, expression(hat(Y) == 1.2245 + 1.3191*X), cex = 1)
text(1.5, 12, expression(r^2 == 0.9888), cex = 1)

lines(spline(Y_estimado_afim ~ x, n = 1e3), col = 'red')

# B
plot(y ~ x, pch = 20, xlim = c(0, 10), ylim = c(0, 14), col = "blue",
     xlab = "x", ylab = "y", main = "B: Polinomio de II grau")
text(3.6, 13.7, expression(hat(Y) == 1.1410 + 2.0734*X - 0.0958*X^2), cex = 0.8)
text(1.5, 12, expression(r^2 == 0.9959), cex = 1)
lines(spline(Y_estimado_quadratico ~ x, n = 1e3), col = 'red')


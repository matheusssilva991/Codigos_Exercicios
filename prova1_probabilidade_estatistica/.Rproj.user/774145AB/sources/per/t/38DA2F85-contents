library(fdth)
require(fdth)
library(ggplot2)
require(ggplot2)
library(memisc)
require(memisc)

#. Fun??o: gerar_dados
gerar_dados <- function(m1=NULL,m2=NULL,m3=NULL,n=2e3)
{
  stopifnot(is.numeric(m1) & is.numeric(m2) &is.numeric(m3))
  
  set.seed(m1 + m2 +m3)
  
  m_1 <- runif(1,min=20,max=40)
  m_2 <- runif(1,min=20,max=40)
  
  ## Categ?rica
  n_cat_1 <- n/10 * sample(4:8,1)
  
  ## Matriz de vari?ncias e covari?ncias
  sigma_1 <- matrix(c(m_1,m_1 / 1.1,m_1 / 1.1,m_2),ncol=2)
  
  sigma_2 <- matrix(c(m_1,-1 * (m_2 / 1.2),-1 * (m_2 / 1.2),m_2),ncol=2)
  
  require(Matrix) # S4
  near_1 <- nearPD(sigma_1)
  near_2 <- nearPD(sigma_2)
  sigma_1 <- matrix(near_1[['mat']]@x,nc=ncol(sigma_1))
  sigma_2 <- matrix(near_2[['mat']]@x,nc=ncol(sigma_2))
  
  ## Escala proporcional
  require(mvtnorm)
  v_pro_1 <- round(rmvnorm(n=n_cat_1,mean=c(m_1,m_2),sigma=sigma_1),2)
  
  v_pro_2 <- round(rmvnorm(n=(n - n_cat_1),mean=c(m_1,m_2),sigma=sigma_2),2)
  
  ## Escala categ?rica
  cat_1 <- rep('M',n_cat_1)
  cat_2 <- rep('F',n - n_cat_1)
  
  v_pro <- c('v_pro_1','v_pro_2')
  v_cat <- c('cat_1','cat_2')
  
  ord <- sample(1:2,2)
  sexo <- c(eval(parse(text=v_cat[ord[1]])),eval(parse(text=v_cat[ord[2]])))
  
  ## Frame de dados
  res <- as.data.frame(rbind(eval(parse(text=v_pro[ord[1]])),
                             eval(parse(text=v_pro[ord[2]]))))
  
  res <- cbind(res,sexo)
  
  colnames(res) <- c('Y1','Y2','Sexo')
  
  ## Outlier v_pro_1
  n_out_v1 <- sample(10:20,1)
  
  out_v1 <- sample(1:length(res[, 1]),n_out_v1)
  res[, 1][out_v1] <- sample(730:999,n_out_v1)
  
  ## Outlier v_pro_2
  n_out_v2 <- sample(10:30,1)
  out_v2 <- sample(1:length(res[, 2]),n_out_v2)
  res[, 2][out_v2] <- sample(200:300,n_out_v2)
  
  ## NAs
  res[, 1][sample(1:n, sample(10:20, 1))] <- NA
  res[, 2][sample(1:n, sample(10:20, 1))] <- NA
  res[, 3][sample(1:n, sample(10:20, 1))] <- NA
  
  ## Negativos
  res[, 1][sample(1:n, sample(10:20, 1))] <- -999
  res[, 2][sample(1:n, sample(10:20, 1))] <- -999
  
  invisible(res)
}

remove_outlier <- function(x, type=2)
{
  ## Remover NAs
  x <- na.omit(x)
  
  while(1) 
  {
    ## Quartis
    q.t <- quantile(x$Y1,type=type)[2:4]
    q.r <- quantile(x$Y2,type=type)[2:4]
    
    ## Dist?ncias interquart?licas - iqr
    iqr.t <- q.t[3] - q.t[1]
    iqr.r <- q.r[3] - q.r[1]
    
    ## Identifica??o de outliers
    out <- subset(x,Y1 >= q.t[3] + 1.5 * iqr.t |
                    Y1 <= q.t[1] - 1.5 * iqr.t |
                    Y1 < 0 |
                    Y2 >= q.r[3] + 1.5 * iqr.r |
                    Y2 <= q.r[1] - 1.5 * iqr.r | Y2 < 0)
    
    ## Condi??o de sa?da
    if (dim(out)[1] == 0)
      return(x)
    
    ## Remo??o de outliers
    x <- subset(x,Y1 < q.t[3] + 1.5 * iqr.t &
                  Y1 > q.t[1] - 1.5 * iqr.t &
                  Y1 >= 0 & Y2 < q.r[3] + 1.5 * iqr.r &
                  Y2 > q.r[1] - 1.5 * iqr.r & Y2 >= 0)
  }
}

gerar_tdf <- function(m1=NULL,m2=NULL,m3=NULL)
{
  stopifnot(is.numeric(m1) & is.numeric(m2) & is.numeric(m3))
  
  set.seed(sum(m1,m2,m3))
  
  classes <- c("[10, 020)","[20, 030)","[30, 040)","[40, 050)","[50, 060)",
               "[60, 070)","[70, 080)","[80, 090)","[90, 100)")
  
  X <- c(seq(f=10,t=50, b=10),seq(f=40,t=10, b=-10))
  Y <- sample(1:3,length(X),rep=T)
  f <- (X - Y)
  rf <- round(f / sum(f),2)
  rfp <- round(100 * (f / sum(f)),2)
  cf <- round(cumsum(f),2)
  cfp <- round(100 * cumsum(f / sum(f)),2)
  res <- data.frame(classes,f,rf,rfp,cf,cfp)
  names(res) <- c('Classes','f','rf','rf(%)','cf','cf(%)')
  invisible(res)
}

#Faz os dataframes de covariança
make_df_cov <- function(df){
  row1 <- c(round(cov(df$Y1, df$Y1), 2), round(cov(df$Y1, df$Y2), 2))
  row2 <- c(round(cov(df$Y1, df$Y2), 2),round(cov(df$Y2, df$Y2), 2))
  
  df_cov <- data.frame(row1, row2, row.names=c("Y1", "Y2"))
  colnames(df_cov) <- c("Y1", "Y2")
  
  return (df_cov)
}

make_df_cor <- function(df){
  row1 <- c(round(cor(df$Y1, df$Y1), 2), round(cor(df$Y1, df$Y2), 2))
  row2 <- c(round(cor(df$Y1, df$Y2), 2),round(cor(df$Y2, df$Y2), 2))
  
  df_cor <- data.frame(row1, row2, row.names=c("Y1", "Y2"))
  colnames(df_cor) <- c("Y1", "Y2")
  
  return (df_cor)
}

#cavariancia
coeficienteVariacao <- function(dado) {
  raizDaVariancia <- sd(dado)
  mediaDoVetor <- mean(dado)
  cv <- (raizDaVariancia / mediaDoVetor)
  return(cv * 100)
}

#AmplitutdeTotal
amplitudeTotal <- function(max1, max2, max3, max4, max5,
                           min1, min2, min3, min4, min5) {
  amplitude1 <- max1 - min1
  amplitude2 <- max2 - min2
  amplitude3 <- max3 - min3
  amplitude4 <- max4 - min4
  amplitude5 <- max5 - min5
  
  amplitude <- amplitude1 + amplitude2 + amplitude3 + amplitude4 + amplitude5
  
  return(amplitude / 5)
}

gerar_dados_rl <- function(m1=NULL, m2=NULL, m3=NULL, n=10) {
  stopifnot(is.numeric(m1) & is.numeric(m2) & is.numeric(m3))
  
  set.seed(sum(m1, m2, m3))
  
  X <- seq(0, 10, length=n)
  Y <- 1 + 2*X + -.08*X^2 + rnorm(n)
  
  res <- data.frame(X, Y)
  
  invisible(res)
}
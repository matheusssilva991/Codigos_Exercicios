import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

path_image = "D:\mathe\Documents\Meus Codes\Python\CG\lenna.png"

img_lenna = Image.open(path_image) #Carrega a imagem
array_lenna = np.asarray(img_lenna) # Transforma a imagem em uma matriz numpy

R, G, B = array_lenna[:, :, 0], array_lenna[:, :, 1], array_lenna[:, :, 2] #Pega os níveis RGB
img_gray = 0.2989 * R + 0.5870 * G + 0.1140 * B # Faz a conversão para níveis de cinza
img_gray = img_gray.astype(np.uint8) #Faz downcasting do tipo para unsigned int de 8 bits

width, height = array_lenna.shape[:2] #Pega as dimensões da imagem

#Cria arrays numpy de zeros
histograma_original = np.zeros((256))
histograma_segmentado = np.zeros((256))
histograma_equalizado = np.zeros((256))

#criar imagem segmentada
mean = img_gray.mean()
img_gray_segmentada = img_gray.copy()
mask_black = img_gray_segmentada <= mean
mask_white = img_gray_segmentada > mean
img_gray_segmentada[mask_black] = 0
img_gray_segmentada[mask_white] = 255

#Gera o histograma original e segmentado
for i in range(width):
  for j in range(height):
    histograma_original[img_gray[i, j]] += 1
    histograma_segmentado[img_gray_segmentada[i, j]] += 1

#Criar imagem equalizada
histograma_prob = histograma_original / (width * height)
acum_sum = histograma_prob.cumsum()
new_values = np.ceil(acum_sum * 255)
img_gray_equalizada = new_values[img_gray]
img_gray_equalizada = img_gray_equalizada.astype('uint8')

#Gera o histograma equalizado
for i in range(width):
  for j in range(height):
    histograma_equalizado[img_gray_equalizada[i, j]] += 1
        
#Variaveis auxiliares para plotagem
histogramas = [histograma_original, histograma_segmentado, histograma_equalizado]
i_subplot = [1, 2, 3]
titles = ['Original', 'Segmentada', "Equalizada"]
imagens = [img_gray, img_gray_segmentada, img_gray_equalizada]

#grafico dos Histogramas
fig1 = plt.figure(figsize=(16, 10))
for histograma, i, title in zip(histogramas, i_subplot, titles):
  plt.subplot(2, 2, i)
  plt.title(f"Histograma {title}", size=12)
  plt.xlabel("Nivel de Cinza")
  plt.ylabel("Amostragem")
  plt.xlim([0, 256])
  plt.plot(histograma)

#Imagens
fig2 = plt.figure(figsize=(16, 10))
for imagem, i, title in zip(imagens, i_subplot, titles):
  plt.subplot(2, 2, i)
  plt.title(f"Imagem {title}")
  plt.imshow(imagem, cmap='gray')
plt.show()

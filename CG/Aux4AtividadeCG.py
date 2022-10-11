from OpenGL.GL import GL_QUADS, GL_TRIANGLES

r = 150.0

#PirâmideCoordenadas
basePyramid = [(-r, r, 0), (-r, -r, 0), (r, -r, 0), (r, r, 0)]
face1Pyramid = [(-r, -r, 0), (0, 0, -r), (r, -r, 0)]
face2Pyramid = [(-r, r, 0), (0, 0, -r), (r, r, 0)]
face3Pyramid = [(-r, -r, 0), (0, 0, -r), (-r, r, 0)]
face4Pyramid = [(r, -r, 0), (0, 0, -r), (r, r, 0)]

#CuboCoordenadas
faceCube0 = [(-r, r, r), (-r, -r, r), (r, -r, r), (r, r, r)] #frente
faceCube1 = [(r, r, r), (r, -r, r), (r, -r, -r), (r, r, -r)] # direita
faceCube2 = [(r, r, -r), (-r, r, -r), (-r, -r, -r), (r, -r, -r)] #tras
faceCube3 = [(-r, r, r), (-r, r, -r), (-r, -r, -r), (-r, -r, r)] #esquerda
faceCube4 = [(-r, r, r), (r, r, r), (r, r, -r), (-r, r, -r)] #cima
faceCube5 = [(-r, -r, r), (-r, -r, -r), (r, -r, -r), (r, -r, r)] #baixo

coords = [basePyramid, face1Pyramid, face2Pyramid, face3Pyramid, face4Pyramid]
shapes = [GL_QUADS, GL_TRIANGLES, GL_TRIANGLES, GL_TRIANGLES, GL_TRIANGLES]
colors = [(0, 1, 1), (1, 0, 1), (0, 1, 0), (1, 0, 0), (0, 0, 1)]

rotateX = 0
rotateY = 0
rotateZ = 0
moveX = 0
moveY = 0


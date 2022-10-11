import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from random import randint

class CountAxis:
    def __init__(self):
        self.__count_x = 0
        self.__count_y = 0
        self.__count_z = 0
        
    def get_count_x(self):
        return self.__count_x
    
    def get_count_y(self):
        return self.__count_y
    
    def get_count_z(self):
        return self.__count_z
        
    def set_count(self, count_x=False, count_y=False, count_z=False):
        if count_x:
            self.__count_x += 1
            if self.__count_x == 6:
                self.__count_x = 0
        if count_y:
            self.__count_y += 1
            if self.__count_y == 6:
                self.__count_y = 0
        if count_z:
            self.__count_z += 1
            if self.__count_z == 6:
                self.__count_z = 0


r = 2.5
faceCube0 = [(-r, r, r), (-r, -r, r), (r, -r, r), (r, r, r)]  # frente
faceCube1 = [(r, r, r), (r, -r, r), (r, -r, -r), (r, r, -r)]  # direita
faceCube2 = [(r, r, -r), (-r, r, -r), (-r, -r, -r), (r, -r, -r)]  # tras
faceCube3 = [(-r, r, r), (-r, r, -r), (-r, -r, -r), (-r, -r, r)]  # esquerda
faceCube4 = [(-r, r, r), (r, r, r), (r, r, -r), (-r, r, -r)]  # cima
faceCube5 = [(-r, -r, r), (-r, -r, -r), (r, -r, -r), (r, -r, r)]  # baixo

colors = [(0, 1, 1), (1, 0, 1), (0, 1, 0), (1, 0, 0), (0, 0, 1), (1, 1, 0)]
faces = [faceCube0, faceCube1, faceCube2, faceCube3, faceCube4, faceCube5]
textureCoordinates = ((0, 0), (0, 1), (1, 1), (1, 0))

def cubo(face):
    glColor3f(1, 1, 1)
    glBegin(GL_QUADS)

    for i, vertice in enumerate(face):
        glTexCoord2fv(textureCoordinates[i])
        glVertex3f(vertice[0], vertice[1], vertice[2])
    glEnd()


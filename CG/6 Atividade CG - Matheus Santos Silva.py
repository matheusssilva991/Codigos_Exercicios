import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import numpy as np

r = 150.0
faceCube0 = [(-r, r, r), (-r, -r, r), (r, -r, r), (r, r, r)] #frente
faceCube1 = [(r, r, r), (r, -r, r), (r, -r, -r), (r, r, -r)] # direita
faceCube2 = [(r, r, -r), (-r, r, -r), (-r, -r, -r), (r, -r, -r)] #tras
faceCube3 = [(-r, r, r), (-r, r, -r), (-r, -r, -r), (-r, -r, r)] #esquerda
faceCube4 = [(-r, r, r), (r, r, r), (r, r, -r), (-r, r, -r)] #cima
faceCube5 = [(-r, -r, r), (-r, -r, -r), (r, -r, -r), (r, -r, r)] #baixo

shapes = [GL_QUADS, GL_QUADS, GL_QUADS, GL_QUADS, GL_QUADS, GL_QUADS]
colors = [(0, 1, 1), (1, 0, 1), (0, 1, 0), (1, 0, 0), (0, 0, 1), (1, 1, 0)]
coords = [faceCube0, faceCube1, faceCube2, faceCube3, faceCube4, faceCube5] 

def matriz_transformacao(translacao, scala, rotacao, theta):
    d = (translacao[0], translacao[1], translacao[2])
    s = (scala[0], scala[1], scala[2])
    r = (rotacao[0], rotacao[1], rotacao[2])
    m = np.array([[s[0], 0, 0, 0],
                   [0, s[1], 0, 0],
                   [0, 0, s[2], 0],
                   [d[0], d[1], d[2], 1]
                   ], dtype=np.float16)
    
    mx = np.eye(4, dtype=np.float16)
    my = np.eye(4, dtype=np.float16)
    mz = np.eye(4, dtype=np.float16)
    
    if(r[0]):
        mx[1][1] = np.cos(np.radians(-theta))
        mx[1][2] = -np.sin(np.radians(-theta))
        mx[2][1] = np.sin(np.radians(-theta))
        mx[2][2] = np.cos(np.radians(-theta))
    m = mx.dot(m)    
    if(r[1]):
        my[0][0] = np.cos(np.radians(-theta))
        my[0][2] = np.sin(np.radians(-theta))
        my[2][0] = -np.sin(np.radians(-theta))
        my[2][2] = np.cos(np.radians(-theta))
    m = my.dot(m)    
    if(r[2]):
        m[0][0] = np.cos(np.radians(-theta))
        m[0][1] = -np.sin(np.radians(-theta))
        m[1][0] = np.sin(np.radians(-theta))
        m[1][1] = np.cos(np.radians(-theta))
    m = mz.dot(m)    
        
    return m   
    
def make_primitive(shape, coords, colors):
    glColor3f(colors[0], colors[1], colors[2])
    glBegin(shape)
    for x, y, z in coords:
        glVertex3f(x, y, z)
    glEnd()

def iterate():
    glViewport(0, 0, 500, 500)
    glClearDepth(1.0)
    glEnable(GL_DEPTH_TEST)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(45.0, float(500)/float(500), 0.1, 500.0)
    glOrtho(0, 500.0, 0, 500.0, 0, 500)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()

def showScreen():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    iterate()
    glLoadIdentity()
    
    m = matriz_transformacao([250, 250, 250], [0.5, 0.5, 0.5], [1, 0, 0], 30)
    glLoadMatrixf(m)
    
    for shape, coord, color in zip(shapes, coords, colors):
        make_primitive(shape, coord, color)
    glutSwapBuffers()
    
def main():
    global window
    glutInit()
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH)
    glutInitWindowSize(500, 500)  # ajusta o tamanho da janela
    glutInitWindowPosition(550, 150)
    window = glutCreateWindow("Piramide e Cubo")  # função para criar janela
    glutDisplayFunc(showScreen)  # Associa o display ao evento showScreen
    glutIdleFunc(showScreen)
    
    glutMainLoop()

main()
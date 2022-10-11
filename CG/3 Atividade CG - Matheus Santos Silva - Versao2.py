import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

params_triangle = [(-125.0, -125.0), (0, 125.0), (125.0, -125.0)]
params_line = [(0.0, 250.0), (500.0, 250.0), (250.0, 0.0), (250.0, 500.0)]
colors = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]

escala = 0.3
number_iter = 1
moveX = 115
moveY = 10
rotate = 0

def make_triangle(params):
    glBegin(GL_TRIANGLES)
    for i in range(3):
        glColor3f(colors[i][0], colors[i][1], colors[i][2])
        glVertex2f(params[i][0], params[i][1])
    glEnd()
    
def make_line(params):
    glColor3f(1, 1, 1)
    glBegin(GL_LINES)
    for x, y in params:
       glVertex2f(x, y) 
    glEnd()

def iterate():
    glViewport(0, 0, 500, 500)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0, 500.0, 0, 500.0, -1.0, 1.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()

def showScreen():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    iterate()
    glColor3f(1.0, 0.0, 3.0)
    make_line(params_line)  # linhas dos eixos

    #Triangulo central
    glScaled(0.5, 0.5, 0)
    glTranslated(500, 500, 0)
    make_triangle(params_triangle)
    
    #Triangulo cima
    glLoadIdentity()
    glTranslated(250, 375 + moveY, 0)
    glScaled(escala, escala, 0)
    glRotated(180, 0, 0, 1)
    make_triangle(params_triangle)
        
    #Triangulo esquerdo
    glLoadIdentity()
    glTranslated(125, 250, 0)
    glScaled(escala, escala, 0)
    glRotated(-90, 0, 0, 1)
    make_triangle(params_triangle)
        
    #Triangulo direito
    glLoadIdentity()
    glTranslated(375 + moveY, 250, 0)
    glScaled(escala, escala, 0)
    glRotated(90, 0, 0, 1)
    make_triangle(params_triangle)
        
    #Triangulo baixo
    glLoadIdentity()
    glTranslated(250, 125, 0)
    glScaled(escala, escala, 0)
    
    for i in range(number_iter): 
        make_triangle(params_triangle)
        glTranslated(moveX, moveY, 0)
        glRotated(rotate, 0, 0, 1)
    glutSwapBuffers() 

def keyboardPress(*args):
    global escala
    global number_iter
    global moveX
    global rotate
    global moveY

    if (args[0] == b'\x1b'):
        glutDestroyWindow(window)
    elif (args[0] == b'w'): 
        number_iter += 1
        if number_iter % 24 == 0:
            escala *= 0.85
            moveX *= 1.19
            moveY *= 1.10
        rotate = 16
    elif (args[0] == b's'):
        number_iter -= 1
        if number_iter % 24 == 0:
            escala /= 0.85
            moveX /= 1.19
            moveY /= 1.10
        rotate = -16

def specialKeysPress(*args):
    print("specialKeysPress :", args)

def mouseClick(*args):
    print("mouseClick", args)

def mousePassive(*args):
    print("mousePassive", args)

def main():
    global window
    glutInit()
    glutInitDisplayMode(GLUT_RGBA)
    glutInitWindowSize(500, 500)  # ajusta o tamanho da janela
    glutInitWindowPosition(550, 150)
    window = glutCreateWindow("Triangulos")  # função para criar janela
    glutDisplayFunc(showScreen)  # Associa o display ao evento showScreen
    glutIdleFunc(showScreen)

    glutKeyboardFunc(keyboardPress)
    glutSpecialFunc(specialKeysPress)

    glutMouseFunc(mouseClick)
    glutPassiveMotionFunc(mousePassive)

    glutMainLoop()

main()

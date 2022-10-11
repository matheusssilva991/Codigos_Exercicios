import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

params_triangle = [(125.0, 125.0), (250.0, 375.0), (375.0, 125.0)]
params_line = [(0.0, 250.0), (500.0, 250.0), (250.0, 0.0), (250.0, 500.0)]
colors = [(1, 0, 0), (0, 1, 0), (0, 0, 1)]

escala = 1
number_iter = 1
move_aux = 50
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
    glTranslated(250, 250, 0)
    make_triangle(params_triangle)
    
    glLoadIdentity()
    glTranslated(250, 250, 0)
    glScaled(escala, escala, 0)
    
    params_left = [(-156.25 - move_aux, -31.75), (-156.25 - move_aux, 31.75), (-93.75 - move_aux, 0.0)]
    params_up = [(-31.75, 156.25 + move_aux), (0.0, 93.75 + move_aux), (31.75, 156.25 + move_aux)]
    params_right = [(156.25 + move_aux, 31.75), (93.75 + move_aux, 0), (156.25 + move_aux, -31.75)]
    params_down = [(-31.75, -156.75 - move_aux), (0, -93.75 - move_aux), (31.75, -156.75 - move_aux)]
    
    for i in range(number_iter):
        make_triangle(params_left)
        make_triangle(params_up)
        make_triangle(params_right)
        make_triangle(params_down)
        glRotated(rotate, 0, 0, 1)
    glutSwapBuffers() 

def keyboardPress(*args):
    global move
    global escala
    global number_iter
    global move_aux
    global rotate

    if (args[0] == b'\x1b'):
        glutDestroyWindow(window)
    elif (args[0] == b'w'): 
        number_iter += 1
        if number_iter % 24 == 0:
            escala *= 0.85
            move_aux *= 1.22
        rotate = 8
    elif (args[0] == b's'):
        number_iter -= 1
        if number_iter % 24 == 0:
            escala /= 0.85
            move_aux /=  1.22
        rotate = -8

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

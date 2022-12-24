import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from Aux4AtividadeCG import *

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
    glScalef(0.5, 0.5, 0.5)
    glTranslated(500, 500, 500)
    glRotated(rotateX, 1, 0, 0) 
    glRotated(rotateY, 0, 1, 0)
    glRotated(rotateZ, 0, 0, 1)
    
    for shape, coord, color in zip(shapes, coords, colors):
        make_primitive(shape, coord, color)
    glutSwapBuffers()
    
def keyboardPress(*args):
    global rotateX
    global rotateY
    global rotateZ
    global shapes
    global colors
    global coords

    if (args[0] == b'\x1b'):
        glutDestroyWindow(window)
    elif(args[0] == b'w'):
        rotateX += 5
    elif(args[0] == b's'):
        rotateX -= 5
    elif(args[0] == b'a'):
        rotateY += 5
    elif(args[0] == b'd'):
        rotateY -= 5
    elif(args[0] == b'q'):
        rotateZ += 5
    elif(args[0] == b'e'):
        rotateZ -= 5
    elif(args[0] == b'c'):
        shapes = [GL_QUADS, GL_QUADS, GL_QUADS, GL_QUADS, GL_QUADS, GL_QUADS]
        colors = [(0, 1, 1), (1, 0, 1), (0, 1, 0), (1, 0, 0), (0, 0, 1), (1, 1, 0)]
        coords = [faceCube0, faceCube1, faceCube2, faceCube3, faceCube4, faceCube5]   
    elif(args[0] == b't'):
        shapes = [GL_QUADS, GL_TRIANGLES, GL_TRIANGLES, GL_TRIANGLES, GL_TRIANGLES]
        colors = [(0, 1, 1), (1, 0, 1), (0, 1, 0), (1, 0, 0), (0, 0, 1)]
        coords = [basePyramid, face1Pyramid, face2Pyramid, face3Pyramid, face4Pyramid]    

def specialKeysPress(*args):
    print("specialKeysPress :", args)

def mouseClick(*args):
    print("mouseClick", args)

def mousePassive(*args):
    print("mousePassive", args)

def main():
    global window
    glutInit()
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH)
    glutInitWindowSize(500, 500)  # ajusta o tamanho da janela
    glutInitWindowPosition(550, 150)
    window = glutCreateWindow("Piramide e Cubo")  # função para criar janela
    glutDisplayFunc(showScreen)  # Associa o display ao evento showScreen
    glutIdleFunc(showScreen)

    glutKeyboardFunc(keyboardPress)
    glutSpecialFunc(specialKeysPress)

    glutMouseFunc(mouseClick)
    glutPassiveMotionFunc(mousePassive)
    glutMainLoop()

main()
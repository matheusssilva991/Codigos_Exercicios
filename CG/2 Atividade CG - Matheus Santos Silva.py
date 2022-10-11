import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

# Pontos para formar as primitivas
params_line = [(0.0, 250.0), (500.0, 250.0), (250.0, 0.0), (250.0, 500.0)]
params_line_strip = [(125.0, 125.0), (187.5, 375.0),
                     (250.0, 125.0), (312.5, 375.0), (375.0, 125.0)]
params_line_loop = [(125.0, 125.0), (187.5, 375.0),
                    (250.0, 125.0), (312.5, 375.0), (375.0, 125.0)]
params_triangle = [(125.0, 125.0), (250.0, 375.0), (375.0, 125.0)]
params_quads = [(125.0, 125.0), (125.0, 375.0), (375.0, 375.0), (375.0, 125.0)]
params_polygon = [(125.0, 250.0), (156.25, 312.5), (187.5, 375.5), (312.5, 375.5), (343.75, 312.5), (375.0, 250.0),
                  (343.75, 187.5), (312.5, 125.0), (187.5, 125.0), (156.25, 187.5)]
params_triangle_strip = [(125.0, 375.0), (208.33, 125.0),
                         (291.66, 375.0), (375.0, 125.0)]
params_triangle_fan = [(250, 250), (187.5, 375.0), (125, 187.5),
                       (281.25, 125.0), (375, 250.0), (312.5, 375.0)]
params_quads_strip = [(125, 281.25), (125, 218.75), (187.5, 281.25), (187.5, 218.75), (312.5, 312.5), (312.5, 187.5),
                      (375.0, 281.25), (375.0, 218.75)]


def make_primitive(shape, params):
    glColor3f(0, 0, 0)
    glBegin(shape)

    for x, y in params:
        glVertex2f(x, y)
    glEnd()

    for x, y in params:
        point(x, y)

def point(x, y):
    glColor3f(1, 0, 0)  # define cor do desenho
    glPointSize(7.0)
    glBegin(GL_POINTS)
    glVertex2f(x, y)
    glEnd()

def iterate():
    glViewport(0, 0, 500, 500)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(0.0, 500, 0.0, 500, 0.0, 1.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()

def showScreen():
    glClearColor(1, 1, 1, 0)  # função para escolher cor da tela quando limpar
    # função pintar o fundo da tela
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    iterate()
    #point(250, 250),
    #make_primitive(GL_LINES, params_line),
    #make_primitive(GL_LINE_STRIP, params_line_strip),
    #make_primitive(GL_LINE_LOOP, params_line_loop),
    #make_primitive(GL_TRIANGLES, params_triangle),
    #make_primitive(GL_QUADS, params_quads),
    #make_primitive(GL_POLYGON, params_polygon),
    #make_primitive(GL_TRIANGLE_STRIP, params_triangle_strip),
    make_primitive(GL_TRIANGLE_FAN, params_triangle_fan),
    #make_primitive(GL_QUAD_STRIP, params_quads_strip)
    glutSwapBuffers()

glutInit()
glutInitDisplayMode(GLUT_RGBA)
glutInitWindowSize(500, 500)  # ajusta o tamanho da janela
glutInitWindowPosition(0, 0)
wind = glutCreateWindow("Teste OpenGL")  # função para criar janela
glutDisplayFunc(showScreen)  # Associa o display ao evento showScreen
glutIdleFunc(showScreen)
glutMainLoop()

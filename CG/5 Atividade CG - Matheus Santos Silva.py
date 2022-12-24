import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import numpy as np
  
def triangle():
    glBegin( GL_TRIANGLES )
    glColor3f(1.0, 0.0, 0.0)
    glVertex2f( -100.0, -100.0)
    glColor3f(0.0, 1.0, 0.0)
    glVertex2f( 100.0, -100.0)
    glColor3f(0.0, 0.0, 1.0)
    glVertex2f( 0.0, 100.0)
    glEnd()
    
def translated1(dx, dy, dz):
    m = np.eye(4, dtype=np.float16)
    d = (dx, dy, dz)
    
    for i in range(3):
        m[3][i] = d[i]
    return m

def scaled1(sx, sy, sz):
    m = np.eye(4, dtype=np.float16)
    s = (sx, sy, sz)
    
    for i in range(3):
        m[i][i] = s[i]
    return m
 
def rotated1(theta, rx, ry, rz):
    m = np.eye(4, dtype=np.float16)
    
    if(rx):
        m[1][1] = np.cos(np.radians(-theta))
        m[1][2] = -np.sin(np.radians(-theta))
        m[2][1] = np.sin(np.radians(-theta))
        m[2][2] = np.cos(np.radians(-theta))
        return m
    if(ry):
        m[0][0] = np.cos(np.radians(-theta))
        m[0][2] = np.sin(np.radians(-theta))
        m[2][0] = -np.sin(np.radians(-theta))
        m[2][2] = np.cos(np.radians(-theta))
        return m
    if(rz):
        m[0][0] = np.cos(np.radians(-theta))
        m[0][1] = -np.sin(np.radians(-theta))
        m[1][0] = np.sin(np.radians(-theta))
        m[1][1] = np.cos(np.radians(-theta))
        return m
    
def eixoXY():
    glColor3f(1.0, 1.0, 1.0)
    glBegin( GL_LINES )
    glVertex2f(-200,0)
    glVertex2f(200,0)
    glEnd()
    glBegin( GL_LINES )
    glVertex2f(0,-200)
    glVertex2f( 0,200)
    glEnd()

def iterate():
    glViewport(0, 0, 400, 400)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(-200.0, 200, -200.0, 200, 0.0, 1.0)
    glMatrixMode (GL_MODELVIEW)
    glLoadIdentity()
    
def showScreen():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    iterate()
    eixoXY()
    triangle()
    
    #Matriz de Transformação - ESCALA
    m = scaled1(0.5, 0.5, 0)
    
    #Matriz de Transformação - TRANSLAÇÂO
    m = m.dot(translated1(100, 100, 0))
    
    #Matriz de Transformação - ROTAÇÂO
    m = m.dot(rotated1(30, 0, 0, 1))  
    glLoadMatrixf(m)
    triangle()
    
    glutSwapBuffers()

glutInit()
glutInitDisplayMode(GLUT_RGBA)
glutInitWindowSize(400, 400)
glutInitWindowPosition(-200, -200)
wind = glutCreateWindow("Matrizes de Transformacao")
glutDisplayFunc(showScreen)
glutIdleFunc(showScreen)
glutMainLoop()


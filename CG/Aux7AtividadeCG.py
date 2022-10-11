import OpenGL
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *

rotateX = 0
rotateY = 0
rotateZ = 0
count = 0

def make_line(params):
    glColor3f(1, 1, 1)
    glBegin(GL_LINES)
    for x, y, z in params:
       glVertex3f(x, y, z) 
    glEnd()

def teapot():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glutWireTeapot(60)
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-200.0, -200.0, 0.0)
    glutSolidTeapot(60)

def sphere():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glutWireSphere(80, 50, 50)
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-200.0, -200.0, 0.0)
    glutSolidSphere(80, 50, 50)
    
def cube():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glutWireCube(80)
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-200.0, -200.0, 0.0)
    glutSolidCube(80)
    
def cone():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glutWireCone(50, 100, 10, 20)
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-200.0, -200.0, 0.0)
    glutSolidCone(50, 100, 10, 20)
    
def torus():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glutWireTorus(10, 70, 10, 20)
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-200.0, -200.0, 0.0)
    glutSolidTorus(10, 70, 10, 20)

def dodecahedron():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glScaled(50,50,50)
    glutWireDodecahedron()
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-4.0, -4.0, 0.0)
    glutSolidDodecahedron()
    
def octahedron():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glScaled(60,60,60)
    glutWireOctahedron()
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-3.0, -3.0, 0.0)
    glutSolidOctahedron()
    
def tetrahedron():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glScaled(70,70,70)
    glutWireTetrahedron()
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-3.0, -3.0, 0.0)
    glutSolidTetrahedron()
    
def icosahedron():
    glColor3f(0.0, 1.0, 0.0)
    glTranslated(100.0, 100.0, 0.0)
    glScaled(70,70,70)
    glutWireIcosahedron()
    
    glColor3f(1.0, 0.0, 0.0)
    glTranslated(-3.0, -3.0, 0.0)
    glutSolidIcosahedron()
    
def objects_file(shape, name_object):
    number_vertices = 0
    global vertices
    
    glColor3f(1.0, 1.0, 0.0)
    glBegin(shape)
    
    with open(name_object, 'r') as file:
    
        #Pega a quantidade de vertices na primeira linha e faz o tratamento
        number_vertices = file.readline()
        number_vertices = int(number_vertices.replace("\n", "").replace("Vertices: ", ""))
        
        for i in range(number_vertices):
            
            vertices = file.readline()
            vertices = vertices.replace("\n", "").split("     ")
            #glVertex3d(float(vertices[0]) * 60, float(vertices[1]) * 60, float(vertices[2]) * 60)
            glVertex3d(float(vertices[0]), float(vertices[1]), float(vertices[2]))
    glEnd()
    
objects = [sphere, cube, cone, torus, dodecahedron, octahedron, tetrahedron, icosahedron, teapot]



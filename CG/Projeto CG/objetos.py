from OpenGL.GLU import *
from OpenGL.GL import *

def chao():
    glColor3d(1, 1, 1)
    glBegin(GL_QUADS)
    glTexCoord2f(0, 0)
    glVertex3d(-5, -10, 0)
    glTexCoord2f(0, 1)
    glVertex3d(-5, 10, 0)
    glTexCoord2f(1, 1)
    glVertex3d(5, 10, 0)
    glTexCoord2f(1, 0)
    glVertex3d(5, -10, 0)
    glEnd()
    
def left_grass():
    glColor3d(1, 1, 1)
    glBegin(GL_QUADS)
    glTexCoord2f(0, 0)
    glVertex3d(-10, -10, 0)
    glTexCoord2f(0, 1)
    glVertex3d(-10, 10, 0)
    glTexCoord2f(1, 1)
    glVertex3d(-5, 10, 0)
    glTexCoord2f(1, 0)
    glVertex3d(-5, -10, 0)
    glEnd()
    
def right_grass():
    glColor3d(1, 1, 1)
    glBegin(GL_QUADS)
    glTexCoord2f(0, 0)
    glVertex3d(10, -10, 0)
    glTexCoord2f(0, 1)
    glVertex3d(10, 10, 0)
    glTexCoord2f(1, 1)
    glVertex3d(5, 10, 0)
    glTexCoord2f(1, 0)
    glVertex3d(5, -10, 0)
    glEnd()
  
def carArea():
    glColor3d(1, 1, 1)
    glBegin(GL_QUADS)
    glVertex3d(-1, -2, 0)
    glVertex3d(-1, 2, 0)
    glVertex3d(1, 2, 0)
    glVertex3d(1, -2, 0)
    glEnd() 

def line():
    glColor3d(1, 0, 0)
    glBegin(GL_POINTS)
    glVertex3d(0, 0, 0)
    #glVertex3d(1, 2, 0)
    glEnd()


def load_tex(tex_id, datas, images):
    glBindTexture(GL_TEXTURE_2D, tex_id)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, images.get_width(), images.get_height(), 0, GL_RGBA, 
                GL_UNSIGNED_BYTE, datas)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
    
    glEnable(GL_TEXTURE_2D)	
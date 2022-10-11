from cube import *
import pygame
from pygame.locals import *

width = 800
height = 600
angulo = 60
delay_time = 150
loop_condition = True
count_axis = CountAxis()
count = 0

def set_ligthing():
    glLight(GL_LIGHT0, GL_POSITION,  (0, 0, 1, 0))
    glLight(GL_LIGHT0, GL_POSITION,  (5, 5, 5, 1))
    glLightfv(GL_LIGHT0, GL_AMBIENT, (1, 1, 1, 1))
    glLightfv(GL_LIGHT0, GL_DIFFUSE, (1, 1, 1, 1))
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glEnable(GL_COLOR_MATERIAL)
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)
    
def disable_ligthing():
    glDisable(GL_LIGHT0)
    glDisable(GL_LIGHTING)
    glDisable(GL_COLOR_MATERIAL)
    
def inicialize():
    pygame.init()
    display = (width, height)
    pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
    # clock = pygame.time.Clock()
    
    glMatrixMode(GL_PROJECTION)
    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
    glMatrixMode(GL_MODELVIEW)
    glEnable(GL_DEPTH_TEST)
    
def set_event():
    global loop_condition, delay_time, count
    for event in pygame.event.get():
            if event.type == pygame.QUIT:
                loop_condition = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_w:
                    if delay_time > 50:
                        delay_time -= 25
                elif event.key == pygame.K_s:
                    if delay_time < 250:
                        delay_time += 25
                elif event.key == pygame.K_r:
                    count = 0
                    
def axis_rotated():
    global count, count_axis

    axis = randint(1, 7)

    if axis == 1:
        count_axis.set_count(count_z=True)
    elif axis == 2:
        count_axis.set_count(count_y=True)
    elif axis == 3:
        count_axis.set_count(count_y=True, count_z=True)
    elif axis == 4:
        count_axis.set_count(count_x=True)
    elif axis == 5:
        count_axis.set_count(count_x=True, count_z=True)
    elif axis == 6:
        count_axis.set_count(count_x=True, count_y=True)
    elif axis == 7:
        count_axis.set_count(count_x=True, count_y=True, count_z=True)

    count += 1

def main():
    inicialize()
    
    images = [pygame.image.load(f'facesDado/face{i}.png') for i in range(1, 7)]
    datas = [pygame.image.tostring(images[i], 'RGBA') for i in range(6)]
    tex_id = glGenTextures(6, [1, 2, 3, 4, 5, 6])

    while loop_condition:
        global angulo, count, delay_time
        set_event()  
                                       
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        set_ligthing()

        if count < 30:
            axis_rotated()
        
        glLoadIdentity()
        glTranslatef(0, 0, -20)
        glRotated(angulo * count_axis.get_count_x(), 1, 0, 0)
        glRotated(angulo * count_axis.get_count_y(), 0, 1, 0)
        glRotated(angulo * count_axis.get_count_z(), 0, 0, 1)

        for i in range(6):    
            glBindTexture(GL_TEXTURE_2D, tex_id[i])
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, images[i].get_width(), images[i].get_height(), 0, GL_RGBA, 
                         GL_UNSIGNED_BYTE, datas[i])
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
    
            glEnable(GL_TEXTURE_2D)
        
            cubo(faces[i])

        disable_ligthing()

        pygame.display.flip()
        pygame.event.pump()
        pygame.time.delay(delay_time)
        # clock.tick(20)


main()


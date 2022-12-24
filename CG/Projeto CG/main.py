import random
import sys
from loader import *
from pygame.locals import *
from pygame.constants import *
from objetos import *

viewport = (800,600)
width = viewport[0]/2
height = viewport[1]/2
display = None
title = "Jogo do Carrinho"

def colision(car_position_x, car_position_y, enemy_position_x, enemy_position_y):
    width_car = 2
    height_car = 4
    
    if enemy_position_y - height_car > car_position_y:
        return False
    elif enemy_position_x + width_car <= car_position_x or car_position_x + width_car <= enemy_position_x: 
        return False
    else:
        return True
       
def initialize():
    global display
    pygame.init()
    display = pygame.display.set_mode(viewport, OPENGL | DOUBLEBUF)
    pygame.display.set_caption(title)
    
    glLightfv(GL_LIGHT0, GL_POSITION,  (-40, 200, 100, 0.0))
    glLightfv(GL_LIGHT0, GL_AMBIENT, (0.6, 0.6, 0.6, 1.0))
    glLightfv(GL_LIGHT0, GL_DIFFUSE, (0.5, 0.5, 0.5, 1.0))
    glEnable(GL_LIGHT0)
    glEnable(GL_LIGHTING)
    glEnable(GL_COLOR_MATERIAL)
    glEnable(GL_DEPTH_TEST)
    glShadeModel(GL_SMOOTH)

def event():
    global tx_car, ty_car
    for event in pygame.event.get():
        if event.type == QUIT:
            sys.exit()
        elif event.type == KEYDOWN and event.key == K_ESCAPE:
            sys.exit()
        elif event.type == KEYDOWN:
            if event.key == pygame.K_a:
                if tx_car > -3:
                    tx_car -= 3
            elif event.key == pygame.K_d:
                if tx_car < 3:
                    tx_car += 3
                  
def main():
    initialize()

    imagesNames = ['images/rua.png', 'images/grass.jpg']
    #Carrega os carros
    obj = OBJ('Car.obj', swapyz=True)
    enemyObj = OBJ('enemyCar.obj', swapyz=True)
    images = [pygame.image.load(image) for image in imagesNames]
    datas = [pygame.image.tostring(images[i], 'RGBA') for i in range(len(images))]
    tex_id = glGenTextures(2, [0, 1])
    clock = pygame.time.Clock()

    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(-10, 10, -10, 10, -10, 10)
    glEnable(GL_DEPTH_TEST)
    glMatrixMode(GL_MODELVIEW)

    global tx_car, ty_car
    tx_car, ty_car = (0,-8)
    tx_enemy, ty_enemy = (0, 8)
    positions = [-3, 0, 3]
    zpos = 5

    while 1:
        clock.tick(60)
        event()
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    
        #Chão
        glLoadIdentity()
        glTranslate(0, 0, - zpos)
        load_tex(tex_id[0], datas[0], images[0])
        chao()
        load_tex(tex_id[1], datas[1], images[1])
        left_grass()
        right_grass()
        
        # Carro principal
        glLoadIdentity()
        glTranslate(tx_car, ty_car,0)
        glScaled(0.7, 0.7, 0.7)
        glCallList(obj.gl_list)
        
        #Carro inimigo
        glLoadIdentity()
        
        ty_enemy -= 0.3
        if ty_enemy < -10:
            ty_enemy = 8
            tx_enemy = positions[random.randint(0, 2)]

        glTranslate(tx_enemy, ty_enemy, - zpos)
        glRotate(180, 0, 0, 1)
        glScaled(0.7, 0.7, 0.7)
        glCallList(enemyObj.gl_list) 
        
        if colision(tx_car - 1, -7, tx_enemy - 1, ty_enemy + 2):
            pygame.time.wait(3000)
            sys.exit()
        
        pygame.display.flip()
        
main()
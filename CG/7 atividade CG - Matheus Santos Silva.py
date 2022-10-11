from Aux7AtividadeCG import *
    
def iterate():
    glViewport(0, 0, 500, 500)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    glOrtho(-300.0, 300.0, -300.0, 300.0, -300.0, 300.0)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    
def inicializa():
    glClearColor(0.0, 0.0, 0.0, 0.0)
    glEnable(GL_COLOR_MATERIAL)
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glEnable(GL_DEPTH_TEST)
    glShadeModel(GL_SMOOTH)

def iluminacao():
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, [0,1.0,1.0,1.0])
    glMateriali(GL_FRONT_AND_BACK,GL_SHININESS, 40)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, [0.2,0.2,0.2,1.0])
    glLightfv(GL_LIGHT0, GL_AMBIENT, [0.2,0.2,0.2,1.0])

def showScreen():
    inicializa()
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    iluminacao()
    glLoadIdentity()
    iterate()
    glLoadIdentity()
    glRotated(rotateX, 1, 0, 0) 
    glRotated(rotateY, 0, 1, 0)
    glRotated(rotateZ, 0, 0, 1)
    
    # ------OBJETOS A PARTIR DA FUNÇÂO PRIMITIVA------
    #objects[count]()
    
    # ------OBJETOS A PARTIR DO ARQUIVO------
    glTranslated(0, -100, 0)
    glScaled(60,60,60)
    
    #objects_file(GL_TRIANGLE_FAN, "Sphere.txt") #Solid
    #objects_file(GL_TRIANGLES, "Sphere.txt") #Wireframe
    
    #objects_file(GL_TRIANGLE_STRIP, "Torus.txt") 
    
    #objects_file(GL_LINE_LOOP, "Tube.txt")
    #objects_file(GL_TRIANGLES, "Tube.txt")
    #------FIM OBJETOS A PARTIR DO ARQUIVO------
    glutSwapBuffers()   

def keyboardPress(*args):
    global rotateX
    global rotateY
    global rotateZ

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
    elif(args[0] == b'r'):
        rotateZ = 0
        rotateY = 0
        rotateX = 0

def specialKeysPress(*args):
    global count
    
    if(args[0] == 100):
        count -= 1  
        if(count == -1):
            count = 8
    elif(args[0] == 102):
        count += 1
        if(count == 9):
            count = 0
            
def main():
    global window
    glutInit()
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH)
    glutInitWindowSize(500, 500)  # ajusta o tamanho da janela
    glutInitWindowPosition(550, 150)
    window = glutCreateWindow("Objetos 3D")  # função para criar janela
    glutDisplayFunc(showScreen)  # Associa o display ao evento showScreen
    glutIdleFunc(showScreen)

    glutKeyboardFunc(keyboardPress)
    glutSpecialFunc(specialKeysPress)
    
    glutMainLoop()

main()
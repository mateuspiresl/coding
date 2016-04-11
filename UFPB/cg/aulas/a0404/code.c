/* gcc -o file file.c -lglut -lGL -lGLU */
/* gcc -g code.c -lopengl32 -lglu32 -lfreeglut */

#include <GL/glut.h>
#include <stdio.h>

void display();
void keyEventHandler(unsigned char key, int x, int y);
void drawCube();

int moveHor = 0;
int moveVer = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);

	int windowID = glutCreateWindow("OPENGL");

    glutKeyboardFunc(keyEventHandler);
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}

void keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':   moveVer = 1;
                    break;
        case 's':   moveVer = -1;
                    break;
        case 'a':   moveHor = -1;
                    break;
        case 'd':   moveHor = 1;
                    break;
	}
    
    printf("%d %d\n", moveHor, moveVer);

    glutPostRedisplay();
} 

void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);

	// Matriz de modeling - permite translação
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -50);
    
    glScaled(10, 10, 0);

    drawCube(0, 0, 0);

	glPopMatrix();
	glRotated(moveHor * 10, 0, 1, 0);
    glRotated(moveVer * 10, 1, 0, 0);
	glPushMatrix();

    drawCube(0, 0, 0);

    // Reset movement
    moveHor = 0;
    moveVer = 0;

	glFlush();
}

void drawCube()
{
    // Lado branco - FRENTE
    glBegin(GL_POLYGON);
        glColor3d(   1.0,  0.0, 0.0 );
        glVertex3d(  0.5, -0.5, -0.5 );
        glVertex3d(  0.5,  0.5, -0.5 );
        glVertex3d( -0.5,  0.5, -0.5 );
        glVertex3d( -0.5, -0.5, -0.5 );
    glEnd();

    // Lado branco - TRASEIRA
    glBegin(GL_POLYGON);
        glColor3d(   0.0,  1.0, 0.0 );
        glVertex3d(  0.5, -0.5, 0.5 );
        glVertex3d(  0.5,  0.5, 0.5 );
        glVertex3d( -0.5,  0.5, 0.5 );
        glVertex3d( -0.5, -0.5, 0.5 );
    glEnd();

    // Lado roxo - DIREITA
    glBegin(GL_POLYGON);
        glColor3d(  0.0,  0.0,  1.0 );
        glVertex3d( 0.5, -0.5, -0.5 );
        glVertex3d( 0.5,  0.5, -0.5 );
        glVertex3d( 0.5,  0.5,  0.5 );
        glVertex3d( 0.5, -0.5,  0.5 );
    glEnd();

    // Lado verde - ESQUERDA
    glBegin(GL_POLYGON);
        glColor3d(   1.0,  1.0,  0.0 );
        glVertex3d( -0.5, -0.5,  0.5 );
        glVertex3d( -0.5,  0.5,  0.5 );
        glVertex3d( -0.5,  0.5, -0.5 );
        glVertex3d( -0.5, -0.5, -0.5 );
    glEnd();

    // Lado azul - TOPO
    glBegin(GL_POLYGON);
        glColor3d(   0.0,  1.0,  1.0 );
        glVertex3d(  0.5,  0.5,  0.5 );
        glVertex3d(  0.5,  0.5, -0.5 );
        glVertex3d( -0.5,  0.5, -0.5 );
        glVertex3d( -0.5,  0.5,  0.5 );
    glEnd();

    // Lado vermelho - BASE
    glBegin(GL_POLYGON);
        glColor3d(   1.0,  0.0,  1.0 );
        glVertex3d(  0.5, -0.5, -0.5 );
        glVertex3d(  0.5, -0.5,  0.5 );
        glVertex3d( -0.5, -0.5,  0.5 );
        glVertex3d( -0.5, -0.5, -0.5 );
    glEnd();
}



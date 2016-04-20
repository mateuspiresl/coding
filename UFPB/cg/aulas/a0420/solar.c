/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STARS 300

void display();
void keyEventHandler(unsigned char key, int x, int y);
void gameLoop();
void list();
void displayPesp(int p);
void drawCube();

int p = 0;
int d = 0;
int rotX = 0;
int rands[STARS];

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	int window1 = glutCreateWindow("OPENGL");
	glutInitWindowPosition(0, 0);
	glutKeyboardFunc(keyEventHandler);
	glutDisplayFunc(display);
	glutIdleFunc(gameLoop);

	list();

	glutMainLoop();

	return 0;
}

void keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		/*case 'a':   rotX--;
					break;
		case 'd':   rotX++;
					break;*/
		case 'p':	p = ! p;
					break;
		case 'd':	d = ! d;
	}

	glutPostRedisplay();
}

void list()
{
	glNewList(1, GL_COMPILE);
		drawCube(50);
	glEndList();
}

void displayPesp(int p)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (p) glFrustum(-25, 25, -25, 25, 50, 200);
	else glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (p) glTranslated(0, 0, -100);
	else glTranslated(0, 0, -50);
}

void display()
{
	glDrawBuffer(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Janela 1

	glViewport(0, 0, 300, 600);
	displayPesp(p);

	glCallList(1);
	
	// Janela 2

	glViewport(300, 0, 300, 600);
	displayPesp( ! p);

	glCallList(1);

	glutSwapBuffers();
}

clock_t last = 0;

void gameLoop()
{
	if (clock() - last < 16) return;

	last = clock();
	rotX++;

	glutPostRedisplay();
}

void drawCube(int scale)
{
    // Lado branco - FRENTE
    glBegin(GL_POLYGON);
        glColor3d(   1.0,  0.0, 0.0 );
        glVertex3d(  0.5 * scale, -0.5 * scale, -0.5 * scale );
        glVertex3d(  0.5 * scale,  0.5 * scale, -0.5 * scale );
        glVertex3d( -0.5 * scale,  0.5 * scale, -0.5 * scale );
        glVertex3d( -0.5 * scale, -0.5 * scale, -0.5 * scale );
    glEnd();

    // Lado branco - TRASEIRA
    glBegin(GL_POLYGON);
        glColor3d(   0.0,  1.0, 0.0 );
        glVertex3d(  0.5 * scale, -0.5 * scale, 0.5 * scale );
        glVertex3d(  0.5 * scale,  0.5 * scale, 0.5 * scale );
        glVertex3d( -0.5 * scale,  0.5 * scale, 0.5 * scale );
        glVertex3d( -0.5 * scale, -0.5 * scale, 0.5 * scale );
    glEnd();

    // Lado roxo - DIREITA
    glBegin(GL_POLYGON);
        glColor3d(  0.0,  0.0,  1.0 );
        glVertex3d( 0.5 * scale, -0.5 * scale, -0.5 * scale );
        glVertex3d( 0.5 * scale,  0.5 * scale, -0.5 * scale );
        glVertex3d( 0.5 * scale,  0.5 * scale,  0.5 * scale );
        glVertex3d( 0.5 * scale, -0.5 * scale,  0.5 * scale );
    glEnd();

    // Lado verde - ESQUERDA
    glBegin(GL_POLYGON);
        glColor3d(   1.0,  1.0,  0.0 );
        glVertex3d( -0.5 * scale, -0.5 * scale,  0.5 * scale );
        glVertex3d( -0.5 * scale,  0.5 * scale,  0.5 * scale );
        glVertex3d( -0.5 * scale,  0.5 * scale, -0.5 * scale );
        glVertex3d( -0.5 * scale, -0.5 * scale, -0.5 * scale );
    glEnd();

    // Lado azul - TOPO
    glBegin(GL_POLYGON);
        glColor3d(   0.0,  1.0,  1.0 );
        glVertex3d(  0.5 * scale,  0.5 * scale,  0.5 * scale );
        glVertex3d(  0.5 * scale,  0.5 * scale, -0.5 * scale );
        glVertex3d( -0.5 * scale,  0.5 * scale, -0.5 * scale );
        glVertex3d( -0.5 * scale,  0.5 * scale,  0.5 * scale );
    glEnd();

    // Lado vermelho - BASE
    glBegin(GL_POLYGON);
        glColor3d(   1.0,  0.0,  1.0 );
        glVertex3d(  0.5 * scale, -0.5 * scale, -0.5 * scale );
        glVertex3d(  0.5 * scale, -0.5 * scale,  0.5 * scale );
        glVertex3d( -0.5 * scale, -0.5 * scale,  0.5 * scale );
        glVertex3d( -0.5 * scale, -0.5 * scale, -0.5 * scale );
    glEnd();
}
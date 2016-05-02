/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "help.h"

void keyEventHandler(unsigned char key, int x, int y);
void reshape();
void display();
void display_init();
void setLight();
void userRotation();

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

int rotX = 0;
int rotY = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OPENGL");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyEventHandler);

	glutMainLoop();

	return 0;
}

void keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':   rotY--;
					break;
		case 's':   rotY++;
					break;
		case 'a':   rotX--;
					break;
		case 'd':   rotX++;
					break;
	}

	glutPostRedisplay();
}

/* Define as matrizes de projeção e modelview. */
void reshape()
{
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-25.0, 25.0, -25.0, 25.0, 50.0, 200.0);
	
	glMatrixMode(GL_MODELVIEW);
}

/* Função de desenho. */
void display()
{
	display_init();
	setLight();

	// Simula altura do observador
	//glRotated(15, 1, 0, 0);
	//glTranslated(0, -20, 0);

	glPushMatrix();
		glTranslated(-28, 0, 0);
		userRotation();
		glutSolidTeapot(15);
	glPopMatrix();

	glPushMatrix();
		glTranslated(28, 0, 0);
		userRotation();
		glutSolidTeapot(15);
	glPopMatrix();

	glutSwapBuffers();
}

void display_init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslated(0, 0, -150);
}

/* Inicializa a iluminação */
void setLight()
{
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, nvf4(1.0, 1.0, 1.0, 1.0));
	glMaterialfv(GL_FRONT, GL_SHININESS, nvf1(50.0));	
	
	glLightfv(GL_LIGHT0, GL_POSITION, nvf4(1.0, 1.0, 1.0, 0.0));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, nvf4(0.1, 0.1, 0.1, 1.0));
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void userRotation() {
	glRotated(rotX, 0, 1, 0);
	glRotated(-rotY, 1, 0, 0);
}
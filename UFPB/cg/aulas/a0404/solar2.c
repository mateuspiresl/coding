/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STARS 300

void display();
void keyEventHandler(unsigned char key, int x, int y);
void gameLoop();

int p = 0;
int rotX = 0;
int rands[STARS];

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);

	int windowID = glutCreateWindow("OPENGL");

	glutKeyboardFunc(keyEventHandler);
	glutDisplayFunc(display);
	glutIdleFunc(gameLoop);

	srand(time(NULL));
	int i;
	for (i = 0; i < STARS; i++)
		rands[i] = (rand() % 110) - 55;

	glutMainLoop();

	return 0;
}

void keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'a':   rotX--;
					break;
		case 'd':   rotX++;
					break;
		case 'p':	p = ! p;
	}
	
	printf("%d\n", rotX);

	glutPostRedisplay();
} 

void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (p) glFrustum(-1.0, 1.0, -1.0, 1.0, 1, 200.0);
	else glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);
	//glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);
	//gluPerspective(65, 1, 20, 10);
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1, 200.0);

	// Matriz de modeling - permite translação
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -50);
	//if (p) glTranslated(0, 0, -50);
	//else glTranslated(0, 0, -50);

	// Stars
	glPushMatrix();
		glRotated(rotX * 0.02, 1, 0, 0);
		glRotated(rotX * 0.04, 0, 1, 0);
		glRotated(rotX * 0.06, 0, 0, 1);

		glBegin(GL_POINTS);
			int i;
			for (i = 0; i < STARS; i += 3)
				glVertex3d(rands[i], rands[i + 1], rands[i + 2]);
		glEnd();
	glPopMatrix();

	// Sun
	glPushMatrix();
		glRotated(rotX * 0.1, 1, 0, 0);
		glRotated(rotX * 0.2, 0, 1, 0);
		glRotated(rotX * 0.3, 0, 0, 1);
		glColor3d(1, 0.8, 0);
		glutWireSphere(10, 28, 16);
	glPopMatrix();

	
	glRotated(rotX * 0.001, 1, 0, 0);
	glRotated(rotX * 0.002, 0, 1, 0);
	glRotated(rotX * 0.003, 0, 0, 1);

	glColor3d(0, 0.2, 0.6);
	
	glRotated(rotX, 0, 1, 0);

	glTranslated(30, 0, 0);
	glRotated(rotX * 0.03, 1, 0, 0);
	glRotated(rotX * 0.04, 0, 1, 0);
	glRotated(rotX * 0.05, 0, 0, 1);
	glutWireSphere(4, 20, 10);

	glColor3d(0.7, 0.7, 0.7);
	glRotated(rotX * 0.001, 1, 0, 0);
	glRotated(rotX * 0.002, 0, 1, 0);
	glRotated(rotX * 1.2, 0, 0, 1);
	glTranslated(8, 0, 0);
	glutWireSphere(1, 14, 10);

	//glFlush();
	glutSwapBuffers();
}

clock_t last = 0;

void gameLoop()
{
	if (clock() - last < 33) return;

	last = clock();
	rotX++;

	glutPostRedisplay();
}
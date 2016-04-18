/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STARS 300

void display();
void keyEventHandler(unsigned char key, int x, int y);
void gameLoop();

int p = 1;
int d = 1;
int rotX = 0;
int rands[STARS];

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
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

void display()
{
	if (d) glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (p) glFrustum(-25, 25, -25, 25, 50, 200);
	else glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);

	// Matriz de modeling - permite translação
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (p) glTranslated(0, 0, -100);
	else glTranslated(0, 0, -50);

	glRotated(15, 1, 0, 0);

	glPushMatrix();
		// Stars rotation
		glRotated(rotX * 0.01, 1, 0, 0);
		glRotated(rotX * 0.02, 0, 1, 0);
		glRotated(rotX * 0.03, 0, 0, 1);

		// Stars
		glBegin(GL_POINTS);
			int i;
			for (i = 0; i < STARS; i += 3)
				glVertex3d(rands[i], rands[i + 1], rands[i + 2]);
				glColor3d(1.0 / rands[i + 2], 1.0 / rands[i + 1], 1.0 / rands[i]);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		// Sun rotation relative to its center
		glRotated(rotX * 0.01, 1, 0, 0);
		glRotated(rotX * 0.02, 0, 1, 0);
		glRotated(rotX * 0.03, 0, 0, 1);

		// Sun
		glColor3d(1, 0.8, 0);
		glutSolidSphere(10, 28, 16);
	glPopMatrix();

	// Earth rotation and distance relative to the sun
	glRotated(rotX, 0, 1, 0);
	glTranslated(30, 0, 0);

	glPushMatrix();
		// Earth rotation relative to its center
		glRotated(rotX * 0.002, 1, 0, 0);
		glRotated(rotX * 0.15, 0, 1, 0);
		glRotated(rotX * 0.002, 0, 0, 1);

		// Earth
		glColor3d(0, 0.2, 0.6);
		glutSolidSphere(4, 20, 10);
	glPopMatrix();

	// Moon rotation and distance relative to the earth
	glRotated(rotX, 0, 1, 0);
	glTranslated(6, 0, 0);

	// Moon
	glColor3d(0.7, 0.7, 0.7);
	glutSolidSphere(1, 14, 10);

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
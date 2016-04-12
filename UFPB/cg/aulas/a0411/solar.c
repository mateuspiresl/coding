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
	if (p) glFrustum(-1.0, 1.0, -1.0, 1.0, 1, 130.0);
	else glOrtho(-50.0, 50.0, -50.0, 50.0, 1, 100);

	// Matriz de modeling - permite translação
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -50);

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
		glEnd();
	glPopMatrix();

	glPushMatrix();
		// Sun rotation
		glRotated(rotX * 0.1, 1, 0, 0);
		glRotated(rotX * 0.2, 0, 1, 0);
		glRotated(rotX * 0.3, 0, 0, 1);

		// Sun
		glColor3d(1, 0.8, 0);
		glutWireSphere(10, 28, 16);
	glPopMatrix();

	// Small rotation relative to the sun
	glRotated(rotX * 0.001, 1, 0, 0);
	glRotated(rotX * 0.002, 0, 1, 0);
	glRotated(rotX * 0.003, 0, 0, 1);

	// Earth rotation and distance relative to the sun
	glRotated(rotX, 0, 1, 0);
	glTranslated(30, 0, 0);

	// Earth rotation relative to its center
	glRotated(rotX * 0.1, 1, 0, 0);
	glRotated(rotX * 0.15, 0, 1, 0);
	glRotated(rotX * 0.2, 0, 0, 1);

	// Earth
	glColor3d(0, 0.2, 0.6);
	glutWireSphere(4, 20, 10);

	// Moon rotation relative to the earth
	glRotated(rotX * 0.1, 1, 1, 0);

	// Moon distance from the earth
	glTranslated(8, 0, 0);

	// Moon rotation relative to its center
	glRotated(rotX * 0.001, 1, 0, 0);
	glRotated(rotX * 0.002, 0, 1, 0);
	glRotated(rotX * 0.003, 0, 0, 1);

	// Moon
	glColor3d(0.7, 0.7, 0.7);
	glutWireSphere(1, 14, 10);

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
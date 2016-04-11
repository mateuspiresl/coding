/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>

void display();
void keyEventHandler(unsigned char key, int x, int y);
void gameLoop();

int rot = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);

	int windowID = glutCreateWindow("OPENGL");

	glutKeyboardFunc(keyEventHandler);
	glutDisplayFunc(display);
	glutIdleFunc(gameLoop);

	glutMainLoop();

	return 0;
}

void keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'a':   rot--;
					break;
		case 'd':   rot++;
					break;
	}
	
	printf("%d\n", rot);

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
	
	glColor3d(1, 0.8, 0);
	glutWireSphere(10, 50, 40);

	glColor3d(0, 0.2, 0.6	);
	glRotated(rot, 0, 0, 1);
	glTranslated(40, 0, 0);
	glutWireSphere(4, 30, 30);

	glColor3d(0.7, 0.7, 0.7);
	glRotated(rot * 2, 0, 0, 1);
	glTranslated(10, 0, 0);
	glutWireSphere(1, 20, 20);

	//glFlush();
	glutSwapBuffers();
}

clock_t last = 0;

void gameLoop()
{
	if (clock() - last < 33) return;

	last = clock();
	rot++;
	glutPostRedisplay();
}
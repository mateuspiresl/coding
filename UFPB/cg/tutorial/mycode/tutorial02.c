/* gcc -o file file.c -lglut -lGL -lGLU */

#include <GL/glut.h>

int abs(int n) { return n > 0 ? n : -n; }
int rnd(float n) { return (int) (n + 0.5); }

void display();
void drawLineBres(int xa, int ya, int xb, int yb, int inverted);
void drawLineDDA(int xa, int ya, int xb, int yb);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 480);
	int windowID = glutCreateWindow("a0307");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void display()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_LINES);
		glColor3d(1, 0, 0);
		glVertex2d(0, 0);
		glVertex2d(50, 50);
	glEnd();

	glFlush();
}
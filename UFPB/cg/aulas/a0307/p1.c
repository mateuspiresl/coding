/* gcc -o file file.c -lglut -lGL -lGLU */

#include <GL/glut.h>
#include <stdio.h>

int abs(int n) { return n > 0 ? n : -n; }
int rnd(float n) { return (int) (n + 0.5); }

void display();
void drawLineBres(int xa, int ya, int xb, int yb, int inverted);
void drawLineDDA(int xa, int ya, int xb, int yb);
void drawLine(int xa, int ya, int xb, int yb, int reversed);


int algorithm = 0;
int xa, ya, xb, yb;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 480);
	
	while (algorithm < 1 || algorithm > 3)
	{
		printf("\n1. Equação da reta\n2. DDA\n3. Bresenham\n\n");
		printf("Escolha o algorítmo: ");
		scanf("%d", &algorithm);
	}

	printf("Reta (xa ya xb yb): ");
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	printf("Veja a tela do gráfico!\n");

	int windowID = glutCreateWindow("a0307");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void display()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_LINES);
		glColor3d(0.9, 0.9, 0.9);
		glVertex2d(-100, 0);
		glVertex2d(100, 0);
		glVertex2d(0, 100);
		glVertex2d(0, -100);
	glEnd();
	glBegin(GL_POINTS);
		glColor3d(0, 0, 0);

		switch (algorithm)
		{
			case 1: drawLine(xa, ya, xb, yb, 0); break;
			case 2: drawLineDDA(xa, ya, xb, yb); break;
			case 3: drawLineBres(xa, ya, xb, yb, 0); break;
		}
	glEnd();

	glFlush();
}

void drawLineBres(int xa, int ya, int xb, int yb, int inverted)
{
	int dx = xb - xa,
		dy = yb - ya,
		slope;
	
	if (xa > xb)
		return drawLineBres(xb, yb, xa, ya, inverted);
	if (abs(dy) > abs(dx))
		return drawLineBres(ya, xa, yb, xb, ! inverted);

	if (dy < 0)
	{
		slope = -1;
		dy = -dy;
	}
	else slope = 1;

	int incE = 2 * dy,
		incNE = 2 * (dy - dx),
		p = 2 * dy - dx;

	for (; xa <= xb; xa++)
	{
		if (inverted)
			glVertex2d(ya, xa);
		else
			glVertex2d(xa, ya);

		if (p < 0)
			p += incE;
		else {
			p += incNE;
			ya += slope;
		}
	}
}


void drawLineDDA(int xa, int ya, int xb, int yb)
{
	int dx = xb - xa,
		dy = yb - ya;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float	xIncrement = dx / (float) steps,
			yIncrement = dy / (float) steps,
			x = xa,
			y = ya;

	glVertex2d(rnd(x), rnd(y));

	for (int k = 0; k < steps; k++)
	{
		x += xIncrement;
		y += yIncrement;

		glVertex2d(rnd(x), rnd(y));
	}
}

void drawLine(int xa, int ya, int xb, int yb, int inverted)
{
	if (xa > xb)
		return drawLine(xb, yb, xa, ya, inverted);

	int dx = xb - xa,
		dy = yb - ya;

	if (abs(dx) < abs(dy))
		return drawLine(ya, xa, yb, xb, ! inverted);

	double m = (double) (yb - ya) / (xb - xa);

	for (int x = xa; x <= xb; x++)
	{
		int y = (x - xa) * m + ya;

		if (inverted)
			glVertex2d(y, x);
		else
			glVertex2d(x, y);
	}
}
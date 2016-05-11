#include "drawing.h"
#include <GL/glut.h>

void draw_cube(float size)
{
	// TRASEIRA
	glBegin(GL_POLYGON);
		glNormal3f(0.0, 0.0, -1.0);
		glVertex3f(0, size, -size);
		glVertex3f(0, 0, -size);
		glVertex3f(size, 0, -size);
		glVertex3f(size, size, -size);
	glEnd();

	// FRENTE
	glBegin(GL_POLYGON);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(0, size, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(size, 0, 0);
		glVertex3f(size, size, 0);
	glEnd();

	// ESQUERDA
	glBegin(GL_POLYGON);
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(0, size, -size);
		glVertex3f(0, 0, -size);
		glVertex3f(0, 0, 0);
		glVertex3f(0, size, 0);
	glEnd();

	// DIREITA
	glBegin(GL_POLYGON);
		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(size, size, 0);
		glVertex3f(size, 0, 0);
		glVertex3f(size, 0, -size);
		glVertex3f(size, size, -size);
	glEnd();

	// BASE
	glBegin(GL_POLYGON);
		glNormal3f(0.0, -1.0, 0.0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -size);
		glVertex3f(size, 0, -size);
		glVertex3f(size, 0, 0);
	glEnd();

	// TOPO
	glBegin(GL_POLYGON);
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(0, size, -size);
		glVertex3f(0, size, 0);
		glVertex3f(size, size, 0);
		glVertex3f(size, size, -size);
	glEnd();
}

void draw_pyramid(float base, float size)
{
	glBegin(GL_TRIANGLES);
		glColor3f(0.66, 0, 0.33);
		glVertex3f(0, 0, 0);
		glVertex3f(base, 0, 0);
		glVertex3f(base, 0, -base);
		
		glColor3f(0.33, 0, 0.66);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -base);
		glVertex3f(base, 0, -base);

		glColor3f(0.17, 0.33, 0.50);
		glNormal3f(1.0, 0.5, 0.0);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, -base);
		glVertex3f(base / 2, size, -base / 2);

		glColor3f(0.50, 0.33, 0.17);
		glNormal3f(0.0, 0.5, 1.0);
		glVertex3f(0, 0, 0);
		glVertex3f(base, 0, 0);
		glVertex3f(base / 2, size, -base / 2);
		
		glColor3f(0.50, 0.33, 0.83);
		glNormal3f(0.0, 0.5, -1.0);
		glVertex3f(0, 0, -base);
		glVertex3f(base, 0, -base);
		glVertex3f(base / 2, size, -base / 2);
		
		glColor3f(0.83, 0.33, 0.50);
		glNormal3f(-1.0, 0.5, 0.0);
		glVertex3f(base, 0, 0);
		glVertex3f(base, 0, -base);
		glVertex3f(base / 2, size, -base / 2);
	glEnd();
}

/* Desenha um retângulo formado por vários retângulos menores */
void draw_rect(int size, int precision)
{
	for (int x = 0; x < size; x += precision) {
		for (int z = 0; z > -size; z -= precision)
		{
			glBegin(GL_POLYGON);
				glVertex3d(x, 0, z);
				glVertex3d(x + precision, 0, z);
				glVertex3d(x + precision, 0, z + precision);
				glVertex3d(x, 0, z + precision);
			glEnd();
		}
	}
}
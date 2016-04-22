#include "drawing.h"
#include <GL/glut.h>

void draw_cube(float x, float y, float z, int len)
{
	// FRENTE
	glBegin(GL_POLYGON);
		glVertex3d(x, y + len, z + len);
		glVertex3d(x, y, z + len);
		glVertex3d(x + len, y, z + len);
		glVertex3d(x + len, y + len, z + len);
	glEnd();

	// TRASEIRA
	glBegin(GL_POLYGON);
		glVertex3d(x, y + len, z);
		glVertex3d(x, y, z);
		glVertex3d(x + len, y, z);
		glVertex3d(x + len, y + len, z);
	glEnd();

	// DIREITA
	glBegin(GL_POLYGON);
		glVertex3d(x, y + len, z + len);
		glVertex3d(x, y, z + len);
		glVertex3d(x, y, z);
		glVertex3d(x, y + len, z);
	glEnd();

	// ESQUERDA
	glBegin(GL_POLYGON);
		glVertex3d(x + len, y + len, z);
		glVertex3d(x + len, y, z);
		glVertex3d(x + len, y, z + len);
		glVertex3d(x + len, y + len, z + len);
	glEnd();

	// TOPO
	glBegin(GL_POLYGON);
		glVertex3d(x, y, z);
		glVertex3d(x, y, z + len);
		glVertex3d(x + len, y, z + len);
		glVertex3d(x + len, y, z);
	glEnd();

	// BASE
	glBegin(GL_POLYGON);
		glVertex3d(x, y + len, z + len);
		glVertex3d(x, y + len, z);
		glVertex3d(x + len, y + len, z);
		glVertex3d(x + len, y + len, z + len);
	glEnd();
}

void draw_putLight(float x, float y, float z)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 150.0 };
	GLfloat light_position[] = { x, y, z, 1.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 0.1 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
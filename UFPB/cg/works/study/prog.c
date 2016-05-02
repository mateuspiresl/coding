/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

void display();
void keyEventHandler(unsigned char key, int x, int y);
void putLight();
void material();
void material2();
void pointLight();

int rotX = 0;
int rotY = 0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	int windowID = glutCreateWindow("OPENGL");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyEventHandler);

	glEnable(GL_DEPTH_TEST);
	
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

/* Configurações. */
void settings()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-25, 25, -25, 25, 50, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -150);
}

/* Função de desenho. */
void display()
{	
	settings();

	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat red_light[] = { 1.0, 0.0, 0.0, 1.0 };

	// Light 0

	glPushMatrix();
		glTranslated(-25, 0, 0);

		pointLight(GL_LIGHT0, red_light);

		glRotated(rotX * 4, 0, 1, 0);
		glRotated(rotY * 4, 1, 0, 0);

		material();
		glutSolidTeapot(20);
	glPopMatrix();

	// Light 1

	glPushMatrix();
		glTranslated(25, 0, 0);

		pointLight(GL_LIGHT1, white_light);

		glRotated(rotX * 4, 0, 1, 0);
		glRotated(rotY * 4, 1, 0, 0);

		material2();
		glutSolidTeapot(20);
	glPopMatrix();

	glutSwapBuffers();
}

void material()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void material2()
{
	GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 0.5 };
	GLfloat mat_shininess[] = { 100.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void pointLight(GLenum light, GLfloat color[])
{
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	
	glLightfv(light, GL_POSITION, light_position);
	glLightfv(light, GL_DIFFUSE, color);
	glLightfv(light, GL_SPECULAR, color);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(light);
}

void putLight()
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };

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
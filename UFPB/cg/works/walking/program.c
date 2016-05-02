/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "drawing.h"
#include "map.h"
#include "player.h"

void gameLoop();
void reshape(int w, int h);
void display();
void draw();
void setRandomObjectsData(int n, int x, int z, int size);
void drawRandomObjects();

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

extern Player player;
int* data = NULL;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Game");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(gameLoop);

	glutKeyboardFunc(player_keyEventHandler);
	player_init(0, 0, 0);

	setRandomObjectsData(80, -500, 0, 1000);

	glutMainLoop();

	return 0;
}

clock_t last = 0;

void gameLoop()
{
	if (clock() - last < 16) return;
	last = clock();

	if (player.position.y < 0)
	{
		player.position.y *= player.acc;
		player.acc *= 0.9;

		if (player.position.y > -0.05)
		{
			player.position.y = 0;
			player.acc = 0;
		}
	}

	glutPostRedisplay();
}

void reshape(int w, int h)
{
	//glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-25.0, 25.0, -25.0, 25.0, 50.0, 10000.0);
	
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0, 0, 0, 0);
}

void display()
{
	glLoadIdentity();

	glTranslated(0, -30, -100);

	// Luz
	GLfloat light_position[] = { 0.0, 0.0, 20.0, 1.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glPushMatrix();
		glTranslated(0, 10, 10);
		glutSolidTorus(2, 4, 10, 10);
	glPopMatrix();

	glTranslated(player.position.x, 0, player.position.z);

	draw();

	glutSwapBuffers();
}

void draw()
{
	glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat[]) { 1.0, 1.0, 1.0, 1.0 });
	glMaterialfv(GL_FRONT, GL_SHININESS, (GLfloat[]) { 50.0 });	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat[]) { 0.6, 0.6, 0.6, 1.0 });	

	drawRandomObjects();

	glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat[]) { 0.4, 0.4, 0.4, 1.0 });

	glPushMatrix();
		glTranslated(-500, 0, 0);
		draw_rect(1000, 5);

		glTranslated(0, 60, 0);
		draw_rect(1000, 5);
	glPopMatrix();
}

void setRandomObjectsData(int n, int x, int z, int size)
{
	data = malloc(n * 4 * sizeof (int) + 1);
	srand(time(NULL));

	int j = 0;
	for (int i = 0; i < n; i++)
	{
		data[j++] = rand() % 3;
		data[j++] = x + (rand() % size);// + 100;
		data[j++] = z - (rand() % size) - 100;

		if (data[j - 3] == 1)
			data[j++] = 2 + (rand() % 20);
	}

	data[j] = -1;
}

void drawRandomObjects()
{
	for (int j = 0; data[j] != -1;)
	{
		glPushMatrix();
		if (data[j++] == 0)
		{
			//glRotated(270, 1, 0, 0);
			glTranslated(data[j], 0, data[j + 1]); j += 2;
			draw_triangle(20, 40);
			//glutSolidCone(10, 40, 20, 20);
		}
		else if (data[j++] == 1)
		{
			glTranslated(data[j], data[j + 2], data[j + 1]); j += 3;
			draw_cube(20);
		}
		else
		{
			glRotated(180, 0, 0, 1);
			glTranslated(data[j], 0, data[j + 1]); j += 2;
			glTranslated(-20, -60, 0);
			draw_triangle(20, 40);
		}
		glPopMatrix();
	}
}
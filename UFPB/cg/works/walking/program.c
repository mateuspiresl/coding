/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "drawing.h"
#include "map.h"
#include "player.h"

void display();
void gameLoop();

extern Player player;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	glutCreateWindow("Game");

	glutKeyboardFunc(player_keyEventHandler);
	glutDisplayFunc(display);
	glutIdleFunc(gameLoop);

	player_init(0, 0, 0);

	glutMainLoop();

	return 0;
}

void display()
{
	glEnable(GL_DEPTH_TEST);
	
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-25, 25, -25, 25, 1, 100);

	// Matriz de modeling - permite translação
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslated(0, 0, -1);

	glRotated(10, 0, 1, 0);
	map_draw();

	//draw_cube(0, 0, 0, 10);

	draw_putLight(player.x + 50, player.y + 10, player.z + 10);

	glutSwapBuffers();
}

clock_t last = 0;

void gameLoop()
{
	if (clock() - last < 16) return;
	last = clock();

	glutPostRedisplay();
}
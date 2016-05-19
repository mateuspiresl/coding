/* gcc -o file file.c -lglut -lGL -lGLU */
#include <GL/glut.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "drawing.h"
#include "player.h"

void gameLoop();
void reshape(int w, int h);
void display();
void drawRandomObjects(int n, int x, int z, int size);

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

// Armazena dados do jogador
extern Player player;

GLuint listIndex;

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

	// Inicializa o jogador
	player_init(0, 0, 0);

	// Gera os dados dos objetos aleatórios
	listIndex = glGenLists(1);
	glNewList(listIndex, GL_COMPILE);
		drawRandomObjects(120, -500, 0, 1000);
	glEndList();

	glutMainLoop();

	return 0;
}

clock_t last = 0;

void gameLoop()
{
	// Re-exibe a cada 16 millis (~60fps)
	if (clock() - last < 16) return;
	last = clock();

	// Atualiza posição do jogador
	player_updatePosition();

	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-25.0, 25.0, -25.0, 25.0, 100.0, 1500.0);
	
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.3, 0.5, 0.5, 1);

	// Luz
	GLfloat light_position[] = { -100.0, -30.0, -150.0, 1.0 };
	GLfloat white_light[] = { 0.0, 0.8, 0.8, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
}

void display()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

	// Altura do usuário e aproximação
	glTranslated(0, -30, -100);

	// Movimento do usuário
	glTranslated(player.position.x * 2, player.position.y, player.position.z * 3);

	// Definição do material dos objetos
	glMaterialfv(GL_FRONT, GL_SPECULAR, (GLfloat[]) { 0.6, 0.6, 0.6, 1.0 });
	glMaterialfv(GL_FRONT, GL_SHININESS, (GLfloat[]) { 100.0 });	
	glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat[]) { 0.3, 0.3, 0.3, 0.3 });	

	// Desenha objetos aleatórios
	glCallList(listIndex);

	// Definição do material dos objetos do piso e do teto
	glMaterialfv(GL_FRONT, GL_DIFFUSE, (GLfloat[]) { 0.1, 0.1, 0.1, 1.0 });

	// Desenha o piso e o teto
	glPushMatrix();
		glTranslated(-500, 0, 0);
		draw_rect(1000, 50);

		glTranslated(0, 60, 0);
		draw_rect(1000, 50);
	glPopMatrix();

	glutSwapBuffers();
}

void drawRandomObjects(int n, int x, int z, int size)
{
	srand(time(NULL));

	// Desenhar 30 objetos
	for (int i = 0; i < 30; i++)
	{
		int randX = x + (rand() % size),
			randZ = z - (rand() % size);

		glPushMatrix();
			// 25% de chance de ser um pirâmide
			if (rand() % 4 == 0)
			{
				glTranslated(randX, 0, randZ);
				draw_pyramid(20, 40);
			}
			// 50% de chance de ser um cubo
			else if (rand() % 4 <= 2)
			{
				glTranslated(randX, 0, randZ);
				draw_cube(20);
			}
			// 25% de chance de ser um pirâmide invertida
			else
			{
				glRotated(180, 0, 0, 1);
				glTranslated(randX, 0, randZ);
				glTranslated(-20, -60, 0);
				draw_pyramid(20, 40);
			}
		glPopMatrix();
	}
}
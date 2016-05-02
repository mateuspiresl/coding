#include "player.h"
#include <GL/glut.h>

const float PLAYER_JUMP = -100;

Player player;

void player_init(float x, float y, float z)
{
	player.position.x = x;
	player.position.y = y;
	player.position.z = z;

	player.orientation.x = 0;
	player.orientation.y = 0;
	player.orientation.z = 0;

	player.acc = 0;
}

int lastX = -1, lastY = -1;

void player_keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':   player.position.z++;
					break;
		case 's':	player.position.z--;
					break;
		case 'a':   player.position.x++;
					break;
		case 'd':	player.position.x--;
					break;
		case 'b':	player.position.y = PLAYER_JUMP;
					player.acc = 1;
	}

	if (lastX != -1 && lastY != -1)
	{
		player.orientation.x += x - lastX;
		player.orientation.y += y - lastY;
	}

	lastX = x;
	lastY = y;

	glutPostRedisplay();
}
#include "player.h"
#include <GL/glut.h>

const float JUMP_ACC = 10;

Player player;

void player_init(float x, float y, float z)
{
	player.x = x;
	player.y = y;
	player.z = z;

	player.zAcc = 0;
}

void player_keyEventHandler(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':   player.y++;
					break;
		case 'a':   player.x--;
					break;
		case 's':	player.y--;
					break;
		case 'd':	player.x++;
					break;
		case 'b':	player.zAcc = JUMP_ACC;
	}

	glutPostRedisplay();
}
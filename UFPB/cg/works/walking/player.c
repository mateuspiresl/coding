#include "player.h"
#include <GL/glut.h>

const float PLAYER_JUMP = -20;

Player player;

void player_init(float x, float y, float z)
{
	player.position.x = x;
	player.position.y = y;
	player.position.z = z;

	player.acc = 0;
}

/* Atualiza posição do jogador em caso de saltos */
void player_updatePosition()
{
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
}

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
		// Pula
		case 'b':	player.position.y = PLAYER_JUMP;
					player.acc = 1;
	}

	glutPostRedisplay();
}
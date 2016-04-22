#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct {
	float x, y, z;
	float zAcc;
} Player;

void player_init(float x, float y, float z);

void player_keyEventHandler(unsigned char key, int x, int y);

#endif
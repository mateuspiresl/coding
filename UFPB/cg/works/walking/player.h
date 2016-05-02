#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct {
	float x, y, z;
} PointF;

typedef struct {
	PointF position;
	PointF orientation;
	float acc;
} Player;

void player_init(float x, float y, float z);

void player_keyEventHandler(unsigned char key, int x, int y);

#endif
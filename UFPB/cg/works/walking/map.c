#include "map.h"
#include "drawing.h"
#include <GL/glut.h>

void map_draw()
{
	int len = 20;

	int x, y;
	for (x = 0; x < 20; x++)
		for (y = 0; y < 20; y++)
	{
		//glColor3d(1 / (x * len + 1), 1 / (y * len + 1), 1 / (1 * len + 1));
		draw_cube(x * len - 10 * len, -len * 2, y * len, len);
	}
}
#include <stdio.h>
#include <GL/glut.h>
#include "point3d.h"
#include "quadface.h"

QuadFaceList readCube(char* filename)
{
	FILE* file = fopen(filename, "r");
	const size_t line_size = 300;
	char* line = malloc(line_size);

	Point3DList pointsList = pl_newList();
	QuadFaceList facesList = fl_newList();

	while (fgets(line, line_size, file) != NULL)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			char v;
			float x, y, z;
			sscanf(line, "%c %f %f %f", &v, &x, &y, &z);
			printf("%f %f %f\n", x, y, z);

			pl_add(pointsList, pl_newPoint(x, y, z));
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			char v;
			int a, b, c, d;
			sscanf(line, "%c %d %d %d %d", &v, &a, &b, &c, &d);
			printf("%d %d %d %d\n", a, b, c, d);

			fl_add(facesList, fl_newFace(
					pl_get(pointsList, a - 1),
					pl_get(pointsList, b - 1),
					pl_get(pointsList, c - 1),
					pl_get(pointsList, d - 1)
				));
		}
	}

	fclose(file);
	//pl_freeList(pointsList);

	return facesList;
}

void pointVertex(Point3D* point) {
	glVertex3d(point->x, point->y, point->z);
}

void faceVertex(QuadFace* face)
{
	pointVertex(face->a);
	pointVertex(face->b);
	pointVertex(face->c);
	pointVertex(face->d);
}

void drawCube(QuadFaceList faces)
{
	QuadFaceNode node = fl_getHead(faces);

	while (node != NULL)
	{
		printf("NODE: %p\n", node);

		glBegin(GL_POLYGON);

		glColor3d(
				node->face->a->x < 1 ? node->face->a->x : 1 / node->face->a->x,
				node->face->a->y < 1 ? node->face->a->y : 1 / node->face->a->y,
				node->face->a->z < 1 ? node->face->a->z : 1 / node->face->a->z
			);

		if (node->face->a == NULL) { printf("node->face->a == NULL\n"); return; }
		if (node->face->b == NULL) { printf("node->face->b == NULL\n"); return; }
		if (node->face->c == NULL) { printf("node->face->c == NULL\n"); return; }
		if (node->face->d == NULL) { printf("node->face->d == NULL\n"); return; }

		faceVertex(node->face);

		glEnd();

		printf("\n(%d %d %d) (%d %d %d) (%d %d %d) (%d %d %d)\n\n",
				node->face->a->x, node->face->a->y, node->face->a->z,
				node->face->b->x, node->face->b->y, node->face->b->z,
				node->face->c->x, node->face->c->y, node->face->c->z,
				node->face->d->x, node->face->d->y, node->face->d->z
			);

		node = fl_getNext(node);
	}
}
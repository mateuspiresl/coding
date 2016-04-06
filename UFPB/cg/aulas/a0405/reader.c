#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

typedef struct {
	float x, y, z;
} Point3D;
struct _Point3DNode {
	struct _Point3DNode* next;
	Point3D point;
};
typedef struct _Point3DNode Point3DNode;

typedef struct {
	Point3D *a, *b, *c, *d;
} QuadFace;
struct _QuadFaceNode {
	struct _QuadFaceNode* next;
	QuadFace face;
};
typedef struct _QuadFaceNode QuadFaceNode;

Point3D* pointAt(Point3DNode* pointsRoot, int index)
{
	Point3DNode* node = pointsRoot;

	while (index && node != NULL)
	{
		index--;
		node = node->next;
	}

	if (index == 0)
		return &(node->point);
	else
		return NULL;
}

QuadFaceNode* readCube(char* filename)
{
	FILE* file = fopen(filename, "r");
	const size_t line_size = 300;
	char* line = malloc(line_size);

	Point3DNode* pointsRoot = NULL;
	Point3DNode* pointsNode = NULL;

	QuadFaceNode* facesRoot = NULL;
	QuadFaceNode* facesNode = NULL;

	while (fgets(line, line_size, file) != NULL)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			if (pointsNode == NULL)
				pointsNode = pointsRoot = malloc(sizeof(Point3DNode));
			else
			{
				pointsNode->next = malloc(sizeof(Point3DNode));
				pointsNode = pointsNode->next;
			}

			char v;
			float x, y, z;
			sscanf(line, "%c %f %f %f", &v, &x, &y, &z);

			pointsNode->point.x = x;
			pointsNode->point.y = y;
			pointsNode->point.z = z;

			printf("%f %f %f\n", x, y, z);
		}

		else if (line[0] == 'f' && line[1] == ' ')
		{
			if (facesNode == NULL)
				facesNode = facesRoot = malloc(sizeof(QuadFaceNode));
			else
			{
				facesNode->next = malloc(sizeof(QuadFaceNode));
				facesNode = facesNode->next;
			}

			char v;
			int a, b, c, d;
			sscanf(line, "%c %d %d %d %d", &v, &a, &b, &c, &d);

			facesNode->face.a = pointAt(pointsRoot, a);
			facesNode->face.b = pointAt(pointsRoot, b);
			facesNode->face.c = pointAt(pointsRoot, c);
			facesNode->face.d = pointAt(pointsRoot, d);

			printf("%d %d %d %d\n", a, b, c, d);
		}
	}

	fclose(file);

	return facesRoot;
}

void drawCube(QuadFaceNode* facesRoot)
{
	QuadFaceNode* node = facesRoot;

	while (node != NULL)
	{
		glBegin(GL_POLYGON);

		glColor3d(
				node->face.a->x < 1 ? node->face.a->x : 1 / node->face.a->x,
				node->face.a->y < 1 ? node->face.a->y : 1 / node->face.a->y,
				node->face.a->z < 1 ? node->face.a->z : 1 / node->face.a->z
			);

		glVertex3d(node->face.a->x, node->face.a->y, node->face.a->z);
		glVertex3d(node->face.b->x, node->face.b->y, node->face.b->z);
		glVertex3d(node->face.c->x, node->face.c->y, node->face.c->z);
		glVertex3d(node->face.d->x, node->face.d->y, node->face.d->z);

		glEnd();

		printf("(%d %d %d) (%d %d %d) (%d %d %d) (%d %d %d)\n",
				node->face.a->x, node->face.a->y, node->face.a->z,
				node->face.b->x, node->face.b->y, node->face.b->z,
				node->face.c->x, node->face.c->y, node->face.c->z,
				node->face.d->x, node->face.d->y, node->face.d->z
			);

		node = node->next;
	}
}
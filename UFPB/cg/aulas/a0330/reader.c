#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y, z;
} Point3D;
struct _Point3DNode {
	struct _Point3DNode* next;
	Point3D point;
};
typedef struct _Point3DNode Point3DNode;

typedef struct {
	int a, b, c, d;
} QuadFace;
struct _QuadFaceNode {
	struct _QuadFaceNode* next;
	QuadFace face;
};
typedef struct _QuadFaceNode QuadFaceNode;

int main()
{
	FILE* file = fopen("cubo.obj", "r");
	const size_t line_size = 300;
	char* line = malloc(line_size);

	int numPoints = 0;
	Point3DNode pointsRoot;
	Point3DNode* pointsNode = NULL;

	int numFaces = 0;
	QuadFaceNode facesRoot;
	QuadFaceNode* facesNode = NULL;

	while (fgets(line, line_size, file) != NULL)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			if (pointsNode == NULL)
				pointsNode = &pointsRoot;
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
				facesNode = &facesRoot;
			else
			{
				facesNode->next = malloc(sizeof(QuadFaceNode));
				facesNode = facesNode->next;
			}

			char v;
			int a, b, c, d;
			sscanf(line, "%c %d %d %d %d", &v, &a, &b, &c, &d);

			facesNode->face.a = a;
			facesNode->face.b = b;
			facesNode->face.c = c;
			facesNode->face.d = d;

			printf("%d %d %d %d\n", a, b, c, d);
		}
	}

	fclose(file);

	return 0;
}
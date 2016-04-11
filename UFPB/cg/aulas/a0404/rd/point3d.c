#include <stdlib.h>
#include "point3d.h"

Point3DList pl_newList()
{
	Point3DList list = malloc(sizeof(struct __Point3DList));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

Point3DNode pl_newNode()
{
	Point3DNode node = malloc(sizeof(struct __Point3DNode));
	node->next = NULL;
	node->point = NULL;
	return node;
}

Point3D* pl_newPoint(float x, float y, float z)
{
	Point3D* point = malloc(sizeof(Point3D));
	point->x = x;
	point->y = y;
	point->z = z;
	return point;
}

void pl_freeList(Point3DList list)
{
	Point3DNode node = list->head;

	while (node != NULL)
	{
		free(node);
		node = node->next;
	}

	free(list);
}

void pl_add(Point3DList list, Point3D* point)
{
	if (list->head == NULL)
	{
		list->head = list->tail = pl_newNode();
	}
	else
	{
		list->tail->next = pl_newNode();
		list->tail = list->tail->next;
	}

	list->tail->point = point;
}

Point3D* pl_get(Point3DList list, int index)
{
	Point3DNode node = list->head;

	while (index--)
		node = node->next;

	return node->point;
}
#include <stdlib.h>
#include "quadface.h"

FaceList fl_newList()
{
	FaceList list = malloc(sizeof(struct __FaceList));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

FaceNode fl_newNode()
{
	FaceNode node = malloc(sizeof(struct __FaceNode));
	node->next = NULL;
	node->face = NULL;
	return node;
}

Face* fl_newFace(Point3D* a, Point3D* b, Point3D* c, Point3D* d)
{
	Face* face = malloc(sizeof(Face));
	face->a = a;
	face->b = b;
	face->c = c;
	face->d = d;
	return face;
}

void fl_add(FaceList list, Face* face)
{
	if (list->head == NULL)
	{
		list->head = list->tail = fl_newNode();
	}
	else
	{
		list->tail->next = fl_newNode();
		list->tail = list->tail->next;
	}

	list->tail->face = face;
}

FaceNode fl_getHead(FaceList list) {
	return list->head;
}

FaceNode fl_getNext(FaceNode node)
{
	if (node == NULL) return NULL;
	return node->next;
}

Face* fl_getValue(FaceNode node) {
	return node->face;
}
#include <stdlib.h>
#include "quadface.h"

QuadFaceList fl_newList()
{
	QuadFaceList list = malloc(sizeof(struct __QuadFaceList));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

QuadFaceNode fl_newNode()
{
	QuadFaceNode node = malloc(sizeof(struct __QuadFaceNode));
	node->next = NULL;
	node->face = NULL;
	return node;
}

QuadFace* fl_newFace(Point3D* a, Point3D* b, Point3D* c, Point3D* d)
{
	QuadFace* face = malloc(sizeof(QuadFace));
	face->a = a;
	face->b = b;
	face->c = c;
	face->d = d;
	return face;
}

void fl_add(QuadFaceList list, QuadFace* face)
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

QuadFaceNode fl_getHead(QuadFaceList list) {
	return list->head;
}

QuadFaceNode fl_getNext(QuadFaceNode node)
{
	if (node == NULL) return NULL;
	return node->next;
}

QuadFace* fl_getValue(QuadFaceNode node) {
	return node->face;
}
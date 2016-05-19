#ifndef QUADFACE_H
#define QUADFACE_H

#include "point3d.h"

typedef struct {
	Point3D *a, *b, *c, *d;
} Face;

struct __FaceNode {
	struct __FaceNode* next;
	Face* face;
};
typedef struct __FaceNode* FaceNode;

struct __FaceList {
	FaceNode head;
	FaceNode tail;
	int size;
};
typedef struct __FaceList* FaceList;

FaceList fl_newList();

FaceNode fl_newNode();

Face* fl_newFace(Point3D* a, Point3D* b, Point3D* c, Point3D* d);

void fl_add(FaceList list, Face* face);

FaceNode fl_getHead(FaceList list);

FaceNode fl_getNext(FaceNode node);

Face* fl_getValue(FaceNode node);

#endif
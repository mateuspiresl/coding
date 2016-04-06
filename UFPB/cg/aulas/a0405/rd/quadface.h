#ifndef QUADFACE_H
#define QUADFACE_H

#include "point3d.h"

typedef struct {
	Point3D *a, *b, *c, *d;
} QuadFace;

struct __QuadFaceNode {
	struct __QuadFaceNode* next;
	QuadFace* face;
};
typedef struct __QuadFaceNode* QuadFaceNode;

struct __QuadFaceList {
	QuadFaceNode head;
	QuadFaceNode tail;
};
typedef struct __QuadFaceList* QuadFaceList;


QuadFaceList fl_newList();

QuadFaceNode fl_newNode();

QuadFace* fl_newFace(Point3D* a, Point3D* b, Point3D* c, Point3D* d);

void fl_add(QuadFaceList list, QuadFace* face);

QuadFaceNode fl_getHead(QuadFaceList list);

QuadFaceNode fl_getNext(QuadFaceNode node);

QuadFace* fl_getValue(QuadFaceNode node);

#endif
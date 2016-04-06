#ifndef POINT3D_H
#define POINT3D_H

typedef struct {
	float x, y, z;
} Point3D;

struct __Point3DNode {
	struct __Point3DNode* next;
	Point3D* point;
};
typedef struct __Point3DNode* Point3DNode;

struct __Point3DList {
	Point3DNode head;
	Point3DNode tail;
};
typedef struct __Point3DList* Point3DList;

Point3DList pl_newList();

Point3DNode pl_newNode();

Point3D* pl_newPoint(float x, float y, float z);

void pl__freeList(Point3DList list);

void pl_add(Point3DList list, Point3D* point);

Point3D* pl_get(Point3DList list, int index);

#endif
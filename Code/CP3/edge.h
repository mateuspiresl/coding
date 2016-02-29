#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

class Edge {

public:
	Vertex* to;
	int weight;

	Edge(Vertex* _to, int _weight);

};

#endif
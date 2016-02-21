#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

template <class Value, class Weight>
class Edge {

public:
	Vertex<Value, Weight>* to;
	Weight weight;

	Edge(Vertex<Value, Weight>* _to, Weight _weight) {
		to = _to;
		weight = _weight;
	}

};

#endif
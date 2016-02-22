#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

#include "edge.h"

template <class Value, class Weight>
class Vertex {

public:
	Value value;
	std::vector<Edge<Value, Weight>*> neighbors;

	Vertex(Value _value);

};

#endif
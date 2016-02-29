#ifndef VERTEX_H
#define VERTEX_H

#include <vector>

class Edge;
class Vertex {

public:
	int value;
	std::vector<Edge*> neighbors;

	Vertex(int _value);

};

#endif
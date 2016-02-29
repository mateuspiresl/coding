#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>

class Vertex {

public:
	int value;
	std::vector<Vertex*> neighbors;

	Vertex(int _value);

	//std::vector<Vertex*>::iterator begin(); 
	//std::vector<Vertex*>::iterator end(); 

};

#endif
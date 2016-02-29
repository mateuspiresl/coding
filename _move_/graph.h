#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "vertex.h"

class Graph {

public:
	std::vector<Vertex*> V;

	int insert(Vertex* vertex);
	void direct(int a, int b);
	void connect(int a, int b);

	Vertex* depthFirstSearch(Vertex* source, Vertex* find);
	Vertex* dfs(Vertex* source, Vertex* find, std::set<Vertex*>* visited);

	Vertex* breadthFirstSearch(int value);

};

#endif
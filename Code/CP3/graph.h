#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

#include "vertex.h"

class Graph {

	std::vector<Vertex*> V;

	bool dfs_findVertex_(Vertex* source, Vertex* vertex, std::set<Vertex*>* visited);
	bool dfs_findValue_(Vertex* source, int value, std::set<Vertex*>* visited);

public:
	int insert(Vertex* vertex);
	Vertex* at(int index);
	int indexOf(Vertex* vertex);

	void direct(int from, int to, int weight);
	void connect(int a, int b, int weight);

	bool dfs_findVertex(Vertex* source, Vertex* vertex);
	bool dfs_findValue(Vertex* source, int value);

};

#endif
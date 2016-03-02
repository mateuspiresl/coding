#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::set<int> si;

class Graph {

	std::vector<vii*> V;

	bool dfs_connection_(int source, int target, si* visited);

public:
	int insert(vii* vertex);
	vii* at(int index);
	
	void direct(int source, int target, int weight);
	void connect(int a, int b, int weight);

	bool dfs_connection(int source, int target);
	bool dfs_insideCicle(int index);

};

#endif
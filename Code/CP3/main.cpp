#include <iostream>
#include "graph.h"

int main()
{
	Graph graph;

	std::cout << "Size: ";
	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
		graph.insert(new Vertex(i));

	std::cout << "Connections: ";
	int c; std::cin >> c;
	while (c--)
	{
		int from, to;
		std::cin >> from >> to;
		
		graph.connect(from, to, 1);
	}

	std::cout << "Find vertex: ";
	int f; std::cin >> f;
	while (f--)
	{
		int from, find;
		std::cin >> from >> find;
		
		std::cout << (graph.dfs_findVertex(graph.at(from), graph.at(find)) ? "found" : "not") << std::endl;
	}

	std::cout << "Find value: ";
	int v; std::cin >> v;
	while (v--)
	{
		int from, value;
		std::cin >> from >> value;

		std::cout << (graph.dfs_findValue(graph.at(from), value) ? "found" : "not") << std::endl;
	}

	return 0; 
}
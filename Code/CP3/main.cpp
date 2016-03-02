#include <iostream>
#include "graph.h"

int main()
{
	Graph graph;

	std::cout << "Size: ";
	int n; std::cin >> n;
	for (int i = 0; i < n; i++)
		graph.insert(new vii);

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
		
		std::cout << (graph.dfs_findVertex(from, find) ? "found" : "not") << std::endl;
	}

	std::cout << "Find cicle: ";
	int t; std::cin >> t;
	while (t--)
	{
		int from;
		std::cin >> from;

		std::cout << (graph.dfs_findCicle(from) ? "has" : "has not") << std::endl;
	}

	return 0; 
}
#include <iostream>
#include "graph.h"

int main()
{
	Graph graph;

	for (int i = 0; i <= 9; i++)
		graph.insert(new Vertex(i));

	graph.connect(0, 1);
	graph.connect(0, 4);
	graph.connect(1, 2);
	graph.connect(2, 3);
	graph.connect(2, 9);
	graph.connect(3, 4);
	graph.connect(4, 5);
	graph.connect(5, 6);
	graph.connect(5, 7);
	graph.connect(7, 8);

	Vertex* found = graph.breadthFirstSearch(8);

	if (found != NULL)
		std::cout << "found " << found->value << std::endl;
	else
		std::cout << "found " << "nothing" << std::endl;

	return 0;
}
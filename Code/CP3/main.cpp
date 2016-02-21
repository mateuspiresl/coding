#include <iostream>

#include "graph.cpp"

int main()
{
	Vertex<int, void>* v = new Vertex<int, void>(10);

	cout << v.value << endl;

	return 0; 
}
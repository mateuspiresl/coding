#include <iostream>
#include <vector>

#include "graph.h"
#include "edge.h"

int Graph::insert(Vertex* vertex)
{
	V.push_back(vertex);
	return V.size() - 1;
}

Vertex* Graph::at(int index) {
	return V[index];
}

int Graph::indexOf(Vertex* vertex)
{
	for (int i = 0; i < V.size(); i++)
		if (V[i] == vertex)
			return i;

	return -1; 
}

void Graph::direct(int from, int to, int weight) {
	at(from)->neighbors.push_back(new Edge(at(to), weight));
}

void Graph::connect(int a, int b, int weight) {
	direct(a, b, weight);
	direct(b, a, weight);
}

bool Graph::dfs_findVertex(Vertex* source, Vertex* vertex)
{
	std::set<Vertex*> visited;
	return dfs_findVertex_(source, vertex, &visited);
}

bool Graph::dfs_findVertex_(Vertex* source, Vertex* vertex, std::set<Vertex*>* visited)
{
	if (source == vertex)
		return true;

	visited->insert(source);

	std::vector<Edge*>::iterator edge = source->neighbors.begin();
	for (; edge != source->neighbors.end(); edge++)
	{
		if (visited->find((*edge)->to) == visited->end())
			if (dfs_findVertex_((*edge)->to, vertex, visited))
				return true;
	}

	return false;
}

bool Graph::dfs_findValue(Vertex* source, int value)
{
	std::set<Vertex*> visited;
	return dfs_findValue_(source, value, &visited);
}

bool Graph::dfs_findValue_(Vertex* source, int value, std::set<Vertex*>* visited)
{
	if (source->value == value)
		return true;

	visited->insert(source);

	std::vector<Edge*>::iterator edge = source->neighbors.begin();
	for (; edge != source->neighbors.end(); edge++)
	{
		if (visited->find((*edge)->to) == visited->end())
			if (dfs_findValue_((*edge)->to, value, visited))
				return true;
	}

	return false;
}
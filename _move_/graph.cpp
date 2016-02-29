#include "graph.h"

int Graph::insert(Vertex* vertex)
{
	V.push_back(vertex);
	return V.size();
}

void Graph::direct(int a, int b) {
	V[a]->neighbors.push_back(V[b]);
}

void Graph::connect(int a, int b)
{
	direct(a, b);
	direct(b, a);
}

Vertex* Graph::depthFirstSearch(int value)
{
	if (V.size() == 0)
		return NULL;

	std::set<Vertex*> visited;
	return dfs(value, &visited, V[0]);
}

Vertex* Graph::dfs(int value, std::set<Vertex*>* visited, Vertex* vertex)
{
	if (vertex->value == value)
		return vertex;

	visited->insert(vertex);

	std::vector<Vertex*>::iterator v = vertex->neighbors.begin();
	for (; v != vertex->neighbors.end(); v++)
	{
		if (visited->find(*v) == visited->end())
		{
			Vertex* found = dfs(value, visited, *v);
			
			if (found != NULL)
				return found;
		}
	}

	return NULL;
}

Vertex* Graph::breadthFirstSearch(int value)
{
	if (V.size() == 0)
		return NULL;

	std::set<Vertex*> enqueued;

	std::queue<Vertex*> unvisited;
	enqueued.insert(V[0]);
	unvisited.push(V[0]);

	while (unvisited.size() > 0)
	{
		Vertex* vertex = unvisited.front();

		if (vertex->value == value)
			return vertex;

		unvisited.pop();

		std::vector<Vertex*>::iterator v = vertex->neighbors.begin();
		for (; v != vertex->neighbors.end(); v++)
		{
			if (enqueued.find(*v) == enqueued.end())
			{
				enqueued.insert(*v);
				unvisited.push(*v);
			}
		}
	}

	return NULL;
}
#include "graph.h"

int Graph::insert(vii* vertex)
{
	V.push_back(vertex);
	return V.size() - 1;
}

vii* Graph::at(int index) {
	return V[index];
}

void Graph::direct(int source, int target, int weight) {
	V[source]->push_back(ii(target, weight));
}

void Graph::connect(int a, int b, int weight) {
	direct(a, b, weight);
	direct(b, a, weight);
}

bool Graph::dfs_connection(int source, int target)
{
	si visited;
	return dfs_connection_(source, target, &visited);
}

bool Graph::dfs_connection_(int source, int target, si* visited)
{
	if (source == target)
		return true;

	visited->insert(source);

	vii::iterator edge = V[source]->begin();
	for (; edge != V[source]->end(); edge++)
	{
		int neighbor = edge->first;

		if (visited->find(neighbor) == visited->end())
			if (dfs_connection_(neighbor, target, visited))
				return true;
	}

	return false;
}

bool Graph::dfs_insideCicle(int index)
{
	si visited;

	vii::iterator edge = V[index]->begin();
	for (; edge != V[index]->end(); edge++)
	{
		int neighbor = edge->first;
		visited.insert(neighbor);

		vii::iterator neiEdge = V[neighbor]->begin();
		for (; neiEdge != V[neighbor]->end(); neiEdge++)
		{
			int neiNeighbor = neiEdge->first;

			if (neiNeighbor != index && visited.find(neiNeighbor) == visited.end())
				if (dfs_connection_(neiNeighbor, index, &visited))
					return true;
		}
	}

	return false;
}

bool Graph::dfs_hasCicle(int index)
{
	si visited;

	vii::iterator edge = V[index]->begin();
	for (; edge != V[index]->end(); edge++)
	{
		int neighbor = edge->first;
		visited.insert(neighbor);

		vii::iterator neiEdge = V[neighbor]->begin();
		for (; neiEdge != V[neighbor]->end(); neiEdge++)
		{
			int neiNeighbor = neiEdge->first;

			if (neiNeighbor != index && visited.find(neiNeighbor) == visited.end())
				if (dfs_connection_(neiNeighbor, index, &visited))
					return true;
		}
	}

	return false;
}
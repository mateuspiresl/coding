#include <iostream>
#include <vector>

#include "vertex.cpp"

template <class Value, class Weight>
class Graph {

	std::vector<Vertex<Value, Weight>*> vertices;
	std::set<Vertex<Value, Weight>*> inserted;

public:

	bool insertVertex(Vertex<Value, Weight>* vertex)
	{
		if (inserted.find(vertex) == inserted.end())
		{
			vertices.insert(vertex);
			inserted.insert(vertex);

			return true;
		}
		else return false;
	}

	bool depthFirstSearch(Value value)
	{
		if (vertices.size() == 0)
			return false;

		if (vertices[0].value == value)
			return true;

		return dfs(value, new set<Vertex<Value>*>, vertices[0]);
	}

private:

	bool dfs(Value value, std::set<Vertex<Value>*>* visited, Vertex<Value> vertex)
	{
		visited.insert(vertex);

		std::vector<Edge<Value, Weight>*>::iterator neighbor = vertex.neighbors.begin();
		for (; neighbor != vertex.neighbors.end(); neighbor++)
		{
			std::vector<Edge<Value, Weight>*>::iterator found = visited.find(*neighbor);

			if (found != visited.end())
			{
				if (neighbor->value == value)
					return true;

				dfs(value, visited, neighbor);
			}
		}
	}

};
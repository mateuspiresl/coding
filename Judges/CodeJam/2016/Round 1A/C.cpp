#include <iostream>

using namespace std;

typedef struct {
	vector<int> edges;
	int value;
} Vertex;


int main()
{
	int t;
	cin >> t;

	for (int ti = 1; ti <= t; ti++)
	{
		int n;
		cin >> n;

		Vertex** graph = malloc(sizeof(Vertex*) * (n + 1));

		for (int i = 1; i <= n; i++)
		{
			int j;
			cin >> j;
			graph[i]->edges.push(j);
			graph[i]->value = 0;
		}

		int** lens = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			lens[i] = new int[n + 1];
			for (int j = 1; j <= n; j++)
				lens[i][j] = 1;
		}

		for (int i = 1; i <= n; i++)
		{
			Vertex* v = graph[i];
			set<int> visited;
			visited.insert(i);

			if (v->value > 1)
				continue;

			vector<int>::iterator it = v->edges.begin();
			for (; it != v->edges.end(); it++)
			{

			}
		}
	}

	return 0;
}
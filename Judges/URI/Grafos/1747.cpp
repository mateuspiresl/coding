#include <iostream>

int main()
{
	int numIslands, numServices;
	cin >> numIslands >> numServices;

	int numCandies[numIslands];
	for (int i = 0; i < numIslands; i++)
		cin >> numCandies[i];

	vector<int> graph[numIslands];

	for (int i = 0; i < numServices; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].insert(b);
		graph[b].insert(a);
	}
}
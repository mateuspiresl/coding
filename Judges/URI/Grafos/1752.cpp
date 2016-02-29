#include <iostream>

int main()
{
	int numRows, numColumns, numProvinces;
	cin >> numRows >> numColumns >> numProvinces;

	int travelCosts[numRows][numColumns];
	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numColumns; j++)
			cin >> travelCosts[i][j];

	int rowTravelLimit[numRows][numColumns];
	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numColumns; j++)
			cin >> lineTravelLimit[i][j];

	int columnTravelLimit[numRows][numColumns];
	for (int i = 0; i < numRows; i++)
		for (int j = 0; j < numColumns; j++)
			cin >> columnTravelLimit[i][j];

	pair<int, int> path[numProvinces];

	for (int i = 0; i < numServices; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].insert(b);
		graph[b].insert(a);
	}
}
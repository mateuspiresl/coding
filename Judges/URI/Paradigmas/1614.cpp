#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int nTests;
	cin >> nTests;

	while (nTests--)
	{
		int nSpots, nStations, days;
		cin >> nSpots >> nStations >> days;

		vector<int*> spots;

		while (nSpots--)
		{
			int* spot = new int[2];
			cin >> spot[0] >> spot[1];
			spots.push_back(spot);
		}

		vector<int> dists;
		double sum(0.0);
		int count(0), average(INT_MAX);

		while (nStations--)
		{
			int* station = new int[2];
			cin >> station[0] >> station[1];

			for (int i = 0; i < spots.size(); i++)
			{
				int dist = abs(station[0] - spots[i][0]) + abs(station[1] - spots[i][1]);

				if (dist < average)
				{
					dists.push_back(dist);

					if (count < days)
					{
						count++;
						sum += (double) dist / days;

						if (count == days)
							average = (int) sum;
					}
				}
			}
		}

		sort(dists.begin(), dists.end());
		int answer(0);

		for (int i = 0; i < days; i++)
			answer += dists[i];

		cout << answer << endl;
	}

	return 0;
}
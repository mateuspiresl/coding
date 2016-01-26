#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int numDays;

	while (cin >> numDays)
	{
		int cost;
		cin >> cost;

		int days[numDays + 1];

		for (int i = 1; i <= numDays; i++)
		{
			cin >> days[i];
			days[i] -= cost;
		}

		int profit[numDays + 1][numDays + 1];

		for (int i = 1; i < numDays; i++)
			profit[i][1] = days[i];

		int bestProfit = 0;

		for (int c = 2; c <= numDays; c++)
		{
			for (int d = c; d <= numDays; d++)
			{
				profit[d][c] = profit[d - 1][c - 1] + days[d];

				if (profit[d][c] > bestProfit)
					bestProfit = profit[d][c];
			}
		}

		cout << bestProfit << endl;
	}

	return 0;
}
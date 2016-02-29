#include <iostream>

using namespace std;

int main()
{
	int numDays;

	while (cin >> numDays)
	{
		int cost;
		cin >> cost;

		int days[numDays];

		for (int i = 0; i < numDays; i++)
		{
			cin >> days[i];
			days[i] -= cost;
		}

		int begin = 0, end = numDays - 1;
		while (days[begin] < 0 && begin < end) begin++;
		while (days[end] < 0 && end >= begin) end--;

		if (begin > end)
			cout << 0 << endl;

		else if (begin == end)
			cout << days[begin] << endl;
		
		else
		{
			int profit[numDays][numDays];
			int bestProfit = 0;

			for (int d = end; d >= begin; d--)
			{
				profit[d][0] = days[d];

				if (profit[d][0] > bestProfit)
					bestProfit = profit[d][0];
			
				for (int c = 1; c < end - d + 1; c++)
				{
					profit[d][c] = days[d] + profit[d + 1][c - 1];

					if (profit[d][c] > bestProfit)
						bestProfit = profit[d][c];
				}
			}

			cout << bestProfit << endl;
		}
	}

	return 0;
}
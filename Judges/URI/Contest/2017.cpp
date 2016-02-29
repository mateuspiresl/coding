#include <iostream>

using namespace std;

typedef long long lli;

int main()
{
	string x, y[5];
	int k;
	cin >> x >> k;

	int xlen = x.length();

	int best = 0;
	int bestDist = k + 1;

	for (int i = 0; i < 5; i++)
	{
		cin >> y[i];

		int dist = 0;

		int j = 0;
		for (; j < xlen; j++)
		{
			if (x[j] != y[i][j])
				dist++;
		}

		if (j < xlen)
			dist += xlen - j;
		
		if (dist < bestDist)
		{
			best = i;
			bestDist = dist;
		}
	}

	if (bestDist > k)
		cout << -1 << endl;
	else
	{
		cout << (best + 1) << endl;
		cout << bestDist << endl;
	}

	return 0;
}
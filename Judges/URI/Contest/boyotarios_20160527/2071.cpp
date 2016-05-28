#include <iostream>

using namespace std;

int mem[1000001];

int main()
{
	mem[0] = 0;

	int ntc; cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> mem[i];
			//mem[i] += mem[i - 1];
		}

		int best = 0;
		int bestFrom = 0, bestTo = 0;

		int q; cin >> q;
		for (int i = 0; i < q; i++)
		{
			int from, to; cin >> from >> to;
			int result = mem[to] - mem[from];

			if (result > best)
			{
				best = result;
				bestFrom = from;
				bestTo = to;
			}

			cout << best << " " << (bestTo - bestFrom) << endl;
		}

	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int instances;
	cin >> instances;

	while (instances--)
	{
		int numTypes, size;
		cin >> numTypes >> size;

		vector<int> types;
		int count[size + 1];
		count[0] = 0;

		while (numTypes--)
		{
			int type;
			cin >> type;

			types.push_back(type);
		}

		for (int len = 1; len <= size; len++)
		{
			count[len] = INT_MAX;

			for (int t = 0; t < types.size(); t++)
			{
				if (types[t] > len) break;

				int c = 1 + count[len - types[t]];

				if (c < count[len])
					count[len] = c;
			}
		}

		cout << count[size] << endl;
	}

	return 0;
}
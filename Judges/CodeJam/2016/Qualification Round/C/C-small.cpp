#include <iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;

	for (int c = 1; c <= cases; c++)
	{
		int mem = 0;

		string pank;
		cin >> pank;

		char last = pank[0];
		int flips = 0;

		for (int i = 1; i < pank.length(); i++)
		{
			if (pank[i] != last)
			{
				flips++;
				last = pank[i];
			}
		}

		if (last == '-')
			flips++;

		cout << "Case #" << c << ": " << flips << endl;
	}

	return 0;
}
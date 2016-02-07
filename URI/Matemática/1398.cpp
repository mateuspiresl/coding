#include <iostream>

using namespace std;

#define MAX 10000
#define NUM 131071
#define LOG 17

int main()
{
	int mods[LOG]; mods[0] = 1;
	int currMod(1);

	for (int i = 1; i < LOG; i++)
	{
		currMod <<= 1;
		currMod %= NUM;
		mods[i] = currMod;
	}

	string bin;

	while (cin >> bin)
	{
		while (bin.at(bin.length() - 1) != '#')
		{
			string end;
			cin >> end;
			bin += end;
		}

		int value(0);
		int logCmp = LOG - 1;
		currMod = 0;

		for (int i = bin.length() - 2; i >= 0; i--)
		{
			if (bin.at(i) == '1')
			{
				value += mods[currMod];
				value %= NUM;
			}

			currMod = currMod == logCmp ? 0 : currMod + 1;
		}

		cout << (value == 0 ? "YES" : "NO") << endl;
	}

	return 0;
}
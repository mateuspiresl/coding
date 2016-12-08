#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int __INT_VAL, __CHAR_VAL;
#define cinInt() (cin >> __INT_VAL, __INT_VAL)
#define cinChar() (cin >> __CHAR_VAL, __CHAR_VAL)

#define each(item, list) (vector<int>::iterator item = list.begin(); item != list.end(); item++)
#define range(i, max) (int i = 0; i < max; i++)

const int Light = 0;
const int Heavy = 1;

int main()
{
	int instances = cinInt();

	for (int instance = 0; instance < instances; instance++)
	{
		int nCoins = cinInt();
		int nWeightings = cinInt();
		bitset<100>* coins = new bitset<100>[2]{ bitset<100>(0x0), bitset<100>(0x0) };

		for (int weighting = 0; weighting < nWeightings; weighting++)
		{
			int nCoinsOnSide = cinInt();
			
			vector<int> leftCoins;
			vector<int> rightCoins;

			for range(coin, nCoinsOnSide)
				leftCoins.push_back(cinInt() - 1);

			for range(coin, nCoinsOnSide)
				rightCoins.push_back(cinInt() - 1);

			string signal; cin >> signal;

			if (signal[0] != '>')
			{
				for each(coin, leftCoins)
					coins[Light][*coin] = true;

				for each(coin, rightCoins)
					coins[Heavy][*coin] = true;
			}
			
			if (signal[0] != '<')
			{
				for each(coin, leftCoins)
					coins[Heavy][*coin] = true;

				for each(coin, rightCoins)
					coins[Light][*coin] = true;
			}

		}

		int ans = 0;

		for (int i = 0; i < 2 && ans != -1; i++)
		{
			for range(coin, nCoins) {
				if (!coins[i][coin]) {
					if (ans != 0)
					{
						if (ans != coin + 1)
						{
							ans = -1;
							break;
						}
					}
					else ans = coin + 1;
				}
			}
		}

		if (ans == -1) ans = 0;

		if (instance > 0) cout << endl;
		cout << ans << endl;
	}
}
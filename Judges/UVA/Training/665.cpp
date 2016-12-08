#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

string TRASH;
int __INT_VAL, __CHAR_VAL;
#define cinInt() (cin >> __INT_VAL, __INT_VAL)
#define cinChar() (cin >> __CHAR_VAL, __CHAR_VAL)

#define each(item, list) (vector<int>::iterator item = list.begin(); item != list.end(); item++)
#define range(i, max) (int i = 0; i < max; i++)

#define dbug if (false) cout

const int Light = 0;
const int Heavy = 1;

int main()
{
	int instances = cinInt();
	dbug << "instances: " << instances << endl;

	for (int instance = 0; instance < instances; instance++)
	{
		int nCoins = cinInt();
		int nWeightings = cinInt();
		bitset<100>* coins = new bitset<100>[2]{ bitset<100>(0x0), bitset<100>(0x0) };

		dbug << "isntance: " << instance << endl;
		dbug << "\tnCoins: " << nCoins << endl;
		dbug << "\tnWeightings: " << nWeightings << endl;

		dbug << "\tcoins[Light]:";
		for range(coin, nCoins)
			dbug << " " << coins[Light][coin];
		dbug << endl;

		dbug << "\tcoins[Heavy]:";
		for range(coin, nCoins)
			dbug << " " << coins[Heavy][coin];
		dbug << endl;

		for (int weighting = 0; weighting < nWeightings; weighting++)
		{
			int nCoinsOnSide = cinInt();
			dbug << "\t\tnCoinsOnSide: " << nCoinsOnSide << endl;
			
			vector<int> leftCoins;
			vector<int> rightCoins;

			dbug << "\t\tleftCoins:";
			for range(coin, nCoinsOnSide) {
				leftCoins.push_back(cinInt() - 1);
				dbug << " " << *(leftCoins.rbegin());
			}
			dbug << endl;

			dbug << "\t\trightCoins:";
			for range(coin, nCoinsOnSide) {
				rightCoins.push_back(cinInt() - 1);
				dbug << " " << *(rightCoins.rbegin());
			}
			dbug << endl;

			string signal; cin >> signal;
			dbug << "\t\tsignal: '" << signal << "'" << endl;

			if (signal[0] != '>')
			{
				for each(coin, leftCoins)
					coins[Light][*coin] = true;

				dbug << "\t\t!> coins[Light]:";
				for range(coin, nCoins)
					dbug << " " << coins[Light][coin];
				dbug << endl;

				for each(coin, rightCoins)
					coins[Heavy][*coin] = true;

				dbug << "\t\t!> coins[Heavy]:";
				for range(coin, nCoins)
					dbug << " " << coins[Heavy][coin];
				dbug << endl;
			}
			
			if (signal[0] != '<')
			{
				for each(coin, leftCoins)
					coins[Heavy][*coin] = true;

				dbug << "\t\t!< coins[Heavy]:";
				for range(coin, nCoins)
					dbug << " " << coins[Heavy][coin];
				dbug << endl;

				for each(coin, rightCoins)
					coins[Light][*coin] = true;

				dbug << "\t\t!< coins[Light]:";
				for range(coin, nCoins)
					dbug << " " << coins[Light][coin];
				dbug << endl;
			}

			dbug << endl;
		}

		int ans = 0;

		for (int i = 0; i < 2 && ans != -1; i++)
		{
			for range(coin, nCoins) {
				dbug << "on " << coin << endl;
				if (!coins[i][coin]) {
					if (ans != 0)
					{
						dbug << "for ans " << ans << endl;
						if (ans != coin + 1)
						{
							dbug << "Happened: n = -1" << endl;
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
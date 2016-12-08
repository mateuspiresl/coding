#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int __INT_VAL, __CHAR_VAL;
#define cinInt() (cin >> __INT_VAL, __INT_VAL)
#define cinChar() (cin >> __CHAR_VAL, __CHAR_VAL)

// #define each(item, list) (vector<int>::iterator item = list.begin(); item != list.end(); item++)
// #define in ,

const int Light = 0;
const int Heavy = 0;

int main()
{
	int instances = cinInt();
	cout << "instances: " << instances << endl;

	for (int instance = 0; instance < instances; instance++)
	{
		int nCoins = cinInt();
		int nWeightings = cinInt();
		bitset<100>* coins = new bitset<100>[2];
		// coins[Left] = bitset<100>(0x0);
		// coins[Right] = bitset<100>(0x0);

		cout << "nCoins: " << nCoins << endl;
		cout << "nWeightings: " << nWeightings << endl;

		for (int weighting = 0; weighting < nWeightings; weighting++)
		{
			int nCoinsOnSide = cinInt();
			vector<int> leftCoins;
			vector<int> rightCoins;

			for (int coin = 0; coin < nCoinsOnSide; coin++)
				leftCoins.push_back(cinInt());

			for (int coin = 0; coin < nCoinsOnSide; coin++)
				rightCoins.push_back(cinInt());

			char signal = cinChar();

			/*if (signal == '<')
			{
				for each(coin, leftCoins)
					coins[Light][coin] = true;
				for each(coin, rightCoins)
					coins[Heavy][coin] = true;
			}
			else
			{
				for each(coin, rightCoins)
					coins[Light][coin] = true;
				for each(coin, leftCoins)
					coins[Heavy][coin] = true;
			}*/
		}
	}
}
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int tc = 1; tc <= n; tc++)
	{
		string s;
		cin >> s;

		int alpha[255];
		memset (alpha, 0, sizeof(alpha));

		int number[10];
		memset (number, 0, sizeof(number));

		for (int i = 0; i < s.size(); i++)
			alpha[s[i]]++;
		
		number[0] = alpha['Z'];
		alpha['E'] -= alpha['Z'];
		alpha['R'] -= alpha['Z'];
		alpha['O'] -= alpha['Z'];
		alpha['Z'] = 0;

		number[2] = alpha['W'];
		alpha['T'] -= alpha['W'];
		alpha['O'] -= alpha['W'];
		alpha['W'] = 0;
		
		number[4] = alpha['U'];
		alpha['F'] -= alpha['U'];
		alpha['O'] -= alpha['U'];
		alpha['R'] -= alpha['U'];
		alpha['U'] = 0;

		number[6] = alpha['X'];
		alpha['S'] -= alpha['X'];
		alpha['I'] -= alpha['X'];
		alpha['X'] = 0;
		
		number[8] = alpha['G'];
		alpha['E'] -= alpha['G'];
		alpha['I'] -= alpha['G'];
		alpha['H'] -= alpha['G'];
		alpha['T'] -= alpha['G'];
		alpha['G'] = 0;


		number[1] = alpha['O'];
		alpha['N'] -= alpha['O'];
		alpha['E'] -= alpha['O'];
		alpha['O'] = 0;

		number[3] = alpha['T'];
		alpha['H'] -= alpha['W'];
		alpha['R'] -= alpha['W'];
		alpha['E'] -= 2 * alpha['W'];
		alpha['T'] = 0;

		number[5] = alpha['F'];
		alpha['I'] -= alpha['F'];
		alpha['V'] -= alpha['F'];
		alpha['E'] -= alpha['F'];
		alpha['F'] = 0;

		number[7] = alpha['S'];
		alpha['E'] -= 2 * alpha['S'];
		alpha['V'] -= alpha['S'];
		alpha['N'] -= alpha['S'];
		alpha['S'] = 0;


		number[9] = alpha['I'];


		cout << "Case #" << tc << ": ";
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < number[i]; j++)
				cout << i;
		cout << endl;
	}

	return 0;
}
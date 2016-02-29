#include <iostream>

using namespace std;

int main()
{
	string number;
	cin >> number;

	int ocurr[10] = {0};
	
	string::iterator c = number.begin();
	int n = *c - '0';

	while (ocurr[n] < 2 && c != number.end())
	{
		ocurr[n]++;
		c++;
		n = *c - '0';
	}

	if (c != number.end())
	{
		while (n > 0 && ocurr[n] == 2)
		{
			(*c)--;
			n--;
		}

		if (n == 0 && ocurr[0] == 2 && )
		{
			do
			{
				c--;
				n = *c - '0';
				ocurr[n]--;
			}
			while (n == 0 && c != number.begin());

			do
			{
				(*c)--;
				n--;
			}
			while (n > 0 && ocurr[n] == 2);
		}

		if (c != number.begin())
			ocurr[*c - '0']++;

		int greater(9);

		for (c++; c != number.end(); c++)
		{
			while (ocurr[greater] == 2)
				greater--;

			*c = greater + '0';
			ocurr[greater]++;
		}
	}

	const char* str = number.c_str();
	cout << (str[0] == '0' ? str + 1 : str) << endl;

	return 0;
}
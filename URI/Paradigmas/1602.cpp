#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 10e6;

bool prime[MAX + 1];
int divisors[MAX + 1];

int main()
{
	memset(&prime, true, sizeof(bool) * (MAX + 1));
	memset(&divisors, 0, sizeof(int) * (MAX + 1));

	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i])
		{
			divisors[i] = 2;

			for (int j = i + i; j <= MAX; j += i)
			{
				divisors[j] += 1 + divisors[j / i];
				prime[j] = false;
			}
		}
	}

	int hiperprimes = 0;

	for (int i = 2; i <= MAX; i++)
		divisors[i] = prime[divisors[i]] ? ++hiperprimes : hiperprimes;

	int n;
	while (cin >> n)
		cout << divisors[n] << endl;

	return 0;
}
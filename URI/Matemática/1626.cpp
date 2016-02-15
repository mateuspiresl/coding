#include <iostream>

using namespace std;

const int MAX = 10e5;

int main()
{
	bool primes[MAX + 1];
	//set<int> divisors[MAX + 1];

	memset(primes, true, MAX);

	//divisors[1].insert(1);

	for (int i = 2; i <= MAX; i++)
	{
		//divisors[i].insert(1);

		if (primes[i])
		{
			for (int j = i + i; i < MAX; i += i)
			{
				primes[j] = false;
				//divisors[j].insert(i);
			}
		}
	}

	set<int> numbers;
	set<long long> products;

	int count[MAX + 1];
	count[0] = 0;

	for (int i = 1; i <= MAX; i++)
	{
		set<int>::iterator it;
		for (it = numbers.begin(); it != numbers.end(); it++)
		{
			long long p = *it * i;

			if (products)
		}

		count[i] = count[i - 1] + primes[i];

		numbers.insert(i);
	}

	int fact[MAX + 1];
	fact[0] = 1;

	for (int i = 1; i <= MAX; i++)
		fact[i] = fact[i - 1] * i;

	int n;

	while (cin >> n)
		cout << 

	return 0;
}
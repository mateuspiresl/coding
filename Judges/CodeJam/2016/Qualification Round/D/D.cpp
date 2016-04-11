#include <bits/stdc++.h>

using namespace std;

int isNotPrime(int n)
{
	if (n % 2 == 0)
		return 2;

	int sq = sqrt(n);

	for (int i = 3; i < sq; i += 2)
		if (n % i == 0)
			return i;

	return 0;
}

int get_num(string bs, int base, int length) {
	int _return = 0;
	for(int i = length - 1; i >= 0; i--) {
		if(bs[i] == '1')
			_return += pow(base, i);
	}
	return _return;
}

int main()
{
	int cases, n, j;
	cin >> cases >> n >> j;

	int from = pow(2, n - 1) + 1;
	int to = pow(2, n) - 1;


	cout << "Case #1:" << endl;

	for (int number = from; from <= to; number += 2)
	{
		int divisors[11];

		bitset<16> bs(number);
		string bss = bs.to_string();
		istringstream iss(bss);

		int b;
		for (b = 2; b <= 10; b++)
		{
			int ver = get_num(bss, b, n);
			
			if ( ! (divisors[b] = isNotPrime(ver)))
				break;
		}

		if (b == 11)
		{
			cout << bss;

			for (int i = 2; i <= 10; i++)
				cout << " " << divisors[i];

			cout << endl;
		}
	}

	return 0;
}
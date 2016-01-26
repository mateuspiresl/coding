#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull countCalls(ull, ull);

int main()
{
	int tc = 0;

	for (int i = 0; i < 100; i++)
		cout << countCalls(i, 9999999) << endl;

	while (false)//(++tc)
	{
		ull num;
		int base;
		cin >> num >> base;

		if (num == 0 && base == 0)
			break;

		ull calls = countCalls(num, base);

		cout << "Case " << tc << ": " << num << " " << base << " " << calls << endl;
	}

	return 0;
}

ull countCalls(ull number, ull base)
{
	ull a = 1ull,
		b = 1ull;

	for (ull i = 2ull; i <= number; i++)
	{
		ull r = (a + b + 1ull) % base;
		a = b;
		b = r;
	}

	return b;
}
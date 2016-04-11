#include <iostream>

using namespace std;

void check(int* mem, int num);

const int SLEEP = 0x3FF;

int main()
{
	int cases;
	cin >> cases;

	for (int c = 1; c <= cases; c++)
	{
		int mem = 0;

		int num;
		cin >> num;

		cout << "Case #" << c << ": ";

		if (num > 0)
		{
			int sum = 0;

			while (mem < SLEEP)
				check(&mem, sum += num);

			cout << sum << endl;
		}
		else cout << "INSOMNIA" << endl;
	}
}

void check(int* mem, int num)
{
	if (num == 0) return;

	*mem |= 1 << (num % 10);
	check(mem, num / 10);
}
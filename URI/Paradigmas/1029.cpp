#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> fibs;
	fibs.push_back(0);
	fibs.push_back(1);

	vector<int> calls;
	calls.push_back(0);
	calls.push_back(0);

	while (n--)
	{
		int arg;
		cin >> arg;

		if (fibs.size() < arg)
			for (int i = fibs.size(); i <= arg; i++)
		{
			fibs.push_back(fibs[i - 2] + fibs[i - 1]);
			calls.push_back(calls[i - 2] + calls[i - 1] + 2);
		}

		cout << "fib(" << arg << ") = " << calls[arg] << " calls = " << fibs[arg] << endl;
	}

	return 0;
}
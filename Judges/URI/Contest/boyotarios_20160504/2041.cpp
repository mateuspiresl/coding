#include <bits/stdc++.h>

using namespace std;

string next(string number)
{
	int size = number.size();
	char num = number[0];
	int x = 0;

	stringstream ss;

	int i;
	for (i = 1; i < size; i++)
	{
		if (number[i] != num)
		{
			ss << (i - x) << num;
			num = number[i];
			x = i;
		}
	}

	ss << (i - x) << num;

	return ss.str();
}

int main()
{
	string numbers[40];
	numbers[0] = "3";
	int done = 1;

	int n;
	while (cin >> n)
	{
		while (done < n)
		{
			numbers[done] = next(numbers[done - 1]);
			done++;
		}

		cout << numbers[n - 1] << endl;
	}

	return 0;
}
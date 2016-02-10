#include <iostream>
#include <sstream>

//#define pl(_s) cout << _s << endl;

using namespace std;

int main()
{
	int n, d;

	while (true)
	{
		cin >> n >> d;

		if ( ! n && ! d)
			break;

		string number;
		cin >> number;

		int answerSize(0);
		int answerMax = n - d;

		int greater(0);
		int i(0);

		while (i < n && answerSize < answerMax)
		{
			int j = d + answerSize;

			for (i = greater + 1; i <= j; i++)
				if (number[i] > number[greater])
					greater = i;

			cout << number[greater];
			answerSize++;
			greater++;
		}

		cout << endl;
	}

	return 0;
}
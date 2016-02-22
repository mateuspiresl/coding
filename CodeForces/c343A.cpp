#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* colChoc = new int[n];
	memset(colChoc, 0, n * sizeof(int));

	unsigned long long happiness = 0;
	char choc;

	for (int i = 0; i < n; i++) {
		int lineChoc = 0;

		for (int j = 0; j < n; j++) {
			cin >> choc;

			if (choc == 'C')
			{
				colChoc[j]++;
				lineChoc++;
			}
		}

		lineChoc--;

		if (lineChoc > 0)
			happiness += (lineChoc * (1 + lineChoc)) / 2;
	}

	for (int i = 0; i < n; i++)
	{
		colChoc[i]--;

		if (colChoc > 0)
			happiness += (colChoc[i] * (1 + colChoc[i])) / 2;
	}

	cout << happiness << endl;

	return 0;
}
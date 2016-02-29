#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int diff = n - k + 1;

	int right = n * n;
	int left = right - diff * n;

	int greatest = right - n + k;
	int lowest = greatest - (n - 1) * diff;
	// P.A.
	cout << ((n * (lowest + greatest)) / 2) << endl;

	for (int row = 0; row < n; row++)
	{
		left -= k - 1;
		int v = left + 1;

		for (int col = k - 2; col >= 0; col--)
			cout << v++ << " ";

		right -= n - k + 1;
		v = right + 1;

		for (int col = n - 1; col >= k - 1; col--)
			cout << v++ << " ";

		cout << endl;
	}

	return 0;
}
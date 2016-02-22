#include <bits/stdc++.h>

using namespace std;

int min(int a, int b) { return a <= b ? a : b; }

int main()
{
	int nFriends;
	cin >> nFriends;

	// 0: male
	// 1: female
	// 358 days:
	//		366 + 1 (367) to access 1 to 366 by index and
	// 		367 + 1 (368) to do not overflow when do "to + 1" at line 22
	//			~ if "to" equals 366, it will access days[x][367]!
	int days[2][368] = {0};

	for (int i = 0; i < nFriends; i++)
	{
		char gender;
		int from, to;
		cin >> gender >> from >> to;

		days[gender == 'M'][from]++;

		// subtract 1 person from the next day
		// at day "to", the person can still be counted, but can not be at day "to + 1"
		days[gender == 'M'][to + 1]--;
	}

	int friendsCounter[2] = {0};
	int friendsComming = 0;

	for (int i = 1; i <= 366; i++)
	{
		friendsCounter[0] += days[0][i];
		friendsCounter[1] += days[1][i];

		int sum = min(friendsCounter[0], friendsCounter[1]);
		sum <<= 1;

		if (sum > friendsComming)
			friendsComming = sum;
	}

	cout << friendsComming << endl;

	return 0;
}
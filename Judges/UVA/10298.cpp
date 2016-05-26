#include <bits/stdc++.h>

using namespace std;

int main()
{
	while (true)
	{
		string s;
		cin >> s;

		if (s.length() == 1 && s[0] == '.')
			break;

		int len = 1;
		int max = s.length() >> 1;

		for (; len <= max; len++)
		{
			if (s.length() % len != 0)
				continue;

			int comp = len;

			for (; comp < s.length(); comp++)
				if (s[comp] != s[comp % len])
					break;

			if (comp == s.length())
			{
				cout << (s.length() / len) << endl;
				break;
			}
		}

		if (len > max)
			cout << 1 << endl;
	}

	return 0;
}
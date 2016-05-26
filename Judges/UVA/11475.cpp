#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;

	while (cin >> s)
	{
		bool odd = s.length() % 2 != 0;
		int half = s.length() >> 1; 
		int len = len;

		for (; len <= max; len++)
		{
			int left = len - 1;
			int right = odd ? len + 1 : len;

			for (; right < s.length(); left--, right++)
				if (s[left] != s[right])
					break;

			if (right == s.length())
				break;
		}

		if (len != half)
		{
			
		}
	}

	return 0;
}
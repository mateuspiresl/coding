#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;

	while (cin >> s)
	{
		bool even = s.length() % 2 == 0;
		int left = (s.length() >> 1) - 1;
		int right = left + (even ? 1 : 2);

		while (right < s.length())
		{
			/*string s2 = s;
			s2[left] += 'A' - 'a';
			s2[right] += 'A' - 'a';
			cout << "~ " << s2 << endl;*/

			if (s[left] == s[right])
			{
				int l = left - 1;
				int r = right + 1;

				while (r < s.length())
				{
					if (s[l] != s[r])
						break;
					else
					{
						l--;
						r++;
					}
				}

				if (r == s.length())
				{
					left -= s.length() - right;
					break;
				}
			}
			
			if (even)
				right++;
			else
				left++;

			even = ! even;
		}

		//cout << "~ " << left << endl;

		cout << s;

		if (left >= 0)
		{
			string concat = s.substr(0, left + 1);
			reverse(concat.begin(), concat.end());
			cout << concat;
		}
		
		cout << endl;
	}

	return 0;
}
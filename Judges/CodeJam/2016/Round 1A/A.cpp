#include <iostream>
#include <list>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int ti = 1; ti <= t; ti++)
	{
		string s;
		cin >> s;

		list<char> r;
		r.push_front(s[0]);

		int size = s.size();
		for (int i = 1; i < size; i++)
		{
			if (s[i] >= r.front())
				r.push_front(s[i]);
			else
				r.push_back(s[i]);
		}

		list<char>::iterator it = r.begin();
		cout << "Case #" << ti << ": ";
		for (; it != r.end(); it++)
			cout << *it;
		cout << endl;
	}

	return 0;
}
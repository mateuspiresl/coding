#include <iostream>

using namespace std;

int main()
{
	string str, sub;
	cin >> str >> sub;

	int iStr(0), iSub(0), count(0);

	for (; iStr < str.length(); iStr++)
	{
		if (str[iStr] == sub[iSub])
		{
			if (++iSub == sub.length())
			{
				iSub = 0;
				count++;
			}
		}
		else iSub = 0;
	}

	cout << count;

	return 0;
}
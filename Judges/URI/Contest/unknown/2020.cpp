#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int getValue(string::iterator* c, string::iterator end)
{
	while ((**c < '1' || **c > '9') && *c != end)
		(*c)++;
	
	if (*c == end)
		return -1;

	int value = **c - '0';
	(*c)++;

	if (*c != end && **c >= '0' && **c <= '9')
	{
		value *= 10;
		value += **c - '0';
		(*c)++;
	}

	return value;
}

int main()
{
	int x;
	int counter = 0;

	while (cin >> x) {
		counter++;

		vector<int> letters;
		vector<int> numbers;
		set<string> made;

		for (int n = 0; n < 26; n++)
		{
			letters.push_back(n);
			numbers.push_back(n);
		}

		while (x--)
		{
			string codes;
			while (codes.length() == 0)
				getline(cin, codes);

			stringstream ss;

			for (string::iterator c = codes.begin(); c != codes.end();)
			{
				int v = getValue(&c, codes.end()) - 1;

				if (v < 26)
				{
					int value = numbers[v];
					ss << (char) (letters[value] + 'A');

					numbers.erase(numbers.begin() + v);
					numbers.push_back(value);

					v = value;
					value = letters[v];

					letters.erase(letters.begin() + v);
					letters.push_back(value);
				}
				else ss << ' ';
			}

			made.insert(ss.str());
		}

		if (counter > 1) cout << endl;
		cout << "LISTA#" << counter << ":" << endl;

		set<string>::iterator it = made.begin();
		while (it != made.end())
		{
			cout << *it << endl;
			it++;
		}
	}

	return 0;
}
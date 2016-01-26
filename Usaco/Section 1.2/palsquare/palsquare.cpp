/*
ID: mateusp1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char REPRESENTATIONS[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'
};

string convert(int base, int value);
bool palindrome(string value);

int main()
{
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	
	int base;
	fin >> base;

	for (int i = 1; i <= 300; i++)
	{
		string number = convert(base, i * i);

		if (palindrome(number))
			fout << convert(base, i) << " " << number << "\n";
	}

	return 0;
}

string convert(int base, int value)
{
	string result = "";

	while (value > 0)
	{
		result = REPRESENTATIONS[value % base] + result;
		value /= base;;
	}

	return result;
}

bool palindrome(string value)
{
	string::iterator begin = value.begin();
	string::iterator end = value.end() - 1;

	while (begin < end)
		if (*begin++ != *end--)
			return false;

	return true;
}
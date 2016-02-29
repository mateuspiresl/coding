/*
ID: mateusp1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char REPRESENTATIONS[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

string convert(int base, int value);
bool palindrome(string value);

int main()
{
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	
	int count, number;
	fin >> count >> number;

	for (number++; count > 0; number++)
	{
		int pals = 0;

		for (int base = 2; base <= 10 && pals < 2; base++)
		{
			if (palindrome(convert(base, number)) && ++pals == 2)
			{
				fout << number << "\n";
				count--;
			}
		}
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
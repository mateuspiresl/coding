/*
ID: mateusp1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const int REPRESENTATIONS[] = {
	"1", "2", "3", "4", "5", "6", "7", "8", "9",
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"
};

string convert(int base, string value);
bool palindrome(string value);

int main()
{
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	
	int base;
	fin >> base;

	for (int i = 1; i <= 300; i++)
	{
		
	}

	return 0;
}

string convert(int base, string value)
{
	
}

bool palindrome(string value)
{
	
}
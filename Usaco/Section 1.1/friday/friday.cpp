/*
ID: mateusp1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int WEEK = 7;
const int WEEK_START = 2;
const int YEAR_START = 1900;
const int YEAR = 12;
const int MONTHS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");

	int n;
	fin >> n;

	int week[7];
	int end = YEAR_START + n - 1;
	int day = 1;
	int weekDay = WEEK_START;

	for (int y = YEAR_START; y <= end; y++)
	{
		for (int)

		day = 13;
		week[day / WEEK + day % WEEK]++;

		day = 31 + 13;
		week[day / WEEK + day % WEEK]++;

		day = 31;

		if (y % 100 == 0 && y % 400 == 0)
			day += 29;

		else if (y % 100 > 0 && y % 4 == 0)
			day += 29;
		
		else
			day += 28;

		

	}




	int days = 0;

	for (int y = YEAR_START; y <= end; y++)
	{
		if (y % 100 == 0 && y % 400 == 0)
			days += 366;

		else if (y % 100 > 0 && y % 4 == 0)
			days += 366;
		
		else
			days += 365;
	}

	int all = days / 7;
	int mod = days % 7;

	for (int d = WEEK_START; d < WEEK; d++)
		week[d] = all + (mod-- > 0 ? 1 : 0);

	for (int d = 0; d < WEEK_START; d++)
		week[d] = all + (mod-- > 0 ? 1 : 0);

	for (int d = 0; d < WEEK - 1; d++)
		fout << week[d] << " ";

	fout << week[WEEK - 1] << "\n";

	return 0;
}

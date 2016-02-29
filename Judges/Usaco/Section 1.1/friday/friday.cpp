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

int update(int week[], int day) {
	week[(WEEK_START + day + 11) % WEEK]++;
}

int main()
{
	ofstream fout ("friday.out");
	ifstream fin ("friday.in");

	int n;
	fin >> n;

	int week[WEEK] = {0};
	int end = YEAR_START + n - 1;
	int day = 1;

	for (int y = YEAR_START; y <= end; y++)
	{
		update(week, day);
		day += MONTHS[0];

		update(week, day);
		day += MONTHS[1];

		if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))
			day++;

		for (int m = 2; m < YEAR; m++)
		{
			update(week, day);
			day += MONTHS[m];
		}
	}

	for (int d = 0; d < WEEK - 1; d++)
		fout << week[d] << " ";

	fout << week[WEEK - 1] << "\n";

	return 0;
}

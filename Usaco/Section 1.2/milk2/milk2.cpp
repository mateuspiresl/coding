/*
ID: mateusp1
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ofstream fout ("milk2.out");
	ifstream fin ("milk2.in");

	int n;
	fin >> n;

	int open = 0;
	int start = 0, end = 0;
	int longestOpen = 0, longestClosed = 0;

	map<int, int> times;
	int startTime, endTime;

	while (n--)
	{
		fin >> startTime >> endTime;

		if (times.find(startTime) == times.end() || times.find(startTime)->second < endTime)
			times.insert(pair<int, int>(startTime, endTime));
	}

	for (std::map<int, int>::iterator it = times.begin(); it != times.end(); it++)
	{
		startTime = it->first;
		endTime = it->second;

		if (startTime > end)
		{
			int time = end - start;
			if (time > longestOpen)
				longestOpen = time;

			time = startTime - end;
			if (end > 0 && time > longestClosed)
				longestClosed = time;

			start = startTime;
			end = endTime;
		}

		else if (end < endTime)
			end = endTime;
	}

	int time = end - start;
	if (time > longestOpen)
		longestOpen = time;

	fout << longestOpen << " " << longestClosed << "\n";

	return 0;
}
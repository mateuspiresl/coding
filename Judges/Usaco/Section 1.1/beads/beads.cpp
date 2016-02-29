/*
ID: mateusp1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char BLUE = 'b';
const char RED = 'r';
const char WHITE = 'w';
const char INVALID = ' ';

int count(char bead)
{
	static int white = 0, colored = 0;
	static char color = INVALID;

	// Reset
	if (bead == INVALID)
	{
		white = 0;
		colored = 0;
		color = INVALID;
	}
	else if (bead == WHITE)
	{
		white++;
	}
	else if (bead == color)
	{
		colored += white + 1;
		white = 0;
	}
	else
	{
		color = bead;
		colored = white + 1;
		white = 0;
	}

	return colored + white;
}

int main()
{
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");

	int n;
	fin >> n;

	char beads[n + 1];
	fin >> beads;

	int N = n * 2;
	int left[N];
	int points[N];
	
	int c = 0;

	for (int i = 0; i < N; i++)
	{
		left[i] = c;
		c = count(beads[i % n]);
	}

	c = 0;
	count(INVALID);

	for (int i = N - 1; i >= 0; i--)
	{
		c = count(beads[i % n]);
		points[i] = left[i] + c;
	}

	for (int i = 1; i < N - 1; i++)
		if (c < points[i])
			c = points[i];

	fout << (c > n ? n : c) << "\n";

	return 0;
}
/*
ID: mateusp1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");

	char comet[8], group[8];
	fin >> comet >> group;

	int cometCode = 1;
	for (int i = 0; i < 6 && comet[i] != '\n' && comet[i] != '\0'; i++)
		cometCode *= comet[i] - 'A' + 1;

	int groupCode = 1;
	for (int i = 0; i < 6 && group[i] != '\n' && group[i] != '\0'; i++)
		groupCode *= group[i] - 'A' + 1;

	fout << (cometCode % 47 == groupCode % 47 ? "GO" : "STAY") << "\n";

	return 0;
}

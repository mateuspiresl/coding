/*
ID: mateusp1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 10

typedef bool pattern[MAX][MAX];

void read(ifstream &fin, pattern patt, int n);
void printPattern(pattern patt, int n);
bool equals(pattern a, pattern b, int n);
void reflect(pattern original, pattern transformed, int n);
void rot90(pattern original, pattern transformed, int n);

int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");

	pattern original, transformed, result, combination;

	int n;
	fin >> n;

	read(fin, original, n);
	read(fin, transformed, n);

	rot90(original, result, n);
	if (equals(result, transformed, n))
	{
		fout << 1 << "\n";
		return 0;
	}

	rot90(result, combination, n);
	if (equals(combination, transformed, n))
	{
		fout << 2 << "\n";
		return 0;
	}

	rot90(combination, result, n);
	if (equals(result, transformed, n))
	{
		fout << 3 << "\n";
		return 0;
	}

	reflect(original, result, n);
	if (equals(result, transformed, n))
	{
		fout << 4 << "\n";
		return 0;
	}

	rot90(result, combination, n);
	if (equals(combination, transformed, n))
	{
		fout << 5 << "\n";
		return 0;
	}

	rot90(combination, result, n);
	if (equals(result, transformed, n))
	{
		fout << 5 << "\n";
		return 0;
	}

	rot90(result, combination, n);
	if (equals(combination, transformed, n))
	{
		fout << 5 << "\n";
		return 0;
	}

	if (equals(original, transformed, n))
	{
		fout << 6 << "\n";
		return 0;
	}

	fout << 7 << "\n";
	return 0;
}

void read(ifstream &fin, pattern patt, int n)
{
	for (int line = 0; line < n; line++)
		for (int column = 0; column < n; column++)
	{
		char tile;
		fin >> tile;

		patt[line][column] = tile == '@';
	}
}

void printPattern(pattern patt, int n)
{
	for (int line = 0; line < n; line++)
	{
		for (int column = 0; column < n; column++)
			cout << (patt[line][column] ? '@' : '-');

		cout << endl;
	}
}

bool equals(pattern a, pattern b, int n)
{
	for (int line = 0; line < n; line++)
		for (int column = 0; column < n; column++)
			if (a[column][line] != b[column][line])
				return false;

	return true;
}

void rot90(pattern in, pattern out, int n)
{
	for (int inLine = 0, outLine = n - 1; inLine < n; inLine++, outLine--)
		for (int column = 0; column < n; column++)
			out[column][outLine] = in[inLine][column];
}

void reflect(pattern in, pattern out, int n)
{
	for (int line = 0; line < n; line++)
		for (int inColumn = 0, outColumn = n - 1; inColumn < n; inColumn++, outColumn--)
			out[line][outColumn] = in[line][inColumn];
}
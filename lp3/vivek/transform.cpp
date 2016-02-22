/*
ID: mateusp1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read(ifstream &fin, pattern patt, int n);
void printPattern(pattern patt, int n);
bool equals(pattern a, pattern b, int n);
void reflect(pattern original, pattern transformed, int n);
void rot90(pattern original, pattern transformed, int n);

int main()
{
	int n;
	fin >> n;

	int matrix[n][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	rot90(original, result, n);
	if (equals(result, transformed, n))
	{
		fout << 1 << "\n";
		return 0;
	}

	fout << 7 << "\n";
	return 0;
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

void rot90(int** matrix, int n)
{
	int column[n];

	for (int i = 0; i < n; i++)
		column[i] = matrix[i][0];

	for (int inLine = 0, outLine = n - 1; inLine < n; inLine++, outLine--)
		for (int column = 0; column < n; column++)
			out[column][outLine] = in[inLine][column];
}
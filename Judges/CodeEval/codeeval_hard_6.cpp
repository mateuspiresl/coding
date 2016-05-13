#include <bits/stdc++.h>

using namespace std;

#define COUNT 0
#define DIR 1
#define DIAG 0
#define TOP 1
#define LEFT 2

void lcs_seq_printCount(const string a, const string b, const char mem[51][51][2])
{
	for (int ai = 0; ai <= a.size(); ai++) {
		for (int bi = 0; bi <= b.size(); bi++) {
			if (ai == 0 && bi == 0)
				cout << "  ";
			else if (ai == 0 && bi > 0)
				cout << b[bi - 1] << " ";
			else if (bi == 0 && ai > 0)
				cout << a[ai - 1] << " ";
			else
				cout << ((int) mem[ai][bi][COUNT]) << " ";
		}
		cout << endl;
	}
}

void lcs_seq_printDir(const string a, const string b, const char mem[51][51][2])
{
	for (int ai = 0; ai <= a.size(); ai++) {
		for (int bi = 0; bi <= b.size(); bi++) {
			if (ai == 0 && bi == 0)
				cout << "  ";
			else if (ai == 0 && bi > 0)
				cout << b[bi - 1] << " ";
			else if (bi == 0 && ai > 0)
				cout << a[ai - 1] << " ";
			else
				cout << ((int) mem[ai][bi][DIR]) << " ";
		}
		cout << endl;
	}
}

int lcs_seq(const string a, const string b, char mem[51][51][2])
{
	for (int bi = 0; bi <= b.size(); bi++)
		mem[0][bi][COUNT] = 0;

	for (int ai = 1; ai <= a.size(); ai++) {
		mem[ai][0][COUNT] = 0;

		for (int bi = 1; bi <= b.size(); bi++)
		{
			if (a[ai - 1] == b[bi - 1])
			{
				mem[ai][bi][COUNT] = mem[ai - 1][bi - 1][COUNT] + 1;
				mem[ai][bi][DIR] = DIAG;
			}
			else if (mem[ai - 1][bi][COUNT] >= mem[ai][bi - 1][COUNT])
			{
				mem[ai][bi][COUNT] = mem[ai - 1][bi][COUNT];
				mem[ai][bi][DIR] = TOP;
			}
			else
			{
				mem[ai][bi][COUNT] = mem[ai][bi - 1][COUNT];
				mem[ai][bi][DIR] = LEFT;
			}
		}
	}

	return mem[a.size()][b.size()][COUNT];
}

string lcs_seq_makeString(const string a, const string b, const char mem[51][51][2])
{
	stringstream ss;
	int ai = a.size(), bi = b.size();

	while (mem[ai][bi][COUNT] > 0)
	{
		if (mem[ai][bi][DIR] == DIAG)
		{
			ss << b[bi - 1];
			ai--;
			bi--;
		}
		else if (mem[ai][bi][DIR] == TOP)
			ai--;
		else
			bi--;
	}

	string result = ss.str();
	reverse(result.begin(), result.end());
	return result;
}

int main(int argc, char* argv[])
{
	ifstream file(argv[1]);
	string line;

	char mem[51][51][2];

	if (file.is_open())
	{
		while (getline(file, line))
		{
			int ai = 0;

			while (line[ai] != ';') ai++;

			string a = line.substr(0, ai);
			string b = line.substr(ai + 1, line.size() - ai - 1);

			lcs_seq(a, b, mem);
			cout << lcs_seq_makeString(a, b, mem) << endl;
		}

		file.close();
	}
	else cout << "Unable to open file!" << endl;

	return 0;
}
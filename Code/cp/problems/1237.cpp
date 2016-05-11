#include <bits/stdc++.h>

using namespace std;

int lcs_str_diag(string a, string b, int bi)
{
	int mem[2] = { 0, 0 };
	int memi = 0;
	int size = 0;

	int ai;
	for (ai = 0; bi < b.size(); ai++, bi++)
	{
		if (a[ai] == b[bi])
		{
			mem[memi] = mem[!memi] + 1;
			if (mem[memi] > size) size = mem[memi];
		}
		else mem[memi] = 0;

		memi = !memi;
	}

	mem[!memi] = 0;

	for (bi = 0; ai < a.size(); ai++, bi++)
	{
		if (a[ai] == b[bi])
		{
			mem[memi] = mem[!memi] + 1;
			if (mem[memi] > size) size = mem[memi];
		}
		else mem[memi] = 0;

		memi = !memi;
	}

	return size;
}

int lcs_str(string a, string b)
{
	int best = lcs_str_diag(a, b, 0);

	for (int i = 1; i + best < a.size(); i++)
	{
		int size = lcs_str_diag(b, a, i);
		if (size > best) best = size;
	}

	return best;
}

int main()
{
	string a, b;
	while (getline(cin, a) && getline(cin, b))
		cout << lcs_str(a, b) << endl;

	return 0;
}

using namespace std;

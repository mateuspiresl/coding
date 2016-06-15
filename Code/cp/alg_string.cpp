#ifndef ALG_STRING_CPP_
#define ALG_STRING_CPP_

#include <bits/stdc++.h>

using namespace std;

#define COUNT 0
#define DIR 1
#define DIAG 0
#define TOP 1
#define LEFT 2

// Prototypes
int lcs_str(string a, string b, bool cicled);
int lcs_str_diag(string a, string b, int bi, bool cicled);
int lcs_seq(char* a, int as, char* b, int bs);
int lcs_seq(const string a, const string b, char mem[51][51][2]);
string lcs_seq_makeString(const string a, const string b, const char mem[51][51][2]);
void lcs_seq_printCount(const string a, const string b, const char mem[51][51][2]);
void lcs_seq_printDir(const string a, const string b, const char mem[51][51][2]);


int lcs_str_diag(string a, string b, int bi, bool cicled)
{
	int mem[2] = { 0, 0 };
	bool memi = 0;
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

	if ( ! cicled) mem[!memi] = 0;

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

int lcs_str(string a, string b, bool cicled)
{
	int best = lcs_str_diag(a, b, 0, cicled);

	// when not cicled, it really has to be subtracted by best?
	for (int i = 1; i - (cicled ? 0 : best) < a.size(); i++)
	{
		int size = lcs_str_diag(b, a, i, cicled);
		if (size > best) best = size;
	}

	return best;
}

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

int lengthStringStar(string s)
{
	int len = 1;
	int max = s.length() >> 1;

	for (; len <= max; len++)
	{
		if (s.length() % len != 0)
			continue;

		int comp = len;

		for (; comp < s.length(); comp++)
			if (s[comp] != s[comp % len])
				break;

		if (comp == s.length())
			return len;
	}

	return s.length();
}

int countStringStar(string s) {
	return s.length() / lengthStringStar(s);
}

string getStringStar(string s) {
	return s.substr(0, lengthStringStar(s));
}


/* Knuth-Morris-Pratt (KMP) */

int* kmp_process(const string& pattern)
{
	int* occurr = new int[pattern.length() + 1];
	occurr[0] = -1;

	int k = -1;

	for (int i = 1; i <= pattern.length(); i++)
	{
		while (k >= 0 && pattern[k] != pattern[i - 1])
			k = occurr[k];

		occurr[i] = ++k;
	}

	return occurr;
}

int kmp(const string& text, const string& pattern, int* occurr, int& i, int& k)
{
	for (; i <= text.length(); i++)
	{
		while (k >= 0 && pattern[k] != text[i - 1])
			k = occurr[k];

		if (++k == pattern.length())
		{
			int iText = i - k;
			k = occurr[k];
			return iText;
		}
	}

	return -1;
}


int kmp_get(const string& text, const string& pattern, vector<int>& positions)
{
	int i = 0, k = 0, pos;
	vector<int>* is = new vector<int>;

	while ((pos = kmp(text, pattern, kmp_process(pattern), i, k)) >= 0)
		positions.push_back(pos);

	return positions.size();
}

int kmp_count(const string& text, const string& pattern)
{
	int i = 0, k = 0, count = 0;

	while (kmp(text, pattern, kmp_process(pattern), i, k) > 0)
		count++;

	return count;
}

bool kmp_contains(const string& text, const string& pattern)
{
	int i = 0, k = 0;
	return kmp(text, pattern, kmp_process(pattern), i, k) >= 0;
}

/* END Knuth-Morris-Pratt (KMP) */

#endif
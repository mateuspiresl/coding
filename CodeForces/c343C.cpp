#include <bits/stdc++.h>

using namespace std;

const long long MOD 10e9 + 7;

int main()
{
	int max, size;
	cin >> max >> size >> str;

	char* str = new char[size + 1];
	cin >> str;

	str[0] = str[0] == '(' ? 1 : -1;
	
	for (int i = 1; i < size; i++)
		str[i] = str[i] == '(' ? str[i - 1] + 1 : str[i - 1] - 1;

	int left = max - size;
	int pMin = str[size - 1] < 0 ? - str[size - 1] : 0;
	int qMin = str[size - 1] > 0 ? str[size - 1] : 0;

	int p = ;

	return 0;
}
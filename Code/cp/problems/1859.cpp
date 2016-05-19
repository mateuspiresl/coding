#include <bits/stdc++.h>
#include "../alg_string.cpp"

using namespace std;

int main()
{
	string a, b;
	while (getline(cin, a) && getline(cin, b))
		cout << (lcs_str(a, b, true) / 8.0) << endl;

	return 0;
}
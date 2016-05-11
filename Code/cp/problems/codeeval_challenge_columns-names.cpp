#include <bits/stdc++.h>

using namespace std;

#define TO_LETTER(n) ((char) ('A' + n))

string convert(int n)
{
	for (int e = 1; n >= 0; n -= 26^e, e++)
 		cout << ((char) (n % 26 == 0 ? 'Z' : 'A' + (n % 26)));

 	return "";
	/*stringstream ss;
	
	int a = column % 26;
	int div = (column - a) / 26;
	int b = div % 26 - 1;
	int c = (div - b) / 26 - 1;

	cout << column << " : " << c << " " << b << " " << a << endl;

	if (c >= 0) ss << TO_LETTER(c);
	if (b >= 0) ss << TO_LETTER(b);
	ss << TO_LETTER(a);

	return ss.str();*/
}

int main(int argc, char* argv[])
{
	//ifstream file(argv[1]);
	int column;

	//while (file >> column)
	for (int i = 26 * 26 * 26 + 26 * 26; i <= 26 * 26 * 26 + 26 * 26 + 25; i++)
		cout << convert(i - 1) << endl;

	return 0;
}

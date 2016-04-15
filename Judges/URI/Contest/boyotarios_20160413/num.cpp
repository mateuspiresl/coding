#include <iostream>
#include <sstream>

using namespace std;

int SIZE = 0;

void pnums(int size, int from, int to, string curr)
{
	if (size == 0) 
	{
		cout << curr << endl;
		SIZE++;
	}
	else
	{
		for (int i = from; i <= to; i++)
		{
			ostringstream conv; conv << curr << i << " ";
			pnums(size - 1, i + 1, to, conv.str());
		}
	}
}

int  main()
{
	int size, from, to;
	cin >> size >> from >> to;
	pnums(size, from, to, "");
	cout << endl << SIZE << endl;
	return 0;
}
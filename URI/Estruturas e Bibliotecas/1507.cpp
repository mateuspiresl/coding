#include <iostream>

using namespace std;

int main()
{
	int nTest;
	cin >> nTest;

	while (nTest--)
	{
		string base;
		cin >> base;

		int nComp;
		cin >> nComp;

		while (nComp--)
		{
			string comp;
			cin >> comp;

			int iBase(0), iComp(0);

			for (; iBase < base.length() && iComp < comp.length(); iBase++)
				if (base[iBase] == comp[iComp])
					iComp++;

			cout << (iComp == comp.length() ? "Yes" : "No") << endl;
		}
	}

	return 0;
}
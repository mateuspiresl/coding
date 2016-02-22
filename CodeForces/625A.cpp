#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
	ull money, plastic, glass, back;
	cin >> money >> plastic >> glass >> back;

	ull plasticBottles = plastic <= money ? money / plastic : 0;

	ull glassBottles = glass <= money;
	if (glassBottles)
	{
		ull rest = money - glass;
		ull withBack = glass - back;

		glassBottles += rest / withBack + (rest % withBack + back) / plastic;
	}

	if (plasticBottles > glassBottles)
		cout << plasticBottles << endl;
	else
		cout << glassBottles << endl;

	return 0;
}
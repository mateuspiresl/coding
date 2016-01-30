#include <iostream>
#include <string>

using namespace std;

int main()
{
	string equation;

	while (true)
	{
		cin >> equation;

		int	i,
			power,
			sum = 0;

		power = 1;
		for (i = 0; i < equation.length(); i++)
		{
			if (equation[i] != '+')
				sum += (equation[i] - '0') * power;
			else
				break;

			power *= 10;
		}
		
		bool zero = sum == 0;
		
		power = 1;
		for (i++; i < equation.length(); i++)
		{
			if (equation[i] != '=')
				sum += (equation[i] - '0') * power;
			else
				break;

			power *= 10;
		}

		zero = zero && sum == 0;

		power = 1;
		for (i++; i < equation.length(); i++)
		{
			sum -= (equation[i] - '0') * power;
			power *= 10;
		}

		cout << (sum == 0 ? "True" : "False") << endl;

		if (zero && sum == 0) break;
	}

	return 0;
}
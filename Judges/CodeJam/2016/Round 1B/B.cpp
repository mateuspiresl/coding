#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int tc = 1; tc <= n; tc++)
	{
		string co, ja;
		cin >> co >> ja;

		long long comem[262144];
		memset(comem, 0, sizeof(comem));

		long long jamem[262144];
		memset(jamem, 0, sizeof(jamem));

		int coi, jai;

		for (int i = 1; i <= co.size(); i++)
		{
			int i

			if (co[i] == '?')
			{
				mem
			}





			if (co[i] == '?')
			{
				if (ja[i] == '?')
				{
					co[i] = '0';
					ja[i] = '0';
				}
				else
				{
					co[i] = ja[i];
				}
				continue;
			}
			else if (ja[i] == '?')
			{
				ja[i] = co[i];
				continue;
			}

			if (co[i] == ja[i])
				continue;

			if (co[i] > ja[i])
			{
				for (int j = i + 1; j < co.size(); j++)
				{
					if (co[i] == '?')
						co[i] = '0';

					if (ja[i] == '?')
						ja[i] = '9';
				}
				break;
			}
			else if (co[i] < ja[i])
			{
				for (int j = i + 1; j < co.size(); j++)
				{
					if (co[j] == '?')
						co[j] = '9';

					if (ja[j] == '?')
						ja[j] = '0';
				}
				break;
			}
		}

		cout << "Case #" << tc << ": " << co << " " << ja << endl;
	}

	return 0;
}
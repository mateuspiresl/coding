#include <bits/stdc++.h>

using namespace std;

/*
procedure generate(n : integer, A : array of any):
    if n = 1 then
          output(A)
    else
        for i := 0; i < n - 1; i += 1 do
            generate(n - 1, A)
            if n is even then
                swap(A[i], A[n-1])
            else
                swap(A[0], A[n-1])
            end if
        end for
        generate(n - 1, A)
    end if
*/

void generate(string curr, int i)
{
	if (i - 1 < curr)
	{
		if (curr[i] != curr[i + 1])
		{
			swap(curr[i], curr[i + 1]);
			cout << "," << curr;
		}
		else
		{

		}

		swap(curr[i], curr[n - 1]);
		generate(curr, i + 1);
		swap(curr[n-1], curr[i]);
	}




	if (n == 1)
		cout << curr << ",";
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			generate(n - 1, curr);

			if (n % 2 == 0)
				swap(curr[i], curr[n - 1]);
			else
				swap(curr[0], curr[n - 1]);
		}

		generate(n - 1, curr);
	}
}

int main(int argc, char* argv[])
{
	ifstream file(argv[1]);
	string line;

	while (getline(file, line))
	{
		sort(line.begin(), line.end());

		generate(line.size(), line);
		cout << endl;
	}

	return 0;
}
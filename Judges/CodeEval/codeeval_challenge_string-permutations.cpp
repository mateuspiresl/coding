#include <bits/stdc++.h>

using namespace std;

void generate(string curr, int i, string& beforeOut, stringstream& ss)
{
	if (i == curr.size() - 1)
	{
		ss << beforeOut << curr;
		beforeOut = ",";
	}
	else
	{
		generate(curr, i + 1, beforeOut, ss);

		for (int j = i + 1; j < curr.size(); j++)
		{
			if (curr[i] != curr[j])
			{
				swap(curr[i], curr[j]);
				generate(curr, i + 1, beforeOut, ss);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	ifstream file(argv[1]);
	stringstream ss;
	string line;

	while (getline(file, line))
	{
		sort(line.begin(), line.end());

		string beforeOut = "";
		generate(line, 0, beforeOut, ss);
		
		ss << endl;
	}

	cout << ss.str();

	return 0;
}

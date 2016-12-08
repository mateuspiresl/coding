#include <iostream>

using namespace std;

int __INT_VAL, __CHAR_VAL;
#define cinInt() (cin >> __INT_VAL, __INT_VAL)
#define cinChar() (cin >> __CHAR_VAL, __CHAR_VAL)

#define each(item, list) (vector<int>::iterator item = list.begin(); item != list.end(); item++)
#define range(i, max) (int i = 0; i < max; i++)

char** rotate(char** matrix, int size)
{
	char** rotated = new char*[size];
	for range(i, size) rotated[i] = new char[size + 1];

	for range(row, size)
		for range(col, size)
			rotated[row][col] = matrix[size - col - 1][row];

	return rotated;
}

void printMatrix(char** matrix, int size)
{
	for range(i, size)
		cout << matrix[i] << endl;
}

int main()
{
	int __it = 0;

	while (true)
	{
		// cout << "it: " << __it++ << endl;

		int biggestSize = cinInt();
		int smallestSize = cinInt();

		if (biggestSize <= 0 || smallestSize <= 0) break;

		char** biggest = new char*[biggestSize];
		for range(i, biggestSize)
		{
			biggest[i] = new char[biggestSize + 1];
			cin >> biggest[i];
		}

		char** smallest = new char*[smallestSize];
		for range(i, smallestSize)
		{
			smallest[i] = new char[smallestSize + 1];
			cin >> smallest[i];
		}

		// cout << "\tbiggest:" << endl;
		// printMatrix(biggest, biggestSize);

		long* matches = new long[4];
		for range(i, 4)
		{
			if (i > 0)
			{
				char** temp = smallest;
				smallest = rotate(smallest, smallestSize);
				delete [] temp;
			}

			// cout << "\tsmallest:" << endl;
			// printMatrix(smallest, smallestSize);

			for range(row, biggestSize - smallestSize + 1) {
				for range(col, biggestSize - smallestSize + 1)
				{
					bool supposed = true;

					for range(rowOffset, smallestSize) {
						for range(colOffset, smallestSize)
						{
							if (biggest[row + rowOffset][col + colOffset] != smallest[rowOffset][colOffset])
							{
								supposed = false;
								break;
							}
						}

						if (!supposed) break;
					}

					if (supposed) matches[i]++;
				}
			}
		}

		for range(i, 4)
		{
			if (i > 0) cout << " ";
			cout << matches[i];
		}

		cout << endl;
	}

	return 0;
}
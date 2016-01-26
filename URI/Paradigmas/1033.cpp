#include <iostream>

using namespace std;

typedef unsigned long long ull;

int countCalls(ull, int);
int** matrixProduct(int**, int**, int);
int callsFor(int**, int);

int MATRIX[3][3] = { { 1, 1, 1 }, { 1, 0, 0 }, { 0, 0, 1 } };

int main()
{
	int tc = 0;

	while (++tc)
	{
		ull num;
		int base;
		cin >> num >> base;

		if (num == 0 && base == 0)
			break;

		ull calls = countCalls(num, base);

		cout << "Case " << tc << ": " << num << " " << base << " " << calls << endl;
	}

	return 0;
}

int countCalls(ull number, int base)
{
	if (number == 0ull || number == 1ull)
		return 1;

	int** cache[64] = {NULL};
	int calculated = 0;

	cache[0] = new int*[3];
	cache[0][0] = MATRIX[0];
	cache[0][1] = MATRIX[1];
	cache[0][2] = MATRIX[2];

	number--;

	int bit = 63;

	while (number >> bit == 0x0) bit--;

	if (bit > calculated)
	{
		int b = calculated + 1; 

		for (; b <= bit; b++)
			cache[b] = matrixProduct(cache[b - 1], cache[b - 1], base);

		calculated = b - 1;
	}

	int** result = cache[bit];

	while (--bit >= 0)
		if (number & (0x1 << bit))
			result = matrixProduct(result, cache[bit], base);

	return callsFor(result, base);
}

int** matrixProduct(int** a, int** b, int base)
{
	int** result = new int*[3];

	for (int l = 0; l < 3; l++)
	{
		result[l] = new int[3];

		for (int c = 0; c < 3; c++)
		{
			result[l][c] = (
				a[l][0] * b[0][c] +
				a[l][1] * b[1][c] +
				a[l][2] * b[2][c]
			) % base;
		}
	}

	return result;
}

int callsFor(int** matrix, int base)
{
	int result[3] = {0};

	for (int l = 0; l < 3; l++)
		for (int c = 0; c < 3; c++)
			result[l] += matrix[l][c];
	
	return result[0] % base;
}
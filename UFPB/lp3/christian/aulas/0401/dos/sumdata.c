#include "sumdata.h"

int x[5] = { 1, 2, 3, 4, 5 };

int Sum(int sum_even) {
	int i;
	int acc = 0;

	for (i = 0; i < 5; i++)
		if ( ! (sum_even && x[i] % 2))
			acc += x[i];

	return acc;
}
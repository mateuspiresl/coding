#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include "insertion.h"

float Median(int *v, int size)
{
	int *tmp = malloc(sizeof(int) * size);
	memcpy(tmp, v, sizeof(int) * size);

	InsertionSort(tmp, size);

	float median;

	if (size % 2)
		median = tmp[(int) size / 2];
	else
		median = (tmp[size / 2] + tmp[size / 2 - 1]) * 0.5f;

	free(tmp);

	return median;
}
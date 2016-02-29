#include <stdio.h>

float average(int *w, int n) {
	int i;
	int avg = 0;
	for (i = 0; i < n; i++)
		avg += w[i];

	return (float) avg / n;
}

int main() {
	int x[5] = { 2, 2, 3, 4, 5 };
	int num = 5;
	float avg = average(x, num);
	printf("Average: %f\n", avg);
	return 0;
}
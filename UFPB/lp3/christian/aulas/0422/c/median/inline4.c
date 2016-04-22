#include "insertion.h"

int y[5] = { 5, 4, 3, 2, 1 };

extern float Median(int *v, int size);

int main(int argc, char* argv[]) {
	InsertionSort(y, 5);
	float m = Median(y, 5);
	return (int) m * y[0];
}
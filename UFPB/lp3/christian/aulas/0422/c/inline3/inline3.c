#include "insertion.h"

int y[5] = { 5, 4, 3, 2, 1 };

int main(int argc, char* argv[]) {
	InsertionSort(y, 5);
	return y[0];
}
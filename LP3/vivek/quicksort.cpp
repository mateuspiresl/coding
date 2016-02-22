#include <iostream>

using namespace std;

void quicksort(int* array, int size);
void qs(int* array, int begin, int end);
void swap(int* a, int* b);

int main()
{
	int arr[8] = { 5, 6, 1, 9, 4, 5, 3, 2 };

	quicksort(arr, 8);

	for (int i = 0; i < 8; i++)
		cout << arr[i] << " ";

	return 0;
}

void quicksort(int* array, int size)
{
	if (size > 1)
		qs(array, 0, size - 1);
}

void qs(int* array, int begin, int end)
{
	int left(begin), right(end - 1);

	if (left >= right)
		return;

	do {
		while (array[left] < array[end] && left < right)
			left++;
		
		while (array[right] > array[end] && right > left)
			right--;
		
		if (left == right)
			break;

		swap(array + left, array + right);

		left++;
		right--;
	}
	while (left < right);

	if (left == right && array[left] <= array[end])
		left++;

	swap(array + left, array + end);

	qs(array, begin, left - 1);
	qs(array, left + 1, end);
}

void swap(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}
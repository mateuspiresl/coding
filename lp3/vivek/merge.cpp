#include <iostream>

using namespace std;

void sort(int* arr, int size);
void _sort(int* arr, int begin, int end);

int main()
{
	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	sort(arr, 10);

	return 0;
}

void merge_sort(int* arr, int size) {
	mergesort_constantspace(arr, 0, size - 1);
}

void mergesort_constantspace(int arr[], int begin, int end)
{
	int leftBegin = begin;
	int leftEnd = begin + (end - begin) / 2;
	int rightBegin = leftEnd + 1;
	int rightEnd = end;

	if (end - begin > 1)
	{
		_sort(arr, leftBegin, leftEnd);
		_sort(arr, rightBegin, rightEnd);
	}

	while (leftBegin <= leftEnd && rightBegin <= rightEnd)
	{
		if (arr[leftBegin] <= arr[rightBegin])
			leftBegin++;
		else
		{
			int aux = arr[rightBegin];

			for (int i = rightBegin; i > leftBegin; i--)
				arr[i] = arr[i - 1];

			arr[leftBegin] = aux;

			leftBegin++;
			leftEnd++;

			rightBegin++;
		}
	}
}

void mergesort_constantspace(int arr[], int begin, int end)
{
	int leftBegin = begin;
	int leftEnd = begin + (end - begin) / 2;
	int rightBegin = leftEnd + 1;
	int rightEnd = end;

	if (end - begin > 1)
	{
		mergesort_constantspace(arr, leftBegin, leftEnd);
		mergesort_constantspace(arr, rightBegin, rightEnd);
	}

	while (leftBegin <= leftEnd && rightBegin <= rightEnd)
	{
		if (arr[leftBegin] <= arr[rightBegin])
			leftBegin++;
		else
		{
			int aux = arr[rightBegin];

			for (int i = rightBegin; i > leftBegin; i--)
				arr[i] = arr[i - 1];

			arr[leftBegin] = aux;

			leftBegin++;
			leftEnd++;

			rightBegin++;
		}
	}
}
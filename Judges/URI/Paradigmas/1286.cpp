#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Item
{
	int weight;
	int value;
};

int main()
{
	int numItems;

	while (cin >> numItems && numItems > 0)
	{
		int capacity;
		cin >> capacity;

		Item items[numItems+1];
		int values[capacity + 1][numItems + 1];

		for (int i = 1; i <= numItems; i++)
		{
			Item item;
			cin >> item.value >> item.weight;
		}

		for (int c = 0; c <= capacity; c++)
			for (int i = 0; i <= numItems; i++)
				values[c][i] = 0;

		for (int c = 1; c <= capacity; c++)
		{
			for (int i = 1; i <= numItems; i++)
			{
				if (items[i].weight <= c)
					values[c][i] = max(values[c - items[i].weight][i - 1] + items[i].value, values[c][i - 1]);
				else
					values[c][i] = values[c][i - 1];
			}
		}
//4 5 500 4 400 2 300 1 450 3
		for (int c = 1; c <= capacity; c++)
		{
			for (int i = 1; i <= numItems; i++)
				printf("%d ", values[c][i]);
			printf("\n");
		}
		cout << values[capacity][numItems] << " min." << endl;
	}

	return 0;
}
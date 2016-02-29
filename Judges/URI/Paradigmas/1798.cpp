
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Item
{
	int weight;
	int value;
};

bool sortItemsByWeight(Item const& a, Item const& b)
{
	return a.weight < b.weight;
}

int main()
{
	int numItems, capacity;
	cin >> numItems >> capacity;

	vector<Item> items;

	for (int i = 0; i < numItems; i++)
	{
		Item item;
		cin >> item.weight >> item.value;
		items.push_back(item);
	}

	//sort(items.begin(), items.end(), &sortItemsByWeight);

	int values[capacity + 1];
	values[0] = 0;

	memset(values, 0, sizeof values);
	for (int c = 1; c <= capacity; c++)
	{
		//values[c] = values[c - 1];

		for (int i = 0; i < numItems; i++)
		{
			//int value = values[c - items[i].weight] + items[i].value;
			if(items[i].weight <= c)
			values[c] = max(values[c-items[i].weight] + items[i].value, values[c]);
			//if (value > values[c])
			//	values[c] = value;
		}
	}

	cout << values[capacity] << endl;

	return 0;
}
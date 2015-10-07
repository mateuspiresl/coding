#include <iostream>

using namespace std;

int main()
{
	int numQuotations;
	short cost;

	cin >> numQuotations >> cost;

	short quotations[numQuotations];

	int smaller = 0, greater = 0;
	int gain = 0;

	cin >> quotations[0];

	for (int i = 1; i < numQuotations; i++)
	{
		cin >> quotations[i];

		if (quotations[i] < quotations[smaller])
		{
			if (smaller < greater)

			smaller = i;
			greater = i;
		}

		else if (i != smaller && quotations[i] == quotations[smaller])
		{
			int selling = quotations[greater] - quotations[smaller] - cost;

			if (selling > 0)
				gain += selling;

			smaller = i + 1;
			greater = i + 1;

			i++;	
		}

		else if (quotations[i] > quotations[greater])
		{
			greater = i;
		}
	}
}

int _main()
{
	int numQuotations;
	short cost;

	cin >> numQuotations >> cost;

	short quotations[numQuotations];

	list<int> smallers;
	list<int> greaters;

	int gain = 0;

	cin >> quotations[0];

	int quotation = quotations[0];

	smaller.push_back(quotation);
	greater.push_back(quotation);

	for (int i = 1; i < numQuotations; i++)
	{
		cin >> quotations[i];
		quotation = quotations[i];

		list<int>::iterator smIt = smaller.begin();
		list<int>::iterator grIt = greater.begin();

		if (quotation < *smIt)

		for (; smIt != smaller.end(); smIt++, grIt++)
		{
			if (quotation < *smIt)
				gain += sellAll(smallers, greaters);


		}

		if (quotations[i] < quotations[smaller])
		{
			if (smaller < greater)

			smaller = i;
			greater = i;
		}

		else if (i != smaller && quotations[i] == quotations[smaller])
		{
			int selling = quotations[greater] - quotations[smaller] - cost;

			if (selling > 0)
				gain += selling;

			smaller = i + 1;
			greater = i + 1;

			i++;	
		}

		else if (quotations[i] > quotations[greater])
		{
			greater = i;
		}
	}
}

int sellAll(list<int> smallers, list<int> greaters)
{
	int gain = 0;

	list<int>::iterator smIt = smaller.begin();
	list<int>::iterator grIt = greater.begin();

	for (; smIt != smaller.end(); smIt++, grIt++)
	{
		gain += *grIt - *smIt - cost;
		smaller.
	}

	return gain;
}
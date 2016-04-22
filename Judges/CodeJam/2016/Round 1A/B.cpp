#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int ti = 1; ti <= t; ti++)
	{
		int n;
		cin >> n;

		priority_queue< pair< int, vector<int>* > > pq;

		for (int i = 0; i < n; i++)
		{
			vector<int>* list = new vector<int>;

			for (int j = 0; j < n; j++)
			{
				int value;
				cin >> value;
				list.push(value);
			}

			pq.insert(pair< int, vector<int> >(-list->at(0), list));
		}

		int** mat = new int[n];
		for (int i = 0; i < n; i++) {
			mat[i] = new int[n];
			for (int j = 0; j < n; j++)
				mat[i][j] = 0;
		}

		int last = pq.top->first;
		vector<int>* seq = pq.top->second;
		pq.pop();

		for (int i = )
	}

	return 0;
}
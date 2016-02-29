#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int tc = 222;
	int n;

	while (tc-- && cin >> n)
	{
		map<int, vector<int>*> ys;

		while (n--)
		{
			int x, y;
			cin >> x >> y;

			map<int, vector<int>*>::iterator found = ys.find(y);

			if (found != ys.end())
			{
				found->second->push_back(x);
			}
			else
			{
				vector<int>* xs = new vector<int>;
				xs->push_back(x);

				ys.insert(pair<int, vector<int>*>(y, xs));
			}
		}

		map<int, vector<int>*>::iterator
				a = ys.begin(),
				b = ys.begin();

		bool one = true;
		b++;

		int best = 0;

		while (b != ys.end())
		{
			if (a->first == b->first - 2)
			{
				vector<int>* av = a->second;
				vector<int>* bv = b->second;

				sort(av->begin(), av->end());
				sort(bv->begin(), bv->end());

				vector<int>::iterator it;

				//cout << "~ A: ";

				//for (it = av->begin(); it != av->end(); it++)
				//	cout << *it << " ";

				//cout << endl << "~ B: ";

				//for (it = bv->begin(); it != bv->end(); it++)
				//	cout << *it << " ";

				//cout << endl;

				vector<int>::iterator curr = av->begin();
				vector<int>::iterator next = bv->begin();

				int cnt = 1;

				while (next != av->end() && next != bv->end())
				{
					if (*next > *curr)
					{
						cnt++;

						it = curr;
						curr = next;
						it++;
						next = it;
					}
					else next++;
				}

				if (cnt > best)
					best = cnt;

				curr = bv->begin();
				next = av->begin();

				//cout << "~ " << cnt << " ";
				cnt = 1;

				while (next != av->end() && next != bv->end())
				{
					if (*next > *curr)
					{
						cnt++;

						it = curr;
						curr = next;
						it++;
						next = it;
					}
					else next++;
				}

				//cout << cnt << endl << endl;

				if (cnt > best)
					best = cnt;

				a++;
				b++;
			}
			else if (one)
			{
				if (a->first != b->first - 1)
					a++;
				else
					one = false;

				b++;
			}
			else
			{
				a++;
				one = true;
			}
		}

		cout << best << endl;
	}

	return 0;
}
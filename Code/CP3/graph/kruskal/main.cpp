#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*********************/
/*** disjoint-sets ***/
/*********************/

typedef struct {
	vector<int> p, rank;
} DisjointSets;

DisjointSets* dj_create(int n)
{
	DisjointSets* dj = new DisjointSets;

	dj->p.assign(n, 0);
	dj->rank.assign(n, 0);

	for (int i = 0; i < n; i++)
		dj->p[i] = i;
}

int dj_findSet(DisjointSets* dj, int i) {
	return dj->p[i] == i ? i : (dj->p[i] = dj_findSet(dj, dj->p[i]));
}

bool dj_isSameSet(DisjointSets* dj, int i, int j) {
	return dj_findSet(dj, i) == dj_findSet(dj, j);
}

void dj_unionSet(DisjointSets* dj, int i, int j)
{
	int is = dj_findSet(dj, i);
	int js = dj_findSet(dj, j);

	if (is != js)
	{
		if (dj->rank[is] > dj->rank[js])
			dj->p[js] = is;
		else {
			dj->p[is] = js;
			
			if (dj->rank[is] == dj->rank[js])
				dj->rank[js]++;
		}
	}
}

/*************************/
/*** END disjoint-sets ***/
/*************************/


typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

int main()
{
	viii edgeList;

	int n, e;
	cin >> n >> e;

	while (e--)
	{
		int w, a, b;
		cin >> w >> a >> b;

		edgeList.push_back(iii(w, ii(a, b)));
	}

	sort(edgeList.begin(), edgeList.end());

	viii::iterator viii_it = edgeList.begin();
	DisjointSets* dj = dj_create(n);
	int size = 1;

	for (; viii_it != edgeList.end(); viii_it++)
	{
		int a = viii_it->second.first;
		int b = viii_it->second.second;

		if ( ! dj_isSameSet(dj, a, b))
		{
			

			dj_unionSet(dj, a, b);
			size++;
		}
	}

	cout << "Cost: " << size << endl;

	return 0;
}
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef std::vector<int> vi;

typedef struct {
	vi p, rank;
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


int main()
{
	int numCases;
	cin >> numCases;

	int numComp;
	cin >> numComp;

	for (int i = 0; i < numCases; i++)
	{
		DisjointSets* dj = dj_create(numComp);

		while ( ! cin.eof())
		{
			string in;
			cin >> in;

			if (in[0] == 'c')
			{
				dj_unionSet()
			}
		}
	}
}
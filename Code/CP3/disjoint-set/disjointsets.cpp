#include "../cp3.h"

class DisjointSets {

private:
	vi p, rank;

public:
	DisjointSets(int n)
	{
		p.assign(n, 0);
		rank.assign(n, 0);

		for (int i = 0; i < n; i++)
			p[i] = i;
	}

	int findSet(int i) {
		return p[i] == i ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j)
	{
		int is = findSet(i);
		int js = findSet(j);

		if (is != js)
		{
			if (rank[is] > rank[js])
				p[js] = is;
			else {
				p[is] = js;
				
				if (rank[is] == rank[js])
					rank[js]++;
			}
		}
	}

};
#include <bits/stdc++.h>

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

	for (int i = 0; i <= n; i++)
	{
		dj->p.push_back(i);
		dj->rank.push_back(0);
	}

	return dj;
}

int dj_findSet(DisjointSets* dj, int i)
{
	if (dj->p[i] == i)
		return i;

	dj->p[i] = dj_findSet(dj, dj->p[i]);
	return dj->p[i];
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
typedef pair<float, ii> fii;
typedef vector<fii> vfii;

template<typename T, typename U> ostream& operator<<(ostream &s, pair<T, U> t){ //print vector
	s << t.first << " " << t.second << " "; return s; }
template<typename T> ostream& operator<<(ostream &s, vector<T> t){ //print vector
	for(int i = 0, sz = t.size(); i < sz; i++) s << t[i] << ", ";return s; }

int main()
{
	int tc = 1;
	int n, e;
	while (cin >> n >> e)
	{
		if ( ! n) break;

		vfii edgeList;

		while (e--)
		{
			int a, b;
			float w;
			cin >> a >> b >> w;

			edgeList.push_back(fii(w - 1, ii(a, b)));
		}

		sort(edgeList.begin(), edgeList.end());

		vfii::iterator vfii_it = edgeList.begin();
		DisjointSets* dj = dj_create(n);
		float prob = 1;

		for (; vfii_it != edgeList.end(); vfii_it++)
		{
			int a = vfii_it->second.first;
			int b = vfii_it->second.second;

			if ( ! dj_isSameSet(dj, a, b))
			{
				dj_unionSet(dj, a, b);
				prob *= vfii_it->first;
			}
		}

		if (tc > 1) cout << endl;
		cout << "Instancia " << (tc++) << endl;
		cout << fixed << setprecision(5) << (1 - (prob > 0 ? prob : -prob)) << endl;
	}

	return 0;
}
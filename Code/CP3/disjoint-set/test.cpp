#include <iostream>
#include "disjointsets.cpp"

using namespace std;

void findSet(DisjointSets* dj, int i) {
	cout << "findSet(" << i << ") == " << dj->findSet(i) << endl;
}

void isSameSet(DisjointSets* dj, int i, int j) {
	cout << "isSameSet(" << i << ", " << j << ") == " << dj->isSameSet(i, j) << endl;
}

int main()
{
	DisjointSets dj(10);

	dj.unionSet(0, 1);
	dj.unionSet(1, 2);
	dj.unionSet(2, 3);

	dj.unionSet(4, 5);
	dj.unionSet(4, 6);

	dj.unionSet(7, 8);
	dj.unionSet(9, 7);

	findSet(&dj, 2);
	findSet(&dj, 4);
	findSet(&dj, 8);
	isSameSet(&dj, 2, 3);
	isSameSet(&dj, 0, 4);
	isSameSet(&dj, 6, 4);
	isSameSet(&dj, 6, 9);

	dj.unionSet(2, 4);

	findSet(&dj, 2);
	findSet(&dj, 4);
	isSameSet(&dj, 0, 3);
	isSameSet(&dj, 2, 6);

	dj.unionSet(6, 9);

	findSet(&dj, 6);
	findSet(&dj, 9);
	isSameSet(&dj, 0, 8);
	isSameSet(&dj, 4, 7);
}
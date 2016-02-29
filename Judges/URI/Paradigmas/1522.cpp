#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<short>	*stackA = NULL,
				*stackB = NULL,
				*stackC = NULL;
bool possibles[1000000];

int toKey(short a, short b, short c)
{
	int key = 0;

	if (a > 0) key += a * 10000;
	if (b > 0) key += b * 100;
	if (c > 0) key += c;

	return key;
}

bool isPossible(short a, short b, short c)
{
	if (a == -1 && b == -1 && c == -1)
		return true;

	short cardA = a >= 0 ? stackA->at(a) : -1;
	short cardB = b >= 0 ? stackB->at(b) : -1;
	short cardC = c >= 0 ? stackC->at(c) : -1;

	if (a >= 0 && b >= 0 && (cardA + cardB) % 3 == 0)
		if (possibles[toKey(a - 1, b - 1, c)])
			if (isPossible(a - 1, b - 1, c))
				return true;

	if (a >= 0 && c >= 0 && (cardA + cardC) % 3 == 0)
		if (possibles[toKey(a - 1, b, c - 1)])
			if (isPossible(a - 1, b, c - 1))
				return true;

	
	if (b >= 0 && c >= 0 && (cardB + cardC) % 3 == 0)
		if (possibles[toKey(a, b - 1, c - 1)])
			if (isPossible(a, b - 1, c - 1))
				return true;

	
	if (a >= 0 && b >= 0 && c >= 0 && (cardA + cardB + cardC) % 3 == 0)
		if (possibles[toKey(a - 1, b - 1, c - 1)])
			if (isPossible(a - 1, b - 1, c - 1))
				return true;

	possibles[toKey(a, b, c)] = false;
	return false;
}

int main()
{
	short n;

	while (true)
	{
		cin >> n;
		if ( ! n) break;

		stackA = new vector<short>;
		stackB = new vector<short>;
		stackC = new vector<short>;

		while (n--)
		{
			short cardA, cardB, cardC;
			cin >> cardA >> cardB >> cardC;

			if (cardA % 3) stackA->push_back(cardA);
			if (cardB % 3) stackB->push_back(cardB);
			if (cardC % 3) stackC->push_back(cardC);
		}

		short	a = stackA->size() - 1,
				b = stackB->size() - 1,
				c = stackC->size() - 1;

		memset(possibles, true, 1000000);

		cout << (isPossible(a, b, c) ? 1 : 0) << endl;

		delete stackA;
		delete stackB;
		delete stackC; 
	}

	return 0;
}
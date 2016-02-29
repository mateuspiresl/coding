






#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

struct Node
{
	char value;
	Node* prev;
	Node* next;
};

Node** nodesList()
{
	Node* toRoot = new Node;
	Node* node = toRoot;

	for (int n = 1; n <= 26; n++)
	{
		node->next = new Node;
		node->next->prev = node;
		node = node->next;
		node->value = n;
	}

	Node** ret = new Node*[2];
	ret[0] = toRoot->next;
	ret[1] = node;

	node = toRoot->next;
	node->prev = NULL;
	delete toRoot;

	return ret;
}

inline int abs(int n) {
	return n > 0 ? n : -n;
}

Node* find(Node* node, int* curr, int reach)
{
	if (*curr > reach) {
		do {
			(*curr)--;
			node = node->prev;
		}
		while (*curr > reach);
	}
	else while (*curr < reach)
	{
		(*curr)++;
		node = node->next;
	}

	return node;
}

// build delete

int main()
{
	int x;
	int counter = 0;

	while (cin >> x)
	{
		cout << "Read " << x << endl;

		counter++;

		Node** nl = nodesList();
		Node* nb = nl[0];
		Node* ne = nl[1];
		Node* n = nb;

		int max = 27;

		set<string> made;

		while (x--)
		{
			cout << "Reading " << x << endl;

			Node** start = &(ne->next);
			int size = 0;

			string codes;
			while (codes.length() == 0)
				getline(cin, codes);

			stringstream ss;
			
			cout << "~~ " << codes << " (" << codes.length() << ")" << endl;

			for (string::iterator c = codes.begin(); c != codes.end();)
			{
				cout << "LIST: ";
				Node* p = nb;
				while (p != NULL)
				{
					cout << (char) (p->value + 'A' - 1) << " ";
					p = p->next;
				}
				cout << endl;

				size++;
				while (*c < '1' || *c > '9') c++;

				int v = *c - '0';
				c++;

				if (c != codes.end() && *c >= '0' && *c <= '9')
				{
					v *= 10;
					v += *c - '0';
					c++;
				}

				cout << "\tindex: " << v << endl;

				if (v < 27)
				{
					int ni = 1;
					n = nb;

					n = find(n, &ni, v);

					cout << "\tfound: " << n->value << endl;

					n = find(n, &ni, n->value);

					cout << "\tvalue: " << (char) (n->value + 'A' - 1) << endl;

					ss << (char) (n->value + 'A' - 1);

					if (ni > 1)
					{
						n->next->prev = n->prev;
						n->prev->next = n->next;
					}
					else if (ni == 1)
					{
						nb->next->prev = NULL;
						nb = nb->next;
					}
					
					ne->next = n;
					n->next = NULL;
					n->prev = ne;

					ne = n;
				}
				else ss << ' ';
			}

			cout << "LIST: ";
			Node* p = nb;
			while (p != NULL)
			{
				cout << p->value << " ";
				p = p->next;
			}
			cout << endl;

			made.insert(ss.str());
		}

		if (counter > 1) cout << endl;

		cout << "LISTA #" << counter << ":" <<  endl;

		set<string>::iterator it = made.begin();
		while (it != made.end())
		{
			cout << *it << endl;
			it++;
		}
	}

	return 0;
}
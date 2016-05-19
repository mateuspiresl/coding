#include <iostream>

using namespace std;


struct _Node {
	struct Node* parent = NULL;
	char c;
	vector<struct Node*> children;
	bool end;
};

typedef struct _Node Node;

int offsets[] = { 0, 1, 4, 7, 10, 12, 14, 17, 20, 23 };
	int limits[] = { 1, 4, 7, 10, 12, 14, 17, 20, 23, 26 };
	char repr[] = {
			'e',
			'j', 'n', 'q',
			'r', 'w', 'x',
			'd', 's', 'y',
			'f', 't',
			'a', 'm',
			'c', 'i', 'v',
			'b', 'k', 'u',
			'l', 'o', 'p',
			'g', 'h', 'z'
		};

int main()
{
	while (true)
	{
		int numWords; cin >> numWords;
		if ( ! numWords) break;

		string words[] = new string[numWords];
		Node* root = new Node;

		for (int i = 0; i < numWords; i++)
		{
			cin >> words[i];

			Node* node = root;

			string::iterator sit = words[i].begin();
			for (; sit != words[i].end(); sit++)
			{
				vector::iterator vit = node->children.rbegin();

				if (vit != node->children.rend() && *sit == vit->c)
					node = vit;
				else
				{
					Node* child = new Node;
					child->parent = node;
					child->c = *sit;
					node->children.push_back(child)
					node = child;
				}
			}

			node->end = true;
		}

		int numNumbers; cin >> numNumbers;

		while (numNumbers--)
		{
			string number; cin >> number;
			string::iterator sit = number.begin();

			Node* node = root;

			// ... r
		}
	}

	return 0;
}

void r(Node* root, Node* node, string::iterator nit, string::iterator nend, string s)
{
	if (nit == nend)
	{
		if (node->end)
		{
			cout << s << endl;
		}
		else return;
	}
	else if (node->end)
	{
		

		r()
	}

	int digit = *sit - '0';

	// se for digito
	if (digit >= 0 && digit <= 9)
	{
		// para cada representação
		for (int i = offsets[digit]; i < limits[digit]; i++)
		{
			// pega representação
			auto found = lower_bound(node->children.begin(), node->children.end(), repr[i]);

			// se existe no dicionario
			if (found != node->children.end())
			{
				r(root, found, nit + 1, ss);
			}
		}
	}
}









/*


struct _Node {
	struct Node* parent = NULL;
	char* children = NULL;
	string* attached = NULL;
};


int main()
{
	int offsets[] = { 0, 1, 4, 7, 10, 12, 14, 17, 20, 23 };
	int sizes[] = { 1, 3, 3, 3, 2, 2, 3, 3, 3, 3 };
	char repr[] = {
			'e',
			'j', 'n', 'q',
			'r', 'w', 'x',
			'd', 's', 'y',
			'f', 't',
			'a', 'm',
			'c', 'i', 'v',
			'b', 'k', 'u',
			'l', 'o', 'p',
			'g', 'h', 'z'
		};

	int idxs[256];
	char chars[52];
	chars[0] = '"';
	chars[1] = '-';

	char c = 'A';
	while (c <= 'Z')
	{
		chars[i] = c;
		idxs[c] = i;
		c++;
	}

	char c = 'a';
	while (c <= 'z')
	{
		chars[i] = c;
		idxs[c] = i;
		c++;
	}

	int ntc; cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++)
	{
		int numWords; cin >> numWords;

		string words[] = new string[numWords];

		int counter[]

		for (int i = 0; i < numWords; i++)
		{
			cin >> words[i];

			
		}
	}

	return 0;
}

*/
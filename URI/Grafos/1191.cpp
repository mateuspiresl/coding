#include <iostream>

using namespace std;

struct Node {
	Node* left = NULL;
	Node* right = NULL;
	char c;
};

// Caractere atual na prefixa
string::iterator p;

Node* find(string in)
{
	if (in.length())
	{
		string str;
		str.push_back(*p);

		size_t i = in.find_first_of(str);

		if (i != string::npos)
		{
			Node* node = new Node;
			node->c = *p++;

			if (*p != '\0')
			{
				node->left = find(in.substr(0, i));
				node->right = find(in.substr(i + 1, in.length() - i));
			}

			return node;
		}
	}

	return NULL;
}

void printTree(Node* node)
{
	if (node == NULL) return;

	printTree(node->left);
	printTree(node->right);

	cout << node->c;
}

int main()
{
	string pre, in;
	
	while (cin >> pre >> in)
	{
		p = pre.begin();
		printTree(find(in));
		cout << endl;
	}

	return 0;
}
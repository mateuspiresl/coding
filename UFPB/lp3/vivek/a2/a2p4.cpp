#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* high;
};

Node* getList();
void solveCounting(Node* root);
void solve(Node* root, int size);

int main()
{
	Node* root = getList();

	root->high = root;

	solveCounting(root);

	while (root != NULL)
	{
		cout << root->value << " ";
		root++;
	}
	cout << endl;

	return 0;
}

Node* getList()
{
	Node* toRoot = new Node;
	Node* node = toRoot;

	int n;
	cin >> n;

	while (n--)
	{
		int value;
		cin >> value;

		node->next = new Node;
		node = node->next;
		node->value = value;
	}
	
	node = toRoot->next;
	delete toRoot;

	return node;
}

void solveCounting(Node* root)
{
	Node* node = root;
	int size = 0;

	while (node != NULL)
	{
		size++;
		node = node->next;
	}

	solve(root, size);
}

void solve(Node* root, int size)
{
	Node* node = root + (size - 1);
	Node* higher = node;

	node--;

	while (node >= root)
	{
		node->high = higher;

		if (higher->value < node->value)
			higher = node;
	}
}
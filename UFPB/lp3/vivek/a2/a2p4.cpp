#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* high;

	Node(int _value)
	{
		value = _value;
		next = NULL;
		high = NULL;
	}
};

void solveCounting(Node* root);
void solve(Node* root, int size);

int main()
{
	Node* toRoot = new Node(0);;
	Node* node = toRoot;

	int value;
	while (cin >> value)
		node = node->next = new Node(value);
	
	node = toRoot->next;
	delete toRoot;

	solveCounting(node);

	while (node != NULL)
	{
		cout << node->value << " ";
		node++;
	}

	return 0;
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
#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next = NULL;
};

bool solve(Node* root, int k);
void swap(Node* a, Node* b);

int main()
{
	int size, k;
	cin >> size >> k;

	int* arr;

	Node* root = new Node;
	Node* node = root;

	while (size--)
	{
		node->next = new Node;
		node = node->next;
		cin >> node->value;
	}

	node = root;
	root = root->next;
	delete node;

	solve(root, k);

	while (root != NULL)
	{
		cout << root->value << " ";
		root = root->next;
	}

	cout << endl;

	return 0;
}

void swap(Node** root, Node** node)
{
	Node* aux = *node;
	*node = (*node)->next;
	aux->next = *root;
	*root = aux;
}

bool solve(Node* root, int k)
{
	// IDA

	int counter = 1;

	Node* node = root;
	root = NULL;

	while (node != NULL && counter < k)
	{
		counter++;
		swap(&root, &node);
	}

	if (k >= counter)
		return false;

	Node* first = node;

	while (node != NULL)
		swap(&root, &node);

	// VOLTA

	node = root;
	root = NULL;

	while (--k)
		swap(&root, &node);
	
	int aux = first->value;
	first->value = node->value;
	node->value = aux;

	while (node != NULL)
		swap(&root, &node);
}
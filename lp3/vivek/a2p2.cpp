#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* next = NULL;
};

bool solve(Node* root, int k);

int main()
{
	int size = 8;
	int arr[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int k = 3;

	Node* root = new Node;
	Node* node = root;
	node->value = arr[0];

	for (int i = 1; i < size; i++)
	{
		node->next = new Node;
		node = node->next;
		node->value = arr[i];
	}

	solve(root, k);

	while (root != NULL)
	{
		cout << root->value << " ";
		root = root->next;
	}

	return 0;
}

bool solve(Node* root, int k)
{
	int counter = 0;

	Node* first;
	if (counter == k)
		first = root;
	
	Node* node = root->next;
	root->next = NULL;

	while (node != NULL)
	{
		if (counter == k)
			first = node;

		Node* aux = node;
		node = node->next;
		aux->next = root;
		root = aux;

		counter++;
	}

	if (k < counter)
		return false;

	counter = 0;
	node = root;
	root = NULL;

	while (k > 0)
	{
		Node* aux = node;
		node = node->next;
		aux->next = root;
		root = aux;
	}
	
	int aux = first->value;
	first->value = node->value;
	node->value = aux;
}
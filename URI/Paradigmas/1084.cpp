#include <iostream>

//#define pl(_s) cout << _s << endl;

using namespace std;

struct Node
{
public:
	Node* next;
	char value;
	int index;

	Node(int _value, int i, Node* _next = NULL)
	{
		next = _next;
		value = _value;
		index = i;
	}
};

int main()
{
	int n, d;

	while (true)
	{
		cin >> n >> d;

		if ( ! n && ! d)
			break;

		string number;
		cin >> number;

		int ansSize = n - d;
		int i = n - ansSize;

		Node* root = new Node(number[i], i);
		Node* node = root;

		for (i++; i < n; i++)
		{
			node->next = new Node(number[i], i);
			node = node->next;
		}

		for (i = n - ansSize - 1; i >= 0; i--)
		{
			node = root;

			if (number[i] >= node->value)
			{
				root = new Node(number[i], i, node);

				Node* comp = node;
				node = root;

				while (comp->next != NULL && comp->value >= comp->next->value)
				{
					node = comp;
					comp = comp->next;
				}

				node->next = comp->next;
				//delete comp;
			}
		}

		while (root != NULL)
		{
			cout << root->value;
			root = root->next;
		}

		cout << endl;
	}

	return 0;
}
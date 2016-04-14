#include <iostream>

using namespace std;

struct _Node {
	char c;
	char end;
	struct _Node* list;
};
typedef struct _Node Node;

Node* createList() {
	return malloc(sizeof(_Node*) * 27);
}

Node* createNode() {
	Node* node = malloc(sizeof(Node));
	node->list = createList();
	for (int i = 0; i < 27; i++)
		node->list[i] = NULL;
}

int const ONE = 0x1;
int const ONE_END = 0x2;
int const TWO = 0x4;
int const TWO_END = 0x8;

int main()
{
	int n;
	cin >> n;

	Letter* root = createNode();

	while (n != -1)
	{
		for (int i = 0; i < n; i++)
		{
			string name;
			cin >> name;

			Node node = root;
			int length = name.length();

			for (int i = 0; i < length; i++)
			{
				Node curr = node->list[i];

				if (curr == NULL)
				{
					curr = createNode();
					curr->a = name[i];
					curr->end = 0x1;
				}

				node->list[i] = curr;
			}

			node->list[length - 1]->end |= 0x2;
		}

		for (int i = 0; i < n; i++)
		{
			string name;
			cin >> name;

			Node node = root;
			int length = name.length();
			int size = 0;

			for (int i = 0; i < length; i++)
			{
				Node curr = node->list[i];

				if (curr == NULL)
				{
					curr = createNode();
					curr->a = name[i];
					curr->end = 2;
				}
				else
				{
					if (curr->end == 1)
						curr->end = 3;

					else if (curr->end == -1)
						curr->end = -3;

					size++;
				}

				node->list[i] = curr;
			}

			node->list[length - 1]->end = -1;
		}

		cin >> n;
	}

	return 0;
}
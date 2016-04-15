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

Node* createNode(char c) {
	Node* node = malloc(sizeof(Node));
	node->c = c;
	node->end = 0;
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

	Letter* root = createNode(0);

	while (n != -1)
	{
		vector<int> lens;

		for (int i = 0; i < n; i++)
		{
			string name;
			cin >> name;

			Node node = root;
			int length = name.length();
			lens.push(length);

			for (int i = 0; i < length; i++)
			{
				Node curr = node->list[i];

				if (curr == NULL)
				{
					curr = createNode(name[i]);
					curr->end |= ONE;
				}

				node->list[i] = curr;
			}

			node->list[length - 1]->end |= ONE_END;
		}

		sort(lens.begin(), lens.end());

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
					if (i == 0)
					{
						curr = createNode(name[i]);
						curr->end |= TWO;
					}
					else
					{
						node->end |= TWO;
						ans += 
					}
				}
				else if (i == length - 1)
				{

				}

				node->list[i] = curr;
			}

			node->list[length - 1]->end |= TWO_END;
		}

		cin >> n;
	}

	return 0;
}
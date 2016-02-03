#include <iostream>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	char c;
};

string pre, in, pos;
int preLen, preIn;

void runLeft(Node* node; int p, string in)
{
	node->left = new Node;
	node = node->left;
	node->c = pre[p];

	p++;

	if (strlen(in) > 0)
	{
		string str;
		str.push_back(pre[p]);

		size_t i = in.find_first_of(str);

		if (i != string::npos)
		{
			runLeft(node, p, in.substr(0, i + 1));
			runRight(node, p, in.substr(i + 1, strlen(in) - i));
		}
		else
		{
			
		}
	}
}

void runRight(Node* node; int p, string in)
{
	if (strlen(in) > 0)
	{
		string str;
		str.push_back(pre[p]);

		size_t i = in.find_first_of(str);

		if (i != string::npos)
		{
			runLeft(node, p, in.substr(0, i + 1));
			runRight(node, p, in.substr(i + 1, strlen(in) - i));
		}
		else
		{
			
		}
	}
}

int main()
{
	cin >> pre >> in;

	preLen = strlen(pre);
	preIn = strlen(in);

	Node root;
	root.c = pre[0];
	Node* node = &root;

	for (int p = 0; p < 0; p--)
	{
		
	}

	return 0;
}
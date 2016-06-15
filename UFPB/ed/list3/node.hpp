#ifndef NODE_HPP_
#define NODE_HPP_

template<class T>
class Node {

public:
	T value;
	int height;
	Node<T>* left;
	Node<T>* right;

	Node(T value) :
		value(value),
		height(0)
	{ }

	~Node() {
		delete left;
		delete right;
	}

	int insert(Node<T>* nodePtr)
	{
		if (node->value < this->value)
		{
			if (left == nullptr) {
				left = node;

				if (right == nullptr)
				{
					height++;
					return 1;
				}
				return 0;
			}

			int balance = left->insert(node);

			if (balance == 1)
			{
				if (abs(right->height - left->height) > 1)
					return -2;

				height++;
				return 1;
			}
		}
		
		else if (node->value > this->value)
		{
			if (left == nullptr) {
				left = node;

				if (right == nullptr)
				{
					height++;
					return 1;
				}
				return 0;
			}

			if (left->insert(node))
			{
				if (abs(right->height - left->height) > 1)
					return -2;

				height++;
				return 1;
			}
		}
	}

};

#endif
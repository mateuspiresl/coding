#ifndef TREE_HPP_
#define TREE_HPP_

#include "node.hpp"

template<class T>
class Tree {

private:
	int size;
	Node<T> root;

public:
	Tree() :
		size(0)
	{ }

	int size() {
		return this->size;
	}

	Node<T> getRoot() {
		return this->root;
	}

	void insert(T value)
	{
		
	}

	Tree<T> operator +=(T value)
	{

	}

};

#endif
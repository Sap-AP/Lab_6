#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>
#include <iostream>

template <class node, class T>
class TIterator {
public:
	TIterator(node* n) {
		node_ptr = n;
	}

	node* operator * () {
		return node_ptr;
	}

	node* operator -> () {
		return node_ptr;
	}

	void operator ++ () {
		node_ptr = node_ptr->getNext();
	}

	TIterator operator ++ (int) {
		TIterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator == (TIterator const &i) {
		return node_ptr == i.node_ptr;
	}

	bool operator != (TIterator const& i) {
		return !(*this == i);
	}

private:
	node* node_ptr;
};

#endif

#ifndef TBINTREE_H
#define TBINTREE_h

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Rhombus.h"
#include "TBTreeItem.h"
#include "TIterator.h"

#include <memory>

template <class T> class TBTree {
public:
	TBTree();
	TBTree(const TBTree<T>& orig);

	void push(int PKey, int Key, std::shared_ptr<T> figure);
	std::shared_ptr<T> get(int Key);
	int prov(int Key);

	void del(int Key);

	TIterator<TBTreeItem<T>, T> begin();
	TIterator<TBTreeItem<T>, T> end();
	bool empty();

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TBTree<A>& obj);

	virtual ~TBTree();
private:
	TBTreeItem<T> *root;
};

#endif

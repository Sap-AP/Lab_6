#ifndef TTREEITEM_H
#define TTREEITEM_H

#include "Figure.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Rhombus.h"
#include "TAllocationBlock.h"
#include <memory>

template <class T> class TBTreeItem {
public:
	TBTreeItem(std::shared_ptr<T> figure, int Key);
	TBTreeItem(const TBTreeItem<T>& orig);
	TBTreeItem<T>* find(int Key);
	void print(std::ostream& os);
	void push(TBTreeItem<T> *item);
	void * operator new (size_t size);
	void operator delete(void *p);
	std::shared_ptr<T> GetFigure();
	TBTreeItem<T>* findMostLeft();
	TBTreeItem<T>* findMostRight();
	TBTreeItem<T>* getNext();

	template <class A> friend std::ostream& operator<<(std::ostream& os, const TBTreeItem<A>& obj);
	virtual ~TBTreeItem();
	
private:
	std::shared_ptr<T> figure;
	int Key;
	TBTreeItem<T> *left;
	TBTreeItem<T> *right;
	TBTreeItem<T> *fath;

	static TAllocationBlock btreeitem_allocator;
};

#endif

#include "TBTreeItem.h"
#include <memory>



template <class T> TBTreeItem<T>::TBTreeItem(std::shared_ptr<T> figure, int Key) {
	this->figure = figure;
	this->Key = Key;
	this->left = nullptr;
	this->right = nullptr;
	this->fath = nullptr;
}


//template <class T> TBTreeItem<T>::TBTreeItem(const TBTreeItem<T>& orig) {
//	this->figure = orig.figure;
//	this->Key = orig.Key;
//	this->left = orig.left;
//	this->right = orig.right;
//	this->fath = orig.fath;
//}

template <class T> TBTreeItem<T>* TBTreeItem<T>::find(int Key) {
	if (!this) {
		return nullptr;
	}
	if (this->Key == Key) {
		return this;
	}
	TBTreeItem<T>* p = this->left->find(Key);
	if (p) {
		return p;
	}
	else {
		return this->right->find(Key);
	}

}

template <class T> void TBTreeItem<T>::push(TBTreeItem<T> *item) {
	if (!(this->left)) {
		this->left = item;
		item->fath = this;
	}
	else
		if (!(this->right)) {
			this->right = item;
			item->fath = this;
		}
		else {
			std::cout << "Нельзя добавить\n" << std::endl;
		}
}

template <class T> std::shared_ptr<T> TBTreeItem<T>::GetFigure() {
	return this->figure;
}


template <class T> TBTreeItem<T>::~TBTreeItem() {
	if (this->fath == nullptr) {
		return;
	}
	else {
		if (this->fath->left == this) {
			this->fath->left = nullptr;
		}
		else
			if (this->fath->right == this) {
				this->fath->right = nullptr;
			}
	}
	delete left;
	delete right;
}

template <class T> TBTreeItem<T>* TBTreeItem<T>::findMostLeft() {
	if (this->left == nullptr) {
		return this;
	}
	else {
		return this->left->findMostLeft();
	}
}

template <class T> TBTreeItem<T>* TBTreeItem<T>::findMostRight() {
	if (this->right == nullptr) {
		return this;
	}
	else {
		return this->right->findMostRight();
	}
}

template <class T> TBTreeItem<T>* TBTreeItem<T>::getNext() {
	TBTreeItem<T>* thisRoot = this;
	while (thisRoot->fath != nullptr) {
		thisRoot = thisRoot->fath;
	}
	TBTreeItem<T>* mostRight = thisRoot->findMostRight();
	if (this == mostRight) {
		return nullptr;
	}
	if (this->right == nullptr) {
		TBTreeItem<T>* ptr = this;
		while (ptr->fath->left != ptr) {
			ptr = ptr->fath;
		}
		return ptr->fath;
	}
	else {
		return this->right->findMostLeft();
	}
}

template <class T> std::ostream& operator<<(std::ostream& os, const TBTreeItem<T>& obj) {
	os << "Key = " << obj.Key << ", ";
	os << *obj.figure;
	return os;
}

template <class T> void TBTreeItem<T>::print(std::ostream& os) {
	static int level = 0;
	level++;
	if (this->left) {
		this->left->print(os);
	}

	for (int i = 0; i < level; ++i) {
		os << '\t';
	}
	os << *this << std::endl;
	if (this->right) {
		this->right->print(os);
	}
	level--;

}

template <class T> TAllocationBlock
TBTreeItem<T>::btreeitem_allocator(sizeof(TBTreeItem<T>), 100);

template <class T> TBTreeItem<T>::TBTreeItem(const TBTreeItem<T>& orig) {
	this->figure = orig.figure;
	this->Key = orig.Key;
	this->left = orig.left;
	this->right = orig.right;
	this->fath = orig.fath;
}

template <class T> void * TBTreeItem<T>::operator new (size_t size) {
	return btreeitem_allocator.allocate();
}

template <class T> void TBTreeItem<T>::operator delete(void *p) {
	btreeitem_allocator.deallocate(p);
}

#include "Figure.h"
template class TBTreeItem<Figure>;
template std::ostream& operator <<(std::ostream& os, const TBTreeItem<Figure>& obj);
#include "TBTree.h"
#include "TBTreeItem.h"
#include "TIterator.h"
#include <iostream>
#include <memory>


template <class T> TBTree<T>::TBTree() : root(nullptr) {
}

template <class T> TBTree<T>::TBTree(const TBTree<T>& orig) {
	root = orig.root;
	std::cout << "Создана копия дерева" << std::endl;
}


template <class T> void TBTree<T>::push(int PKey, int Key, std::shared_ptr<T> figure) {
	if (this->empty()) {
		root = new TBTreeItem<T>(figure, Key);
		return;
	}
	TBTreeItem<T> *newFather = root->find(PKey);
	if (!newFather) {
		std::cout << "Не найден родитель" << std::endl;
		return;
	}
	TBTreeItem<T> *other = new TBTreeItem<T>(figure, Key);
	newFather->push(other);
}

template <class T> std::shared_ptr<T> TBTree<T>::get(int Key) {
	TBTreeItem<T> *p = root->find(Key);
	std::shared_ptr<T> pent = p->GetFigure();
	return pent;
}

template <class T> int TBTree<T>::prov(int Key) {
	TBTreeItem<T> *p = root->find(Key);
	return (p != nullptr);
}


template <class T> void TBTree<T>::del(int Key) {
	TBTreeItem<T> *p = root->find(Key);
	if (p == root) {
		this->root = nullptr;
		return;
	}
	if (!p) {
		std::cout << "Фигура не найдена" << std::endl;
		return;
	}
	delete p;
}

template <class T> bool TBTree<T>::empty() {
	return (root == nullptr);
}

template <class T> TBTree<T>::~TBTree() {
	delete root;
}

template <class T> std::ostream& operator<<(std::ostream& os, const TBTree<T>& obj) {
	TBTreeItem<T> *rt = obj.root;
	rt->print(os);
	return os;
}

template <class T> TIterator<TBTreeItem<T>, T> TBTree<T>::begin() {
	TBTreeItem<T>* mostLeft;
	mostLeft = this->root->findMostLeft();
	return TIterator<TBTreeItem<T>, T>(mostLeft);
}

template <class T> TIterator<TBTreeItem<T>, T> TBTree<T>::end() {
	return TIterator<TBTreeItem<T>, T>(nullptr);
}

#include "Figure.h"
template class TBTree<Figure>;
template std::ostream& operator << (std::ostream& os, const TBTree<Figure>& obj);
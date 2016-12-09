#include <cstdlib>
#include <iostream>
#include <memory>

#include "TBTreeItem.h"
#include "TBTree.h"

#include "TAllocationBlock.h"

void menu() {
	std::cout << "Menu:";
	std::cout << "m - menu\n";
	std::cout << "v - �������� ������\n";
	std::cout << "s - ����� ������\n";
	std::cout << "d - ������� ������\n";
	std::cout << "p - ������ ������\n";
	std::cout << "e - �����\n";
}

int main() {
	int Key, PKey;
	char i;
	setlocale(LC_ALL, "Russian");
	std::shared_ptr<TBTree<Figure>> tree(new (TBTree<Figure>));
	Pentagon *pentagon = new Pentagon;
	Hexagon *hexagon = new Hexagon;
	Rhombus *rhombus = new Rhombus;
	std::shared_ptr<Figure> figPtr;
	menu();
	std::cout << "";
	while (std::cin >> i) {
		switch (i)
		{
		case 'v':
			std::cout << "������� ���� ��������:\n";
			std::cout << "���� �������� ���, ������� ����� �����\n";
			std::cin >> PKey;
			std::cout << "������� ���� ��������\n";
			std::cin >> Key;
			int newCheck;
			std::cout << "������� 1 (- rhombus), 2 (- pentagon) or 3 (- hexagon):\n";
			std::cin >> newCheck;
			if (newCheck == 2) {
				std::cin >> *pentagon;
				figPtr = std::shared_ptr<Figure>(pentagon);
				tree->push(PKey, Key, figPtr);
				pentagon = new Pentagon;
			}
			else if (newCheck == 3) {
				std::cin >> *hexagon;
				figPtr = std::shared_ptr<Figure>(hexagon);
				tree->push(PKey, Key, figPtr);
				hexagon = new Hexagon;
			}
			else if (newCheck == 1) {
				std::cin >> *rhombus;
				figPtr = std::shared_ptr<Figure>(rhombus);
				tree->push(PKey, Key, figPtr);
				rhombus = new Rhombus;
			}
			else {
				std::cout << "������ �����\n";
			}
			break;
		case 's':
			if (tree->empty()) {
				std::cout << "������ ������";
				std::cout << std::endl;
				break;
			}
			std::cout << "������� ����\n";
			std::cin >> Key;
			if (tree->prov(Key)) {
				figPtr = tree->get(Key);
				std::cout << "����� �������:\n";
				std::cout << *figPtr << std::endl;
			}
			else {
				std::cout << "������� �� ������\n";
			}
			break;
		case 'd':
			if (tree->empty()) {
				std::cout << "������ ������";
				std::cout << std::endl;
				break;
			}
			std::cout << "������� ����\n";
			std::cin >> Key;
			tree->del(Key);
			break;
		case 'p':
			if (tree->empty()) {
				std::cout << "������ ������";
				std::cout << std::endl;
				break;
			}
			std::cout << *tree << std::endl;
			break;
		case 'm':
			menu();
			break;
		case 'e':
			return 0;
			break;
		default:
			std::cout << "������������ ����\n";

		}
		std::cout << ">";
	}
	std::cout << "\b";
	return 0;
}
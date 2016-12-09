#include "RHOMBUS.h"
#include <iostream>
#include <cmath>

Rhombus::Rhombus() : Rhombus(0, 0) {}

Rhombus::Rhombus(size_t i, size_t j) : diag_a(i), diag_b(j) {}

Rhombus::Rhombus(const Rhombus& orig) {
	diag_a = orig.diag_a;
	diag_b = orig.diag_b;
}

double Rhombus::Square() {
	return  (double(diag_a))*(double(diag_b)) / 2.0;
}

void Rhombus::Print() {
	std::cout << "Ромб с диагоналями : " << diag_a << ", " << diag_b;

}

std::istream& operator >> (std::istream &is, Rhombus& romb) {
	std::cout << "Введите диагонали ромба: ";
	is >> romb.diag_a;
	is >> romb.diag_b;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Rhombus& romb) {
	os << "Ромб с диагоналями: " << romb.diag_a << ", " << romb.diag_b;
	return os;
}

Rhombus& Rhombus::operator= (const Rhombus& orig) {
	if (this == &orig)
		return *this;
	diag_a = orig.diag_a;
	diag_b = orig.diag_b;
	return *this;
}

bool operator == (const Rhombus& left, const Rhombus& right) {
	return bool(left.diag_a == right.diag_a) && bool(left.diag_b == right.diag_b);
}
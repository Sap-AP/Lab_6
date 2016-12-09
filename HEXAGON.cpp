#include "HEXAGON.h"
#include <iostream>
#include <cmath>

Hexagon::Hexagon() : Hexagon(0) {}

Hexagon::Hexagon(size_t a) : side(a) {}

Hexagon::Hexagon(const Hexagon& orig) {
	side = orig.side;
}

double Hexagon::Square() {
	return 0.5 * 3 * sqrt(3) * side * side;
}

void Hexagon::Print() {
	std::cout << "6-угольник со стороной: " << side;
}

std::istream& operator >> (std::istream &is, Hexagon& pent) {
	std::cout << "¬ведите сторону шестиугольника: ";
	is >> pent.side;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Hexagon& pent) {
	os << "Ўестиугольник со стороной: " << pent.side;
	return os;
}

Hexagon& Hexagon::operator= (const Hexagon& orig) {
	if (this == &orig)
		return *this;
	side = orig.side;
	return *this;
}

bool Hexagon::operator== (const Hexagon& right) {
	if (side == right.side)
		return true;
	return false;
}
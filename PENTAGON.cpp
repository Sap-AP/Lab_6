#include <iostream>
#include <cmath>
#include "Pentagon.h"

#define pi 3.14159265

Pentagon::Pentagon() : Pentagon(0) {}

Pentagon::Pentagon(size_t i) : radius(i) {}

Pentagon::Pentagon(const Pentagon& orig) {
	radius = orig.radius;
}

double Pentagon::Square() {
	return 2.5*pow(double(radius), 2.0)*sin(2.0*pi / 5.0);
}

void Pentagon::Print() {
	std::cout << "5-угольник с радиусом: " << radius;
}

std::istream& operator >> (std::istream &is, Pentagon& pent) {
	std::cout << "Введите радиус пятиугольника: ";
	is >> pent.radius;
	return is;
}

std::ostream& operator<<(std::ostream &os, const Pentagon& pent) {
	os << "Пятиугольник с радиусом: " << pent.radius;
	return os;
}

Pentagon& Pentagon::operator= (const Pentagon& orig) {
	if (this == &orig)
		return *this;
	radius = orig.radius;
	return *this;
}

bool Pentagon::operator== (const Pentagon& right) {
	if (radius == right.radius)
		return true;
	return false;
}
#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <cstdlib>
#include <iostream>
#include "FIGURE.h"

class Rhombus : public Figure {
public:
	Rhombus();
	Rhombus(size_t i, size_t j);
	Rhombus(const Rhombus& orig);

	double Square() override;
	void Print() override;

	friend std::istream& operator >> (std::istream &is, Rhombus& romb);
	friend std::ostream& operator <<(std::ostream &os, const Rhombus& romb);
	Rhombus& operator= (const Rhombus& orig);
	friend bool operator == (const Rhombus& left, const Rhombus& right);

private:
	size_t diag_a;
	size_t diag_b;
};

#endif

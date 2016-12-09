#ifndef HEXAGON_H
#define HEXAGON_H

#include <iostream>
#include "Figure.h"

class Hexagon : public Figure {
public:
	Hexagon();
	Hexagon(size_t a);
	Hexagon(const Hexagon& orig);
	double Square() override;
	void Print() override;
	friend std::istream& operator >> (std::istream &is, Hexagon& pent);
	friend std::ostream& operator <<(std::ostream &os, const Hexagon& pent);
	Hexagon& operator= (const Hexagon& orig);
	bool operator== (const Hexagon& right);
private:
	size_t side;
};

#endif

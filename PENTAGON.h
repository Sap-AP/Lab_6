#ifndef PENTAGON_H
#define PENTAGON_H

#include <iostream>
#include "Figure.h"

class Pentagon : public Figure {
public:
	Pentagon();
	Pentagon(size_t i);
	Pentagon(const Pentagon& orig);
	double Square() override;
	void Print() override;
	friend std::istream& operator >> (std::istream &is, Pentagon& pent);
	friend std::ostream& operator <<(std::ostream &os, const Pentagon& pent);
	Pentagon& operator= (const Pentagon& orig);
	bool operator== (const Pentagon& right);
private:
	size_t radius;
};


#endif

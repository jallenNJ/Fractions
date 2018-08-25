#ifndef FRACTION_H
#define FRACTION_H

#include <math.h>





class Fraction {
public:

	Fraction();
	Fraction(int, int);
	~Fraction();

	void setNumerator(int num) {
		fraction[0] = num;
	}
	void setDenominator(int den) {
		if (den == 0) {
			isUndefined = true;
			fraction[1] = 1;
			return;
		}
		if (den < 0) {
			fraction[0] *= -1;
		}
		fraction[1] = abs(den);
	}
private:
	int* fraction;
	bool isUndefined;
};





#endif // !FRACTION_H

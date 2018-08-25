#ifndef FRACTION_H
#define FRACTION_H

#include <math.h>





class Fraction {
public:

	Fraction();
	Fraction(int, int);
	~Fraction();


	void scale(int);

	Fraction operator+(Fraction other) {
		return addFractions(other);
	}


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
	int getNumerator() {
		return fraction[0];
	}

	int getDenominator() {
		return fraction[1];
	}

	void addToNumerator(int increase) {
		fraction[0] += increase;
	}

	bool isZero() {
		return fraction[0] != 0;
	}

	
private:
	int fraction[2];
	bool isUndefined;
	Fraction addFractions(Fraction);

	bool sameDenominator(Fraction other) {
		return fraction[1] == other.getDenominator();
	}

	void addToDenomiator(int increase) {
		fraction[1] += increase;
		if (fraction[1] == 0) {
			isUndefined = true;
			fraction[1] = 1;
		}
		else {
			isUndefined = false; 
		}
	}
};





#endif // !FRACTION_H

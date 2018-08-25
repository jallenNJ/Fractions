#include "Fraction.h"


Fraction::Fraction() {
	fraction = new int[2];
	setNumerator(1);
	setDenominator(1);
}

Fraction::Fraction(int num, int den) {
	fraction = new int[2];
	setNumerator(num);
	setDenominator(den);
}

Fraction::~Fraction() {
	delete fraction;
}
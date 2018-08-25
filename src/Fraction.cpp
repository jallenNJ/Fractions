#include "Fraction.h"


Fraction::Fraction() {
	setNumerator(1);
	setDenominator(1);
}

Fraction::Fraction(int num, int den) {
	setNumerator(num);
	setDenominator(den);
}

Fraction::~Fraction() {

}

Fraction Fraction::addFractions(Fraction other) {
	if (!sameDenominator(other)) {
		//HANDLE DIFFERENT BASES
	}

	return Fraction(getNumerator() + other.getNumerator(), getDenominator());


}
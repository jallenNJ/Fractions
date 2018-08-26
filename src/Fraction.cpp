#include "Fraction.h"


Fraction::Fraction() {
	undefined = false;
	setNumerator(1);
	setDenominator(1);
}

Fraction::Fraction(int num, int den) {
	undefined = false;
	setNumerator(num);
	setDenominator(den);
}

Fraction::~Fraction() {

}

Fraction Fraction::addFractions(Fraction other) {
	int thisNumerator = getNumerator();
	int otherNumerator = other.getNumerator();
	int sharedDenominator = getDenominator();
	if (!sameDenominator(other)) {
		sharedDenominator = findLCM(other.getDenominator());
		int ourScale = sharedDenominator / getDenominator();
		int theirScale = sharedDenominator / other.getDenominator();

		thisNumerator *= ourScale;
		otherNumerator *= theirScale;

	}

	return Fraction(thisNumerator + otherNumerator, sharedDenominator);


}

int Fraction::findLCM( int otherDenominator) {
	long product = fraction[1] * otherDenominator;
	int LCM = product / findGCD(otherDenominator);
	return LCM;
}


//GCD using Euclid's algorithm
// let a = denominator and b = otherDenomiator
// if a and b are postive then the GCD can be found by
// GCD(a,b) = a where a=b
// GCD(a,b) = GCD(a-b,b) where a>b
// GCD(a,b) = GCV(a,b-a) where b > a
int Fraction::findGCD(int otherDenominator) {
	if (undefined) {
		return otherDenominator;
	} 
	int denominator = fraction[1]; //Save in local var for readbility and allow for it to be modified

	if (denominator == otherDenominator || otherDenominator == 0) {
		return denominator;
	}
	if (otherDenominator < 0) { //As this function is public, cannot assure that parameter will abide by rules of data structure
		otherDenominator = abs(otherDenominator);
	}
	while (true) {

		if (denominator == otherDenominator) {
			return denominator;
		}

		if (denominator > otherDenominator) {
			denominator -= otherDenominator;
		} else {
			otherDenominator -= denominator;
		}
	}

}
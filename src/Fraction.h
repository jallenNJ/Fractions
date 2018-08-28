#ifndef FRACTION_H
#define FRACTION_H

#include <math.h> //For abs()





class Fraction {
public:

	//Constructors and destructors
	Fraction();
	Fraction(int, int);
	Fraction(float);
	~Fraction();

	int findLCM(int);
	int findGCD(int);

	Fraction operator+(Fraction other) {
		return addFractions(other);
	}

	Fraction operator+(int incrementAmount) {
		return Fraction(getNumerator() + (incrementAmount * getDenominator()), getDenominator());
	}


	void setNumerator(int num) {
		fraction[0] = num;
	}

	void setDenominator(int den) {
		if (den == 0) {
			undefined = true;
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
		return fraction[0] == 0;
	}

	bool isUndefined() {
		return undefined;
	}
	void scale(int scaleFactor) {
		fraction[0] *= scaleFactor;
		fraction[1] *= scaleFactor;
	}

	float toFloat() {
		return (float)getNumerator() / (float)getDenominator();
	}

	double toDouble() {
		return (double)getNumerator() / (double)getDenominator();
	}
	operator float() {
		return toFloat();
	}
	operator double() {
		return toDouble();
	}

	
private:
	int fraction[2];
	bool undefined;
	Fraction addFractions(Fraction);

	bool sameDenominator(Fraction other) {
		return fraction[1] == other.getDenominator();
	}

	void addToDenomiator(int increase) {
		fraction[1] += increase;
		if (fraction[1] == 0) {
			undefined = true;
			fraction[1] = 1;
		}
		else {
			undefined = false; 
		}
	}

	void reduceFraction() {
		while (true) {
			int newGcd = findGCD(getNumerator());
			if (newGcd <= 1) {
				break;
			}
			setNumerator(getNumerator() / newGcd);
			setDenominator(getDenominator() / newGcd);
		}
	}
};





#endif // !FRACTION_H

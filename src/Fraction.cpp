#include "Fraction.h"


//No arg constructor sets to 1/1 
Fraction::Fraction() {
	undefined = false;
	setNumerator(1);
	setDenominator(1);
}


//Constructor to intialize a fraction with a set numerator and denominator
Fraction::Fraction(int num, int den) {
	undefined = false;
	setNumerator(num);
	setDenominator(den);
}


Fraction::Fraction(float floatToConvert ) {	
	undefined = false;
	float intPortion, decPart;
	decPart = modff(floatToConvert, &intPortion);

	float newNumerator = 0;
	int timesLooped = 0;
	while (decPart > 0) {
		float toParse = newNumerator + decPart;
		toParse *= 10;
		decPart = modff(toParse, &newNumerator);
		timesLooped++;
	}

	setDenominator((int)pow(10, timesLooped));
	setNumerator((int)newNumerator + ((int)intPortion * getDenominator()));
	reduceFraction();

}


//Destructor incase its needed
Fraction::~Fraction() {

}


Fraction Fraction::addFractions(Fraction other) {
	//Get the variables and store in local copy so changes dont effect member variables
	int thisNumerator = getNumerator();
	int otherNumerator = other.getNumerator();
	int sharedDenominator = getDenominator();

	if (!sameDenominator(other)) { //If the bases need to be swapped
		//Find the lowest shared denominator between them
		sharedDenominator = findLCM(other.getDenominator());

		//Find the scale factor each need to be multipled by to reach there
		int ourScale = sharedDenominator / getDenominator();
		int theirScale = sharedDenominator / other.getDenominator();

		//Apply the scaling
		thisNumerator *= ourScale;
		otherNumerator *= theirScale;

	}

	//Create new object
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

bool Fraction::reduceBy(int scaleDown) {
	if (getNumerator() % scaleDown != 0 || getDenominator() % scaleDown != 0) {
		return false;
	}
	setNumerator(getNumerator() / scaleDown);
	setDenominator(getDenominator() / scaleDown);
	return true;
}


Fraction Fraction::getReciprical() {

	int newNumerator = getDenominator();
	int newDenominator = getNumerator();


	if (undefined) {
		newNumerator = 0;
	}

	if (newDenominator < 0) {
		newDenominator = abs(newDenominator);
		newNumerator *= -1;
	}

	Fraction reciprical = Fraction(newNumerator, newDenominator);
	return reciprical;
}

void Fraction::applyReciprical() {
	
	int toDenom = getNumerator();
	bool applyNegative = false;
	if (toDenom < 0) {
		toDenom = abs(toDenom);
		applyNegative = true;
	}

	if (undefined) {
		undefined = false;
		setNumerator(0);
	}
	else {
		int toNum = getDenominator();
		if (applyNegative) {
			toNum *= -1;
		}
		setNumerator(toNum);
	}

	if (toDenom == 0) {
		undefined = true;
		setDenominator(1);
	}
	else {
		setDenominator(toDenom);

	}
}
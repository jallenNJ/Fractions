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

//Constructor to intialize a fraction from an exisiting floating point number
//Returns a close rationial approximation, for exact values, this is NOT the constructor to use.
Fraction::Fraction(float floatToConvert ) {	

	undefined = false;
	float intPortion, decPart;
	//Get the whole number, and the fraction portion in seperate variables
	decPart = modff(floatToConvert, &intPortion);

	float newNumerator = 0;
	int timesLooped = 0;
	//While there is still remaining value in the decimial.
	while (decPart > 0) {
		//Get the current parsed data, and multiple it by ten to move decimal over one.
		float toParse = newNumerator + decPart;
		toParse *= 10;
		
		//Seperate off the new decimial and increment counter
		decPart = modff(toParse, &newNumerator);
		timesLooped++;
	}
	
	//Set denominator to (10^ times looped)
	setDenominator((int)pow(10, timesLooped));
	//Numerator is equal to the decimial contents, + the whole number  converted to an improper fraction
	setNumerator((int)newNumerator + ((int)intPortion * getDenominator()));
	//Reduce to lowest terms
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

//This function finds and returns the Least Common Multiple of the current denonimator and the passed in value 

//The algoithm is multiple the two values together, and then devided by the Greatest common Divisor of the two. The result is floored before being returned.
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
	while (true) { //Loop breaks when the two values are equal.

		if (denominator == otherDenominator) {
			return denominator;
		}

		if (denominator > otherDenominator) { //Subtract the smaller value from the greater one
			denominator -= otherDenominator;
		} else {
			otherDenominator -= denominator;
		}
	}
}


//This function reduces both the numerator and the denominator by the specified amount if they are
//	both divisible by that amount

//RETURNS TRUE if the reduction was successfully
//RETURNS FALSE if both are not divisible by the inputted number. 
bool Fraction::reduceBy(int scaleDown) {
	if (getNumerator() % scaleDown != 0 || getDenominator() % scaleDown != 0) {
		return false;
	}
	setNumerator(getNumerator() / scaleDown);
	setDenominator(getDenominator() / scaleDown);
	return true;
}

//This function gets and returns the reciprical of the current fraction
// If the current fraction is a zero fraction, the returned fraction will have a denominator one created. (0/3 => 3/1)
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

//This function has the current fraction flip and become its reciprical in the same object. 
void Fraction::applyReciprical() {
	
	int toDenom = getNumerator();
	bool applyNegative = false;
	if (toDenom < 0) { //If the new denominator is currently negative
		toDenom = abs(toDenom);
		applyNegative = true;
	}

	if (undefined) { //If the fraction is currently undefined
		undefined = false;
		setNumerator(0);
	}
	else { //If the fraction is anything that isn't (x/0)
		int toNum = getDenominator();
		if (applyNegative) {
			toNum *= -1;
		}
		setNumerator(toNum);
	}

	if (toDenom == 0) { //If the fraction will become undefined when its a reciprical 
		undefined = true;
		setDenominator(1);
	}
	else {
		setDenominator(toDenom);
	}
}
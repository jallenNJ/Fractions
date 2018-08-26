#include "Fraction.h"
#include <assert.h> //For unit testing macro
int main(int argc, char* argv[]) {

	//Test adding two fractions with the same base
	Fraction frac1(2, 5);
	Fraction frac2(3, 5);
	Fraction frac3 = frac1 + frac2;
	assert("Adding two fractions with same base" && frac3.getNumerator() == 5 && frac3.getDenominator() == 5);
	//Test scaling a fraction
	frac1.scale(2);
	assert("Scaling frac by 2" && frac1.getNumerator() == 4 && frac1.getDenominator() == 10);

	//Testing the GCD function
	Fraction gcdTest(1, 48);
	assert("Testing GCD where a<b" && gcdTest.findGCD(180) == 12);
	assert("Testing GCD where a=b" && gcdTest.findGCD(48) == 48);
	Fraction gcdTest2(1, 426);
	assert("Testing GCD where a>b" && gcdTest2.findGCD(71) == 71);

	//Testing the LCM function
	Fraction lcmTest(1, 8);
	assert("Testing LCM where a < b" && lcmTest.findLCM(24) == 24);
	assert("Testing LCM where a = b" && lcmTest.findLCM(8) == 8);
	assert("Testing LCM where a > b" && lcmTest.findLCM(6) == 24);


	//Testing addition with different bases
	Fraction diffBaseAddition(1, 2);
	Fraction diffBaseAddition2(1, 4);
	Fraction diffBaseAdditionResult = diffBaseAddition + diffBaseAddition2;
	Fraction diffBaseAdditionResult2 = diffBaseAddition2 + diffBaseAddition;

	assert("Adding different base, larger base first" && diffBaseAdditionResult.getNumerator() == 3 && diffBaseAdditionResult.getDenominator() == 4);
	assert("Adding different base, smaller base first" && diffBaseAdditionResult2.getNumerator() == 3 && diffBaseAdditionResult2.getDenominator() == 4);
	
	//Testing intialzing edge cases
	Fraction divideByZero(1, 0);
	assert("Checking for intializing with zero being handled" && divideByZero.isUndefined() && divideByZero.getDenominator() != 0);

	Fraction intializedNegativeDenominator(2, -3);
	assert("Checking for proper handling of negative denomiator being moved to numerator" && intializedNegativeDenominator.getNumerator() < 0 && intializedNegativeDenominator.getDenominator() > 0);


	Fraction addingByAnInt(3, 5);
	addingByAnInt = addingByAnInt + 1;
	assert("Checking for adding by an int" && addingByAnInt.getNumerator() == 8 && addingByAnInt.getDenominator() == 5);
	addingByAnInt = addingByAnInt + 2;
	assert("Checking for adding by an int (second)" && addingByAnInt.getNumerator() == 18 && addingByAnInt.getDenominator() == 5);

	Fraction zeroFlagTest(0, 2);
	assert("Checking if a fraction set to zero is zero" && zeroFlagTest.isZero());
	zeroFlagTest= zeroFlagTest+ 1;
	assert("Checking if a fraction added away from zero clears flag" && zeroFlagTest.isZero() == false);
	zeroFlagTest = zeroFlagTest + -1; 
	assert("Checking if a fraction sets zero flag when adding a negative number " && zeroFlagTest.isZero());

	Fraction threeFourths(3, 4);
	assert("Checking toFloat and toDouble with two decimals"&& threeFourths.toFloat() == threeFourths.toDouble() && threeFourths.toDouble() == .75);
	Fraction oneTenth(1, 10);
	assert("Checking floating point accuracy of impercise converstion(float)" && oneTenth.toFloat() > .09 && oneTenth.toFloat() < .11);
	assert("Checking floating point accuracy of impercise converstion(double)" && oneTenth.toDouble() > .09 && oneTenth.toDouble() < .11);
	
	assert("Checking implict cast (float)" && (float)threeFourths == threeFourths.toFloat());
	assert("Checking implict cast (double)" && (double)threeFourths == threeFourths.toDouble());
	//If reached return, all unit tests passed. 
	return 0;
}

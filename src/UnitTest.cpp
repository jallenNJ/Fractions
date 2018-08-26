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




	//If reached return, all unit tests passed. 
	return 0;
}

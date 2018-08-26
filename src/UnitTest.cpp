#include "Fraction.h"
#include <assert.h>
int main(int argc, char* argv[]) {

	Fraction frac1(2, 5);
	Fraction frac2(3, 5);
	Fraction frac3 = frac1 + frac2;

	assert("Adding two fractions with same base" && frac3.getNumerator() == 5 && frac3.getDenominator() == 5);
	frac1.scale(2);
	assert("Scaling frac by 2" && frac1.getNumerator() == 4 && frac1.getDenominator() == 10);
	Fraction gcdTest(1, 48);
	assert("Testing GCD where a<b" && gcdTest.findGCD(180) == 12);
	assert("Testing GCD where a=b" && gcdTest.findGCD(48) == 48);
	Fraction gcdTest2(1, 426);
	assert("Testing GCD where a>b" && gcdTest2.findGCD(71) == 71);

	Fraction lcmTest(1, 8);
	assert("Testing LCM where a < b" && lcmTest.findLCM(24) == 24);
	assert("Testing LCM where a = b" && lcmTest.findLCM(8) == 8);
	assert("Testing LCM where a > b" && lcmTest.findLCM(6) == 24);

	return 0;
}

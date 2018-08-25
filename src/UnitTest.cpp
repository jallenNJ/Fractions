#include "Fraction.h"
#include <assert.h>
int main(int argc, char* argv[]) {

	Fraction frac1(2, 5);
	Fraction frac2(3, 5);
	Fraction frac3 = frac1 + frac2;

	assert("Adding two fractions with same base" && frac3.getNumerator() == 5 && frac3.getDenominator() == 5);
	frac1.scale(2);
	assert("Scaling frac by 2" && frac1.getNumerator() == 4 && frac1.getDenominator() == 10);
	return 0;
}

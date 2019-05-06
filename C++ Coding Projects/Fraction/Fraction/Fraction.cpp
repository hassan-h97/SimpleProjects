#include "Fraction.h"
Fraction::Fraction(int val1, int val2) {
	if (val2 == 0) {
		Numerator = 0;
		Denominator = 1;
		cout << "\nInvalid, the Denominator can't be 0. Fraction value replaced with 0\n";
	}
	else
		if (val2 < 0) { Numerator = -val1; Denominator = -val2; }
		else { Numerator = val1; Denominator = val2; }
}
void Fraction::setDenominator(int val) {
	if (val == 0) {
		Numerator = 0;
		Denominator = 1;
		cout << "\nInvalid, the Denominator can't be 0. Fraction value was replaced with 0\n";
	}
	else
		if (val < 0) { Numerator = -Numerator; Denominator = -val; }
		else { Denominator = val; }
}
Fraction Fraction::operator + (Fraction Fract) const {
	if (Denominator != Fract.getDenominator())
		return Fraction(Numerator * Fract.getDenominator() + Fract.getNumerator() * Denominator, Denominator * Fract.getDenominator());
	else 	return Fraction(Numerator + Fract.getNumerator(), Denominator);
}
Fraction Fraction::operator - (Fraction Fract) const {
	if (Denominator != Fract.getDenominator())
		return Fraction(Numerator * Fract.getDenominator() - Fract.getNumerator() * Denominator, Denominator * Fract.getDenominator());
	else	return Fraction(Numerator - Fract.getNumerator(), Denominator);
}
Fraction& Fraction::operator +=(Fraction Fract) {
	if (Denominator != Fract.getDenominator()) {
		Numerator = Numerator * Fract.getDenominator() + Fract.getNumerator() * Denominator;
		Denominator = Denominator * Fract.getDenominator();
	}
	else 	Numerator += Fract.getNumerator();
	return *this;
}
Fraction SumFraction(vector<Fraction> v) {
	Fraction	Sum;
	for (unsigned int i = 0; i < v.size(); i++) Sum = v[i] + Sum;
	return Sum;
}
int Fraction::Reduce() {
	int GCF = greatest_common_divisor(Numerator, Denominator);
	Numerator = Numerator / GCF;
	Denominator = Denominator / GCF;
	return GCF;
};

int greatest_common_divisor(int A, int B) {
	if (B == 0) return A;
	return abs(greatest_common_divisor(B, A % B));
}
void DisplayResult(Fraction Frac) {
	cout << "The fraction\t";
	Frac.DisplayFract();
	int GCF = Frac.Reduce();
	if ((GCF != 1) && (GCF != -1)) {
		cout << "\t smallest form is ";
		Frac.DisplayFract();
	}
	else cout << "\t cannot be reduced ";
	cout << "\tand its value is " << Frac.getValue() << endl;;
}

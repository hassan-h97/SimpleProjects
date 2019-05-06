#ifndef Fraction_H
#define Fraction_H

#include <iostream>
#include <vector>

using namespace std;

class Fraction
{
	int Numerator;
	int Denominator;
public:
	Fraction(int val1 = 0, int val2 = 1);
	~Fraction() {}

	int getNumerator() const { return Numerator; }
	int getDenominator() const { return Denominator; }
	double getValue() const { return (double)Numerator / Denominator; }

	void setNumerator(int val) { Numerator = val; }
	void setDenominator(int val);
	int Reduce(); // Reduces the fraction and returns the greatest divisor used 

	void DisplayFract() const {
		if (Denominator != 1)	cout << Numerator << "/" << Denominator;
		else					cout << Numerator;
	}
	void DisplayValue() const { cout << getValue(); }


	Fraction operator + (Fraction Fract) const;
	Fraction operator - (Fraction Fract) const;

	Fraction operator * (Fraction Fract) const
	{
		return Fraction(Numerator * Fract.getNumerator(), Denominator * Fract.getDenominator());
	}
	Fraction operator / (Fraction Fract) const
	{
		return Fraction(Numerator * Fract.getDenominator(), Denominator * Fract.getNumerator());
	}
	Fraction operator -()	const { return Fraction(-Numerator, Denominator); }

	Fraction& operator +=(Fraction Fract);
};

Fraction SumFraction(vector<Fraction> v);
int greatest_common_divisor(int A, int B);
void DisplayResult(Fraction Frac);

#endif

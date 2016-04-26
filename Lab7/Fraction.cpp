// Brendan O'Connor
// 3/14/16
// Lab 7

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD( int num1, int num2 )
{
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
} 

// Reduce/simplify a fraction
void Fraction::reduce()
{
    // Alter this function later to adjust for negative values
	int gcd = getGCD(m_num, m_denom);
	m_num /= gcd;
	m_denom /= gcd;
} 

// initialize the fraction to 0/0 if no parameters passed
Fraction::Fraction() {
	m_num = 0;
	m_denom = 0;
}

// initialize the fraction to numerator / denominator
Fraction::Fraction(int numerator, int denominator) {
	m_num = numerator;
	m_denom = denominator;
}

// Output the numerator and denominator seperated by a forward slash
ostream& operator<<(ostream& output, const Fraction& fract) {
	output << fract.m_num << "/" << fract.m_denom;
	return output;
}

// read in the first number to numerator remove the slash and 
// read in the second number to denominator
istream& operator>>(istream& input, Fraction& fract) {
	char slash;
	input >> fract.m_num >> slash >> fract.m_denom;
	return input;
}

// put fractions in terms of common demoniator, add, then simplify
Fraction operator+(const Fraction& fract1, const Fraction& fract2) {
	int num = (fract1.m_num*fract2.m_denom) + (fract2.m_num*fract1.m_denom);
	int denom = fract1.m_denom * fract2.m_denom;
	Fraction sum(num, denom);
	sum.reduce();
	return sum;
}

// put fractions in terms of common demoniator, subtract, then simplify
Fraction operator-(const Fraction& fract1, const Fraction& fract2) {
	int num = (fract1.m_num*fract2.m_denom) - (fract2.m_num*fract1.m_denom);
	int denom = fract1.m_denom * fract2.m_denom;
	Fraction dif(num, denom);
	dif.reduce();
	return dif;
}

// multiply numerators and denominators then simplify
Fraction operator*(const Fraction& fract1, const Fraction& fract2) {
	int num = fract1.m_num * fract2.m_num;
	int denom = fract1.m_denom * fract2.m_denom;
	Fraction product(num, denom);
	product.reduce();
	return product;
}

// multiply the fraction 1 times the inverse of fraction 2 then simplify
Fraction operator/(const Fraction& fract1, const Fraction& fract2) {
	int num = fract1.m_num * fract2.m_denom;
	int denom = fract1.m_denom * fract2.m_num;
	Fraction div(num, denom);
	div.reduce();
	return div;
}

// simplify then compare the numerators and denominators
// if both are the same return true else false
bool operator==(Fraction fract1, Fraction fract2) {
	fract1.reduce();
	fract2.reduce();
	if ((fract1.m_num == fract2.m_num) && (fract1.m_denom == fract2.m_denom)) {
		return true;
	}
	else {
		return false;
	}
}
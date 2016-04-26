// Brendan O'Connor
// 3/14/16
// Lab 7

#include <iostream>
using namespace std;

class Fraction
{

// Add the variables and functions you need to. getGCD and reduce are 
// provided for you.

private:
	int getGCD( int num1, int num2 );
	int m_num;
	int m_denom;

public:
	void reduce();
	Fraction();
	Fraction(int numerator, int denominator);
	friend ostream& operator<<(ostream& output, const Fraction& fract);
	friend istream& operator>>(istream& input, Fraction& fract);
	friend Fraction operator+(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator-(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator*(const Fraction& fract1, const Fraction& fract2);
	friend Fraction operator/(const Fraction& fract1, const Fraction& fract2);
	friend bool operator==(Fraction fract1, Fraction fract2);
};


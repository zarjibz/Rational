/*   Based on an example from C++ How To Program (Deitel and Deitel)
*   Modified by cz
*   Modified by rbh
*   Modified by nas 12/01/17
*/

#include <cmath>
#include <cassert>
#include "rational.h"

////////////////////////////////////////////////////////////////////////////////

Rational::Rational()
{
	num = 0;
	denom = 1;
}

Rational::Rational(int numerator, int denominator)
{
	num = numerator;
	denom = denominator;
	reduce();
}

Rational::Rational(int i)
{
	num = i;
	denom = 1;
}

Rational::Rational(double r)
{
	bool implemented = false;
	assert(implemented);
}

////////////////////////////////////////////////////////////////////////////////

Rational Rational::operator+(const Rational & r) const
/*
*  a/b + c/d = (a*d + b*c) / b*d
*/
{
	return Rational(num * r.denom + denom * r.num, denom * r.denom);
}

Rational Rational::operator-(const Rational & r) const
/*
*  a/b - c/d = (a*d - b*c) / b*d
*/
{
	bool implemented = false;
	assert(implemented);
	return Rational(0);
}

Rational Rational::operator*(const Rational & r) const
/*
*  (a/b) * (c/d) = (a*c) / (b*d)
*/
{
	bool implemented = false;
	assert(implemented);
	return Rational(0);
}

Rational Rational::operator/(const Rational & r) const
/*
*  (a/b) / (c/d) = (a*d) / (b*c)
*  Division by zero throws a DivideByZeroErception
*/
{
	bool implemented = false;
	assert(implemented);
	return Rational(0);
}

////////////////////////////////////////////////////////////////////////////////

/* Comparison Operators
*
*  a/b < c/d
*  if
*     b > 0 (class invariant),
*     d > 0 (class invariant),
*  and
*     a*d < c*b
*/

bool Rational::operator<(const Rational & r) const
{
	bool implemented = false;
	assert(implemented);
	return false;
}

bool Rational::operator>(const Rational & r) const
{
	bool implemented = false;
	assert(implemented);
	return false;
}

bool Rational::operator<=(const Rational & r) const
{
	bool implemented = false;
	assert(implemented);
	return false;
}

bool Rational::operator>=(const Rational & r) const
{
	bool implemented = false;
	assert(implemented);
	return false;
}

bool Rational::operator==(const Rational & r) const
{
	bool implemented = false;
	assert(implemented);
	return false;
}

bool Rational::operator!=(const Rational & r) const
{
	bool implemented = false;
	assert(implemented);
	return false;
}

////////////////////////////////////////////////////////////////////////////////

Rational & Rational::operator+=(const Rational & r)
/*
*  a/b + c/d = (a*d + b*c) / b*d
*/
{
	bool implemented = false;
	assert(implemented);
	return *this;
}

Rational & Rational::operator-=(const Rational & r)
/*
*  a/b - c/d = (a*d - b*c) / b*d
*/
{
	bool implemented = false;
	assert(implemented);
	return *this;
}

Rational & Rational::operator*=(const Rational & r)
/*
*  (a/b) * (c/d) = (a*c) / (b*d)
*/
{
	bool implemented = false;
	assert(implemented);
	return *this;
}

Rational & Rational::operator/=(const Rational & r)
/*
*  (a/b) / (c/d) = (a*d) / (b*c)
*  Division by zero throws a DivideByZeroErception
*/
{
	bool implemented = false;
	assert(implemented);
	return *this;
}

////////////////////////////////////////////////////////////////////////////////

Rational Rational::abs(const Rational & r)
{
	bool implemented = false;
	assert(implemented);
	return r;
}

Rational Rational::negate(const Rational & r)
{
	bool implemented = false;
	assert(implemented);
	return r;
}

////////////////////////////////////////////////////////////////////////////////

long int gcd(long int i, long int j)
/*
*  Requires the arguments to be positive integers.
*  Note : This is an inefficent algorithm for computing the greatest common divisor.
*  It would be much better to use Euclid's Algorithm.
*/
{
	assert(i > 0);
	assert(j > 0);

	long int x = std::min(i, j);
	while (x > 1 && ((i % x != 0) || (j % x != 0)))
	{
		--x;
	}

	return x;

}

void Rational::reduce()
{
	if (denom == 0)
	{
		throw(DivideByZeroException());
	}

	if (denom < 0)
	{
		num = -num;
		denom = -denom;
	}

	if ((num == 0) || (denom == 1))
	{
		denom = 1;
	}
	else
	{
		int factor = gcd(std::abs(num), denom);
		num /= factor;
		denom /= factor;
	}
}

////////////////////////////////////////////////////////////////////////////////

std::ostream & operator<<(std::ostream & output, const Rational & r)
/*  Prints the numerator and denominator separated by '/'.
*  If the denominator is 1, then the '/' and denominator are omitted.
*/
{
	if (r.denom == 1)
	{
		output << r.num;
	}
	else
	{
		output << r.num << '/' << r.denom;
	}
	return output;
}

std::istream & operator >> (std::istream & input, Rational & r)
/*  Accepts either a pair of integers separated by '/', or a single integer
*  followed by a character other than '/'.
*  For any other input, the result is zero.
*/
{
	input >> r.num;
	if (input.peek() == '/')
	{
		input.ignore(1);
		input >> r.denom;
	}
	else
	{
		r.denom = 1;
	}
	r.reduce();
	return input;
}

////////////////////////////////////////////////////////////////////////////////

const char* DivideByZeroException::what() const throw() {
	return "Divide by zero";
}

////////////////////////////////////////////////////////////////////////////////
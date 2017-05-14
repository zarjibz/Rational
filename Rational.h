/*   Based on an example from C++ How To Program (Deitel and Deitel)
*   Modified by cz
*   Modified by rbh
*   Modified by nas 12/01/17
*/

#ifndef RATIONAL_H_NAS120117
#define RATIONAL_H_NAS120117

#include <iostream>

/*
* The Rational class represents rational numbers.
* Unlike floats and doubles, arithmetic operations on Rational objects introduce
* no rounding errors.
* Example string representations of Rationals include "2/3", "-7/8", "20/9" and "6".
*/

class Rational
{
public:

	/* Default constructor, initialises to 0  */
	Rational();

	/* Construct a Rational from a numerator and denominator. */
	Rational(int numerator, int denominator);

	/* Converting constructors */
	Rational(int);
	Rational(double);

	/* Arithmetic Operators */
	Rational operator+(const Rational &) const;
	Rational operator-(const Rational &) const;
	Rational operator*(const Rational &) const;
	Rational operator/(const Rational &) const; // Division by zero throws a DivideByZeroException

												/* Comparison operators */
	bool operator<(const Rational &) const;
	bool operator>(const Rational &) const;
	bool operator<=(const Rational &) const;
	bool operator>=(const Rational &) const;
	bool operator==(const Rational &) const;
	bool operator!=(const Rational &) const;

	/* Compund Assignment operators */
	Rational & operator+=(const Rational &);
	Rational & operator-=(const Rational &);
	Rational & operator*=(const Rational &);
	Rational & operator/=(const Rational &); // Division by zero throws a DivideByZeroException

	static Rational abs(const Rational & r);
	static Rational negate(const Rational & r);

	/*  Prints the numerator and denominator separated by '/'.
	*  If the denominator is 1, then the '/' and denominator are omitted.
	*/
	friend std::ostream & operator<<(std::ostream &, const Rational &);

	/*  Accepts either a pair of integers separated by '/', or a single integer
	*  followed by a character other than '/'.
	*  For any other input, the result is zero.
	*/
	friend std::istream & operator >> (std::istream &, Rational &);

private:
	/* A rational number can be represented as a ratio between two integers:
	called the numerator and denominator.
	*/
	long int num; // numerator
	long int denom; // denominator

					/* Class invariant: The fraction is stored in its simplest form (lowest terms).
					* Furthermore, the denominator is never negative; negative rational numbers
					* are represented using a negative numerator.
					*/

					/* Reduce a fraction to its lowest (simplest) terms.
					* This function is used internally to restore the class invariant after any
					* operation that could invalidate it.
					*/
	void reduce();
};

class DivideByZeroException : public std::exception
{
	const char* what() const throw() override;
};

std::ostream & operator<<(std::ostream &, const Rational &);

std::istream & operator >> (std::istream &, Rational &);

#endif
/* -----------------------------------------------------------------------------
FILE NAME:         Polynomial.h
DESCRIPTION:       Header file and Specification for Polynomial.cpp
USAGE:             ./poly_class
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Dallin Gomez       2022-03-28         1.0 From lab 5
Dallin Gomez       2022-03-28         2.0 added the + operator
Dallin Gomez       2022-03-28         3.0 added the - operator
Dallin Gomez       2022-03-28         4.0 added the * operator
Dallin Gomez       2022-03-29         5.0 added the << operator
Dallin Gomez       2022-03-29         6.0 added the >> operator
----------------------------------------------------------------------------- */
#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>

#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

using namespace std;

class Polynomial
{
	private:
		int degree;		// Degree of the polynomial
		int coef[9];		// Array of coefficients

	public:
		Polynomial();		// Constructor`

		Polynomial operator + (const Polynomial &); // Overloaded + operator
		Polynomial operator - (const Polynomial &); // Overloaded - operator
		Polynomial operator * (const Polynomial &); // Overloaded * operator

		friend ostream& operator << (ostream &, const Polynomial &); // overloaded << operator
		friend istream& operator >> (istream &, Polynomial &); // overloaded >> operator
};

#endif /* __POLYNOMIAL_H__ */

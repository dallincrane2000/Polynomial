/* -----------------------------------------------------------------------------
FILE NAME:         Polynomial.cpp
DESCRIPTION:       Implementation file for Polynomial Class
USAGE:             ./poly_class
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Dallin Gomez       2022-03-29         1.0 Created from Lab 5
Dallin Gomez       2022-03-28         2.0 Created the addition function
Dallin Gomez       2022-03-28         3.0 Created the subtraction function
Dallin Gomez       2022-03-28         4.0 Created the Multiplication function
Dallin Gomez       2022-03-29         5.0 Created the output <<
Dallin Gomez       2022-03-29         6.0 Created the input >>
----------------------------------------------------------------------------- */

#include "Polynomial.h"

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial()
DESCRIPTION:       Constructor initializes all values to 0
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
Polynomial::Polynomial()		// Constructor
{					// Initialize all values to 0
	degree = 0;
	
	for (int i = 0; i < ARRAY_SIZE(coef); i++)
		coef[i] = 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator + ()
DESCRIPTION:       Overloads the + operator
RETURNS:           p2
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator + (const Polynomial &p1)
{
	Polynomial p2;

	p2.degree = MAX(degree, p1.degree);

	for (int i = p2.degree; i >= 0; i--)
		p2.coef[i] = coef[i] + p1.coef[i];

	return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator - ()
DESCRIPTION:       Overloads the - operator
RETURNS:           p2
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator - (const Polynomial &p1)
{
        Polynomial p2;

        p2.degree = MAX(degree, p1.degree);

        for (int i = p2.degree; i >= 0; i--)
                p2.coef[i] = coef[i] - p1.coef[i];

        return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          Polynomial::operator * ()
DESCRIPTION:       Overloads the * operator
RETURNS:           p2
NOTES:             
------------------------------------------------------------------------------- */
Polynomial Polynomial::operator * (const Polynomial &p1)
{
        Polynomial p2;

        p2.degree = (degree + p1.degree);

        for(int i = degree; i >= 0; i--){
		for(int j = p2.degree; j >= 0; j--){
			p2.coef[i+j] += coef[i] * p1.coef[j];
		}
	}
        return p2;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator << ()
DESCRIPTION:       Overloads the << operator
RETURNS:           out
NOTES:             
------------------------------------------------------------------------------- */
ostream &operator << (ostream & out, const Polynomial &p)
{
	static int n;
        /*if(n < 2){
                out << "\nPolynomial    # " << ++n << "  is: ";
        }*/

        for (int i = p.degree; i >= 0; i--)
        {
                if (i < p.degree)
                {
                        if (p.coef[i] >= 0){
				out << " +";
			}
                        else{
				out << " ";
			}
                }
                out << p.coef[i];

                if (i>1){
			out << "x^" << i;
		}
                if (i==1){
			out << "x";
		}
        }

	return out;
}

/* -----------------------------------------------------------------------------
FUNCTION:          operator >> ()
DESCRIPTION:       Overloads the >> operator
RETURNS:           in
NOTES:             
------------------------------------------------------------------------------- */
istream &operator >> (istream & in, Polynomial &p)
{
	cout << "\nDegree of polynomial: ";
        in >> p.degree;

        cout << "\nEnter " << p.degree+1 << " coefficients: ";

        for (int i = p.degree; i >= 0; i--){
		in >> p.coef[i];
	}

	return in;
}

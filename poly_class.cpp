/* -----------------------------------------------------------------------------
FILE NAME:         poly_class.cpp
DESCRIPTION:       driver function
USAGE:             ./cs202_template
COMPILER:          GNU g++ compiler on Linux
NOTES:             

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Dallin Gomez       2022-03-28         1.0 from lab 5
Dallin Gomez       2022-03-28         2.0 added +, -, *
----------------------------------------------------------------------------- */
#include "Polynomial.h"		// Specification file

const char PROGRAMMER_NAME[] = "Dallin Gomez";	// Global Constant

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Driver function
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
	Polynomial poly[3];

	for (int i = 0; i < 2; i++)
	{
		cin >> poly[i];
		cout << "\nPoly " << i+1 << ":  ";
		cout << "p" << i+1 << " (x) = " << poly[i] << endl;
	}
	
	//cout << "poly 1: p1(x): "  
	//cout << "poly 2: p2(x): "  
	cout << "\npoly 1 + poly 2: ";
	poly[2] = poly[0] + poly [1];
	cout << poly[2] << endl;
	
	cout << "poly 1 - poly 2: ";
        poly[2] = poly[0] - poly [1];
        cout << poly[2] << endl;

	cout << "poly 1 * poly 2: ";
        poly[2] = poly[0] * poly [1];
        cout << poly[2] << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}


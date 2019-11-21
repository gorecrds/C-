/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 10/11/2019
 * Prof. Dave Harden
 * File: fraction.h, fraction.cpp
 * Descrip.:Program that introduces a class that does arithmetic operations (adding,subtracting, multiplying and dividing) with 2 fractions.
 * It also compares if fractions are equal by calling a method that returns either true  of false. It also introduces a constructor class as well as a function that simplifies fractions.
 */

#ifndef FRACTION_H
#define FRACTION_H


/*
The Fraction class can be used to create objects that store a Fraction, calculate it  over with another fraction.
The following functions are available:

Fraction();
  post: The calling object has been created and initialized to fraction 1/1

void set(int inNumerator, int inDenominator);
  post: The calling object has been modified so that the numerator is inNumerator and the denominator is inDenominator,

void print();
  post: The calling object has been printed to the console window in the format numerator/denominator.

Fraction multipliedBy (Fraction &argFraction);
  post: Arithmetic operations that calculate and returns the product of the calling object and the parameter

Fraction dividedBy (Fraction &argFraction);
  post: Arithmetic operations that calculate the quotient of the calling object and the parameter

Fraction addedTo (Fraction &argFraction);
  post: Arithmetic operations that calculate the sum of the calling object and the parameter

Fraction subtract (Fraction &argFraction);
  post: Arithmetic operations that calculate the difference of the calling object and the parameter

bool isEqualTo (Fraction &argFraction);
  post: Returns true if the calling object is equal to the  parameter "argFraction".  Otherwise
         returns false.

void simplify();
  post: The calling object has been reduced/simplified to lowest terms in the format numerator/denominator.
*/

class Fraction {
	//class declaration
	public: //member methods
	Fraction(); //default constructor
	Fraction (const int inNumerator, const int inDenominator); // class constructor
	//function prototype
	void print() const;
	Fraction multipliedBy (const Fraction &argFraction) const;
	Fraction dividedBy (const Fraction &argFraction) const;
	Fraction addedTo (const Fraction &argFraction) const;
	Fraction subtract (const Fraction &argFraction) const;
	bool isEqualTo (const Fraction &argFraction) const;


	private: //member variables.
	int numerator;
	int denominator;
	void simplify();
};

#endif

/*
The result starts off at 0/1
The product of 9/8 and 2/3 is 3/4
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.
The product of 3/2 and 2/3 is 1/1
 */

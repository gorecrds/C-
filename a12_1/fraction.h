/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 10/31/2019
 * Prof. Dave Harden
 * File: fraction.h, fraction.cpp
 * Description.:Program demonstrate the Fraction class that does arithmetic operations (adding,subtracting, multiplying, dividing, increments,decrements, simplification) with Fractions.
 * The current class provides a class to manipulate fractions where it supports supports mixed, proper and improper.It also compares fraction if they are equal, lesser or greater.
 * It also allows to get inputs from a data file. The program overloads operator to fully integrate the data type into the language,
 * so that it can behave as if it were a built-in data type.
 */

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>


/*
The Fraction class can be used to create objects that store a Fraction, calculate, compare it  over with another fraction.
The following functions are available:

Fraction (int inNumerator=0, int inDenominator=1);
  post: The calling object has been modified so that the numerator is inNumerator and the denominator is inDenominator. for a missing argument, the calling object initializes to fraction 0/1

friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
  post: The calling object has been modified to implement the stream insertion ('<<') to print to the console window in the format numerator/denominator or whole numerator/denominator or whole number.
  pre: Fractions right must contain valid values

friend std::istream& operator>>(std::istream& in, Fraction& fract_in);
  post: Implements the stream extraction operator ('>>') for the fraction class.Read any of the fraction formats such as mixed number, negative number, whole numbers, improper and proper fraction value from input.
  pre: input must be a whole number, a fraction with a numerator and denominator separated by a forward slash "/" or a mixed fraction separated by an arithmetic operator (e.g. -4+3/12, 1+1/4)

friend bool operator>(const Fraction &left, const Fraction &right);
  post: implements the relational operator ">" to the class Fraction and returns a boolean if 'left' greater that the 'right'.

friend bool operator>=(const Fraction &left, const Fraction &right);
  post: implements the relational operator ">=" to the class Fraction and returns a boolean if 'left' greater or equal to the 'right'.

friend bool operator<(const Fraction &left, const Fraction &right);
  post: implements the relational operator "<" to the class Fraction and returns a boolean if 'left' is less than the 'right'.

friend bool operator<=(const Fraction &left, const Fraction &right);
  post: implements the relational operator "<=" to the class Fraction and returns a boolean if 'left' less or equal to the 'right'.

friend bool operator==(const Fraction &left, const Fraction &right);
  post: implements the relational operator "==" to the class Fraction and returns a boolean if 'left' equal to the 'right'.

friend bool operator!=(const Fraction &left, const Fraction &right);
  post: implements the relational operator "!=" to the class Fraction and returns a boolean if 'left' is not equal to the 'right'.

friend Fraction operator+(const Fraction& left, const Fraction& right);
  post: implements Arithmetic operation '+' that calculate the sum between 'left' and 'right' fraction and returns the result

friend Fraction operator-(const Fraction& left, const Fraction& right);
  post: implements Arithmetic operation '-' that calculate the subtraction between 'left' and 'right' fraction and returns the result

friend Fraction operator*(const Fraction& left, const Fraction& right);
  post: implements Arithmetic operation '*' that calculate the product between 'left' and 'right' fraction and returns the result

friend Fraction operator/(const Fraction& left, const Fraction& right);
  post: implements Arithmetic operation '/' that calculate the division between of 'left' and 'right' fraction and returns the result

Fraction operator+=(const Fraction &right);
  post: implements the shorthand arithmetic assignment operators that return the addition of the current value of the calling object to the value on right.

Fraction operator-=(const Fraction &right);
  post: implements the shorthand arithmetic assignment operators that return the difference of the current value of the calling object to the value on right.

Fraction operator*=(const Fraction &right);
  post: implements the shorthand arithmetic assignment operators that return the product of the current value of the calling object to the value on right.

Fraction operator/=(const Fraction &right);
  post: implements the shorthand arithmetic assignment operators that return the quotient of the current value of the calling object to the value on right.

Fraction operator++();
  post: implement the postfix increment operator that return the calling object value added to 1 after the current expression is evaluated

Fraction operator++(int);
  post: implement the prefix increment operator that return the calling object value added to 1 before the current expression is evaluated

Fraction operator--();
  post: implement the postfix decrement operator that return the calling object subtracted to 1 after the current expression is evaluated

Fraction operator--(int);
  post: implement the prefix decrement operator that return the calling object subtracted to 1 before the current expression is evaluated


void simplify();
  post: The calling object has been reduced/simplified to lowest terms in the format numerator/denominator.
  pre: must contain valid data for numerator and denominator and a Fraction that can be reduced.
*/

namespace cs_fraction{
	class Fraction {
		//class declaration
		public: //member methods
		//function prototype
		Fraction (int inNumerator=0, int inDenominator=1); // class constructor
		friend std::ostream& operator<<(std::ostream& out, const Fraction& right);
		friend std::istream& operator>>(std::istream& in, Fraction& fract_in);
		friend bool operator>(const Fraction &left, const Fraction &right);
		friend bool operator>=(const Fraction &left, const Fraction &right);
		friend bool operator<(const Fraction &left, const Fraction &right);
		friend bool operator<=(const Fraction &left, const Fraction &right);
		friend bool operator==(const Fraction &left, const Fraction &right);
		friend bool operator!=(const Fraction &left, const Fraction &right);
		friend Fraction operator+(const Fraction& left, const Fraction& right);
		friend Fraction operator-(const Fraction& left, const Fraction& right);
		friend Fraction operator*(const Fraction& left, const Fraction& right);
		friend Fraction operator/(const Fraction& left, const Fraction& right);
		Fraction operator+=(const Fraction &right);
		Fraction operator-=(const Fraction &right);
		Fraction operator*=(const Fraction &right);
		Fraction operator/=(const Fraction &right);
		Fraction operator++();
		Fraction operator++(int);
		Fraction operator--();
		Fraction operator--(int);


		private: //member variables.
		int numerator;
		int denominator;
		void simplify();
	};
}






#endif


/*
----- Testing basic Fraction creation & printing
(Fractions should be in reduced form, and as mixed numbers.)
Fraction [0] = 1/2
Fraction [1] = -5/7
Fraction [2] = 10
Fraction [3] = -4
Fraction [4] = 0
Fraction [5] = 4+2/3
Fraction [6] = 0

----- Now reading Fractions from file
Read Fraction = 1/3
Read Fraction = 1/2
Read Fraction = 3/4
Read Fraction = -4/5
Read Fraction = 6
Read Fraction = 5
Read Fraction = -8
Read Fraction = 1+2/5
Read Fraction = -16+2/3
Read Fraction = 1+1/4
Read Fraction = 2
Read Fraction = -4+1/4
Read Fraction = -10+5/6

----- Testing relational operators between Fractions
Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing -1/2 to 1/2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing 1/2 to 1/10
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 1/10 to 0
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? true
Comparing 0 to 0
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? false

----- Testing relations between Fractions and integers
Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true
Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? true

----- Testing binary arithmetic between Fractions
1/6 + 1/3 = 1/2
1/6 - 1/3 = -1/6
1/6 * 1/3 = 1/18
1/6 / 1/3 = 1/2
1/3 + -2/3 = -1/3
1/3 - -2/3 = 1
1/3 * -2/3 = -2/9
1/3 / -2/3 = -1/2
-2/3 + 5 = 4+1/3
-2/3 - 5 = -5+2/3
-2/3 * 5 = -3+1/3
-2/3 / 5 = -2/15
5 + -1+1/3 = 3+2/3
5 - -1+1/3 = 6+1/3
5 * -1+1/3 = -6+2/3
5 / -1+1/3 = -3+3/4

----- Testing arithmetic between Fractions and integers
-1/2 + 4 = 3+1/2
-1/2 - 4 = -4+1/2
-1/2 * 4 = -2
-1/2 / 4 = -1/8
3 + -1/2 = 2+1/2
3 - -1/2 = 3+1/2
3 * -1/2 = -1+1/2
3 / -1/2 = -6

----- Testing shorthand arithmetic assignment on Fractions
1/6 += 4 = 4+1/6
4+1/6 -= 4 = 1/6
1/6 *= 4 = 2/3
2/3 /= 4 = 1/6
4 += -1/2 = 3+1/2
3+1/2 -= -1/2 = 4
4 *= -1/2 = -2
-2 /= -1/2 = 4
-1/2 += 5 = 4+1/2
4+1/2 -= 5 = -1/2
-1/2 *= 5 = -2+1/2
-2+1/2 /= 5 = -1/2

----- Testing shorthand arithmetic assignment using integers
-1/3 += 3 = 2+2/3
2+2/3 -= 3 = -1/3
-1/3 *= 3 = -1
-1 /= 3 = -1/3

----- Testing increment/decrement prefix and postfix
Now g = -1/3
g++ = -1/3
Now g = 2/3
++g = 1+2/3
Now g = 1+2/3
g-- = 1+2/3
Now g = 2/3
--g = -1/3
Now g = -1/3
 */

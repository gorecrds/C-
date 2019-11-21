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

#include <iostream>
#include <cassert>
#include "fraction.h"

using namespace std;


namespace cs_fraction{

	Fraction::Fraction (int inNumerator, int inDenominator) {
		//initializing member variables with parameters inNumerator and  inDenominator
		assert(inDenominator != 0);  // check to make sure that the second parameter is not a 0
		numerator=inNumerator;
		denominator=inDenominator;
		simplify();
	}







	//overloading operator "<<" stream (insertion operator)
	ostream& operator<<(ostream& out, const Fraction& right){

		int wholeNumber = (right.numerator / right.denominator);
		int remainder = right.numerator % right.denominator;
		Fraction result;

		if (remainder==0) { //remainder is 0 than it must be a whole number and must be returned to out
			out << wholeNumber;
		}else{
			if (abs(right.numerator)>abs(right.denominator)){ //if the absolute numerator is greater than the denominator out to be returned will be mixed/improper
				out << wholeNumber << "+" << abs(remainder) << "/" << right.denominator;
			} else { //else it is a proper fraction
				out << right.numerator << "/" << right.denominator;

			}
		}
		return out;
	}








	istream& operator>> (istream& in, Fraction& inFraction){
	    int inNum, inDen,wholeNumber;
	    in >> inNum;
	    //look ahead and identify which conditions is appropriate
	    if (in.peek() == '+'){ //condition for mixed fraction
	    	wholeNumber=inNum;
	    	in.ignore();
	    	in >> inNum;
	    	in.ignore();
	    	in >> inDen;
	    	inNum = wholeNumber > 0 ? abs(inDen * wholeNumber) + inNum: -1 *(abs(inDen * wholeNumber) + inNum); //reassign it back to positive or negative number
	    } else if (in.peek() == '/'){  //condition for proper and improper fraction
	    	in.ignore();
			in >> inDen;
	    } else { //condition for whole numbers
	    	inDen=1;
	    }
	    inFraction = Fraction(inNum, inDen);
	    return  in;
	}








	//overloading operator ">" greater than
	bool operator>(const Fraction& left, const Fraction& right){
		int leftValue=left.numerator*right.denominator;
		int rightValue=left.denominator*right.numerator;
		return leftValue>rightValue;
	}







	//overloading operator ">=" greater than or equal to
	bool operator>=(const Fraction& left, const Fraction& right){
		int leftValue=left.numerator*right.denominator;
		int rightValue=left.denominator*right.numerator;
		return leftValue>=rightValue;
	}







	//overloading operator "<" less than
	bool operator<(const Fraction& left, const Fraction& right){
		int leftValue=left.numerator*right.denominator;
		int rightValue=left.denominator*right.numerator;
		return leftValue<rightValue;
	}







	//overloading operator "<=" less than  or equal to
	bool operator<=(const Fraction& left, const Fraction& right){
		int leftValue=left.numerator*right.denominator;
		int rightValue=left.denominator*right.numerator;
		return leftValue<=rightValue;
	}







	//overloading operator "==" equal to.
	bool operator==(const Fraction& left, const Fraction& right){
		int leftValue=left.numerator * right.denominator;
		int rightValue=left.denominator * right.numerator;
		return leftValue==rightValue;
	}







	//overloading operator "!=" not equal to
	bool operator!=(const Fraction& left, const Fraction& right){
		int leftValue=left.numerator*right.denominator;
		int rightValue=left.denominator*right.numerator;
		return leftValue!=rightValue;
	}










	//overloading operator "+" plus
	Fraction operator+(const Fraction& left, const Fraction& right){
		Fraction result;
		result.numerator=(left.numerator*right.denominator)+(left.denominator*right.numerator);
		result.denominator=left.denominator*right.denominator;
		result.simplify();
		return result;
	}







	//overloading operator "-" minus
	Fraction operator-(const Fraction& left, const Fraction& right){
		Fraction result;
		result.numerator=(left.numerator*right.denominator)-(left.denominator*right.numerator);
		result.denominator=left.denominator*right.denominator;
		result.simplify();
		return result;
	}








	//overloading operator "*" multiply
	Fraction operator*(const Fraction& left, const Fraction& right){
		Fraction result;
		result.numerator=left.numerator*right.numerator;
		result.denominator=left.denominator*right.denominator;
		result.simplify();
		return result;
	}







	//overloading operator "/" division
	Fraction operator/(const Fraction& left, const Fraction& right){
		Fraction result;
		result.numerator=left.numerator*right.denominator;
		result.denominator=left.denominator*right.numerator;
		result.simplify();
		return result;
	}







	//overloading operator "+=" which first adds the current value of the variable on left to the value on right
	Fraction Fraction::operator+=(const Fraction& right){
		*this=*this+right;
		 return *this;
	 }







	//overloading operator "-=" which first subtracts the current value of the variable on left to the value on right
	Fraction Fraction::operator-=(const Fraction& right)
	 {

		*this=*this-right;
		 return *this;
	 }







	//overloading operator "*=" which first multiplies the current value of the variable on left to the value on right
	Fraction Fraction::operator*=(const Fraction& right)
	 {

		*this=*this*right;
		 return *this;
	 }







	//overloading operator "/=" which divides adds the current value of the variable on left to the value on right
	Fraction Fraction::operator/=(const Fraction& right)
	 {

		*this=*this/right;
		 return *this;
	 }









	//overloading operator "++" increment
	Fraction Fraction::operator++()
	{
		*this+=1;
		return *this;

	}







	//overloading operator "++" increment
	Fraction Fraction::operator++(int)
	{
		Fraction temp(numerator, denominator);  //declaration statement
		*this+=1;
		return temp;
	}






	//overloading operator "--" decrement
	Fraction Fraction::operator--()
	{
		*this-=1;
		return *this;

	}






	//overloading operator "--" decrement
	Fraction Fraction::operator--(int)
	{
		Fraction temp(numerator, denominator);  //declaration statement
		*this-=1;
		return temp;
	}







	//simplify/reduce the calling fraction
	void Fraction::simplify() {
		int min,divisor=2; //variable declaration

		//identifying the lowest number between a numerator and a denominator to deal with the fraction being proper and improper
		min=abs(numerator)<=abs(denominator)?numerator:denominator;
		// if denominator is negative, multiply both sides (numerator/denominator) by -1
		if (denominator<0){
			numerator*=-1; denominator*=-1;
		}
		//loop until the divisor is less than the min (lowest denominator)
		while (divisor<=abs(min) && denominator!=0){
			//attempt to divide by 2,3,4...min. if after dividing by the divisor, both the numerator and denominator result with
			//a remainder of 0, then both numbers share a common factor.
			if ((numerator % divisor == 0)&&(denominator % divisor == 0)) {
				//assign simplified numbers to numerator and denominator
				numerator /= divisor;
				denominator /= divisor;
				min=numerator<=denominator?numerator:denominator; //reassess and assign a new lowest denominator to the max possible divisor
			} else {
				divisor++; //increment divisor"
			}
		}
	}
}



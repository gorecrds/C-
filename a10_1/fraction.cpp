#include <iostream>
#include <cassert>
#include "fraction.h"

using namespace std;


//default constructor
Fraction::Fraction(){
	//initializing fraction as of 0/1
	numerator=0;
	denominator=1;
}






Fraction::Fraction (const int inNumerator,const int inDenominator) {
	//initializing member variables with parameters inNumerator and  inDenominator
	numerator=inNumerator;
	assert(inDenominator != 0);  // check to make sure that the second parameter is not a 0
	denominator=inDenominator;
	simplify(); //attempt to simplify

}





//function used to print an object fraction in the format x/y
void Fraction::print() const{
    cout << numerator << "/" << denominator;
}






//function used to multiple the object fraction times the fraction argument (argFraction)
Fraction Fraction::multipliedBy (const Fraction &argFraction) const {
    Fraction result;
    result.numerator=numerator*argFraction.numerator;
    result.denominator=denominator*argFraction.denominator;
    result.simplify();   //attempt to simplify
    return result;
}






//function used to quotient the object by the argument. Fraction divided by the fraction argument (argFraction)
Fraction Fraction::dividedBy(const Fraction &argFraction) const{
    Fraction result;
    result.numerator=numerator*argFraction.denominator;
    result.denominator=denominator*argFraction.numerator;
    result.simplify();  //attempt to simplify
	return result;
}






//function used to add the object fraction plus the fraction argument (argFraction)
Fraction Fraction::addedTo(const Fraction &argFraction) const{
    Fraction result;
    result.numerator=(numerator*argFraction.denominator)+(denominator*argFraction.numerator);
	result.denominator=denominator*argFraction.denominator;
    result.simplify();  //attempt to simplify
	return result;
}






//function used to subtract the object fraction minus the fraction argument (argFraction)
Fraction Fraction::subtract(const Fraction &argFraction) const{
    Fraction result;
    result.numerator=(numerator*argFraction.denominator)-(denominator*argFraction.numerator);
	result.denominator=denominator*argFraction.denominator;
    result.simplify();   //attempt to simplify
	return result;
}






//function used to compared the object fraction by the fraction argument (argFraction)
bool Fraction::isEqualTo (const Fraction &argFraction) const {
	bool result;
	result=((numerator*argFraction.denominator)==(denominator*argFraction.numerator)); //compare fractions to see ifthey are equal
	return  result;//return true of false
}





void Fraction::simplify() {
	int min,divisor=2; //variable declaration

	//identifying the lowest number between a numerator and a denominator to deal with the fraction being proper and improper
	if (numerator<=denominator){
		min=numerator; //lowest is the numerator
	}else{
		min=denominator; //lowest is  the denominator
	}

	//loop until the lowest number found in the fraction
	while (divisor<=min && denominator>0){
		//attempt to divide by 2,3,4...min. if after dividing by the divisor, both the numerator and denominator result with
		//a remainder of 0, then both numbers share a common factor.
		if ((numerator % divisor == 0)&&(denominator % divisor == 0)) {
			//assign simplified numbers to numerator and denominator
		    numerator /= divisor;
			denominator /= divisor;
		    min=numerator<=denominator?numerator:denominator; //reassess and assign the lowest number
		} else {
			divisor++; //increment divisor
		}
	}
}



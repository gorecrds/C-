/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 10/11/2019
 * Prof. Dave Harden
 * File: a9_1.cpp
 * Descrip.:Program that introduces a class that does arithmetic operations (adding,subtracting, multiplying and dividing) 2 fractions.
 * It also compares if fractions are equal by calling a method tha returns either true  of false.
  */
#include <iostream>
using namespace std;


/*
The Fraction class can be used to create objects that store a Fraction, calculate it  over with another fraction.
The following functions are available:

void set(int inNumerator, int inDenominator);
  post: The calling object has been modified so that the numerator is inNumerator and the denominator is inDenominator,

void print();
  post: The calling object has been printed to the console window in the format numerator/denominator.

Fraction multipliedBy (Fraction argFraction);
  post: Arithmetic operations that calculate and returns the product of the calling object and the parameter

Fraction dividedBy (Fraction argFraction);
  post: Arithmetic operations that calculate the quotient of the calling object and the parameter

Fraction addedTo (Fraction argFraction);
  post: Arithmetic operations that calculate the sum of the calling object and the parameter

Fraction subtract (Fraction argFraction);
  post: Arithmetic operations that calculate the difference of the calling object and the parameter


bool isEqualTo (Fraction argFraction);
  post: Returns true if the calling object is equal to the  parameter "argFraction".  Otherwise
         returns false.
*/

class Fraction {
	//class declaration
	public: //member methods
	void set(int inNumerator, int inDenominator);
	void print();
	Fraction multipliedBy (Fraction argFraction);
	Fraction dividedBy (Fraction argFraction);
	Fraction addedTo (Fraction argFraction);
	Fraction subtract (Fraction argFraction);
	bool isEqualTo (Fraction argFraction);

	private: //member variables.
	int numerator;
	int denominator;
};





//function used to set up a numerator and denominator to an object
void Fraction::set(int inNumerator, int inDenominator){
	numerator=inNumerator;
	denominator=inDenominator;
}






//function used to print an object fraction in the format x/y
void Fraction::print(){
    cout << numerator << "/" << denominator;
}






//function used to multiple the object fraction times the fraction argument (argFraction)
Fraction Fraction::multipliedBy (Fraction argFraction){
    Fraction result;
    result.numerator=numerator*argFraction.numerator;
    result.denominator=denominator*argFraction.denominator;
	return result;
}






//function used to quotient the object by the argument. Fraction divided by the fraction argument (argFraction)
Fraction Fraction::dividedBy(Fraction argFraction){
    Fraction result;
    result.numerator=numerator*argFraction.denominator;
    result.denominator=denominator*argFraction.numerator;
	return result;
}





//function used to add the object fraction plus the fraction argument (argFraction)
Fraction Fraction::addedTo(Fraction argFraction){
    Fraction result;
    result.numerator=(numerator*argFraction.denominator)+(denominator*argFraction.numerator);
	result.denominator=denominator*argFraction.denominator;
	return result;
}





//function used to subtract the object fraction minus the fraction argument (argFraction)
Fraction Fraction::subtract(Fraction argFraction){
    Fraction result;
    result.numerator=(numerator*argFraction.denominator)-(denominator*argFraction.numerator);
	result.denominator=denominator*argFraction.denominator;
	return result;
}





//function used to compared the object fraction by the fraction argument (argFraction)
bool Fraction::isEqualTo (Fraction argFraction) {
	bool result;
	result=((numerator*argFraction.denominator)==(denominator*argFraction.numerator)); //compare fractions to see ifthey are equal
	return  result;//return true of false
}






int main()
{
    Fraction f1; //Instantiating f1
    Fraction f2; //Instantiating f2
    Fraction result;

    f1.set(9, 8); //assignment of fraction
    f2.set(2, 3); //assignment of fraction

    //displaying f1 and f2 fractions and calculating the product
    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    //displaying f1 and f2 fractions and calculating the quotient
    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    //displaying f1 and f2 fractions and calculating the sum
    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    //displaying f1 and f2 fractions and calculating the difference
    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    //comparing if 2 fractions are equal
    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }

}
/*
The product of 9/8 and 2/3 is 18/24
The quotient of 9/8 and 2/3 is 27/16
The sum of 9/8 and 2/3 is 43/24
The difference of 9/8 and 2/3 is 11/24
The two Fractions are not equal.
*/

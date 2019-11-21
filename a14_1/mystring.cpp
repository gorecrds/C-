/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 11/17/2019
 * Prof. Dave Harden
 * File: mystringn.h, mystring.cpp
 * Description.:Program demonstrate the MyString class provides All six of the relational operators, constructors, overload the square brackets [ ]
 * the "Big-Three" member functions that are required when a class uses dynamic memory. The program overloads operator to fully integrate the data type into the language,
 * so that it can behave as if it were a built-in data type. The purpose of the program is to introduce a string class that adds easiness to working with c-strings.
 */
#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"



using namespace std;



//using namespace cs_mystring;
namespace cs_mystring {







	//default constructor
	MyString::MyString(){

		cString = new char[1];
		strcpy(cString, "");
	}








	//constructor
	MyString::MyString(const char *inString){

		cString = new char[strlen(inString)+1];
		strcpy(cString,inString);
	}









	//copy constructor
	MyString::MyString(const MyString &right){

		cString = new char[right.length()+1];
		strcpy(cString,right.cString);
	}









	//length method
	int MyString::length() const{

		return strlen(cString);
	}








	//overloading the assignment operator
	MyString MyString::operator = (const MyString &right){
        if (this != &right){

        	delete [] cString; //deallocating cString
            cString = new char[strlen(right.cString) + 1];
            strcpy(cString, right.cString);
        }

        return *this;
	}










	//overloading operator "<<" stream (insertion operator)
	std::ostream& operator << (std::ostream &out, const MyString &source){

		out<< source.cString;
		return out;
	}









	//overloading the extraction operator ">>".
    std::istream& operator>>(std::istream &in, MyString &target){

    	while (isspace(in.peek())){
            in.ignore();
        }

        char temp[MyString::MAX_INPUT_SIZE + 1]; //dynamic array with with the constant size of MAX_INPUT_SIZE + 1
        in >> temp;
        delete [] target.cString; //deallocating/deleting
        target.cString = new char[strlen(temp) + 1];

        strcpy(target.cString, temp);//copying temp to cString
        return in;
    }









    //overlaoding the  concatenate operator "+"
    MyString operator+( const MyString &left, const MyString &right )
    {

    	MyString result = new char [left.length() + right.length() + 1];
        strcpy(result.cString, left.cString); //copying left to result
        strcat(result.cString, right.cString); //concatenating right.cString with result.cString
        return result;
    }











    //overloading the combined Concatenation/Assignment Operator
    MyString &MyString::operator += (const MyString &right) {

    	*this =*this+right;
        return *this;
    }










    //Method read() function will allow the client programmer to specify the delimiting character
    void MyString::read(istream& in, char charStop) {

    	char readInLine[128];

        in.getline(readInLine, 128, charStop);
        delete [] cString;

        cString = new char [strlen(readInLine)];

        strcpy(cString, readInLine);
    }













	// Overloading [] operator to access elements in array style
	char MyString::operator [] (int index)const{

		assert(index >= 0 && index < (int)strlen(cString));
		return cString[index];
	}











	// Implementation of [] operator.  This function must return a
	// reference as array element can be put on left side
	char& MyString::operator [] (int index){

		assert(index >= 0 && index < (int)strlen(cString));
		return cString[index];
	}











	//overloading operator "<" lesser than
	bool operator < (const MyString &left,const MyString &right){

		return strcmp(left.cString,right.cString) < 0;
	}










	//overloading operator "<=" lesser equal than
	bool operator <= (const MyString &left,const MyString &right){

		return strcmp(left.cString,right.cString)<=0;
	}











	//overloading operator ">" greater than
	bool operator > (const MyString &left,const MyString &right){

		return strcmp(left.cString,right.cString) > 0;
	}











	//overloading operator ">=" greater euqal than
	bool operator >= (const MyString &left,const MyString &right){

		return strcmp(left.cString,right.cString) >= 0;
	}









	//overloading operator "!=" unequal than
	bool operator != (const MyString &left,const MyString &right){

		return strcmp(left.cString,right.cString) != 0;
	}










	//overloading operator "==" greater than
	bool operator == (const MyString &left,const MyString &right){

		return strcmp(left.cString,right.cString) == 0;
	}










    //Destructors for memory deallocation.
	MyString::~MyString(){
		// cSTring is true, deallocate
		if(cString){
			delete []cString;
		}
	}






}

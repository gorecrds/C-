/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 11/08/2019
 * Prof. Dave Harden
 * File: mystringn.h, mystring.cpp
 * Description.:Program demonstrate the MyString class provides All six of the relational operators, constructors, overload the square brackets [ ]
 * the "Big-Three" member functions that are required when a class uses dynamic memory.. The program overloads operator to fully integrate the data type into the language,
 * so that it can behave as if it were a built-in data type.
 */
#include <iostream>
#include <cassert>
#include "mystring.h"
#include <cstring>
#include <string>

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
            delete [] cString;
            cString = new char[strlen(right.cString) + 1];
            strcpy(cString, right.cString);
        }
        return *this;
	}






	//overloading operator "<<" stream (insertion operator)
	std::ostream& operator << (std::ostream &out, const MyString &right){
		out<< right.cString;
		return out;
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
		if(cString){
			delete []cString;
		}
	}






}

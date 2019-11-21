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

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

//using namespace cs_mystring;
namespace cs_mystring {

	class MyString{
		//class declaration
		public:
		//function prototype
		MyString();
		MyString(const char *inString);
		MyString(const MyString &inString);
		int length()const;
		MyString operator=(const MyString &right);
		friend std::ostream& operator<<(std::ostream &out, const MyString &right);
		char operator[](int index)const;
		char& operator[](int index);
		friend bool operator<(const MyString &left,const MyString &right);
		friend bool operator<=(const MyString &left,const MyString &right);
		friend bool operator>(const MyString &left,const MyString &right);
		friend bool operator>=(const MyString &left,const MyString &right);
		friend bool operator!=(const MyString &left,const MyString &right);
		friend bool operator==(const MyString &left,const MyString &right);
		~MyString();

		private: //member variable.
		char* cString;
	};

}

#endif


/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing apple to
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true
Comparing  to Banana
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing Banana to Banana
    Is left < right? false
    Is left <= right? true
    Is left > right? false
    Is left >= right? true
    Does left == right? true
    Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
    Is left < right? true
    Is left <= right? true
    Is left > right? false
    Is left >= right? false
    Does left == right? false
    Does left != right ? true
Comparing why to wackity
    Is left < right? false
    Is left <= right? false
    Is left > right? true
    Is left >= right? true
    Does left == right? false
    Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
*/

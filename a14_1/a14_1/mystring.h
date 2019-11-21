/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 11/17/2019
 * Prof. Dave Harden
 * File: mystringn.h, mystring.cpp
 * Description.:Program demonstrate the MyString class provides All six of the relational operators, constructors, overload the square brackets [ ]
 * the "Big-Three" member functions that are required when a class uses dynamic memory. The program overloads operator to fully integrate the data type into the language,
 * so that it can behave as if it were a built-in data type. The purpose of the program is to introduce a string class that adds easiness towards working with c-strings.
 */

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

//MyString class has the purpose o to introduce a string class that adds easiness and is prone to reduce errors when working with c-strings.

/*
		MyString();
		  Post:The calling object has been modified so that MyString has a c-string with ''.


		MyString(const char *inString);
		  Pre : inString is a c-string.
		  Post:The calling object has been modified so that inString is cString.



		MyString(const MyString &inString);
   		   Pre : inString is a c-string.
		   Post:The calling object has been modified so that MyStringis a copy of inString (copy of right)..


		int length()const;
		   Post: The calling object returns the number of a characters in a c-string.


		MyString operator=(const MyString &right);
		   Pre :right must be a MyString object.
		   Post:The calling object variable that is in the left points to a copy of right.


		friend std::ostream& operator<<(std::ostream &out, const MyString &source);
		   Pre :source must be a MyString object.
		   Post:The calling object has been modified to implement the stream insertion ('<<') to print to the console window.


		friend std::istream& operator>>(std::istream &in, MyString &target);
		   Pre :input must be a non-formatted text readable file.
		   Post:The calling object has been modified to implement the stream insertion ('>>') to read up to 127 characters ignoring the "#" symbol, ignoring initial spaces.


	    friend MyString operator+(const MyString &left, const MyString &right );
		   Pre :left and righr need to be either c-string of MyString
		   Post:The calling  object returns a concatenate string that combines left and right.


	    MyString &operator+=(const MyString &right);
		   Pre :MyStrings can be on the left-hand side of the += operation, but either MyStrings or C-strings may appear on the right side
		   Post:The calling object returns the assigned the value of the concatenation between right and cString.


		void read(std::istream& in, char charStop);
		   Pre :in is an istream and a character for charStop.
		   Post:The calling object read up to 127 characters and stops at the first occurrence thatmatches charStop.


		char operator[](int index)const;
		   Pre :The calling object must be a const MyString object.
		   Post:The Calling object returns the value in the cString index.


		char& operator[](int index);
		   Pre :The calling object must be MyString object.
		   Post:The Calling object returns the reference in the cString index.


		friend bool operator<(const MyString &left,const MyString &right);
		   Pre :left and right must be a c-string or MyString variable.
		   Post:Implements the relational operator "<" to the class MyString and returns a boolean if 'left' is less than the 'right' based on strcmp.


		friend bool operator<=(const MyString &left,const MyString &right);
		   Pre :left and right must be a c-string or MyString variable.
		   Post:Implements the relational operator "<=" to the class MyString and returns a boolean if 'left' is less or equal than the 'right' based on strcmp.


		friend bool operator>(const MyString &left,const MyString &right);
		   Pre :left and right must be a c-string or MyString variable.
		   Post:Implements the relational operator ">" to the class MyString and returns a boolean if 'left' is greater  than the 'right' based on strcmp.


		friend bool operator>=(const MyString &left,const MyString &right);
		   Pre :left and right must be a c-string or MyString variable.
		   Post:Implements the relational operator ">=" to the class MyString and returns a boolean if 'left' is greater or equal than the 'right' based on strcmp.


		friend bool operator!=(const MyString &left,const MyString &right);
		   Pre :left and right must be a c-string or MyString variable.
		   Post:Implements the relational operator "!=" to the class MyString and returns a boolean if 'left' is not equal to the 'right' based on strcmp.


		friend bool operator==(const MyString &left,const MyString &right);
		   Pre :left and right must be a c-string or MyString variable.
		   Post:Implements the relational operator "==" to the class MyString and returns a boolean if 'left' is equal to the 'right' based on strcmp.


		~MyString();
		   Pre :A memory must be allocated to cString.
		   Post:Dealocates/deletes the memory associated to cString




*/

//using namespace cs_mystring;
namespace cs_mystring {

	class MyString{
		//class declaration
		public:
		//function prototype
        static const int MAX_INPUT_SIZE = 127;
		MyString();
		MyString(const char *inString);
		MyString(const MyString &inString);
		int length()const;
		MyString operator=(const MyString &right);
		friend std::ostream& operator<<(std::ostream &out, const MyString &source);
		friend std::istream& operator>>(std::istream &in, MyString &target);
	    friend MyString operator+(const MyString &left, const MyString &right );
	    MyString &operator+=(const MyString &right);
	    MyString &operator+=(const char &right);
		void read(std::istream& in, char charStop);
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

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string =     read individual words, next
Read string = we read whole lines

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

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
 + cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo
 */

/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 08/17/2019
 * Prof. Dave Harden
 * File: a1_1.cpp
 * Descrip.:Program that asks the user to enter a date in the following format dd/mm/yy
 * and then determines if the date is a magic date. A magic date is when the multiplication of
 * the day times the  month equals the year.
 * Upon the execution of the program, the user will enter a date. The program will then multiply the
 * day times the month. If the result equal the year, then it  will display "That is a magic date!"
 */
#include<iostream>
#include<string>
using namespace std;

int main(){
	int day, month , year, calcNumber=0;
	char ch1, ch2;

	cout << "Enter a date in the  format month/day/2-digit-year: ";
	cin >> day >> ch1 >> month >> ch2 >> year;

	calcNumber=day*month;
	if ( calcNumber == year ){
		cout << "That is a magic date!";
	}
}

/* C:\Users\Im_Ig\eclipse-workspace\a1_1\Debug>a1_1
Enter a date in the  format month/day/2-digit-year: 6/10/60
That is a magic date! */

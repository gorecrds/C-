/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 09/20/2019
 * Prof. Dave Harden
 * File: a6_1.cpp
 * Descrip.:Program with 23 requirements that provides a good practice on how to pointer is work.
  */

#include <iostream>
using namespace std;

void noNegative(int *x); //prototype for function noNegative
void swap(int*, int*);  //prototype for function swap

int main() {
// 1. Create two integer variables named x and y.
int x,y; //declaring x and y

// 2. Create an int pointer named p1.
int* p1=nullptr; //declaring pointerp1 and initializing it with null value

// 3. Store the address of x in p1.
p1=&x; //p1 equals the address of x

// 4. Use only p1 (not x) to set the value of x to 99.
*p1=99;   //value pointed by p1 equals 99

// 5. Using cout and x (not p1), display the value of x.
cout <<"x contains: "<<x<<endl; //displaying the value of x

// 6. Using cout and the pointer p1 (not x), display the value of x.
cout <<"x contains: "<<*p1<<endl;  //displaying the value pointed by p1

// 7. Store the address of y into p1.
p1=&y;  //p1 equals the address of y

// 8. Use only p1 (not y) to set the value of y to -300.
*p1=-300;   //value pointed by p1 equals -300

// 9. Create two new variables: an int named temp, and an int pointer named p2. Make p2
//    point to x.
int temp, *p2=nullptr;   //declaring temp and pointer p2
p2=&x;                   //p2 equals the address of x

// 10. Use only temp, p1, and p2 (not x or y) to swap the values in x and y. (This will take
//     a few statements.   Don't use a swap function.)
temp = *p1; //Initializing temp with the value pointed to p1
*p1 = *p2;  //pointing the value of p1 to p2
*p2 = temp; //pointing the value of p2 to value of temp

// 11. Write a function with the following signature: void noNegatives(int *x). The function
//     should accept the address of an int variable. If the value of this integer is
//     negative then it should set it to zero.
//     Place the prototype for this function above the main function, and the definition
//     below main().
// 12. Invoke the function twice: once with the address of x as the argument, and once with
//     the address of y.  Use x or y for the argument (not p1 or p2).
noNegative(&x);  //invoking the noNegative function with address of x
noNegative(&y);  //invoking the noNegative function with address of y


// 13. Use p2 to display the values in x and y (this will require both assignment statements
//     and cout statements).  You can use x and y in assignment statements, but not in your
//     cout statement. This should produce the output
//
//     x is: 0
//     y is: 99
p2=&x;    //p2 equals address of x
cout <<"x is: "<<*p2<<" and ";  //displaying p2's pointed value
p2=&y;    //p2 equals address of y
cout <<"y is: "<<*p2<< endl;//displaying p2's pointed value


// 14. Create an int array named 'a' with two elements. Make p2 point to the first element
//     of a.
const int size = 2; //declaring and initializing constant to value 2
int a[size]; //declaring array
p2=&a[0];  //pointing p2 to the first element.

// 15. Use only p2 and x (not a) to initialize the first element of a with the value of x.
*p2=x; //initializing the first element to the value of x

// 16. Use only p2 and y (not a) to initialize the second element of a with the value of y.
//     Leave p2 pointing to the first element of a. Don't use pointer arithmetic.
//     Hint: don't forget that pointers and arrays are the same thing.
p2[1]=y; // initializing p2 equall to y

// 17. Using cout and p2 only, display the address of the first element in a.
cout <<"The address of the first element is "<<p2<< endl; //displaying p2's first element address

// 18. Using cout and p2 only, display the address of the second element in a. Leave p2
//     pointing to the first element of a.   Don't use pointer arithmetic.
cout <<"The address of the second element is "<<&p2[1]<< endl; //displaying p2's second element address

// 19. Use p1, p2, and temp to swap the values in the two elements of array 'a'.
//     (first point p1 at a[0], then point p2 at a[1], then do not use "a" again. After this
//     the swapping steps should look very similar to step 10. Don't use a swap function.)
p1 = &a[0]; //p1 equals the address of a[0]
p2 = &a[1]; //p2 equals the address of a[1]
temp = *p1; //temp equals pointed p1's value
*p1 = *p2; // p1's pointed value is equal to p2's pointed val
*p2 = temp; // p2's pointed value is equal to temp's value

// 20. Display the values of the two elements.
//     (The first element should be 99, the second 0).
cout << "The first  element in a[] is "<< a[0] << " and the second element in a[] is "<< a[1] << endl; //displaying elements


// 21. Write a function named 'swap' that accepts two pointers to integers as arguments, and
//     then swaps the contents of the two integers. Do not use any reference parameters.
//     Place the function prototype for swap() above the main() function, and place the
//     definition of swap() below main().
// 22. Invoke your swap() function with the addresses of x and y (using the address-of
//     operator in the arguments), then print their values.  (x should be 99, y should be 0).
swap(&x,&y); //calling the swap function to swap a[0] and a[1]
cout << "Now, x contains: "<<x<<" and y contains: "<<y<<endl;//displaying x and y

// 23. Invoke your swap function with the address of the two elements in array 'a', then
//     print their values.  (a[0] should be 0, a[1] should be 99).
cout <<"a[0] contains: "<<a[0]<<" and a[1] contains: "<<a[1]<<endl;
swap(&a[0],&a[1]);   //calling the swap function to swap a[0] and a[1]
cout << "Now, a[0] contains: " << a[0] <<" and a[1] contains: "<<a[1]<<endl;
} /* end of function main() */

void noNegative(int *intPtr)
{

//if the value of intPTR is below 0, the assign the value 0
  if(*intPtr < 0) *intPtr = 0;

}

void swap(int *intPtr1, int *intPtr2){
  int temp;       //declaration of temp
  temp = *intPtr1;    //Initializing temp with the value pointed to intPtr1
  *intPtr1 = *intPtr2; // pointing the value of intPtr2 to intPtr1
  *intPtr2 = temp;    //assigning  the value of temp to intPtr2
}


/*
 *
x contains: 99
x contains: 99
x is: 0 and y is: 99
The address of the first element is 0x62fdf8
The address of the second element is 0x62fdfc
The first  element in a[] is 99 and the second element in a[] is 0
Now, x contains: 99 and y contains: 0
a[0] contains: 99 and a[1] contains: 0
Now, a[0] contains: 0 and a[1] contains: 99
 *
 */


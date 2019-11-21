/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 09/21/2019
 * Prof. Dave Harden
 * File: a7_1.cpp
 * Descrip.:Implementation several functions. The functions deals with null terminated C-Style strings.
 * Such functions checks for:
 * - the last Index of a c-string
 * - reverses a c-string
 * - replace characters in a c-string
 * - checks if a c-string it is a Palindrome
 * - Converts a c-string into uppercase
 * - Counts number of alphanumeric characters is a c-string
  */
#include <iostream>
#include <cstring>
using namespace std;

// prototype functions
int lastIndexof (const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);

int main() {

	//C-strings to be used in tests
	char str1[]="Hello World";
	char str2[]="C++ is fun";
	char str3[]="Programmer: an organism that turns caffeine and pizza into software";
	char str4[]="Ab1BA";
	char str5[]="abc cba";
	char str6[]="abc ba";
	char str7[]="HaNnAh";
	char str8[]="There is no place like 127.0.0.1";
	char str9[]="D I S C O N N E C T E D !";

//Last Index Test
	cout <<"\n***LAST INDEX***"<<endl;
	cout <<"found last index of char at: "<<lastIndexof(str1,'l')<<endl;//Although there is three 'l' in str1, the function provides the index of the last one
	cout <<"found last index of char at: "<< lastIndexof(str2,'F')<<endl;//Function is case sensitive and here it returns -1 because the character 'F' does exist as opposed to 'f' which does.
	cout <<"found last index of char at: "<< lastIndexof(str3,' ')<<endl;//Function can also identify Space character. here it identifies the last space at index 58.
	cout <<"found last index of char at: "<< lastIndexof(str4,'2')<<endl;//Function returns -1 if the character doesn't exist at all .

//Reverse test
	cout <<"\n***REVERSE***"<<endl;
	cout << "Orginal: "<<str1; //displaying original str1
	reverse(str1); // reversing it
	cout <<" | Reversed: "<<str1<<endl; //displaying str1 reversed

//Replace
	cout <<"\n***REPLACE***"<<endl;
	cout << "Original: "<<str2<<" | Occurrences: "<<replace(str2,'+','-')<<" | Altered: "<<str2<<endl; //replacing '+' for '-' and displaying the number of occurrences
//Palindrome
	cout <<"\n***PALINDROME***"<<endl;
	if (isPalindrome(str4)) {cout<<str4<<" is a palindrome.\n";}else{cout<<str4<<" is not a palindrome.\n";};
	if (isPalindrome(str5)) {cout<<str5<<" is a palindrome.\n";}else{cout<<str5<<" is not a palindrome.\n";};
	if (isPalindrome(str6)) {cout<<str6<<" is a palindrome.\n";}else{cout<<str6<<" is not a palindrome.\n";};
	if (isPalindrome(str7)) {cout<<str7<<" is a palindrome.\n";}else{cout<<str7<<" is not a palindrome.\n";};



//toupper
	cout <<"\n***TOUPPER***"<<endl;
	cout <<"Original.... "<<str3<<endl;
	toupper(str3);
	cout <<"Converted... "<<str3<<endl;

//numLetters
	cout <<"\n***numLetters***"<<endl;
	cout <<"String: \""<< str7 <<"\" has a total of "<<numLetters(str7)<<" letters"<<endl;
	cout <<"String: \""<< str8 <<"\" has a total of "<<numLetters(str8)<<" letters"<<endl;
	cout <<"String: \""<< str9 <<"\" has a total of "<<numLetters(str9)<<" letters"<<endl;

}


/*function that searches for the last index in a c-string of a given char.
The function returns the position of the character or a -1 if no index is found.
*/
int lastIndexof (const char* inString, char target){
	int returnIndex = -1, index = 0; //declaring variables

	//loop until the null character is encountered
	while(inString[index] != '\0'){
		//if the current character position inString matches the target character, returnIndex gets the current index position
		if (inString[index] == target){
			returnIndex = index;
		}
		index++;
	}
	return returnIndex;
}

//function that will reverse a given c-string
void reverse(char* inString){

	//Declaring Variables
    int index = 0, strSize = strlen(inString);
    char tempChar;
    //loop through until the middle of the array  and swap array elements following the first with last, the second with the second last and successively
    while (index < strSize/2){

    	tempChar = inString[index]; //copy the current position of index to tempChar
    	inString[index] = inString[strSize - index - 1]; //copy the value of the opposite side of index position of the array.
    	inString[strSize - index - 1] = tempChar;  // copy the tempChar value to the opposite side of the index position
    	index++; //increase count
    }
}

//Function that will replace a character for another character in a c-string and return the number of occurrences.
int replace(char* inString, char target, char replacementChar){
	int index=0; //declaring an index to be used in the array
	int matchesFound = 0; //Declaring a variable to return the number of occurrences

	//looping until the end of the array
	while (inString[index]!='\0'){

		//if the current character in the c-String equals the replacement character , replace it and increase matchesFound by 1
		if (inString[index] == target){
			inString[index] = replacementChar;
            matchesFound++;
		}

		index++; //increase index to loop to the next character in the string.
	}
	return matchesFound; //returning the number of occurrences.
}

//Function that returns true c-string is a palindrome
bool isPalindrome(const char* inString){
	int index = 0, strSize = strlen( inString ); //declaring the index and strSize that represent the size of the C-String
	//Loop until the middle of the array and compare the elements: first with last, second with second last and successively
	while (index < strSize / 2 ){
		//return false if there is a mistach
		if (tolower(inString[ index ]) != tolower(inString[ strSize - index - 1 ])){
			return false;
		}
		index++;
	} return true; //if no mismatch is found
}

//This function converts the c-string parameter to uppercase.
void toupper(char* inString){

    int index=0;//declaring variables and initiating value

    //Loop into the string and into each character update it to uppercase
    while (inString[index]!='\0'){
        inString[index] = toupper(inString[index]);
        index++;
    }
}
//function returns the number of letters in the c-string
int numLetters(const char* inString){
     int index=0, letters = 0; //declaring and initiating varibles
     //loop in the c-string and go one character at a time.
     while (inString[index]!='\0'){
    	 //if the character is an alphanumeric, increase letters by 1
    	 if (isalpha(inString[index])){
             letters++;
         }
         index++; //increase index and move to the next character
    }
     return letters; //return character
}

/*
***LAST INDEX***
found last index of char at: 9
found last index of char at: -1
found last index of char at: 58
found last index of char at: -1

***REVERSE***
Orginal: Hello World | Reversed: dlroW olleH

***REPLACE***
Original: C++ is fun | Occurrences: 2 | Altered: C-- is fun

***PALINDROME***
Ab1BA is a palindrome.
abc cba is a palindrome.
abc ba is not a palindrome.
HaNnAh is a palindrome.

***TOUPPER***
Original.... Programmer: an organism that turns caffeine and pizza into software
Converted... PROGRAMMER: AN ORGANISM THAT TURNS CAFFEINE AND PIZZA INTO SOFTWARE

***numLetters***
String: "HaNnAh" has a total of 6 letters
String: "There is no place like 127.0.0.1" has a total of 18 letters
String: "D I S C O N N E C T E D !" has a total of 12 letters

 */

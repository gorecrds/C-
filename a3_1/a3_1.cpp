/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 08/30/2019
 * Prof. Dave Harden
 * File: a3_1.cpp
 * Descrip.:This is guessing number game to be  played with a user. 
 The  user will think of a number between 1 and 100 and with one to a few iterations, the program will try to guess. 
 The program will make guesses and the user will tell the program to guess higher or lower until it finds the exact numbe the  user had in mind.
 The user begins by telling the program if the number is guess is either correct, higher or lower. After a few iterations, 
 The program will get closer and closer to  the number until the user user confirms it that it is right
 */

#include <iostream>
using namespace std;

//Function that calculates and returns the midpoint between the two numbers given
int getMidpoint (int low, int high) {
    return (low+high) / 2;
}

//Function that asks the user for a response. 
void getUserResponseToGuess(int guess, char& result) {
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: ";
	cin >> result;
}

//Function to initiate the game
void playOneGame(){
	//Declaring variables
    int low = 1, high = 100, guess;
    char result;

    guess = getMidpoint(low,high); //initiatilizing guess with the first guessed number

    cout << "Think of a number between 1 and 100." << endl; //Telling theuser to guess the first number
    do{
    	getUserResponseToGuess(guess, result); // prompting the user to enter 'h', 'l', or 'c' and collecting user's response
    	
    	//Retry the next guess based on the user's response
    	if (result=='l') {
    		high=guess;      //When the number is lower, then the high number becomes the guessed number
    		guess = getMidpoint(low,guess);

    	}
    	if (result=='h') { 
    		low=guess;      //When the number is higher, then the low number becomes the guessed number
    		guess = getMidpoint(guess,high);
    	}

    } while (result !='c');


}



int main (){
	char response;

	cout << "Ready to  play (y/n)? ";  //asking the user if he wants to play
	cin >> response;                   //getting user's response
	while (response=='y'){
		playOneGame();  // calling the game if the user says 'y'
		cout << "Great! Do you want to play again (y/n)? ";
		cin >> response;
	}
}



/*
Ready to  play (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: h
My guess is 75. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: h
My guess is 87. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: l
My guess is 81. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: c
Great! Do you want to play again (y/n)? y
Think of a number between 1 and 100.
My guess is 50. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: l
My guess is 25. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: h
My guess is 37. Enter 'l' if your number is lower, 'h'if it is higher, 'c'if it is correct: c
Great! Do you want to play again (y/n)? n
*/
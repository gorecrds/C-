/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 09/06/2019
 * Prof. Dave Harden
 * File: a4_1.cpp
 * Descrip.:Program that reads five (or more) cards from the user, then analyzes the cards and prints out the category of hand that they represent.
 * The user will enter 5 cards and program will determine if it is a pair, two pair, Three of a kind, Straight, Full House, Four of a Kind.
 * The program take in consideration that the user will enter a range of numbers between 2 to 9.
  */
#include <iostream>

using namespace std;

int const HANDSIZE = 5; //How many cards will one hold in his hand. Declaring a Global Constant and initializing it to 5.
int const LOWCARD = 2;  //lowest possible card
int const HIGHCARD = 9; //highest possible card

/* void checkHand function
 * Checks how many repeat cards it  will find and adds a valueto numResult every time
 * it finds a repeating card.
 * A pickedCard is check in the hand array to see how many repeating events is found
 */
void checkHand(int pickCard, const int allNumbers[], int &numResult){

	for (int counter=pickCard+1; counter<HANDSIZE;counter++){
		if (allNumbers[pickCard]==allNumbers[counter]){
			numResult++; // adds one every time a pickCard matches one of the cards on the Hand Array
		}
	}
}

/* void checkStraightCards function
 * Checks if the following consecutive card exists in hand.
 * The function receives the first consecutive possible number that can exist (2-9) and checks to see
 * if there number is match. If there is a  match it add 1 to numResult and flags found as true to avoid
 * counting duplicates. After the for loop iteration, the tempNumber checks if the numResult remained the same.
 * When this happens, it means that there was break in the consecutive sequence (number being checks is not found in hand) and
 * it sets the numResult back to 0. *
 */
void checkStraightCards(int numConsecutive, const int allNumbers[], int &numResult){
	int tempNumber=numResult; bool found=false; //Declaration of variables and assigning tempNumber to have the same value as numResult at the beginning of the function iteration
	for (int counter=0; counter<HANDSIZE; counter++){

		if (numConsecutive==allNumbers[counter] and found==false){// If the Consecutive number is found in hand
			numResult++; found=true;                            // , add one to numResult and set found equal to true
		}
	}
	//if numResult is the same as the tempNumber and the amount of Consecutive card found is less than 5,
	//it means that no consecutive number was found in hand deck for this iteration and numResult is put back to 0 since there is consecutive sequence break.
	if (numResult==tempNumber and numResult<5) numResult=0;
}

//Function that checks if there is a pair
bool containsPair(const int hand[]){

	bool response=false; int numResult = 0; //variable declaration

	for (int counter=0; counter<HANDSIZE; counter++){
		checkHand(counter, hand, numResult); //Calling function to check how many repeating cards in hand
	}

	if (numResult==1)   // if one is found than response is true
		response=true;

	return response; //Return Response
}

//Function that checks if there is two pair
bool  containsTwoPair(const int hand[]){
	bool response=false; int numResult = 0; //variable declaration

	for (int counter=0; counter<HANDSIZE; counter++){
		checkHand(counter, hand, numResult); //Calling function to check how many repeating cards in hand
	}

	if (numResult==2) response=true; // if two pairs  is found than response is true

	return response; //Return Response
}

//Function that checks if there is three matching cards
bool  containsThreeOfaKind(const int hand[]) {

	bool response=false; int numResult = 0; //variable declaration

	for (int counter=0; counter<HANDSIZE; counter++){
		checkHand(counter, hand, numResult); //Calling function to check how many repeating cards in hand
	}

	if (numResult==3) response=true; // if three matches is found than response is true

	return response; //Return Response
}

//Function that checks if there is 5 consecutive numbers in hand
bool  containsStraight(const int hand[]) {
	bool response=false; int numResult = 0;	int LOWCARD=2; int HIGHCARD=9; //variable declaration and declaring that the deck of cards only carry numbers low[2-9]max. Range of card deck is 2-9
	for (int counter=0;counter<HIGHCARD; counter++){ //looping for 2-9
		checkStraightCards(LOWCARD+counter, hand, numResult); //Function that checks if the numbers [2-9] exists in the hand (array)
	}
	if (numResult>=5) response=true; // if a straight  (5 consecutive cards) found than response is true

	return response; //Return Response
}

//Function that checks if there is 1 pair and 3 matching cards
bool  containsFullHouse(const int hand[]){

	bool response=false; int numResult = 0; //variable declaration

	for (int counter=0; counter<HANDSIZE; counter++){
		checkHand(counter, hand, numResult); //Calling function to check how many repeating cards in hand
	}

	if (numResult==4) response=true;

	return response; //Return Response
}

//Function that checks if there is four mathcing cards
bool  containsFourOfaKind(const int hand[]){
	bool response=false; int numResult = 0; //variable declaration

	for (int counter=0; counter<HANDSIZE;counter++){
		checkHand(counter, hand, numResult); //Calling function to check how many repeating cards in hand
	}

	if (numResult==6) response=true; // if four matches is found than response is true

	return response; //Return Response
}

int main() {


	int hand[HANDSIZE]; // Declaring array and specifying the size to the global constant
	cout << "Enter five numeric cards, no face cards. Use 2 - 9.\n"; //Displaying message to have user enter 5 number froma range of 2-9

	//looping through 5 inputs
	for (int counter=0; counter<HANDSIZE; counter++){
		cout << "Card "<<counter+1<<": "; //Displaying card number
		cin >> hand[counter]; //recording user's input in array
		cin.ignore();
	}


/*Condition from strongest to weakest hand
 *calls function and if there is matching hand, prints what it is.
 */

	if (containsStraight(hand)){
		cout << "Straight!";
	}
	else if (containsFourOfaKind(hand)){
		cout << "Four of a Kind!";
	}
	else if (containsFullHouse(hand)){
		cout << "Full House!";
	}
	else if (containsThreeOfaKind(hand)){
		cout << "Three of a kind!";
	}
	else if (containsTwoPair(hand)){
		cout << "Two Pair!";
	}
	else if (containsPair(hand)){
		cout << "contains a pair";
	}

}

/*
 * Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 5
Card 2: 5
Card 3: 2
Card 4: 3
Card 5: 4
contains a pair

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 4
Card 2: 4
Card 3: 2
Card 4: 2
Card 5: 6
Two Pair!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 4
Card 3: 3
Card 4: 4
Card 5: 4
Three of a kind!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 2
Card 2: 2
Card 3: 3
Card 4: 2
Card 5: 2
Four of a Kind!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 4
Card 2: 5
Card 3: 4
Card 4: 5
Card 5: 5
Full House!

Enter five numeric cards, no face cards. Use 2 - 9.
Card 1: 4
Card 2: 3
Card 3: 2
Card 4: 5
Card 5: 6
Straight!



 */





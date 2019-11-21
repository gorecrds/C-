/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 08/25/2019
 * Prof. Dave Harden
 * File: a2_1.cpp
 * Descrip.:Card game where a player draw as many card as they want
 * with the goal of as getting as close as possible to a total of 21.
 * Player is busted if the total sum of the cards drawn exceeds 21.
 *
 * The program will drawn 2 set of cards (numbers) and provide a  total sum of them.
 * The player (user)may choose to draw another card to get as close to 21.
 * In case the  player decides to draw the card the card is summed to the total.
 * if the number exceeds 21, the played is busted and the program asks if the player
 * wishes to play again.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));   //seeding the random-number generator
	int num1,num2,total;                           // Declaring integer variables to be used in the program
	string playAgain="y", anotherCard="y";         // Declaring and initializing String Variable

	while (playAgain=="y"){           // Execute the code block while playAgain="y". Sop if the user inputs a "n"
		num1= rand() % 10+1;          //initializing variable num1 with random number in the range between 1 to 10
		num2= rand() % 10+1;          //initializing variable num2 with random number in the range between 1 to 10
		total=num1+num2;              //summing num1 and num2
        cout << "\nFirst cards: " << num1 << ", " << num2 << "\nTotal: " << total << endl;   //display the user the two cards and the sum of the total

        do {
        	//asking the user if he wishes to flip another card (number)
            cout << "Do you want another card? (y/n): ";
            cin >> anotherCard;

            if (anotherCard=="y"){
            	num2= rand() % 10+1; //if the user answer "y" display a new number and a sum
            	total+=num2;
            	cout << "Card: " << num2 << "\nTotal: " << total << endl;
        	}

            if (total>21){
        		cout << "Bust.\n"; //if the number is greater than 21, displplay Bust
        	}

        } while (anotherCard=="y" and total<=21); //end do while

        cout << "Would you like to play again? (y/n): "; //Ask the user if he wants to play again
        cin >> playAgain;             // collecting user input if he wants to play again
	}; //end while Loop
};


/*
 First cards: 1, 4
 Total: 5
 Do you want another card? (y/n): y
 Card: 10
 Total: 15
 Do you want another card? (y/n): y
 Card: 4
 Total: 19
 Do you want another card? (y/n): n
 Would you like to play again? (y/n): y

 First cards: 1, 6
 Total: 7
 Do you want another card? (y/n): y
 Card: 7
 Total: 14
 Do you want another card? (y/n): y
 Card: 7
 Total: 21
 Do you want another card? (y/n): y
 Card: 4
 Total: 25
 Bust.
 Would you like to play again? (y/n): n


 */



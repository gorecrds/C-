/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 10/04/2019
 * Prof. Dave Harden
 * File: a8_1.cpp
 * Descrip.:Program that reads five (or more) names and score in a struct and sorts it in a
 * descending order. The takes program will start by asking the input of 5 names and scores which will be stored
 *  in a struct array and displays in a descending order from the highest to the lowest score
  */
#include <iostream>
using namespace std;

//structure declaration
struct highscore {
	char name[24];  //student's name up to 23 characters
	int score;      //student's score
};


void readData (highscore scores [], int size); // declaration of function readData
void sortData (highscore scores [], int size); // declaration of function sortData
void displayData (const highscore scores [], int size); // declaration of function displayData

int main() {

	highscore *scores=nullptr; //initializing a highscore pointer to null value

	int size;  //declaring size
	cout << "How many scores will you enter?: "; //display message
	cin >> size;  //storing the users input on variable size
	scores = new highscore[size]; //allocating memory to a highscore dynamic array to hold inputs
	//Calling Functions
	readData (scores,size); // calling readData function to take inputs
	cout << scores <<endl;
	sortData (scores, size); // calling sortData function to sort the scores in a descending order
	displayData(scores, size); // calling displayData function Displaying the name and scores in a descending order.
	delete [] scores; // deallocating array scores
}






void readData (highscore scores [], int size) {

	for (int index=0; index<size;index++){  //For loop that iterates over a number of times associated to the size of the array
		cout << "Enter the name for score #"<<index+1<<": "; //Displaying message
		cin >> scores[index].name; //recording user's input in array
		cout << "Enter the score for score #"<<index+1<<": "; //Displaying message
		cin >> scores[index].score; //recording user's input in array
	}
}






void sortData (highscore scores [], int size){
	for (int  startingIndex=0;startingIndex<size;startingIndex++){ //Creating a count under the variable startingIndex starting at element 0. iterate to the next element once the check or swap occurs
		int targetIndex = startingIndex;   // declaring and initiating the targetIndex equal to current StartingIndex of the iteration
		for (int count=startingIndex+1; count<size; count++){ //For Loop checking the next index after the current position of startingIndex. It will locate the element with the  highest value.
			if (scores[count].score>scores[targetIndex].score){ // If during the iteration of the array, it locates a larger score number than targetIndex then
				targetIndex=count;                  // capture the index position being ran by count and assign it to targetIndex.
			}
		}
		swap(scores[targetIndex],scores[startingIndex]);//swapping the largest element found (targetIndex) for the initial element of the iteration (startigIndex) in the "scores" array //swapping array's position
	}
}






void displayData (const highscore scores [], int size){
	// Iteration to display the values for elements under "names" and "scores" per line.
	cout <<"\nTop Scorers:\n";
	for (int index=0;index<size;index++) { //creating counter to loop over the arrays
		cout << scores[index].name << ": "<< scores[index].score <<endl; //displaying each element related its indices
	}
}


/*
Enter the name for score #1: Suzy
Enter the score for score #1: 600
Enter the name for score #2: Igor
Enter the score for score #2: 9900
Enter the name for score #3: Bob
Enter the score for score #3: 1012
Enter the name for score #4: Armando
Enter the score for score #4: 8000
Enter the name for score #5: Tim
Enter the score for score #5: 514

Top Scorers:
Igor: 9900
Armando: 8000
Bob: 1012
Suzy: 600
Tim: 514
 */



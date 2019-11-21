/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 09/21/2019
 * Prof. Dave Harden
 * File: a6_2.cpp
 * Descrip.:Program that user's response for how many scores will be entered sorts the scores in a
 * descending orderwth it respective names. User will enter how many scores it will be entering,
 * and displays in a descending order from the highest to the lowest score
  */
#include <iostream>
#include <utility>
using namespace std;

void readData(string[],int[],int); // declaration of function readData
void sortData (string[], int[], int); // declaration of function sortData
void displayData (const string[], const int[], int); // declaration of function displayData

int main() {

	int size;  //declaring size
	cout << "How many scores will you enter?: "; //display message
	cin >> size;  //storing the users input on variable size

	string* names = new string[size]; //Declaring a dynamic Array names
	int* scores = new int[size];   //Declaring a dynamic Array scores
	readData (names,scores,size); // calling readData function to take inputs
	sortData (names, scores, size); // calling sortData function to sort the scores in a descending order
	displayData(names, scores, size); // calling displayData function Displaying the name and scores in a descending order.
	delete [] names;  //  deallocating array names
	delete [] scores; //  deallocating array scores

}

void readData (string names [], int scores[], int size) {

	for (int index=0; index<size;index++){  //For loop that iterates over a number of times associated to the size of the array

		cout << "Enter the name for score #"<<index+1<<": "; //Displaying message
		cin >> names[index]; //recording user's input in array
		cout << "Enter the score for score #"<<index+1<<": "; //Displaying message
		cin >> scores[index]; //recording user's input in array

	}
}



void sortData (string names [], int scores[], int size){
	for (int  startingIndex=0;startingIndex<size;startingIndex++){ //Creating a count under the variable startingIndex starting at element 0. iterate to the next element once the check or swap occurs
		int targetIndex = startingIndex;   // declaring and initiating the targetIndex equal to current StartingIndex of the iteration
		for (int count=startingIndex+1; count<size; count++){ //For Loop checking the next index after the current position of startingIndex. It will locate the element with the  highest value.
			if (scores[count]>scores[targetIndex]){ // If during the iteration of the array, it locates a larger number than targetIndex then
				targetIndex=count;                  // capture the index position being ran by count and assign it to targetIndex. When this happens,targetIndex no longer holds the same value as startingIndex, until this whole for iteration is over.
			}
		}
		swap(names[targetIndex],names[startingIndex]); //swapping the largest element found (targetIndex) for the initial element oft he iteration (startigIndex) in the "names" array
		swap(scores[targetIndex],scores[startingIndex]);//swapping the largest element found (targetIndex) for the initial element oft he iteration (startigIndex) in the "scores" array
	}
}

void displayData (const string names [], const int scores[], int size){
	// Iteration to display the values for elements under "names" and "scores" per line.
	cout <<"\nTop Scorers:\n";
	for (int index=0;index<size;index++) { //creating counter to loop over the arrays
		cout << names[index] << ": "<< scores[index] <<endl; //displaying each element related its indices
	}
}


/*
How many scores will you enter?: 4
Enter the name for score #1: Suzy
Enter the score for score #1: 9900
Enter the name for score #2: Kim
Enter the score for score #2: 1000000
Enter the name for score #3: Armando
Enter the score for score #3: 822
Enter the name for score #4: Tim
Enter the score for score #4: 514

Top Scorers:
Kim: 1000000
Suzy: 9900
Armando: 822
Tim: 514
 */



/*
 * Name: Igor Cardoso
 * Class CIS 278 (CS1) Programming Methods: C++
 * Date: 09/14/2019
 * Prof. Dave Harden
 * File: a5_1.cpp
 * Descrip.:Program that reads five (or more) takes 5 names and score inputs and sorts it in a
 * descending order. The takes 5 names and a score for each name and displays in a descending order from
 * the highest to the lowest score
  */
#include <iostream>
using namespace std;

int const SIZE=5; // Declaring a constant size to be use in the below arrays


void readData(string[],int[],int); // declaration of function readData
void sortData (string[], int[], int); // declaration of function sortData
void displayData (const string[], const int[], int); // declaration of function displayData

int main() {

	string names [SIZE]; //Declaring Array names
	int scores [SIZE];   //Declaring Array scores
	readData (names,scores,SIZE); // calling readData function to take inputs
	sortData (names, scores, SIZE); // calling sortData function to sort the scores in a descending order
	displayData(names, scores, SIZE); // calling displayData function Displaying the name and scores in a descending order.
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



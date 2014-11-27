/****************************************************************************
*Author:                           		James Spolsdoff
*Dated Created:                     11/4/14
*Last Modified Date:               11/4/14
*Filename:                         	stringMix.cpp
*
*Overview:
*This program will ask the user for a string and pass it and another string
*to a function that will randomize the first string and store it in the second.
*The program will ask the user if they want another random string generated.
*
*Input:
*The program will ask the user for a string input as well as if they would
*like to generate another random arrangement of the string.
*
*Output:
*The program will output a random arrangement of the input string.
*
*
****************************************************************************/

#include <iostream>
#include <string>		// include string library
#include <cstdlib>		// include cstdlib for rand function
#include <ctime>		// include ctime for seed generation
#include <cstring>
using namespace std;

void StringMix(char* string1, char* string2);			// function prototype

int main()
{

	// declare needed variables

	 const int SIZE = 30;			// variable for string length
			      char again;			// variable used for do/while loop
	   char string1[SIZE],			// variable for original C-String function argument
			  string2[SIZE];			// variable for C-String for random generation
	
	// tell the user what the program does
	cout << "This program will take a string you input and randomly mix up the letters.\n" << endl;
	
	// ask them for a string input
	cout << "Please enter a string that is less than 30 characters that you would like to mix up: ";
	cin >> string1;
	
	cout << "\n\n" << endl; 
		
	do
	{
	// put function in do/while loop so that user can continue to generate random string
		
		// pass both C-Strings to the function
		StringMix(string1, string2);
		
		// check if the users want to play again
		cout << "Do you want to play again? (Y/N)";
		
		cin >> again;
	
	} while (toupper(again) == 'Y');		// make sure input matches the case of the validator

	return 0;
}  

/**********************************************************************************************
*												StringMix
*This functions gets passed two C-Strings and will return a random arrangement
*of the first string.
**********************************************************************************************/
void StringMix(char* string1, char* string2)
{
	
	      int high_number = 0,		// high random number range
seed,
		        low_number = 0,		// low random number range
	                       size = 0, 		// size of C-String
						r_num = 0,		// variable for random number
						l_num = 0,		// variable for last random number generated
			                         i ;		// variable for the loop
	
	// use time function to get seed for srand function
	seed = time(0);
	srand(seed);
	
	size = strlen(string1);
	
	high_number = size - 1;
	
	// test area
	cout << size << endl;
	
	for (i = 0; i < size; i++)
	{
		do
		{
		// random number generator
		r_num = (rand() % high_number + low_number);
		} while (r_num == l_num);
		
		l_num = r_num;
		
		string2[i] = string1[r_num]; 
			
	}
	
	// display original input string
	cout << "Your original string is " << string1 << endl;
	// display mixed up string
	cout << "Your mixed up string is " << string2 << endl;
}

/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/16/14
*Last Modified Date:               10/16/14
*Filename:                         randNumb.cpp
*
*Overview:
*This program is a random number generator that outputs a random number
*within a given range. The program will ask the user for a high and low
*range and generate and print and random number within that range.
*
*
*Input:
*The user will be asked to input the high and low range of the random number.
*
*Output:
*The program will print out the random number.
*
*****************************************************************************/

#include <iostream>
#include <cstdlib> 		// header for rand function
#include <ctime>   		// header for time function
#include <string>		// header for strings
using namespace std;

int main()
{

	// declare variables for program
		int high_number,		// high random number range
			 low_number,		// low random number range
		  random_number,		// random number
				   seed;		// seed variable

	// tell the user what the program does
	cout << "This program will generate a random number between an input high and low range." << endl;
	
	// use time function to get seed for srand function
	seed = time(0);
	srand(seed);
	
	// ask the user for the first int values
	cout << "Please enter the low range integer for the random number: ";
	
	// store first int value
	cin >> low_number;
	
	// validate first input int value is not a string
	while (!(cin >> low_number) || cin.get() != '\n')
	{
		cout << "This is not a valid number. Please enter a valid number: ";
		cin.clear();
		cin.ignore(1000,'\n');
		cin >> low_number;
	}
	
	// ask the user for the second int value
	cout << "Please enter the high range integer for the random number: ";
	
	// store second int value
	cin >> high_number;
	
	// make sure that the high number is greater than the low number
	if (high_number <= low_number)
	{
		cout << "Your input is invalid. Please enter another number: ";
		
		cin >> high_number;
	}
	
	// validate second input int value
	while (!cin)
	{
		cout << "This is not an integer. Please enter an integer: ";
		cin.clear();
		cin.ignore(1000,'\n');
		cin >> high_number;
	}
	
	// generate random number within range
	random_number = (rand() % ((high_number - low_number) + 1) + low_number);		// store random number in variable
		
	// print random number
	cout << "The random number between " << low_number << " and " << high_number << " is " << random_number << endl;

	return 0;
}  

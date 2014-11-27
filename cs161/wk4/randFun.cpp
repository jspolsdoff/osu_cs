/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:          		   10/25/14          
*Last Modified Date:               10/26/14
*Filename:                         randFun.cpp
*
*Overview:
*This program will ask the user for a low value and a high value and pass them
*to a function that will generate a random number between those values.
*
*Input:
*The user will be asked for two int variables for the low and high range of the
*random number.
*
*Output:
*The program will generate a random number between the low and high range.
*
****************************************************************************/

#include <iostream>
#include <cstdlib>		// include cstdlib for rand function
#include <ctime>		// include ctime for seed generation
using namespace std;

// display random number function prototype
void RandomNumber(int, int);

int main()
{
	// declare variables
	int low_number,		// low number range for random number
	   high_number;		// high number range for random number
	   
	// tell user what the program does
	cout << "This program will use a function to generate a number in a specified range" << endl;
	
	// ask for a low range
	cout << "Please enter an integer for the low limit: ";
	
	cin >> low_number;
	
	// ask for high range
	cout << "Please enter an integer for the high limit: ";
	
	cin >> high_number;
	
	// validate high range input
	if (high_number <= low_number)
	{
		cout << "The high range must be greater than the low range. Please enter another number: ";
		cin >> high_number;
	}
	
	// pass value to random number function
	RandomNumber(low_number, high_number);

	return 0;
}  

/************************************************************************
*							RandomNumber
*This function will generate a random number in between the range specified
*by the user
*************************************************************************/
void RandomNumber(int low_number, int high_number)
{
	// declare variables
	int random_number,		// random number
				 seed;		// seed variable

	// generate seed using time for function
	seed = time(0);
	srand(seed);
	
	// generate random number within range
	random_number = (rand() % ((high_number - low_number) + 1) + low_number);		// store random number in variable
	
	// print random numbers on screen
	cout << "The random number between " << low_number << " and " << high_number << " is " << random_number << endl;
}
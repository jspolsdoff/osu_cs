/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:          		   10/29/14          
*Last Modified Date:               10/29/14
*Filename:                         randFun.cpp
*
*Overview:
*This program will ask the user for a low value and a high value and pass a
*reference variable to a function that will generate a random number between 
*those values.
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
void RandInt(const int &min, const int &max, int &val);
	
int main()
{	
	// declare variables
	int min,		// low number range for random number
	    max,		// high number range for random number
		val;        // the random number between the random numbers.
	   
	// tell user what the program does
	cout << "This program will use a function to generate a number in a specified range" << endl;
	
	// ask for a low range
	cout << "Please enter an integer for the low limit: ";
	
	cin >> min;
	
	// ask for high range
	cout << "Please enter an integer for the high limit: ";
	
	cin >> max;
	
	// validate high range input
	if (max <= min)
	{
		cout << "The high range must be greater than the low range. Please enter another number: ";
		cin >> max;
	}
	
	// pass value to random number function
	RandInt(min, max, val);
	
	cout << "The value stored in the variable val in the main function is " << val << endl;

	return 0;
}  

/************************************************************************
*							RandomNumber
*This function will generate a random number in between the range specified
*by the user
*************************************************************************/
void RandInt(const int &min, const int &max, int &val)
{
	// declare variables
	           
			 int seed;		// seed variable

	// generate seed using time for function
	seed = time(0);
	srand(seed);
	
	// generate random number within range
	val = (rand() % ((max - min) + 1) + min);		// store random number in variable
	
	// print random numbers on screen
	cout << "The random number between " << min << " and " << max << " is " << val << endl;
}
/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:         		   10/15/14           
*Last Modified Date:               10/15/14
*Filename:                         randNum.cpp
*
*Overview:
*This program will generate ten random numbers.
*
*
*Input:
*The only user input will be the program asking the user to press 'enter'
*to start the loop.
*
*Output:
*The program will generate ten random numbers.
*
*
****************************************************************************/

#include <iostream>
#include <cstdlib> 		// header for rand function
#include <ctime>   		// header for time function
using namespace std;

int main()
{
	// define variables
		unsigned seed;		// seed variable
			   char i;		// variable for loop
	
	// use time function to get seed for srand function
	seed = time(0);
	srand(seed);
	
	// tell user about the program
	cout << "This program will display ten random numbers. Please press 'Enter' to start.";
	
	// ask the user to press enter to begin generating random numbers
	cin.get();
	
	// use a for loop to generate random numbers
	for (i = 0; i < 10; i++)
	{
		// print random number using rand()
		cout << rand() << endl;
	}
	
	return 0;
}  

/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/30/14
*Last Modified Date:               10/30/14
*Filename:                         hailstone.cpp
*
*Overview:
*This program will take a user's int input and run a hailstone function and
*tell the user how many steps it would take to reach one.
*
*Input:
*The user will input a int that is great than 0.
*
*Output:
*The Hailstone function will output how many steps it take to get to a value
*of 1.
*
****************************************************************************/

#include <iostream>
using namespace std;

// declare function prototype
int Hailstone(int start);

int main()
{

	int start;		// declare int variable for sequence start point
	
	// tell user what program does
	cout << "This program will tell you the number of steps needed to get to one in a hailstone sequence based on the" << endl;
	cout << "integer variable you input.\n" << endl;
	
	// ask user for int input and store in variable
	cout << "Please enter an integer greater than zero: ";
	cin >> start;
	
	// validate that int input is > 1
	if (start < 0)
	{
		cout << "Please enter an integer greater than zero: ";
		cin >> start;
	}
	
	// pass int to Hailstone function and display result
	cout << "Your input of " << start << " would require " << Hailstone(start) << " steps to get to one in a hailstone sequence." << endl;
	
	return 0;
}  

/************************************************************************
*							Hailstone
*This functions gets passed an integer and returns the number of steps 
*needed to reach 1 in a hailstone sequence.
*************************************************************************/
int Hailstone(int start)
{
	// if starting int 1 return 0
	if (start == 1)
	{
		return 0;
	}
	
	// if int is even divide by two for next number
	else if (start % 2 == 0)
	{
		return 1 + Hailstone(start / 2);
	}
	
	// else multiply by 3 and add 1
	else
	{
		return 1 + Hailstone(start * 3 + 1);
	}
}

/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/30/14
*Last Modified Date:               10/30/14
*Filename:                         recFun.cpp
*
*Overview:
*This program will ask the user to input the nth Fibonacci number they want
*displayed then runs a function and displays result in the main function.
*
*Input:
*The user will input the nth Fibonacci number in an integer variable
*
*Output:
*The program will out the Fibonacci number that corresponds to the variable.
*
****************************************************************************/

#include <iostream>
using namespace std;

// function prototype
int RecFun(int n);

int main()
{

	int n;		// declare int variable for Fibonacci input
	
	// tell the user what the program does
	cout << "This program will ask you for an integer input and return the corresponding Fibonacci number." << endl;
	
	cout << "As a note this program begins its Fibonacci number sequence with 1 and not 0." << endl;
	
	// ask user for input to calculate nth Fibonacci number
	cout << "Please input an integer value: ";
	cin >> n;
	
	// pass input to Fibonacci function
	cout << "The Fibonacci number is " << RecFun(n) << endl;
	
	return 0;
}  

/************************************************************************
*							RecFun
*This functions gets passed an integer and returns the corresponding
*Fibonacci number
*************************************************************************/
int RecFun(int n)
{
	// use if/else to go through base cases
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return RecFun(n - 1) + RecFun(n - 2);
	}
}
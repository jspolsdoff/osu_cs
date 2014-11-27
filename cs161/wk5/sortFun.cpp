/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/29/14
*Last Modified Date:               10/29/14
*Filename:                         sortFun.cpp
*
*Overview:
*This program will take three user input ints and pass the reference value
*to a function that will sort them in order of smallest to largest.
*
*Input:
*The user will input three int values.
*
*Output:
*The program will display the three values smallest to largest.
*
****************************************************************************/

#include <iostream>
#include <algorithm>	//include algorithm 
using namespace std;

void SortFun(int &a, int &b, int &c); // variable sort function prototype

int main()
{

	int a,		// declare first int variable
	    b,		// declare second int variable
		c;		// declare third int variable
	
	// tell user what program does
	cout << "This program will ask you for three int variable and call a function to sort those from smallest to largest." << endl;
	
	// ask user for inputs and store in variables
	cout << "What is the first integer: ";
	cin >> a;
	
	cout << "What is the second integer: ";
	cin >> b;
	
	cout << "What is the third integer: ";
	cin >> c;
	
	// call SortFun function with three args
	SortFun(a, b, c);
	
	// display sorted variables in main
	cout << "Your integer inputs going from smallest to largest are " << a << " " << b << " " << c << endl;

	return 0;
}  

/************************************************************************
*							SortFun
*This functions gets passed three reference int variables and sorts them
*from smallest to largest
*************************************************************************/
void SortFun(int &a, int &b, int &c)
{
	
	// use if statement and swap function to put variables values in order
	if (a > b)
	{
		swap(a ,b);
	}
	if (a > c)
	{
		swap(a, c);
	}
	if (b > c)
	{
		swap(b, c);
	}

}
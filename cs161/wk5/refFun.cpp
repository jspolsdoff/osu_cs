/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:  				   10/29/14                  
*Last Modified Date:               10/29/14
*Filename:                         refFun.cpp
*
*Overview:
*This program will compare two strings using a function. It lets the user know if they 
*have the same contents.
*
*Input:
*The user will input two strings. The input will be passed by reference.
*
*Output:
*THe program will run the function and return if the strings are equal.
*
****************************************************************************/

#include <iostream>
#include <string>		// include string library
using namespace std;

// display string comparison function prototype
void StringCompare(string &first_string, string &second_string);

int main()
{
	// declare variables
	string num1,	// variable for first user string
		   num2;	// variable for second user string
	
	// tell user what program does
	cout << "This program will take two strings you input and tell you if they are equal." << endl;
	
	// ask user for first string
	cout << "Please enter the first string: ";
	
	// store using getline
	getline(cin, num1);
	
	// ask user for second string
	cout << "Please enter the second string: ";
	
	// store using getline
	getline(cin, num2);
	
	// pass both strings as args into stringCompare function
	StringCompare(num1, num2);

	return 0;
}  

// StringCompare will tell user if inputs are equal
/************************************************************************
*							StringCompare
*This functions gets passed two strings and checks to see if they are equal
*************************************************************************/
void StringCompare(string &first_string, string &second_string)
{

	              int i;		// variable for loop to check string quality

	// check to see if strings are not of equal length
	if (first_string != second_string)
	{
		// tell the user that the strings are not equal
		cout << "The two strings are not equal." << endl;
	}
		
	// else the strings are the same length
	else
	{
		// use a loop to check if each character in strings match
		for (i = 0; i < first_string.length(); i++)
		{
			// use 'if' to check character inequality and break
			if (first_string.at(i) != second_string.at(i))
			{
				break;
			}
		}
		
		// if 'i' doesn't equal string length they are not equal
		if (i != first_string.length())
		{
			
			cout << "The two strings are not equal." << endl;
		}
		
		else
		{
			// tell the user that the strings are equal
			cout << "The strings are equal." << endl;
		}
	}

}
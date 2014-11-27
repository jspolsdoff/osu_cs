/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:           		   10/15/14         
*Last Modified Date:               10/15/14
*Filename:                         loop.cpp
*
*Overview:
*This program will compare two strings and lets the user know if they have
*the same contents.
*
*Input:
*The user will we asked to input two strings.
*
*
*Output:
*The program will tell the user if the two strings have the same contents.
*
****************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{

	// declare variables
		string first_string,		// first string variable
			  second_string;		// second string variable
					  int i;		// variable for loop
	
	// tell the user what the program does
	cout << "This program takes two strings that you input and compares them." << endl;
	
	// get users first string using getline
	cout << "Please enter your first string: ";
	
	getline(cin, first_string);
	
	// get users second string using getline
	cout << "Please enter your second string: ";
	
	getline(cin, second_string);
	
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
		
	return 0;
}  

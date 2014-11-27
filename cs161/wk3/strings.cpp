/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    
*Last Modified Date:               
*Filename:                         
*
*Overview:
*This program will ask the user for a string variable. It will take the
*string and print it one letter at a time using a loop. The program will 
*then take the string and use a loop to print it in reverse. Finally a loop
*will be used to count the number of letters.
*
*Input:
*The user will be asked to input a string
*
*
*Output:
*There will be three outputs. An echo of the string printed one character
*at a time. The same but backward. Finally a count of how many letters
*are in the string input.
*
*
****************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{

	// declare string variables
	string user_input;		// user string input
				int i,		// variable used for loop
		 letter_count;		// number of letters is 
	
	// tell user what the program will do
	cout << "Please enter a string: " << endl;
	
	// get the user string input
	getline(cin, user_input);
	
	// loop to print user input one character at a time
	for (i = 0; i < user_input.length(); i++)
	{
		cout << user_input.at(i) << endl;
	}

	// loop to print user input one character at a time in reverse
	for (i = (user_input.length() - 1); i > -1; i--)
	{
		cout << user_input.at(i) << endl;
	}

	letter_count = 0;
	
	// loop to count how many letters are in user input
	for (i = 0; i < user_input.length(); i++)
	{
		if (user_input.at(i) != ' ')
		{
			letter_count++;
		}
	}
	
	cout << "Your strings contains " << letter_count << " letters." << endl;
	
	return 0;
}  

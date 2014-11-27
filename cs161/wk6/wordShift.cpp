/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                11/5/14    
*Last Modified Date:          11/9/14     
*Filename:                        wordShift.cpp
*
*Overview:
*This program will take an input of a C-style string from the user and
*allow them to manipulate it is three ways: reverse, left, right. The 
*program will loop until the user quits.
*
*Input:
*The user will input a C-Style string along with the commands to 
*manipulate it.
*
*Output:
*The program will output the results of the commands to the string.
*
****************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

// function prototypes
void ArrayRev(char user_input[], int length);
void ArrayLeft(char user_input[], int length, int move);
void ArrayRight(char user_input[], int length, int move);

int main()
{
	// declare the needed variables
		    const int SIZE = 30;		// variable constant for size of cstring
		  char user_input[SIZE];		// variable for array to be manipulated
           	  char menu_input[SIZE];		// variable for array for menu commands
	         char input_shift[SIZE];		// variable for the number of spaces user wants to shift string
			 int input_size;		// size of user input array
			  int menu_size;		// the size of the user menu command
        		       int move;		// number of moves to pass to function
	
	// tell user what the program does
	cout << "This program will ask you for a C-style string and allow you to use three different commands to manipulate the string.\n" << endl;
	
	// ask your for string input
	cout << "Please enter a string that is less than 30 characters: ";
	cin >> user_input;
	
	// find the length of the user input
	input_size = strlen(user_input);
	
	// size test
	cout << "This is the size of the user input: " << input_size << endl;
	
	cout << "\n\n" << endl;
	
	// display menu options
	cout << "PLEASE SELECT FROM THE FOUR COMMANDS BELOW\n" << endl;
	cout << "REV - Your string will be reversed." << endl;
	cout << "Lx - Your string will shift all characters x spaces to the left. Where x is an integer." << endl;
	cout << "Rx - Your string will shift all characters x spaces to the right. Where x is an integer." << endl;
	cout << "quit - This command will exit the program.\n" << endl;
	
	// place program in do/while array @ [0] != 'q'
	do
	{
		// ask user for command and store in array
		cout << "Please enter a command: ";
		cin >> menu_input;
		menu_size = strlen(menu_input);
		
		// if array @ [2] contains 'v' 
		if ((menu_input[2] == 'v') || (menu_input[2] == 'V'))
		{
			// call ArrayRev, use pointer and references (* and &)
			ArrayRev(user_input, input_size);
			cout << "Your string is: " << user_input << endl;
		}
		// else if array @ [0] contains 'l' 
		else if ((menu_input[0] == 'l') || (menu_input[0] == 'L'))
		{
			// calculate how many shifts need to be made and store in array
			for (int i = 1; i < menu_size; i++)
			{
				input_shift[i - 1] = menu_input[i];
			}
			// convert array to integer to pass to function
			move = atoi(input_shift);
			
			// call ArrayLeft
			ArrayLeft(user_input, input_size, move);
			cout << "Your string is: " << user_input << endl;
		}
		// else if array @ [0] contains 'r' 
		else if ((menu_input[0] == 'r') ||  (menu_input[0] == 'R'))
		{
			// calculate how many shifts need to be made and store in array
			for (int i = 1; i < menu_size; i++)
			{
				input_shift[i - 1] = menu_input[i];
			}
			// convert array to integer to pass to function
			move = atoi(input_shift);
			
			// call ArrayRight
			ArrayRight(user_input, input_size, move);
			cout << "Your string is: " << user_input << endl;
		}
		// else if array @ [0] contains 'q' 
		else if ((menu_input[0] == 'q') || (menu_input[0] == 'Q'))
		{
			// 	thank user and program will exit
			cout << "Thank you for using the program." << endl;
		}
		// else the user input is invalid
		else
		{
			cout << "Your input command is invalid. Please enter a valid command." << endl;
		}
		
	} while ((menu_input[0] != 'q') && (menu_input[0] != 'Q'));
		
	return 0;
}  
/******************************************************************************************
*				ArrayRev
*This function will get passed a C-Style string and reverse it.
*******************************************************************************************/
void ArrayRev(char user_input[], int length)
{
	     const int SIZE = (length - 1);		// variable constant for size of cstring
	             char temp_input[SIZE];		// variable for array to be manipulated
	
	for (int i = 0; i < length; i++)
	{
		temp_input[i] = user_input[(length - 1) - i];
	}
	for (int i = 0; i < length; i++)
	{
		user_input[i] = temp_input[i];
	}

	*user_input = *temp_input;	
	
}
/******************************************************************************************
*				ArrayLeft
*This function will get passed a C-Style string and shift all elements to the left
*by 'x' elements.
*******************************************************************************************/
void ArrayLeft(char user_input[], int length, int move)
{
	     const int SIZE = (length - 1);		// variable constant for size of cstring
	             char temp_input[SIZE];		// variable for array to be manipulated
	
	for (int i = 0; i < length; i++)
	{
		//  use a for loop to fill temporary array with the shifted characters 
		temp_input[((length - move) + i) % length] = user_input[i];
	}
	// fill the original array with the correct shifted values
	for (int i = 0; i < length; i++)
	{
		user_input[i] = temp_input[i];
	}
	
}
/******************************************************************************************
*				ArrayRight
*This function will get passed a C-Style string and shift all elements to the right
*by 'x' elements.
*******************************************************************************************/
void ArrayRight(char user_input[], int length, int move)
{
	     const int SIZE = (length - 1);		// variable constant for size of cstring
	             char temp_input[SIZE];		// variable for array to be manipulated

	for (int i = 0; i < length; i++)
	{
		//  use a for loop to fill temporary array with the shifted characters 
		temp_input[(i + move) % length] = user_input[i];
	}
	// fill the original array with the correct shifted values
	for (int i = 0; i < length; i++)
	{
		user_input[i] = temp_input[i];
	}
	
}

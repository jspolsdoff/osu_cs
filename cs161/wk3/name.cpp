/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/15/14
*Last Modified Date:               10/19/14
*Filename:                         name.cpp
*
*Overview:
*This program will take a users name in the follow format: first name,
*middle name or initial, and finally last name. The program then outputs the name 
*in the format: last name, first name, middle initial.
*
*
*Input:
*The program will ask the user for their first, middle and last name.
*
*
*
*Output:
*The program will output the users name in the following format:
*last name, first name, and middle initial. It will place a period behind
*the initial
*
****************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{

	// declare variables
	    
		 int first_space,		// variable to store space between first and middle name
		    second_space;		// variable to store space between middle and last name
		string full_name,		// full name variable 
			  first_name,		// first name
			 middle_name,		// middle name
			   last_name,		// last name
	   full_name_correct;		// full name in correct format
	 char middle_initial;		// middle initial variable
			       int i;		// variable used for while loop for middle initial
	
	// tell the user about the program
	cout << "This program will take your name and put it in the correct format." << endl;
	
	// ask user for their first, middle and last name
	cout << "What is your first, middle, and last name: ";
	
	// store first name in string
	getline(cin, full_name);
	
	// find and store space between first and middle name
	first_space = full_name.find(" ");
	
	// find and store space between middle and last name
	second_space = full_name.find(" ", first_space+1);
	
	// get first name from full name string
	first_name = full_name.substr(0, first_space);
	
	// get middle name from full name string
	middle_name = full_name.substr(first_space+1, second_space - first_space);
	
	// get last name from full name string
	last_name = full_name.substr(second_space);
	
	
	// if the middle name variable is empty concatenate last and first name
	//if (middle_name.empty())
	//{
	//	full_name_correct = last_name + ", " + first_name;
	//}
	
	// else concatenate last, first, middle initial and add period
	//else
	//{
		// use loop to store middle initial in variable
	//	for (i=0; i < 1; i++)
	//	{
	//		middle_initial = middle_name.at(i);
	//	}
	
	//	full_name_correct = last_name + ", " + first_name + " " + middle_initial + ".";
	
	//}
	
	// print name in the assignment format
	cout << "The correct name format is: " << full_name_correct << endl;
	
	cout << middle_name << endl;
	
	return 0;
}  

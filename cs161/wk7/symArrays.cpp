/****************************************************************************
*Author:                          James Spolsdoff
*Dated Created:                   11/14/14   
*Last Modified Date:          	  11/14/14     
*Filename:                        symArrays.cpp
*
*Overview:
*This program will use command line arguments to take the size of three arrays 
*from the user. The program will ask to user to fill the arrays and call a 
*function that will tell the user if the arrays are symmetric.
*
*Input:
*The user will input the size of three arrays in the command line. The user
*will also allow the user to enter values for the arrays.
*
*Output:
*The output of the program will tell the user is the arrays are symmetric
*using a function.
*
****************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

// function prototype to test is array is symmetric
bool SymArrays(int [], int);

int main(int argc, char *argv[])
{
	// checks if the user did not input exactly three command line arguments
	if (argc != 4)
	{
		cout << "Please use only three command line arguments." << endl;
		exit(EXIT_FAILURE); 
	}
	
	const int FIRST_ARRAY_SIZE = atoi(argv[1]);		// variable for the first array defined in the command line
	const int SECOND_ARRAY_SIZE = atoi(argv[2]);		// variable for the second array defined in the command line
	const int THIRD_ARRAY_SIZE = atoi(argv[3]);		// variable for the third array defined in the command line
	int array1[FIRST_ARRAY_SIZE];				// first array from command line
	int array2[SECOND_ARRAY_SIZE];				// second array from command line
	int array3[THIRD_ARRAY_SIZE];				// third array from command line
	
	// this is a testing area
	cout << "This is the first constant " << FIRST_ARRAY_SIZE << endl;
	
	// tell the user what the program does
	cout << "This program will ask you to fill three arrays and tell you if they are symmetric.\n" << endl;
	
	// fill the first array using for loop
	cout << "Please fill the first array with " << FIRST_ARRAY_SIZE << " elements on one line seperated by a space: ";
	for (int i = 0; i < FIRST_ARRAY_SIZE; i++)
		cin >> array1[i];

	// fill the second array using for loop
	cout << "Please fill the second array with " << SECOND_ARRAY_SIZE << " elements on one line seperated by a space: ";
	for (int i = 0; i < SECOND_ARRAY_SIZE; i++)
		cin >> array2[i];
	
	// fill the third array using for loop
	cout << "Please fill the third array with " << THIRD_ARRAY_SIZE << " elements on one line seperated by a space: ";
	for (int i = 0; i < THIRD_ARRAY_SIZE; i++)
		cin >> array3[i];
	
	// pass all three arrays to function

	// return value of function and you if/else to display results
	if (SymArrays(array1, FIRST_ARRAY_SIZE) == 1)
		cout << "Array 1 is symmetric." << endl;
	else
		cout << "Array 1 is not symmetric." << endl;
	if (SymArrays(array2, SECOND_ARRAY_SIZE) == 1)
		cout << "Array 2 is symmetric." << endl;
	else
		cout << "Array 2 is not symmetric." << endl;
	if (SymArrays(array3, THIRD_ARRAY_SIZE) == 1)
		cout << "Array 3 is symmetric." << endl;
	else
		cout << "Array 3 is not symmetric." << endl;
		
	
	return 0;
}  

/***********************************************************************************
*				       SymArrays
*This function will be passed an array and check if the values are symmetric. It will
*return the result in a boolean value.
***********************************************************************************/
bool SymArrays(int array[], int array_size)
{
	int array_mirror = array_size - 1; 	

	for (int i = 0; i < array_size; i++)
	{
		if (array[i] != array[array_mirror])
		{	
			return false;
		}
		array_mirror--;
	}
	
	return true;
}

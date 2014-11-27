/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                11/5/14       
*Last Modified Date:          11/5/14    
*Filename:                        arrayAdd.cpp
*
*Overview:
*This program adds two arrays together using pointer arithmetic and
*stores the results in a third variable through the use of a function.
*
*Input:
*The user will input the number of elements in the arrays as well as
*all the values of the two arrays.
*
*Output:
*After the arguments are past to the function the program will display
*the third array that contains the sum of the first two arrays.
*
****************************************************************************/

#include <iostream>
#include <stdlib.h>		// include needed library
using namespace std;

// function prototype
void AddArray(int size, int array1[], int array2[], int array3[]);

int main()
{

	// declare variables
	const int SIZE = 50;		// variable constant for array size
	int elements;			// variable for number of elements in arrays
	int array1[SIZE];		// variable for first array
	int array2[SIZE];		// variable for second array
	int array3[SIZE];		// variable for third array that contains sum
	
	// tell the user what the program does
	cout << "This program will ask you for the size of two arrays followed by the input of numbers" << endl;
	cout << "to fill these two arrays. These two arrays will then be added together into a third array.\n" << endl;
	
	cout << "This is the first element of the first array " << *array1 << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << *array1 << " ";
		*array1++; 
	}

	
	// ask the user how many elements they will input in array
	cout << "How many elements will the arrays hold: ";
	cin >> elements;
	
	// use a for loop to fill the first array
	for (int i = 0; i < elements; i++)
	{
		cout << "Please enter an integer value for array one at index " << i << ": "; 
		cin >> array1[i];
	}
	// use a for loop to fill the second array
	for (int i = 0; i < elements; i++)
	{
		cout << "Please enter an integer value for array two at index" << i << ": ";
		cin >> array2[i];
	}
	// pass both arrays and element number to function
	AddArray(elements, array1, array2, array3);

	// print out the third array that contains the sum of the first two
	cout << "The sum of the elements of the first and second array are: ";
	for (int i =0; i < elements; i ++)
	{
		cout << array3[i] << " ";
	}
	
	cout << endl;	

	return 0;
}  

/******************************************************************************************
*											AddArray
*This function will get passed two arrays and use pointer arithmetic to add them
*together in a third array.
*******************************************************************************************/
void AddArray(int size, int array1[], int array2[], int array3[])
{
	// declare pointer variables
	int *array1Ptr = array1;
	int *array2Ptr = array2;
	int *array3Ptr = array3;
	
	for (int i = 0; i < size; i++) 
	{
		// add the two array elements together
		*array3Ptr = (*array1Ptr + *array2Ptr);
		
		// go to next location
		*array1Ptr++;
		*array2Ptr++;
		*array3Ptr++;
	}
}

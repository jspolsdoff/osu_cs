/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    11/4/14
*Last Modified Date:               11/4/14
*Filename:                         evenOdd.cpp
*
*Overview:
*This program will return the sum of the even values - sum of odd values of an 
*array. The user will input both the size and contents of the array.
*
*Input:
*The user will input the size and values of the array.
*
*Output:
*The program will output the sum of all the even values of the array - the sum
*of the odd numbers.
*
****************************************************************************/

#include <iostream>
using namespace std;

// function prototype
int SumArray(int, int []);

int main()
{

	// declare variables
			 int size = 0;			// variable for array size
			int num[size];			// variable for array
					int i;			// variable for loop
	
	// tell user what program does
	cout << "This program will ask you for the array size and values. It will then tell you the " << endl;
	cout << "difference between the sum of even and odd numbers.\n" << endl;
	
	// ask user for input for array size
	cout << "Please enter the size of the array: ";
	cin >> size;
	
	cout << "Please enter the " << size << " values for the array: ";
	
	// ask user for array values
	for (i = 0; i < size; i++)
	{
		cin >> num[i];
	}

	cout << "The difference between even and odd is " << SumArray(size, num) << endl;
	
	return 0;
}  

/************************************************************************
*							SumArray
*This functions gets passed an integer and array and returns the difference
*between the even and odd elements.
*************************************************************************/
int SumArray(int size, int num[])
{
					    int i;			// variable for loop
			 int even_sum = 0;			// variable for even sum
			  int odd_sum = 0;			// variable for odd sum
	
	// loop to go through elements of array
	for (i = 0; i < size; i++)
	{
		
		// if check if number is even and add element
		if (num[i] % 2 == 0)
		{
			even_sum += num[i];
		}
		// else number is odd and add element
		else
		{
			odd_sum += num[i];
		}
	}
	// calculate different between even and odd
	return even_sum - odd_sum;
	
}
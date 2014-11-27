/*******************************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    sameSum.cpp    
*Last Modified Date:               11/13/14     
*Filename:                         11/14/14
*
*Overview:
*This program will contain a function that will return a boolean value
*indicating whether all the rows, columns, and both diagonals of the user's 
*2D square array sum to the main value.
*
*Input:
*The user will fill the array with integers. The max size will be 10 x 10
*but the users doesn't have to fill the whole array.
*
*Output:
*The function will output the boolean value indicating whether all the rows, 
*columns, and both diagonals of the user's 2D square array sum to the same 
*value.
********************************************************************************************/

#include <iostream>
using namespace std;

const int NUM_COL = 10;		// constant for maximum number of columns in 2D array

// function prototype
bool SameSum(const int square[][NUM_COL], int);

int main()
{

	// declare needed variables
		const int NUM_ROW = 10;						// constant for maximum number of row in 2D array
		// const int NUM_COL = 10;						// constant for maximum number of columns in 2D array
		int square[NUM_ROW][NUM_COL];					// 2D array with a maximum of 10 rows and 10 columns
		int square_size;						// square size variable for loop maximum
		int row_loop, col_loop;						// loops variables
	
	// tell user what the program does
	cout << "This program will ask you to fill a 2D array and send it to a function." << endl;
	
	// ask the user how big their square will be
	cout << "How will be the size of your 2D array: ";
	
	// store value in variable for loop maximum to input values
	cin >> square_size;
	
	cout << "Please enter the values for the square array one row at a time. After each row press 'Enter'." << endl;
	cout << "Enter the values for the first row: ";

	// create nested loop to fill the array with user input
	for (row_loop = 0; row_loop < square_size; row_loop++)
	{
		for (col_loop = 0; col_loop < square_size; col_loop++)
		{
			cin >> square[row_loop][col_loop];		
		}
	}
	

	// use return value of function to tell user if all sums are equal
	if (SameSum(square, square_size) == false)
	{
		cout << "The sums of the array are not equal." << endl;
	}
	else
	{
		cout << "The sums of the array are equal." << endl;
	}
	

	// test area
	
	return 0;
}  

/********************************************************************************************************
*												SameSum
*This functions gets passed a 2D array and returns a boolean value indicating whether 
*all the rows, columns, and both diagonals of the user's 2D square array sum to the same 
*value.
*********************************************************************************************************/
bool SameSum(int const square[][NUM_COL], int square_size)
{
	int sum_check = 0;	// variable used to check equality across 2D array
	int dia_total = 0;	// variable used for diagonal sum total	

	// used to establish value to test equality against
	for (int col_loop = 0; col_loop < square_size; col_loop++)
	{
		sum_check += square[0][col_loop];
	}
	
	
	// loop to calculate the sum of all the row in the 2D array
	for (int row_loop = 0; row_loop < square_size; row_loop++)
	{
		// variable for total sum of each row
		int total = 0;

		for (int col_loop = 0; col_loop < square_size; col_loop++)
		{
			total += square[row_loop][col_loop];
		}
		// if statement to check if the sum of the rows are equal
		if (total != sum_check)
			return false;
	}
	// loop to calculate the sum of all the columns in the array
	for (int col_loop = 0; col_loop < square_size; col_loop++)
	{
		// variable for total sum of each column
		int total = 0;

		for (int row_loop = 0; row_loop < square_size; row_loop++)
		{
			total += square[row_loop][col_loop];
		}
		// if statement to check if the sum of the rows are equal
		if (total != sum_check)
			return false;
	}
	// loop to calculate the sum of the main diagonals of the array
	for (int row_col = 0; row_col < square_size; row_col++)
	{
		dia_total += square[row_col][row_col];
	}
	// if statement to check if the sum of the diagonal are equal
	if (dia_total != sum_check)
		return false;
	
	// reset diagonal sum variable
	dia_total = 0;
	
	for (int row_col = square_size -1; row_col >= 0; row_col--)
	{
		dia_total += square[row_col][row_col];
	}
	// if statement ot check if the sum of the diagonal are equal
	if (dia_total != sum_check)
		return false;

	return true;
}

/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    1/11/15    
*Last Modified Date:               1/11/15     
*Filename:                         pointers.cpp 
*
*Overview:
*This program will call a function that passes three pointers to int as args.
*It will print out args in order of smallest int to largest int.
*
*Input:
*The user will input three int values.
*
*Output:
*The program will output the int values from smallest to largest.
*
****************************************************************************/
#include <iostream>
#include <algorithm>

// function prototype for arranging pointers from lowest to highest
void Sort(int *x, int *y, int *z);

int main()
{
	int x = 0,	// variables for user inputs
	    y = 0,
	    z = 0;
					
	// ask user for input for first int variable and store
	std::cout << "Please enter an integer value for x: ";
	std::cin >> x;
	
	// ask user for input for second int variable and store
	std::cout << "Please enter an integer value for y: ";
	std::cin >> y;
	
	// ask user for input for third int variable and store
	std::cout << "Please enter an integer value for z: ";
	std::cin >> z;
	
	// print variable values on screen
	std::cout << "These are the values you entered: " << x << " " << y << " " << z << std::endl;
	
	// pass pointers to void function
	Sort(&x, &y, &z);
	
	// print new variable values on screen
	std::cout << "These are the values you entered after the function call: " << x << " " << y << " " << z << std::endl;
		
	return 0;
}

/***************************************************************************************************
 *					Sort
 *This fuction will put the pointers in order from lowest to highest value.
 *				
 ***************************************************************************************************/
 void Sort(int *x, int *y, int *z)
 {
	
	if (*x > *y)
		std::swap(*x, *y);
		
	if (*x > *z)
		std::swap(*x ,*z);
		
	if (*y > *z)
		std::swap(*y, *z);
		
 }

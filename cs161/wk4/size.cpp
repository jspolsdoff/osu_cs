/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:              	   10/26/14      
*Last Modified Date:               10/26/14
*Filename:                         size.cpp
*
*Overview:
*This program will tell the user the correct size hat, jacket, and pants to
*purchase based on their inputs.
*
*Input:
*The user will input their height in inches, weight in pounds, and age in 
*years.
*
*Output:
*The program will use three functions to out the users correct size hat,
*jacket, and pants.
*
****************************************************************************/

#include <iostream>
using namespace std;

// function prototypes 
int HatSize(int, int);
int JacketSize(int, int, int);
int WaistSize(int, int);

int main()
{
	
	// declare variables
		int height,			// variable for height in inches
			weight,			// variable for weight in lbs
			   age,			// variable for age in years
		  hat_size,			// variable for hat size
	   jacket_size,			// variable for jacket size
	    waist_size;			// variable for waist in inches
	    char again;			// variable to run program again
	
	// wrap function in do/while loop
	do
	{
	// tell user what program does
	cout << "This program will take your height, weight, and age and tell you your suit size." << endl;
	
	// ask user for height, weight, and age input and store in variables
	cout << "What is your height in inches: ";
	cin >> height;
	
	cout << "What is your weight in pounds: ";
	cin >> weight;
	
	cout << "What is your age in years: ";
	cin >> age;
	
	// pass needed args to HatSize, JacketSize, and WaistSize functions
	hat_size = HatSize(weight, height);
	jacket_size = JacketSize(height, weight, age);
	waist_size = WaistSize(weight, age);
	
	// return values to user 
	cout << "Your hate size is " << hat_size << endl;
	
	cout << "Your jacket size is " << jacket_size << endl;
	
	cout << "Your waist size is " << waist_size << endl;
	
	// ask if they would like to do another calculation
	cout << "Do you want to play again? (Y/N)";
		
	cin >> again;
	} while (toupper(again) == 'Y');
	
	return 0;
}  

/************************************************************************
*							HatSize
*This functions takes user input and returns their hat size
*************************************************************************/
int HatSize(int weight, int height)
{
	return (weight / height) * 2.9;
}
/************************************************************************
*							JacketSize
*This functions takes user input and returns their jacket size
*************************************************************************/
int JacketSize(int height, int weight, int age)
{
	double adjust = 0.13;
	     int jacket_size;
	
	jacket_size = (height * weight) / 288;
	
	if ((age >= 40) && (age < 50))
	{
		jacket_size = jacket_size + adjust;
	}
	else if ((age >= 50) && (age < 60))
	{
		jacket_size = jacket_size + (2 * adjust);
	}
	else if ((age >= 60) && (age < 70))
	{
		jacket_size = jacket_size + (3 * adjust);
	}
	else if ((age >= 70) && (age < 80))
	{
		jacket_size = jacket_size + (4 *adjust);
	}
	
	return jacket_size;
}
/************************************************************************
*							WaistSize
*This functions takes user input and returns waist size
*************************************************************************/
int WaistSize(int weight, int age)
{
	double waist,
	adjust = 0.1;
	       int i;
	
	waist = weight / 5.7;
	
	if (age >= 30)
	{
		for (i = 30; i <= age; i+2)
		{
			waist = waist + adjust;
		}
	}
	
	return waist;	
}
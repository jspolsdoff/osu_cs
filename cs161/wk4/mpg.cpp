/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/26/14 
*Last Modified Date:               10/26/14
*Filename:                         mpg.cpp
*
*Overview:
*This program will take the users input of miles driven and gasoline used
*in liters and return mpg.
*
*Input:
*The user will input miles driver and liters of gasoline consumed.
*
*Output:
*The output will be gas mileage in mpg.
*
****************************************************************************/

#include <iostream>
using namespace std;

// define global variable for liters per gallon
static const long double LITER_PER_GALLON = 0.264179;

// function prototype
double ConvertMpg(double, double);


int main()
{
	// declare variables
	double liters_consumed,		// user input for liters of gasoline consumed
	          miles_driven,		// user input for miles driven
			       mileage;		// calculated mileage after function
			    char again;		// user input for doing another calculation
	
	// wrap program in do/while loop
	do 
	{
	// tell user what program does
	cout << "This program will convert an input of liters and miles driven to miles per gallon." << endl;
	
	// ask user for liters consumed
	cout << "How many liters of gasoline did your car consume: ";
	
	cin >> liters_consumed;
	
	// ask user for miles driven
	cout << "How many miles did you drive: ";
	
	cin >> miles_driven;
	
	// pass two args to mpg function
	mileage = ConvertMpg(liters_consumed, miles_driven);
	
	// display answer to user
	cout << "Your gas mileage is " << mileage << " mpg." << endl;
	
	// ask if they would like to do another calculation
	cout << "Do you want to play again? (Y/N)";
		
	cin >> again;
	} while (toupper(again) == 'Y');
	
	return 0;
}  

/************************************************************************
*							ConvertMpg
*This functions takes user input and returns mpg calculation
*************************************************************************/
double ConvertMpg(double liters_consumed, double miles_driven)
{	
	return miles_driven / (liters_consumed * LITER_PER_GALLON);
}
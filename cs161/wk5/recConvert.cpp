/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    11/1/14
*Last Modified Date:               11/2/14
*Filename:                         recConvert.cpp
*
*Overview:
*This program will let the user convert a binary number to decimal, a decimal
*to binary or exit the program via a menu. The conversions will be done using
*recursion.
*
*Input:
*The user will input their menu choice along with the number (binary or decimal) that 
*they want to convert.
*
*Output:
*The program will output either a binary or decimal conversion based on the users
*input.
*
****************************************************************************/

#include <iostream>
#include <sstream>
#include <stdlib.h>		// include needed library
#include <string>
#include <math.h>
using namespace std;

// declare function prototypes
string DecToBinary(int);
int BinToDecimal(string, int, int ex = 0);

int main()
{
	cout << "Welcome to my number converter. Please choose from the following three options.\n" << endl;
	cout << "1) Convert a binary number to a decimal." << endl;
	cout << "2) Convert a decimal number to a binary." << endl;
	cout << "3) Exit this program.\n" << endl;
	
		  int select,		// variable for menu selection
				 pos,		// starting position for binary conversion
		   dec_input;		// variable for decimal to binary input
	string bin_input;		// variable for binary to decimal input
	
	// wrap menu with do/while loop so user can do another calculation
	do 
	{	
		cout << "Please enter your selection: ";
		cin >> select;
		cin.clear();
		cin.ignore(10000, '\n');
		
		// if option one converts binary to decimal
		if (select == 1)
		{
			// ask for a number to convert
			cout << "Please enter a binary number to convert: ";
			getline(cin, bin_input);
			
			// validate input
			for (int i = 0; i < bin_input.length(); i++)
			{
				if ((bin_input.at(i) != '1') && (bin_input.at(i) != '0'))
				{
					cout << "Your input is invalid. Please enter a binary number: ";
					getline(cin, bin_input);
					i = 0;
				}
			}
			
			pos = bin_input.length() - 1;
			
			// call and return value from function
			cout << "Your input of " << bin_input << " is " << BinToDecimal(bin_input, pos) << " in decimal." << endl;
		}
		// else if option two converts decimal to binary
		else if (select == 2)
		{
			// ask for a number to convert
			cout << "Please enter a positive integer to convert: ";
			cin >> dec_input;
			
			// validate input
			while (dec_input < 0)
			{
				cout << "Your input was negative. Please input a positive integer: ";
				cin >> dec_input;
			}
			
			// call and return value 
			cout << "Your input of " << dec_input << " is " << DecToBinary(dec_input) << " in binary." << endl;
		}
		// else if option three exits program
		else if (select == 3)
		{
			// display exit message
			cout << "Thank you for using my number converter." << endl;
			exit(EXIT_SUCCESS);
		}	
		// else entered invalid number and ask for new input
		else
		{
			cout << "Your input is invalid!" << endl;
		}
	
	} while((select <= 2) || (select >= 4));
	
	return 0;
}  

/************************************************************************
*							DecToBinary
*This functions gets passed a valid input and will convert a decimal number
*to its binary equivalent.
*************************************************************************/
// create recursive function to convert decimal to binary
string DecToBinary(int num)
{
			  int remainder;
	ostringstream bin_digit;
		
		remainder = num % 2;
			  num = num / 2;
			  
	// use recursive function to % 2 and use remainder to form binary number
	if (num == 0)
	{
		return "1";
	}

	else
	{
		bin_digit << remainder;
		return DecToBinary(num) + bin_digit.str();
	}
	
}
/************************************************************************
*							BinToDecimal
*This functions gets passed a valid input and will convert a binary number
*to its decimal equivalent.
*************************************************************************/
// create recursive function to convert binary to decimal
int BinToDecimal(string bin, int pos, int ex)
{
	int result;
	
	// base case
	 if (pos < 0)
    {
        return 0;
    }
    
    // use power of 2 for recursion
    else
    {
        if (bin.at(pos) == '1')
        {
            return pow(2, ex) + BinToDecimal(bin, pos - 1, ex + 1);
        }
        
        else
        {
            return 0 + BinToDecimal(bin, pos - 1, ex + 1);
        }
    }
    
}

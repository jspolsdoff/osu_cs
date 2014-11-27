/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/26/14
*Last Modified Date:               10/26/14
*Filename:                         finalist.cpp
*
*Overview:
*This program will select four people to win a prize out of 25 finalists.
*
*
*Input:
*The user just needs to press the 'enter' key.
*
*Output:
*The program will generate the winning numbers for 4 finalists.
*
****************************************************************************/

#include <iostream>
#include <cstdlib> 		// header for rand function
#include <ctime>   		// header for time function
using namespace std;

// function prototype
int WinningTicket(int, int);

int main()
{

	int first_finalist = 1,		// low range of random number
	    last_finalist = 25,		// high range of random number
		         last_pick,		// last random number selection
		      current_pick,		// current random number selection
						 i;		// variable for loop
	         unsigned seed;		// seed variable	
	
	// use time function to get seed for srand function
	seed = time(0);
	srand(seed);	
	
	// ask the user to press enter to begin generating random numbers
	cout << "This program will select 4 winning numbers from a pool of 25. Press 'Enter' to start.";
	cin.get();
	
	// use a for loop to generate random numbers
	for (i = 0; i < 5; i++)
	{
		current_pick = WinningTicket(last_finalist, first_finalist);
		
		while (current_pick == last_pick)
		{
			current_pick = WinningTicket(last_finalist, first_finalist);
		}
		
		cout << "Winning ticket " << current_pick << endl;
		last_pick = current_pick;
		
	}
		
	return 0;
}  

/************************************************************************
*							WinningTicket
*This functions returns a random number for the winning ticket
*************************************************************************/
int WinningTicket(int high_number, int low_number)
{
	return(rand() % ((high_number - low_number) + 1) + low_number);
}

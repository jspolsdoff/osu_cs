/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/10/14
*Last Modified Date:               10/11/14
*Filename:                         arcade2.cpp
*
*Overview:
*This program will evaluate how many tickets the user has a tell them how
*many candy bars and gumballs they can get. The user prefers candy bars
*so the maximum amounts of candy bars will be purchased with the remainder
*used for gumballs.
*
*Input:
*The user will input the number of tickets they have. By using a loop this is
*my first program with input validation to make sure the user isn't putting in
*a negative number of tickets.
*
*Output:
*The program will tell the user how many candy bars they can get with their
*tickets. First the maximum number of candy bars will be calculated. After
*the remainder will output how many gumballs can be purchased. The difference
*in this version is that loops are used in order to subtract tickets from the 
*users total.
****************************************************************************/

#include <iostream>
using namespace std;

int main()
{

	const int CANDY_BAR = 10,  // ticket cost of a candy bar
	          GUMBALL = 3;     // ticket cost of a gumball

	int tickets,               // number of tickets the user has
	    primary_candy = 0,     // number of candy bars they can get with tickets
	    remainder_candy = 0,   // number of gumballs they can get with remaining tickets
	    just_gumballs;         // if user doesn't have at least 10 tickets they get just gumballs

	// tell the user about what the program does and how their tickets will be used
	cout << "Great job winning all those tickets! I will help you convert your tickets into" << endl;

	cout << "candy bars and gumballs. Since you like candy bars the most I will first tell you the" << endl;

	cout << "maximum ammount of candy bars you can get. With the remainder I will tell you how many" << endl;

	cout << "gumballs you can get." << endl;

	cout << "Candy bars cost 10 tickets." << endl;

	cout << "Gumballs cost 3 tickets." << endl;

	// ask how many tickets the user has and store value in variable
	cout << "Lets get started! First tell me how many tickets you have: ";

	cin >> tickets;
	
	// validate that the user didn't input a negative number of tickets
	while (tickets <= 0)
	{
	   cout << "You can't have negative tickets! Please enter a positive number; ";
	   cin >> tickets;
	 }
	
	cout << "Wow, great job! Thats a lot of tickets!" << endl;

	// check if the user can buy at least one candy bar if not just give them gumballs
	if (tickets < CANDY_BAR)
	{
	  just_gumballs = (tickets / GUMBALL);

	  cout << "I'm sorry you can't get any candy bars but you can get " << just_gumballs << " gumballs." << endl;
	}

	else
	{
	  // run two loops to remove tickets from users input for candy bars then gumballs
	  while (tickets >= 10)
	  {
	    tickets = (tickets - CANDY_BAR);
	    primary_candy++;
	  }
	  
	  while (tickets >= 3)
	  {
	    tickets = (tickets - GUMBALL);
	    remainder_candy++;
	  }
	  
	  // tell user how many candy bars and gumballs they will get
	  cout << "With your tickets you can get " << primary_candy << " candy bars and " << remainder_candy << " gumballs." << endl;
	  
	  // tell user how many tickets they have left over
	  cout << "You have " << tickets << " left over.";
	}
	return 0;
}  

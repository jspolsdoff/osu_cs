/******************************************************************************
*Author:                     James Spolsdoff
*Date Created:               10/7/14
*Last Modified Date:         10/8/14
*Filename:                   fireslaw.cpp
*
*Overview:
*This program tests to see if a meeting room is in violation of the fire
*regulations regarding the maximum room capcity. It will tell you how many
*more people can attend if you are under the limit. If you are over the limit
*it will tell you how many people must leave the meeting.
******************************************************************************/

#include <iostream>
using namespace std;

int main()

{

	int room_capacity,    // the capacity of the meeting room
	    attendees,        // how many people will be attending the meeting
	    exclude,          // how many people to exclude if room is over limit
	    include;          // how many people to include if room in under limit

	
	// tell the user about the program and the needed inputs
	cout << "Before you can host your meeting we need to make sure that" << endl;
	
	cout << "you are in compliance with the fire laws." << endl;

	cout << "If you are in compliance I will tell you how many more people" << endl;

	cout << "you can invite to your meeting." << endl;

	cout << "If you are not in compliance I will tell you how many people you" << endl;

	cout << "need to ask to leave." << endl;
	
	// ask what their meeting room capacity is
	cout << "First tell me what the capacity of the room is: "; 
	
	// store in variable
	cin >> room_capacity;

	// ask how many people will attend the meeting
	cout << "How people will attend the meeting: ";

	// store in variable
	cin >> attendees;

	// test if the meeting is in compliance, if not tell user how many people must leave
	if (attendees > room_capacity) 
	{
	   exclude = (attendees - room_capacity);
	   cout << "You are in violation of the fire law and you must ask " << exclude << endl;	
	   cout << "people to leave the meeting." << endl;
	}
	
	// the room is in compliance with the law and tell user how many more people can attend
	else 
	{
	   include = (room_capacity - attendees);
	   cout << "You are in compliance with the fire law and you can invite " << include << endl;
	   cout << "more people to your meeting." << endl;
	}

	return 0;

}

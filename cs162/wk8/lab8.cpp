/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           3/3/15
*Last Modification Date: 3/1/15
*Filename:               lab8.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include <string>

struct Room
{
	Room *north;
	Room *east;
	Room *south;
	Room *west;
	
	Room()
	{
		north = NULL;
		east = NULL;
		south = NULL;
		west = NULL;
	}	
};

int main()
{
	// create the rooms for the maze
	Room *roomOne = new Room();
	Room *roomTwo = new Room();
	Room *roomThree = new Room();
	Room *roomFour = new Room();
	Room *roomFive = new Room();
	
	roomOne->east = roomTwo;
	roomTwo->north = roomThree;
	roomThree->north = roomFour;
	roomFour->east = roomFive;

	Room *player = roomOne;

	player = roomOne->north;
	
	return 0;
}



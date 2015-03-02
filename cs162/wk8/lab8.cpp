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
	std::string name;
	
	Room *north = NULL;
	Room *east = NULL;
	Room *south = NULL;
	Room *west = NULL;
}

int main()
{
	Room *roomOne = new Room();
	Room *roomTwo = new Room();
	
	roomOne->east = roomTwo;

	return 0;
}


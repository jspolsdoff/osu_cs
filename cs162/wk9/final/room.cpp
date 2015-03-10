#include <iostream>
#include "room.hpp"

/**************************************************************************************************
*						Room
*
***************************************************************************************************/
Room::Room()
{    
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	description = " ";
	wasVisited = false;
	isExit = false;
}

/**************************************************************************************************
*						Room
*
***************************************************************************************************/
Room::Room(std::string script)
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	description = script;
	wasVisited = false;
	isExit = false;
}

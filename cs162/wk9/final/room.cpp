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

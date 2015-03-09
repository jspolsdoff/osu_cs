#include <iostream>
#include "room.hpp"

/**************************************************************************************************
*						Room
*
***************************************************************************************************/
Room::Room()
{    
	Room newRoom;
    newRoom.north = NULL;
    newRoom.east = NULL;
    newRoom.south = NULL;
    newRoom.west = NULL;
    newRoom.wasVisited = false;
    newRoom.isExit = false;
}
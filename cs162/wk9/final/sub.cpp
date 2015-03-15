#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "sub.hpp"

/**************************************************************************************************
*						Submarine
*
***************************************************************************************************/
Submarine::Submarine()
{
	std::ifstream roomDescription("rooms.txt");
	std::string line;
	std::string description;
		
	if (!roomDescription)
    {
        std::cerr << "Error! Unable to open room descriptions file!" << std::endl;
        exit(1);
    }
	
	try
	{
		// attempt to read each of the rooms from the file
		for (int i = 0; i < 10; i++)
		{
			getline(roomDescription, line);
			std::cout << line << std::endl;
			// make sure each room starts off correctly
			if (line.find("<ROOM") == std::string::npos)
				throw "Error!"; // if not throw an exception

			// load the description from the file
			description = getRoomDescription(roomDescription);
			std::cout << description << std::endl;

			// create a room with the description
			Room *newRoom = new Room(description);
			rooms[i] = newRoom;
		}
    }
    
	catch (const char *e) // catch an exception that we throw
    {
        std::cerr << e << std::endl;
        exit(1);
    }
    
	catch (...)// catch any other exception that gets thrown
    {
        std::cerr << "Error reading rooms from file" << std::endl;
        exit(1);
    }
	
}

/**************************************************************************************************
*						getRoomDescription
*
***************************************************************************************************/
std::string Submarine::getRoomDescription(std::ifstream &input)
{
	std::string line; 
	std::string description;
	
    getline(input, line);
    // process each line until we get to the closing tag
    while (line.find("</ROOM") == std::string::npos)
    {
        description += line + "\n";
        getline(input, line);
    }

    return description;
}

/**************************************************************************************************
*						makeRoomLink
*
***************************************************************************************************/
void makeRoomLink(Room *room1, Room *room2, Direction dir)
{
    switch (dir)
    {
    case NORTH:
        room1->north = room2;
        room2->south = room1;
        break;
    case EAST:
        room1->east = room2;
        room2->west = room1;
        break;
    case SOUTH:
        room1->south = room2;
        room2->north = room1;
        break;
    case WEST:
        room1->west = room2;
        room2->east = room1;
        break;
    }
}

/**************************************************************************************************
*						configRooms
*
***************************************************************************************************/
void configRooms()
{
	// room 1
	makeRoomLink(rooms[0], rooms[1], SOUTH);
    makeRoomLink(rooms[1], rooms[0], NORTH);
	
	// room 2
	makeRoomLink(rooms[1], rooms[2], EAST);
	makeRoomLink(rooms[2], rooms[1], WEST);
	
	// room 3
	makeRoomLink(rooms[2], rooms[3], EAST);
	makeRoomLink(rooms[3], rooms[2], WEST);
	
	// room 4
	makeRoomLink(rooms[3], rooms[4], SOUTH);
	makeRoomLink(rooms[4], rooms[3], NORTH);
	
	// room 5
	
	// room 6
	
	// room 6
	
	// room 7
	
	// room 8
	
	// room 9
	
	// room 10

}
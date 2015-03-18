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

	key_card = false;
	pass_code = false;
		
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
			
			// make sure each room starts off correctly
			if (line.find("<ROOM") == std::string::npos)
				throw "Error!"; // if not throw an exception

			// load the description from the file
			description = getRoomDescription(roomDescription);
			
			// create a room with the description
			Room *newRoom = new Room(description);
			rooms[i] = newRoom;
		
			if (i == 8)
			{
				Room *newRoom = new ActionRoom(description);
				rooms[i] = newRoom;
			}
		}
    	
		rooms[9]->setExit();

		
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
	
	// close room description file
	roomDescription.close();

	// configure rooms
	configRooms();

	current_room = rooms[0]; 
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
void Submarine::makeRoomLink(Room *room1, Room *room2, int dir)
{
    switch (dir)
    {
    case 1: // north
        room1->north = room2;
        room2->south = room1;
        break;
    case 2: // east
        room1->east = room2;
        room2->west = room1;
        break;
    case 3: // south
        room1->south = room2;
        room2->north = room1;
        break;
    case 4: // west
        room1->west = room2;
        room2->east = room1;
        break;
    }
}

/**************************************************************************************************
*						configRooms
*
***************************************************************************************************/
void Submarine::configRooms()
{
	// 1 = north
	// 2 = east
	// 3 = south
	// 4 = west		

	// room 1
	makeRoomLink(rooms[0], rooms[1], 3);
    		
	// room 2
	makeRoomLink(rooms[1], rooms[2], 2);
		
	// room 3
	makeRoomLink(rooms[2], rooms[3], 2);
	
	// room 4
	makeRoomLink(rooms[3], rooms[5], 2);
		
	// room 5
	makeRoomLink(rooms[4], rooms[3], 1);
	
	// room 6
	makeRoomLink(rooms[5], rooms[6], 2);
		
	// room 7
	makeRoomLink(rooms[6], rooms[8], 2);
		
	// room 8
	makeRoomLink(rooms[7], rooms[6], 3);
		
	// room 9
	makeRoomLink(rooms[8], rooms[9], 2);
		
	// room 10
}

/**************************************************************************************************
*
*
***************************************************************************************************/
std::string Submarine::getCurrentRoomDescription()
{
	return current_room->getDescription();
}

/**************************************************************************************************
*
*
***************************************************************************************************/
int Submarine::getMoveDirection()
{
	int move_choice;

	if (current_room->north != NULL)
		std::cout << "You can move north." << std::endl;
	if (current_room->east != NULL)
		std::cout << "You can move east." << std::endl;
	if (current_room->south != NULL)
		std::cout << "You can move south." << std::endl;
	if (current_room->west != NULL)
		std::cout << "You can move west." << std::endl;

	do
	{
		// ask for move input
		std::cout << "\nNorth = 1\nEast = 2\nSouth = 3\nWest = 4\nQuit = 5" << std::endl;
		std::cout << "Which direction do you want to move: ";
		std::cin >> move_choice;
		
		// run validation loop
		while ((move_choice < 1) || (move_choice > 5))
		{
			std::cout << "Not a valid choice. Please enter another choice: ";
			std::cin >> move_choice;
		};

		if (move_choice == 5)
			exit(0);			 	 
	
	} while (!checkDirectionValid(move_choice));

	return move_choice; 
}

/**************************************************************************************************
*
*
***************************************************************************************************/
bool Submarine::checkDirectionValid(int move)
{     
	if (move == 1)
	{
		if (current_room->north == NULL)
		{
			std::cout << "Not a valid direction!" << std::endl;
			return false;
		}
		if (current_room == getRoom(6) && !(key_card))
		{
			std::cout << "This door is locked. It looks like you need some kind of keycard." << std::endl;
			return false;
		}
		else
			return true;
	}
	else if (move == 2)
	{
		if (current_room->east == NULL)
		{
			std::cout << "Not a valid direction!" << std::endl;
			return false;
		}
		if (current_room == getRoom(8) && !(current_room->getCode()))
		{
			std::cout << "You didn't enter the right code!" << std::endl;
			return false; 
		}  	
		else
			return true;
	}
	else if (move == 3)
	{
		if (current_room->south == NULL)
		{
			std::cout << "Not a valid direction!" << std::endl;
			return false;
		}
		else
			return true;
	} 
	else if (move == 4)
	{
		if (current_room->west == NULL)
		{
			std::cout << "Not a valid direction!" << std::endl;
			return false;
		}
		else
			return true;
	}

	
}

/**************************************************************************************************
*
*
***************************************************************************************************/
Room* Submarine::move(int move_choice)
{
	if (move_choice == 1)
	{
		return current_room->north;
	}
	else if (move_choice == 2)
	{
		return current_room->east;
	}
	else if (move_choice == 3)
	{
		return current_room->south;
	}
	else if (move_choice == 4)
  	{
		return current_room->west;
	}
}

/**************************************************************************************************
*
*
***************************************************************************************************/
Room* Submarine::getRoom(int i)
{
	return rooms[i];
}      

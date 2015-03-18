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

/**************************************************************************************************
*						test
*
***************************************************************************************************/
std::string Room::getDescription()
{
	return description;
}

/**************************************************************************************************
*
*
***************************************************************************************************/
void Room::setExit()
{
	isExit = true; 
}

/***************************************************************************************************
*
*
***************************************************************************************************/
bool Room::getIsExit()
{
	return isExit;
}

/***************************************************************************************************
*
*
***************************************************************************************************/
ActionRoom::ActionRoom(std::string script)
{
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	description = script;
	wasVisited = false;
	isExit = false;
	correct_code = false;
}

/**************************************************************************************************
*
*
***************************************************************************************************/
void Room::enterCode()
{
	int code_input;

	std::cout << "Please enter the code: ";
	std::cin >> code_input;

	while (code_input != 1234)
	{
		std::cout << "Please enter code again or enter 1 to EXIT: ";
		std::cin >> code_input;

		if (code_input == 1)
			return;
	}

	if (code_input == 1234)
	{
		correct_code = true;
		std::cout << "The door is now open. Quick head through and make your escape." << std::endl;
	}
}       

bool Room::getCode()
{
	return correct_code;
} 

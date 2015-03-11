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
			Room newRoom* = new Room(description);
			rooms.push_back(newRoom);
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

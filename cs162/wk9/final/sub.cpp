#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "sub.hpp"

/**************************************************************************************************
*						Submarine
*
***************************************************************************************************/
Submarine::Submarine()
{
	ifstream roomDescription("rooms.txt");
	std::string line;
	std::string description;
	
	if (!roomDescription)
    {
        std::cerr << "Error! Unable to open room descriptions file!" << endl;
        exit(1);
    }
	
	try
	{
		// attempt to read each of the rooms from the file
		for (int i = 0; i < 10; room++)
		{
			getline(roomDescriptions, line);
			// make sure each room starts off correctly
			if (line.find("<ROOM") == string::npos)
				throw "Error!"; // if not throw an exception

			// load the description from the file
			description = loadRoomDescription(roomDescription);
			// create a room with the description
			rooms[i] = createRoom(description);
		}
    }
    
	catch (const char *e) // catch an exception that we throw
    {
        std::cerr << e << endl;
        exit(1);
    }
    
	catch (...)// catch any other exception that gets thrown
    {
        std::cerr << "Error reading rooms from file" << endl;
        exit(1);
    }
	
}

/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           3/9/15
*Last Modification Date: 3/9/15
*Filename:               main.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include "room.hpp"
#include "sub.hpp"

int main()
{
	Submarine yellow_sub;

	std::cout << "The yellow submarine was created" << std::endl;
	
	std::cout << "These are the rooms in the yellow submarine:\n" << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << yellow_sub.room[i]->getDescription() << std::endl;
	}

	return 0;
}

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
			
	// while loop used to get user move and update position in the submarine
	while (!(yellow_sub.current_room->getIsExit()))
	{ 
		std::cout << yellow_sub.getCurrentRoomDescription() << std::endl;
			
		yellow_sub.current_room = yellow_sub.move(yellow_sub.getMoveDirection());	
	}

	std::cout << "You made it out alive" << std::endl;	

	return 0;
}

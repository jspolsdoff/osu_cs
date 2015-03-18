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
#include "user.hpp"
#include "room.hpp"
#include "sub.hpp"



int main()
{
	Submarine yellow_sub;
	int turns = 0;
	int menu_selection;	
	
	std::cout << "\nAND THEN THERE WAS ONE\n" << std::endl;
	std::cout << "Can you escape certain death?" << std::endl;

	std::cout << "Main Menu" << std::endl;
	std::cout << "1) Play Game" << std::endl;
	std::cout << "2) Quit" << std::endl;
	std::cout << "\nPlease enter your selection: " << std::endl;
	std::cin >> menu_selection;

	if (menu_selection == 2)
		exit(0);   
		
	// while loop used to get user move and update position in the submarine
	while (!(yellow_sub.current_room->getIsExit()))
	{ 
		turns++;

		std::cout << yellow_sub.getCurrentRoomDescription() << std::endl;
			
		yellow_sub.current_room = yellow_sub.move(yellow_sub.getMoveDirection());	
	
		if (yellow_sub.current_room == yellow_sub.getRoom(4))
		{
			yellow_sub.key_card = true;	
			std::cout << "You find a key card on the ground. It might be useful so you put it in your pocket." << std::endl;
		}
		if (yellow_sub.current_room == yellow_sub.getRoom(8))
			yellow_sub.rooms[8]->enterCode();

		// implementation of "time limit"
		if (turns > 4)
			std::cout << "Hurry the ships about to blow up" << std::endl; 

		if (turns > 15)
		{
			std::cout << "The ship blew up" << std::endl;	
			exit(0);
		}
	}

	std::cout << "You made it out alive" << std::endl;	

	return 0;
}

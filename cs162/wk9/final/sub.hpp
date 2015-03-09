#ifndef SUB_HPP
#define SUB_HPP
#include "room.hpp"

class Submarine
{
	private:
	Room rooms[10];
	
	public:
	Submarine();
	std::string getRoomDescription(std::ifstream &input);
	
};

#endif

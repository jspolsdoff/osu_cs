#ifndef SUB_HPP
#define SUB_HPP
#include "room.hpp"

class Submarine
{
	private:
	std::vector<Room *> rooms;
	
	public:
	Submarine();
	std::string getRoomDescription(std::ifstream &);
	
};

#endif

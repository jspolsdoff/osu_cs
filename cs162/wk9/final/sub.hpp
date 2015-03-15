#ifndef SUB_HPP
#define SUB_HPP
#include "room.hpp"

class Submarine
{
	private:
	Room *rooms[10];
	enum Direction { NORTH, EAST, SOUTH, WEST };
	
	public:
	Submarine();
	std::string getRoomDescription(std::ifstream &);
	void makeRoomLink(Room *room1, Room *room2, Direction dir);
	void configRooms();
	
};

#endif

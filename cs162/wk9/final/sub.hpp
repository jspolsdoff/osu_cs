#ifndef SUB_HPP
#define SUB_HPP
#include "room.hpp"

class Submarine
{
	// private:
	public: 
	Room *rooms[9];
	// Room *current_room;	

	// public:
	Submarine();
	Room *current_room;
	std::string getRoomDescription(std::ifstream &);
	void makeRoomLink(Room *room1, Room *room2, int dir);
	void configRooms();
	std::string getCurrentRoomDescription();
	int getMoveDirection();
	bool checkDirectionValid(int);
	Room* move(int);
};

#endif

#ifndef SUB_HPP
#define SUB_HPP
#include "room.hpp"
#include "user.hpp"

class Submarine
{
	// private:
	public: 
	Room *rooms[9];
	bool key_card;
	bool pass_code;
		
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
	Room* getRoom(int i);
};

#endif

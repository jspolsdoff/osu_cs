#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room
{
	protected:
	Room *north;
    Room *east;
    Room *south;
    Room *west;
	std::string description;
    bool wasVisited;
    bool isExit;
	
	public:
	virtual Room();
	
};

// basic derived room
class BasicRoom : public Room
{
	private:
	
	
	public:
	// virtual Room();
};

// room that contains an item
class ItemRoom : public Room
{
	private:
	
	
	public:
	// virtual ItemRoom();
};

// room that triggers an action
class ActionRoom : public Room
{
	private:
	
	
	public:
	// virtual ActionRoom();
};

#endif
#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

class Room
{
	public:
	Room *north;
    Room *east;
    Room *south;
    Room *west;
	std::string description;
    bool wasVisited;
    bool isExit;
	
	
	Room();
	Room(std::string script);
	std::string getDescription();
	void setExit();
	bool getIsExit();
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

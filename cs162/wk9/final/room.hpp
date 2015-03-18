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
	bool correct_code;	

	Room();
	Room(std::string script);
	std::string getDescription();
	void setExit();
	bool getIsExit();
	void enterCode();
	bool getCode();
	
};

// basic derived room
class LockedRoom : public Room
{
	private:
	
	
	public:
	
};

// room that contains an item
class ItemRoom : public Room
{
	private:
	
	
	public:
	
};

// room that triggers an action
class ActionRoom : public Room
{
	private:
	int enter_code;
	bool correct_code;
	
	public:
	ActionRoom(std::string script);
	void enterCode();
	bool getCode();	
};

#endif

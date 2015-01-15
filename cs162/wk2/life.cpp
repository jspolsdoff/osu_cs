/**************************************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    1/15/15
*Last Modified Date:               1/15/15
*Filename:                         menu.cpp
*
*Overview:
*This is a program designed to mimic Conway's Game of Life.
*
*Input:
*The user will be able to pick a type of pattern from the menu.
*
*Output:
*The board will display the pattern throughout the different generations of life.
*
*
**************************************************************************************************/

#include <iostream>

// create the class that will represent the cell object
class Cell
{
	private:
	bool alive;
	
	public:
	Cell();	// default constructor that sets alive to F
	void setAlive(bool);
	bool getAlive();
};

// create the class that will represent the live board object
class Board
{
	private:
	Cell life[80][22];
	
	public:
	void setBlinker();
	void runLife();	// function to run 100 generations of the game of life
};

int main()
{
	std::cout << "Just a quick test" << std::endl;
	// create board object
	// display menu with choice of 3 patterns that the user can choose
		// ask for starting coordinates from user
	// use if/else statement to call correct Board initialize member function
	// call runLife function

	return 0;
}

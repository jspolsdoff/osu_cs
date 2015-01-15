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
#include <iomanip>

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
	Board board;
	
	for (int row = 0; row < 80; row++)
	{ for (int col = 0; col < 22; col++)
		{
			std::cout << std::setw(5) << board.life[row][col] << " ";
		}
		std::cout << std::endl;
	}
	
	
	// create board object
	// display menu with choice of 3 patterns that the user can choose
		// ask for starting coordinates from user
	// use if/else statement to call correct Board initialize member function
	// call runLife function

	return 0;
}

// Cell class member functions
/**************************************************************************************************
 *						Cell
 *This is the constructor for the Cell class. It builds a Cell object default values.
 **************************************************************************************************/ 
 Cell::Cell()
 {
	alive = false;
 }
 
 /**************************************************************************************************
 *						setAlive
 *This function will set the status of the cell to either dead or alive.
 **************************************************************************************************/ 
void Cell::setAlive(bool status)
 {
	alive = status;
 }
 
 /**************************************************************************************************
 *						getAlive
 *This function will tell you if the cell is dead or alive.
 **************************************************************************************************/ 
bool Cell::getAlive()
{
	return alive;
}

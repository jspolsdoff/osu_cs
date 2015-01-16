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
#include <stdlib.h>

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
	Cell life[22][80];
	Cell temp_life[22][80];
	
	public:
	Board();
	void setBlinker(int start_row, int start_col);
	void runLife();	// function to run 100 generations of the game of life
	
	void printBoard();	// test function to print the life array
};

int main()
{
	// create board object
	Board life_board;
	int menu_choice = 0;
	int start_row = 0;
	int start_col = 0;
	
	life_board.printBoard();
	
	// display menu with choice of 3 patterns that the user can choose
	std::cout << "\nWELCOME TO CONWAYS GAME OF LIFE\n" << std::endl;

	std::cout << "Please choose from one of the four options below\n" << std::endl;

	std::cout << "1) Blinker" << std::endl;
	std::cout << "2) Glider" << std::endl;
	std::cout << "3) Gun" << std::endl;
	std::cout << "4) Quit\n" << std::endl;

	std::cout << "Please enter your selection: ";
	std::cin >> menu_choice;
  
	// ask for starting coordinates from user
	std::cout << "Please enter start x coordinate for the pattern: ";
	std::cin >> start_row;
	
	std::cout << "Please enter the start y coordinate for the pattern: ";
	std::cin >> start_col;

	// wrap in do/while loop for input validation 
	// use if/else statement to call correct Board initialize member function
	if (menu_choice == 1)
	{	
		std::cout << "Blinker pattern holder" << std::endl;
		// build pattern by passing variables to function
		life_board.setBlinker(start_row, start_col);
		// call runLife function 
		life_board.printBoard();
	}
	else if (menu_choice == 2)
		std::cout << "Glider pattern holder" << std::endl;
		// build pattern by passing variables to function
	else if (menu_choice == 3)
		std::cout << "Gun pattern holder" << std::endl;
		// build pattern by passing variables to function
	else if (menu_choice == 4)
		exit(EXIT_SUCCESS); 
	
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

// Board class member functions
/***************************************************************************************************
 *						Board
 *This is the default board constructor.
 **************************************************************************************************/ 
Board::Board()
{
	for (int row = 0; row < 22; row++)
	{
		for (int col = 0; col < 80; col++)
		{
			life[row][col].setAlive(false);
		}
	}
}

/**************************************************************************************************
 *						setBlinker
 *This function will set up the Game of Life board with the blinker pattern. 
 **************************************************************************************************/
void Board::setBlinker(int start_row, int start_col)
{
	for (int row = start_row; row < (start_row + 1); row++)
	{
		for (int col = start_col; col < (start_col + 3); col++)
		{
			life[row][col].setAlive(true);
		}
	}
}
 
/**************************************************************************************************
 *						runLife
 *This the main life function it contains all the logic to decide who lives and dies. 
 **************************************************************************************************/
void Board::runLife()
{
	int neighbors = 0;

	for (int gen = 0; gen < 100; gen++)
	{
		// nested loop to run through the whole life board
		for (int row = 0; row < 22; row++)
		{
			for (int col = 0; col < 80; col++)
			{ 
				// check upper-right diagonal for neighbor
				if (life[row][col] == true)
					neighbors++;
				// check right for neighbor
				// check lower-right diagonal for neighbor
				// check bottom neighbor
				// check lower-left diagonal for neughbor
				// check left neighbor
				// check upper-left for neighbor
				// check above for neighbor
			
				// check if cell is currently alive
					// if neighbors less than or equal to 1 it dies
					// else if neighbors are greater than 3 it dies
					// else it stays alive
				// else current cell is dead
					// if neighbors equal to 3 then there is a birth 	   
			}
		}
	}
}
 
 /**************************************************************************************************
 *						printBoard
 *This function will print the board.
 **************************************************************************************************/
 void Board::printBoard()
 {
	
	for (int row = 0; row < 22; row++)
	{ 
		for (int col = 0; col < 80; col++)
		{
			//std::cout << false;
			std::cout << life[row][col].getAlive();
		}
		std::cout << std::endl;
	}
 }

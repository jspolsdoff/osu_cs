/**************************************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    1/15/15
*Last Modified Date:               1/16/15
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
#include <string>

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
	Cell life[32][90];
	Cell temp_life[32][90];
	
	public:
	Board();
	void setBlinker(int start_row, int start_col);
	void setGlider(int start_row, int start_col);
	void setGun(int start_row, int start_col);
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
	
	// life_board.printBoard();
	
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
	std::cout << "Please enter start row  coordinate for the pattern: ";
	std::cin >> start_row;
	// adding 5 to account for oversize board so that edges calculate correctly
	start_row = start_row + 5;
	
	std::cout << "Please enter the start column coordinate for the pattern: ";
	std::cin >> start_col;
	// adding 5 to account for oversize board so that edges calculate correctly
	start_col = start_col + 5;

	// wrap in do/while loop for input validation 
	do {
		// use if/else statement to call correct Board initialize member function
		if (menu_choice == 1)
		{	
			// build pattern by passing variables to function
			life_board.setBlinker(start_row, start_col);
			// call runLife function 
			life_board.printBoard();
			life_board.runLife();
		}
		else if (menu_choice == 2)
		{
			// build pattern by passing variables to function
			life_board.setGlider(start_row, start_col);
			// call runLife function
			life_board.printBoard();
			life_board.runLife();
		}	
		else if (menu_choice == 3)
		{
			// build pattern by passing variables to function
			life_board.setGun(start_row, start_col);
			// call runLife function
			life_board.printBoard();
			life_board.runLife();
		}	
		else if (menu_choice == 4)
			exit(EXIT_SUCCESS); 
	} while(!menu_choice == 4);
	
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
	for (int row = 0; row < 32; row++)
	{
		for (int col = 0; col < 90; col++)
		{
			life[row][col].setAlive(false);
		}
	}

	for (int row = 0; row < 32; row++)
	{
		for (int col = 0; col < 90; col++)
		{
			temp_life[row][col].setAlive(false);
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
 *						setGlider
 *This function will set up the Game of Life board with the blinker pattern. 
 **************************************************************************************************/
 void Board::setGlider(int start_row, int start_col)
 {
	life[start_row][start_col + 1].setAlive(true);
	life[start_row + 1][start_col + 2].setAlive(true);
 	life[start_row + 2][start_col].setAlive(true);
	life[start_row + 2][start_col + 1].setAlive(true);
	life[start_row + 2][start_col + 2].setAlive(true);
 }
 
 /**************************************************************************************************
 *						setGun
 *This function will set up the Game of Life board with the blinker pattern. 
 **************************************************************************************************/
 void Board::setGun(int start_row, int start_col)
 {
	// building the smallest glider gun 
	life[start_row][start_col + 25].setAlive(true);
	life[start_row + 1][start_col + 23].setAlive(true);
 	life[start_row + 1][start_col + 25].setAlive(true);
	life[start_row + 2][start_col + 13].setAlive(true);
	life[start_row + 2][start_col + 14].setAlive(true);
	life[start_row + 2][start_col + 21].setAlive(true);
	life[start_row + 2][start_col + 22].setAlive(true);
	life[start_row + 2][start_col + 35].setAlive(true);
	life[start_row + 2][start_col + 36].setAlive(true);
	life[start_row + 3][start_col + 12].setAlive(true);
	life[start_row + 3][start_col + 16].setAlive(true);
	life[start_row + 3][start_col + 21].setAlive(true);
	life[start_row + 3][start_col + 22].setAlive(true);
	life[start_row + 3][start_col + 35].setAlive(true);
	life[start_row + 3][start_col + 36].setAlive(true);
	life[start_row + 4][start_col].setAlive(true);
	life[start_row + 4][start_col + 1].setAlive(true);
	life[start_row + 4][start_col + 11].setAlive(true);
	life[start_row + 4][start_col + 17].setAlive(true);
	life[start_row + 4][start_col + 21].setAlive(true);
	life[start_row + 4][start_col + 22].setAlive(true);
	life[start_row + 5][start_col].setAlive(true);
	life[start_row + 5][start_col + 1].setAlive(true);
	life[start_row + 5][start_col + 11].setAlive(true);
	life[start_row + 5][start_col + 15].setAlive(true);
	life[start_row + 5][start_col + 17].setAlive(true);
	life[start_row + 5][start_col + 18].setAlive(true);
	life[start_row + 5][start_col + 23].setAlive(true);
	life[start_row + 5][start_col + 25].setAlive(true);
	life[start_row + 6][start_col + 11].setAlive(true);
	life[start_row + 6][start_col + 17].setAlive(true);
	life[start_row + 6][start_col + 25].setAlive(true);
	life[start_row + 7][start_col + 12].setAlive(true);
	life[start_row + 7][start_col + 16].setAlive(true);
	life[start_row + 8][start_col + 13].setAlive(true);
	life[start_row + 8][start_col + 14].setAlive(true);
 }
 
/**************************************************************************************************
 *						runLife
 *This the main life function it contains all the logic to decide who lives and dies. 
 **************************************************************************************************/
void Board::runLife()
{
	int neighbor = 0;

	for (int gen = 0; gen < 100; gen++)
	{
		std::cout << "\nTHIS IS GENERATION " << (gen + 1) << "\n" << std::endl;

		// nested loop to run through the whole life board
		for (int row = 2; row < 30; row++)
		{
			for (int col = 2; col < 88; col++)
			{ 
				// check upper-right diagonal for neighbor
				if (life[row - 1][col + 1].getAlive() == true)
					neighbor++;
				// check right for neighbor
				if (life[row][col +1].getAlive() == true)
					neighbor++;
				// check lower-right diagonal for neighbor
				if (life[row + 1][col + 1].getAlive() == true)
					neighbor++;
				// check bottom neighbor
				if (life[row + 1][col].getAlive() == true)
					neighbor++;
				// check lower-left diagonal for neughbor
				if (life[row + 1][col -1].getAlive() == true)
					neighbor++;
				// check left neighbor
				if (life[row][col -1].getAlive() == true)
					neighbor++;
				// check upper-left for neighbor
				if (life[row - 1][col - 1].getAlive() == true)
					neighbor++;
				// check above for neighbor
				if (life[row - 1][col].getAlive() == true)
					neighbor++;
			
				// check if cell is currently alive
				if (life[row][col].getAlive() == true)
				{
					// if neighborsiless than or equal to 1 it dies
					if (neighbor <= 1)
						temp_life[row][col].setAlive(false);
					// else if neighbors are greater than 3 it dies
					else if (neighbor > 3)
						temp_life[row][col].setAlive(false);
					// else it stays alive
					else if (neighbor == 2)
						temp_life[row][col].setAlive(true);
					else if (neighbor == 3)
						temp_life[row][col].setAlive(true);
				}
				
				// else current cell is dead
				else
				{
					// if neighbors equal to 3 then there is a birth
					if (neighbor == 3)
						temp_life[row][col].setAlive(true);
					// else
					//	temp_life[row][col].setAlive(false);
				}
				neighbor = 0;
			}
		}
	
		// copy temp_life over to life (need to test!!!!)
		for (int row = 0; row < 32; row++)
		{
			for (int col = 0; col < 90; col++)
			{ 
				life[row][col].setAlive(temp_life[row][col].getAlive());
			}
		}	
		// print the board of life
		printBoard();	
	}
}
 
 /**************************************************************************************************
 *						printBoard
 *This function will print the board.
 **************************************************************************************************/
 void Board::printBoard()
 {
	
	for (int row = 5; row <= 27; row++)
	{ 
		for (int col = 5; col <= 85; col++)
		{
			std::cout << life[row][col].getAlive();
		}
		std::cout << std::endl;
	}
 }

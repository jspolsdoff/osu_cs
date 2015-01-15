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

// run game of life with simple oscillator pattern
// run game of life with glider pattern
// run game of life with gun pattern

int main()
{
	// size of the visible world of life
	// 2D array to hold the current generation of life
	// 2D temp array to hold the next generation of life while logic runs on correct generation
	// the row coordinate for the starting location
	// the column coordinate for the starting location

	std::cout << "WELCOME TO CONWAYS GAME OF LIFE/n" << std::endl;
	
	// user is told how big the life board is
	std::cout << "The life board is 80 x 22 cells. You will be allowed to specify the starting location" << std::endl;
	std::cout << "once you have selected your pattern./n" << std::endl;
	
	// user menu to select life pattern
	std::cout << "Please choose from one of the patterns below to start the game./n" << std::endl;
	
	std::cout << "1) Simple Oscillator" << std::endl;
	// ask for the start location of the pattern
	// pass the starting location along with both 2D arrays to oscillator function
	
	std::cout << "2) Glider" << std::endl;
	// ask for the start location of the pattern
	// pass the starting location along with both 2D arrays to glider function
	
	std::cout << "3) Gun" << std::endl;
	// ask for the start location of the pattern
	// pass the starting location along with both 2D arrays to gun function

	return 0;
}

 /**************************************************************************************************
 *					Oscillator																
 *
 ***************************************************************************************************/
void Oscillator()
{
	// initialize life board with the oscillator pattern using nested loops and print
	// run loop for 100 generations
		// run logic rules through nested loop and store values
		// print array
		// copy temp array to original array
		// print array
		
}

 /**************************************************************************************************
 *					Glider										
 *
 ***************************************************************************************************/
void Glider()
{

}

 /**************************************************************************************************
 *					Gun											
 *
 ***************************************************************************************************/
void Gun()
{

} 
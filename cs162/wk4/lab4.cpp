/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/01/15
*Last Modification Date: 2/01/15
*Filename:               lab4.cpp
*
*Overview
*This program will act as a simulation of rolling dice. It will derive a loadedDice class from the
*original dice class.
***************************************************************************************************/
#include <iostream>
#include <stdlib.h>

// define Dice class
class Dice
{
	public:
	Dice();
	Dice(int numSides);
	virtual int rollDice() const;
	
	protected:
	int numSides;
};

// define LoadedDice class that will be derived from the Dice class

// function prototype for rolling two dice together
int rollTwoDice(const Dice& die1, const Dice& die2);

int randTest();

// write the main function that will call the rolling dice functions
int main()
{
	Dice die1, die2;
	int result = 0;
	int test = 0;
	
	std::cout << "This is a dice rolling simulator." << std::endl;
	
	result = rollTwoDice(die1, die2);
	test = randTest();	

	std::cout << "The result of rolling two dice is: " << result << std::endl;
	
	std::cout << "This is the test 1-2 generator: " << test << std::endl;

	return 0;
}

// below are the member functions for the Dice class
/**************************************************************************************************
 *						Dice
 *
 **************************************************************************************************/
 Dice::Dice()
 {
	numSides = 6;
	srand(time(NULL));	// seed random number generator
 }
 
 /**************************************************************************************************
 *						Dice
 *
 **************************************************************************************************/
 Dice::Dice(int numSides)
 {
	this->numSides = numSides;
	srand(time(NULL));	// seed random number generator
 }
 
 /**************************************************************************************************
 *						rollDice
 *
 **************************************************************************************************/
int Dice::rollDice() const
{
	return (rand() % numSides) + 1;
}

// below are the member functions for the LoadedDice class
/**************************************************************************************************
 *						
 *
 **************************************************************************************************/

// function for rolling two dice
/**************************************************************************************************
 *						rollTwoDice
 *
 **************************************************************************************************/
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}

/**************************************************************************************************
 *
 *
 **************************************************************************************************/
int randTest()
{
	int loaded = 0;
	
	srand(time(NULL));
	
	loaded = (rand() % 2) + 1;

	return loaded;
}  

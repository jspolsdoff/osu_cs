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
class LoadedDice:public Dice
{
	public:
	virtual int rollDice() const;
};

// function prototype for rolling two dice together
int rollTwoDice(const Dice& die1, const Dice& die2);

// write the main function that will call the rolling dice functions
int main()
{
	LoadedDice die1, die2;
	int result = 0;
	
	std::cout << "This is a dice rolling simulator." << std::endl;
	
	for (int i = 0; i < 100; i++)		
	{
		result = rollTwoDice(die1, die2);

		std::cout << result << std::endl;
	}

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

// loaded dice override rollDice function
/**************************************************************************************************
 *						rollDice
 *
 **************************************************************************************************/
int LoadedDice::rollDice() const
{
	int loaded = 0;
	
	loaded = (rand() % 2) + 1;

	if (loaded == 2)
		return numSides;
	
	else
		return (rand() % (numSides - 1)) + 1;
}  

// function for rolling two dice
/**************************************************************************************************
 *						rollTwoDice
 *
 **************************************************************************************************/
int rollTwoDice(const Dice& die1, const Dice& die2)
{
	return die1.rollDice() + die2.rollDice();
}



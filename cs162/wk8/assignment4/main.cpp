/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/22/15
*Last Modification Date: 3/1/15
*Filename:               main.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <stack>

class Creature
{
	protected:
	int str_points;
	int armor;
	int atk_die_num;
	int atk_die_side;
	int def_die_num;
	int def_die_side;
	
	public:
	virtual int attack();
	virtual int defense(int);
	int getHealth();
};

class Barbarian : public Creature
{
	public:
	Barbarian();
};

class ReptilePeople : public Creature
{
	public:
	ReptilePeople();
};

class BlueMen : public Creature
{
	public:
	BlueMen();
};

class TheShadow : public Creature
{
	public:
	TheShadow();
	int defense(int);
};

class Goblin : public Creature
{
	private:
	bool achilles;
	
	public:
	Goblin();
	virtual int attack();
	virtual int defense(int);
};

// function prototype to fill creature lineup
void FillLineup(int lineup_num, std::queue<Creature *> & lineup);	

int main()
{
	std::queue<Creature *> p1_lineup;	// create container of creature pointers for player 1
	std::queue<Creature *> p2_lineup;	// create container of creature pointers for player 2
	std::stack<Creature *> losers;	// create container of creature for losers
	int lineup_num;	// variable for number of creatures in lineup
	 
	std::cout << "WELCOME TO THE WARRIOR'S ARENA\n" << std::endl;

	// ask user for number of creatures to include in the line-up
	std::cout << "How many fighters will be in each players line-up: ";
	std::cin >> lineup_num;
	
	// pass player 1 container to function to fill line-up
	FillLineup(lineup_num, p1_lineup);
	
	// pass player 2 container to function to fill line-up 
	// do while loop to contain
		// run fighter match-up function
	//
	
	return 0;
}

//base class functions
/**************************************************************************************************
*						attack
*
**************************************************************************************************/
int Creature::attack()
{
	int atk_value = 0;
			
	for (int i = 0; i < atk_die_num; i++)
	{
		atk_value = atk_value + ((rand() % atk_die_side) + 1);
	}
	
	return atk_value;
}

/**************************************************************************************************
*						defense
*
**************************************************************************************************/
int Creature::defense(int opp_atk)
{
	int def_value = 0;
	int result = 0;
		
	for (int i = 0; i < def_die_num; i++)
	{
		def_value = def_value + ((rand() % def_die_side) + 1);
	}
	
	if (opp_atk - def_value - armor > 0)
	{ 	
		str_points = str_points - (opp_atk - def_value - armor);
	}	

	result = str_points;

	return result;
}

/**************************************************************************************************
 *						getHealth
 *
 **************************************************************************************************/
int Creature::getHealth()
{
	return str_points;
} 

// using polymorphism to construct barbarian
/**************************************************************************************************
 *						Barbarian
 *
 **************************************************************************************************/
Barbarian::Barbarian()
 {
	str_points = 12;
	armor = 0;
	atk_die_num = 2;
	atk_die_side = 6;
	def_die_num = 2;
	def_die_side = 6;
 }
 
 // using polymorphism to construct ReptilePeople
/**************************************************************************************************
 *						ReptilePeople
 *
 **************************************************************************************************/
ReptilePeople::ReptilePeople()
 {
	str_points = 18;
	armor = 7;
	atk_die_num = 3;
	atk_die_side = 6;
	def_die_num = 1;
	def_die_side = 6;
 }
 
 // using polymorphism to construct BlueMen
/**************************************************************************************************
 *						BlueMen
 *
 **************************************************************************************************/
BlueMen::BlueMen()
 {
	str_points = 12;
	armor = 3;
	atk_die_num = 2;
	atk_die_side = 10;
	def_die_num = 3;
	def_die_side = 6;
 }
 
 // using polymorphism to construct TheShadow
/**************************************************************************************************
 *						TheShadow
 *
 **************************************************************************************************/
TheShadow::TheShadow()
 {
	str_points = 12;
	armor = 0;
	atk_die_num = 2;
	atk_die_side = 10;
	def_die_num = 1;
	def_die_side = 6;
 }
 
 /**************************************************************************************************
 *						defense
 *
 **************************************************************************************************/
int TheShadow::defense(int opp_atk)
{
	int def_value = 0;
	int result = 0;
	int special = 1;

	special = (rand() % 2) + 1;
	std::cout << "Special: " << special << std::endl;
	
	if (special == 1)
		result = str_points;
	else
	{
		for (int i = 0; i < def_die_num; i++)
		{
			def_value = def_value + ((rand() % def_die_side) + 1);
		}

		if (opp_atk - def_value > 0)
		{
			str_points = str_points - (opp_atk - def_value - armor);
		
			result = str_points;
		}
	}

	return result;
}
 
 // using polymorphism to construct Goblin
/**************************************************************************************************
 *						Goblin
 *
 **************************************************************************************************/
Goblin::Goblin()
 {
	str_points = 8;
	armor = 3;
	atk_die_num = 2;
	atk_die_side = 6;
	def_die_num = 1;
	def_die_side = 6;
	achilles = false;
 }
 
 /**************************************************************************************************
 *						attack
 *
 **************************************************************************************************/
 int Goblin::attack()
{
	int atk_value = 0;

	for (int i = 0; i < atk_die_num; i++)
	{
		atk_value = atk_value + ((rand() % atk_die_side) + 1);
	}

	if (achilles != true)
	{
		if (atk_value == 12)
		{
			achilles = true;
	
			std::cout << "The goblin cut its opponents achilles tendon" << std::endl;
		}
	}	

	return atk_value;
}

/**************************************************************************************************
 *						defense
 *
 **************************************************************************************************/
int Goblin::defense(int opp_atk)
{
	int def_value = 0;
	int result = 0;
	
	if (achilles == true)
		opp_atk = opp_atk / 2;

	for (int i = 0; i < def_die_num; i++)
	{
		def_value = def_value + ((rand() % def_die_side) + 1);
	}

	if (opp_atk - def_value > 0)
	{
		str_points = str_points - (opp_atk - def_value - armor);

		result = str_points;
	}

	return result;
}

/**************************************************************************************************
 *						FillLineup
 *
 **************************************************************************************************/
void FillLineup(int lineup_num, std::queue<Creature *> & lineup)
{
	Creature *fighter;	// declare pointer to Creature class
	int selection;
	
	// display list of fighters
	std::cout << "\nList of Creatures\n" << std::endl;
	std::cout << "1) Goblin" << std::endl;
	std::cout << "2) Barbarian" << std::endl;
	std::cout << "3) Reptile People" << std::endl;
	std::cout << "4) Blue Men" << std::endl;
	std::cout << "5) The Shadow\n" << std::endl; 
	
	// for loop to fill queue with creature pointers
	for (int i = 0; i < lineup_num; i++)
	{
		// ask user for choice and store value
		std::cout << "Please select a creature for position " << (i + 1) << " in your lineup: ";
		std::cin >> selection;
		
		// use if else to determine which creature the user selects for lineup 
		// if user selects 1 create barbarian and add to queue
		if (selection == 1)
		{
			Creature *fighter = new Barbarian();
			lineup.push(fighter);
		}
		// else if user selects 2 create reptile people and add to queue
		else if (selection == 2)
		{}
		// else if user selects 3 create blue men and add to queue
		else if (selection == 3)
		{}
		// else if user selects 4 create the shadow and add to queue
		else if (selection == 4)
		{}
		// else if user selects 5 create the goblin and add to queue
		else if (selection == 5)
		{}
	}
}

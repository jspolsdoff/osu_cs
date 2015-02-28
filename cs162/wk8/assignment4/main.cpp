/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/22/15
*Last Modification Date: 2/22/15
*Filename:               main.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>

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

int main()
{
	Barbarian conan;
	
	std::cout << "A barbarian named Conan was created." << std::endl;
	
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
 Barbarian:Barbarian()
 {
	str_points = 12;
	armor = 0;
	atk_die_num = 2;
	atk_die_side = 6;
	def_die_num = 2;
	def_die_side = 6;
 }

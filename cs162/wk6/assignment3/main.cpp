/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/14/15
*Last Modification Date: 2/14/15
*Filename:               main.cpp
*
*Overview
*This program will act as a fantasy combat game. It will use inheritance and polymorphism in the
*different creature classes.
***************************************************************************************************/
#include <iostream>
#include <stdlib.h>

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
	Creature(int a, int b, int c, int d, int e, int f);
	int attack();
	int defense(int);
};

class Barbarian:public Creature
{
	private:
	
	public:
	Barbarian(12, 0, 2, 6, 2, 6) : Creature(a, b, c, d, e, f);
};

int main()
{
	Barbarian sam;
	int atk_result;
	
	atk_result = sam.attack();
	
	std::cout << "This is Sam's attack: " << atk_result << std::endl;

	return 0;
}

// base class functions for all creatures
/**************************************************************************************************
*						Creature
*
**************************************************************************************************/
Creature::Creature(int a, int b, int c, int d, int e, int f)
{
	str_points = a;
	armor = b;
	atk_die_num = c;
	atk_die_side = d;
	def_die_num = e;
	def_die_side = f;
} 

/**************************************************************************************************
*						attack
*
**************************************************************************************************/
int Creature::attack()
{
	int atk_value = 0;
	
	srand(time(NULL));
	
	for (int i = 0; i < atk_die_num; i++)
	{
		atk_value = atk_value + ((rand() % atk_die_sie) + 1)
	}
	
	return atk_value
}

/**************************************************************************************************
*						defense
*
**************************************************************************************************/
int Creature::defense(int opp_atk)
{
	int def_value = 0;
	int result = 0;
	
	srand(time(NULL));
	
	for (int i = 0; i < def_die_num; i++)
	{
		def_value = def_value + ((rand() % def_die_sie) + 1);
	}
	
	str_points = str_points - (opp_atk - def_value - armor);
	
	result = str_points;
}
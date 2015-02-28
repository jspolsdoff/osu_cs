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
	Creature(int a, int b, int c, int d, int e, int f);
	int attack();
	int defense(int);
	int getHealth();
};

class Barbarian:public Creature
{
	private:
	
	public:
	Barbarian(int a, int b, int c, int d, int e, int f) : Creature(a, b, c, d, e, f)
	{}
};

class ReptilePeople:public Creature
{
	private:

	public:
	ReptilePeople(int a, int b, int c, int d, int e, int f) : Creature(a, b, c, d, e, f)
	{}
};

class BlueMen:public Creature
{
	private:

	public:
	BlueMen(int a, int b, int c, int d, int e, int f) : Creature(a, b, c, d, e, f)
	{}
};

class TheShadow:public Creature
{
	private:

	public:
	TheShadow(int a, int b, int c, int d, int e, int f) : Creature(a, b, c, d, e, f)
	{}
	int defense(int);		
};

class Goblin:public Creature
{
	private:
	bool achilles;

	public:
	Goblin();
	int attack();
	int defense(int); 
};

int main()
{
	int turn = 1;
	int health;	

	srand(time(NULL));

	std::cout << "\nFANTASY COMBAT TEST GAME\n" << std::endl;
	std::cout << "\nList of Creatures\n" << std::endl;
	std::cout << "1) Goblin" << std::endl;
	std::cout << "2) Barbarian" << std::endl;
	std::cout << "3) Reptile People" << std::endl;
	std::cout << "4) Blue Men" << std::endl;
	std::cout << "5) The Shadow\n" << std::endl; 

	Goblin player1();  
	
	Goblin player2();
	
	while ((player1.getHealth() > 0) && (player2.getHealth() > 0))
	{
		if (turn == 1)
		{
			health = player2.defense(player1.attack());
			turn = 2;
			
			if (health < 1)
			{
				std::cout << "Player 2 is DEAD" << std::endl;
				exit (EXIT_SUCCESS);
			}
			else
				std::cout << "Player 2 has " << health << " health points left." << std::endl;			
		}
	
		else
		{
			health = player1.defense(player2.attack());
			turn = 1;
			
			if (health < 1)
			{
				std::cout << "Player 1 is DEAD" << std::endl;
				exit (EXIT_SUCCESS);
			}
			else
				std::cout << "Player 1 has " << health << " health points left." << std::endl; 
		}
	}
	
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

// speial defense function for The Shadow
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

// special functions for goblin attack and defense
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


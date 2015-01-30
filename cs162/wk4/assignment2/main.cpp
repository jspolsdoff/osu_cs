/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           1/28/14
*Last Modification Date: 1/28/14
*Filename:               main.cpp
*
*Overview
*This program will act as a grocery list. The program will display a list of items. The user can 
*enter and edit the items. Finally the user has the ability to save the list.
***************************************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>

// define the 'item' class
class Item
{
	private:
	std::string name;		// name of item
	int unit;				// unit of measure
	int quantity_needed;	// number of 'item' to buy
	double price;			// unit price
	
	public:
	Item(std::string, int, int, double);	// default constructor
	getName();								// display name of item
	getUnit();								// display the unit of item
	getQuantity();							// display the number to buy
	getPrice();								// display the unit price
};

// define the 'list' class
class List
{
	private:
	std::vector<Item> item_list;			// vector composed of items
	std::ifstream inputList;				// input file stream
	std::ofstream outputList;				// output file stream
	
	public:
	List();									// constructor
	addItem();								// adds an item to list vector
	removeItem();							// removes an item from list vector
	displayList();							// displays the list
	readList();								// read a saved list
	saveList();								// save a list to file
};

int main()
{
	Item item;								// item name variable
	List shoppingList;						// create list object
	std::string name;						// item name
	int unit;								// unit of measure variable
	int quantity;							// quantity to buy variable
	double price;							// unit price variable
	int menu_choice;						// menu choice variable
	int item_delete;						// variable to choose what item to delete
	
	// contain menu in do/while loop
	do {
		// display menu
		std::cout << "\nWELCOME TO THE GROCERY LIST PROGRAM\n" << std::endl;
		std::cout << "Please choose from the following options" << std::endl;
		std::cout << "1) Add Item to Grocery List" << std::endl;
		std::cout << "2) Remove Item from Grocery List" << std::endl;
		std::cout << "3) Display Grocery List" << std::endl;
		std::cout << "4) Read List From File" << std::endl;
		std::cout << "5) Save List To File" << std::endl;
		std::cout << "6) Quit" << std: endl;
		
		// ask user for menu input
		std::cout << "Please enter your selection: ";
		
		// store in variable
		std::cin >> menu_choice;
		
		// validate the input for the menu choice
		while ((menu_choice < 1) || (menu_choice > 6))
		{
			std::cout << "Your input is invalid. Please enter another selection: ";
			std::cin >> menu_choice;
		}  
		
		// add item option
		if (menu_choice == 1)
		{
			std::cout << "\nPlease enter the follow information about the item\n" << std::endl;
			
			// ask and store item name
			std::cout << "Name: ";
			// use getline to store string
			
			// ask and store unit of measure
			std::cout << "Unit of Measure: ";
			std::cin >> unit;
			
			// ask and store quantity to buy
			std::cout << "Quantity: ";
			std::cin >> quantity;
			
			// ask and store price
			std::cout << "Price: ";
			std::cin >> price;
			
			// pass variables to function and add item to list
			Item item(name, unit, quantity, price);
		}
		
		// remove item
		else if (menu_choice == 2)
		{
			// ask user for what item they want remove
			// pass variable to function
		}
		
		// display list
		else if (menu_choice == 3)
		{
			// call function to display list
		}
		
		// read saved list
		else if (menu_choice == 4)
		{
		
		}
		
		// save list
		else if (menu_choice == 5)
		{
		
		}
		// quit program
		else
			exit(EXIT_SUCCESS);
			
	} while(menu_choice != 6);	
		
	return 0;
}

// below are the 'item' member functions
/**************************************************************************************************
*						Item
*Default constructor for the Item object.
***************************************************************************************************/ 
Item::Item()
{

}

// below are the 'list' member functions
/**************************************************************************************************
*						List
*Default constructor for the List object.
***************************************************************************************************/ 
List::List()
{

}
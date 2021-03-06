/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           1/28/15
*Last Modification Date: 1/30/15
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
#include <iomanip>

// define the 'item' class
class Item
{
	private:
	std::string name;		// name of item
	std::string unit;		// unit of measure
	int quantity_needed;	// number of 'item' to buy
	double price;			// unit price
	
	public:
	Item();
	Item(std::string, std::string, int, double);	// default constructor
	std::string getName();					// display name of item
	std::string getUnit();					// display the unit of item
	int getQuantity();						// display the number to buy
	double getPrice();						// display the unit price
};

// define the 'list' class
class List
{
	private:
	std::vector<Item> item_list;			// vector composed of items
	Item input_item;
	std::ifstream inputList;				// input file stream
	std::ofstream outputList;				// output file stream
	
	public:
	void addItem(Item);						// adds an item to list vector
	void removeItem(int);					// removes an item from list vector
	void displayList();						// displays the list
	void readList();						// read a saved list
	void saveList();						// save a list to file
};

int main()
{
	Item new_item;							// item name variable
	List shoppingList;						// create list object
	std::string name;						// item name
	std::string unit;						// unit of measure variable
	int quantity;							// quantity to buy variable
	double price;							// unit price variable
	int menu_choice;						// menu choice variable
	int remove_item;						// variable to choose what item to delete
	
	// contain menu in do/while loop
	do {
		// display menu
		std::cout << "\nWELCOME TO THE GROCERY LIST PROGRAM\n" << std::endl;
		std::cout << "Please choose from the following options" << std::endl;
		std::cout << "1) ADD ITEM TO GROCERY LIST" << std::endl;
		std::cout << "2) REMOVE ITEM FROM GROCERY LIST" << std::endl;
		std::cout << "3) DISPLAY GROCERY LIST" << std::endl;
		std::cout << "4) READ LIST FROM FILE" << std::endl;
		std::cout << "5) SAVE LIST TO FILE" << std::endl;
		std::cout << "6) QUIT" << std::endl;
		
		// ask user for menu input
		std::cout << "\nPlease enter your selection: ";
		
		// store in variable
		std::cin >> menu_choice;
		
		// validate the input for the menu choice
		while ((menu_choice < 1) || (menu_choice > 6))
		{
			std::cout << "Your input is invalid. Please enter another selection: ";
			std::cin >> menu_choice;
		}  
		
		switch (menu_choice)
		{
			// add item option
			case 1:
			{
				std::cout << "\nPlease enter the follow information about the item\n" << std::endl;
			
				// clear the input buffer
				std::cin.clear();
				std::cin.ignore(); 
				 
				// ask and store item name
				std::cout << "Name: ";
				std::getline(std::cin, name);			

				// ask and store unit of measure
				std::cout << "Unit of Measure: ";
				std::getline(std::cin, unit);
			
				// ask and store quantity to buy
				std::cout << "Quantity: ";
				std::cin >> quantity;
			
				// ask and store price
				std::cout << "Price: ";
				std::cin >> price;
			
				// pass variables to function and add item to list
				Item new_item(name, unit, quantity, price);
			
				// pass new_item object to grocery list object
				shoppingList.addItem(new_item);
			
				// display confirmation message
				std::cout << "Your item has been successfully added to the list!" << std::endl;
		
				break;	
			}
		
			// remove item
			case 2:
			{
				// ask user for what item they want remove
				std::cout << "What item number would you like to remove from your list: ";
				std::cin >> remove_item;
				remove_item--;
				
				// pass variable to function
				shoppingList.removeItem(remove_item);
				
				// display confirmation message
				std::cout << "Your item has been successfully removed from the list!" << std::endl; 

				break;	
			}
		
			// display list
			case 3:
			{
				// call function to display list
				shoppingList.displayList();
				break;	
			}
		
			// read saved list
			case 4:
			{
				// use input list stream from grocery list object 
				shoppingList.readList();

				// display confirmation message
				std::cout << "Your list has been successfully read from shoppinglist.txt!" << std::endl; 	
				break;	
			}
		
			// save list
			case 5:
			{
				// use output list stream from grocery list object
				shoppingList.saveList();

				// display confirmation message
				std::cout << "Your list has been successfully saved to shoppinglist.txt!" << std::endl; 
				break;	
			}
			// quit program
			case 6:
			{
				exit(EXIT_SUCCESS);
			}
		}		
	} while(menu_choice != 6);	
		
	return 0;
}

// below are the 'item' member functions
/**************************************************************************************************
 *						Item
 *Default constructor for the Item class.
 **************************************************************************************************/
Item::Item()
{
	name = " ";
	unit = " ";
	quantity_needed = 0;
	price = 0;
} 

/**************************************************************************************************
*						Item
*Default constructor for the Item class.
***************************************************************************************************/ 
Item::Item(std::string a, std::string b, int c, double d)
{
	name = a;
	unit = b;
	quantity_needed = c;
	price = d; 
}

/**************************************************************************************************
 *						getName
 *
 **************************************************************************************************/
 std::string Item::getName()
 {
	return name;
 }
 
 /**************************************************************************************************
 *						getUnit
 *
 **************************************************************************************************/
 std::string Item::getUnit()
 {
	return unit;
 }
 
 /**************************************************************************************************
 *						getQuantity
 *
 **************************************************************************************************/
 int Item::getQuantity()
 {
	return quantity_needed;
 }
 
 /**************************************************************************************************
 *						getPrice
 *
 **************************************************************************************************/
double Item::getPrice()
{
	return price;
}

// below are the 'list' member functions
/**************************************************************************************************
*						List
*Default constructor for the List object.
***************************************************************************************************/ 
// List::List()
// {
//
// }

/**************************************************************************************************
*						addItem
*
**************************************************************************************************/
void List::addItem(Item new_item)
{
	item_list.push_back(new_item);
} 
/**************************************************************************************************
*						removeItem
*
**************************************************************************************************/
void List::removeItem(int remove_item)
{
	item_list.erase(item_list.begin()+remove_item);
}
 
/**************************************************************************************************
*						displayList
*
**************************************************************************************************/
void List::displayList()
{
	int length = item_list.size();	// variable for the end of the loop
	int item_count = 0;				// variable to count how many items are in the shopping list


	std::cout << "\nThis is what is contain in your grocery list.\n" << std::endl;
	
	// loop through the vector displaying all the information from the class
	for (int i = 0; i < length; i++)
	{
		// display basic information about the car
		std::cout << "Name: " << item_list[i].getName() << std::endl;
		std::cout << "Unit: " << item_list[i].getUnit() << std::endl;
		std::cout << "Quantity: " << item_list[i].getQuantity() << std::endl;
		std::cout << "Price: $" << std::fixed << std::setprecision(2) << item_list[i].getPrice() << std::endl;
		
		item_count++;	// increase the number of items in your grocery list
			
		std::cout << std::endl;	
	}

	std::cout << "The total number of items in your grocery list: " << item_count << std::endl; 
}
	
/**************************************************************************************************
*						saveList
*
**************************************************************************************************/
void List::saveList()
{
	int length = item_list.size();

	// open the output file
	outputList.open("shoppinglist.txt");
	
	// use a loop to go through vector shopping list and copy items to file
	for (int i = 0; i < length; i++)
	{
		outputList << item_list[i].getName() << "\n";
		outputList << item_list[i].getUnit() << "\n";
		outputList << item_list[i].getQuantity() << "\n";
		outputList << std::fixed << std::setprecision(2) << item_list[i].getPrice() << "\n";
	}
	
	// close the file
	outputList.close(); 
}

/**************************************************************************************************
 *						readList
 *
 **************************************************************************************************/
void List::readList()
{
	std::string name;
	std::string unit;
	int quantity;
	double price;

	// open the input file
	inputList.open("shoppinglist.txt");
 
	// check for file open errors
	if (inputList)
 	{
		// use a while loop to extract data and place into item vector
		while(!inputList.fail())
		{
			// pull all item information from file and store in variables
			inputList >> name;
			inputList >> unit;
			inputList >> quantity;
			inputList >> price;
					
			// create item object and construct using variables from file	
			Item input_item(name, unit, quantity, price);

			// pass new item object to list vector for storage
			item_list.push_back(input_item);
		}

		// not sure why when I run loop it adds an extra copy of last shopping list
		// item. I am using the vector pop_back function as a fix
		item_list.pop_back(); 
		
		// close the file
		inputList.close(); 		
	}
	
	else
	{
		std::cout << "Error opening the shopping list!\n" << std::endl;
	}
} 

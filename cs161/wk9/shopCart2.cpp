/****************************************************************************
*Author:                     James Spolsdoff
*Dated Created:              11/26/14     
*Last Modified Date:         11/26/14      
*Filename:                   shopCart2.cpp  
*
*Overview:
*This program will use a class to act as a shopping cart. It will allow
*the user to enter information about an items price and quantity. The 
*program will also display the total cost of all items.
*
*Input:
*The user will input information regarding the item such as price and
*quantity.
*
*Output:
*The program menu will have the option to list the contents of the menu
*as well as display the total cost of all the items in the cart.
*
****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// define struct called item that will contain name, price, and quantity
class Item
{
	private:
	string name;
	double price;
	int quantity;
	
	public:
	Item();						// default constructor
	void setItem();					// builds the object with user input
	string getName();				// function for getter to display the name in the object
	double getPrice();				// function for getter to display the price in the object
	int getQuantity();				// funtion for the getter to display the quantity in the object

};

class ShoppingCart
{
	private:
	vector<Item> contents;

	public: 
	void addItem(Item);				// function for adding an 'Item' to the ShoppingCart object
	void listContents();
	void totalPrice();				// function that calculates the total price in the ShoppinCart object
};
  
// function prototype for 'add item'
// void BuildItem(Item&);
 
int main()
{
	// declare struct
	Item item;					// declare item object
	ShoppingCart shoppingCart;			// declare shopping cart object
	int menu_choice = 0;				// variable for menu choice	

	cout << "WELCOME TO THE SHOPPING CART\n" << endl;

	// display the program menu	
	cout << "Please select from one of the options below.\n" << endl;
	cout << "1) ADD ITEM" << endl;
	cout << "2) LIST CONTENTS" << endl;
	cout << "3) TOTAL PRICE" << endl;
	cout << "4) QUIT\n" << endl; 
	
	// wrap in do while loop
	do { 
		// ask for and store the users menu choice
		cout << "Please enter your selection: ";
		cin >> menu_choice;
  		
		// validate the input for the menu choice
		while ((menu_choice < 1) || (menu_choice > 4))
		{
			cout << "Your input is invalid. Please enter another selection: ";
			cin >> menu_choice;
		}  
		// use if or switch statement to call function based on user menu input
		switch (menu_choice)
		{		
			// call 'add item' function if user selects 1
			case 1: cout << "This is option 1" << endl;
				item.setItem();
				shoppingCart.addItem(item);			
				break;		
			// call 'list contents' function if user selects 2
			case 2: cout << "This is option 2" << endl;	
				shoppingCart.listContents();
				break;
			// call 'total price' function if user selects 3
			case 3: cout << "This is option 3" << endl;
				shoppingCart.totalPrice();
				break;
			// quit program if user selects 4
			case 4: cout << "This is option 4" << endl;
				exit(EXIT_SUCCESS);
				break;
		}
		
	} while(menu_choice != 4);	

	return 0;
}

// Item class member function implementation section

/***************************************************************************************************
 *					Item
 *This is the default constructor for the Item class.				
 ***************************************************************************************************/
 Item::Item()
 {
	name = " ";
	price = quantity = 0;
 }

 /***************************************************************************************************
 *					setItem
 *This fuction will ask the user to will out the 'item' struct and add it to the shoppingCart array	
 *				
 ***************************************************************************************************/
void Item::setItem()
{

	cout << "\n" << endl;	
  	
	// ask the user to enter the item name
	cout << "Please enter the name of the item: ";
	cin.ignore();
	getline(cin, name); 
	
	// ask the user to enter the item price
	cout << "Please enter the item price: ";
	cin >> price;
	
	// ask the user to enter the quantity of the item
	cout << "Please enter the item quantity: ";
	cin >> quantity; 
 
	// validate the quantity input is valid
	while(quantity < 1) 
	{
		// ask the user to enter the quantity of the item 
		cout << "Your input is invalid. Please enter a positive item quantity: ";
		cin >> quantity;
	} 	
	
	cout << "\n" << endl;		

}

/**************************************************************************************************
 *					getName
 *This is a getter emember function for the Item class to display the price variable
 **************************************************************************************************/
string Item::getName()
{
	return name;
} 

/**************************************************************************************************
 * 					getPrice
 *This is a getter member function for the Item class to display the price variable
 **************************************************************************************************/
double Item::getPrice()
{
	return price;
} 					

/**************************************************************************************************
 *					getQuantity
 *This is a getter member function for the Item class to display the quantity variable 
 **************************************************************************************************/ 
int Item::getQuantity()
{
	return quantity;
}
 
// ShoppingCart class member function implementation section
  
/**************************************************************************************************
 *					addItem
 *This function will add an item to the ShoppingCart object. 
 **************************************************************************************************/
 void ShoppingCart::addItem(Item item)
 {
	contents.push_back(item);
 }
 
/**************************************************************************************************
 *					listContents
 *This function will list the contents of the Item shoppingCart class.
 **************************************************************************************************/
void ShoppingCart::listContents()
{
	int length = contents.size();
	
	cout << "This is what is in the shopping cart.\n" << endl;
	
	// loop through the vector displaying all the information from the object
	for (int i = 0; i < length; i++)
	{
		// display information about contents of cart
		cout << "Name: " << contents[i].getName() << endl; 
		cout << "Price: $" << fixed << setprecision(2) << contents[i].getPrice() << endl;
		cout << "Quantity: " << contents[i].getQuantity() << endl;
	
		cout << endl;
	}
}

/**************************************************************************************************
 *					totalPrice
 *This function will calculate the total price of all the content of the shopping cart. 
 *
 **************************************************************************************************/
void ShoppingCart::totalPrice()
{
	double total_price = 0;				// this is a variable for the total price of contents of shopping cart
	int length = contents.size();
	
	for (int i = 0; i < length; i++)
	{
		total_price += contents[i].getPrice() * contents[i].getQuantity();
	}
	
	cout << "Total cost of items in shopping cart: $" << fixed << setprecision(2) << total_price << "\n" << endl;
}
 


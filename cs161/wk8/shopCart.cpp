/****************************************************************************
*Author:                          James Spolsdoff
*Dated Created:               11/17/14     
*Last Modified Date:         11/17/14      
*Filename:                       shopCart.cpp  
*
*Overview:
*This program will use a struct to act as a shopping cart. It will allow
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
#include <stdlib.h>
#include <iomanip>
using namespace std;

// define struct called item that will contain name, price, and quantity
struct Item
{
	string name;
	double price;
	int quantity;
};
  
// function prototype for 'add item'
void AddItem(int &, Item []);
 
// function prototype for 'list contents'
void ListContents(int, Item []);
 
// function prototype for 'total price'
void TotalPrice(int, Item []); 

int main()
{
	// declare struct
	Item shoppingCart[100];		// declare array that will act as shopping cart to hold items
	int menu_choice = 0;		// variable for menu choice	
	int cart_item_num = 0;		// variable to keep track of the number of items in the shopping cart	

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
				AddItem(cart_item_num, shoppingCart);			
				break;		
			// call 'list contents' function if user selects 2
			case 2: cout << "This is option 2" << endl;	
				ListContents(cart_item_num, shoppingCart);
				break;
			// call 'total price' function if user selects 3
			case 3: cout << "This is option 3" << endl;
				TotalPrice(cart_item_num, shoppingCart);
				break;
			// quit program if user selects 4
			case 4: cout << "This is option 4" << endl;
				exit(EXIT_SUCCESS);
				break;
		}
		
	} while(menu_choice != 4);	

	return 0;
}

/***************************************************************************************************
 *					AddItem
 *This fuction will ask the user to will out the 'item' struct and add it to the shoppingCart array	
 *				
 ***************************************************************************************************/
void AddItem(int &cart_item_num, Item shoppingCart[])
{
	cout << "\n" << endl;	
  	
	// ask the user to enter the item name
	cout << "Please enter the name of the item: ";
	cin.ignore();
	getline(cin, shoppingCart[cart_item_num].name); 
	
	// ask the user to enter the item price
	cout << "Please enter the item price: ";
	cin >> shoppingCart[cart_item_num].price;
	
	// ask the user to enter the quantity of the item
	cout << "Please enter the item quantity: ";
	cin >> shoppingCart[cart_item_num].quantity; 
 
	// validate the quantity input is valid
	while(shoppingCart[cart_item_num].quantity < 1) 
	{
		// ask the user to enter the quantity of the item 
		cout << "Your input is invalid. Please enter a positive item quantity: ";
		cin >> shoppingCart[cart_item_num].quantity;
	} 	

	cout << "\n" << endl;		

	// increase the cart number to the next element
	cart_item_num++;
}

/**************************************************************************************************
 *					ListContents
 *This function will list the contents of the Item shoppingCart struct array.
 *
 **************************************************************************************************/
void ListContents(int cart_item_num, Item shoppingCart[])
{
	for (int i = 0; i < cart_item_num; i++)
	{
		cout << "\nName: " << shoppingCart[i].name << endl;
		cout << "Price: $" << shoppingCart[i].price << endl;
		cout << "Quantity: " << shoppingCart[i].quantity << endl;
		cout << "\n" << endl; 
	}

}

/**************************************************************************************************
 *					TotalPrice
 *This function will calculate the total price of all the content of the shopping cart. 
 *
 **************************************************************************************************/
void TotalPrice(int cart_item_num, Item shoppingCart[])
{
	double total_price = 0;	// this is a variable for the total price of contents of shopping cart

	for (int i = 0; i < cart_item_num; i++)
	{
		total_price += shoppingCart[i].price * shoppingCart[i].quantity;
	}
	
	cout << "Total cost of items in shopping cart: $" << fixed << setprecision(2) << total_price << "\n" << endl;
}
 

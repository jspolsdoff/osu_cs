/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    11/22/14
*Last Modified Date:               11/22/14
*Filename:                         carLot.cpp
*
*Overview:
*
*
*
*
*
*Input:
*
*
*
*
*Output:
*
*
*
*
*
****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// create a struct called Date
struct Date
{
	int day;
	int month;
	int year;
};

// create a struct called Car
struct Car
{
	string make;
	string model;
	int year;
	Date datePurchased;
	double purchasePrice;
	bool isSold;
	Date dateSold;
	double salePrice; 
};

// function prototypes make sure to pass by reference
void AddEntry(vector<Car> &carLot);
void ListInventory(vector<Car> &carLot); 
void CalculateProfits(vector<Car> &carLot);

int main()
{
	// declare needed variables
	vector<Car> carLot;
	int menu_choice = 0;	// variable for menu selection

	cout << "WELCOME TO THE CAR LOT\n" << endl;

	// display the program menu	
	cout << "Please select from one of the options below.\n" << endl;
	cout << "1) ADD ENTRY" << endl;
	cout << "2) LIST CURRENT INVENTORY" << endl;
	cout << "3) CALCULATE MONTHLY PROFIT" << endl;
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
			// call 'add entry' function if user selects 1
			case 1: cout << "This is option 1" << endl;
				// call function to add entry			
				AddEntry(carLot);				
				break;		
			// call 'list current inventory' function if user selects 2
			case 2: cout << "This is option 2" << endl;	
				// call function to list current inventory
				ListInventory(carLot);
				break;
			// call 'profit for a month' function if user selects 3
			case 3: cout << "This is option 3" << endl;
				// call function to calculate profit for a given month
				CalculateProfits(carLot);	
				break;
			// quit program if user selects 4
			case 4: cout << "This is option 4" << endl;
				exit(EXIT_SUCCESS);
				break;
		}
		
	} while(menu_choice != 4);		 

	return 0;
}  

/**************************************************************************************************
 *						AddEntry
 *This function will allow the user to enter the information for a car then add that information to
 *the vector
 **************************************************************************************************/ 
void AddEntry(vector<Car> &carLot)
{
	Car tempCar;
	char is_sold;

	cout << endl;
	
	// clear the input buffer
	cin.ignore(256, '\n'); 
	
	// start to fill the struct with new entry information
	cout << "Please enter the following information about the new entry." << endl;
	cout << "What is the make: ";
	getline(cin, tempCar.make);

	cout << "What is the model: ";
	getline(cin, tempCar.model);

	cout << "What is the year: ";
	cin >> tempCar.year;

	cout << "When was the car purchased?" << endl;
	
	cout << "Month: ";
	cin >> tempCar.datePurchased.month; 	 
	
	// wrap month input in do/while loop for input validation 	
	while((tempCar.datePurchased.month > 12) || (tempCar.datePurchased.month < 1))
	{
	
		cout << "The month you entered is invalid. Please enter a value from 1-12: ";
		cin >> tempCar.datePurchased.month;
	
	} 	

	cout << "Day: ";
	cin >> tempCar.datePurchased.day;

	// validate day input
	if ((tempCar.datePurchased.month == 1) || (tempCar.datePurchased.month == 3) || (tempCar.datePurchased.month == 5) || (tempCar.datePurchased.month == 7) || (tempCar.datePurchased.month == 8) || (tempCar.datePurchased.month == 10) || (tempCar.datePurchased.month == 12))
	{
		while((tempCar.datePurchased.day > 31) || (tempCar.datePurchased.day < 1))
		{
			cout << "The day you entered is invalid. Please enter a value from 1-31: ";
			cin >> tempCar.datePurchased.day;
		}
	}

	else if (tempCar.datePurchased.month == 2)
	{
		while((tempCar.datePurchased.day > 28) || (tempCar.datePurchased.day < 1))
		{
			cout << "The day you entered is invalid. Please enter a value from 1-28: ";
			cin >> tempCar.datePurchased.day;
		}
	}

	else
	{
		while((tempCar.datePurchased.day > 30) || (tempCar.datePurchased.day < 1))
		{
			cout << "The day you entered is invalid. Please enter a value from 1-30: ";
			cin >> tempCar.datePurchased.day;
		}
	}	

	cout << "Year: ";
	cin >> tempCar.datePurchased.year;

	cout << "What was the purchase price: ";
	cin >> tempCar.purchasePrice;

	cout << "Is the car sold? Please enter 'Y' or 'N': ";
	cin >> is_sold;

	if (is_sold == 'Y')
	{
		tempCar.isSold = true;
		
		cout << "When was the car sold?" << endl;

		cout << "Month: ";
		cin >> tempCar.dateSold.month;
		
		// wrap month input in do/while loop for input validation 	
		while((tempCar.dateSold.month > 12) || (tempCar.dateSold.month < 1))
		{
		
			cout << "The month you entered is invalid. Please enter a value from 1-12: ";
			cin >> tempCar.dateSold.month;
		
		} 

		cout << "Day: ";
		cin >> tempCar.dateSold.day;
		
		// validate day input
		if ((tempCar.dateSold.month == 1) || (tempCar.dateSold.month == 3) || (tempCar.dateSold.month == 5) || (tempCar.dateSold.month == 7) || (tempCar.dateSold.month == 8) || (tempCar.dateSold.month == 10) || (tempCar.dateSold.month == 12))
		{
			while((tempCar.dateSold.day > 31) || (tempCar.dateSold.day < 1))
			{
				cout << "The day you entered is invalid. Please enter a value from 1-31: ";
				cin >> tempCar.dateSold.day;
			}
		}

		else if (tempCar.dateSold.month == 2)
		{

			while((tempCar.dateSold.day > 28) || (tempCar.dateSold.day < 1))
			{
				cout << "The day you entered is invalid. Please enter a value from 1-28: ";
				cin >> tempCar.dateSold.day; 
			} 
		}

		else
		{
			while((tempCar.dateSold.day > 30) || (tempCar.dateSold.day < 1))
			{
				cout << "The day you entered is invalid. Please enter a value from 1-30: ";
				cin >> tempCar.dateSold.day;
			}
		}	

		cout << "Year: ";
		cin >> tempCar.dateSold.year;

		cout << "What was the sales price: ";
		cin >> tempCar.salePrice;

	}	  
	
	else
	{	
		tempCar.isSold = false;
	}

	carLot.push_back(tempCar);

	cout << endl;		
}

/**************************************************************************************************
 *						ListInventory
 *This function lists all the inventory items added to the vector
 *
 **************************************************************************************************/
void ListInventory(vector<Car> &carLot)
{
	int length = carLot.size();	// variable for the end of the loop

	cout << "This is what is in the car lot inventory.\n" << endl;
	
	// loop through the vector displaying all the information from the struct
	for (int i = 0; i < length; i++)
	{
		// display basic information about the car
		cout << "Make: " << carLot[i].make << endl;
		cout << "Model: " << carLot[i].model << endl;
		cout << "Year: " << carLot[i].year << endl;
		cout << "Date Purchased: " << carLot[i].datePurchased.month << "/" << carLot[i].datePurchased.day << "/" << carLot[i].datePurchased.year << endl;
		cout << "Purchase Price: $" << fixed << setprecision(2) << carLot[i].purchasePrice << endl;
		
		// set up if else statement to display if the car is sold
		if (carLot[i].isSold == true)
		{
			cout << "Date Sold: " << carLot[i].dateSold.month << "/" << carLot[i].dateSold.day << "/" << carLot[i].dateSold.year << endl;
  			cout << "Sale Price: $" << fixed << setprecision(2) << carLot[i].salePrice << endl;
		} 
		
		cout << endl;	

	}

} 

/**************************************************************************************************
 *						CalculateProfits
 *
 *
 **************************************************************************************************/
void CalculateProfits(vector<Car> &carLot)
{
	int sales_month;		// variable used to calculate the profit for given month
	int sales_year;			// variable used to calculate the profit for given year
	int length = carLot.size();	// variable used for the size of the loop
	double profit = 0;		// variable for the profit

	// ask user for input for the month and year to calculate
	cout << "Please enter the month and year you would like to calculate profits for." << endl;
	
	cout << "Month: ";
	cin >> sales_month;

	cout << "Year: ";
	cin >> sales_year;

	for (int i = 0; i < length; i++)
	{
		if ((carLot[i].isSold == true) && (carLot[i].dateSold.month == sales_month) && (carLot[i].dateSold.year == sales_year))
		{
			profit += (carLot[i].salePrice - carLot[i].purchasePrice);
		}  
	}   

	// display the profits for the given month
	cout << "The total profits for sales on " << sales_month << "/" << sales_year << " are: $" << fixed << setprecision(2) << profit << endl;

	cout << endl;
} 

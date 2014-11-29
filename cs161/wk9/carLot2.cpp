/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    11/27/14
*Last Modified Date:               11/28/14
*Filename:                         carLot2.cpp
*
*Overview:
*This is the same program as last week only using classes.
*
*Input:
*The user can input information about the cars.
*
*Output:
*This program will output information regarding the car lot.
*
****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// create a class called Date
class Date
{
	private:
	int day;
	int month;
	int year;
	
	public:
	Date();					// default constructor for Date class
	Date(int, int, int);	// constructor that takes all variables as parameters
	getMonth();				// getter function to display the month variable
	getDay();				// getter function to display the day variable
	getYear();				// getter function to display the year variable
};

// create a class called Car
class Car
{
	private:
	string make;
	string model;
	int year;
	Date datePurchased;
	double purchasePrice;
	bool isSold;
	Date dateSold;
	double salePrice;

	public:
	// constructors to build Car object that is either sold or not sold
	Car();
	Car(string, string, int, Date, double, bool, Date, double);
	Car(string, string, int, Date, double, bool);
	
	getMake();				// display the make variable
	getModel();				// display the model variable
	getYear();				// display the year variable
	get purchasePrice();	// display the purchase price variable
	get isSold()			// display if variable is true/false
	get salePrice();		// display the salePrice variable
	getProfit();
};

// create a class called CarLot
class CarLot
{
	private:
	vector<Car> inventory
	
	public:
	addCar();				// takes the Car class as a parameter and adds to the 'inventory' vector
	listCurrentInv();		// prints out a list of current Car inventory that hasn't been sold yet
	getMonthProfit();		// returns the total profit for sales in a given month and year
};

int main()
{
	CarLot carLot;			// variable for carLot object
	int menu_choice = 0;	// variable for menu selection
	
	// variable for Day arguments				
	int day,	
	month,	
	year;
	
	// variable for Car arguments
	string make,
	model;
	int year;
	double purchase_price;
	char sold;
	bool is_sold;
	double sale_price;
				   

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
			// take all of user input information and create Date and Car
			case 1: cout << "This is option 1\n" << endl;
				
				// ask for the make of car
				cout << "What is the make of the car: ";
				cin >> make;
				
				// ask for the car model
				cout << "What is the model of the car: ";
				cin >> model;
				
				// ask for model year
				cout << "What is the model year of the car: ";
				cint >> year;
				
				// ask for date purchased
				cout << "When was the car purchased?" << endl;
					// month
					cout << "Month: ";
					cin >> month;
					
					// day
					cout << "Day: ";
					cin >> day;
					
					// year
					cout << "Year: ";
					cin >> year;
					
					// create datePurchased object
					Date datePurchased(month, day, year);
					
				// ask for purchase price
				cout << "What was the purchase price of the car: ";
				cin >> purchase_price;
				
				// ask if the car is sold
				cout << "Is the car sold? Please enter 'Y' or 'N': ";
				cin >> sold;
					
				// if sold ask for date sold and sale price
				if (sold == 'Y')
				{
					is_sold = true;
					
					// ask for the date the car was sold
					cout << "What was the sale price: ";
					cin >> sale_price;
					
					cout << "When was the car sold?" << endl;
					
					cout << "Month: ";
					cin >> month;
					
					cout << "Day: ";
					cin >> day;
					
					cout << "Year: ";
					cin >> year;
					
					// create the dateSold object
					Date dateSold(month, day, year);
					
					// create Car object
					Car car(make, model, year, datePurchased, purchase_price, is_sold, dateSold, sale_price);
					
				}
				
				else
				{
					is_ sold = false;
					
					// create Car object
					Car car(make, model, year, datePurchased, purchase_price, is_sold);
					
				}
				
				// pass car object into carLot object and store in vector
				carLot.addCar(car);
				
				break;		
			
			// call 'list current inventory' function if user selects 2
			case 2: cout << "This is option 2" << endl;	
				// call function to list current inventory
				carLot.inventory.listCurrentInv();
				break;
			// call 'profit for a month' function if user selects 3
			case 3: cout << "This is option 3" << endl;
				// call function to calculate profit for a given month
					
				break;
			// quit program if user selects 4
			case 4: cout << "This is option 4" << endl;
				exit(EXIT_SUCCESS);
				break;
		}
		
	} while(menu_choice != 4);		 

	return 0;
}  

// Date class member function implementation section

/**************************************************************************************************
 *						Date
 *This is the constructor for the Date class. It builds a Date object default values.
 **************************************************************************************************/ 
Date::Date()
{
	month = day = year = 0;
}
/**************************************************************************************************
 *						Date
 *This is the constructor for the Date class. It builds a Date object with all three needed parameters
 **************************************************************************************************/ 
Date::Date(int user_input_month, int user_input_day, int user_input_year)
{
	// set the year from passed argument
	year = user_input_year;
	
	// set the month from passed argument
	month = user_input_month;
	
	// wrap month input in do/while loop for input validation 	
	while((month > 12) || (month < 1))
	{
	
		cout << "The month you entered is invalid. Please enter a value from 1-12: ";
		cin >> month;
	
	} 	
	
	// set the day from passed argument
	day = user_input_day;
	
	// validate day input
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
	{
		while((day > 31) || (day < 1))
		{
			cout << "The day you entered is invalid. Please enter a value from 1-31: ";
			cin >> day;
		}
	}

	else if (month == 2)
	{
		while((day > 28) || (day < 1))
		{
			cout << "The day you entered is invalid. Please enter a value from 1-28: ";
			cin >> day;
		}
	}

	else
	{
		while((day > 30) || (day < 1))
		{
			cout << "The day you entered is invalid. Please enter a value from 1-30: ";
			cin >> day;
		}
	}	
}

 /**************************************************************************************************
 *						getMonth
 *This is a getter member function for the Date class to display the month variable
 **************************************************************************************************/
int Date::getMonth()
{
	return month;
}

 /**************************************************************************************************
 *						getMonth
 *This is a getter member function for the Date class to display the month variable
 **************************************************************************************************/
int Date::getDay()
{
	return day;
}

 /**************************************************************************************************
 *						getYear
 *This is a getter member function for the Date class to display the year variable
 **************************************************************************************************/
int Date::getYear()
{
	return year;
}

// Car class member function implementation section

 /**************************************************************************************************
 *						Car
 *This is the constructor for the Car class. It builds a Car object default values.
 **************************************************************************************************/
  Car::Car(string user_input_make, string user_input_model, int user_input_year, Date ui_datePurchased, double ui_purchasePrice, bool user_input_isSold, Date user_input_dateSold, double user_input_salePrice)
 {
	make = user_input_make;
	model = user_input_model;
	year = user_input_year;
	datePurchased = ui_datePurchased;
	purchasePrice = ui_purchasePrice;
	isSold = user_input_isSold;
	dateSold = user_input_dateSold;
	salePrice = user_input_salePrice;
	
 }
 
 /**************************************************************************************************
 *						Car
 *This is the constructor for the Car class. It builds a Car object default values.
 **************************************************************************************************/
 Car::Car(string user_input_make, string user_input_model, int user_input_year, Date ui_datePurchased, double user_input_purchasePrice, bool user_input_isSold)
 {
	make = user_input_make;
	model = user_input_model;
	year = user_input_year;
	datePurchased = ui_datePurchased;
	purchasePrice = ui_purchasePrice;
	isSold = user_input_isSold;
 }
 
 /**************************************************************************************************
 *						getMake
 *This is a getter member function for the Car class to display the make variable
 **************************************************************************************************/
string Car::getName()
{
	return make;
}

/**************************************************************************************************
 *						getModel
 *This is a getter emember function for the Car class to display the model variable
 **************************************************************************************************/
string Car::getModel()
{
	return model;
}

/**************************************************************************************************
 *						getYear
 *This is a getter emember function for the Car class to display the year variable
 **************************************************************************************************/
int Car::getYear()
{
	return year;
}   
 
 /**************************************************************************************************
 *						getPurchasePrice
 *This is a getter emember function for the Car class to display the purchase price variable
 **************************************************************************************************/
int Car::getPurchasePrice()
{
	return purchasePrice;
}   
 
// CarLot class member function implementation section

/**************************************************************************************************
 *						addCar
 *This function will add an item to the ShoppingCart object. 
 **************************************************************************************************/
 void CarLot::addCar(Car car)
 {
	inventory.push_back(car);
 }

/**************************************************************************************************
 *						listInventory
 *This function lists all the inventory items added to the vector in the CarLot class.
 **************************************************************************************************/
void CarLot::listInventory()
{
	int length = inventory.size();	// variable for the end of the loop

	cout << "This is what is in the car lot inventory.\n" << endl;
	
	// loop through the vector displaying all the information from the class
	for (int i = 0; i < length; i++)
	{
		// display basic information about the car
		cout << "Make: " << inventory[i].car.getMaker() << endl;
		cout << "Model: " << inventory[i].car.getModel() << endl;
		cout << "Year: " << inventory[i].car.getYear() << endl;
		cout << "Date Purchased: " << inventory[i].datePurchased.getMonth() << "/" << inventory[i].datePurchased.getDay() << "/" << inventory[i].datePurchased.getYear() << endl;
		cout << "Purchase Price: $" << fixed << setprecision(2) << inventory[i].getPurchasePrice() << endl;
		
		// set up if else statement to display if the car is sold
		/*
		if (inventory[i].isSold == true)
		{
			cout << "Date Sold: " << carLot[i].dateSold.month << "/" << carLot[i].dateSold.day << "/" << carLot[i].dateSold.year << endl;
  			cout << "Sale Price: $" << fixed << setprecision(2) << carLot[i].salePrice << endl;
		} 
		
		cout << endl;	
		*/
	}

} 

/**************************************************************************************************
 *						CalculateProfits
 *
 *
 **************************************************************************************************/
/*
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
*/
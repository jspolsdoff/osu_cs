/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    11/27/14
*Last Modified Date:               11/29/14
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
#include <math.h>
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
	Date(int, int, int);			// constructor that takes all variables as parameters
	int getMonth();				// getter function to display the month variable
	int getDay();				// getter function to display the day variable
	int getYear();				// getter function to display the year variable
};

// create a class called Car
class Car
{
	private:
	string make;
	string model;
	int year;
	// Date datePurchased;
	double purchasePrice;
	bool isSold;
	// Date dateSold;
	double salePrice;

	public:
	// constructors to build Car object that is either sold or not sold
	Car();
	Car(string, string, int, Date, double, bool, Date, double);
	Car(string, string, int, Date, double, bool);

	Date datePurchased;
	Date dateSold;
	
	string getMake();		// display the make variable
	string getModel();		// display the model variable
	int getYear();			// display the year variable
	double getPurchasePrice();	// display the purchase price variable
	bool getIsSold();		// display if variable is true/false
	double getSalePrice();		// display the salePrice variable
	double getProfit();		// displays the profit if the car has been sold
};

// create a class called CarLot
class CarLot
{
	private:
	vector<Car> inventory;
	
	public:
	void addCar(Car);			// takes the Car class as a parameter and adds to the 'inventory' vector
	void listCurrentInv();			// prints out a list of current Car inventory that hasn't been sold yet
	double getMonthProfit(int, int);	// returns the total profit for sales in a given month and year
};

int main()
{
	CarLot carLot;			// variable for carLot object
	Car newCar;
	Date dateSold;
	Date datePurchased;
	int menu_choice = 0;	// variable for menu selection
	
	// variable for Day arguments				
	int purchase_day = 0,	
	purchase_month = 0,	
	purchase_year = 0;

	int sold_day = 0,
	sold_month = 0,
	sold_year = 0;
	
	// variable for Car arguments
	string make,
	model;
	int model_year;
	double purchase_price;
	char sold;
	bool is_sold;
	double sale_price;

	// variables to pass for profit calculation
	int profit_month,
	profit_year; 
				   

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
			case 1: 
			{
				cout << "This is option 1\n" << endl;
				
				// ask for the make of car
				cout << "What is the make of the car: ";
				cin >> make;
				
				// ask for the car model
				cout << "What is the model of the car: ";
				cin >> model;
				
				// ask for model year
				cout << "What is the model year of the car: ";
				cin >> model_year;
				
				// ask for date purchased
				cout << "When was the car purchased?" << endl;
					// month
					cout << "Month: ";
					cin >> purchase_month;
					
					// day
					cout << "Day: ";
					cin >> purchase_day;
					
					// year
					cout << "Year: ";
					cin >> purchase_year;
					
					// create datePurchased object
					Date datePurchased(purchase_month, purchase_day, purchase_year);
					
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
					cin >> sold_month;
					
					cout << "Day: ";
					cin >> sold_day;
					
					cout << "Year: ";
					cin >> sold_year;
					
					// create the dateSold object
					Date dateSold(sold_month, sold_day, sold_year);
					
					// create Car object
					Car newCar(make, model, model_year, datePurchased, purchase_price, is_sold, dateSold, sale_price);
					
					// pass car object into carLot object and store in vector
					carLot.addCar(newCar);
				}
				
				else
				{
					is_sold = false;
					
					// create Car object
					Car newCar(make, model, model_year, datePurchased, purchase_price, is_sold);
					
					carLot.addCar(newCar);

				}
												
				break;		
			}
			// call 'list current inventory' function if user selects 2
			case 2: 
			{	
				cout << "This is option 2" << endl;	
				// call function to list current inventory
				carLot.listCurrentInv();
				break;
			}
			// call 'profit for a month' function if user selects 3
			case 3: 
			{	
				cout << "This is option 3" << endl;
				//  calculate profit for a given month and year
				cout << "What date do you want to calculate profits for?" << endl;
				cout << "Month: ";
				cin >> profit_month;

				cout << "Year: ";
				cin >> profit_year;  

				cout << endl;
	
				cout << "The profit for " << profit_month << "/" << profit_year << " is: $ " << fixed << setprecision(2) << carLot.getMonthProfit(profit_month, profit_year) << endl;

				break;
			}
			// quit program if user selects 4
			case 4: 
			{
				cout << "This is option 4" << endl;
				exit(EXIT_SUCCESS);
				break;
			}
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
 *This is the deffault constructor for the Car class.
 **************************************************************************************************/ 
Car::Car()
{
	make = " ";
	model = " ";
	year = 0;
	Date datePurchased;
	purchasePrice = 0;
	isSold = false;
}

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
Car::Car(string user_input_make, string user_input_model, int user_input_year, Date ui_datePurchased, double ui_purchasePrice, bool user_input_isSold)
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
string Car::getMake()
{
	return make;
}

/**************************************************************************************************
 *						getModel
 *This is a getter member function for the Car class to display the model variable
 **************************************************************************************************/
string Car::getModel()
{
	return model;
}

/**************************************************************************************************
 *						getYear
 *This is a getter member function for the Car class to display the year variable
 **************************************************************************************************/
int Car::getYear()
{
	return year;
}   
 
 /**************************************************************************************************
 *						getPurchasePrice
 *This is a getter member function for the Car class to display the purchase price variable
 **************************************************************************************************/
double Car::getPurchasePrice()
{
	return purchasePrice;
}   
 
/**************************************************************************************************
 *						getIsSold
 *This is a getter member function that returns a bool value. 
 **************************************************************************************************/ 
bool Car::getIsSold()
{
	return isSold;
}

/**************************************************************************************************
 *						getProfit
 *This is a getter member function that return a double for the profit of a sold car.
 **************************************************************************************************/ 
double Car::getProfit()
{
	if (isSold == true)
	{
		return (salePrice - purchasePrice); 
	}
	else
		return NAN;
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
 *						listCurrentInv
 *This function lists all the inventory items added to the vector in the CarLot class.
 **************************************************************************************************/
void CarLot::listCurrentInv()
{
	int length = inventory.size();	// variable for the end of the loop
	int car_count = 0;		// variable to count how many car are in the inventory


	cout << "This is what is in the car lot inventory.\n" << endl;
	
	// loop through the vector displaying all the information from the class
	for (int i = 0; i < length; i++)
	{
		if (inventory[i].getIsSold() == false)		
		{
		// display basic information about the car
		cout << "Make: " << inventory[i].getMake() << endl;
		cout << "Model: " << inventory[i].getModel() << endl;
		cout << "Year: " << inventory[i].getYear() << endl;
		cout << "Date Purchased: " << inventory[i].datePurchased.getMonth() << "/" << inventory[i].datePurchased.getDay() << "/" << inventory[i].datePurchased.getYear() << endl;
		cout << "Purchase Price: $" << fixed << setprecision(2) << inventory[i].getPurchasePrice() << endl;
		
		car_count++;	// increase the number of cars in the inventory
			
		cout << endl;	
		}
	}

	cout << "The total number of cars in inventory are: " << car_count << endl; 

} 

/**************************************************************************************************
 *						getMonthProfit
 *
  **************************************************************************************************/
double CarLot::getMonthProfit(int month, int year)
{
	int length = inventory.size();	// variable used for the size of the loop
	double profit = 0;		// variable for the profit

	for (int i = 0; i < length; i++)
	{
		if ((inventory[i].getIsSold() == true) && (inventory[i].dateSold.getMonth() == month) && (inventory[i].dateSold.getYear() == year))
		{
			profit += inventory[i].getProfit();
		}  
	}   
	
	return profit;
}


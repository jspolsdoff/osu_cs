/**************************************************************************************************
*Author:					James Spolsdoff
*Date Created:				12/2/14
*Last Modified Date:		12/2/14
*Filename:					menu.cpp
*
*Overview:
*
*Input:
*
*Output:
*
***************************************************************************************************/

#include <iostream>
#include <string>
#include "Book.h"
#include "Patron.h"
#include "Library.h"
using namespace std;

int main()
{
	int menu_choice = 0;	// variable to store menu choice
	Library library;	// create library object	
	string bookID,
	patronID;

	cout << "\nWELCOME TO THE LIBRARY\n" << endl;
	
	cout << "Please select one of the options below\n" << endl;

	// display menu
	cout << "1) Add Book" << endl;
	cout << "2) Add Member" << endl;
	cout << "3) Check Out Book" << endl;
	cout << "4) Return Book" << endl;
	cout << "5) Request Book" << endl;
	cout << "6) Pay Fine" << endl;
	cout << "7) Increament Current Date" << endl;
	cout << "8) View Patron Information" << endl;
	cout << "9) View Book Information" << endl;
	cout << "10) Quit\n" << endl;

	// wrap in do while loop
	do {
		// ask for the menu selection
		cout << "Please enter your selection: ";
		cin >> menu_choice;
	
		// validate menu input
		while ((menu_choice < 1) || (menu_choice > 10))
		{
			cout << "Your input is invalid. Please enter another selection: ";
			cin >> menu_choice;
		}

		// use switch statement to call function based on user input
		switch (menu_choice)
 	    	{ 
			// add book
			case 1: 
			{
				cout << "This is option 1" << endl;
					
				// create book object and add to library
				library.addBook();

				break;
			}
			// add member
	  		case 2: 
			{
				cout << "This is option 2" << endl;
				
				// create patron object and add to library
				library.addMember();
				
				break;
			}
			// check out book
			case 3: 
			{
				cout << "This is option 3" << endl;	

				// clear the input buffer before storing strings
				cin.ignore(256,'\n');
				
				cout << "Please enter the following information to check out a book." << endl;
				cout << "Patron ID: ";
				getline(cin, patronID);
				
				cout << "Book ID: ";
				getline(cin, bookID);
				
				// pass arguments to Library function and check out book
				library.checkOutBook(patronID, bookID);
				
				break;
			}
			// return book
			case 4: 
			{
				cout << "This is option 4" << endl;
				
				// clear the input buffer before storing strings
				cin.ignore(256,'\n');
				
				cout << "Please enter the following information to return a book." << endl;
				
				cout << "Book ID: ";
				getline(cin, bookID);
				
				// pass variables to the Library member function
				library.returnBook(bookID);
				
				break;
			}
			// request book
			case 5: 
			{
				cout << "This is option 5" << endl;
				
				// clear the input buffer before storing strings
				cin.ignore(256,'\n');
				
				cout << "Please enter the following information to request a book." << endl;
				cout << "Patron ID: ";
				getline(cin, patronID);
				
				cout << "Book ID: ";
				getline(cin, bookID);
				
				// pass arguments to Library function and request book
				library.requestBook(patronID, bookID);
				
				break;
			}
			// pay fine
			case 6: 
			{
				cout << "This is option 6" << endl;
				break;
			}
			// increment current date
			case 7: 
			{
				cout << "This is option 7" << endl;
				break;
			}
			// view Patron info
			case 8: 
			{
				cout << "This is option 8" << endl;
				
				// clear the input buffer before storing strings
				cin.ignore(256,'\n');
				
				cout << "Please enter the following information to request patron information." << endl;
				cout << "Patron ID: ";
				getline(cin, patronID);
				
				// pass arguments to function and get requested patron information
				library.viewPatronInfo(patronID);
				
				break;
			}
			// view book info
			case 9: 
			{
				cout << "This is option 9" << endl;

				cout << "Please enter the Book ID to display book information: ";
				cin.ignore();
				getline(cin, bookID);

				library.viewBookInfo(bookID);
				
				break;	
			}
			// quit 
 			case 10: 
			{
				cout << "This is option 10" << endl;
				exit(EXIT_SUCCESS);
			}	
		
		}	

	} while(menu_choice != 10);

	return 0;
}

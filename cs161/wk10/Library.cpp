// Library.cpp is the Library class function implementation file.
#include "Library.h"
#include "Book.h"
#include "Patron.h"

/**************************************************************************************************
 *								Library															
 *This is the default constructor for the Library class.
 ***************************************************************************************************/
 Library::Library()
 {
	currentDate = 0;
 }
 /**************************************************************************************************
 *								addBook															
 *This is a member function that prompts the user for book info and uses it to create a Book, which
 *is added to holdings vector.
 ***************************************************************************************************/
 void Library::addBook()
 {
	std::string idc;
    std::string t;
    std::string a;
	
	// clear the input buffer before storing strings
	std::cin.ignore(10000,'\n');
	
	std::cout << "Enter the following information to create a new book in the library's system" << endl;
	
	std::cout << "Please enter the book's ID Code: ";
	
	std::getline(std::cin, idc);
	
	// ask for the title of the book
	std::cout << "Please enter the book's title: ";
	std::getline(std::cin, t);
	
	// ask for the author of the book
	std::cout << "Please enter the book's author: ";
	std::getline(std::cin, a);
	
	// pass variables to Book constructor and create object
	Book newbook(idc, t, a);
	
	// add newly created Book object to holdings vector
	holdings.push_back(newbook);
 }
 /**************************************************************************************************
 *								addMember															
 *This is a member function the prompts the user for patron info and uses it to create a Patron, which
 *is added to members vector.
 ***************************************************************************************************/
 void Library::addMember()
 {
	std::string idn; 
	std::string n;
	
	// clear the input buffer before storing strings
	std::cin.ignore(10000,'\n');
	
	std::cout << "Enter the following information to create a new member in the library's system" << endl;
	
	// ask user for ID number
	std::cout << "Please enter an ID Number: ";
	std::getline(std::cin, idn);
	
	// ask user for name
	std::cout << "Please enter the account name: ";
	std::getline(std::cin, n);
	
	// pass arguments to Patron constructor and create new object
	Patron newpatron(idn, n);
	
	// add newly created Patron object to members vector
	members.push_back(newpatron);
 }
 /**************************************************************************************************
 *								checkOutBook															
 *This member function will check out a Book to a Patron. It will preform various validations as well.
 ***************************************************************************************************/
 void Library::checkOutBook(std::string patronID, std::string bookID)
 {
	int members_length = members.length(),
	holdings_length = holdings.length(),
	book_position = 0,
	members_check = 0,
	holdings_check = 0;
	
	// check to see if passed patronID does not exist
	for (int i = 0; i < members_length; i++)
	{
		// loop through vector and check if the patronID exists
		if (members[i].getIdNum() == patronID)
			members_check++;
	}
	
	if (members_check == 0)
	{
		// if patronID does not exist print out message and return to menu
		std::cout << "The patronID does not exist." << endl;
		return;
	}
	
	// check to see if passed bookID do not exist
	for (int i = 0; i < holdings_length; i++)
	{
		// loop through vector and check if the bookID exists
		if (holdings[i].getIdCode() == bookID)
		{
			holdings_check++;
			book_position = i;
		}
	}
	
	if (holdings_check == 0)
	{
		// if bookId does not exist print out message and return to menu
		std::cout << "The bookID does not exist." << endl;
		return;
	}
	
	// check to see if Book is already checked out (getLocation)
	if (holdings[book_position].getLocation() == CHECKED_OUT)
	{
		// if Book is already checked print message and return to menu
		std::cout << "The book is already checked out." << endl;
		return;
	}
	
	// check to see if Book is on hold by another Patron (getLocation)
	else if (holdings[book_position].getLocation() == ON_HOLD)
	{
		// if Book is on hold print message and return to menu
		std::cout << "The book is on hold for another patron." << endl;
		return;
	}
	
	// else update the Book checkedOutBy, dateCheckedOut and Location
		// if Book was on hold for Patron
			// update requestedBy
		// update Patron list
		// print Book 'title' has been checked out to Patron 'name'
 }
 /**************************************************************************************************
 *								returnBook															
 *
 ***************************************************************************************************/
 void Library::returnBook(std::string bookID)
 {
	// check to see if Book (bookID) does not exist in Library
		// if does not exist print out message and return to menu
	// if book is not checked out
		// print message and return to menu
	// else
		// update the Patron list
		// update book location
		// print out the Book 'title' has been returned
 }
 /**************************************************************************************************
 *								requestBook															
 *
 ***************************************************************************************************/
 void Library::requestBook(std::string patronID, std::string bookID)
 {
	// check to see if Book (bookID) or Patron (patronID) are not in Library
	int members_length = members.length(),
	holdings_length = holdings.length(),
	book_position = 0,
	members_check = 0,
	holdings_check = 0;
	
	// check to see if passed patronID does not exist
	for (int i = 0; i < members_length; i++)
	{
		// loop through vector and check if the patronID exists
		if (members[i].getIdNum() == patronID)
			members_check++;
	}
	
	if (members_check == 0)
	{
		// if patronID does not exist print out message and return to menu
		std::cout << "The patronID does not exist." << endl;
		return;
	}
	
	// check to see if passed bookID do not exist
	for (int i = 0; i < holdings_length; i++)
	{
		// loop through vector and check if the bookID exists
		if (holdings[i].getIdCode() == bookID)
		{
			holdings_check++;
			book_position = i;
		}
	}
	
	if (holdings_check == 0)
	{
		// if bookId does not exist print out message and return to menu
		std::cout << "The bookID does not exist." << endl;
		return;
	}
	
	// if Book is requested by another Patron
	if (holdings[i].getRequestedBy() != patronID)
	{
		// print message and return to menu
		std::cout << "Another patron has requested the book." << endl;
		return;
	}
	
	// update the Book requestedBy
		
		// if Book is ON_SHELF
			// update location to ON_HOLD
		// print Book 'title' is on request for Patron 'name'
 }
 /**************************************************************************************************
 *								incrementCurrentDate															
 *
 ***************************************************************************************************/
 void Library::incrementCurrentDate()
 {
	// increment current date
	// increase each Patron fine by DAILY_FINE for each overdue Book (use amendFine)
 }
 /**************************************************************************************************
 *								payFine															
 *
 ***************************************************************************************************/
 void Library::payFine(std::string patronID, double payment)
 {
	// check to see if Patron (patronID) do not exist
		// if not print out message and return to menu
	// use amendFine to update the Patron fine
		// print out that fines for Patron 'name' are now Patron fineAmout
 }
 /**************************************************************************************************
 *								viewPatronInfo															
 *
 ***************************************************************************************************/
 void Library::viewPatronInfo(std::string patronID)
 {
	// check to see if Patron (patronID) do not exist
		// if not print out message and return to menu
	// print Patron 'ID', 'name', any checked out Books and current fines
 }
 /**************************************************************************************************
 *								viewBookInfo															
 *
 ***************************************************************************************************/
 void Library::viewBookInfo(std::string bookID)
 {
	// check to see if Book does not exist in Library
		// if not print out message and return to menu
	// print the Book ID, 'title', 'author' 'location'
	// if it's on request print Patron that requested it
	// if it's checked out print Patron that check it out and due date	
 }

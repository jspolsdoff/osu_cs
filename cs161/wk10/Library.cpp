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
	
	std::cout << "Enter the following information to create a new book in the library's system" << std::endl;
	
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
	std::cin.ignore(256,'\n');
	
	std::cout << "Enter the following information to create a new member in the library's system" << std::endl;
	
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
	int members_length = members.size(),
	holdings_length = holdings.size(),
	book_position = 0,
	member_position = 0,
	members_check = 0,
	holdings_check = 0;
	Patron* patronPtr;
	Book* bookPtr;
	
	// check to see if passed patronID does not exist
	for (int i = 0; i < members_length; i++)
	{
		// loop through vector and check if the patronID exists
		if (members[i].getIdNum() == patronID)
			members_check++;
			member_position = i;
			patronPtr = &members[i];
	}
	
	if (members_check == 0)
	{
		// if patronID does not exist print out message and return to menu
		std::cout << "The patronID does not exist." << std::endl;
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
			bookPtr = &holdings[i];
		}
	}
	
	if (holdings_check == 0)
	{
		// if bookId does not exist print out message and return to menu
		std::cout << "The bookID does not exist." << std::endl;
		return;
	}
	
	// check to see if Book is already checked out (getLocation)
	if (holdings[book_position].getLocation() == CHECKED_OUT)
	{
		// if Book is already checked print message and return to menu
		std::cout << "The book is already checked out." << std::endl;
		return;
	}
	
	// check to see if Book is on hold by another Patron (getLocation)
	else if (holdings[book_position].getLocation() == ON_HOLD)
	{
		// if Book is on hold print message and return to menu
		std::cout << "The book is on hold for another patron." << std::endl;
		return;
	}
	
	// else update the Book checkedOutBy, dateCheckedOut and Location
	else
	{
		holdings[book_position].setCheckedOutBy(patronPtr);
		
		holdings[book_position].setDateCheckedOut(currentDate);
		
		holdings[book_position].setLocation(CHECKED_OUT);
		
		// if Book was on hold for Patron
		if (holdings[book_position].getRequestedBy() == patronPtr)
		{
			// update requestedBy
			holdings[book_position].setRequestedBy(NULL);
		}
		
		// update Patron list
		members[member_position].addBook(bookPtr);
		
		// print Book 'title' has been checked out to Patron 'name'
		std::cout << "CONFIRMED: The book " << holdings[book_position].getTitle() << " is on checked out by " << members[member_position].getName() << std::endl;
	}
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
	int members_length = members.size(),
	holdings_length = holdings.size(),
	book_position = 0,
	member_position = 0,
	members_check = 0,
	holdings_check = 0;
	Patron* patronPtr;
	
	// check to see if passed patronID does not exist
	for (int i = 0; i < members_length; i++)
	{
		// loop through vector and check if the patronID exists
		if (members[i].getIdNum() == patronID)
		{	
			members_check++;
			member_position = i;
			patronPtr = &members[i];
		}
	}
	
	if (members_check == 0)
	{
		// if patronID does not exist print out message and return to menu
		std::cout << "The patronID does not exist." << std::endl;
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
		std::cout << "The bookID does not exist." << std::endl;
		return;
	}
	
	// if Book is requested by another Patron
	if (holdings[book_position].getRequestedBy() != NULL)
	{
		// print message and return to menu
		std::cout << "Another patron has requested the book." << std::endl;
		return;
	}	
	
	// update the Book requestedBy
	holdings[book_position].setRequestedBy(patronPtr);
	
		// if Book is ON_SHELF
		if (holdings[book_position].getLocation() == ON_SHELF)
		{
			// update location to ON_HOLD
			holdings[book_position].setLocation(ON_HOLD);
		}
		// print Book 'title' is on request for Patron 'name'
		std::cout << "CONFIRMED: The book " << holdings[book_position].getTitle() << " is on request by " << members[member_position].getName() << std::endl;
 }
 /**************************************************************************************************
 *								incrementCurrentDate															
 *
 ***************************************************************************************************/
 void Library::incrementCurrentDate()
 {
	// increment current date
	currentDate++;
	
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
	int members_length = members.size(),
	members_position = 0,
	members_check = 0;
	Patron* patronPtr;
	
	// check to see if passed patronID does not exist
	for (int i = 0; i < members_length; i++)
	{
		// loop through vector and check if the patronID exists
		if (members[i].getIdNum() == patronID)
			members_check++;
			members_position = i;
			patronPtr = &members[i];
	}
	
	if (members_check == 0)
	{
		// if patronID does not exist print out message and return to menu
		std::cout << "The patronID does not exist." << std::endl;
		return;
	}
	
	// print Patron 'ID', 'name', any checked out Books and current fines
	std::cout << "Patron ID: " << members[members_position].getIdNum() << std::endl;
	
	std::cout << "Patron ID: " << members[members_position].getName() << std::endl;
	
	std::cout << "\nThe following books are checked out\n" << std::endl;
	
	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i].getCheckedOutBy() == patronPtr)
			std::cout << holdings[i].getTitle() << std::endl;
	}
	
	std::cout << "\nCurrent Fines: $" << std::fixed << std::setprecision(2) << members[members_position].getFineAmount() << std::endl;
 }
 /**************************************************************************************************
 *								viewBookInfo															
 *
 ***************************************************************************************************/
 void Library::viewBookInfo(std::string bookID)
 {
	int holdings_length = holdings.size(),
	book_position = 0,
	holdings_check = 0;
	
	// check to see if Book does not exist in Library
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
		std::cout << "The bookID does not exist." << std::endl;
		return;
	}
	
	// print the Book ID, 'title', 'author' 'location'
	std::cout << "Book ID: " << holdings[book_position].getIdCode() << std::endl;
	
	std::cout << "Title: " << holdings[book_position].getTitle() << std::endl;
	
	std::cout << "Author: " << holdings[book_position].getAuthor() << std::endl;
	
	std::cout << "Location: " << holdings[book_position].getLocation() << std::endl;

	// if it's on request print Patron that requested it
	if (holdings[book_position].getRequestedBy() != NULL)
	{
		std::cout << "Requested By: " << holdings[book_position].getRequestedBy()->getName() << std::endl;
	}
	// if it's checked out print Patron that check it out and due date	
	if (holdings[book_position].getCheckedOutBy() != NULL)
	{
		std::cout << "Checked Out By: " << holdings[book_position].getCheckedOutBy()->getName() << std::endl;
	} 

}


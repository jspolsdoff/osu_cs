// Library.cpp is the Library class function implementation file.
#include "Library.h"

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
 
 }
 /**************************************************************************************************
 *								addMember															
 *This is a member function the prompts the user for patron info and uses it to creat a Patron, which
 *is added to members vector.
 ***************************************************************************************************/
 void Library::addMember()
 {
 
 }
 /**************************************************************************************************
 *								checkOutBook															
 *This member function will check out a Book to a Patron. It will preform various validations as well.
 ***************************************************************************************************/
 void Library::checkOutBook(std::string patronID, std::string bookID)
 {
	// check to see if passed patronID do not exist
		// if patronID does not exist print out message and return to menu
	// check to see if passed bookID do not exist
		// if bookId does not exist print out message and return to menu
	// check to see if Book is already checked out (getLocation)
		// if Book is already checked print message and return to menu
	// check to see if Book is on hold by another Patron (getLocation)
		// if Book is on hold print message and return to menu
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
		// if not print message and return to menu
	// if Book is requested by another Patron
		// print message and return to menu
	// else 
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
	// increament current date
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

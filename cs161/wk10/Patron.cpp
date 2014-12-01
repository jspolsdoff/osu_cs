// Patron.cpp is the Patron class function implementation file.
#include "Patron.h"

/**************************************************************************************************
 *								Patron																
 *This is the default constructor for the Patron class that takes no arguments.
 ***************************************************************************************************/
 Patron::Patron()
 {
	
 }
 /**************************************************************************************************
 *								Patron								
 *This is a constructor for the Patron class that takes a idNum and name as arguments.
 ***************************************************************************************************/
 Patron::Patron(std::string idn, std::string n)
 {
	idNum = idn;
	name = n;
 }
 /**************************************************************************************************
 *								getIdNum									
 *This is a member function that returns an idNum for a Patron.
 ***************************************************************************************************/
 std::string Patron::getIdNum()
 {
	return idNum;
 }
 /**************************************************************************************************
 *								getName						
 *This is a member function that returns a name for a Patron.
 ***************************************************************************************************/
 std::string Patron::getName()
 {
	return name;
 }
 /**************************************************************************************************
 *								getCheckedOutBooks							
 *This is a member function that returns a vector containing a list of Books that the Patron has
 *checkedOut.
 ***************************************************************************************************/
 std::vector<Book*> Patron::getCheckedOutBooks()
 {
	return checkedOutBooks;
 }
 /**************************************************************************************************
 *								addBook					
 *This is a member function that adds the specified Book to checkedOutBooks.
 ***************************************************************************************************/
 void Patron::addBook(Book* b)
 {
	checkedOutBooks.pushback(*b);
 }
 /**************************************************************************************************
 *								removeBook								
 *This is a member function that removes the specified Book from checkedOutBooks.
 ***************************************************************************************************/
 void Patron::removeBook(Book* b)
 {
	int length = checkedOutBooks.size();
	
	// loop through the checkedOutBooks vector looking for Book
	for (int i = 0; i < length; i++)
	{
		// if the loop finds the books then delete the book and shift elements over
		if (checkedOutBooks[i] == *b)
			checkedOutBooks.erase(i);
	}
 }
 /**************************************************************************************************
 *								getFineAmount							
 *This is a member function that returns how much the Patron owes the Library in late fines.
 ***************************************************************************************************/
 double Patron::getFineAmount()
 {
	return fineAmount;
 }
 /**************************************************************************************************
 *								amendFine								
 *This is a member function that amends the fineAmount. A positive argument increases and a negative
 *argument decreases fineAmount.
 ***************************************************************************************************/
 void Patron::amendFine(double amount)
 {
	fineAmount += amount;
 }

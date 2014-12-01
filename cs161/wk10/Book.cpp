// Book.cpp is the Book class function implementation file.
#include "Book.h"

/**************************************************************************************************
 *								getCheckOutLength								
 *This is a member function that returns the how long a Book can be checked out for.
 ***************************************************************************************************/
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
} 

/**************************************************************************************************
 *								getIdCode
 *This is a member function that returns the unique identifier for a Book.
 ***************************************************************************************************/
 std::string Book::getIdCode()
 {
	return idCode;
 }
 /**************************************************************************************************
 *								getTitle
 *This is a member function that returns the title for a Book.
 ***************************************************************************************************/
 std::string Book::getTitle()
 {
	return title;
 }
 /**************************************************************************************************
 *								getAuthor
 *This is a member function that returns the author for a Book.
 ***************************************************************************************************/
 std::string Book::getAuthor()
 {
	return author;
 }
 /**************************************************************************************************
 *								getLocation
 *This is a member function that returns the location for a Book. It can either be on the shelf, on hold
 *or checked out.
 ***************************************************************************************************/
 Locale Book::getLocation()
 {
	return location;
 }
 /**************************************************************************************************
 *								setLocation
 *This is a member function that sets the locations for a Book. It can either be on the shelf, on hold
 *or checked out.
 ***************************************************************************************************/
 void Book::setLocation(Locale lo)
 {
	location = lo;
 }
 /**************************************************************************************************
 *								getCheckedOutBy
 *This is a member function that returns the Patron who has checked out a Book.
 ***************************************************************************************************/
 Patron* Book::getCheckedOutBy()
 {
	return checkedOutBy;
 }
 /**************************************************************************************************
 *								setCheckedOutBy
 *This is a member function that sets the Patron who has checked out a Book.
 ***************************************************************************************************/
 void Book::setCheckedOutBy(Patron* p)
 {
	checkedOutBy = p;
 }
 /**************************************************************************************************
 *								getRequestedBy
 *This is a member function that returns the Patron who has requested a Book.
 ***************************************************************************************************/
 Patron* Book::getRequestedBy()
 {
	return requestedBy;
 }
 /**************************************************************************************************
 *								setRequestedBy
 *This is a member function that sets the Patrong who has requested a Book.
 ***************************************************************************************************/
 void Book::setRequestedBy(Patron* p)
 {
	requestedBy = p;
 }
 /**************************************************************************************************
 *								getDateCheckedOut
 *This is a member function that returns the date the Book was checked out.
 ***************************************************************************************************/
 int Book::getDateCheckedOut()
 {
	return dateCheckedOut;
 }
 /**************************************************************************************************
 *								setDateCheckedOut
 *This is a member function that sets the date to the currentDate of the Library.
 ***************************************************************************************************/
 void Book::setDateCheckedOut(int d)
 {
	dateCheckedOut = d;
 }
/****************************************************************************
*Author:                      James Spolsdoff
*Dated Created:               11/25/14    
*Last Modified Date:          11/25/14     
*Filename:                    geom.cpp 
*
*Overview:
*This program will use classes and objects to do three functions.
*Store the user input points as objects. Calculate distances between
*the point objects. Calculate the slope of the line segment.
*
*Input:
*The user will input an ordered pair of points that will be stored as 
*point objects.
*
*Output:
*The classes will display functions that calculate distance and slope.
*
****************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

// create Point class
class Point
{ 
	// private double variables for 'x' and 'y' coordinates
	private:
	double x;
	double y;
	double distance;

	public: 
	// constructor that takes two double parameters to initialize coordinates
	Point();
	
	// mutator to set the point to the user input coordinates
	void setPoint(double, double);
	
	// create accessor functions for points
	double getX() const
	{ return x; }
	double getY() const
	{ return y; } 
	
	// method called 'distanceTo' that parameter constant reference to another Point class
	double distanceTo(const Point&);
};
	
// create LineSegment class
class LineSegment
{ 
	// private area contains two Point objects that represent endpoints
	private:
	Point point1;
	Point point2;
	double length;
	double slope;

	public:
	// constructor that uses two Point parameters to initialize endpoints
	LineSegment(Point, Point);

	// mutator to set the line segment with new end points
	void setPoint(Point, Point);

	// method called 'length' that returns the length of LineSegment
	double getLength();
	
	// method called 'slope' that returns slope of LineSegment
	double getSlope();
};

int main()
{

	Point point1,				// declare object for first Point
	      point2;	 			// declare object for second point
	LineSegment line1(point1, point2);	// declare object for LineSegment
	double x,				// declare variable for 'x' coordinate
	       y;				// declare variable for 'y' coordinate
	
	// wrap program in do/while loop to allow user to repeat	
	// ask user for first point coordinate
	cout << "Please enter the coordinates for two points below." << endl;
 
	// store input in variables
	cout << "Point 1 X: ";
	cin >> x;

	cout << "Point 1 Y: ";
	cin >> y;

	// pass variables to create 'point1' object
	point1.setPoint(x, y);
	
	cout << endl;

	// ask user for second point coordinate
	cout << "Point 2 X: ";
	cin >> x;

	cout << "Point 2 Y: ";
	cin >> y;
	
	// pass variables to create 'point2' object
	point2.setPoint(x, y);
	
	// pass both Point objects to LineSegment to create new line object
	line1.setPoint(point1, point2);	

	cout << "The distance between the two points are " << point1.distanceTo(point2) << endl;

	// build 'line' object with both Point objects
	cout << "\nThe length of the LineSegment is " << line1.getLength() << endl; 

	// display the 'line' objects length and slope
	cout << "\nThe slope of the LineSegment is " << line1.getSlope() << endl;

	return 0;
}  

// Point member function implementation section

/**************************************************************************************************
 *					Point
 *This is the default constructor. It initializes the coordinates of the Point class.
  **************************************************************************************************/  
Point::Point()
{
	// initialize points
	x = y = 0;
}

/**************************************************************************************************
 *					distanceTo
 *This is a member function of Point that calculates the distance between two Point objects.
 **************************************************************************************************/
double Point::distanceTo(const Point &second_point)
{
	// use the math function a^2 = b^2 + c^2
	return distance = sqrt(pow((x - second_point.getX()), 2) + pow((y - second_point.getY()), 2));
}

/**************************************************************************************************
 *					setPoint
 *This is a member function mutator to set the point for the two Point objects. 
 **************************************************************************************************/
void Point::setPoint(double input_x, double input_y)
{
	x = input_x;
	y = input_y;
}   

// LineSegment member function implementation section

/**************************************************************************************************
 *					LineSegment
 *This is the default constructor for the LineSegment class.
 **************************************************************************************************/
LineSegment::LineSegment(Point p1, Point p2)
{
	point1 = p1;
	point2 = p2;
}  

/**************************************************************************************************
 *					setPoint
 *
 **************************************************************************************************/ 
void LineSegment::setPoint(Point p1, Point p2)
{
	point1 = p1;
	point2 = p2;
}
/**************************************************************************************************
 *					getLength
 *This member function uses the two Point classes in the LineSegment class to find its length
 **************************************************************************************************/
double LineSegment::getLength()
{
	return length = sqrt(pow((point1.getX() - point2.getX()), 2) + pow((point1.getY() - point2.getY()), 2 ));
} 

/**************************************************************************************************
 *					getSlope
 *This member function uses calculates the slope of the LineSegment class 
 **************************************************************************************************/
double LineSegment::getSlope()
{
	return slope = ((point1.getY() - point2.getY()) / (point1.getX() - point2.getX()));
}  

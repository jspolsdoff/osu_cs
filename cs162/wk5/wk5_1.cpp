/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/08/15
*Last Modification Date: 2/08/15
*Filename:               lab5.cpp
*
*Overview
*This program will act as a filter and using inheritance and polymorphism
***************************************************************************************************/
#include <iostream>
#include <fstream>

// define base class that will be used for all file filters
class Filter
{
	private:
	std::ifstream inputFile;	// create the input file stream
	std::ofstream outputFile;	// create the output file stream
	
	private:
	virtual void doFilter() = 0;	// pure virtual function used to make transformations
};
	
// define derived class based on above base
class basicFilter:public Filter
{
	private:
	
	public:
	virtual void doFilter();	// filter function will create an unchanged copy of the original file
};
	
void main()
{
	basicFilter filter1;
	
	filter1.doFilter();

	return 0;
}

// derived class member function
/**************************************************************************************************
 *						doFilter
 *
 **************************************************************************************************/
 void basicFilter::doFilter()
 {
	char x;
	
	// open input file
	inputFile.open("original.txt");
	
	// open output file
	outputFile.open("filtered.txt");
	
	// test for file open errors
	if (inputFile && outputFile)
	{	
		// use while loop to transfer information from input to output file
		while (inputFile)
		{
			inputFile >> x;
			outputFile << x;
		}
		
		// close both files
		inputFile.close();
		outputFile.close();
	}	
	
	// else error opening file display message
	else
	{
		std::cout << "Error opening the files." << std::endl;
	}
 }
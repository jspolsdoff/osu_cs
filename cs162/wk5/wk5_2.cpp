/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/08/15
*Last Modification Date: 2/08/15
*Filename:               lab5_1.cpp
*
*Overview
*This program will act as a filter and using inheritance and polymorphism
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

// define base class that will be used for all file filters
class Filter
{
	private:
	
	private:
	virtual void doFilter() = 0;	// pure virtual function used to make transformations
};
	
// define derived class based on above base
class basicFilter:public Filter
{
	private:
	int key;	

	public:
	basicFilter(int key);
	virtual void doFilter();	// filter function will create an unchanged copy of the original file
};
	
int main()
{
	int key = 0;
		
	std::cout << "Please enter an integer encryption key: ";
	std::cin >> key;

	basicFilter filter1(key);	

	filter1.doFilter();

	return 0;
}

// derived class member function
/**************************************************************************************************
 *
 *
 **************************************************************************************************/
basicFilter::basicFilter(int x)
{
	key = x;
}
  
/**************************************************************************************************
 *						doFilter
 *
 **************************************************************************************************/
 void basicFilter::doFilter()
 {
	std::ifstream inputFile;	// create the input file stream
	std::ofstream outputFile;	// create the outputfile stream
	std::string input_line;
	char x;
	int offset = 0;
		
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
			getline(inputFile, input_line);
			const char *y = input_line.c_str();
			
			for(int i = 0;i < input_line.length(); i++)
			{
					
				if (y[i] >= 65 && y[i] <= 90)
				{
					offset = 65;
				}
				else if (y[i] >= 97 && y[i] <= 122)
				{
					offset = 97;
				}
				
				x = ((y[i] - offset) + key) % 26 + offset;		
			
				outputFile << x;
			}	
		
			outputFile << std::endl;	
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

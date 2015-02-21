/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/15/15
*Last Modification Date: 2/15/15
*Filename:               lab6_1.cpp
*
*Overview
*This program will be an example of code for searching algorithms. It will implement one
*basic algorithm that searches for a 0 in my data files.
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// function prototype for vetor search
int conductSearch(std::vector<int> &, int);

int main()
{
	std::ifstream inputFile;	// create file stream object
	std::vector <int> numbers;	// create vector
	std::string filename;	// variable used to store users filename input
	int search_value;	// this is the value we are searching for
	int result;	// the result of the search
	
	std::cout << "What file would you like to load: ";
	std::cin >> filename;
	
	std::cout << "What number are we searching for: ";
	std::cin >> search_value;
	
	// open file
	inputFile.open(filename.c_str());
	
	// test if file opened correctly
	if (inputFile)
	{
		// load file data into vector
		while (inputFile)
		{
			int i;	// variable to hold number from file before being placed into vector
			inputFile >> i;	// move int values from file stream object to variable
			numbers.push_back(i);	// load int variable into vector
		}
		
		// close file
		inputFile.close();
	}	
		
	// else show error and end program
	else
	{
		std::cout << "Error opening the files." << std::endl;
	}		
	
	// conduct search
	result = conductSearch(numbers, search_value);
	
	// analyze result and let user know if number was found
	if (result == -1)
		std::cout << "The number " << search_value << " was not found." << std::endl;
	else
	{
		std::cout << "The number " << search_value << " was found in position " << (result +1) << "!" << std::endl;
	}	
	
	return 0;
}

/**************************************************************************************************
*	conductSearch
*
*
***************************************************************************************************/
int conductSearch(std::vector<int> &numbers, int value)
{
	int index = 0;		// set index to 0
	int position = -1;	// set position to -1
	bool found = false;	// set found to false
	
	// conduct search
	while ((index < numbers.size()) && !found)
	{
		if (numbers[index] == value)
		{
			found = true;
			position = index;
		}
		
		index++;
	}
	
	// return result
	return position;	
}

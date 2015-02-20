/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/15/15
*Last Modification Date: 2/15/15
*Filename:               lab6_3.cpp
*
*Overview
*This program will be an example of code for searching algorithms. It will implement one
*basic algorithm that searches for a 0 in my data files.
***************************************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// display function prototypes
void sortVector(std::vector<int> &numbers);
void displayVector(std::vector<int> numbers);
int binarySearch(std::vector<int> &, int);	

int main()
{
	std::ifstream inputFile;	// create file stream object
	std::ofstream outputFile;
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

	// call sort vector function
	sortVector(numbers);
		
	// call display vector function	
	displayVector(numbers);
	
	// call the binary search function
	result = binarySearch(numbers, search_value);
	
	// analyze result and let user know if number was found
	if (result == -1)
		std::cout << "The number " << search_value << " was not found." << std::endl;
	else
	{
		std::cout << "The number " << search_value << " was found in position " << (result +1) << "!" << std::endl;
	}	
	
	// ask user for output file information
	std::cout << "What file would you like to write to: ";
	std::cin >> filename;
	
	// open file
	outputFile.open(filename.c_str());
	
	for (int i = 0; i < numbers.size(); i++)
	{
		outputFile << numbers[i];
	}

	// close file
	outputFile.close();
	
	return 0;
}

/**************************************************************************************************
*	sortVector
*
*
***************************************************************************************************/
void sortVector(std::vector<int> &numbers)
{ 
	int temp;
	bool swap;

	do
	{ 
		swap = false;

		for (unsigned count = 0; count < numbers.size()-1; count++)
		{

			if (numbers[count] > numbers[count + 1])
			{
				temp = numbers[count];
		
				numbers[count] = numbers[count + 1];

				numbers[count + 1] = temp;
		
				swap = true;
			}
		}
	} while (swap);
}

/**************************************************************************************************
*	displayVector
*
*
***************************************************************************************************/
void displayVector(std::vector<int> numbers)
{
	for (unsigned count = 0; count < numbers.size(); count++)
		std::cout << numbers[count] << " ";
	
	std::cout << std::endl;
}

/**************************************************************************************************
*	binarySearch
*
*
***************************************************************************************************/
int binarySearch(std::vector<int> &numbers, int value)
{
	int first = 0;
	int last = numbers.size();
	int middle;
	int position = -1;
	bool found = false;
	
	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		
		if (numbers[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (numbers[middle] > value)
			last = middle -1;
		else first = middle + 1;	
	}
	
	return position;
}	
/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/15/15
*Last Modification Date: 2/15/15
*Filename:               lab6_2.cpp
*
*Overview
*This program will be an example of code for searching algorithms. It will implement one
*basic algorithm that searches for a 0 in my data files.
***************************************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>

// display function prototypes
void sortVector(std::vector<int> &numbers);
void displayVector(std::vector<int> numbers);

int main()
{
	std::ifstream inputFile;	// create file stream object
	std::ofstream outputFile;
	std::vector <int> numbers;	// create vector
	std::string filename;	// variable used to store users filename input
	
	std::cout << "What file would you like to load: ";
	std::cin >> filename;
	
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
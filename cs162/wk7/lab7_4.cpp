/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/21/15
*Last Modification Date: 2/21/15
*Filename:               lab7_4.cpp
*
*Overview
*This program will be an example of code for searching algorithms. It will implement one
*basic algorithm that searches for a 0 in my data files.
***************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std::chrono;

// display function prototypes
void sortVector(std::vector<int> &numbers, int);
void displayVector(std::vector<int> numbers);

int main()
{
	std::ifstream inputFile;	// create file stream object
	std::ofstream outputFile;
	std::vector <int> numbers;	// create vector
	std::string filename;	// variable used to store users filename input
	int total_size;	// total size of the vector calculated when loading file
	
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
			total_size++;
		}
		
		// close file
		inputFile.close();
	}	
		
	// else show error and end program
	else
	{
		std::cout << "Error opening the files." << std::endl;
	}

	// start timer
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	// call sort vector function
	sortVector(numbers, total_size);
	
	// stop timer and calculate result
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
		
	// call display vector function	
	displayVector(numbers);
	
	// display timer results
	std::cout << "It took " << duration << " microseconds to run this sort." << std::endl;
	
	return 0;
}

/**************************************************************************************************
*	sortVector
*
*
***************************************************************************************************/
void sortVector(std::vector<int> &numbers, int size)
{ 
	int temp;

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(numbers[j] > numbers[j + 1])
			{
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
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
/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/20/15
*Last Modification Date: 2/21/15
*Filename:               lab7_2.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std::chrono;

// function prototype for vetor search
int conductSearch(std::vector<int> &, int);

int main()
{
	std::ifstream inputFile;	// create file stream object
	std::vector <int> numbers;	// create vector
	std::string filename;	// variable used to store users filename input
	int search_value;	// this is the value we are searching for
	int result;	// the result of the search
	
	// using high_resolution_clock example code from from cplusplus.com
		
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
	
	// start timer
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	// conduct search
	result = conductSearch(numbers, search_value);
	
	// stop timer and calculate result
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	
	// analyze result and let user know if number was found
	if (result == -1)
		std::cout << "The number " << search_value << " was not found." << std::endl;
	else
	{
		std::cout << "The number " << search_value << " was found in position " << (result +1) << "!" << std::endl;
	}

	// display timer results
	std::cout << "It took " << duration << " microseconds to run this sort." << std::endl;
	
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

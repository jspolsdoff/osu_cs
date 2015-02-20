/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           2/19/15
*Last Modification Date: 2/19/15
*Filename:               lab7_1.cpp
*
*Overview
*
*
***************************************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

int main()
{
	std::ofstream outputFile1;	// file stream object for output
	std::ofstream outputFile2;
	std::ofstream outputFile3;
	std::ofstream outputFile4;
	std::string file1;	// variables for file names
	std::string file2;
	std::string file3;
	std::string file4;
	int max_number;	// how many random numbers the user wants to save to file
	int random_num;	// stores the random number that will be saved to file
	int half_max;	// cuts the number of random numbers in half so that a 0 can be input there
	
	// seed random number generator
	srand(time(NULL));	
	
	// ask user for how many random numbers to generate
	std::cout << "How many random numbers would you like to generate for each of the three files: ";
	std::cin >> max_number;

	// dump input buffer
	std::cin.ignore(10000, '\n');

	half_max = max_number / 2;
	
	// ask user for name of files to write to
	std::cout << "Please enter a name for file 1: ";
	getline(std::cin, file1);
	
	std::cout << "Please enter a name for file 2: ";
	getline(std::cin, file2);
	
	std::cout << "Please enter a name for file 3: ";
	getline(std::cin, file3);
	
	std::cout << "Please enter a name for file 4: ";
	getline(std::cin, file4);
	
	// open the files for writing
	outputFile1.open(file1.c_str());
	
	outputFile2.open(file2.c_str());
	
	outputFile3.open(file3.c_str());
	
	outputFile4.open(file4.c_str());
	
	// first for loop generates a file with zero at the beginning
	for (int i = 0; i < max_number; i++)
	{
		if (i == 0)
			outputFile1 << 0 << std::endl;
			
		else
		{
			random_num = (rand() % 9) + 1;
			
			outputFile1 << random_num << std::endl;
		}
	}
	
	// second for loop generates a file with a zero in the middle
	for (int i = 0; i < max_number; i++)
	{
		if (i == (half_max - 1))
			outputFile2 << 0 << std::endl;
			
		else
		{
			random_num = (rand() % 9) + 1;
			
			outputFile2 << random_num << std::endl;
		}
	}
	
	// third for loop generates a file with zero at the end
	for (int i = 0; i < max_number; i++)
	{
		if (i == (max_number - 1))
			outputFile3 << 0 << std::endl;
			
		else
		{
			random_num = (rand() % 9) + 1;
			
			outputFile3 << random_num << std::endl;
		}
	}
	
	// last loop just random numbers
	for (int i = 0; i < max_number; i++)
	{
		random_num = (rand() % 9) + 1;
			
		outputFile4 << random_num << std::endl;
	}
	
	// close files
	outputFile1.close();
	
	outputFile2.close();
	
	outputFile3.close();
	
	outputFile4.close();

	return 0;
}

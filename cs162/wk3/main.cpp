/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           1/24/14
*Last Modification Date: 1/24/14
*Filename:               main.cpp
*
*Overview
*This program will merge the numbers contained in two files and write all the numbers into a third
*file.
***************************************************************************************************/

#include <iostream>
// include file stream
#include <fstream>

// function prototype that takes two input streams and output stream as arguments
// this will compare and sort numbers from low to high and write to output stream

int main()
{
	// input stream for first file
	ifstream inputFile1;
	// input stream for second file
	// output stream for destination file
	// variable to run output test on first file
	int number;
	
	// open file
	inputFile1.open("num1.txt");
	
	// test for file open errors
	if (inputFile1)
	{
		// use while loop to print file contents to screen
		while (inputFile1 >> number)
			std::cout << number << std::endl;
			
		// close file
		inputFile1.close();
	}
	
	// else show error and end program
	else
	{
		std::cout << "Error opening the file." << std::endl;
	}
	
	return 0;

}

// function to sort and write file
/**************************************************************************************************
*						sortFile
*
***************************************************************************************************/ 
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
#include <fstream>

// function prototype that takes two input streams and output stream as arguments
// this will compare and sort numbers from low to high and write to output stream

int main()
{
	// input stream for first file
	std::ifstream inputFile1;
	
	// input stream for second file
	std::ifstream inputFile2;	

	// output stream for destination file
	std::ofstream outputFile;
	
	// variable to run output test on first file
	int number;
	
	// open first input file
	inputFile1.open("num1.txt");

	// open second input file
	inputFile2.open("num2.txt"); 

	// open output file
	outputFile.open("numout.txt"); 
	
	// test for file open errors
	if (inputFile1 && inputFile2)
	{
		// use while loop to print file contents to output file
		while (inputFile1 >> number)
			outputFile << number << std::endl;
			
		// close file
		inputFile1.close();

		// use while loop to print file contents to output file
		while (inputFile2 >> number)
			outputFile << number << std::endl;

		//close second input and out files
		inputFile2.close();
		outputFile.close(); 
	}
	
	// else show error and end program
	else
	{
		std::cout << "Error opening the files." << std::endl;
	}
	
	return 0;

}

// function to sort and write file
/**************************************************************************************************
*						sortFile
*
***************************************************************************************************/ 

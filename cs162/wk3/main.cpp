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
void sortFile(std::ifstream &if1,std::ifstream &if2,std::ofstream &of);

int main()
{
	// input stream for first file
	std::ifstream inputFile1;
	
	// input stream for second file
	std::ifstream inputFile2;	

	// output stream for destination file
	std::ofstream outputFile;
	
	// call function to sort and put numbers in output file
	sortFile(inputFile1, inputFile2, outputFile);	

	std::cout << "The sort has been completed." << std::endl;

	return 0;

}

// function to sort and write file
/**************************************************************************************************
*						sortFile
*
***************************************************************************************************/ 
void sortFile(std::ifstream & if1,std::ifstream & if2,std::ofstream & of)
{
	// open first input file
	if1.open("num1.txt");

	// open second input file
	if2.open("num2.txt"); 

	// open output file
	of.open("numout.txt"); 

	// create int variables for conparison
	int num1 = 0;
	int num2 = 0;

	// put first value in file stream into int variable
	if1 >> num1;
	if2 >> num2; 
		
	// test for file open errors
	if (if1 && if2)
	{
		// use a loop and the peek member function to compare numbers in each file 
		while (if1 && if2)
		{
			if (num1 < num2)
			{
				of << num1 << std::endl;
				if1 >> num1;
			}
			else
			{
				of << num2 << std::endl;
				if2 >> num2;
			}
		}
		
		// use if statement with stream as parameter to check if end of stream is reached for first file
		if (if1)
		{	
			// write rest of stream to output file
			while (if1)
			{
				of << num1 << std::endl;
				if1 >> num1;
			}
		}
		// use if statement with stream as parameter to check if end of stream is reached for second file
		if (if2)
		{
			// write rest of stream to output file
			while (if2)
			{
				of << num2 << std::endl;
				if2 >> num2;
			}
		}
			
		//close files
		if1.close();
		if2.close();
		of.close(); 
	}
	
	// else show error and end program
	else
	{
		std::cout << "Error opening the files." << std::endl;
	}
}

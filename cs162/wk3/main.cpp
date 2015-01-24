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
		
	// test for file open errors
	if (if1 && if2)
	{
		// use a loop and the peek member function to compare numbers in each file 
		while (if1 && if2)
		{
			if (if1.peek() < if2.peek())
				of << if1.get();
			else
				of << if2.get();
		}
		
		// use if statement with stream as parameter to check if end of stream is reached for first file
		if (if1)
		{	
			// write rest of stream to output file
			while (if1)
				of << if1.get();
		}
		// use if statement with stream as parameter to check if end of stream is reached for second file
		if (if2)
		{
			// write rest of stream to output file
			while (if2)
				of << if2.get();
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
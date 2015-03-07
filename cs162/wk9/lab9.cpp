/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           3/7/15
*Last Modification Date: 3/7/15
*Filename:               main.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include "stack.hpp"

int main()
{
	Stack testStack;
	int max_num;
	int num;
	
	std::cout << "DATA STURCTURE TEST PROGRAM\n" << std::endl;
	
	std::cout << "How many numbers will you enter: ";
	std::cin >> max_num;
	
	// fill and display stack
	for (int i = 0; i < max_num; i++)
	{
		std::cout << "Please enter number " << (i + 1) << " for your stack: ";
		std::cin >> num;
		
		std::cout << "Pushing number... " << num << std::endl;
		testStack.push(num);
	}
	
	while (!testStack.isEmpty())
	{
		testStack.pop(num);
		std::cout << "Popping... " << num << std::endl;
	}
	
	// fill and display queue
	
	return 0;
}

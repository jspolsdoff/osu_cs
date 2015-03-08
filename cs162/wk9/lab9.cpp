/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           3/7/15
*Last Modification Date: 3/7/15
*Filename:               lab9.cpp
*
*Overview
*
***************************************************************************************************/
#include <iostream>
#include "stack.hpp"
#include "queue.hpp"

int main()
{
	Stack testStack;
	Queue testQueue;
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
	for (int i = 0; i <max_num; i++)
	{
		std::cout << "Please enter number " << (i + 1) << " for your queue: ";
		std::cin >> num;
		
		std::cout << "Adding to the back... " << num << std::endl;
		testQueue.addBack(num);
	}
	
	while (!testQueue.isEmpty())
	{
		std::cout << "Removing from front... " << testQueue.getFront() << std::endl;
		testQueue.removeFront();
	}
	
	return 0;
}

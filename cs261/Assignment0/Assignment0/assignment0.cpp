/*



*/

#include <iostream>

int main()
{
	int num;
	
	std::cout << "WELCOME TO THE TEST IDE PROGRAM\n" << std::endl;

	std::cout << "Please enter a number and I will double it: ";
	std::cin >> num;

	num = num * 2;

	std::cout << "\nYour number doubled is " << num << std::endl;

	return 0;
}
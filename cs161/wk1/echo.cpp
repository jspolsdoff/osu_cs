/*********************************************************
*Author:                 James Spolsdoff
*Date Created:           10/3/14
*Last Modification Date: 10/5/14
*Filename:               echo.cpp
*
*Overview
*This program will take an integer input from the user and echo it back.
*********************************************************/

#include <iostream>
using namespace std;

int main()
{

	int echo;

	cout << "Hello, I'm Mr. Echo! Type in an integer and I'll repeat it: ";

	cin >> echo;

	cout << "Your number is " << echo << endl;

	cout << "Thanks for playing!" << endl;

	return 0;

}

/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:               11/4/14     
*Last Modified Date:         11/4/14      
*Filename:                       grades.cpp  
*
*Overview:
*This program will generate a text based histogram for quiz results
*input by the user. It will store values in an array and display it once
*all the data has been entered.
*
*Input:
*The user will input how many grades they will enter along with the 
*score for those tests.
*
*Output:
*The program will output a text based histogram based on all the quiz
*results.
*
****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	// declare needed variables
							   const int SIZE = 6;		// variable for array size
		int grades[SIZE] = {0, 0, 0, 0, 0, 0},		// variable for array
								  num_grades = 0, 	// variable for number of quiz scores that will be entered
								            grade = 0,
														 i; 	// variable for loop
	
	// tell the user what the program does
	cout << "This program will ask you for quiz scores and keep tracks and give you a summary of results." << endl;
	
	// ask the user how many quiz scores will be entered
	cout << "How many quiz scores will you enter: ";
	cin >> num_grades;
	
	// loop to go through input
	for (i = 0; i < num_grades; i++)
	{
		// ask user for quiz score
		cout << "Please enter the quiz score: ";
		cin >> grade;
		
		// if/else if statement to test which array element needs to be incremented
		if (grade == 0)
		{
			grades[0]++;
		}
		else if (grade == 1)
		{
			grades[1]++;
		}
		else if (grade == 2)
		{
			grades[2]++;
		}
		else if (grade == 3)
		{
			grades[3]++;
		}
		else if (grade == 4)
		{
			grades[4]++;
		}
		else
		{
			grades[5]++;
		}
	}
	// display the results of the array
	cout << grades[0] << "grade(s) of 0" << endl;
	cout << grades[1] << "grade(s) of 1" << endl;
	cout << grades[2] << "grade(s) of 2" << endl;
	cout << grades[3] << "grade(s) of 3" << endl;
	cout << grades[4] << "grade(s) of 4" << endl;
	cout << grades[5] << "grade(s) of 5" << endl;

	return 0;
}  

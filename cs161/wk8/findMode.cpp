/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    11/20/14    
*Last Modified Date:               11/22/14     
*Filename:                         findMode.cpp 
*
*Overview:
*This program will call a function that passes as a parameter a vector
*of ints and return a vector containing the mode of the data.
*
*Input:
*The program will prompt the user to keep entering another int until they
*want to stop.
*
*Output:
*The program will output the returned mode of the vector from the 
*function.
*
****************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function prototype findMode
vector<int> FindMode(vector<int>);

int main()
{

	// declare variables for main function
	vector<int> user_input_vec;		// variable for vector to store input integers
	vector<int> mode_vec;
	int user_input_num = 0;			// variable for user input
	int user_input_length = 0;		// variable for length of vector	
	int mode_vec_length = 0;		// vaariable used to determined length of vector returned from mode function

	cout << "Enter integers below to fill the vector.\n" << endl;

	do {
		cout << "Please enter an integer: ";
		cin >> user_input_num;
		user_input_vec.push_back(user_input_num);
		cout << "Enter the number '1' to input another number. Enter 'q' if you are done filling the vector: "; 
	
	} while (cin >> user_input_num);

	// pass the vector to the mode function and return mode
	mode_vec = FindMode(user_input_vec);
	
	// find the size of the returned mode vector
	mode_vec_length = mode_vec.size();
	
	// use a for loop to display the mode of the mode value vector returned from the function
	cout << "The mode of the set of numbers you input is/are: ";
	
	for (int i = 0; i < mode_vec_length; i++)
	{
		cout << mode_vec[i] << " ";
	}  	
	
	cout << endl;

	return 0;
}  

/***************************************************************************************************
 *					FindMode
 *This function will find the mode of the vector that is passed to it. It will return the answer  
 *in a vector.
 **************************************************************************************************/ 
vector<int> FindMode(vector<int> input_vec)
{
	int length = input_vec.size();	// size of variable used for loops
	int prev_count = 0;		// variable for previous calculated mode
	int cur_count = 0;		// variable for the current mode count
	int multi_mode_count = 0;	// variable to count if there are more than one mode
	vector<int> mode_vec;		// vector used to store the mode
		

	// sort the vector before calculating the mode	
	sort(input_vec.begin(), input_vec.end());
	
	// create loop to calculate mode
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			// starting couting sorted numbers in vector
			if (input_vec[i] == input_vec[j])	
			cur_count++;
		}
		// check if the set of numbers counted will be the new mode
		if (cur_count > prev_count)	
		{
			prev_count = cur_count;
			cur_count = 0;
			mode_vec.clear();
			mode_vec.push_back(input_vec[i]);
		}
		// if the number appears the name amout of there will be more than one mode
		else if ((cur_count == prev_count) && (input_vec[i] != mode_vec[multi_mode_count]))
		{
			cur_count = 0;
			mode_vec.push_back(input_vec[i]);
			multi_mode_count++;
		} 	 	
		cur_count = 0;
	}  
	
	return mode_vec;
}
 


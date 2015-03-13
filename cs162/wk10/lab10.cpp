/**************************************************************************************************
*Author:                 James Spolsdoff
*Date Created:           3/9/15
*Last Modification Date: 3/13/15
*Filename:               lab10.cpp
*
*Overview
*
***************************************************************************************************/
/*
* Program.cpp
* 
*  OS: Fedora 13
*  Language: Native C++
*  Compiler: GNU g++
*  Created on: Sep 11, 2010
*      Author: julian
*/
 
#include <iostream>
#include <stdlib.h>
#include "FibonacciR.h"
#include "FibonacciNR.h"
#include <chrono>
#include <algorithm>

using namespace std::chrono;

using namespace std;

void Usage()
{
	cout<<"Correct Usage:"<<endl;
	cout<<"./Fibonacci [n]"<<endl;
}

int main(int argc, char** args) 
{
	try
	{
		const char* input; //Note: char by default initializes to '\0'
		if(args[1]!=0)
		{	
			cout<<"1st passed arguement: '"<<args[1]<<"'"<<endl;
			input= args[1]; 
		}
		
		int n= atoi(input);
		
		cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<endl;
		
		cout<<"Calling Recursive Fibonacci implementation"<<endl;
		
		// start timer
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		
		FibonacciR fr(n);
		
		// stop timer and calculate result
		high_resolution_clock::time_point t2 = high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		
		fr.PrintFibonacci();
		
		cout << "The time to run function is : " << duration << endl;
		
		cout<<"Calling Non-Recursive Fibonacci implementation"<<endl;
		
		// start timer
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		
		FibonacciNR fnr(n);
		
		// stop timer and calculate result
		high_resolution_clock::time_point t2 = high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
		
		fnr.PrintFibonacci();
		
		cout << "The time to run function is : " << duration << endl;
		
		cout << "Done!!!!" << endl; 
		
		return 0;
	}
	
	catch(...)
	{
		cout<<"Oops an error occured! Please check usage"<<endl;
		Usage();
		return 1;
	}
}
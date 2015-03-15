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

//using namespace std;

long rfactorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * rfactorial(n-1);
}

long factorialHelper(int n, int result)
{
	if (n == 1)
		return result;
	else
		return factorialHelper(n-1,n*result);
}


void Usage()
{
	std::cout<<"Correct Usage:"<<std::endl;
	std::cout<<"./Fibonacci [n]"<<std::endl;
}

int main(int argc, char** args) 
{
	try
	{
		const char* input; //Note: char by default initializes to '\0'
		if(args[1]!=0)
		{	
			std::cout<<"1st passed arguement: '"<<args[1]<<"'"<<std::endl;
			input= args[1]; 
		}
		
		int n= atoi(input);
		
		std::cout<<"Finding '"<<n<<"'th "<<"fibonacci number...."<<std::endl;
		
		std::cout<<"Calling Recursive Fibonacci implementation"<<std::endl;
		
		// start timer
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		
		FibonacciR fr(n);
		
		// stop timer and calculate result
		high_resolution_clock::time_point t2 = high_resolution_clock::now();

		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

		fr.PrintFibonacci();
		
		std::cout << "The time to run function is : " << time_span.count() << std::endl;
		
		std::cout<<"Calling Non-Recursive Fibonacci implementation"<<std::endl;
		
		// start timer
		t1 = high_resolution_clock::now();
		
		FibonacciNR fnr(n);
		
		// stop timer and calculate result
		t2 = high_resolution_clock::now();

		time_span = duration_cast<duration<double>>(t2 - t1);
		
		fnr.PrintFibonacci();
		
		std::cout << "The time to run function is : " << time_span.count() << std::endl;
		
		std::cout << "Done!!!!" << std::endl; 
	

		/*if (n > 1)
		{
			long factorial = rfactorial(n);

			std::cout << factorial << std::endl;
		}*/	

		return 0;
	}
	
	catch(...)
	{
		std::cout<<"Oops an error occured! Please check usage"<<std::endl;
		Usage();
		return 1;
	}
}

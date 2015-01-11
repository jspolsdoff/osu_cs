/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    1/11/15    
*Last Modified Date:               1/11/15     
*Filename:                         lab1-2.cpp 
*
*Overview:
*This program will use separate linked source files to form a program.
*
*Input:
*None
*
*Output:
*The program will display a message that is in both f() and g().
*
****************************************************************************/
#include <iostream>
#include "f.h"
#include "g.h"

void main()
{
	// call first function
	f();
	
	// call second function
	g();
	
	return 0;
}
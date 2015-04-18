#define _CTR_SECURE_NO_WARNINGS
/* CS261- Assignment 1 - Q.2*/
/* Name: James Spolsdoff
 * Date: 4/5/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = *a * 2;
    
    /*Set b to half its original value*/
	*b = *b / 2;
    
    /*Assign a+b to c*/
	c = *a + *b;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;

	int foo_return;
    
    /*Print the values of x, y and z*/
	printf("The value of x = %d\nThe value of y = %d\nThe value of z = %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
	foo_return = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
	printf("The value returned by foo is %d\n", foo_return);

    /*Print the values of x, y and z again*/
	printf("The value of x = %d\nThe value of y = %d\nThe value of z = %d\n", x, y, z);
 
    /*Is the return value different than the value of z?  Why?*/
	// Yes, the value is different for both x and y because they were passed by reference to the function since its parameters
	// were pointers. The variable z was not changed because a copy of the variable was passed to the function.
    return 0;
}
    
    

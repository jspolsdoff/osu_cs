/* CS261- Assignment 1 - Q.3*/
/* Name: James Spolsdoff
 * Date: 4/5/15
 * Solution description:
 */
 
#include <stdio.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int temp;

	for (int i = 0; i < n; ++i)

	{

		for (int j = i + 1; j < n; ++j)

		{

			if (number[i] > number[j])

			{

				temp = number[i];

				number[i] = number[j];

				number[j] = temp;

			}

		}

	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	int *xPtr;

    /*Allocate memory for an array of n integers using malloc.*/
	xPtr = (int *)malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
	for (int i = 0; i < n; i++)
	{
		xPtr[i] = rand() % 100 + 1;
	}
    
    /*Print the contents of the array.*/
	for (int i = 0; i < n; i++)
	{
		printf("The contents of element %d is %d\n", i + 1, xPtr[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	sort(xPtr, n);
    
	printf("\n");

    /*Print the contents of the array.*/
	for (int i = 0; i < n; i++)
	{
		printf("The contents of element %d is %d\n", i + 1, xPtr[i]);
	}

	free(xPtr);
    
    return 0;
}

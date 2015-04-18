#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
	// check to make sure there are at least two elements in array
	double x;
	double y;
	double z;
	
	if (sizeDynArr(stack) < 2) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and add them and add back to stack
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	z = x + y;
	pushDynArr(stack, z);

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double y;
	double z;

	if (sizeDynArr(stack) < 2) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and sub them and add back to stack
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	z = y - x;
	pushDynArr(stack, z);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double y;
	double z;

	if (sizeDynArr(stack) < 2) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and div them and add back to stack
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	z = y / x;
	pushDynArr(stack, z);
}

void multiple(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double y;
	double z;

	if (sizeDynArr(stack) < 2) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	z = y * x;
	pushDynArr(stack, z);
}

void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double y;
	double z;

	if (sizeDynArr(stack) < 2) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	y = topDynArr(stack);
	popDynArr(stack);
	z = pow(y, x);
	pushDynArr(stack, z);
}

void square(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = x * x;
	pushDynArr(stack, z);
}

void cube(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = x * x * x;
	pushDynArr(stack, z);
}

void absolute(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = fabs(x);
	pushDynArr(stack, z);
}

void squareroot(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = sqrt(x);
	pushDynArr(stack, z);
}

void exponential(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = exp(x);
	pushDynArr(stack, z);
}

void natlog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = log(x);
	pushDynArr(stack, z);
}

void reglog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double x;
	double z;

	if (sizeDynArr(stack) < 1) {
		printf("There are not elements on stack to add.");
		return;
	}

	// pop first two elements, store and conduct operation
	x = topDynArr(stack);
	popDynArr(stack);
	z = log10(x);
	pushDynArr(stack, z);
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	double *pnum = malloc(sizeof(double));
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiple(stack);
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			power(stack);
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
			square(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			squareroot(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			natlog(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			reglog(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if (strcmp(s, "pi") == 0) {
				pushDynArr(stack, 3.14159265);
			}

			else if (strcmp(s, "e") == 0) {
				pushDynArr(stack, 2.7182818);
			}

			else if (isNumber(s, pnum) == 1) {
				pushDynArr(stack, *pnum);
			}

			else {
				printf("The argument you enter is not valid.\n");
				return 1;
			}
			
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if (sizeDynArr(stack) != 1) {
		printf("Error: Not the proper number of arguments\n");
		return 1;
	}

	else {
		result = topDynArr(stack);
	}

	printf("The result is %f\n", result);

	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}

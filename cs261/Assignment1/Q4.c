/* CS261- Assignment 1 - Q.4*/
/* Name: James Spolsdoff
 * Date: 4/5/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/  
	int temp;

	for (int i = 0; i < n; ++i)

	{

		for (int j = i + 1; j < n; ++j)

		{

			if (students[i].score > students[j].score)

			{
				// sort scores
				temp = students[i].score;

				students[i].score = students[j].score;

				students[j].score = temp;

				// sort ids for corresponding scores
				temp = students[i].id;

				students[i].id = students[j].id;

				students[j].id = temp;
			}

		}

	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;
    
    /*Allocate memory for n students using malloc.*/
	struct student *myStudents = malloc(n * sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
	int stud_id[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		int x;

		do{
			x = rand() % 10;
			if (stud_id[x] != 0)
			{
				myStudents[i].id = stud_id[x];
				stud_id[x] = 0;
				break;
			}
		} while (stud_id[x] == 0);

	}

	for (int i = 0; i < 10; i++)
	{
		myStudents[i].score = rand() % 100;
	}
    
    /*Print the contents of the array of n students.*/
	for (int i = 0; i < 10; i++)
	{
		printf("ID %d   Score %d\n", myStudents[i].id, myStudents[i].score);
	}

    /*Pass this array along with n to the sort() function*/
	sort(myStudents, n);
    
    /*Print the contents of the array of n students.*/
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("ID %d   Score %d\n", myStudents[i].id, myStudents[i].score);
	}

	free(myStudents);
    
    return 0;
}

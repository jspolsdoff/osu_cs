#define _CTR_SECURE_NO_WARNINGS
/* CS261- Assignment 1 - Q.1*/
/* Name: James Spolsdoff
 * Date: 4/5/15
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *myStudents = malloc(10 * sizeof(struct student));
     /*return the pointer*/
	return myStudents;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int stud_id[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	for (int i = 0; i < 10; i++)
	{
		int x;

		do{
			x = rand() % 10;
			if (stud_id[x] != 0)
			{
				students[i].id = stud_id[x];
				stud_id[x] = 0;
				break;
			}
		} while (stud_id[x] == 0);

	}
	
	for (int i = 0; i < 10; i++)
	{
		students[i].score = rand() % 100;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("ID %d   Score %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int min = students[0].score;
	int max = students[0].score;
	int avg = 0;

	// calculate min
	for (int i = 1; i < 10; i++)
	{
		if (students[i].score < min)
			min = students[i].score;
	}

	// print min
	printf("The min score is %d\n", min);

	// calculate max
	for (int i = 1; i < 10; i++)
	{
		if (students[i].score > max)
			max = students[i].score;
	}

	// print max
	printf("The max score is %d\n", max);

	// calculate average
	for (int i = 0; i < 10; i++)
	{
		avg = avg + students[i].score;
	}

	avg = avg / 10;

	// print average
	printf("The average score is %d\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
	struct student* stud = NULL;

	srand(time(NULL));

	/*call allocate*/
	stud = allocate();

	/*call generate*/
	generate(stud);
   
	/*call output*/
	output(stud);

    /*call summary*/
	summary(stud);
    
    /*call deallocate*/
	deallocate(stud);

    return 0;
}

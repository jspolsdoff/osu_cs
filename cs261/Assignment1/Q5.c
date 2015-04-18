/* CS261- Assignment 1 - Q.5*/
/* Name: James Spolsdoff
 * Date: 4/5/15
 * Solution description:
 */
 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
	int count = 1;
	int i = 0;

	while (word[i] != 0)
	{
		if (count % 2 == 1)
		{
			if (word[i] >= 'a' && word[i] <= 'z')
				word[i] = toUpperCase(word[i]);
		}
		else
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
				word[i] = toLowerCase(word[i]);
		}

		i++;
		count++;
	}
}

int main(){
	char word[30];
	
	/*Read word from the keyboard using scanf*/
	printf("Please enter a word and I will turn it into sticky caps\n");
	scanf("%s", word);
    
    /*Call sticky*/
	sticky(word);
    
    /*Print the new word*/
	printf("You entered %s\n", word);
    
    return 0;
}

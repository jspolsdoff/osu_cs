/****************************************************************************
*Author:                           James Spolsdoff
*Dated Created:                    10/11/14
*Last Modified Date:               10/11/14
*Filename:                         numGuess.cpp
*
*Overview:
*This is a two player number guessing game. One player will be asked for a 
*secret number. The next player will have three guesses to get the number
*right. The program will keep track of the guess and let the player know if they
*too high, low, or exactly correct.
*
*Input:
*The inputs will be the secret numbers and the users guesses.
*
*
*
*Output:
*The outputs will be the program telling the user how many guesses they have 
*left and if they are too high, low, or correct. If the second player does not
*guess the correct number by the third chance the program prints how close their 
*guess was and the secret number.
****************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	int secret_number,		// the number the users are trying to guess
		guess_number,		// the users guess
		attempt,			// how many attempts the users has made to guess the number
		low_range,			// the low point for the guess range
		high_range,			// the high point for the guess range
		close_low,			// how close the users guess from secret number on low range
		close_high,			// how close the users guess from secret number on high range
		how_close;          // how close was the user to the secret number
	char again;				// the variable used to test if the users want to play again (Y or N)

	do  // do-while loop wraps whole program so that game can be played again without restarting
	{
		cout << "WELCOME TO THE NUMBER GUESSING GAME" << endl;
		
		cout << "\nThis is a two player number guessing game. The first player will select the secret number." << endl;
		
		cout << "The second player will have three chances to guess the number. After every guess you will be told" << endl;
		
		cout << "if your guess is too high, too low, or spot on.\n" << endl;
		
		// ask first user for the secret number
		cout << "Player one please enter a secret number from 1 to 100: ";
		
		cin >> secret_number;
		
		// validate secret number
		while ((secret_number <= 1) || (secret_number >= 100))
		{
			cout << "Not a valid number. Enter a number from 1 to 100: ";
			cin >> secret_number;
		}
		
		// move screen down to hide secret number input from player two
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		
		// initialize low range number before loop
		low_range = 1; 
		// initialize high range number before loop
		high_range = 100;
		
		cout << "Player two get to try to guess the secret number.\n" << endl;
		
		// start loop to have second user begin guessing the value of the secret number
		for (attempt = 3; attempt > 0; attempt--)
		{
			// tell user the range, how many guesses they have, and ask for input
			cout << "The range of the secret number is " << low_range << " to " << high_range << endl;
		
			cout << "You have " << attempt << " chances to guess the number." << endl;
		
			cout << "What is your guess: ";
		
			cin >> guess_number;
		
			// validate guess number
			while ((guess_number <= low_range) || (guess_number >= high_range))
			{
				cout << "Not a valid number. Enter a number from " << low_range << " to " << high_range << ": ";
				cin >> guess_number;
			}
			
			// run test to see how user guess compares to secret number
			if (guess_number > secret_number)
			{
				high_range = guess_number;
				cout << "Your guess was too high." << endl;
			}
			
			else if (guess_number < secret_number)
			{
				low_range = guess_number;
				cout << "Your guess was too low." << endl;
			}
			
			else if (guess_number == secret_number)
			{
				cout << "Great job! You guessed the right number!" << endl;
				break;
			}
		
		}
		
		// check if second user guessed secret number if not tells them what it was and how close they were
		if (guess_number != secret_number)
		{
			cout << "The secret number was " << secret_number << endl;
			
			// calculate how close the users guesses were to secret number
			close_low = (secret_number - low_range);
			close_high = (high_range - secret_number);
			
			// tell user how close they were to secret number  "try using high and low ranges"
			if (close_low < close_high)
			{
				cout << "You were " << close_low << " numbers away from the secret number." << endl;
			}
			
			else
			{
				cout << "You're closest guess was " << close_high << " numbers away from the secret number." << endl;
			}
		}
		
		// check if the users want to play again
		cout << "Do you want to play again? (Y/N)";
		
		cin >> again;
	
	// make sure input matches the case of the validator
	} while (toupper(again) == 'Y');
	
	return 0;
}  

/****************************************************************************
*Author:                      James Spolsdoff
*Dated Created:               11/14/14    
*Last Modified Date:          11/16/14     
*Filename:                         
*
*Overview:
*The program is a simple two player tic-tac-toe game. It will allow the player 
*to determine how many games to play in the series based on a command line 
*argument.
*
*Input:
*The player will input how many games they will to play in a series in the 
*command line. They will also input their move by typing the coordinates of 
*a 2D array that represents the board.
*
*Output:
*The program will output the number of games won along with their move on the 
*board.
*
****************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

// global variable for the tic tac toe board
char board[3][3] = {{'.','.','.'},
                    {'.','.','.'},
                    {'.','.','.'}};

// function prototypes
void PrintBoard();
void ClearBoard();
void WhoGoesFirst(int game_num, char &player);
void SwitchPlayer(char &player);
void GetMove(int move[], char player); 
void StoreMove(int move[], char player);
bool CheckWinner(char player);
void Score(int game_num, int game_total, char player, bool did_win, int &player_x_wins, int &player_o_wins, int &tie); 

int main(int argc, char *argv[])
{
	
	// declare variables
	int game_num = 1;	// variable for the number of games played
	int game_total = 1;	// variable for the total number of games to be played
	int game_turns = 1;	// variable for the number of turn in game (max 9) 
	int move[2];		// array to hold each players move
	int player_x_wins = 0;	// variable for wins for player x
	int player_o_wins = 0;	// variable for wins for player o 
	int tie = 0;			// variable for a tie
	char player = 'X';	// temp variable to hold the character of player
	bool did_win;		// variable used to break loop if there is a winner	
	
	cout << "WELCOME TO THE TIC-TAC-TOE GAME \n" << endl;
	
	// check to see if there is a command line argument for the number of games to be played
	if (argc == 2)
	{
		game_total = atoi(argv[1]);
	}	 

	do{	
		// switch who goes first in a series of games
		WhoGoesFirst(game_num, player);
	
		// print out the blank default board
		PrintBoard();
		cout << "\n" << endl;	

		do{
	
		// ask the player for their move
		GetMove(move, player);
		
		cout << "\n" << endl;

		// store the player's move on the game board
	 	StoreMove(move, player);

		// print the game board after the move has been made
		PrintBoard();
	
		// check for winner
		did_win = CheckWinner(player);

		// if there is a winner break the loop
		if (did_win == 1)
			break; 	
		
		// switch players for upcoming turn
		SwitchPlayer(player); 
 
		// increase the variable to the next game turn	
		game_turns++;
	
		} while((game_turns <= 9) && (did_win == 0)); // change back to 9 when done testing
		
		// display the updated score
		Score(game_num, game_total, player, did_win, player_x_wins, player_o_wins, tie);

		// keep track of the number of games played
		game_num++;

		// clear the game board and reset game turn to 0 for the next game
		ClearBoard();
		game_turns = 1;

	} while(game_num <= game_total);	

	return 0;
}  

/*******************************************************************************
*				PrintBoard
*This function will print the tic tac toe board.
********************************************************************************/
void PrintBoard()
{
	cout << "  " << 0 << " " << 1 << " " << 2 << endl;	

	for (int i = 0; i < 3; i++)
	{
		cout << i << " ";
		 
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j] << " ";
		} 
		cout << endl;
	} 
}

/*******************************************************************************
*				ClearBoard
*This function will clear the game board for the next board
********************************************************************************/
void ClearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = '.';
		}
	} 
}  
/*******************************************************************************
*				SwitchPlayer
*This function will switch the players inbetween turns 
********************************************************************************/
void SwitchPlayer(char &player)
{
	if (player == 'O')
		player = 'X';
	else
		player = 'O';
}
 
/*******************************************************************************
*				GetMove
*This function will ask to user and store it in a two element array 
** ******************************************************************************/
void GetMove(int move[], char player)
{
	cout << "Player " << player << ": please enter your move: ";
	cin >> move[0];
	cin >> move[1];
	
	// check to see if the player tries to take an occupied space
	while ((board[move[0]][move[1]] == 'X') || (board[move[0]][move[1]] == 'O'))
	{
		cout << "You entered an invalid move. Please enter another move: ";
		cin >> move[0];
		cin >> move[1];	
	}
} 

/*******************************************************************************
*				StoreMove
*This function will handle making the move for the player on the game board
********************************************************************************/
void StoreMove(int move[], char player)
{
	board[move[0]][move[1]] = player;
}

/*******************************************************************************
*				CheckWinner
*This function will check if there is a winner after each move
********************************************************************************/
bool CheckWinner(char player)
{
	int win_value = player * 3;	// value to check if there are three char in a row
	int line_total = 0;		// variable to store character values of a line

	// loop to calculate the sum of all rows
	for (int i = 0; i < 3; i++)
	{
		line_total = 0;

		for (int j = 0; j < 3; j++)
		{
			line_total += board[i][j];
		} 	
		// if statement to check if there is a winner
		if (line_total == win_value)
		{
			// we have a winner  
			cout << "We have a winner! " << "Great job player " << player << endl;
			return true;
		}
	}

	// loop to calculate the sum off all columns
	for (int j = 0; j < 3; j++)
	{
		line_total = 0;

		for (int i = 0; i < 3; i++)
		{
			line_total += board[i][j];
		}
		// if statement to check if there is a winner
		if (line_total == win_value)
		{
			// we have a winner
			cout << "We have a winner! " << "Great job player " << player << endl;
			return true;
		}
	} 

	line_total = 0;		// set the line total variable back to zero for next loop

	// loop to calculate the sum of diagonals
	for (int i = 0; i < 3; i++)
	{
		line_total += board[i][i];
	} 
	// if statement to check if there is a winner
	if (line_total == win_value)
	{
		// we have a winner
		cout << "We have a winner! " << "Great job player " << player << endl;
		return true;
	}

	line_total = 0;
	int j = 2;

	for (int i = 0; i < 3; i++)
	{
		line_total += board[i][j];
		j--;
	}	  
	// if statement to check if there is a winner
	if (line_total == win_value)
	{
		// we have a winner
		cout << "We have a winner! " << "Great job player " << player << endl;
		return true;
	}

	return false;	
}
  
/*******************************************************************************
*				WhoGoesFirst
*This function will rotate which player goes first if there are more than 1 game.
********************************************************************************/
void WhoGoesFirst(int game_num, char &player)
{
	if ((game_num % 2) != 0)
		player = 'X';
	else
		player = 'O';
}

/*******************************************************************************
*				PrintScore
*This function will keep track of and print the score of a series of games.
********************************************************************************/
void Score(int game_num, int game_total, char player, bool did_win, int &player_x_wins, int &player_o_wins, int &tie)
{
	// keep track of wins and ties
	if ((did_win == 1) && (player == 'X'))
		player_x_wins++;
	else if ((did_win == 1) && (player == 'O'))
		player_o_wins++;
	else
		tie++;
	
	cout << "\n\n" << endl;
	
	// check to see if the game is over and the overall winner needs to be calculated
	if (game_num < game_total)
	{
	cout << "THE CURRENT MATCH SCORE\n" << endl;
	cout << "Player X: " << player_x_wins << endl;
	cout << "Player O: " << player_o_wins << endl;
	cout << "Ties: " << tie << endl;
	cout << "\n" << endl;
	}
	
	// calculate the overall winner of the match
	else
	{
		if (player_x_wins > player_o_wins)
		{
			cout << "Player X: You are the overall winner!" << endl;
			exit(EXIT_SUCCESS);
		}
		else if (player_o_wins > player_x_wins)
		{
			cout << "Player O: You are the overall winner!" << endl;
			exit(EXIT_SUCCESS);
		}
		else
		{
			cout << "The match ends in a tie. You should play again to settle this." << endl;
			exit(EXIT_SUCCESS);
		}
	}
}

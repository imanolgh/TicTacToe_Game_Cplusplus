#pragma once
#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"

using namespace std;



int main(int argc, char* argv[]) {


	if (argc != incorrect_cmd_ln_args) {
		cout << "incorrect number of commands" << endl;
		return usageMessage(argv[cmd_ln_arguments::programName]);

	}

	string stringTwo = argv[fileInput];

	if (stringTwo != "TicTacToe") {
		cout << "There was an error with the name inputted, must be TicTacToe" << endl;
		return cmd_ln_arguments::incorrectName;
	}
	// Declare an object of the Game class
	Game letsPlay;
	//Call the object's play() method and use the result that was returned by that method as the program's return value.


	int outcome = letsPlay.play();
	return outcome;

}


//usageMessage
int usageMessage(char* programName) {
	cout << "error is" << "<incorrect_cmd_ln_args>" << endl;
	cout << "input should be: " << programName << "<TicTacToe>" << endl;
	return cmd_ln_arguments::incorrectArg;
}

//Constructor
Game::Game()
	: gameBoard{ {0, 1, 2, 3, 4,}, {0, 1, 2, 3, 4,}, {0, 1, 2, 3, 4,}, {0, 1, 2, 3, 4,}, {0, 1, 2, 3, 4,} },
	turns(9),
	playerX('X'),
	playerO('O'),
	space(' '),
	victoryX(false),
	victoryO(false),
	quitted(false),
	moveIsValid(false)

{
	// print out the game board
	for (int row = 0; row <= 4; row++) {
		for (int column = 0; column <= 4; column++) {
			gameBoard[row][column] = space;
		}
	}
	cout << "Let's play Tic Tac Toe" << endl;
	cout << *this << endl;
}

// insertion operator using operator<<
ostream& operator<<(ostream& output, const Game& TicTacToe) {
	// the 4 in the for loops refers to the total width and height of the whole board
	for (int i = 4; i >= 0; i--) {
		if ((i > 0)) {
			if (i <= 4) {
				output << i << "   ";
				for (int k = 1; k < 4; k++) {
					if (TicTacToe.gameBoard[k][i] != ' ') {
						output << TicTacToe.gameBoard[k][i] << " ";
					}
					else {
						output << "  ";
					}
				}
				output << endl;
			}
		}
		else {
			output << i << endl;
		}
	}
	output << "  ";
	for (int k = 0; k < 5; k++) {
		output << k << " ";
	}
	output << endl;
	return output;
}


// This method should return true if 3 Xs or Os are in a vertical, horizontal or diagonal line to win the game; 
// else the method should return false.
bool Game::done() {

	if (space != gameBoard[1][1] && space != gameBoard[2][2] && space != gameBoard[3][3]) {
		if (gameBoard[2][2] == gameBoard[1][1] && gameBoard[2][2] == gameBoard[3][3]) {
			if (playerO == gameBoard[2][2]) {

				victoryO = true;
				return victoryO;
			}
			else if (playerX == gameBoard[2][2]) {

				victoryX = true;
				return victoryX;
			}
		}
	}
	
	// check diagonals for win
	
	if (space != gameBoard[1][3] && space != gameBoard[2][2] && space != gameBoard[3][1]) {
		if (gameBoard[2][2] == gameBoard[1][3] && gameBoard[2][2] == gameBoard[3][1]) {
			if (playerO == gameBoard[2][2]) {
				victoryO = true;
				return victoryO;
				cout << "player X wins!" << endl;
			}
			else if (gameBoard[2][2] == playerX) {
				victoryX = true;
				return victoryX;
				cout << "player X wins!" << endl;
			}
		}
	}
	
	//check horizontals for win
	// r represents the current row which is being checked for win
	for (int r = 1; r < 4; r++) {
		if (space != gameBoard[r][1] && space !=  gameBoard[r][2] && space != gameBoard[r][3]) {
			if (gameBoard[r][2] == gameBoard[r][1] && gameBoard[r][2] == gameBoard[r][3]) {
				if (playerO == gameBoard[r][2]) {
					victoryO = true;
					return victoryO;
					cout << "player X wins!" << endl;
				}
				else if (playerX == gameBoard[r][2]) {
					victoryX = true;
					return victoryX;
					cout << "player O wins!" << endl;
				}
			}
		}
	}
	//check verticals for win
	// c represents the current column which is being checked for win
	for (int c = 1; c < 4; c++) {
		if (space != gameBoard[1][c] && space != gameBoard[2][c] && space !=  gameBoard[3][c]) {
			if (gameBoard[2][c] == gameBoard[1][c] && gameBoard[2][c] == gameBoard[3][c]) {
				if (playerO == gameBoard[2][c]) {
					victoryO = true;
					return victoryO;
					cout << "player X wins!" << endl;
				}
				else if (playerX == gameBoard[2][c]) {
					victoryX = true;
					return victoryX;
					cout << "player X wins!" << endl;
				}
			}
		}
	}

	return succeeded;
}
 
// return false if there are turns remaining or if the done() method returns true;
//otherwise the draw() method returns true.
bool Game::draw() {
	
	if (done() == true) {
		return false;
	}
	else if (turns != 0) {
		return false;
	}
	else {
		return true;
	}
}


 
int Game::prompt(unsigned int& row, unsigned int& column) {
	string UserIn;
	bool validMove = false;
	
	// string wrapper

	while (validMove == false) {
		cout << "enter a valid coordinate with the format: 'x,y' or quit the game by typing 'quit'" << endl;
		cin >> UserIn;
		//replace comma with a space
		for (unsigned int s = 0; s < UserIn.size(); s++) {
			if (UserIn[s] == ',') {
				UserIn[s] = ' ';
			}
		}
		istringstream iss(UserIn);

		if (UserIn == "quit") {
			this->quitted = true;
			return state::playerQuit;
		}

		else {
			if (iss >> row) {
				if (iss >> column) {
					if (row > 3 && column > 3) {
						cout << "out of bounds index for both row and column" << endl;
					}
					else if (row < 1 && column < 1) {
						cout << "out of bounds index for both row and column" << endl;
					}
					else if (row < 1 && column > 1) {
						cout << "out of bounds index for both row and column" << endl;
					}
					else if (row > 1 && column < 1) {
						cout << "out of bounds index for both row and column" << endl;
					}
					
					
					if (column > 0 && column < 4 && row > 0 && row < 4) {

						if (space == gameBoard[row][column]) {
							validMove = true;
							return validMove;
							cout << "your input is valid" << endl;
						}
						else {
							cout << "that space is already taken, please enter a valid space" << endl;
						}
					}
					else if(column > 0 && column < 4) {
						cout << "out of bounds for row index" << endl;
					}
					
					else if (row > 0 && row < 4) {
						cout << "out of bounds for column index" << endl;
					}
				}
				else {
					cout << "invalid input for column" << endl;
				}
			}
			else {
				cout << "invalid input for row" << endl;
			}
		}

	}
	return state::succeeded;
}


int Game::turn() {
	bool moveIsValid = false;
	unsigned int row;
	unsigned int column;
	// Repeatedly call the prompt() method to obtain coordinates for a valid
	// move in the game, or to determine that the user has quit the game
	while (turns != 0 && done() == false) {
		if (prompt(row, column) == state::playerQuit) {
			return state::playerQuit;
		}

		//X's turn
		if (turns % 2 != 0) {
			gameBoard[row][column] = 'X';
			cout << *this;
			cout << "It is player X's turn" << endl;
			// the 3 in the for loops refers to the last valid index in which the player can make a valid move
			for (int row = 1; row <= 3; row++) {
				for (int column = 1; column <= 3; column++) {
					if ('X' == gameBoard[row][column]) {
						cout << row << ',' << column << endl;
					}
				}
			}
			if (done() == true) {
				return state::succeeded;
			}
			turns--;
		}
		//O's turn
		else if (turns % 2 == 0) {
			gameBoard[row][column] = 'O';
			cout << *this;
			cout << "Current Player: player O's turn" << endl;
			// 3 in the for loops refers to the last valid index in which the player can make a valid move
			for (int row = 1; row <= 3; row++) {
				for (int column = 1; column <= 3; column++) {
					if ('O' == gameBoard[row][column]) {
						cout << row << ',' << column << endl;
					}
				}
			}
			if (done() == true) {
				return state::succeeded;
			}
			turns--;
		}
	}
	return succeeded;
}

int Game::play() {

	while (done() != true && quitted != true) {
		turn();
	}
	// the 9 in currentTurns refers to the number of total moves in the game
	int currentTurns = 9 - turns;
	//check the done method
	if (done() == true) {
		if (victoryX == true) {
			cout << "player X wins!" << endl;
			return state::succeeded;
		}
		else if (victoryO == true) {
			cout << "player O wins!" << endl;
			return state::succeeded;
		}
	}
	// a player has quit
	else if (quitted == true) {

		cout << "a player has quit the game,the turns is " << currentTurns << endl;

		return state::playerQuit;
	}
	// all squares filled and no player winning = draw
	else if (draw() == true) {
		cout << "The result is a draw, the turn number is " << currentTurns << endl;
		return state::isDraw;
	}
	
	return succeeded;
}
